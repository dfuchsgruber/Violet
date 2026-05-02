#!/usr/bin/env python3

import argparse
import json
import re
from pathlib import Path


FIELDS = (
    "effect",
    "base_power",
    "type",
    "accuracy",
    "pp",
    "effect_accuracy",
    "affects_whom",
    "priority",
    "flags",
    "effect_table",
    "category",
    "rating",
)

CONSTANT_FIELDS = {"type", "affects_whom", "flags", "category"}


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
        if char in ("'", '"'):
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
    for idx, char in enumerate(text):
        if char == "{":
            depth += 1
        elif char == "}":
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
    if isinstance(values, list):
        base = int(payload.get("base", 0))
        return {name: base + idx for idx, name in enumerate(values)}
    return {name: int(value) for name, value in values.items()}


def normalize_expr(expr):
    return " ".join(expr.strip().split())


def parse_int(expr):
    expr = normalize_expr(expr)
    if not re.fullmatch(r"-?(?:0x[0-9A-Fa-f]+|\d+)", expr):
        raise ValueError(f"expected integer expression, got {expr!r}")
    return int(expr, 0)


def parse_value(field, expr):
    expr = normalize_expr(expr)
    if field in CONSTANT_FIELDS:
        return 0 if expr == "0" else expr
    return parse_int(expr)


def parse_entry(body):
    body = strip_comments(body).strip()
    entry = {field: 0 for field in FIELDS}
    if re.search(r"\.\w+\s*=", body):
        for assignment in split_top_level(body):
            match = re.fullmatch(r"\.(\w+)\s*=\s*(.+)", assignment, flags=re.DOTALL)
            if not match:
                raise ValueError(f"could not parse designated field {assignment!r}")
            field, expr = match.groups()
            if field not in entry:
                raise ValueError(f"unknown attack field {field!r}")
            entry[field] = parse_value(field, expr)
    else:
        values = split_top_level(body)
        if len(values) != len(FIELDS):
            raise ValueError(f"expected {len(FIELDS)} positional values, got {len(values)}")
        for field, expr in zip(FIELDS, values):
            entry[field] = parse_value(field, expr)
    return entry


def iter_initializers(text):
    cleaned = strip_comments(text)
    match = re.search(r"\battacks\s*\[\s*ATTACK_CNT\s*\]\s*=\s*\{", cleaned)
    if not match:
        raise ValueError("could not find attacks[ATTACK_CNT] initializer")
    outer_start = cleaned.find("{", match.start())
    outer_end = find_matching(cleaned, outer_start)
    body = cleaned[outer_start + 1 : outer_end]
    idx = 0
    pos = 0
    while pos < len(body):
        while pos < len(body) and body[pos] in " \t\r\n,":
            pos += 1
        if pos >= len(body):
            break
        designator = None
        designator_match = re.match(r"\[\s*(ATTACK_[A-Z0-9_]+)\s*\]\s*=\s*", body[pos:])
        if designator_match:
            designator = designator_match.group(1)
            pos += designator_match.end()
        if pos >= len(body) or body[pos] != "{":
            raise ValueError(f"expected attack entry initializer near offset {pos}")
        entry_start = pos
        entry_end = find_matching(body, entry_start)
        yield designator, body[entry_start + 1 : entry_end]
        pos = entry_end + 1
        if designator is None:
            idx += 1


def parse_attacks(source, attack_constants):
    attack_count = attack_constants["ATTACK_CNT"]
    index_to_attack = {value: name for name, value in attack_constants.items()}
    data = [None] * attack_count
    next_idx = 0
    for designator, body in iter_initializers(source.read_text(encoding="utf-8")):
        if designator is None:
            idx = next_idx
        else:
            idx = attack_constants[designator]
        if idx >= attack_count:
            raise ValueError(f"initializer for {designator or idx} exceeds ATTACK_CNT")
        if data[idx] is not None:
            raise ValueError(f"duplicate initializer for {index_to_attack.get(idx, idx)}")
        data[idx] = parse_entry(body)
        next_idx = idx + 1
    missing = [index_to_attack.get(idx, idx) for idx, entry in enumerate(data) if entry is None]
    if missing:
        raise ValueError(f"missing attack initializers: {missing}")
    return data, [index_to_attack[idx] for idx in range(attack_count)]


def indent_block(text, prefix):
    return "\n".join(prefix + line if line else line for line in text.splitlines())


def dump_attacks_pms(label, type_name, data, attack_ids):
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
    parser = argparse.ArgumentParser(description="Exports src/attacks/attacks.c to a PMS attack table.")
    parser.add_argument("--source", type=Path, default=Path("src/attacks/attacks.c"))
    parser.add_argument("--attacks-const", type=Path, default=Path("constants/attacks.const"))
    parser.add_argument("--label", default="attacks")
    parser.add_argument("--type", default="attack.table")
    parser.add_argument("output", type=Path)
    args = parser.parse_args()

    data, attack_ids = parse_attacks(args.source, parse_constants(args.attacks_const))
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(dump_attacks_pms(args.label, args.type, data, attack_ids), encoding="utf-8")


if __name__ == "__main__":
    main()
