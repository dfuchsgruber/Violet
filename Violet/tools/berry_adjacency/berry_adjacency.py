#!/usr/bin/env python3

import itertools
import agb.types
import pymap.project
import argparse
from collections import defaultdict
from itertools import product

NUM_BERRY_TREES = 256

def string_to_int(i):
    if isinstance(i, int):
        return i
    else:
        return int(i, 0)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates metadata for the adjacency of berry trees')
    parser.add_argument('symbol', help='The symbol of the adjacancy map')
    parser.add_argument('project', help='The pymap project.')
    parser.add_argument('-o', help='The output assembly to create.', dest='output_path')
    args = parser.parse_args()

    project = pymap.project.Project(args.project)

    location_to_berry = {}
    adjacency = defaultdict(set)

    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for person_idx, person in enumerate(header['events']['persons']):
                try:
                    if person['script_std_and_in_connection']['script_std'] == 'PERSON_BERRY_TREE':
                        tree_idx = int(str(person['value']['berry_tree_idx']), 0)
                        x, y = string_to_int(person['x']), string_to_int(person['y'])
                        location_to_berry[(string_to_int(bank), string_to_int(map_idx), x, y)] = tree_idx
                        for dx, dy in itertools.product(range(-2, 2 + 1), repeat=2):
                            if dx == 0 and dy == 0:
                                continue
                            adjacent_tree_idx = location_to_berry.get((string_to_int(bank), string_to_int(map_idx), x + dx, y + dy), None)
                            if adjacent_tree_idx is not None:
                                adjacency[tree_idx].add(adjacent_tree_idx)
                                adjacency[adjacent_tree_idx].add(tree_idx)
                except Exception as e:
                    print(f'Error in parsing berry of person {person_idx} on map {bank},{map_idx}')
                    raise e
    
    data = []
    for i in range(NUM_BERRY_TREES):
        data.append(f'\t@ berry tree {i}')
        data.append(f'\t.word {len(adjacency[i])}')
        data.append(f'\t.byte ' + ', '.join(map(str, list(adjacency[i]) + [0] * (4 - len(adjacency[i])))))

    blocks = [
        agb.types.label_and_align('\n'.join(data), args.symbol, 2, True),
    ]
    with open(args.output_path, 'w+') as f:
        f.write('\n\n'.join(blocks + ['']))
    