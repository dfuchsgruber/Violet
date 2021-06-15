#!/usr/bin/env python3

from symbols import parse_symbols
from pymap.project import Project, _canonical_form
from collections import defaultdict
from pprint import pprint
import argparse, pickle


def get_misc_index(rompath, symbolspath, projectpath):
    """ Builds the index for where miscs are stored """
    with open(rompath, 'rb') as f:
        rom = f.read()
    symbols = parse_symbols(symbolspath)
    project = Project(projectpath)

    mushroom_flag_to_map = defaultdict(list)
    shell_flag_to_map = defaultdict(list)
    trash_flag_to_map = defaultdict(list)

    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for person_idx, person in enumerate(header['events']['persons']):
                try:
                    if person['script_std'] == 'PERSON_MUSHROOM':
                        idx = str(person['value']['berry_tree_idx'])
                        mushroom_flag_to_map[int(idx, 0)].append((bank, map_idx, namespace))
                    elif person['script_std'] == 'PERSON_SHELL':
                        idx = str(person['value']['berry_tree_idx'])
                        shell_flag_to_map[int(idx, 0)].append((bank, map_idx, namespace))
                    elif person['script_std'] == 'PERSON_TRASH_CAN':
                        idx = str(person['value']['berry_tree_idx'])
                        trash_flag_to_map[int(idx, 0)].append((bank, map_idx, namespace))
                except Exception as e:
                    print(f'Error in parsing item of person {person_idx} on map {bank},{map_idx}')
                    raise e
    return {
        'mushroom_flag_to_map' : dict(mushroom_flag_to_map),
        'shell_flag_to_map' : dict(shell_flag_to_map),
        'trash_flag_to_map' : dict(trash_flag_to_map),
    }

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates an index pickle for all misc persons (mushrooms, shells...).')
    parser.add_argument('rom', help='the built rom')
    parser.add_argument('symbols', help='the symbol dump of armips')
    parser.add_argument('project', help='the pymap project which holds the constants')
    parser.add_argument('-o', dest='output', help='output pickle containing the misc persons')
    args = parser.parse_args()

    index = get_misc_index(args.rom, args.symbols, args.project)
    with open(args.output, 'wb') as f:
        pickle.dump(index, f)