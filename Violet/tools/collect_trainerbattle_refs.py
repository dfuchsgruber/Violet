#!/usr/bin/env python3
"""Collect trainerbattle trainer id references from assembly scripts."""

from __future__ import annotations

import argparse
import json
import re
from collections import defaultdict
from pathlib import Path
from typing import Iterable


PROJECT_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_MACRO_FILE = PROJECT_ROOT / "include" / "as" / "overworld_script.s"
DEFAULT_TRAINER_FILE = PROJECT_ROOT / "src" / "trainer" / "trainers.c"
DEFAULT_TRAINER_HEADER = PROJECT_ROOT / "include" / "c" / "trainer" / "trainer.h"
ASM_SUFFIXES = {".s", ".asm"}

MACRO_RE = re.compile(r"^\s*\.macro\s+(\S+)(?:\s+(.*?))?\s*$")
BYTE_5C_RE = re.compile(r"^\s*\.byte\s+0x5c\b", re.IGNORECASE)
ENDM_RE = re.compile(r"^\s*\.endm\b")
TRAINER_ENTRY_RE = re.compile(r"^\s*\[(0x[0-9a-fA-F]+|\d+)\]\s*=", re.MULTILINE)
TRAINER_CNT_RE = re.compile(r"^\s*#define\s+TRAINER_CNT\s+(0x[0-9a-fA-F]+|\d+)\b", re.MULTILINE)


def strip_comment(line: str) -> str:
    """Strip common assembly line comments outside of quoted strings."""
    in_string = False
    quote = ""
    escaped = False

    for i, char in enumerate(line):
        if in_string:
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif char == quote:
                in_string = False
            continue

        if char in ('"', "'"):
            in_string = True
            quote = char
            continue

        if char == "@" or char == ";":
            return line[:i]
        if char == "/" and i + 1 < len(line) and line[i + 1] == "/":
            return line[:i]

    return line


def parse_macro_params(params: str | None) -> list[str]:
    if not params:
        return []
    parsed = []
    for token in re.split(r"[\s,]+", params.strip()):
        if not token:
            continue
        parsed.append(token.split(":", 1)[0])
    return parsed


def collect_trainerbattle_macros(macro_file: Path) -> dict[str, list[int]]:
    """Return trainerbattle macro names and the parameter indexes that are ids."""
    macros: dict[str, list[int]] = {}
    current_name: str | None = None
    current_params: list[str] = []
    current_is_trainerbattle = False
    current_uses_trainerbattle_opcode = False
    first_body_directive_seen = False

    for raw_line in macro_file.read_text(encoding="utf-8").splitlines():
        line = strip_comment(raw_line).strip()
        macro_match = MACRO_RE.match(line)
        if macro_match:
            current_name = macro_match.group(1)
            current_params = parse_macro_params(macro_match.group(2))
            current_is_trainerbattle = current_name.startswith("trainerbattle")
            current_uses_trainerbattle_opcode = False
            first_body_directive_seen = False
            continue

        if current_name is None:
            continue

        if ENDM_RE.match(line):
            if current_is_trainerbattle and current_uses_trainerbattle_opcode:
                trainer_indexes = [
                    i
                    for i, param in enumerate(current_params)
                    if param.startswith("trainer") or param == "ally"
                ]
                if trainer_indexes:
                    macros[current_name] = trainer_indexes

            current_name = None
            current_params = []
            current_is_trainerbattle = False
            current_uses_trainerbattle_opcode = False
            first_body_directive_seen = False
            continue

        if not current_is_trainerbattle or not line:
            continue

        if not first_body_directive_seen:
            current_uses_trainerbattle_opcode = BYTE_5C_RE.match(line) is not None
            first_body_directive_seen = True

    return macros


def iter_assembly_files(root: Path) -> Iterable[Path]:
    for path in root.rglob("*"):
        if path.is_file() and path.suffix.lower() in ASM_SUFFIXES:
            yield path


def parse_int(token: str) -> int | None:
    token = token.strip().rstrip(",")
    if not re.fullmatch(r"[+-]?(?:0x[0-9a-fA-F]+|\d+)", token):
        return None
    return int(token, 0)


def collect_references(root: Path, macros: dict[str, list[int]]) -> dict[int, set[str]]:
    references: dict[int, set[str]] = defaultdict(set)
    macro_names = set(macros)

    for path in iter_assembly_files(root):
        relative_path = path.relative_to(root).as_posix()
        for raw_line in path.read_text(encoding="utf-8").splitlines():
            line = strip_comment(raw_line).strip()
            if not line:
                continue

            parts = re.split(r"[\s,]+", line)
            macro_name = parts[0]
            if macro_name not in macro_names:
                continue

            args = parts[1:]
            for arg_index in macros[macro_name]:
                if arg_index >= len(args):
                    continue
                trainer_id = parse_int(args[arg_index])
                if trainer_id is not None:
                    references[trainer_id].add(relative_path)

    return references


def format_mapping(references: dict[int, set[str]]) -> dict[str, list[str]]:
    return {
        str(trainer_id): sorted(paths)
        for trainer_id, paths in sorted(references.items())
    }


def collect_explicit_trainer_ids(trainer_file: Path) -> set[int]:
    return {
        int(match.group(1), 0)
        for match in TRAINER_ENTRY_RE.finditer(trainer_file.read_text(encoding="utf-8"))
    }


def collect_trainer_id_range(trainer_header: Path) -> set[int]:
    match = TRAINER_CNT_RE.search(trainer_header.read_text(encoding="utf-8"))
    if not match:
        raise ValueError(f"could not find TRAINER_CNT in {trainer_header}")
    return set(range(int(match.group(1), 0)))


def format_unreferenced_ids(
    defined_ids: set[int], referenced_ids: set[int]
) -> dict[str, list[int] | int]:
    unreferenced = sorted(defined_ids - referenced_ids)
    return {
        "count": len(unreferenced),
        "ids": unreferenced,
    }


def main() -> None:
    parser = argparse.ArgumentParser(
        description=(
            "Collect ids referenced by trainerbattle macros in .s/.asm files."
        )
    )
    parser.add_argument(
        "--root",
        type=Path,
        default=PROJECT_ROOT,
        help=f"project root to scan (default: {PROJECT_ROOT})",
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
        help="write the id-to-path mapping to this JSON file",
    )
    parser.add_argument(
        "--unreferenced-output",
        type=Path,
        help="write unreferenced trainer ids to this JSON file",
    )
    parser.add_argument(
        "--defined-trainers",
        choices=("explicit", "range"),
        default="explicit",
        help=(
            "which trainer ids count as defined for unreferenced output: "
            "explicit table initializers or every id from 0 to TRAINER_CNT - 1 "
            "(default: explicit)"
        ),
    )
    parser.add_argument(
        "--trainer-file",
        type=Path,
        default=DEFAULT_TRAINER_FILE,
        help=f"trainer table source file (default: {DEFAULT_TRAINER_FILE})",
    )
    parser.add_argument(
        "--trainer-header",
        type=Path,
        default=DEFAULT_TRAINER_HEADER,
        help=f"trainer header with TRAINER_CNT (default: {DEFAULT_TRAINER_HEADER})",
    )
    args = parser.parse_args()

    root = args.root.resolve()
    macro_file = args.macro_file.resolve()
    trainer_file = args.trainer_file.resolve()
    trainer_header = args.trainer_header.resolve()
    macros = collect_trainerbattle_macros(macro_file)
    references = collect_references(root, macros)
    mapping = format_mapping(references)
    encoded = json.dumps(mapping, indent=2)

    if args.output:
        args.output.write_text(encoded + "\n", encoding="utf-8")
    else:
        print(encoded)

    if args.unreferenced_output:
        if args.defined_trainers == "explicit":
            defined_ids = collect_explicit_trainer_ids(trainer_file)
        else:
            defined_ids = collect_trainer_id_range(trainer_header)
        unreferenced = format_unreferenced_ids(defined_ids, set(references))
        args.unreferenced_output.write_text(
            json.dumps(unreferenced, indent=2) + "\n", encoding="utf-8"
        )


if __name__ == "__main__":
    main()
