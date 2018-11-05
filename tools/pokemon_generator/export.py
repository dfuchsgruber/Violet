#!/usr/bin/env python3

import argparse
import pymap.project
import pickle
import json
from export import *

if __name__ == '__main__':

    # Define types to export
    types_to_export = (
        # Triplets: name, default_file_type, default_label, export_function
        ('basestats', 'basestats', 'basestats', basestats.export_basestats),
        ('levelupmoves', 'levelup_moves', 'pokemon_movesets', levelup_moves.export_levelup_moves),
        ('eggmoves', 'egg_moves', 'pokemon_egg_moves', egg_moves.export_egg_moves),
        ('tmcompatibility', 'tm_compatibilities', 'pokemon_tm_compatibility', compatibility.export_tm_compatibility),
        ('tutorcompatibility', 'tutor_compatibilities', 'pokemon_move_tutor_compatibility', compatibility.export_tutor_compatibility),
        ('accessiblemoves', 'accessible_moves', 'pokemon_accessible_moves', accessible_moves.export_accessible_moves),
        ('pokemonnames', 'pokemon_names', 'pokemon_names', pokemon_names.export_pokemon_names),
        ('pokedexorder', 'pokedex_order', 'pokedex_order', pokedex_order.export_pokedex_order),
        ('pokedexentries', 'pokedex_entries', 'pokedex_entries',
            lambda stats, project: pokedex_entries.export_pokedex_entries(stats, project, pokedex_order.export_pokedex_order(stats, project))
        )
    )

    parser = argparse.ArgumentParser(description='Exports base stats and move tables.')
    parser.add_argument('input', help='File that contains the pokemon stats and movesets.')
    parser.add_argument('project', help='The pymap project.')

    # Add arguments for file types to export
    for name, default_file_type, default_label, _ in types_to_export:
        parser.add_argument(name, help=f'Path to the {name}.')
        parser.add_argument(f'--{name}filetype', dest=f'{name}filetype', help=f'Filetype of the {name}.', default=default_file_type)
        parser.add_argument(f'--{name}label', dest=f'{name}label', help=f'Label for the {name}', default=default_label)

    args = parser.parse_args()

    with open(args.input, 'rb') as f:
        stats = pickle.load(f)
    project = pymap.project.Project(args.project)

    # Export types

    for name, _, _, export_func in types_to_export:
        with open(getattr(args, name), 'w+', encoding=project.config['json']['encoding']) as f:
            json.dump({
                'label' : getattr(args, f'{name}label'),
                'type' : getattr(args, f'{name}filetype'),
                'data' : export_func(stats, project)
            }, f, indent=project.config['json']['indent'])