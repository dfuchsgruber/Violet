#!/usr/bin/env python3
import argparse
import csv
import json
import re
from pathlib import Path


STAT_COLUMNS = [
    ("ev_hp", ("STAT_HP",)),
    ("ev_attack", ("STAT_ATTACK",)),
    ("ev_defense", ("STAT_DEFENSE",)),
    ("ev_special_attack", ("STAT_SPECIAL_ATTACK", "STAT_SP_ATTACK")),
    ("ev_special_defense", ("STAT_SPECIAL_DEFENSE", "STAT_SP_DEFENSE")),
    ("ev_speed", ("STAT_SPEED",)),
]

COLUMNS = [
    "species",
    "rating",
    "ability",
    "hidden_ability",
    "nature",
    "held_item",
    *(name for name, _ in STAT_COLUMNS),
    "attack_0",
    "attack_1",
    "attack_2",
    "attack_3",
    "hidden_power_type",
]


def strip_jsonc(text):
    """Remove JSONC comments while preserving string literals."""
    output = []
    i = 0
    in_string = False
    escaped = False

    while i < len(text):
        char = text[i]
        next_char = text[i + 1] if i + 1 < len(text) else ""

        if in_string:
            output.append(char)
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif char == '"':
                in_string = False
            i += 1
            continue

        if char == '"':
            in_string = True
            output.append(char)
            i += 1
        elif char == "/" and next_char == "/":
            i = text.find("\n", i)
            if i == -1:
                break
            output.append("\n")
            i += 1
        elif char == "/" and next_char == "*":
            end = text.find("*/", i + 2)
            if end == -1:
                raise ValueError("Unterminated block comment")
            output.append("\n" * text[i:end + 2].count("\n"))
            i = end + 2
        else:
            output.append(char)
            i += 1

    return "".join(output)


def remove_trailing_commas(text):
    previous = None
    while previous != text:
        previous = text
        text = re.sub(r",(\s*[}\]])", r"\1", text)
    return text


def load_pms(path):
    text = path.read_text(encoding="utf-8")
    return json.loads(remove_trailing_commas(strip_jsonc(text)))


def iter_builds(data):
    value = data.get("value")
    if isinstance(value, dict):
        for species, builds in value.items():
            if species.startswith("POKEMON_"):
                yield species, builds

    for species, builds in data.items():
        if species.startswith("POKEMON_"):
            yield species, builds


def bool_to_csv(value):
    return "true" if value else "false"


def flatten_build(species, build):
    evs = build.get("evs", {})
    attacks = list(build.get("attacks", []))[:4]
    attacks.extend([""] * (4 - len(attacks)))

    row = {
        "species": species,
        "rating": build.get("rating", ""),
        "ability": build.get("ability", ""),
        "hidden_ability": bool_to_csv(build.get("hidden_ability", False)),
        "nature": build.get("nature", ""),
        "held_item": build.get("held_item", ""),
        "attack_0": attacks[0],
        "attack_1": attacks[1],
        "attack_2": attacks[2],
        "attack_3": attacks[3],
        "hidden_power_type": build.get("hidden_power_type", ""),
    }

    for column, pms_keys in STAT_COLUMNS:
        row[column] = next((evs[key] for key in pms_keys if key in evs), 0)

    return row


def convert(input_path, output_path):
    data = load_pms(input_path)
    rows = []
    species_count = 0

    for species, builds in iter_builds(data):
        species_count += 1
        if not isinstance(builds, list):
            raise ValueError(f"{species} must contain a list of builds")
        rows.extend(flatten_build(species, build) for build in builds)

    with output_path.open("w", encoding="utf-8", newline="") as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=COLUMNS)
        writer.writeheader()
        writer.writerows(rows)

    return species_count, len(rows)


def main():
    parser = argparse.ArgumentParser(description="Convert pokemon_builds.pms to CSV.")
    parser.add_argument(
        "input",
        nargs="?",
        type=Path,
        default=Path(__file__).with_name("pokemon_builds.pms"),
    )
    parser.add_argument(
        "output",
        nargs="?",
        type=Path,
        default=Path(__file__).with_name("pokemon_builds.csv"),
    )
    args = parser.parse_args()

    species_count, row_count = convert(args.input, args.output)
    print(f"Wrote {row_count} builds for {species_count} species to {args.output}")


if __name__ == "__main__":
    main()
