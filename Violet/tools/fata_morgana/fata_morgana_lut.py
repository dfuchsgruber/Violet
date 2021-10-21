#!/usr/bin/env python3

import agb.types
import pymap.project
import argparse
import json
import itertools

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates metadata for the fata morgana feature.')
    parser.add_argument('footer', help='Path to the map footer the fata morgana appears on.')
    parser.add_argument('lutlabel', help='The label of the lookup table to create.')
    parser.add_argument('lutsize', help='The label of the size storage of the lookup table to create.')
    parser.add_argument('project', help='The pymap project.')
    parser.add_argument('-o', help='The output assembly to create.', dest='output_path')
    args = parser.parse_args()

    project = pymap.project.Project(args.project)

    # Retrieve the footer
    footer_type = project.model['footer']
    with open(args.footer) as f:
        footer = json.load(f)

    if not footer['type'] == 'footer':
        raise RuntimeError(f'Expected a map footer file, not {header["type"]}')
    footer = footer['data']
    
    FATA_MORGANA_BLOCK_IDXS = set(range(0x320, 0x3b0)).union(set((0x286, 0x287, 0x28e, 0x28f, 0x296, 0x297, 0x294, 0x295))) # kinda ugly, ngl...

    data = [
        (x + 7, y + 7, footer['blocks'][y][x]['block_idx'])
        for y, x in itertools.product(range(footer['height']), range(footer['width']))
        if footer['blocks'][y][x]['block_idx'] in FATA_MORGANA_BLOCK_IDXS
    ]

    blocks = [
        agb.types.label_and_align('\n'.join(
                        map(lambda triplet: f'.hword {triplet[0]}, {triplet[1]}, {triplet[2]}', data)
                    ), args.lutlabel, 2, True),
        agb.types.label_and_align(f'.word {len(data)}', args.lutsize, 2, True)
    ]

    with open(args.output_path, 'w+') as f:
        f.write('\n\n'.join(blocks + ['']))
