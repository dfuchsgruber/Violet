#!/usr/bin/env python3

import agb.types
import pymap.project
import argparse
from collections import defaultdict
import logging

from typing import NamedTuple
from model import AGGRESSIVE_WILD_ENCOUNTER_DATATYPE, model
from pymap.compile import datatype_to_assembly


def string_to_int(i):
    if isinstance(i, int):
        return i
    else:
        return int(i, 0)


class WildEncounter(NamedTuple):
    bank: int
    map_idx: int
    x: int
    y: int
    despawn_rate: int
    flag: str = ""


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Creates metadata for aggressive wild encounters"
    )
    parser.add_argument("symbol", help="The symbol of the aggressive wild encounters")
    parser.add_argument("project", help="The pymap project.")
    parser.add_argument("-o", help="The output assembly to create.", dest="output_path")
    args = parser.parse_args()

    project = pymap.project.Project(args.project)

    idx_to_wild_encounter = defaultdict(set)
    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for person_idx, person in enumerate(header["events"]["persons"]):
                try:
                    if (
                        person["script_std_and_in_connection"]["script_std"]
                        == "PERSON_AGGRESSIVE_POKEMON"
                    ):
                        idx = str((person["flag"], project, "flags"))
                        x, y = string_to_int(person["x"]), string_to_int(person["y"])
                        idx_to_wild_encounter[idx].add(
                            WildEncounter(bank, map_idx, x, y, 0)
                        )
                except Exception as e:
                    print(
                        f"Error in parsing aggressive wild of person {person_idx} on map {bank},{map_idx}"
                    )
                    raise e

    if any(len(encounters) > 1 for encounters in idx_to_wild_encounter.values()):
        logging.warning(
            f"Multiple encounters found for some flags: {[(idx, encounters) for idx, encounters in idx_to_wild_encounter.items() if len(encounters) > 1]}"
        )

    value = []
    for flag, encounters in idx_to_wild_encounter.items():
        if not encounters:
            continue
        encounter = next(iter(encounters))
        if not encounter.flag:
            continue
        if string_to_int(encounter.despawn_rate) >= 100:
            continue
        value.append(
            {"flag": flag, "despawn_rate": encounter.despawn_rate, "filler": 0}
        )

    project.model.update(model)
    assembly = datatype_to_assembly(
        value, AGGRESSIVE_WILD_ENCOUNTER_DATATYPE, args.symbol, project
    )
    with open(args.output_path, "w+") as f:
        f.write(assembly)
