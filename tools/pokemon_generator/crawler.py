#!/usr/bin/env python3

import argparse
import json
import pickle
import requests
import urllib
import pymap.project
import cache.cache as pokeapi_cache
from species_to_idx import species_to_idx

LANGUAGE='de'
VERSION_GROUP='sun-moon'
METHOD_LEVEL_UP = 'Level up'
METHOD_EGG = 'Ei'

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

def get_resource(url, cache=None):
    """ Returns any resource located at the PokéApi.

    Parameters:
    -----------
    url : str
        Url to the resource.
    cache : dict or None
        An optional cache instance.
    
    Returns:
    --------
    response : dict
        The json response.
    """
    # Try to get the resource from the cache
    if cache is not None:
        if url in cache:
            return cache[url]
    response = requests.get(url)
    response.raise_for_status()
    resource = response.json()

    # Try to save the resource in the cache
    if cache is not None:
        cache[url] = resource
    
    return resource


def get_name(resource, language=LANGUAGE):
    """ Returns the name of a resource in a certain language.
    
    Parameters:
    -----------
    resource : dict
        The resource to obtain the name from. The resource must provide
        a 'names' key.
    language : str
        The name of the language that is desired.
        
    Returns:
    --------
    name : str
        The name of the resource.
    """
    for name in resource['names']:
        if name['language']['name'] == language:
            return name['name']
    raise RuntimeError(f'Language {language} not found in {resource}') 

# Translate a stat name to an index
stat_to_idx = {
    'hp' : 0,
    'attack' : 1,
    'defense' : 2,
    'speed' : 3,
    'special-attack' : 4,
    'special-defense' : 5
}

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Fetches and preprocesses data for each pokemon from pokewiki.de.')
    parser.add_argument('project', help='the pymap project which holds the species constants')
    parser.add_argument('-o', dest='output', help='output pickle containing the pokemon data')
    parser.add_argument('--version_group', dest='version_group', help='The version group the movesets are based on.', default=VERSION_GROUP)
    parser.add_argument('--cache', dest='cache', action='store_true', help='If set all data crawled will be cached.')
    args = parser.parse_args()
    
    project = pymap.project.Project(args.project)
    pokemons = []
    cache = pokeapi_cache.get_cache()

    for species in project.constants['species']:
        idx = species_to_idx[species]
        if idx is not None:
            print(f'Fetching pokemon idx {idx}')
            pokemon = {}
        
            # Process the species information
            pokemon_species = get_resource(get_url('pokemon-species', idx), cache=cache)

            pokemon['name'] = get_name(pokemon_species)
            egg_groups = [
                get_name(get_resource(egg_group['url'], cache=cache))
                for egg_group in pokemon_species['egg_groups']
                ] * 2
            pokemon['egg_group_0'] = egg_groups[0]
            pokemon['egg_group_1'] = egg_groups[1]
            
            gender_ratio = pokemon_species['gender_rate']
            if gender_ratio >= 0:
                gender_ratio = int(round(gender_ratio / 8 * 254))
            else:
                gender_ratio = 255
            pokemon['gender_ratio'] = gender_ratio
            pokemon['capture_rate'] = pokemon_species['capture_rate']
            pokemon['base_happiness'] = pokemon_species['base_happiness']
            pokemon['egg_cycles'] = pokemon_species['hatch_counter']
            pokemon['color_and_flip'] = [0, get_name(get_resource(pokemon_species['color']['url'], cache=cache))]
            # Shape is only available in english...
            pokemon['shape'] = get_name(get_resource(pokemon_species['shape']['url'], cache=cache), language='en')
            pokemon['growth_rate'] = pokemon_species['growth_rate']['name']

            pokemon['dex_entry'] = None
            # Parse dex entries
            for dex_entry in pokemon_species['flavor_text_entries']:
                if dex_entry['language']['name'] == LANGUAGE:
                    pokemon['dex_entry'] = dex_entry['flavor_text'].replace('\n', ' ') # Linebreaks will be calculated at compile time
            
            pokemon['genus'] = ''
            # Parse the genera
            for genus in pokemon_species['genera']:
                if genus['language']['name'] == LANGUAGE:
                    pokemon['genus'] = genus['genus']

            pokemon_resource = get_resource(get_url('pokemon', idx), cache=cache)
            pokemon['height'] = pokemon_resource['height']
            pokemon['weight'] = pokemon_resource['weight']
            pokemon['exp_yield'] = min(255, pokemon_resource['base_experience']) # Gen3 only supports bytes
            
            # Parse abilities
            pokemon['hidden_ability'] = None
            pokemon['ability_0'] = None
            pokemon['ability_1'] = None
            for entry in pokemon_resource['abilities']:
                abilitiy_resource = get_resource(entry['ability']['url'], cache=cache)
                ability_name = get_name(abilitiy_resource)
                if entry['is_hidden']:
                    pokemon['hidden_ability'] = ability_name
                else:
                    slot = int(entry['slot']) - 1
                    pokemon[f'ability_{slot}'] = ability_name

            # Parse stats
            pokemon['basestats'] = {}
            pokemon['ev_yield'] = [0] * 7

            for element in pokemon_resource['stats']:
                name = element['stat']['name']
                pokemon['basestats'][name] = element['base_stat']
                pokemon['ev_yield'][stat_to_idx[name]] = element['effort']

            # Parse movesets
            pokemon['levelup_moves'] = []
            pokemon['egg_moves'] = set()
            # TM and tutor moves are later generated based on the 'accessible_moves'
            pokemon['accessible_moves'] = set()

            for element in pokemon_resource['moves']:
                # Only consider moves of one version group
                for version_group_details in element['version_group_details']:
                    if version_group_details['version_group']['name'] == args.version_group:
                        move_learn_method = get_name(get_resource(version_group_details['move_learn_method']['url'], cache=cache))
                        move = get_name(get_resource(element['move']['url'], cache=cache))
                        if move_learn_method == METHOD_LEVEL_UP:
                            pokemon['levelup_moves'].append((move, version_group_details['level_learned_at']))
                        elif move_learn_method == METHOD_EGG:
                            pokemon['egg_moves'].add(move)
                        pokemon['accessible_moves'].add(move)
        
            # Parse held items
            pokemon['common_item'] = 0
            pokemon['rare_item'] = 0
            for element in pokemon_resource['held_items']:
                # Check if this element is associated with the version group
                for version_details in element['version_details']:
                    version = get_resource(version_details['version']['url'], cache=cache)
                    if version['version_group']['name'] == args.version_group:
                        # This item is assigned to a version of the version group
                        rarity = version_details['rarity']
                        name = get_name(get_resource(element['item']['url'], cache=cache))
                        pokemon['common_item' if rarity == 5 else 'rare_item'] = name

            pokemon['type_0'] = None
            pokemon['type_1'] = None
            # Parse types
            for element in pokemon_resource['types']:
                name = get_name(get_resource(element['type']['url'], cache=cache))
                slot = int(element['slot']) - 1
                pokemon[f'type_{slot}'] = name
            
        else:
            pokemon = None
        
        pokemons.append(pokemon)

    # Save the cache instance
    if args.cache:
        pokeapi_cache.save_cache(cache)
    
    # Output the pokemon
    with open(args.output, 'wb') as f:
        pickle.dump(pokemons, f)
