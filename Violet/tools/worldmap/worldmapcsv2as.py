#!/usr/bin/env python3

import agb.types
import csv
import argparse
import pymap.project
import pymap.compile

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Compiles worldmap csv files.')
    parser.add_argument('csv', help='The csv to compile.')
    parser.add_argument('symbol', help='The symbol to export')
    parser.add_argument('project', help='The pymap project.')
    parser.add_argument('-o', help='The output assembly to create.', dest='output_path')
    args = parser.parse_args()

    project = pymap.project.Project(args.project)
    assembly = pymap.compile.get_preamble(set(('map_namespaces',)), project) + '\n'

    assembly += f'.global {args.symbol}\n'
    assembly += f'{args.symbol}:\n'

    with open(args.csv) as f:
        reader = csv.reader(f)
        for line in reader:
            line = ['MAP_NAMESPACE_NONE' if ns == '' else ns for ns in line] # Replace empty namespaces with MAP_NAMESPACE_NONE
            assembly += '.byte ' + ', '.join(map(str, line)) + '\n'
    assembly += '\n'
    with open(args.output_path, 'w+') as f:
        f.write(assembly)
