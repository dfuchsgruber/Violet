#!/usr/bin/env python3
"""Apply the Pichu/Rotom dex-number reshuffle to pokeapi/updates.json."""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_UPDATES = PROJECT_ROOT / "pokeapi" / "updates.json"

PICHU = "POKEMON_PICHU"
PIKACHU = "POKEMON_PIKACHU"
RAICHU = "POKEMON_RAICHU"
WATTZAPF = "POKEMON_WATTZAPF"
VOLTULA = "POKEMON_VOLTULA"
ROTOM = "POKEMON_ROTOM"

EXPECTED_DEX_NUMBERS = {
    PICHU: 329,
    PIKACHU: 13,
    RAICHU: 14,
    WATTZAPF: 35,
    VOLTULA: 36,
    ROTOM: 330,
}

SPECIAL_TARGETS = {
    PICHU: 13,
    ROTOM: 36,
    WATTZAPF: 329,
    VOLTULA: 330,
}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Move Pichu to dex 13, shift the old 13-34 block up by one, "
            "move Rotom to 36, and move Wattzapf/Voltula to 329/330."
        )
    )
    parser.add_argument(
        "updates_json",
        nargs="?",
        type=Path,
        default=DEFAULT_UPDATES,
        help=f"path to updates.json (default: {DEFAULT_UPDATES})",
    )
    parser.add_argument(
        "--check",
        action="store_true",
        help="validate and print the planned changes without writing the file",
    )
    return parser.parse_args()


def pokemon_with_dex_number(data: dict, dex_number: int) -> str | None:
    matches = [
        species
        for species, updates in data.items()
        if isinstance(updates, dict) and updates.get("dex_number") == dex_number
    ]
    if len(matches) > 1:
        raise ValueError(f"dex number {dex_number} is used by multiple species: {matches}")
    return matches[0] if matches else None


def validate_source_layout(data: dict) -> None:
    missing = [species for species in EXPECTED_DEX_NUMBERS if species not in data]
    if missing:
        raise ValueError(f"missing expected species: {missing}")

    mismatches = []
    for species, expected in EXPECTED_DEX_NUMBERS.items():
        actual = data[species].get("dex_number")
        if actual != expected:
            mismatches.append(f"{species}: expected {expected}, found {actual}")
    if mismatches:
        raise ValueError(
            "updates.json does not match the expected source dex layout:\n"
            + "\n".join(f"  - {mismatch}" for mismatch in mismatches)
        )

    for dex_number in range(13, 37):
        species = pokemon_with_dex_number(data, dex_number)
        if species is None:
            raise ValueError(f"expected dex number {dex_number} to be occupied")


def plan_changes(data: dict) -> dict[str, tuple[int, int]]:
    changes: dict[str, tuple[int, int]] = {}

    for dex_number in range(13, 35):
        species = pokemon_with_dex_number(data, dex_number)
        if species in SPECIAL_TARGETS:
            continue
        changes[species] = (dex_number, dex_number + 1)

    for species, new_number in SPECIAL_TARGETS.items():
        changes[species] = (data[species]["dex_number"], new_number)

    return changes


def apply_changes(data: dict, changes: dict[str, tuple[int, int]]) -> None:
    for species, (_, new_number) in changes.items():
        data[species]["dex_number"] = new_number


def apply_changes_to_source(source: str, changes: dict[str, tuple[int, int]]) -> str:
    for species, (old_number, new_number) in changes.items():
        pattern = re.compile(
            rf'("{re.escape(species)}"\s*:\s*\{{.*?"dex_number"\s*:\s*){old_number}(\b)',
            re.DOTALL,
        )
        source, count = pattern.subn(rf"\g<1>{new_number}\2", source, count=1)
        if count != 1:
            raise ValueError(f"could not update dex_number for {species}")
    return source


def validate_result(data: dict) -> None:
    expected_targets = {
        PICHU: 13,
        PIKACHU: 14,
        RAICHU: 15,
        ROTOM: 36,
        WATTZAPF: 329,
        VOLTULA: 330,
    }
    for species, expected in expected_targets.items():
        actual = data[species]["dex_number"]
        if actual != expected:
            raise ValueError(f"{species} should be {expected}, found {actual}")
        actual_species = pokemon_with_dex_number(data, expected)
        if actual_species != species:
            raise ValueError(f"dex number {expected} should be {species}, found {actual_species}")


def main() -> None:
    args = parse_args()
    updates_path = args.updates_json.resolve()
    source = updates_path.read_text(encoding="utf-8")
    data = json.loads(source)

    try:
        validate_source_layout(data)
        changes = plan_changes(data)
    except ValueError as error:
        raise SystemExit(error) from None

    for species in sorted(changes, key=lambda key: changes[key][0]):
        old_number, new_number = changes[species]
        print(f"{species}: {old_number} -> {new_number}")

    if args.check:
        return

    apply_changes(data, changes)
    try:
        validate_result(data)
        source = apply_changes_to_source(source, changes)
    except ValueError as error:
        raise SystemExit(error) from None

    updates_path.write_text(source, encoding="utf-8")


if __name__ == "__main__":
    main()
