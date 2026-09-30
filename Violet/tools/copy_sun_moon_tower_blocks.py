#!/usr/bin/env python3
"""Replace tileset entries 256–511 with modified copies of entries 0–255.

This tileset is plain JSON (no JSONC comments). Re-running is idempotent.
"""

import argparse
from copy import deepcopy
import json
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "path", nargs="?", type=Path,
        default=Path(__file__).resolve().parents[1]
        / "src/map/tileset/maptileset_sun_moon_tower_inside.pms",
    )
    path = parser.parse_args().path
    original = path.read_bytes()
    document = json.loads(original)
    data = document["data"]
    blocks, behaviours = data["blocks"], data["behaviours"]
    if len(blocks) != len(behaviours) or len(blocks) < 256:
        raise ValueError("Expected equally sized arrays with at least 256 entries")

    copied_blocks = deepcopy(blocks[:256])
    copied_behaviours = deepcopy(behaviours[:256])
    for block in copied_blocks:
        for tile in block:
            tile["palette_idx"] = {7: 9, 8: 10}.get(
                tile["palette_idx"], tile["palette_idx"]
            )
    for behaviour in copied_behaviours:
        if behaviour["battle_bg"] == "BATTLE_BG_SUN_TOWER":
            behaviour["battle_bg"] = "BATTLE_BG_MOON_TOWER"

    blocks[256:512] = copied_blocks
    behaviours[256:512] = copied_behaviours
    newline = "\r\n" if b"\r\n" in original else "\n"
    output = json.dumps(document, indent="\t", ensure_ascii=False)
    if original.endswith(b"\n"):
        output += "\n"
    path.write_bytes(output.replace("\n", newline).encode("utf-8"))
    print(f"Updated {path}: {len(blocks)} blocks and {len(behaviours)} behaviours")


if __name__ == "__main__":
    main()
