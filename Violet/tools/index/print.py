#!/usr/bin/env python3

# Module to output the index in very compressed human readable form

import argparse, pickle
from collections import defaultdict

def print_habitat_index(habitats):
    """ Creates a readable version of the habitat index. """
    index = ''
    for species in habitats:
        index += f'{species}\n'
        for habitat in habitats[species]:
            bank = habitat.get('bank', None)
            map_idx = habitat.get('map_idx', None)
            namespace = habitat.get('namespace', None)
            _type = habitat['type']
            index += f'  *\t{_type}\t{namespace}\t[{bank}.{map_idx}]\n'
    return index

def print_item_index(items):
    """ Creates a readable version of the item index. """
    index = ''
    for item, data in items.items():
        attack = data.get('attack', None)
        if attack:
            index += f'{item} ({attack})\n'
        else:
            index += f'{item}\n'
        for location in data['locations']:
            bank = location.get('bank', None)
            map_idx = location.get('map_idx', None)
            namespace = location.get('namespace', None)
            _type = location['type']
            index += f'  *\t{_type}\t{namespace}\t[{bank}.{map_idx}]\n'
    return index

def print_hidden_index(items):
    """ Creates a readable version of all used hidden flags so far. """
    chunks = defaultdict(lambda: defaultdict(list))
    for item, data in items.items():
        for location in data['locations']:
            if location['type'] == 'hidden':
                bank = location.get('bank', None)
                map_idx = location.get('map_idx', None)
                namespace = location.get('namespace', None)
                chunk = location['chunk']
                chunks[chunk][int(location['flag'])].append(f'{namespace} [{bank}.{map_idx}]')
    index = ''
    for chunk in chunks:
        index += f'Chunk {chunk}\n'
        hidden_flags = chunks[chunk]
        for idx in range(min(hidden_flags), max(hidden_flags) + 1):
            if len(hidden_flags[idx]) > 1: index += '\t!!!' # Each flag should be reffered to uniquely
            else: index += '\t'
            index += f'{idx}\t:\t'
            for location in hidden_flags[idx]:
                index += f'{location}\t'
            index += '\n'
    return index

def print_berry_index(berries):
    """ Prints a readable version of the berry index. """
    index = 'Berry Tree Locations\n'
    for flag, locations in enumerate(berries['flag_to_map']):
        index += f'\t{flag}\t:\t{locations}\n'
    index += '\n\nBerrys by flags\n'
    for berry, flags in berries['berry_to_flag'].items():
        index += '\t' + berry + ' : ' + ', '.join(map(str, flags)) + '\n'
    return index

def print_misc_person_index(misc):
    """ Prints a readable version of the index of misc persons (mushrooms, shells etc.) """
    index = ''
    for misc_name, misc_table in (
        ('Mushrooms', misc['mushroom_flag_to_map']),
        ('Shells', misc['shell_flag_to_map']),
        ('Trash Cans', misc['trash_flag_to_map']),
    ):
        index += f'{misc_name}:\n'
        if len(misc_table.keys()) == 0:
            continue
        for idx in range(max(misc_table.keys()) + 1):
            index += '\t' + str(idx) + '\t : ' + ', '.join(map(str, misc_table.get(idx, []))) + '\n'
        index += '\n\n'
    return index

def print_tutor_crystal_index(tutor_crystals):
    index = ''
    for element, data in tutor_crystals.items():
        locations = []
        for entry in data:
            bank = entry['bank']
            map_idx = entry['map_idx']
            namespace = entry['namespace']
            person_idx = entry['person_idx']
            locations.append(f'{namespace} [{bank}.{map_idx}] Person {person_idx}')
        index += f'{element}\t : {",".join(locations)}\n'
    index += '\n\n'
    return index

def print_dungeon_index(dungeons):
    index = ''
    for dungeon_type, idxs in dungeons['dungeon_locations_by_type'].items():
        index += f'{dungeon_type}:\n'
        for idx in idxs:
            index += f'\t{idx}\n'
    index += '\nIdxs:\n'
    for idx in sorted(list(dungeons['dungeon_locations_by_idx'].keys()), key=lambda s: int(s)):
        locations = []
        for entry in  dungeons['dungeon_locations_by_idx'][idx]:
            bank = entry['bank']
            map_idx = entry['map_idx']
            namespace = entry['namespace']
            person_idx = entry['person_idx']
            dungeon_type = entry['type']
            locations.append(f'{namespace} Type {dungeon_type}[{bank}.{map_idx}] Person {person_idx}')
        index += f'\t {idx}\t: ' + ', '.join(locations) + '\n'
    return index

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates an index pickle for all species habitats.')
    parser.add_argument('pickle', help='The pickle to output in readable format')
    parser.add_argument('-o', dest='output', help='output file containing the readable index')
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('--habitats', dest='index_type', action='store_const', const='habitats', help='Output the index for habitats')
    group.add_argument('--items', dest='index_type', action='store_const', const='items', help='Output the index for items')
    group.add_argument('--hidden', dest='index_type', action='store_const', const='hidden', help='Output the index for hidden flags')
    group.add_argument('--berries', dest='index_type', action='store_const', const='berries', help='Output the index for berries')
    group.add_argument('--misc', dest='index_type', action='store_const', const='misc', help='Output the index for misc persons (mushrooms, shells, ...)')
    group.add_argument('--tutor_crystal', dest='index_type', action='store_const', const='tutor_crystal', help='Output the index for tutor crystals')
    group.add_argument('--dungeon', dest='index_type', action='store_const', const='dungeon', help='Output the index for dungeons')
    args = parser.parse_args()

    with open(args.pickle, 'rb') as f:
        index = pickle.load(f)
    if args.index_type == 'habitats':
        readable = print_habitat_index(index)
    elif args.index_type == 'items':
        readable = print_item_index(index)
    elif args.index_type == 'hidden':
        readable = print_hidden_index(index)
    elif args.index_type == 'berries':
        readable = print_berry_index(index)
    elif args.index_type == 'misc':
        readable = print_misc_person_index(index)
    elif args.index_type == 'tutor_crystal':
        readable = print_tutor_crystal_index(index)
    elif args.index_type == 'dungeon':
        readable = print_dungeon_index(index)
    with open(args.output, 'w+') as f:
        f.write(readable)
    
