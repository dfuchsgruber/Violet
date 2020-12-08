#!/usr/bin/env python3

import agb.types
import csv
import argparse
import pymap.project
import pymap.compile
from symbols import parse_symbols

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Checks if all maps have worldmap associations')
    parser.add_argument('rom', help='The binary rom.')
    parser.add_argument('project', help='The pymap project.')
    parser.add_argument('symbols', help='Symbols dump file')
    parser.add_argument('worldmap_association_symbol', help='Symbol of the worldmap associations')
    parser.add_argument('-o', help='The output assembly to create.', dest='output_path')
    args = parser.parse_args()

    with open(args.rom, 'rb') as f:
        rom = f.read()
    project = pymap.project.Project(args.project)
    symbols = parse_symbols(args.symbols)

    errors = []

    for bank in project.headers:
        for map_idx in project.headers[bank]:
            label = project.headers[bank][map_idx][0]
            # Check if this map has a worldmap association
            offset = project.model['pointer'].from_data(rom, symbols[args.worldmap_association_symbol] + 4 * int(bank), project, [], [])
            if offset is None:
                errors.append(f'No worldmap association for bank of map {bank}.{map_idx}:{label}')
            else:
                offset += 4 * int(map_idx) # bit hacky to have the 4 hardcoded here, but w/e...
                shape = project.model['worldmap_position'].from_data(rom, offset, project, [], [])
                if shape['width'] == 0 and shape['height'] == 0:
                    errors.append(f'No worldmap shape specified for map {bank}.{map_idx}:{label}')
    if len(errors):
        raise RuntimeError('\n'.join(errors))
                
