#!/usr/bin/env python3

from symbols import parse_symbols
from pymap.project import Project, _canonical_form
from collections import defaultdict
from pprint import pprint
import argparse, pickle

def tm_hm_compatibility_to_list(compatiblity, tm_hm_to_attack):
    """ Maps a bitfield list of tm_hm_compatiblities to HMs / TMs"""
    l = []
    for i in range(50 + 8):
        if compatiblity[i // 8] & (1 << (i & 7)):
            if i < 50:
                name = ('TM', i + 1)
            else:
                name = ('VM', i - 50 + 1)
            l.append((name, tm_hm_to_attack[i]))
    return l

def get_tm_hm_compatiblity(rom, symbols, project):
    """ Gets the TM / HM compatibility for all species. """
    tm_hm_to_attack = project.model['tm_hm_to_attack'].from_data(rom, symbols['tm_hm_to_attack'], project, [], [])
    tm_hm_comptability = project.model['tm_compatibilities'].from_data(rom, symbols['pokemon_tm_compatibility'], project, [], [])
    return [
        tm_hm_compatibility_to_list(c, tm_hm_to_attack) for c in tm_hm_comptability
    ]

def move_tutor_compatability_to_list(compatibility, tutor_to_attack):
    """ Maps a bitfield to a list of move tutor compatabilities. """
    l = []
    for i in range(len(tutor_to_attack)):
        if compatibility & (1 << i):
            l.append((i, tutor_to_attack[i]))
    return i

def get_move_tutor_compatibility(rom, symbols, project):
    """ Gets the move tutor compatibility for all species. """
    tutor_to_attack = project.model['move_tutor_to_attack'].from_data(rom, symbols['move_tutor_attacks'], project, [], [])
    tutor_compatibilities = project.model['tutor_compatibilities'].from_data(rom, symbols['pokemon_move_tutor_compatibility'], project, [], [])
    return [
        move_tutor_compatability_to_list(c, tutor_to_attack) for c in tutor_compatibilities
    ]

def get_pokemon_index(rompath, symbols_path, project_path):
    """ Builds the index for the data of each species. """
    with open(rompath, 'rb') as f:
        rom = f.read()
    symbols = parse_symbols(symbols_path)
    project = Project(project_path)
    return {
        'levelup_moves' : project.model['levelup_moves'].from_data(rom, symbols['pokemon_moves'], project, [], []),
        'pokedex_order' : [0] + project.model['pokedex_order'].from_data(rom, symbols['pokedex_order'], project, [], []),
        'basestats' : project.model['basestats'].from_data(rom, symbols['basestats'] , project, [], []),
        'pokedex_entries' : project.model['pokedex_entries'].from_data(rom, symbols['pokedex_entries'], project, [], []),
        'egg_moves' : project.model['egg_moves'].from_data(rom, symbols['pokemon_egg_moves'], project, [], []),
        'accessible_moves' : project.model['accessible_moves'].from_data(rom, symbols['pokemon_accessible_moves'], project, [], []),
        'tm_hm_compatibility' : get_tm_hm_compatiblity(rom, symbols, project),
        'move_tutor_compatibility' : get_move_tutor_compatibility(rom, symbols, project),
        'evolutions' : project.model['evolutions'].from_data(rom, symbols['pokemon_evolutions'], project, [], [])
    }

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates an index pickle for pokemon stats, movesets ...')
    parser.add_argument('rom', help='the built rom')
    parser.add_argument('symbols', help='the symbol dump of armips')
    parser.add_argument('project', help='the pymap project which holds the species constants')
    parser.add_argument('-o', dest='output', help='output pickle containing the pokemon data')
    args = parser.parse_args()

    index = get_pokemon_index(args.rom, args.symbols, args.project)
    with open(args.output, 'wb') as f:
        pickle.dump(index, f)
