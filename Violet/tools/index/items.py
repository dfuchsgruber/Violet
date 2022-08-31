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
        item : {
            'locations' : [],
        } for item in project.constants['items']
    }

    # Parse script files
    root = 'src/map/banks'
    for subdir, dirs, files in os.walk(root):
        for file in files:
            filepath = subdir + os.sep + file
            if filepath.endswith('.asm'):
                with open(filepath) as f:
                    content = f.read()
                    # Match callstd giveitems
                    matches = list(re.findall('copyvarifnotzero 0x8000 (.*)$\n.*copyvarifnotzero 0x8001 (.*)', content, flags=re.M)) + list(re.findall('additem (.*) (.*)\n', content, flags=re.M))
                    if len(matches):
                        # Reconstruct the bank and map idx and context from the path
                        bank, map_idx = re.findall(f'{root}/(.*?)/(.*?)/.*', filepath)[0]
                        for item, amount in matches:
                            items[item]['locations'].append({
                                'type' : 'script',
                                'context' : '',
                                'bank' : bank,
                                'map_idx' : map_idx,
                                'amount' : amount,
                            })

    # Parse person and signpost items
    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for person_idx, person in enumerate(header['events']['persons']):
                try:
                    if person['script_std_and_in_connection']['script_std'] in ('PERSON_ITEM', 'PERSON_ITEM_MULTIPLE_COPIES'):
                        items[person['value']['item']]['locations'].append({
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
                    if sign['type'] == 'SIGNPOST_HIDDEN_ITEM':
                        _type = 'hidden'
                    elif sign['type'] == 'SIGNPOST_HIDDEN_TREASURE':
                        _type = 'treasure'
                    else:
                        continue
                    item = sign['value']['item']['item']
                    if item in items:
                        items[item]['locations'].append({
                            'type' : _type,
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


    # # Parse dungeon items
    # datatype = project.model['item_list']
    # for dungeon in ('cave', 'forest', 'ocean'):
    #     for rarity in ('common', 'rare'):
    #         offset = symbols[f'dungeon_{dungeon}_items_{rarity}']
    #         for item in datatype.from_data(rom, offset, project, [], []):
    #             items[item]['locations'].append({
    #                 'type' : 'dungeon',
    #                 'dungeon' : dungeon,
    #                 'rarity' : rarity
    #             })
    # Add attacks that TM/HMs correspond to
    tm_hm_to_attack = project.model['tm_hm_to_attack'].from_data(rom, symbols['tm_hm_to_attack'], project, [], [])
    for item in items:
        match = re.match('ITEM_(T|V)M([0-9]+)', item)
        if match is not None:
            if match.groups()[0] == 'T':
                attack = tm_hm_to_attack[int(match.groups()[1]) - 1]
            elif match.groups()[0] == 'V':
                attack = tm_hm_to_attack[int(match.groups()[1]) - 1 + 50]
            items[item]['attack'] = attack

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