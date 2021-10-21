#!/usr/bin/env python3

import argparse
import pymap.project

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Exports a list of banks and map_idxs that contains all cloud maps.')
    parser.add_argument('project', help='The pymap project.')
    parser.add_argument('output', help='Output assembly')
    parser.add_argument('symbol', help='Symbol of the cloud map list.')
    args = parser.parse_args()

    project = pymap.project.Project(args.project)
    cloud_maps_list = []
    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, _, _ = project.load_header(bank, map_idx)
            if header['type'] == 'MAP_TYPE_CLOUD':
                cloud_maps_list.append({'bank' : bank, 'map_idx' : map_idx})
    
    assembly, assembly_blocks = project.model['cloud_maps_list'].to_assembly(cloud_maps_list, project, [], [], args.symbol, 2, True)
    with open(args.output, 'w+') as f:
        f.write('\n\n'.join([assembly] + assembly_blocks))
