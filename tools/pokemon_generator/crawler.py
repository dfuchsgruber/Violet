#!/usr/bin/env python3

import argparse
import json
import pickle
import requests
import urllib

LANGUAGE='de'
VERSION_GROUP='sun-moon'

def get_url(*args):
    """ Gets the url of a resource. 

    Parameters:
    -----------
    *args :
        The path to the resource

    Returns:
    --------
    url : str
        Url to the resource.
    """
    return f'https://pokeapi.co/api/v2/{"/".join(map(str, args))}/'

def get_resource(url):
    """ Returns any resource located at the PokéApi.

    Parameters:
    -----------
    url : str
        Url to the resource.
    
    Returns:
    --------
    response : dict
        The json response.
    """
    response = requests.get(url)
    response.raise_for_status()
    return response.json()

def get_name(names, language=LANGUAGE):
    """ Returns the name of a resource in a certain language.
    
    Parameters:
    -----------
    names : dict
        The resource to obtain the name from. Usually this is the 'names'
        attribute of another resource.
    language : str
        The name of the language that is desired.
        
    Returns:
    --------
    name : str
        The name of the resource.
    """
    for name in names:
        if name['language']['name'] == language:
            return name['name']
    raise RuntimeError(f'Language {language} not found in {names}') 


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Fetches and preprocesses data for each pokemon from pokewiki.de.')
    parser.add_argument('species', help='The constant value of the species to fetch.')
    parser.add_argument('species_to_idx', help='Path to a json file that maps species constants to numbers.')
    parser.add_argument('output', help='The output pickle file containing all pokemon.')
    parser.add_argument('-g', '--generation', type=int, dest='generation', help='The generation the movesets are based on.', default=7)
    args = parser.parse_args()

    with open(args.species_to_idx) as f:
        species_to_idx = json.load(f)

    idx = species_to_idx[args.species]
    if idx is not None:
        pokemon = {}
    
        # Process the species information
        pokemon_species = get_resource(get_url('pokemon-species', idx))

        pokemon['name'] = get_name(pokemon_species['names'])
        pokemon['egg_groups'] = [
            get_name(get_resource(egg_group['url'])['names'])
            for egg_group in pokemon_species['egg_groups']
            ]
        pokemon['gender_rate'] = pokemon_species['gender_rate'] # in 1/8
        pokemon['capture_rate'] = pokemon_species['capture_rate']
        pokemon['base_happiness'] = pokemon_species['base_happiness']
        pokemon['egg_cycles'] = pokemon_species['hatch_counter']
        pokemon['color'] = get_name(get_resource(pokemon_species['color']['url'])['names'])
        # Shape is only available in english...
        pokemon['shape'] = get_name(get_resource(pokemon_species['shape']['url'])['names'], language='en')
        
        pokemon_resource = get_resource(get_url('pokemon', idx))
        pokemon['height'] = pokemon_resource['height']
        pokemon['weight'] = pokemon_resource['weight']
        pokemon['base_experience'] = pokemon_resource['base_experience']
        
        # Parse abilities
        pokemon['hidden_ability'] = None
        pokemon['abilities'] = []
        for entry in pokemon_resource['abilities']:
            abilitiy_resource = get_resource(entry['ability']['url'])
            ability_name = get_name(abilitiy_resource['names'])
            if entry['is_hidden']:
                pokemon['hidden_ability'] = ability_name
            else:
                pokemon['abilities'].append(ability_name)

        # Parse stats
        pokemon['stats'] = {}
        pokemon['ev_yield'] = {}
        for element in pokemon_resource['stats']:
            name = get_name(get_resource(element['stat']['url'])['names'])
            pokemon['stats'][name] = element['base_stat']
            pokemon['ev_yield'][name] = element['effort']

        # Parse movesets
        pokemon['levelup_moves'] = []
        pokemon['egg_moves'] = {}
        # TM and tutor moves are later generated based on the 'accessible_moves'
        pokemon['accessible_moves'] = {}

        for element in pokemon_resource['moves']:
            pass

        




        
        print(pokemon)

    else:
        pokemon = None

    with open(args.output, 'wb') as f:
        pickle.dump(pokemon, f)
