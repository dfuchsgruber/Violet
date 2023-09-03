#!/usr/bin/env python3

from typing import List
import agb.types
import pymap.project
import argparse
from collections import defaultdict
from symbols import parse_symbols
import pickle
from constants import SRC_ROOT
import os
import re

NUM_TREASURE_MAPS = 32

def string_to_int(i):
    if isinstance(i, int):
        return i
    else:
        return int(i, 0)

def get_treasure_map_locations() -> defaultdict:
    """ Gets scripts that set a treasure map flag. """
    idx_to_location = defaultdict(list)
    # Parse script files
    for subdir, dirs, files in os.walk(SRC_ROOT):
        for file in files:
            filepath = subdir + os.sep + file
            if filepath.endswith('.asm'):
                with open(filepath) as f:
                    content = f.read()
                    # Match callstd giveitems
                    matches = list(re.findall('give_treasure_map (.*)', content, flags=re.M))
                    if len(matches):
                        # Reconstruct the bank and map idx and context from the path
                        bank, map_idx = re.findall(f'{SRC_ROOT}/(.*?)/(.*?)/.*', filepath)[0]
                        treasure_map_idx = [t for t in matches[0].split(' ') if 'treasure_map_idx' in t][0].split('=')[1].strip()
                        idx_to_location[string_to_int(treasure_map_idx)].append({
                            'type' : 'script',
                            'context' : '',
                            'bank' : bank,
                            'map_idx' : map_idx,
                        })
    return idx_to_location


def get_treasure_maps(project: pymap.project.Project) -> List:
    """ Gets treasure maps in the project as a list of dicts."""
    map_locations = get_treasure_map_locations()
    idx_to_treasure = defaultdict(list)

    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for sign_idx, sign in enumerate(header['events']['signposts']):
                try:
                    if sign['type'] == 'SIGNPOST_HIDDEN_TREASURE':
                        idx = string_to_int(sign['value']['treasure_map']['idx'])
                        idx_to_treasure[idx].append({
                            'bank' : bank,
                            'map_idx' : map_idx,
                            'sign_idx' : sign_idx,
                            'item' : sign['value']['treasure_map']['item'],
                            'count' : sign['value']['treasure_map']['amount'],
                            'namespace' : namespace,
                            'map_locations' : map_locations[idx]
                        })
                except Exception as e:
                    print(f'Error in parsing item of sign {sign_idx} on map {bank},{map_idx}')
                    raise e
    treasure_maps = [None for _ in range(NUM_TREASURE_MAPS)] # result
    for idx, locations in idx_to_treasure.items():
        if idx not in range(NUM_TREASURE_MAPS):
            raise RuntimeError(f'Treasure map {locations} does not have valid flag.')
        if len(locations) > 1:
            raise RuntimeError(f'Treasure map flag {idx} is used multiple times: {locations}')
        treasure_maps[idx] = locations[0]
    return treasure_maps


def get_treasure_map_index(rom_path: str, symbols_path: str, project_path: str):
    """ Builds the index for all treasure maps. """
    with open(rom_path, 'rb') as f:
        rom = f.read()
    symbols = parse_symbols(symbols_path)
    project = pymap.project.Project(project_path)
    treasure_maps = get_treasure_maps(project)
    return treasure_maps


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates an index pickle for all treasure maps.')
    parser.add_argument('rom', help='the built rom')
    parser.add_argument('symbols', help='the symbol dump of armips')
    parser.add_argument('project', help='the pymap project')
    parser.add_argument('-o', dest='output', help='output pickle containing the treasure map locations')
    args = parser.parse_args()

    index = get_treasure_map_index(args.rom, args.symbols, args.project)
    with open(args.output, 'wb') as f:
        pickle.dump(index, f)
    