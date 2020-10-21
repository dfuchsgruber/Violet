#!/usr/bin/env python3

import argparse, json, pickle
from pymap import project
from export import tms, move_tutor
import copy

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
            elif isinstance(target[key], set):
                target[key].update(source[key])
            else:
                target[key] = source[key]
        else:
            target[key] = source[key]

def update_accessible_moves(stats):
    """ Updates the accessible moves by removing the levelup moves,
    egg moves, tm moves as well as tutor moves from the set.
    
    Parameters:
    -----------
    stats : dict
        The updated stats of the pokemon.
        
    Returns:
    --------
    accessible_moves : set
        The accessible moves of the pokemon.
    """
    accessible_moves = set(stats['accessible_moves'])
    if 'levelup_moves' in stats:
        accessible_moves.difference_update(map(lambda x: x[0], stats['levelup_moves']))
    if 'egg_moves' in stats:
        accessible_moves.difference_update(stats['egg_moves'])
    accessible_moves.difference_update(move_tutor.tutor_moves)
    accessible_moves.difference_update(tms.tms.keys())
    return accessible_moves

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates a json table for the stats and movesets of each pokemon.')
    parser.add_argument('stats', help='Base stats fetched from PokeApi.')
    parser.add_argument('updates', help='JSON that holds updates for each Pokemon.')
    parser.add_argument('project', help='The pymap project.')
    parser.add_argument('-o', dest='output', help='Output pickle.')
    args = parser.parse_args()

    with open(args.stats, 'rb') as f:
        stats = pickle.load(f)
    with open(args.updates) as f:
        updates = json.load(f)

    project = project.Project(args.project)
    
    species_links = []

    for species in updates:
        update = updates[species]
        idx = project.constants['species'][species]
        if stats[idx] is not None:
            # Update the stats from the PokeApi
            merge(stats[idx], update)
        else:
            # Simply use the update as stat set
            stats[idx] = update
        # Apply species links if present
        if 'species_link' in update:
            link_target = update['species_link']
            link_idx = project.constants['species'][link_target]
            species_links.append((idx, link_idx))


    for idx, link_idx in species_links:
        # Copy the target
        stat = copy.deepcopy(stats[link_idx])
        # Update the target
        merge(stat, stats[idx])
        stats[idx] = stat

    # Create move sets for each species
    for idx, stat in enumerate(stats):
        if stat is None:
            print(idx)
        if not 'accessible_moves' in stat:
            stat['accessible_moves'] = set()
        stat['tm_compatiblilty'] = [
            (move, tms.tms[move]) for move in tms.tms if move in stat['accessible_moves']
        ]
        stat['tutor_compatibility'] = [
            move for move in move_tutor.tutor_moves if move in stat['accessible_moves']
        ]
        stat['accessible_moves'] = update_accessible_moves(stat)

    with open(args.output, 'wb') as f:
        pickle.dump(stats, f)       




    
