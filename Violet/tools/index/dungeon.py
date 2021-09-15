#!/usr/bin/env python3

from symbols import parse_symbols
from pymap.project import Project, _canonical_form
from collections import defaultdict
from pprint import pprint
import argparse, pickle


def get_dungeon_index(rompath, symbolspath, projectpath):
    """ Builds the index for where dungeons are located """
    with open(rompath, 'rb') as f:
        rom = f.read()
    symbols = parse_symbols(symbolspath)
    project = Project(projectpath)

    dungeon_locations_by_type = {
        'PERSON_SECRET_POWER_VINE' : [],
        'PERSON_SECRET_POWER_CAVE' : [],
        'PERSON_SECRET_POWER_WHIRLPOOL' : [],
    }
    dungeon_locations_by_idx = defaultdict(list)

    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for person_idx, person in enumerate(header['events']['persons']):
                try:
                    if person['script_std'] in dungeon_locations_by_type:
                        idx = str(person['value']['berry_tree_idx'])
                        dungeon_locations_by_idx[idx].append({'type' : person['script_std'], 'bank' : bank, 'map_idx' : map_idx, 'person_idx' : person_idx, 'namespace' : namespace})
                        dungeon_locations_by_type[person['script_std']].append(idx)
                except Exception as e:
                    print(f'Error in parsing item of person {person_idx} on map {bank},{map_idx}')
                    raise e
    return {
        'dungeon_locations_by_type' : dungeon_locations_by_type,
        'dungeon_locations_by_idx' : dungeon_locations_by_idx,
    }

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates an index pickle for all dungeons')
    parser.add_argument('rom', help='the built rom')
    parser.add_argument('symbols', help='the symbol dump of armips')
    parser.add_argument('project', help='the pymap project which holds the constants')
    parser.add_argument('-o', dest='output', help='output pickle containing the dungeons')
    args = parser.parse_args()

    index = get_dungeon_index(args.rom, args.symbols, args.project)
    with open(args.output, 'wb') as f:
        pickle.dump(index, f)