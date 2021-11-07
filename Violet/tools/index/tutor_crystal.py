#!/usr/bin/env python3

from symbols import parse_symbols
from pymap.project import Project, _canonical_form
from collections import defaultdict
from pprint import pprint
import argparse, pickle

def get_tutor_crystal_index(rompath, symbolspath, projectpath):
    """ Builds the index for all tutor crystals. """
    with open(rompath, 'rb') as f:
        rom = f.read()
    symbols = parse_symbols(symbolspath)
    project = Project(projectpath)

    index = {t : [] for t in project.constants['pokemon_types']}

    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for person_idx, person in enumerate(header['events']['persons']):
                if person['script_std_and_in_connection']['script_std'] == 'PERSON_ACCESSIBLE_MOVE_TUTOR':
                    index[person['value']['type']].append({
                        'bank' : bank,
                        'map_idx' : map_idx,
                        'label' : label,
                        'namespace' : namespace,
                        'person_idx' : person_idx
                    })
    return index

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates an index pickle for all crytsal move tutors.')
    parser.add_argument('rom', help='the built rom')
    parser.add_argument('symbols', help='the symbol dump of armips')
    parser.add_argument('project', help='the pymap project which holds the pokemon_types constants')
    parser.add_argument('-o', dest='output', help='output pickle containing the tutor crystal locations')
    args = parser.parse_args()

    index = get_tutor_crystal_index(args.rom, args.symbols, args.project)
    with open(args.output, 'wb') as f:
        pickle.dump(index, f)