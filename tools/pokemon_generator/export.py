#!/usr/bin/env python3

import argparse
import pymap.project
import pickle
import json
from functools import partial
import tms, move_tutor

def strfix(s):
    """ Removes all invalid characters of strings such that
    they match the constants.
    
    Parameters:
    -----------
    s : str
        The string to fix (in upper case letters!)
    
    Returns:
    --------
    fixed : str
        The fixed string.
    """
    for seq, repl in (('Ä', 'AE'), ('Ü', 'UE'), ('Ö', 'OE'), ('-', '_'), (' ', '_'), ('ß', 'SS')):
        s = s.replace(seq, repl)
    return s

def attack_to_constant(project, attack):
    """ Tries to associate an attack with a constant.
    
    Parameters:
    -----------
    project : pymap.project.Project
        The pymap project.
    attack : str
        The attack string.
    
    Returns:
    constant : str or None
        The constant if the attack could be associated or None if not.
    """
    attack = f'ATTACK_{strfix(attack.upper())}'
    if attack in project.constants['attacks']:
        return attack
    else:
        return None

def item_to_constant(project, item):
    """ Tries to associate an item with a constant.
    
    Parameters:
    -----------
    project : pymap.project.Project
        The pymap project.
    item : str
        The item string.
    
    Returns:
    constant : str or None
        The item if the attack could be associated or None if not.
    """
    item = f'ITEM_{strfix(item.upper())}'
    if item in project.constants['items']:
        return item
    else:
        return None



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Exports base stats and move tables.')
    parser.add_argument('input', help='File that contains the pokemon stats and movesets.')
    parser.add_argument('project', help='The pymap project.')
    parser.add_argument('stats', help='Path to output the stats json.')
    parser.add_argument('movesets', help='Path to output the movesets json.')
    parser.add_argument('egg_moves', help='Path to output the egg move json.')
    parser.add_argument('tm_compatibility', help='Path to the tm compatbililty json.')
    parser.add_argument('tutor_compatibility', help='Path to the tutor compatibility json.')
    parser.add_argument('accessible_moves', help='Path to the accessible moves json.')
    parser.add_argument('pokemon_names', help='Path to the pokemon names json.')
    parser.add_argument('pokedex_order', help='Path to the pokdex order json.')
    parser.add_argument('pokedex_entries', help='Path to the pokdex entries json.')
    parser.add_argument('--statsfiletype', dest='stats_file_type', help='File type for the stats.', default='stats')
    parser.add_argument('--statslabel', dest='stats_label', help='Label for the stats table.', default='basestats')
    parser.add_argument('--levelupmovesfiletype', dest='levelup_moves_file_type', help='File type for levelup mvoes.', default='levelup_moves')
    parser.add_argument('--levelupmoveslabel', dest='levelup_moves_label', help='Label for the levelup moves.', default='pokemon_movesets')
    parser.add_argument('--eggmovesfiletype', dest='egg_moves_file_type', help='File type for the egg moves.', default='egg_moves')
    parser.add_argument('--eggmoveslabel', dest='egg_moves_label', help='Label for the egg moves.', default='pokemon_egg_moves')
    parser.add_argument('--tmcompatibilityfiletype', dest='tm_compatibility_file_type', help='File type for the tm compatibility.', default='tm_compatibilities')
    parser.add_argument('--tmcompatibilitylabel', dest='tm_compatibility_label', help='Label for the tm compatibility.', default='pokemon_tm_compatibility')
    parser.add_argument('--tutorcompatibilityfiletype', dest='tutor_compatibility_file_type', help='File type for the tutor compatibility.', default='tutor_compatibilities')
    parser.add_argument('--tutorcompatibilitylabel', dest='tutor_compatibility_label', help='Label for the tutor compatibility.', default='pokemon_move_tutor_compatibility')
    parser.add_argument('--accessiblemovesfiletype', dest='accessible_moves_file_type', help='File type for the accessible moves.', default='accessible_moves')
    parser.add_argument('--accessiblemoveslabel', dest='accessible_moves_label', help='Label for the accessible moves.', default='pokemon_accessible_moves')
    parser.add_argument('--pokemonnamesfiletype', dest='pokemon_names_file_type', help='File type for the accessible moves.', default='pokemon_names')
    parser.add_argument('--pokemonnameslabel', dest='pokemon_names_label', help='Label for the accessible moves.', default='pokemon_names')
    parser.add_argument('--pokedexorderfiletype', dest='pokedex_order_file_type', help='File type for the pokedex order.', default='pokedex_order')
    parser.add_argument('--pokedexorderlabel', dest='pokedex_order_label', help='Label for the pokedex order.', default='pokedex_order')
    parser.add_argument('--pokedexentriesfiletype', dest='pokedex_entries_file_type', help='File type for the pokedex entries.', default='pokedex_entries')
    parser.add_argument('--pokedexentrieslabel', dest='pokedex_entries_label', help='Label for the pokedex entries.', default='pokedex_entries')
    args = parser.parse_args()

    with open(args.input, 'rb') as f:
        stats = pickle.load(f)

    project = pymap.project.Project(args.project)

    levelup_moves = []
    egg_moves = []
    tm_compatbililties = []
    tutor_compatibilities = []
    accessible_moves = []
    pokemon_names = []
    pokedex_order = []
    pokedex_entries = [{
        'genus' : 'Unbekannt',
        'height' : 0,
        'weight' : 0,
        'entry_string_0' : None,
        'entry_string_1' : None,
        'field_14' : 0,
        'pokemon_scale' : 0,
        'pokemon_displace' : 0,
        'trainer_scale' : 0,
        'trainer_displace' : 0,
        'field_1E' : 0
    } for i in range(386 + 1)]

    # Export stats
    for stat in stats:
        levelup_moves.append(stat.pop('levelup_moves', None))
        egg_moves.append(stat.pop('egg_moves', None))
        tm_compatbililties.append(tms.get_tm_compatibility(stat['tm_compatiblilty']))
        tutor_compatibilities.append(move_tutor.get_tutor_compatibility(stat['tutor_compatibility']))
        if egg_moves[-1] is not None and len(egg_moves[-1]) > 0:
            egg_moves[-1] = list(filter(lambda x: x is not None, map(partial(attack_to_constant, project), egg_moves[-1])))
        else:
            egg_moves[-1] = None
        accessible_moves.append(list(filter(lambda x: x is not None, map(partial(attack_to_constant, project), stat.pop('accessible_moves', None)))))
        pokemon_names.append(stat.get('name', '???????'))
        pokedex_number = stat.get('dex_number', 0)
        pokedex_order.append(pokedex_number)
        if pokedex_number > 0:
            # Copy into dex entry
            if 'genus' in stat:
                pokedex_entries[pokedex_number]['genus'] = stat['genus']
            if 'dex_entry' in stat:
                pokedex_entries[pokedex_number]['entry_string_0'] = stat['dex_entry']
            if 'weight' in stat:
                pokedex_entries[pokedex_number]['weight'] = stat['weight']
            if 'height' in stat:
                pokedex_entries[pokedex_number]['height'] = stat['height']

        # Add prefixes to match the constants
        for keys, prefix in ((('type_0', 'type_1'), 'TYPE_'),
            (('growth_rate', ), 'GROWTH_RATE_'),
            (('egg_group_0', 'egg_group_1'), 'EGG_GROUP_'),
            (('ability_0', 'ability_1', 'hidden_ability'), ''),
            (('shape',), 'SHAPE_')):
            for key in keys:
                if stat[key] is not None:
                    stat[key] = strfix(f'{prefix}{stat[key]}'.upper())
                else:
                    stat[key] = 0
        # The color is nested, treat it differently
        color = stat['color_and_flip'][1]
        stat['color_and_flip'][1] = strfix(f'POKEMON_COLOR_{color}'.upper())
        # The item may not be present
        for key in ('common_item', 'rare_item'):
            item = stat[key]
            stat[key] = 0
            if item is not None:
                item = item_to_constant(project, str(item))
                if item is not None:
                    stat[key] = item

    with open(args.stats, 'w+', encoding='utf-8') as f:
        json.dump({
            'label' : args.stats_label,
            'type' : args.stats_file_type,
            'data' : stats
        }, f, indent=project.config['json']['indent'])

    # unmatched_moves = set()
    # Export levelup moves
    for i, moveset in enumerate(levelup_moves):
        if moveset is None:
            continue
        # unmatched_moves.update(attack for attack, _ in filter(lambda x: attack_to_constant(project, x[0]) is None, moveset))
        moveset = map(lambda x: (attack_to_constant(project, x[0]), x[1]), moveset)
        moveset = filter(lambda x: x[0] is not None, moveset)
        moveset = sorted(moveset, key=lambda x: x[1])
        levelup_moves[i] = moveset
    
    with open(args.movesets, 'w+', encoding='utf-8') as f:
        json.dump({
            'label' : args.levelup_moves_label,
            'type' : args.levelup_moves_file_type,
            'data' : levelup_moves
        }, f, indent=project.config['json']['indent'])

    # Export egg moves
    with open(args.egg_moves, 'w+', encoding='utf-8') as f:
        json.dump({
            'label' : args.egg_moves_label,
            'type' : args.egg_moves_file_type,
            'data' : egg_moves
        }, f, indent=project.config['json']['indent'])

    # Create tm/hm moves
    with open(args.tm_compatibility, 'w+', encoding='utf-8') as f:
        json.dump({
            'label' : args.tm_compatibility_label,
            'type' : args.tm_compatibility_file_type,
            'data' : tm_compatbililties
        }, f, indent=project.config['json']['indent'])

    # Export tutor compatibility
    with open(args.tutor_compatibility, 'w+', encoding='utf-8') as f:
        json.dump({
            'label' : args.tutor_compatibility_label,
            'type' : args.tutor_compatibility_file_type,
            'data' : tutor_compatibilities
        }, f, indent=project.config['json']['indent'])

    # Export accessible moves
    with open(args.accessible_moves, 'w+', encoding='utf-8') as f:
        json.dump({
            'label' : args.accessible_moves_label,
            'type' : args.accessible_moves_file_type,
            'data' : accessible_moves
        }, f, indent=project.config['json']['indent'])

    # Export pokemon names
    with open(args.pokemon_names, 'w+', encoding='utf-8') as f:
        json.dump({
            'label' : args.pokemon_names_label,
            'type' : args.pokemon_names_file_type,
            'data' : pokemon_names
        }, f, indent=project.config['json']['indent'])

    # Export pokedex order
    with open(args.pokedex_order, 'w+', encoding='utf-8') as f:
        json.dump({
            'label' : args.pokedex_order_label,
            'type' : args.pokedex_order_file_type,
            'data' : pokedex_order[1:]
        }, f, indent=project.config['json']['indent'])

    # Export pokedex entries
    with open(args.pokedex_entries, 'w+', encoding='utf-8') as f:
        json.dump({
            'label' : args.pokedex_entries_label,
            'type' : args.pokedex_entries_file_type,
            'data' : pokedex_entries
        }, f, indent=project.config['json']['indent'])