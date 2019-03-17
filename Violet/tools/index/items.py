#!/usr/bin/env python3
from symbols import parse_symbols
from pymap.project import Project, _canonical_form
from collections import defaultdict
import os, re
from pprint import pprint
import argparse, pickle

def get_item_index(rompath, symbolspath, projectpath):
    """ Creates an index for items. """
    with open(rompath, 'rb') as f:
        rom = f.read()
    symbols = parse_symbols(symbolspath)
    project = Project(projectpath)

    items = {
        item : [] for item in project.constants['items']
    }

    # Parse script files
    root = 'Violet/src/map/banks'
    for subdir, dirs, files in os.walk(root):
        for file in files:
            filepath = subdir + os.sep + file
            if filepath.endswith('.asm'):
                with open(filepath) as f:
                    matches = re.findall('copyvarifnotzero 0x8000 (.*)$\ncopyvarifnotzero 0x8001 (.*)', f.read(), flags=re.M)
                    if len(matches): 
                        # Reconstruct the bank and map idx and context from the path
                        bank, map_idx, _type, context = re.findall(f'{root}/(.*?)/(.*?)/(.*?)/(.*?)/.*', filepath)[0]
                        bank, map_idx = _canonical_form(bank), _canonical_form(map_idx)
                        label, path, namespace = project.headers[bank][map_idx]
                        for item, amount in matches:
                            items[item].append({
                                'type' : _type,
                                'context' : context,
                                'bank' : bank,
                                'map_idx' : map_idx,
                                'map_label' : label,
                                'namespace' : namespace,
                                'amount' : amount,
                            })

    # Parse person and signpost items
    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for person_idx, person in enumerate(header['events']['persons']):
                try:
                    if person['script_std'] == 'PERSON_ITEM':
                        items[person['value']['item']].append({
                            'type' : 'pokeball',
                            'bank' : bank,
                            'map_idx' : map_idx,
                            'flag' : person['flag'],
                            'namespace' : namespace,
                        })
                except Exception as e:
                    print(f'Error in parsing item of person {person_idx} on map {bank},{map_idx}')
                    raise e
            for sign_idx, sign in enumerate(header['events']['signposts']):
                try:
                    item = sign['value']['item']['item']
                    if item in items:
                        items[item].append({
                            'type' : 'hidden',
                            'bank' : bank,
                            'map_idx' : map_idx,
                            'flag' : sign['value']['item']['flag'],
                            'namespace' : namespace,
                            'amount' : sign['value']['item']['amount'],
                            'chunk' : sign['value']['item']['chunk'],
                        })
                except Exception as e:
                    print(f'Error in parsing item of sign {sign_idx} on map {bank},{map_idx}')
                    raise e


    # Parse dungeon items
    datatype = project.model['item_list']
    for dungeon in ('cave', 'forest', 'ocean'):
        for rarity in ('common', 'rare'):
            offset = symbols[f'dungeon_{dungeon}_items_{rarity}']
            for item in datatype.from_data(rom, offset, project, [], []):
                items[item].append({
                    'type' : 'dungeon',
                    'dungeon' : dungeon,
                    'rarity' : rarity
                })


    return items

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates an index pickle for all items.')
    parser.add_argument('rom', help='the built rom')
    parser.add_argument('symbols', help='the symbol dump of armips')
    parser.add_argument('project', help='the pymap project which holds the items constants')
    parser.add_argument('-o', dest='output', help='output pickle containing the items')
    args = parser.parse_args()

    items = get_item_index(args.rom, args.symbols, args.project)
    with open(args.output, 'wb') as f:
        pickle.dump(items, f)