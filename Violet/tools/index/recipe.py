#!/usr/bin/env python3

from asyncio import constants
from typing import List
import agb.types
import pymap.project
import argparse
from collections import defaultdict
from symbols import parse_symbols
from pymap.project import Project
import pickle
from constants import SRC_ROOT, CRAFTING_NUM_RECIPIES, CRAFTING_RECIPES
import os
import re
from symbols import parse_symbols

def string_to_int(i):
    if isinstance(i, int):
        return i
    else:
        try:
            return int(i, 0)
        except:
            return None

def parse_flag(flag, project: pymap.project.Project) -> int:
    flag = flag.split('@')[0].strip()
    if '+' in flag or '-' in flag or '|' in flag or '(' in flag or ')' in flag:
        return None # Ignore
    flag_idx = string_to_int(flag)
    if flag_idx is None:
        if flag in project.constants['flags']:
            return project.constants['flags'][flag]
        else:
            raise ValueError(f'Flag {flag} not found in constants.')
    else:
        return flag_idx
    

def get_recipe_flags(rom, project: Project, symbols: dict) -> set:
    """ Gets all flags that are used in recipies. """
    num_recipies = [project.model['u8'].from_data(rom, symbols[CRAFTING_NUM_RECIPIES] + idx, project, [], [])
        for idx in range(len(project.constants['crafting_recipe_types']) - 1)]
    flags = set()
    for recipe_type_idx, size in enumerate(num_recipies):
        recipies_off = project.model['pointer'].from_data(rom, symbols[CRAFTING_RECIPES] + 4 * recipe_type_idx, project, [], [])
        for idx in range(size):
            recipe_off = 24 * idx + recipies_off
            flag = project.model['u16'].from_data(rom, recipe_off + 18, project, [], [])
            flags.add(flag)
    return flags


def get_flag_locations(flags: set, project: pymap.project.Project) -> defaultdict:
    """ Gets scripts that set a treasure map flag. """
    flag_to_location = {flag : [] for flag in flags}

    # Parse script files
    for subdir, dirs, files in os.walk(SRC_ROOT):
        for file in files:
            filepath = subdir + os.sep + file
            if filepath.endswith('.asm'):
                with open(filepath) as f:
                    content = f.read()
                    # Match callstd giveitems
                    matches = list(re.findall('setflag (.*)', content, flags=re.M))
                    if len(matches):
                        # Reconstruct the bank and map idx and context from the path
                        bank, map_idx = re.findall(f'{SRC_ROOT}/(.*?)/(.*?)/.*', filepath)[0]
                        for flag in matches:
                            try:
                                flag_idx = parse_flag(flag, project)
                                if flag_idx in flags:
                                    # Is a recipe flag
                                    flag_to_location[flag_idx].append({
                                    'type' : 'script',
                                    'context' : '',
                                    'bank' : bank,
                                    'map_idx' : map_idx,
                                })
                            except Exception as e:
                                print(f'Error in parsing flag {flag} in file {filepath}')
                                raise e

    # Parse persons
    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for person_idx, person in enumerate(header['events']['persons']):
                try:
                    if person['script_std_and_in_connection']['script_std'] in ('PERSON_RECIPE',):
                        flag = person['flag']
                        if '+' in flag or '-' in flag or '|' in flag or '(' in flag or ')' in flag:
                                continue # We ignore arithmetic flags here ..
                        flag_idx = parse_flag(flag, project)
                        flag_to_location[flag_idx].append({
                            'type' : 'person',
                            'bank' : bank,
                            'map_idx' : map_idx,
                            'namespace' : namespace,
                            'person_idx' : person_idx,
                            'type' : 'person'
                        })
                except Exception as e:
                    print(f'Error in parsing flag {flag} of person {person_idx} on map {bank},{map_idx}')
                    raise e
    return {k : v for k, v in flag_to_location.items() if k != 0}

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates an index pickle for all recipe flags.')
    parser.add_argument('rom', help='the built rom')
    parser.add_argument('symbols', help='the symbol dump of armips')
    parser.add_argument('project', help='the pymap project')
    parser.add_argument('-o', dest='output', help='output pickle containing the recipe flag locations')
    args = parser.parse_args()
    
    with open(args.rom, 'rb') as f:
        rom = f.read()
    symbols = parse_symbols(args.symbols)
    project = Project(args.project)

    recipe_flags = get_recipe_flags(rom, project, symbols)
    index = get_flag_locations(recipe_flags, project)

    # Add aliases
    flags_inv = project.constants['flags'].inverse()
    # flags_inv = defaultdict(list)
    # for k, v in project.constants['flags'].items():
    #     flags_inv[v].append(k)

    index = {(k,) + tuple(flags_inv[k]) : v for k, v in index.items()}

    with open(args.output, 'wb') as f:
        pickle.dump(index, f)
    