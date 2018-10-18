#!/usr/bin/env python3
""" 
This module uses a webcrawler on pokewiki.de as well as predefined
data sets to create movesets, tm compatibility lists and egg moves
for each pokemon which are up to date with the latest generation
"""

LATEST_GENERATION = 7

import pokemon_move_generator.pokemon_crawler as crawler
from pokemon_move_generator.pokemon_crawler import Pokemon
import urllib.request
import pickle
import pokemon_move_generator.link as link
import pokemon_move_generator.normalize as normalize
import pokemon_move_generator.export as export
import agb.types
import pymap.project
import argparse


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Creates various moveset data for pokemon data fetched from pokewiki.')
    parser.add_argument('project', help='The pymap project file to use.')
    parser.add_argument('linked', help='Linked object file that contains pokemon evolution data at least.')
    parser.add_argument('text', help='Text section dump of the linked object that contains at least pokemon evolution data.')
    parser.add_argument('evotable', help='Raw evolution table dump of the linked object file.')
    parser.add_argument('evotable_label', help='Label of the evolution table in the linked object file.')
    parser.add_argument('lvlupattacks', help='Label to generate for level up attacks.')
    parser.add_argument('eggmoves', help='Label to generate for the egg moves.')
    parser.add_argument('tmcompatibility', help='Label to generate for the tm/hm compatibility.')
    parser.add_argument('tutor', help='Label to generate for the move tutor compatibility.')
    parser.add_argument('inaccessible', help='Label to generate for the inaccessible moves.')
    parser.add_argument('pkldata', help='The pickled pokemon data fetched from pokewiki.')
    parser.add_argument('-o', help='Path to the output file', dest='output_path')
    args = parser.parse_args()

    proj = pymap.project.Project(args.project)
    
    with open(args.pkldata, "rb") as f:
        pkmns = pickle.load(f)
    linked = link.update_and_link(pkmns, proj.constants)

    # Append the sections
    with open(args.output_path, 'w+') as f:
        f.write('\n\n'.join([
            '\n'.join([
                '#include "types.h"',
                '#include "constants/species.h"',
                '#include "constants/attacks.h"',
                '#include "constants/move_tutor.h"',
                '#include "pokemon/count.h"',
                '#include "pokemon/moves.h"'
            ]),
            export.export_egg_moves(linked, args.eggmoves, proj.constants, 
                args.linked, args.text, args.evotable, args.evotable_label),
            export.export_lvlup_attacks(linked, args.lvlupattacks, proj.constants),
            export.export_tm_move_compatibility(linked, args.tmcompatibility, proj.constants),
            export.export_move_tutor_compatibility(linked, args.tutor, proj.constants),
            export.export_inaccessible_attacks(linked, args.inaccessible, proj.constants),
            ''
            ]))

