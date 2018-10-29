#!/usr/bin/env python3

import argparse, json, pickle
from pymap import project

def merge(target, source):
    """ Merges all keys from target recursively into source.
    Dicts are merged, lists are appended, other values simply replaced.
    
    Parameters:
    -----------
    target : dict
        The target dict that will be extended and overwritten.
    source : dict
        The source dict from which overwrite values are taken.
    """
    for key in source:
        if key in target:
            # Decide what to do based on the type of the value
            if isinstance(target[key], list):
                target[key] += source[key]
            elif isinstance(target[key], dict):
                merge(target[key], source[key])
            else:
                target[key] = source[key]
        else:
            target[key] = source[key]

def update_pokemon(base, update):
    """ Updates a pokemon dictionary with new values.
    
    Parameters:
    -----------
    base : dict
        The pokemon base (fetched from PokeApi).
    update : dict
        The custom update for this pokemon.
    
    Returns:
    --------
    updated : dict
        The updated pokemon.
    """
    updated = base.copy()
    merge(updated, update)
    return updated

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates a json table for the stats and movesets of each pokemon.')
    parser.add_argument('stats', help='Base stats fetched from PokeApi.')
    parser.add_argument('updates', help='JSON that holds updates for each Pokemon.')
    parser.add_argument('project', help='The pymap project.')
    parser.add_argument('output', help='Output JSON')
    args = parser.parse_args()

    with open(args.stats, 'rb') as f:
        stats = pickle.load(f)
    with open(args.updates) as f:
        updates = json.load(f)

    project = project.Project(args.project)
    
    for species in updates:
        update = updates[species]
        idx = project.constants['species'][species]
        if stats[idx] is not None:
            # Update the stats from the PokeApi
            merge(stats[idx], update)
        else:
            # Simply use the update as stat set
            stats[idx] = update
        # Apply move links if present
        if 'move_link' in update:
            link_target = update['move_link']
            # print(f'Move link for {species} to {link_target}')
            link_idx = project.constants['species'][link_target]
            stats[idx]['levelup_moves'] = stats[link_idx]['levelup_moves']
            stats[idx]['accessible_moves'] = stats[link_idx]['accessible_moves']
            stats[idx]['egg_moves'] = stats[link_idx]['egg_moves']

    with open(args.output, 'wb') as f:
        pickle.dump(stats, f)       




    