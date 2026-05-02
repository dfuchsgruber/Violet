#!/usr/bin/env python3

import argparse
import html
import json
import pickle
import re
import shutil
import sys
import unicodedata
from pathlib import Path

from pymap.project import Project


STATS = ("hp", "attack", "defense", "special-attack", "special-defense", "speed")
STAT_LABELS = {
    "hp": "KP",
    "attack": "Angriff",
    "defense": "Verteidigung",
    "special-attack": "Spezial-Angriff",
    "special-defense": "Spezial-Verteidigung",
    "speed": "Initiative",
}


def eprint(message):
    print(f"pokemon wiki: {message}", file=sys.stderr)


def load_pickle(path):
    with open(path, "rb") as f:
        return pickle.load(f)


def load_json_data(path):
    try:
        with open(path, encoding="utf-8") as f:
            return json.load(f).get("data")
    except FileNotFoundError:
        return None


def escape(value):
    return html.escape(str(value), quote=True)


def normalize_constant(value, prefixes=()):
    if value is None or value == 0:
        return None
    if not isinstance(value, str):
        return str(value)
    text = value
    for prefix in prefixes:
        if text.startswith(prefix):
            text = text[len(prefix):]
    text = text.replace("_", " ").replace("-", " ")
    return " ".join(part.capitalize() for part in text.split())


def display_value(value, prefixes=()):
    if value is None or value == 0 or value == "ABILITY_NONE" or value == "ITEM_NONE":
        return "-"
    return normalize_constant(value, prefixes) or "-"


def slugify(value):
    value = unicodedata.normalize("NFKD", value).encode("ascii", "ignore").decode("ascii")
    value = re.sub(r"[^a-zA-Z0-9]+", "-", value.lower()).strip("-")
    return value or "pokemon"


def clean_entry_text(value):
    if not value:
        return ""
    return str(value).replace("\\xFE", " ").replace("\xFE", " ").replace("\\n", " ").strip()


def constants_by_value(project, table_name):
    return {value: key for key, value in project.constants[table_name].items()}


def parse_frontsprites(path):
    sprite_map = {}
    text = Path(path).read_text(encoding="utf-8")
    pattern = re.compile(r"\[(POKEMON_[A-Z0-9_]+)\].*?gfx_pokemon_([a-z0-9_]+)_frontspriteTiles")
    for species_constant, sprite_slug in pattern.findall(text):
        sprite_map[species_constant] = sprite_slug
    return sprite_map


def detect_shifted_pokedex_order(pokemon_data):
    order = pokemon_data.get("pokedex_order", [])
    basestats = pokemon_data.get("basestats", [])
    shifted = len(order) == len(basestats) + 1 and len(order) > 2 and order[1] == 0 and order[2] == 1
    if shifted:
        eprint("warning: pokemon.pkl has an old shifted pokedex_order; using defensive +1 lookup")
    return shifted


def dex_number_for(pokemon_data, species_idx, shifted_order):
    order = pokemon_data.get("pokedex_order") or []
    idx = species_idx + 1 if shifted_order else species_idx
    if 0 <= idx < len(order):
        return order[idx]
    return None


def dex_entry_for(pokemon_data, dex_number):
    entries = pokemon_data.get("pokedex_entries") or []
    if isinstance(dex_number, int) and 0 <= dex_number < len(entries):
        return entries[dex_number] or {}
    return {}


def language_value(value, language):
    if isinstance(value, dict):
        return value.get(language) or value.get("LANG_GER") or value.get("LANG_EN")
    return value


def species_href(species_idx, page_slugs, from_species_page=False):
    href = page_slugs.get(species_idx, f"{species_idx:03d}-pokemon/")
    return f"../{href}" if from_species_page else f"species/{href}"


def item_list(values, prefixes=(), limit=None):
    values = values or []
    if isinstance(values, set):
        values = sorted(values)
    if not isinstance(values, (list, tuple)):
        return "<p class=\"muted\">-</p>"
    shown = values if limit is None else values[:limit]
    if not shown:
        return "<p class=\"muted\">-</p>"
    items = []
    for value in shown:
        items.append(f"<li>{escape(display_value(value, prefixes))}</li>")
    if limit is not None and len(values) > limit:
        items.append(f"<li class=\"muted\">und {len(values) - limit} weitere</li>")
    return "<ul class=\"chip-list\">" + "".join(items) + "</ul>"


def move_list_table(levelup_moves):
    moves = levelup_moves or []
    if not moves:
        return "<p class=\"muted\">-</p>"
    rows = []
    for entry in moves:
        if isinstance(entry, dict):
            level = entry.get("level")
            move = display_value(entry.get("move"), ("ATTACK_",))
        elif isinstance(entry, (tuple, list)) and len(entry) >= 2:
            move, level = entry[0], entry[1]
        else:
            continue
        level_text = "Evo" if level == 0 else escape(level)
        rows.append(f"<tr><td>{level_text}</td><td>{escape(display_value(move, ('ATTACK_',)))}</td></tr>")
    return "<table><thead><tr><th>Level</th><th>Attacke</th></tr></thead><tbody>" + "".join(rows) + "</tbody></table>"


def tm_table(entries):
    if not entries:
        return "<p class=\"muted\">-</p>"
    rows = []
    for entry in entries:
        if isinstance(entry, (tuple, list)) and len(entry) == 2:
            machine, move = entry
            if isinstance(machine, (tuple, list)) and len(machine) == 2:
                machine_text = f"{machine[0]}{int(machine[1]):02d}"
            else:
                machine_text = str(machine)
            rows.append(f"<tr><td>{escape(machine_text)}</td><td>{escape(display_value(move, ('ATTACK_',)))}</td></tr>")
    return "<table><thead><tr><th>TM/VM</th><th>Attacke</th></tr></thead><tbody>" + "".join(rows) + "</tbody></table>"


def tutor_table(entries):
    if isinstance(entries, int):
        return "<p class=\"muted\">Nicht verfügbar: altes pokemon.pkl enthält nur den fehlerhaften Indexwert.</p>"
    if not entries:
        return "<p class=\"muted\">-</p>"
    rows = []
    for entry in entries:
        if isinstance(entry, (tuple, list)) and len(entry) == 2:
            rows.append(f"<tr><td>{escape(entry[0])}</td><td>{escape(display_value(entry[1], ('ATTACK_',)))}</td></tr>")
    return "<table><thead><tr><th>Tutor</th><th>Attacke</th></tr></thead><tbody>" + "".join(rows) + "</tbody></table>"


def stat_table(basestats):
    total = sum(int(basestats.get(stat, 0)) for stat in STATS)
    rows = []
    for stat in STATS:
        value = int(basestats.get(stat, 0))
        width = min(100, round(value / 180 * 100))
        rows.append(
            f"<tr><th>{STAT_LABELS[stat]}</th><td>{value}</td>"
            f"<td><span class=\"bar\"><span style=\"width:{width}%\"></span></span></td></tr>"
        )
    rows.append(f"<tr class=\"total\"><th>Summe</th><td>{total}</td><td></td></tr>")
    return "<table class=\"stats\"><tbody>" + "".join(rows) + "</tbody></table>"


def format_evolution_argument(evo):
    arg = evo.get("argument")
    method = evo.get("method") or evo.get("trigger")
    if isinstance(arg, dict):
        if method in ("EVOLUTION_METHOD_STONE", "EVOLUTION_METHOD_TRADE_HOLD_ITEM", "EVOLUTION_METHOD_HOLD_ITEM",
                      "EVOLUTION_METHOD_LINK_CABLE_AND_ITEM", "EVOLUTION_METHOD_MALE_AND_STONE",
                      "EVOLUTION_METHOD_FEMALE_AND_STONE", "EVOLUTION_METHOD_HOLD_ITEM_AND_DAY",
                      "EVOLUTION_METHOD_HOLD_ITEM_AND_NIGHT"):
            arg = arg.get("item")
        elif method == "EVOLUTION_METHOD_KNOW_MOVE":
            arg = arg.get("move")
        elif method == "EVOLUTION_METHOD_KNOW_MOVE_TYPE":
            arg = arg.get("pokemon_type")
        elif method == "EVOLUTION_METHOD_ON_MAP":
            arg = arg.get("map")
        else:
            arg = arg.get("numeric")
    if isinstance(arg, dict):
        return f"{arg.get('bank', 0)}.{arg.get('map_idx', 0)}"
    if arg in (None, 0):
        return ""
    return display_value(arg, ("ITEM_", "ATTACK_", "TYPE_"))


def evolution_list(entries, species_to_idx, names, page_slugs):
    entries = entries or []
    if isinstance(entries, dict):
        entries = [
            {"target": target, "method": details.get("trigger"), "argument": details.get("argument"),
             "baby_trigger_item": details.get("baby_trigger_item")}
            for target, details in entries.items()
        ]
    if not entries:
        return "<p class=\"muted\">-</p>"
    items = []
    for evo in entries:
        target = evo.get("target")
        target_idx = species_to_idx.get(target) if isinstance(target, str) else None
        method = display_value(evo.get("method") or evo.get("trigger"), ("EVOLUTION_METHOD_",))
        argument = format_evolution_argument(evo)
        baby_item = display_value(evo.get("baby_trigger_item"), ("ITEM_",))
        target_name = names.get(target_idx, display_value(target, ("POKEMON_",)))
        if target_idx in page_slugs:
            target_html = f"<a href=\"{escape(species_href(target_idx, page_slugs, True))}\">{escape(target_name)}</a>"
        else:
            target_html = escape(target_name)
        details = method
        if argument:
            details += f" {escape(argument)}"
        if baby_item != "-":
            details += f" (Baby-Item: {escape(baby_item)})"
        items.append(f"<li>{target_html}<span>{escape(details)}</span></li>")
    return "<ul class=\"evolution-list\">" + "".join(items) + "</ul>"


def copy_sprite(species_constant, sprite_map, assets_dir):
    slug = sprite_map.get(species_constant)
    if not slug:
        eprint(f"warning: no frontsprite mapping for {species_constant}")
        return None
    src = Path("asset/gfx/pokemon") / f"gfx_pokemon_{slug}_frontsprite.png"
    if not src.exists():
        eprint(f"warning: missing sprite png {src}")
        return None
    dst = assets_dir / "sprites" / src.name
    dst.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(src, dst)
    return f"../../assets/sprites/{src.name}"


def write_assets(assets_dir):
    assets_dir.mkdir(parents=True, exist_ok=True)
    (assets_dir / "style.css").write_text(STYLE_CSS, encoding="utf-8")
    (assets_dir / "search.js").write_text(SEARCH_JS, encoding="utf-8")


def build_records(args):
    pokemon_data = load_pickle(args.pokemon_pkl)
    readable_stats = load_pickle(args.stats_pkl) if args.stats_pkl.exists() else []
    generated_names = load_json_data(Path("bld/pokeapi/pokemon_names.pms")) or []
    project = Project(str(args.project))
    species_to_idx = dict(project.constants["species"].items())
    idx_to_species = constants_by_value(project, "species")
    sprite_map = parse_frontsprites("include/c/data/pokemon/frontsprites.h")
    shifted_order = detect_shifted_pokedex_order(pokemon_data)

    records = []
    names = {}
    basestats = pokemon_data.get("basestats") or []
    max_species = species_to_idx.get("POKEMON_CNT", len(basestats))
    for idx in range(1, min(len(basestats), max_species)):
        species_constant = idx_to_species.get(idx)
        if not species_constant:
            continue
        readable = readable_stats[idx] if idx < len(readable_stats) and readable_stats[idx] else {}
        generated_name = generated_names[idx] if idx < len(generated_names) else None
        name = language_value(readable.get("name"), args.language) or generated_name or display_value(species_constant, ("POKEMON_",))
        names[idx] = name
        dex_number = dex_number_for(pokemon_data, idx, shifted_order)
        pkl_entry = dex_entry_for(pokemon_data, dex_number)
        dex_text = language_value(readable.get("dex_entry"), args.language) or pkl_entry.get("entry_string_0")
        genus = language_value(readable.get("genus"), args.language) or pkl_entry.get("genus")
        page_slug = f"{idx:03d}-{slugify(name)}"
        records.append({
            "idx": idx,
            "species_constant": species_constant,
            "name": name,
            "slug": page_slug,
            "dex_number": dex_number,
            "readable": readable,
            "pkl_entry": pkl_entry,
            "dex_text": clean_entry_text(dex_text),
            "genus": genus,
        })
    return pokemon_data, records, names, species_to_idx, sprite_map


def render_info_grid(record, stats):
    readable = record["readable"]
    pkl_entry = record["pkl_entry"]
    values = [
        ("Pokédex", record["dex_number"] if record["dex_number"] is not None else "-"),
        ("Art", record["genus"] or "-"),
        ("Größe", f"{(readable.get('height', pkl_entry.get('height', 0)) or 0) / 10:g} m"),
        ("Gewicht", f"{(readable.get('weight', pkl_entry.get('weight', 0)) or 0) / 10:g} kg"),
        ("Farbe", display_value(stats.get("color_and_flip", {}).get("color"), ("POKEMON_COLOR_",))),
        ("Form", display_value(stats.get("shape"), ("SHAPE_",))),
        ("Fangrate", stats.get("capture_rate", "-")),
        ("EP", stats.get("exp_yield", "-")),
        ("Zuneigung", stats.get("base_happiness", "-")),
        ("Safari", stats.get("safari_rate", "-")),
    ]
    return "<dl class=\"info-grid\">" + "".join(f"<div><dt>{escape(k)}</dt><dd>{escape(v)}</dd></div>" for k, v in values) + "</dl>"


def render_species_page(args, record, pokemon_data, names, species_to_idx, sprite_map, page_slugs, output_dir):
    idx = record["idx"]
    stats = pokemon_data["basestats"][idx] or {}
    readable = record["readable"]
    sprite_src = copy_sprite(record["species_constant"], sprite_map, output_dir / "assets")
    types = [stats.get("type_0"), stats.get("type_1")]
    type_badges = "".join(
        f"<span class=\"type type-{slugify(display_value(t, ('TYPE_',)))}\">{escape(display_value(t, ('TYPE_',)))}</span>"
        for t in dict.fromkeys(t for t in types if t)
    )
    ability_values = [stats.get("ability_0"), stats.get("ability_1"), stats.get("hidden_ability")]
    abilities = " / ".join(display_value(v, ("ABILITY_",)) for v in ability_values if display_value(v, ("ABILITY_",)) != "-") or "-"
    held_items = " / ".join(
        display_value(v, ("ITEM_",)) for v in (stats.get("common_item"), stats.get("rare_item")) if display_value(v, ("ITEM_",)) != "-"
    ) or "-"
    ev_yield = ", ".join(
        f"{STAT_LABELS[s]} +{stats.get('ev_yield', {}).get(s)}"
        for s in STATS if stats.get("ev_yield", {}).get(s)
    ) or "-"

    sprite_html = f"<img src=\"{escape(sprite_src)}\" alt=\"{escape(record['name'])}\">" if sprite_src else ""
    content = f"""<!doctype html>
<html lang="de">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>{escape(record['name'])} - Pokémon Violet Wiki</title>
  <link rel="stylesheet" href="../../assets/style.css">
</head>
<body>
  <header class="site-header">
    <a href="../../index.html">Pokémon Violet Wiki</a>
    <nav><a href="../../index.html">Pokédex</a></nav>
  </header>
  <main>
    <section class="hero">
      <div>{sprite_html}</div>
      <div>
        <p class="eyebrow">#{escape(record['idx'])} · {escape(record['species_constant'])}</p>
        <h1>{escape(record['name'])}</h1>
        <div class="types">{type_badges}</div>
        <p>{escape(record['dex_text']) if record['dex_text'] else ''}</p>
      </div>
    </section>
    <section class="panel">{render_info_grid(record, stats)}</section>
    <section class="grid two">
      <article class="panel"><h2>Basiswerte</h2>{stat_table(stats.get('basestats', {}))}</article>
      <article class="panel"><h2>Training</h2>
        <dl class="info-grid compact">
          <div><dt>Fähigkeiten</dt><dd>{escape(abilities)}</dd></div>
          <div><dt>Items</dt><dd>{escape(held_items)}</dd></div>
          <div><dt>EV-Ertrag</dt><dd>{escape(ev_yield)}</dd></div>
          <div><dt>Geschlecht</dt><dd>{escape(stats.get('gender_ratio', '-'))}</dd></div>
          <div><dt>Ei-Gruppen</dt><dd>{escape(display_value(stats.get('egg_group_0'), ('EGG_GROUP_',)))} / {escape(display_value(stats.get('egg_group_1'), ('EGG_GROUP_',)))}</dd></div>
          <div><dt>Ei-Zyklen</dt><dd>{escape(stats.get('egg_cycles', '-'))}</dd></div>
          <div><dt>Wachstum</dt><dd>{escape(display_value(stats.get('growth_rate'), ('GROWTH_RATE_',)))}</dd></div>
        </dl>
      </article>
    </section>
    <section class="grid two">
      <article class="panel"><h2>Entwicklung</h2>{evolution_list(pokemon_data.get('evolutions', [None])[idx], species_to_idx, names, page_slugs)}</article>
      <article class="panel"><h2>Level-Up Attacken</h2>{move_list_table(pokemon_data.get('levelup_moves', [None])[idx])}</article>
    </section>
    <section class="grid two">
      <article class="panel"><h2>Ei-Attacken</h2>{item_list(pokemon_data.get('egg_moves', [None])[idx], ('ATTACK_',))}</article>
      <article class="panel"><h2>Weitere Attacken</h2>{item_list(pokemon_data.get('accessible_moves', [None])[idx], ('ATTACK_',))}</article>
    </section>
    <section class="grid two">
      <article class="panel"><h2>TM/VM</h2>{tm_table(pokemon_data.get('tm_hm_compatibility', [None])[idx])}</article>
      <article class="panel"><h2>Tutor</h2>{tutor_table(pokemon_data.get('move_tutor_compatibility', [None])[idx])}</article>
    </section>
  </main>
</body>
</html>
"""
    page_dir = output_dir / "species" / record["slug"]
    page_dir.mkdir(parents=True, exist_ok=True)
    (page_dir / "index.html").write_text(content, encoding="utf-8")


def render_index(records, pokemon_data, sprite_map, output_dir):
    cards = []
    for record in records:
        idx = record["idx"]
        stats = pokemon_data["basestats"][idx] or {}
        type_text = " ".join(display_value(t, ("TYPE_",)) for t in (stats.get("type_0"), stats.get("type_1")) if t)
        types = "".join(
            f"<span class=\"type type-{slugify(display_value(t, ('TYPE_',)))}\">{escape(display_value(t, ('TYPE_',)))}</span>"
            for t in dict.fromkeys(t for t in (stats.get("type_0"), stats.get("type_1")) if t)
        )
        sprite_slug = sprite_map.get(record["species_constant"])
        sprite_file = f"gfx_pokemon_{sprite_slug}_frontsprite.png" if sprite_slug else ""
        sprite = f"assets/sprites/{sprite_file}" if sprite_file and (output_dir / "assets" / "sprites" / sprite_file).exists() else ""
        img = f"<img src=\"{escape(sprite)}\" alt=\"{escape(record['name'])}\">" if sprite else ""
        cards.append(
            f"<a class=\"pokemon-card\" href=\"species/{escape(record['slug'])}/\" "
            f"data-search=\"{escape((record['name'] + ' ' + record['species_constant'] + ' ' + type_text).lower())}\">"
            f"{img}<span>#{escape(record['idx'])}</span><strong>{escape(record['name'])}</strong><small>{types}</small></a>"
        )
    content = f"""<!doctype html>
<html lang="de">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Pokémon Violet Pokédex</title>
  <link rel="stylesheet" href="assets/style.css">
  <script defer src="assets/search.js"></script>
</head>
<body>
  <header class="site-header">
    <a href="../index.html">Pokémon Violet Wiki</a>
    <nav><a href="../index.html">Projekt</a></nav>
  </header>
  <main>
    <section class="list-header">
      <div>
        <p class="eyebrow">Statischer Pokédex</p>
        <h1>Pokémon</h1>
      </div>
      <label class="search"><span>Suche</span><input id="pokemon-search" type="search" autocomplete="off"></label>
    </section>
    <section id="pokemon-list" class="pokemon-grid">
      {''.join(cards)}
    </section>
  </main>
</body>
</html>
"""
    (output_dir / "index.html").write_text(content, encoding="utf-8")


def generate(args):
    if args.clean and args.output.exists():
        shutil.rmtree(args.output)
    args.output.mkdir(parents=True, exist_ok=True)
    write_assets(args.output / "assets")
    pokemon_data, records, names, species_to_idx, sprite_map = build_records(args)
    page_slugs = {record["idx"]: record["slug"] + "/" for record in records}
    for record in records:
        render_species_page(args, record, pokemon_data, names, species_to_idx, sprite_map, page_slugs, args.output)
    render_index(records, pokemon_data, sprite_map, args.output)
    eprint(f"generated {len(records)} pages in {args.output}")


def main():
    parser = argparse.ArgumentParser(description="Generate a static Pokémon Violet Pokédex wiki.")
    parser.add_argument("--pokemon-pkl", type=Path, default=Path("bld/index/pokemon.pkl"))
    parser.add_argument("--stats-pkl", type=Path, default=Path("bld/pokeapi/updated.pkl"))
    parser.add_argument("--project", type=Path, default=Path("proj.pmp"))
    parser.add_argument("--output", type=Path, default=Path("docs/pokemon"))
    parser.add_argument("--language", default="LANG_GER")
    parser.add_argument("--clean", action="store_true")
    args = parser.parse_args()
    generate(args)


STYLE_CSS = r"""
:root {
  color-scheme: light;
  --bg: #f7f8fa;
  --panel: #fff;
  --ink: #20242a;
  --muted: #68707d;
  --line: #dce1e8;
  --accent: #7b2cbf;
  --accent-2: #0f8b8d;
}
* { box-sizing: border-box; }
body {
  margin: 0;
  font-family: system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
  color: var(--ink);
  background: var(--bg);
}
a { color: inherit; }
.site-header {
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 14px 24px;
  border-bottom: 1px solid var(--line);
  background: var(--panel);
  position: sticky;
  top: 0;
  z-index: 1;
}
.site-header a { text-decoration: none; font-weight: 700; }
main { width: min(1160px, calc(100% - 32px)); margin: 28px auto 56px; }
.hero, .list-header {
  display: grid;
  grid-template-columns: 180px 1fr;
  gap: 24px;
  align-items: center;
  margin-bottom: 24px;
}
.hero img { width: 160px; height: 160px; object-fit: contain; image-rendering: pixelated; }
.eyebrow { margin: 0 0 6px; color: var(--muted); font-size: 13px; font-weight: 700; text-transform: uppercase; }
h1 { margin: 0 0 10px; font-size: 42px; line-height: 1; }
h2 { margin: 0 0 14px; font-size: 20px; }
.panel {
  background: var(--panel);
  border: 1px solid var(--line);
  border-radius: 8px;
  padding: 18px;
  margin-bottom: 18px;
}
.grid { display: grid; gap: 18px; align-items: start; }
.grid.two { grid-template-columns: repeat(2, minmax(0, 1fr)); }
.info-grid { display: grid; grid-template-columns: repeat(5, minmax(0, 1fr)); gap: 12px; margin: 0; }
.info-grid.compact { grid-template-columns: repeat(2, minmax(0, 1fr)); }
.info-grid div { min-width: 0; }
dt { color: var(--muted); font-size: 12px; font-weight: 700; text-transform: uppercase; }
dd { margin: 3px 0 0; overflow-wrap: anywhere; }
table { width: 100%; border-collapse: collapse; }
th, td { padding: 8px 10px; border-bottom: 1px solid var(--line); text-align: left; vertical-align: top; }
th { color: var(--muted); font-size: 13px; }
.stats td:first-of-type { width: 54px; font-variant-numeric: tabular-nums; }
.total th, .total td { color: var(--ink); font-weight: 800; border-bottom: 0; }
.bar { display: block; height: 10px; border-radius: 999px; background: #edf0f4; overflow: hidden; }
.bar span { display: block; height: 100%; background: linear-gradient(90deg, var(--accent-2), var(--accent)); }
.types { display: flex; gap: 8px; flex-wrap: wrap; }
.type {
  display: inline-flex;
  align-items: center;
  min-height: 24px;
  padding: 2px 9px;
  border-radius: 999px;
  color: #fff;
  background: #69707a;
  font-size: 12px;
  font-weight: 800;
}
.type-pflanze { background: #4f9d4f; }
.type-gift { background: #8e5aa9; }
.type-feuer { background: #d65f32; }
.type-wasser { background: #2f7ecb; }
.type-elektro { background: #c99c18; }
.type-psycho { background: #c75078; }
.type-kampf { background: #aa4b3f; }
.type-boden { background: #9a7438; }
.type-gestein { background: #82714a; }
.type-flug { background: #5e7fbf; }
.type-kaefer { background: #7c9b35; }
.type-geist { background: #5e558f; }
.type-stahl { background: #6b8793; }
.type-fee { background: #c96ca6; }
.type-eis { background: #4f9caf; }
.type-drache { background: #695bc6; }
.type-unlicht { background: #4c4141; }
.chip-list, .evolution-list { margin: 0; padding: 0; list-style: none; display: flex; flex-wrap: wrap; gap: 8px; }
.chip-list li, .evolution-list li {
  padding: 6px 9px;
  border: 1px solid var(--line);
  border-radius: 999px;
  background: #fafbfc;
  font-size: 13px;
}
.evolution-list li { display: flex; gap: 8px; border-radius: 8px; }
.evolution-list span, .muted { color: var(--muted); }
.pokemon-grid { display: grid; grid-template-columns: repeat(auto-fill, minmax(170px, 1fr)); gap: 12px; }
.pokemon-card {
  display: grid;
  grid-template-columns: 56px 1fr;
  grid-template-rows: auto auto auto;
  gap: 2px 10px;
  align-items: center;
  padding: 12px;
  text-decoration: none;
  border: 1px solid var(--line);
  border-radius: 8px;
  background: var(--panel);
}
.pokemon-card:hover { border-color: var(--accent); }
.pokemon-card img { grid-row: 1 / 4; width: 54px; height: 54px; object-fit: contain; image-rendering: pixelated; }
.pokemon-card span { color: var(--muted); font-size: 12px; }
.pokemon-card strong { overflow-wrap: anywhere; }
.pokemon-card small { display: flex; gap: 4px; flex-wrap: wrap; }
.pokemon-card small .type { min-height: 18px; padding: 1px 6px; font-size: 10px; }
.search { display: grid; gap: 6px; justify-self: end; color: var(--muted); font-weight: 700; }
.search input { width: min(360px, 70vw); padding: 10px 12px; border: 1px solid var(--line); border-radius: 8px; font: inherit; }
@media (max-width: 760px) {
  main { width: min(100% - 20px, 1160px); margin-top: 18px; }
  .hero, .list-header, .grid.two { grid-template-columns: 1fr; }
  .hero img { width: 128px; height: 128px; }
  h1 { font-size: 34px; }
  .info-grid, .info-grid.compact { grid-template-columns: repeat(2, minmax(0, 1fr)); }
  .search { justify-self: stretch; }
  .search input { width: 100%; }
}
"""


SEARCH_JS = r"""
const input = document.getElementById("pokemon-search");
const cards = Array.from(document.querySelectorAll(".pokemon-card"));
if (input) {
  input.addEventListener("input", () => {
    const query = input.value.trim().toLowerCase();
    for (const card of cards) {
      card.hidden = query && !card.dataset.search.includes(query);
    }
  });
}
"""


if __name__ == "__main__":
    main()
