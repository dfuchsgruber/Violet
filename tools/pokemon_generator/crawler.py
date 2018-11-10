#!/usr/bin/env python3

import argparse
import json
import pickle
import requests
import urllib
import pymap.project
import cache.cache as pokeapi_cache
from species_to_idx import species_to_idx
import language, evolution

LANGUAGE='de' # This is language the constants are in (do not change!)
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



def parse_evolution_chain_entry(entry, species_idx, baby_trigger_item=None, cache=None, language='de'):
    """ Reursively parses an entry in the evolution chain.
    
    Parameters:
    -----------
    entry : dict
        The evolution chain entry, possibly nested.
    species_idx : int
        The original dex value of the species.
    baby_trigger_item : str or None
        The item for triggering the baby breeding.
    cache : dict or None
        An optional cache instance.
    language : str
        The language 
    
    Returns:
    --------
    evolutions : dict or None
        A dict representing the evolutions of a pokemon.
    """
    entry_idx = get_resource(entry['species']['url'], cache=cache)['id']
    if species_idx == entry_idx:
        # Found the entry of this species in the evolution chain
        evolutions = {}
        # Parse all evolutions of this species
        for target in entry['evolves_to']:
            target_idx = get_resource(target['species']['url'], cache=cache)['id']
            target_species = None
            for species, idx in species_to_idx.items():
                if idx == target_idx:
                    target_species = species
                    break
            if target_species is None:
                raise RuntimeError(f'Evolution target with species index {target_idx} not in species_to_idx as value.')
            evolutions[target_species] = {}
            # Parse evolution details
            evolution_details = target['evolution_details'][0]
            trigger, argument = parse_evolution_method(evolution_details, cache=cache)
            evolutions[target_species]['trigger'] = trigger
            evolutions[target_species]['argument'] = argument
            evolutions[target_species]['baby_trigger_item'] = baby_trigger_item if entry['is_baby'] else None
        return evolutions
    else:
        # Recursively explore the evolution tree
        for target in entry['evolves_to']:
            evolutions = parse_evolution_chain_entry(target, species_idx, baby_trigger_item=baby_trigger_item, cache=cache, language=language)
            if evolutions is not None:
                return evolutions
    # In this branch of the evolution tree no match was found
    return None

        
def parse_evolution_method(evolution_details, cache=None):
    """ Parses the evolution method of a evolution chain entry. That is,
    the trigger and arguments are infered and an evolution method is generated
    that only demans a single argument.
    
    Parameters:
    -----------
    evolution_details : dict
        The evolution details.
    cache : dict or None
        An optional cache instance.

    Returns:
    --------
    evolution_method : str
        The evolution method.
    argument : str or int
        The argument.
    """
    # Note that the following methods are not properly integrated into the Api and have to be part of the updates therefore
    # PID-based: Pid_even, Pid_odd
    # Map-based: On_Map
    # Shed : Shedinja
    trigger_type = evolution_details['trigger']['name']
    if trigger_type == 'level-up': 
        # Level Up induced evolution
        if evolution_details['min_happiness'] is not None: 
            # Friendship based evolution
            return evolution.get_friendship_evolution(evolution_details), evolution_details['min_happiness']
        elif evolution_details['relative_physical_stats'] is not None:
            # Tyrouge evolution line
            return evolution.get_physical_stat_based_evolution(evolution_details), evolution_details['min_level']
        elif evolution_details['min_beauty'] is not None:
            # Milotic
            return 'Beauty', evolution_details['min_beauty']
        elif evolution_details['held_item'] is not None:
            # Parse the item
            item_name = get_name(get_resource(evolution_details['held_item']['url'], cache=cache))
            return evolution.get_held_item_based_evolution(evolution_details), item_name
        elif evolution_details['known_move'] is not None:
            move = get_name(get_resource(evolution_details['known_move']['url'], cache=cache))
            return 'Know_Move', move
        elif evolution_details['known_move_type'] is not None:
            move_type = get_name(get_resource(evolution_details['known_move_type']['url'], cache=cache))
            return 'Know_Move_Type', move_type
        else:
            return 'Level_Up', evolution_details['min_level']
    elif trigger_type == 'trade':
        # Trade based evolutions will become link-cable based
        if evolution_details['held_item'] is not None:
            return 'Link_Cable_and_Item', get_name(get_resource(evolution_details['held_item']['url'], cache=cache))
        else:
            return 'Stone', 'Linkkabel'
    elif trigger_type == 'use-item':
        argument = get_name(get_resource(evolution_details['item']['url'], cache=cache))
        return evolution.get_stone_based_evolution(evolution_details), argument
    elif trigger_type == 'shed':
        return 'Spawn_Second', evolution_details['min_level']
    else:
        raise RuntimeError(f'Unsupported trigger type {trigger_type} for evolution {evolution_details}')

            

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

            pokemon['name'] = {lang : get_name(pokemon_species, language=value) for lang, value in language.languages.items()}
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

            # Parse evolutions
            evolution_chain = get_resource(pokemon_species['evolution_chain']['url'], cache=cache)
            baby_trigger_item = None
            if evolution_chain['baby_trigger_item'] is not None:
                baby_trigger_item = get_name(get_resource(evolution_chain['baby_trigger_item']['url'], cache=cache))
            pokemon['evolutions'] = parse_evolution_chain_entry(evolution_chain['chain'], idx, baby_trigger_item=baby_trigger_item, cache=cache)

            pokemon['dex_entry'] = {}
            # Parse dex entries
            for dex_entry in pokemon_species['flavor_text_entries']:
                for lang, value in language.languages.items():
                    if dex_entry['language']['name'] == value:
                        # Check if the version group matches
                        version = get_resource(dex_entry['version']['url'], cache=cache)['version_group']['name']
                        if version == args.version_group or version == 'x-y': # For some pokemon the database is incomplete
                            pokemon['dex_entry'][lang] = dex_entry['flavor_text'].replace('\n', ' ') # Linebreaks will be calculated at compile time
                            for sequence in ('\u00ad ', '\u00ad', '\f', '”'): # Remove -, new page chars, and the Pokémon suffix from the genus
                                pokemon['dex_entry'][lang] = pokemon['dex_entry'][lang].replace(sequence, '')
            
            pokemon['genus'] = {}
            # Parse the genera
            for genus in pokemon_species['genera']:
                for lang, value in language.languages.items():
                    if genus['language']['name'] == value:
                        pokemon['genus'][lang] = genus['genus'].replace(' Pokémon', '') # Remove the Pokémon suffix

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
