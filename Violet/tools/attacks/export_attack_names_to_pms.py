#!/usr/bin/env python3

import argparse
import ast
import json
import re
from pathlib import Path


def strip_comments(text):
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.DOTALL)
    return re.sub(r"//.*", "", text)


def find_matching(text, start, opener="{", closer="}"):
    depth = 0
    in_string = None
    escaped = False
    for idx in range(start, len(text)):
        char = text[idx]
        if in_string:
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif char == in_string:
                in_string = None
            continue
        if char in ('"', "'"):
            in_string = char
        elif char == opener:
            depth += 1
        elif char == closer:
            depth -= 1
            if depth == 0:
                return idx
    raise ValueError("matching brace not found")


def split_top_level(text):
    parts = []
    start = 0
    depth = 0
    in_string = None
    escaped = False
    for idx, char in enumerate(text):
        if in_string:
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif char == in_string:
                in_string = None
            continue
        if char in ('"', "'"):
            in_string = char
        elif char in "({[":
            depth += 1
        elif char in ")}]":
            depth -= 1
        elif char == "," and depth == 0:
            part = text[start:idx].strip()
            if part:
                parts.append(part)
            start = idx + 1
    tail = text[start:].strip()
    if tail:
        parts.append(tail)
    return parts


def parse_constants(path):
    payload = json.loads(strip_comments(path.read_text(encoding="utf-8")))
    values = payload["values"]
    if not isinstance(values, list):
        raise ValueError(f"expected enum list in {path}")
    return [value for value in values if value != "ATTACK_CNT"]


def parse_c_string(expr):
    expr = expr.strip()
    match = re.fullmatch(r'PSTRING\(\s*("(?:\\.|[^"\\])*")\s*\)', expr, flags=re.DOTALL)
    if not match:
        raise ValueError(f"expected PSTRING string, got {expr!r}")
    return ast.literal_eval(match.group(1))


def parse_langdep(expr):
    match = re.fullmatch(r"LANGDEP\((.*)\)", expr.strip(), flags=re.DOTALL)
    if not match:
        raise ValueError(f"expected LANGDEP entry, got {expr!r}")
    args = split_top_level(match.group(1))
    if len(args) != 2:
        raise ValueError(f"expected two LANGDEP arguments, got {len(args)} in {expr!r}")
    return {
        "LANG_GER": parse_c_string(args[0]),
        "LANG_EN": parse_c_string(args[1]),
    }


def parse_attack_names(source):
    text = strip_comments(source.read_text(encoding="utf-8"))
    match = re.search(r"\battack_names\s*\[\s*ATTACK_CNT\s*\]\s*\[\s*13\s*\]\s*=\s*\{", text)
    if not match:
        raise ValueError("could not find attack_names[ATTACK_CNT][13] initializer")
    outer_start = text.find("{", match.start())
    outer_end = find_matching(text, outer_start)
    entries = split_top_level(text[outer_start + 1 : outer_end])
    return [parse_langdep(entry) for entry in entries]


def indent_block(text, prefix):
    return "\n".join(prefix + line if line else line for line in text.splitlines())


def dump_attack_names_pms(label, type_name, data, attack_ids):
    lines = [
        "{",
        f'\t"label": {json.dumps(label, ensure_ascii=False)},',
        f'\t"type": {json.dumps(type_name, ensure_ascii=False)},',
        '\t"data": [',
    ]
    for idx, (attack_id, entry) in enumerate(zip(attack_ids, data)):
        lines.append(f"\t\t// {attack_id}")
        entry_json = json.dumps(entry, indent="\t", ensure_ascii=False)
        suffix = "," if idx < len(data) - 1 else ""
        lines.append(indent_block(entry_json, "\t\t") + suffix)
    lines.extend(["\t]", "}", ""])
    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(description="Exports src/attacks/attack_names.c to a PMS attack names table.")
    parser.add_argument("--source", type=Path, default=Path("src/attacks/attack_names.c"))
    parser.add_argument("--attacks-const", type=Path, default=Path("constants/attacks.const"))
    parser.add_argument("--label", default="attack_names")
    parser.add_argument("--type", default="attack.names")
    parser.add_argument("output", nargs="?", type=Path, default=Path("src/attacks/attack_names.pms"))
    args = parser.parse_args()

    attack_ids = parse_constants(args.attacks_const)
    data = parse_attack_names(args.source)
    if len(data) != len(attack_ids):
        raise ValueError(f"found {len(data)} names, but {len(attack_ids)} attack constants")

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(dump_attack_names_pms(args.label, args.type, data, attack_ids), encoding="utf-8")


if __name__ == "__main__":
    main()
