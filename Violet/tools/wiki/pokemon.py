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

from PIL import Image
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

TYPE_THEMES = {
    "TYPE_NORMAL": {"accent": "#7f7c73", "accent_2": "#a39f95", "soft": "#f1eee6", "line": "#d7d1c7", "ink": "#3b382f"},
    "TYPE_PFLANZE": {"accent": "#4d8f43", "accent_2": "#8fb46c", "soft": "#edf6e8", "line": "#bfd7af", "ink": "#22481b"},
    "TYPE_GIFT": {"accent": "#7e4f99", "accent_2": "#a67ac0", "soft": "#f2eaf7", "line": "#d0b8df", "ink": "#432654"},
    "TYPE_FEUER": {"accent": "#c6572c", "accent_2": "#eb9b61", "soft": "#fff0e6", "line": "#f0c49e", "ink": "#5a2411"},
    "TYPE_WASSER": {"accent": "#2f70bf", "accent_2": "#6fa9e2", "soft": "#eaf3fe", "line": "#bfd4ef", "ink": "#17385f"},
    "TYPE_ELEKTRO": {"accent": "#bb9313", "accent_2": "#e4c048", "soft": "#fff8df", "line": "#edd99b", "ink": "#5f4600"},
    "TYPE_PSYCHO": {"accent": "#bd5576", "accent_2": "#df8ca6", "soft": "#feeff4", "line": "#ebc2d0", "ink": "#5d2137"},
    "TYPE_KAMPF": {"accent": "#a54a3a", "accent_2": "#c87a67", "soft": "#fbeeea", "line": "#e0bbb2", "ink": "#4f1f18"},
    "TYPE_BODEN": {"accent": "#9a7438", "accent_2": "#c2a06a", "soft": "#f7f1e5", "line": "#ddccab", "ink": "#4c3818"},
    "TYPE_GESTEIN": {"accent": "#87724c", "accent_2": "#b4a072", "soft": "#f4f0e4", "line": "#d7ceb2", "ink": "#433723"},
    "TYPE_FLUG": {"accent": "#5d7aba", "accent_2": "#91a8dc", "soft": "#eef2fb", "line": "#c6d1ee", "ink": "#26385e"},
    "TYPE_KAEFER": {"accent": "#739032", "accent_2": "#a2bd61", "soft": "#f0f6e3", "line": "#cadca8", "ink": "#37461a"},
    "TYPE_GEIST": {"accent": "#5d5489", "accent_2": "#8e86b8", "soft": "#efedf7", "line": "#c7c3de", "ink": "#2d2747"},
    "TYPE_STAHL": {"accent": "#607e8b", "accent_2": "#95afbb", "soft": "#edf3f6", "line": "#c3d2d9", "ink": "#263b45"},
    "TYPE_FEE": {"accent": "#c06399", "accent_2": "#e3a0c3", "soft": "#fdf0f7", "line": "#edc0d8", "ink": "#5d2242"},
    "TYPE_EIS": {"accent": "#4d98ab", "accent_2": "#83c6d7", "soft": "#e8f6f9", "line": "#b7dde4", "ink": "#1f4a54"},
    "TYPE_DRACHE": {"accent": "#6556bf", "accent_2": "#988de0", "soft": "#efedfe", "line": "#c8c3ef", "ink": "#302564"},
    "TYPE_UNLICHT": {"accent": "#4b423f", "accent_2": "#7d716e", "soft": "#f1edeb", "line": "#d1c8c4", "ink": "#26201e"},
}

DEFAULT_THEME = {"accent": "#486678", "accent_2": "#7da1b3", "soft": "#edf4f7", "line": "#c8d7df", "ink": "#203741"}

LABEL_OVERRIDES = {
    "LANG_GER": {
        "TYPE_NORMAL": "Normal",
        "TYPE_PFLANZE": "Pflanze",
        "TYPE_GIFT": "Gift",
        "TYPE_FEUER": "Feuer",
        "TYPE_WASSER": "Wasser",
        "TYPE_ELEKTRO": "Elektro",
        "TYPE_PSYCHO": "Psycho",
        "TYPE_KAMPF": "Kampf",
        "TYPE_BODEN": "Boden",
        "TYPE_GESTEIN": "Gestein",
        "TYPE_FLUG": "Flug",
        "TYPE_KAEFER": "Käfer",
        "TYPE_GEIST": "Geist",
        "TYPE_STAHL": "Stahl",
        "TYPE_FEE": "Fee",
        "TYPE_EIS": "Eis",
        "TYPE_DRACHE": "Drache",
        "TYPE_UNLICHT": "Unlicht",
        "POKEMON_COLOR_GRUEN": "Grün",
        "POKEMON_COLOR_BLAU": "Blau",
        "POKEMON_COLOR_BRAUN": "Braun",
        "POKEMON_COLOR_GELB": "Gelb",
        "POKEMON_COLOR_GRAU": "Grau",
        "POKEMON_COLOR_ROSA": "Rosa",
        "POKEMON_COLOR_ROT": "Rot",
        "POKEMON_COLOR_SCHWARZ": "Schwarz",
        "POKEMON_COLOR_VIOLETT": "Violett",
        "POKEMON_COLOR_WEISS": "Weiß",
        "SHAPE_QUADRUPED": "Vierbeinig",
        "SHAPE_HUMANOID": "Humanoid",
        "SHAPE_UPRIGHT": "Aufrecht",
        "SHAPE_SQUIGGLE": "Schlängelnd",
        "SHAPE_BUG_WINGS": "Käferflügel",
        "SHAPE_WINGS": "Flügel",
        "SHAPE_ARMOR": "Panzer",
        "SHAPE_BLOB": "Blob",
        "SHAPE_ARMS": "Arme",
        "SHAPE_LEGS": "Beine",
        "SHAPE_TENTACLES": "Tentakel",
        "SHAPE_FISH": "Fisch",
        "SHAPE_BALL": "Rund",
        "SHAPE_HEADS": "Mehrköpfig",
        "GROWTH_RATE_MEDIUM": "Mittel",
        "GROWTH_RATE_MEDIUM_SLOW": "Mittel-Langsam",
        "GROWTH_RATE_FAST": "Schnell",
        "GROWTH_RATE_SLOW": "Langsam",
        "GROWTH_RATE_SLOW_THEN_VERY_FAST": "Spät sehr schnell",
        "GROWTH_RATE_FAST_THEN_VERY_SLOW": "Früh schnell, später langsam",
        "EGG_GROUP_MONSTER": "Monster",
        "EGG_GROUP_WASSER_1": "Wasser 1",
        "EGG_GROUP_WASSER_2": "Wasser 2",
        "EGG_GROUP_WASSER_3": "Wasser 3",
        "EGG_GROUP_KAEFER": "Käfer",
        "EGG_GROUP_FLUG": "Flug",
        "EGG_GROUP_FELD": "Feld",
        "EGG_GROUP_FEE": "Fee",
        "EGG_GROUP_PFLANZE": "Pflanze",
        "EGG_GROUP_HUMANOTYP": "Humanotyp",
        "EGG_GROUP_MINERAL": "Mineral",
        "EGG_GROUP_AMORPH": "Amorph",
        "EGG_GROUP_DITTO": "Ditto",
        "EGG_GROUP_DRACHE": "Drache",
        "EGG_GROUP_UNBEKANNT": "Unbekannt",
        "Quadruped": "Vierbeinig",
        "Humanoid": "Humanoid",
        "Upright": "Aufrecht",
        "Fish": "Fisch",
        "Blob": "Blob",
        "Legs": "Beine",
        "Arms": "Arme",
        "Wings": "Flügel",
        "Monster": "Monster",
        "Pflanze": "Pflanze",
        "Wasser 1": "Wasser 1",
        "Wasser 2": "Wasser 2",
        "Wasser 3": "Wasser 3",
        "Feld": "Feld",
        "Fee": "Fee",
        "Mineral": "Mineral",
        "Amorph": "Amorph",
        "Drache": "Drache",
        "Unbekannt": "Unbekannt",
        "medium": "Mittel",
        "medium-slow": "Mittel-Langsam",
        "fast": "Schnell",
        "slow": "Langsam",
        "Level_Up": "Levelaufstieg",
        "Friendship": "Freundschaft",
        "Friendship_Day": "Freundschaft (Tag)",
        "Friendship_Night": "Freundschaft (Nacht)",
        "Trade": "Tausch",
        "Stone": "Stein",
        "Know_Move": "Kennt Attacke",
        "Know_Move_Type": "Kennt Typ-Attacke",
        "Hold_Item": "Getragenes Item",
        "Hold_Item_and_Day": "Item am Tag",
        "Hold_Item_and_Night": "Item bei Nacht",
        "Link_Cable_and_Item": "Linkkabel und Item",
        "On_Map": "Auf Karte",
        "CATEGORY_PHYSICAL": "Physisch",
        "CATEGORY_SPECIAL": "Spezial",
        "CATEGORY_STATUS": "Status",
    },
    "LANG_EN": {},
}


def eprint(message):
    print(f"pokemon wiki: {message}", file=sys.stderr)


def strip_jsonc_comments(text):
    result = []
    idx = 0
    in_string = None
    escaped = False
    while idx < len(text):
        char = text[idx]
        next_char = text[idx + 1] if idx + 1 < len(text) else ""
        if in_string:
            result.append(char)
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif char == in_string:
                in_string = None
            idx += 1
            continue
        if char in ('"', "'"):
            in_string = char
            result.append(char)
            idx += 1
            continue
        if char == "/" and next_char == "/":
            idx += 2
            while idx < len(text) and text[idx] not in "\r\n":
                idx += 1
            continue
        if char == "/" and next_char == "*":
            idx += 2
            while idx + 1 < len(text) and not (text[idx] == "*" and text[idx + 1] == "/"):
                idx += 1
            idx += 2
            continue
        result.append(char)
        idx += 1
    return "".join(result)


def load_pickle(path):
    with open(path, "rb") as f:
        return pickle.load(f)


def load_jsonc_payload(path):
    try:
        return json.loads(strip_jsonc_comments(Path(path).read_text(encoding="utf-8")))
    except FileNotFoundError:
        return None


def load_json_data(path):
    payload = load_jsonc_payload(path)
    return payload.get("data") if payload else None


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


def display_value(value, prefixes=(), language="LANG_GER"):
    if value is None or value == 0 or value == "ABILITY_NONE" or value == "ITEM_NONE":
        return "-"
    if isinstance(value, str):
        override = LABEL_OVERRIDES.get(language, {}).get(value)
        if override:
            return override
    normalized = normalize_constant(value, prefixes) or "-"
    override = LABEL_OVERRIDES.get(language, {}).get(normalized)
    if override:
        return override
    return normalized


def theme_key_for_type(type_name):
    if type_name in TYPE_THEMES:
        return type_name
    if not isinstance(type_name, str):
        return None
    normalized = normalize_constant(type_name, ("TYPE_",))
    if not normalized:
        return None
    for key in TYPE_THEMES:
        if normalize_constant(key, ("TYPE_",)) == normalized:
            return key
    for language_overrides in LABEL_OVERRIDES.values():
        for key, label in language_overrides.items():
            if key.startswith("TYPE_") and label == type_name:
                return key
    return None


def type_theme(*types):
    for type_name in types:
        key = theme_key_for_type(type_name)
        if key:
            return TYPE_THEMES[key]
    return DEFAULT_THEME


def normalized_types(values):
    normalized = []
    seen = set()
    for value in values:
        if not value:
            continue
        key = theme_key_for_type(value) or str(value)
        if key in seen:
            continue
        seen.add(key)
        normalized.append(value)
    return normalized


def slugify(value):
    value = unicodedata.normalize("NFKD", value).encode("ascii", "ignore").decode("ascii")
    value = re.sub(r"[^a-zA-Z0-9]+", "-", value.lower()).strip("-")
    return value or "pokemon"


def clean_entry_text(value):
    if not value:
        return ""
    return str(value).replace("\\xFE", " ").replace("\xFE", " ").replace("\\n", " ").strip()


def form_name(species_constant, readable, language="LANG_GER"):
    constant_name = display_value(species_constant, ("POKEMON_",), language)
    base_name = language_value(readable.get("name"), language)
    if base_name and constant_name == base_name:
        return base_name
    return constant_name


def constants_by_value(project, table_name):
    return {value: key for key, value in project.constants[table_name].items()}


def parse_frontsprites(path):
    sprite_map = {}
    text = Path(path).read_text(encoding="utf-8")
    pattern = re.compile(r"\[(POKEMON_[A-Z0-9_]+)\].*?gfx_pokemon_([a-z0-9_]+)_frontspriteTiles")
    for species_constant, sprite_slug in pattern.findall(text):
        sprite_map[species_constant] = sprite_slug
    return sprite_map


def parse_mega_evolutions(path):
    if not Path(path).exists():
        eprint(f"warning: missing mega evolution data {path}")
        return {}
    payload = load_jsonc_payload(path) or {}
    evolutions = {}
    for entry in payload.get("data", []):
        species = entry["species"]
        item = entry["mega_item"]
        mega_species = entry["mega_species"]
        evolution_type = entry["type"]
        evolutions[mega_species] = {
            "species": species,
            "item": item,
            "mega_species": mega_species,
            "type": evolution_type,
        }
    return evolutions


def parse_attacks(path, project):
    payload = load_jsonc_payload(path)
    if not payload:
        eprint(f"warning: missing attacks data {path}")
        return {}
    entries = payload.get("data", [])
    attack_by_index = constants_by_value(project, "attacks")
    attacks = {}
    for idx, entry in enumerate(entries):
        attack_constant = attack_by_index.get(idx)
        if attack_constant:
            attacks[attack_constant] = entry
    return attacks


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


def item_list(values, prefixes=(), limit=None, language="LANG_GER"):
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
        items.append(f"<li>{escape(display_value(value, prefixes, language))}</li>")
    if limit is not None and len(values) > limit:
        items.append(f"<li class=\"muted\">und {len(values) - limit} weitere</li>")
    return "<ul class=\"chip-list\">" + "".join(items) + "</ul>"


def indexed_pokemon_value(pokemon_data, key, idx, fallback=None):
    values = pokemon_data.get(key)
    if isinstance(values, (list, tuple)) and idx < len(values):
        return values[idx]
    return fallback


def normalized_evolution_entries(entries):
    entries = entries or []
    if isinstance(entries, dict):
        return [
            {"target": target, "method": details.get("trigger"), "argument": details.get("argument"),
             "baby_trigger_item": details.get("baby_trigger_item")}
            for target, details in entries.items()
        ]
    return entries


def build_pre_evolution_map(pokemon_data, species_to_idx):
    pre_evolutions = {}
    for source_idx, entries in enumerate(pokemon_data.get("evolutions") or []):
        for evo in normalized_evolution_entries(entries):
            if not isinstance(evo, dict):
                continue
            target = evo.get("target")
            target_idx = species_to_idx.get(target) if isinstance(target, str) else None
            if target_idx is None:
                continue
            current_source = pre_evolutions.get(target_idx)
            if current_source is None or source_idx < current_source:
                pre_evolutions[target_idx] = source_idx
    return pre_evolutions


def base_species_idx(pre_evolutions, idx):
    seen = set()
    while idx in pre_evolutions and idx not in seen:
        seen.add(idx)
        idx = pre_evolutions[idx]
    return idx


def inherited_egg_moves(pokemon_data, idx, pre_evolutions):
    own_egg_moves = indexed_pokemon_value(pokemon_data, "egg_moves", idx)
    if own_egg_moves:
        return own_egg_moves
    base_idx = base_species_idx(pre_evolutions, idx)
    if base_idx == idx:
        return own_egg_moves
    return indexed_pokemon_value(pokemon_data, "egg_moves", base_idx, own_egg_moves)


def render_type_badges(types, language="LANG_GER", variant="solid"):
    badges = []
    for type_name in dict.fromkeys(t for t in types if t):
        label = display_value(type_name, ("TYPE_",), language)
        theme = type_theme(type_name)
        if variant == "soft":
            style = (
                f"--type-accent:{theme['soft']};"
                f"--type-line:{theme['line']};"
                f"--type-ink:{theme['ink']};"
            )
        else:
            style = (
                f"--type-accent:{theme['accent']};"
                f"--type-line:{theme['accent']};"
                f"--type-ink:#ffffff;"
            )
        badges.append(
            f"<span class=\"type type-{variant}\" style=\"{style}\">{escape(label)}</span>"
        )
    return "".join(badges)


def attack_table(entries, attack_details, language="LANG_GER", criterion_label=None):
    if isinstance(entries, int):
        return "<p class=\"muted\">Nicht verfügbar: altes pokemon.pkl enthält nur den fehlerhaften Indexwert.</p>"
    if not entries:
        return "<p class=\"muted\">-</p>"
    show_criterion = criterion_label is not None
    rows = []
    for entry in entries:
        criterion = None
        move = None
        if isinstance(entry, dict):
            move = entry.get("move")
            if "level" in entry:
                level = entry.get("level")
                criterion = "Evo" if level == 0 else str(level)
        elif isinstance(entry, str):
            move = entry
        elif isinstance(entry, (tuple, list)) and len(entry) == 2:
            left, right = entry
            if isinstance(left, (tuple, list)) and len(left) == 2:
                machine, move = left, right
                criterion = f"{machine[0]}{int(machine[1]):02d}"
            elif isinstance(right, (tuple, list)) and len(right) == 2:
                move, machine = left, right
                criterion = f"{machine[0]}{int(machine[1]):02d}"
            elif isinstance(left, int):
                criterion = str(left)
                move = right
            else:
                move, criterion = left, right
        if not move:
            continue
        detail = attack_details.get(move, {})
        cells = []
        if show_criterion:
            cells.append(f"<td>{escape(criterion or '-')}</td>")
        cells.append(f"<td>{escape(display_value(move, ('ATTACK_',), language))}</td>")
        cells.append(f"<td>{render_type_badges([detail.get('type')], language, 'soft') if detail.get('type') else '-'}</td>")
        rows.append("<tr>" + "".join(cells) + "</tr>")
    if not rows:
        return "<p class=\"muted\">-</p>"
    headers = []
    if show_criterion:
        headers.append(f"<th>{escape(criterion_label)}</th>")
    headers.extend([
        "<th>Attacke</th>",
        "<th>Typ</th>",
    ])
    return "<table><thead><tr>" + "".join(headers) + "</tr></thead><tbody>" + "".join(rows) + "</tbody></table>"


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


def format_evolution_argument(evo, language="LANG_GER"):
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
    return display_value(arg, ("ITEM_", "ATTACK_", "TYPE_"), language)


def evolution_list(entries, species_to_idx, names, page_slugs, language="LANG_GER"):
    entries = normalized_evolution_entries(entries)
    if not entries:
        return "<p class=\"muted\">-</p>"
    items = []
    for evo in entries:
        target = evo.get("target")
        target_idx = species_to_idx.get(target) if isinstance(target, str) else None
        method = display_value(evo.get("method") or evo.get("trigger"), ("EVOLUTION_METHOD_",), language)
        argument = format_evolution_argument(evo, language)
        baby_item = display_value(evo.get("baby_trigger_item"), ("ITEM_",), language)
        target_name = names.get(target_idx, display_value(target, ("POKEMON_",), language))
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

    # The source sprites are indexed 4bpp PNGs where palette index 0 is meant
    # to be transparent for the game engine. Convert them to RGBA for the web.
    img = Image.open(src).convert("RGBA")
    transparent = Image.new("RGBA", img.size, (0, 0, 0, 0))
    alpha_mask = Image.open(src)
    alpha = alpha_mask.point(lambda px: 0 if px == 0 else 255, mode="1")
    transparent.paste(img, mask=alpha)
    transparent.save(dst)

    return f"../../assets/sprites/{src.name}"


def write_assets(assets_dir):
    assets_dir.mkdir(parents=True, exist_ok=True)
    (assets_dir / "style.css").write_text(STYLE_CSS, encoding="utf-8")
    (assets_dir / "search.js").write_text(SEARCH_JS, encoding="utf-8")


def build_records(args):
    pokemon_data = load_pickle(args.pokemon_pkl)
    readable_stats = load_pickle(args.stats_pkl) if args.stats_pkl.exists() else []
    raw_updates = load_jsonc_payload(args.updates_json) if args.updates_json.exists() else {}
    generated_names = load_json_data(Path("bld/pokeapi/pokemon_names.pms")) or []
    project = Project(str(args.project))
    species_to_idx = dict(project.constants["species"].items())
    idx_to_species = constants_by_value(project, "species")
    sprite_map = parse_frontsprites("include/c/data/pokemon/frontsprites.h")
    mega_evolutions = parse_mega_evolutions(args.mega_evolutions_pms)
    attack_details = parse_attacks(args.attacks_pms, project)
    shifted_order = detect_shifted_pokedex_order(pokemon_data)
    pokemon_data["_pre_evolutions"] = build_pre_evolution_map(pokemon_data, species_to_idx)
    pokemon_data["_attack_details"] = attack_details

    all_species_rows = []
    species_rows = []
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
        row = {
            "idx": idx,
            "species_constant": species_constant,
            "name": name,
            "dex_number": dex_number,
            "readable": readable,
            "pkl_entry": pkl_entry,
            "dex_text": clean_entry_text(dex_text),
            "genus": genus,
            "updates": raw_updates.get(species_constant, {}),
        }
        all_species_rows.append(row)
        if not isinstance(dex_number, int) or dex_number <= 0:
            continue
        species_rows.append(row)

    records = []
    page_slugs = {}
    for dex_number in sorted({row["dex_number"] for row in species_rows}):
        rows = [row for row in species_rows if row["dex_number"] == dex_number]
        rows.sort(key=lambda row: (1 if row["readable"].get("species_link") else 0, row["idx"]))
        record = dict(rows[0])
        record["alt_species"] = rows[1:]
        record["alternate_forms"] = []
        record["mega_forms"] = []
        record["slug"] = f"{dex_number:03d}-{slugify(record['name'])}"
        records.append(record)
        for row in rows:
            page_slugs[row["idx"]] = record["slug"] + "/"

    record_by_species = {record["species_constant"]: record for record in records}
    for row in all_species_rows:
        species_constant = row["species_constant"]
        linked_species = row["readable"].get("species_link") or row["updates"].get("species_link")
        if not linked_species or linked_species == species_constant:
            continue
        record = record_by_species.get(linked_species)
        if not record:
            linked_idx = species_to_idx.get(linked_species)
            linked_dex = dex_number_for(pokemon_data, linked_idx, shifted_order) if linked_idx is not None else None
            record = next((candidate for candidate in records if candidate["dex_number"] == linked_dex), None)
        if not record:
            eprint(f"warning: no base page found for alternate form {species_constant} -> {linked_species}")
            continue
        form = dict(row)
        form["base_species_constant"] = linked_species
        form["display_name"] = form_name(species_constant, row["readable"], args.language)
        form["mega_evolution"] = mega_evolutions.get(species_constant)
        target = "mega_forms" if form["mega_evolution"] else "alternate_forms"
        if form not in record[target]:
            record[target].append(form)
        page_slugs[row["idx"]] = record["slug"] + "/"

    for record in records:
        record["alternate_forms"].sort(key=lambda form: (form["dex_number"] or 0, form["idx"]))
        record["mega_forms"].sort(key=lambda form: (form["mega_evolution"]["type"], form["idx"]))
    return pokemon_data, records, names, species_to_idx, sprite_map, page_slugs


def render_info_grid(record, stats, language="LANG_GER"):
    readable = record["readable"]
    pkl_entry = record["pkl_entry"]
    values = [
        ("Pokédex", record["dex_number"] if record["dex_number"] is not None else "-"),
        ("Art", record["genus"] or "-"),
        ("Größe", f"{(readable.get('height', pkl_entry.get('height', 0)) or 0) / 10:g} m"),
        ("Gewicht", f"{(readable.get('weight', pkl_entry.get('weight', 0)) or 0) / 10:g} kg"),
        ("Farbe", preferred_value(record, "color", stats.get("color_and_flip", {}).get("color"), language, ("POKEMON_COLOR_",))),
        ("Form", preferred_value(record, "shape", stats.get("shape"), language, ("SHAPE_",))),
        ("Fangrate", stats.get("capture_rate", "-")),
        ("EP", stats.get("exp_yield", "-")),
        ("Zuneigung", stats.get("base_happiness", "-")),
        ("Safari", stats.get("safari_rate", "-")),
    ]
    return "<dl class=\"info-grid\">" + "".join(f"<div><dt>{escape(k)}</dt><dd>{escape(v)}</dd></div>" for k, v in values) + "</dl>"


def preferred_value(record, key, fallback, language="LANG_GER", prefixes=()):
    readable = record["readable"].get(key)
    if readable not in (None, 0, "", []):
        return display_value(readable, prefixes, language)
    return display_value(fallback, prefixes, language)


def render_fact_table(pairs):
    rows = []
    for key, value in pairs:
        rows.append(f"<tr><th>{escape(key)}</th><td>{escape(value)}</td></tr>")
    return "<table class=\"fact-table\"><tbody>" + "".join(rows) + "</tbody></table>"


def stats_from(row, pokemon_data):
    idx = row["idx"]
    if idx < len(pokemon_data.get("basestats", [])):
        return pokemon_data["basestats"][idx] or {}
    return {}


def value_from(row, stats, key):
    readable = row["readable"]
    if key in readable and readable[key] not in (None, "", []):
        return readable[key]
    return stats.get(key)


def render_stat_delta_table(base_stats, form_stats):
    rows = []
    base_values = base_stats.get("basestats", {})
    form_values = form_stats.get("basestats", {})
    for stat in STATS:
        base_value = int(base_values.get(stat, 0))
        form_value = int(form_values.get(stat, 0))
        delta = form_value - base_value
        delta_text = f"+{delta}" if delta > 0 else str(delta)
        rows.append(
            f"<tr><th>{STAT_LABELS[stat]}</th><td>{form_value}</td>"
            f"<td class=\"delta {'positive' if delta > 0 else 'negative' if delta < 0 else 'neutral'}\">{escape(delta_text)}</td></tr>"
        )
    return "<table class=\"stats form-stats\"><thead><tr><th>Wert</th><th>Form</th><th>Δ</th></tr></thead><tbody>" + "".join(rows) + "</tbody></table>"


def render_form_changes(args, form, base_record, pokemon_data, species_to_idx, names, page_slugs):
    updates = form.get("updates") or {}
    base_stats = stats_from(base_record, pokemon_data)
    form_stats = stats_from(form, pokemon_data)
    rows = []

    if "type_0" in updates or "type_1" in updates:
        types = normalized_types([value_from(form, form_stats, "type_0"), value_from(form, form_stats, "type_1")])
        rows.append(("Typ", render_type_badges(types, args.language, "soft") or "-"))

    ability_keys = [key for key in ("ability_0", "ability_1", "hidden_ability") if key in updates]
    if ability_keys:
        abilities = []
        for key in ability_keys:
            label = {
                "ability_0": "Fähigkeit 1",
                "ability_1": "Fähigkeit 2",
                "hidden_ability": "Versteckte Fähigkeit",
            }[key]
            abilities.append(f"{label}: {display_value(value_from(form, form_stats, key), ('ABILITY_',), args.language)}")
        rows.append(("Fähigkeiten", "<br>".join(escape(value) for value in abilities)))

    for key, label, prefixes in (
        ("exp_yield", "EP", ()),
        ("capture_rate", "Fangrate", ()),
        ("safari_rate", "Safari", ()),
        ("common_item", "Häufiges Item", ("ITEM_",)),
        ("rare_item", "Seltenes Item", ("ITEM_",)),
        ("growth_rate", "Wachstum", ("GROWTH_RATE_",)),
        ("egg_group_0", "Ei-Gruppe 1", ("EGG_GROUP_",)),
        ("egg_group_1", "Ei-Gruppe 2", ("EGG_GROUP_",)),
    ):
        if key in updates:
            rows.append((label, escape(display_value(value_from(form, form_stats, key), prefixes, args.language))))

    if form.get("mega_evolution"):
        mega = form["mega_evolution"]
        rows.insert(0, (
            "Auslöser",
            escape(display_value(mega["item"], ("ITEM_",), args.language)),
        ))

    if not rows:
        rows.append(("Änderungen", escape(", ".join(sorted(k for k in updates if k not in ("species_link", "dex_number"))) or "-")))

    body = "<table class=\"fact-table form-change-table\"><tbody>"
    body += "".join(f"<tr><th>{escape(label)}</th><td>{value}</td></tr>" for label, value in rows)
    body += "</tbody></table>"

    if "basestats" in updates:
        body += render_stat_delta_table(base_stats, form_stats)
    if "evolutions" in updates:
        body += f"<div class=\"form-subsection\"><h3>Entwicklung</h3>{evolution_list(value_from(form, form_stats, 'evolutions'), species_to_idx, names, page_slugs, args.language)}</div>"
    return body


def render_form_section(args, title, forms, base_record, pokemon_data, species_to_idx, names, sprite_map, page_slugs, output_dir):
    if not forms:
        return ""
    cards = []
    for form in forms:
        form_stats = stats_from(form, pokemon_data)
        types = normalized_types([value_from(form, form_stats, "type_0"), value_from(form, form_stats, "type_1")])
        theme = type_theme(*types)
        sprite_src = copy_sprite(form["species_constant"], sprite_map, output_dir / "assets")
        sprite_html = f"<img src=\"{escape(sprite_src)}\" alt=\"{escape(form['display_name'])}\">" if sprite_src else ""
        if form.get("mega_evolution"):
            kind = "Mega-Entwicklung" if form["mega_evolution"]["type"] == "MEGA_EVOLUTION" else "Regent-Entwicklung"
        else:
            kind = "Alternative Form"
        cards.append(
            f"<article class=\"form-card\" style=\"--card-accent:{theme['accent']};--card-soft:{theme['soft']};--card-line:{theme['line']};--card-ink:{theme['ink']};\">"
            f"<div class=\"form-sprite\">{sprite_html}</div>"
            f"<div class=\"form-body\"><p class=\"eyebrow\">{escape(kind)} · Species #{escape(form['idx'])}</p>"
            f"<h3>{escape(form['display_name'])}</h3>"
            f"{render_form_changes(args, form, base_record, pokemon_data, species_to_idx, names, page_slugs)}</div>"
            f"</article>"
        )
    return f"<section class=\"panel\"><h2>{escape(title)}</h2><div class=\"form-grid\">{''.join(cards)}</div></section>"


def render_species_page(args, record, pokemon_data, names, species_to_idx, sprite_map, page_slugs, output_dir):
    idx = record["idx"]
    stats = pokemon_data["basestats"][idx] or {}
    readable = record["readable"]
    sprite_src = copy_sprite(record["species_constant"], sprite_map, output_dir / "assets")
    types = normalized_types([readable.get("type_0") or stats.get("type_0"), readable.get("type_1") or stats.get("type_1")])
    page_theme = type_theme(*types)
    type_badges = render_type_badges(types, args.language)
    ability_values = [readable.get("ability_0") or stats.get("ability_0"), readable.get("ability_1") or stats.get("ability_1")]
    abilities = " / ".join(display_value(v, ("ABILITY_",), args.language) for v in ability_values if display_value(v, ("ABILITY_",), args.language) != "-") or "-"
    hidden_ability = display_value(readable.get("hidden_ability") or stats.get("hidden_ability"), ("ABILITY_",), args.language)
    held_items = " / ".join(
        display_value(v, ("ITEM_",), args.language) for v in (readable.get("common_item") or stats.get("common_item"), readable.get("rare_item") or stats.get("rare_item")) if display_value(v, ("ITEM_",), args.language) != "-"
    ) or "-"
    ev_yield = ", ".join(
        f"{STAT_LABELS[s]} +{stats.get('ev_yield', {}).get(s)}"
        for s in STATS if stats.get("ev_yield", {}).get(s)
    ) or "-"
    alternate_forms_html = render_form_section(
        args, "Alternative Formen", record.get("alternate_forms", []), record,
        pokemon_data, species_to_idx, names, sprite_map, page_slugs, output_dir
    )
    mega_forms_html = render_form_section(
        args, "Mega / Regent-Entwicklungen", record.get("mega_forms", []), record,
        pokemon_data, species_to_idx, names, sprite_map, page_slugs, output_dir
    )
    levelup_moves = indexed_pokemon_value(pokemon_data, "levelup_moves", idx, readable.get("levelup_moves"))
    egg_moves = inherited_egg_moves(pokemon_data, idx, pokemon_data.get("_pre_evolutions", {}))
    accessible_moves = indexed_pokemon_value(pokemon_data, "accessible_moves", idx, readable.get("accessible_moves"))
    attack_details = pokemon_data.get("_attack_details", {})
    tm_hm_compatibility = indexed_pokemon_value(
        pokemon_data,
        "tm_hm_compatibility",
        idx,
        readable.get("tm_compatibility") or readable.get("tm_compatiblilty"),
    )
    move_tutor_compatibility = indexed_pokemon_value(
        pokemon_data,
        "move_tutor_compatibility",
        idx,
        readable.get("tutor_compatibility"),
    )

    sprite_html = f"<img src=\"{escape(sprite_src)}\" alt=\"{escape(record['name'])}\">" if sprite_src else ""
    infobox_top = render_fact_table([
        ("Typ", " / ".join(display_value(t, ("TYPE_",), args.language) for t in types if t)),
        ("Pokédex", f"#{record['dex_number']}"),
        ("Art", record["genus"] or "-"),
        ("Größe", f"{(readable.get('height', record['pkl_entry'].get('height', 0)) or 0) / 10:g} m"),
        ("Gewicht", f"{(readable.get('weight', record['pkl_entry'].get('weight', 0)) or 0) / 10:g} kg"),
        ("Farbe", preferred_value(record, "color", stats.get("color_and_flip", {}).get("color"), args.language, ("POKEMON_COLOR_",))),
    ])
    infobox_training = render_fact_table([
        ("Fähigkeiten", abilities),
        ("Versteckte Fähigkeit", hidden_ability),
        ("Items", held_items),
        ("Fangrate", stats.get("capture_rate", "-")),
        ("Zuneigung", stats.get("base_happiness", "-")),
        ("Ei-Gruppen", f"{preferred_value(record, 'egg_group_0', stats.get('egg_group_0'), args.language, ('EGG_GROUP_',))} / {preferred_value(record, 'egg_group_1', stats.get('egg_group_1'), args.language, ('EGG_GROUP_',))}"),
        ("Ei-Zyklen", stats.get("egg_cycles", "-")),
        ("Wachstum", preferred_value(record, 'growth_rate', stats.get("growth_rate"), args.language, ("GROWTH_RATE_",))),
        ("EV-Ertrag", ev_yield),
    ])
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
  <main style="--page-accent:{page_theme['accent']};--page-accent-2:{page_theme['accent_2']};--page-soft:{page_theme['soft']};--page-line:{page_theme['line']};--page-ink:{page_theme['ink']};">
    <section class="species-layout">
      <aside class="infobox">
        <div class="infobox-head">
          <p class="eyebrow">Pokédex #{escape(record['dex_number'])}</p>
          <h1>{escape(record['name'])}</h1>
          <div class="types">{type_badges}</div>
        </div>
        <div class="sprite-frame">{sprite_html}</div>
        <section class="infobox-section">
          <h2>Allgemeine Informationen</h2>
          {infobox_top}
        </section>
        <section class="infobox-section">
          <h2>Fangen, Training und Zucht</h2>
          {infobox_training}
        </section>
      </aside>
      <div class="article-column">
        <section class="lead-card">
          <p class="eyebrow">Species #{escape(record['idx'])} · {escape(record['species_constant'])}</p>
          <p class="lead-copy">{escape(record['dex_text']) if record['dex_text'] else ''}</p>
        </section>
        <section class="panel panel-soft">
          <h2>Übersicht</h2>
          {render_info_grid(record, stats, args.language)}
        </section>
        <section class="panel">
          <h2>Basiswerte</h2>
          {stat_table(stats.get('basestats', {}))}
        </section>
        {alternate_forms_html}
        {mega_forms_html}
        <section class="panel">
          <h2>Entwicklung</h2>
          {evolution_list(readable.get('evolutions') or pokemon_data.get('evolutions', [None])[idx], species_to_idx, names, page_slugs, args.language)}
        </section>
        <section class="grid two">
          <article class="panel"><h2>Level-Up Attacken</h2>{attack_table(levelup_moves, attack_details, args.language, "Level")}</article>
          <article class="panel"><h2>TM/VM</h2>{attack_table(tm_hm_compatibility, attack_details, args.language, "TM/VM")}</article>
        </section>
        <section class="grid two">
          <article class="panel"><h2>Ei-Attacken</h2>{attack_table(egg_moves, attack_details, args.language)}</article>
          <article class="panel"><h2>Weitere Attacken</h2>{attack_table(accessible_moves, attack_details, args.language)}</article>
        </section>
        <section class="grid two">
          <article class="panel"><h2>Tutor</h2>{attack_table(move_tutor_compatibility, attack_details, args.language, "Tutor")}</article>
          <div></div>
        </section>
      </div>
    </section>
  </main>
</body>
</html>
"""
    page_dir = output_dir / "species" / record["slug"]
    page_dir.mkdir(parents=True, exist_ok=True)
    (page_dir / "index.html").write_text(content, encoding="utf-8")


def render_index(records, pokemon_data, sprite_map, output_dir, language="LANG_GER"):
    cards = []
    for record in records:
        idx = record["idx"]
        stats = pokemon_data["basestats"][idx] or {}
        readable = record["readable"]
        index_types = normalized_types([readable.get("type_0") or stats.get("type_0"), readable.get("type_1") or stats.get("type_1")])
        type_text = " ".join(display_value(t, ("TYPE_",), language) for t in index_types if t)
        card_theme = type_theme(*index_types)
        types = render_type_badges(index_types, language, "soft")
        sprite_slug = sprite_map.get(record["species_constant"])
        sprite_file = f"gfx_pokemon_{sprite_slug}_frontsprite.png" if sprite_slug else ""
        sprite = f"assets/sprites/{sprite_file}" if sprite_file and (output_dir / "assets" / "sprites" / sprite_file).exists() else ""
        img = f"<img src=\"{escape(sprite)}\" alt=\"{escape(record['name'])}\">" if sprite else ""
        cards.append(
            f"<a class=\"pokemon-card\" href=\"species/{escape(record['slug'])}/\" "
            f"style=\"--card-accent:{card_theme['accent']};--card-soft:{card_theme['soft']};--card-line:{card_theme['line']};--card-ink:{card_theme['ink']};\" "
            f"data-search=\"{escape((record['name'] + ' ' + record['species_constant'] + ' ' + type_text).lower())}\">"
            f"{img}<span>#{escape(record['dex_number'])}</span><strong>{escape(record['name'])}</strong><small>{types}</small></a>"
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
    pokemon_data, records, names, species_to_idx, sprite_map, page_slugs = build_records(args)
    for record in records:
        render_species_page(args, record, pokemon_data, names, species_to_idx, sprite_map, page_slugs, args.output)
    render_index(records, pokemon_data, sprite_map, args.output, args.language)
    eprint(f"generated {len(records)} pages in {args.output}")


def main():
    parser = argparse.ArgumentParser(description="Generate a static Pokémon Violet Pokédex wiki.")
    parser.add_argument("--pokemon-pkl", type=Path, default=Path("bld/index/pokemon.pkl"))
    parser.add_argument("--stats-pkl", type=Path, default=Path("bld/pokeapi/updated.pkl"))
    parser.add_argument("--updates-json", type=Path, default=Path("pokeapi/updates.json"))
    parser.add_argument("--mega-evolutions-pms", type=Path, default=Path("src/battle/mega/mega_evolutions.pms"))
    parser.add_argument("--attacks-pms", type=Path, default=Path("src/attacks/attacks.pms"))
    parser.add_argument("--project", type=Path, default=Path("proj.pmp"))
    parser.add_argument("--output", type=Path, default=Path("docs/pokemon"))
    parser.add_argument("--language", default="LANG_GER")
    parser.add_argument("--clean", action="store_true")
    args = parser.parse_args()
    generate(args)


STYLE_CSS = r"""
:root {
  color-scheme: light;
  --bg: #f3efe6;
  --panel: #fff;
  --ink: #29251f;
  --muted: #70685e;
  --line: #d7cfc3;
  --accent: #486678;
  --accent-2: #7da1b3;
  --page-accent: #486678;
  --page-accent-2: #7da1b3;
  --page-soft: #edf4f7;
  --page-line: #c8d7df;
  --page-ink: #203741;
}
* { box-sizing: border-box; }
body {
  margin: 0;
  font-family: Georgia, "Times New Roman", serif;
  color: var(--ink);
  background:
    linear-gradient(180deg, rgba(255,255,255,0.72), rgba(255,255,255,0.72)),
    linear-gradient(135deg, #ece6db, #f9f6ef 50%, #ece5d7);
}
a { color: inherit; }
.site-header {
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 14px 24px;
  border-bottom: 1px solid var(--line);
  background: rgba(255,255,255,0.92);
  position: sticky;
  top: 0;
  z-index: 1;
  backdrop-filter: blur(10px);
}
.site-header a { text-decoration: none; font-weight: 700; }
main { width: min(1160px, calc(100% - 32px)); margin: 28px auto 56px; }
.list-header {
  display: grid;
  grid-template-columns: 1fr auto;
  gap: 24px;
  align-items: center;
  margin-bottom: 24px;
}
.eyebrow { margin: 0 0 6px; color: var(--muted); font-size: 13px; font-weight: 700; text-transform: uppercase; }
h1, h2 { font-family: "Trebuchet MS", "Avenir Next", sans-serif; letter-spacing: 0; }
h1 { margin: 0 0 10px; font-size: 40px; line-height: 1; color: var(--page-ink); }
h2 { margin: 0 0 14px; font-size: 18px; color: var(--page-ink); }
.panel {
  background: var(--panel);
  border: 1px solid var(--line);
  border-radius: 6px;
  padding: 16px 18px;
  margin-bottom: 18px;
  box-shadow: 0 1px 0 rgba(0,0,0,0.03);
}
.panel-soft { background: var(--page-soft); border-color: var(--page-line); }
.lead-card {
  padding: 18px 20px;
  margin-bottom: 18px;
  border: 1px solid var(--page-line);
  border-left: 6px solid var(--page-accent);
  border-radius: 6px;
  background: linear-gradient(180deg, rgba(255,255,255,0.96), var(--page-soft));
}
.lead-copy { margin: 0; line-height: 1.7; font-size: 16px; }
.species-layout {
  display: grid;
  grid-template-columns: minmax(270px, 320px) minmax(0, 1fr);
  gap: 24px;
  align-items: start;
}
.infobox {
  border: 1px solid var(--page-line);
  border-radius: 6px;
  overflow: hidden;
  background: #fff;
  box-shadow: 0 1px 0 rgba(0,0,0,0.03);
}
.infobox-head {
  padding: 16px 18px 14px;
  background: linear-gradient(180deg, var(--page-soft), #fff);
  border-bottom: 1px solid var(--page-line);
}
.infobox-head .eyebrow { color: var(--page-accent); }
.infobox-head h1 { margin-bottom: 8px; }
.infobox-section {
  padding: 14px 16px 16px;
  border-top: 1px solid var(--page-line);
}
.infobox-section:first-of-type { border-top: 0; }
.sprite-frame {
  display: grid;
  place-items: center;
  padding: 18px 12px;
  min-height: 210px;
  background:
    radial-gradient(circle at 50% 45%, rgba(255,255,255,0.98), rgba(255,255,255,0.92) 48%, rgba(0,0,0,0) 49%),
    linear-gradient(180deg, #fff, var(--page-soft));
}
.sprite-frame img {
  width: min(220px, 100%);
  height: auto;
  object-fit: contain;
  image-rendering: pixelated;
}
.article-column { min-width: 0; }
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
.fact-table th { width: 38%; color: var(--page-ink); font-size: 12px; }
.fact-table td { color: var(--ink); }
.stats td:first-of-type { width: 54px; font-variant-numeric: tabular-nums; }
.total th, .total td { color: var(--ink); font-weight: 800; border-bottom: 0; }
.bar { display: block; height: 10px; border-radius: 999px; background: #edf0f4; overflow: hidden; }
.bar span { display: block; height: 100%; background: linear-gradient(90deg, var(--page-accent-2), var(--page-accent)); }
.types { display: flex; gap: 8px; flex-wrap: wrap; }
.type {
  display: inline-flex;
  align-items: center;
  min-height: 24px;
  padding: 2px 9px;
  border-radius: 999px;
  color: var(--type-ink, #fff);
  background: var(--type-accent, #69707a);
  border: 1px solid var(--type-line, transparent);
  box-shadow: inset 0 -1px 0 rgba(0,0,0,0.06);
  font-size: 12px;
  font-weight: 800;
}
.type-solid {
  box-shadow: inset 0 -1px 0 rgba(0,0,0,0.18);
}
.type-soft {
  color: var(--type-ink, var(--ink));
}
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
  border: 1px solid var(--card-line, var(--line));
  border-radius: 6px;
  background: linear-gradient(180deg, #fff, var(--card-soft, var(--panel)));
  box-shadow: inset 4px 0 0 var(--card-accent, transparent);
}
.pokemon-card:hover { border-color: var(--card-accent, var(--page-accent)); }
.pokemon-card img { grid-row: 1 / 4; width: 54px; height: 54px; object-fit: contain; image-rendering: pixelated; }
.pokemon-card span { color: var(--card-ink, var(--muted)); font-size: 12px; opacity: 0.8; }
.pokemon-card strong { overflow-wrap: anywhere; }
.pokemon-card small { display: flex; gap: 4px; flex-wrap: wrap; }
.pokemon-card small .type { min-height: 18px; padding: 1px 6px; font-size: 10px; }
.form-grid { display: grid; gap: 12px; }
.form-card {
  display: grid;
  grid-template-columns: 116px minmax(0, 1fr);
  gap: 14px;
  align-items: start;
  padding: 12px;
  border: 1px solid var(--card-line, var(--line));
  border-radius: 6px;
  background: linear-gradient(180deg, #fff, var(--card-soft, #f7f8f8));
  box-shadow: inset 4px 0 0 var(--card-accent, var(--page-accent));
}
.form-sprite {
  display: grid;
  place-items: center;
  min-height: 110px;
  border: 1px solid var(--card-line, var(--line));
  border-radius: 6px;
  background: rgba(255,255,255,0.72);
}
.form-sprite img { width: 96px; height: 96px; object-fit: contain; image-rendering: pixelated; }
.form-body h3 { margin: 0 0 10px; font-family: "Trebuchet MS", "Avenir Next", sans-serif; font-size: 20px; color: var(--card-ink, var(--page-ink)); }
.form-change-table { margin-bottom: 10px; }
.form-change-table .types { display: inline-flex; vertical-align: middle; }
.form-stats { margin-top: 8px; }
.form-stats .delta { width: 56px; font-weight: 800; font-variant-numeric: tabular-nums; }
.form-stats .positive { color: #2f7d46; }
.form-stats .negative { color: #a0463a; }
.form-stats .neutral { color: var(--muted); }
.form-subsection { margin-top: 12px; }
.form-subsection h3 { margin: 0 0 8px; font-size: 15px; }
.search { display: grid; gap: 6px; justify-self: end; color: var(--muted); font-weight: 700; }
.search input { width: min(360px, 70vw); padding: 10px 12px; border: 1px solid var(--line); border-radius: 8px; font: inherit; }
@media (max-width: 760px) {
  main { width: min(100% - 20px, 1160px); margin-top: 18px; }
  .list-header, .grid.two, .species-layout { grid-template-columns: 1fr; }
  .form-card { grid-template-columns: 1fr; }
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
