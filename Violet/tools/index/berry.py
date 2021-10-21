#!/usr/bin/env python3

from symbols import parse_symbols
from pymap.project import Project, _canonical_form
from collections import defaultdict
from pprint import pprint
import argparse, pickle

FIRST_BERRY = 'ITEM_AMRENABEERE'
LAST_BERRY = 'ITEM_ENIGMABEERE'
NUM_BERRY_TREES = 256

def constantize_berry(item_idx, project):
    for k, v in project.constants['items'].items():
        if v == item_idx:
            return k
    raise RuntimeError(f'No item found for berry {item_idx}')

def berry_idx_to_item_idx(berry_idx, project):
    item_idx = berry_idx + project.constants['items'][FIRST_BERRY]
    return constantize_berry(item_idx, project)


def get_berry_index(rompath, symbolspath, projectpath):
    """ Builds the index for where berries are distributed. """
    with open(rompath, 'rb') as f:
        rom = f.read()
    symbols = parse_symbols(symbolspath)
    project = Project(projectpath)

    initial_berry_array_offset = symbols['berry_tree_initial_items']
    berries = [
        berry_idx_to_item_idx(project.model['u8'].from_data(rom, initial_berry_array_offset + i, project, [], []), project) for i in range(NUM_BERRY_TREES)
    ]
    berry_to_flag = {
        constantize_berry(item_idx, project) : [] for item_idx in range(project.constants['items'][FIRST_BERRY], project.constants['items'][LAST_BERRY] + 1)
    }
    for flag, berry in enumerate(berries):
        berry_to_flag[berry].append(flag)
    flag_to_map = [[] for _ in range(NUM_BERRY_TREES)]

    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for person_idx, person in enumerate(header['events']['persons']):
                try:
                    if person['script_std'] == 'PERSON_BERRY_TREE':
                        tree_idx = str(person['value']['berry_tree_idx'])
                        flag_to_map[int(tree_idx, 0)].append((bank, map_idx, namespace))
                except Exception as e:
                    print(f'Error in parsing item of person {person_idx} on map {bank},{map_idx}')
                    raise e
    return {
        'berry_to_flag' : berry_to_flag,
        'flag_to_map' : flag_to_map
    }



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates an index pickle for all berries.')
    parser.add_argument('rom', help='the built rom')
    parser.add_argument('symbols', help='the symbol dump of armips')
    parser.add_argument('project', help='the pymap project which holds the constants')
    parser.add_argument('-o', dest='output', help='output pickle containing the habitats')
    args = parser.parse_args()

    habitats = get_berry_index(args.rom, args.symbols, args.project)
    with open(args.output, 'wb') as f:
        pickle.dump(habitats, f)
