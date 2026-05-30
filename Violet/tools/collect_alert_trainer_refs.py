#!/usr/bin/env python3
"""Collect trainer ids used by alert trainer person events."""

from __future__ import annotations

import argparse
import json
import re
import sys
from collections import defaultdict
from pathlib import Path
from typing import Any, Iterable

from collect_trainerbattle_refs import (
    ASM_SUFFIXES,
    DEFAULT_MACRO_FILE,
    PROJECT_ROOT,
    collect_trainerbattle_macros,
    parse_int,
    strip_comment,
)


DEFAULT_PROJECT_FILE = PROJECT_ROOT / "proj.pmp"
AGGRESSIVE_PERSON_STDS = {
    "PERSON_AGGRESSIVE_POKEMON",
    "PERSON_AGGRESSIVE_POKEMON_NO_OVERWORLD_EFFECT",
    4,
    14,
    "4",
    "14",
}

LABEL_RE = re.compile(r"^\s*([A-Za-z_.$][\w.$]*)\s*:\s*(.*)$")


def load_json(path: Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8"))


def is_one(value: Any) -> bool:
    return value == 1 or value == "1"


def is_aggressive_wild_person(person: dict[str, Any]) -> bool:
    script_std = person.get("script_std_and_in_connection", {}).get("script_std")
    return script_std in AGGRESSIVE_PERSON_STDS


def iter_header_paths(project_file: Path) -> Iterable[tuple[int, int, str, Path]]:
    project = load_json(project_file)
    for bank_text, bank in project["headers"].items():
        for map_text, header in bank.items():
            label, path_text, _namespace = header
            yield int(bank_text), int(map_text), label, PROJECT_ROOT / path_text


def iter_alert_trainers(project_file: Path) -> Iterable[dict[str, Any]]:
    for bank, map_idx, map_label, header_path in iter_header_paths(project_file):
        header = load_json(header_path)
        persons = header["data"]["events"]["persons"]
        for person_idx, person in enumerate(persons):
            if not is_one(person.get("is_trainer")):
                continue
            if is_aggressive_wild_person(person):
                continue

            script = person.get("script")
            if not script or script == "0":
                continue

            yield {
                "map_bank": bank,
                "map_idx": map_idx,
                "map_label": map_label,
                "map_path": header_path.relative_to(PROJECT_ROOT).as_posix(),
                "person_idx": person_idx,
                "target_index": person.get("target_index"),
                "script": script,
                "alert_radius": person.get("alert_radius"),
            }


def iter_assembly_files(root: Path) -> Iterable[Path]:
    for path in root.rglob("*"):
        if path.is_file() and path.suffix.lower() in ASM_SUFFIXES:
            yield path


def split_instruction(line: str) -> list[str]:
    return [part for part in re.split(r"[\s,]+", line.strip()) if part]


def index_script_starts(
    root: Path, macros: dict[str, list[int]]
) -> tuple[dict[str, list[dict[str, Any]]], list[dict[str, Any]]]:
    labels: dict[str, list[dict[str, Any]]] = defaultdict(list)
    pending_label: tuple[str, Path, int] | None = None
    macro_names = set(macros)

    for path in iter_assembly_files(root):
        relative_path = path.relative_to(root).as_posix()
        for lineno, raw_line in enumerate(
            path.read_text(encoding="utf-8").splitlines(), start=1
        ):
            line = strip_comment(raw_line)
            stripped = line.strip()
            label_match = LABEL_RE.match(line)
            if label_match:
                label, remainder = label_match.groups()
                pending_label = (label, path, lineno)
                stripped = remainder.strip()
                if not stripped:
                    continue

            if pending_label is None or not stripped:
                continue
            if stripped.startswith("."):
                continue

            label, label_path, label_lineno = pending_label
            parts = split_instruction(stripped)
            macro_name = parts[0] if parts else ""
            trainer_ids: list[int] = []
            if macro_name in macro_names:
                args = parts[1:]
                for arg_index in macros[macro_name]:
                    if arg_index >= len(args):
                        continue
                    trainer_id = parse_int(args[arg_index])
                    if trainer_id is not None:
                        trainer_ids.append(trainer_id)

            labels[label].append(
                {
                    "file": relative_path,
                    "line": label_lineno,
                    "first_instruction": stripped,
                    "starts_with_trainerbattle": macro_name in macro_names,
                    "macro": macro_name,
                    "trainer_ids": trainer_ids,
                }
            )
            pending_label = None

    duplicates = [
        {"script": label, "definitions": definitions}
        for label, definitions in sorted(labels.items())
        if len(definitions) > 1
    ]
    return labels, duplicates


def collect_alert_trainer_refs(
    project_file: Path, macro_file: Path, root: Path
) -> dict[str, Any]:
    macros = collect_trainerbattle_macros(macro_file)
    script_starts, duplicate_scripts = index_script_starts(root, macros)

    alert_trainers = list(iter_alert_trainers(project_file))
    alert_script_names = {alert_trainer["script"] for alert_trainer in alert_trainers}
    entries: list[dict[str, Any]] = []
    missing_scripts: list[dict[str, Any]] = []
    non_trainerbattle_scripts: list[dict[str, Any]] = []

    for alert_trainer in alert_trainers:
        definitions = script_starts.get(alert_trainer["script"], [])
        if not definitions:
            missing_scripts.append(alert_trainer)
            continue

        map_dir = Path(alert_trainer["map_path"]).parent
        definition = next(
            (
                candidate
                for candidate in definitions
                if Path(candidate["file"]).parent == map_dir
            ),
            definitions[0],
        )
        if not definition["starts_with_trainerbattle"]:
            non_trainerbattle_scripts.append(
                {**alert_trainer, "definition": definition}
            )
            continue

        for trainer_id in definition["trainer_ids"]:
            entries.append(
                {
                    **alert_trainer,
                    "trainer_id": trainer_id,
                    "script_file": definition["file"],
                    "script_line": definition["line"],
                    "macro": definition["macro"],
                    "first_instruction": definition["first_instruction"],
                }
            )

    by_trainer_id: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for entry in entries:
        trainer_id = str(entry["trainer_id"])
        by_trainer_id[trainer_id].append(
            {
                key: value
                for key, value in entry.items()
                if key != "trainer_id"
            }
        )

    duplicate_alert_scripts = [
        duplicate
        for duplicate in duplicate_scripts
        if duplicate["script"] in alert_script_names
    ]

    return {
        "alert_person_count": len(alert_trainers),
        "trainer_id_reference_count": len(entries),
        "distinct_trainer_id_count": len(by_trainer_id),
        "trainer_ids": sorted(int(trainer_id) for trainer_id in by_trainer_id),
        "by_trainer_id": {
            trainer_id: by_trainer_id[trainer_id]
            for trainer_id in sorted(by_trainer_id, key=int)
        },
        "missing_script_count": len(missing_scripts),
        "missing_scripts": missing_scripts,
        "non_trainerbattle_script_count": len(non_trainerbattle_scripts),
        "non_trainerbattle_scripts": non_trainerbattle_scripts,
        "duplicate_alert_script_definition_count": len(duplicate_alert_scripts),
        "duplicate_alert_script_definitions": duplicate_alert_scripts,
    }


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Collect trainer ids used by alert trainer person events."
    )
    parser.add_argument(
        "--root",
        type=Path,
        default=PROJECT_ROOT,
        help=f"project root to scan (default: {PROJECT_ROOT})",
    )
    parser.add_argument(
        "--project-file",
        type=Path,
        default=DEFAULT_PROJECT_FILE,
        help=f"proj.pmp file (default: {DEFAULT_PROJECT_FILE})",
    )
    parser.add_argument(
        "--macro-file",
        type=Path,
        default=DEFAULT_MACRO_FILE,
        help=f"macro definition file (default: {DEFAULT_MACRO_FILE})",
    )
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        help="write the alert-trainer mapping to this JSON file",
    )
    args = parser.parse_args()

    result = collect_alert_trainer_refs(
        args.project_file.resolve(), args.macro_file.resolve(), args.root.resolve()
    )
    encoded = json.dumps(result, indent=2)
    if args.output:
        args.output.write_text(encoded + "\n", encoding="utf-8")
    else:
        sys.stdout.write(encoded + "\n")


if __name__ == "__main__":
    main()
