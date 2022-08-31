#!/usr/bin/env python3

from typing import List
import agb.types
import pymap.project
import argparse
from collections import defaultdict

NUM_TREASURE_MAPS = 32

def string_to_int(i):
    if isinstance(i, int):
        return i
    else:
        return int(i, 0)

def get_treasure_maps(project: pymap.project.Project) -> List:
    """ Gets treasure maps in the project as a list of dicts."""
    idx_to_treasure = defaultdict(list)

    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for sign_idx, sign in enumerate(header['events']['signposts']):
                try:
                    if sign['type'] == 'SIGNPOST_HIDDEN_TREASURE':
                        idx = string_to_int(sign['value']['item']['flag'])
                        idx_to_treasure[idx].append({
                            'bank' : bank,
                            'map_idx' : map_idx,
                            'sign_idx' : sign_idx,
                            'item' : sign['value']['item']['item'],
                            'count' : sign['value']['item']['amount'],
                            'namespace' : namespace,
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


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates metadata for treasure maps')
    parser.add_argument('symbol', help='The symbol of the treasure maps')
    parser.add_argument('project', help='The pymap project.')
    parser.add_argument('-o', help='The output assembly to create.', dest='output_path')
    args = parser.parse_args()

    project = pymap.project.Project(args.project)
    data = []
    for idx, treasure_map in enumerate(get_treasure_maps(project)):
        if treasure_map is None:
            data.append('\t.byte 0xFF, 0xFF, 0xFF, 0xFF')
        else:
            data.append(f'\t.byte ' + ', '.join(map(str, [
                treasure_map['bank'], treasure_map['map_idx'], treasure_map['sign_idx'], '0'
            ])))

        data.append(f'\t@ treasure map {idx}')
        
    blocks = [
        agb.types.label_and_align('\n'.join(data), args.symbol, 2, True),
    ]
    with open(args.output_path, 'w+') as f:
        f.write('\n\n'.join(blocks + ['']))
    