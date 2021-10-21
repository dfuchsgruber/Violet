#!/usr/bin/env python3

from symbols import parse_symbols
from pymap.project import Project, _canonical_form
from collections import defaultdict
from pprint import pprint
import argparse, pickle

def get_habitat_index(rompath, symbolspath, projectpath):
    """ Builds the index for the habitats of each species. """
    with open(rompath, 'rb') as f:
        rom = f.read()
    symbols = parse_symbols(symbolspath)
    project = Project(projectpath)

    # Get all species of the project
    habitats = {
        species : [] for species in project.constants['species']
    }

    # Parse wild pokemon habitats
    datatype = project.model['wild_pokemon']
    wild_pokemon_offset = symbols['wild_pokemon']
    wild_pokemon = datatype.from_data(rom, wild_pokemon_offset, project, [], [])
    for entry in wild_pokemon:
        bank, map_idx = _canonical_form(entry['bank']), _canonical_form(entry['map_idx'])
        label, path, namespace = project.headers[bank][map_idx]
        for habitat in ('grass', 'water', 'other', 'odd_rod', 'good_rod', 'super_rod'):
            if 'rod' in habitat: # Parse rod separately
                if entry['rod'] is None: continue
                encountered_species = parse_habitat(entry['rod']['entries'][habitat])
            else:
                if entry[habitat] is None: continue
                encountered_species = parse_habitat(entry[habitat]['entries'])
            # Add this map to the pokemons habitats
            for species in encountered_species:
                habitats[species].append({
                    'type' : 'wild',
                    'bank' : bank,
                    'map_idx' : map_idx,
                    'label' : label,
                    'namespace' : namespace,
                    'habitat' : habitat,
                    'level_min' : encountered_species[species][0],
                    'level_max' : encountered_species[species][1], 
                })
    
    # Parse wondertrade
    datatype = project.model['species_list']
    for rank in ('bronze', 'silver', 'gold', 'platinum'):
        offset = symbols[f'wondertrade_pokemon_{rank}']
        for species in datatype.from_data(rom, offset, project, [], []):
            habitats[species].append({
                'type' : 'wondertrade',
                'rank' : rank,
            })

    # # Parse dungeons
    # datatype = project.model['species_list']
    # for dungeon in ('cave', 'forest', 'ocean'):
    #     for rarity in ('common', 'rare', 'super_rare'):
    #         if dungeon == 'ocean':
    #             rarity = f'water_{rarity}'
    #         offset = symbols[f'dungeon_{dungeon}_wild_pokemon_{rarity}']
    #         for species in datatype.from_data(rom, offset, project, [], []):
    #             habitats[species].append({
    #                 'type' : 'dungeon',
    #                 'dungeon' : dungeon,
    #                 'rarity' : rarity
    #             })
    # Parse the rod pokemon of the ocean dungeon
    for rod_type in ('rod', 'good_rod', 'super_rod'):
        offset = symbols[f'dungeon_ocean_wild_pokemon_{rod_type}']
        for species in datatype.from_data(rom, offset, project, [], []):
            habitats[species].append({
                'type' : 'dungeon',
                'dungeon' : 'ocean',
                'rod' : rod_type,
            })

    # Eggs
    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            try:
                for person in header['events']['persons']:
                    if person['script_std'] == 'PERSON_EGG':
                        habitats[person['value']['species']].append({
                            'type' : 'egg',
                            'bank' : bank,
                            'map_idx' : map_idx,
                            'label' : label,
                            'namespace' : namespace,
                        })
            except Exception as e:
                print(f'Error in map {bank},{map_idx}')
                raise e

    # Event Pokémon
    habitats['POKEMON_PORYGON'] = [{
        'type' : 'event',
        'description' : 'from Elise after the third badge',
    }]
        
    return habitats


def parse_habitat(habitat):
    """ Parses a set of encounters for a habitat.

    Parameters:
    -----------
    habitat : list
        A set of encounters.

    Returns:
    --------
    species : defaultdict
        A dict mapping each species to its min and max level.
    """
    encountered_species = defaultdict(lambda: [256, -1])
    for encounter in habitat:
        lvl_min = encounter['level_min']
        lvl_max = encounter['level_max']
        species = encounter['species']
        encountered_species[species][0] = min(encountered_species[species][0], lvl_min)
        encountered_species[species][1] = max(encountered_species[species][1], lvl_max)
    return encountered_species

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates an index pickle for all species habitats.')
    parser.add_argument('rom', help='the built rom')
    parser.add_argument('symbols', help='the symbol dump of armips')
    parser.add_argument('project', help='the pymap project which holds the species constants')
    parser.add_argument('-o', dest='output', help='output pickle containing the habitats')
    args = parser.parse_args()

    habitats = get_habitat_index(args.rom, args.symbols, args.project)
    with open(args.output, 'wb') as f:
        pickle.dump(habitats, f)
