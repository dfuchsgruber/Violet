#!/usr/bin/env python3

import pokebase
import argparse
import json
import pickle
import requests
import urllib

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

def get_name(names, language='de'):
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
  
        print(get_resource('https://pokeapi.co/api/v2/growth-rate/'))


        
        print(pokemon)

    else:
        pokemon = None

    with open(args.output, 'wb') as f:
        pickle.dump(pokemon, f)
