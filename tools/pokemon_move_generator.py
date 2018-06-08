#!/usr/bin/env python3
""" 
This module uses a webcrawler on pokewiki.de as well as predefined
data sets to create movesets, tm compatibility lists and egg moves
for each pokemon which are up to date with the latest generation
"""

LATEST_GENERATION = 7

import sys, getopt, os
import pokemon_move_generator.pokemon_crawler as crawler
from pokemon_move_generator.pokemon_crawler import Pokemon
from pymap import project
import urllib.request
import pprint
import pickle
import os.path
import pokemon_move_generator.link as link
import pokemon_move_generator.normalize as normalize
import pokemon_move_generator.export as export


if __name__ == "__main__":

    try:
        opts, args = getopt.getopt(sys.argv[1:], "h", ["help"])
    except getopt.GetoptError:
        print("opterr")
        sys.exit(2)

    #Parse the options
    for opt, arg in opts:
        if opt in ("-h", "--help"):
            print("Usage: pokemon_move_generator.py [projfile] [linked_elf] [linked_elf_text_dump] " +
            "[linked_elf_evolution_table_dump] [evolution_table_symbol] [lvlup_attacks_symbol] [egg_moves_symbol] " +
            "[tm_compatibility_symbol] [move_tutor_compatibility_symbol] [inaccessible_attacks_symbol] " +
            "[pkmn_data] [outfile])")
            sys.exit(0)

    
    proj = project.Project.load_project(args[0])
    elf = args[1]
    elf_text_dump = args[2]
    elf_evolution_table_dump = args[3]
    evolution_table_symbol = args[4]
    lvlup_attacks_symbol = args[5]
    egg_moves_symbol = args[6]
    tm_compatibility_symbol = args[7]
    move_tutor_compatibility_symbol = args[8]
    inaccessible_attacks_symbol = args[9]
    print(args[10])
    pkmn_data = args[10]
    outfile = args[11]
    
    with open(pkmn_data, "rb") as f:
        pkmns = pickle.load(f)
    linked = link.update_and_link(pkmns, proj.constants)

    output = "#include \"types.h\"\n"
    # Create include preamble
    for constant in ["species", "attacks", "move_tutor"]:
        output += proj.constants.get_include_directive(constant, "c") + "\n"
    
    # Extra pokemon count
    output += "#include \"pokemon/count.h\"\n"
    # Extra moves struct
    output += "#include \"pokemon/moves.h\"\n"

    # Append the sections
    for section in [
        export.export_egg_moves(linked, egg_moves_symbol, proj.constants, 
            elf, elf_text_dump, elf_evolution_table_dump, evolution_table_symbol),
        export.export_lvlup_attacks(linked, lvlup_attacks_symbol, proj.constants),
        export.export_tm_move_compatibility(linked, tm_compatibility_symbol, proj.constants),
        export.export_move_tutor_compatibility(linked, move_tutor_compatibility_symbol, proj.constants),
        export.export_inaccessible_attacks(linked, inaccessible_attacks_symbol, proj.constants)
        ]:
        output += section + "\n\n"

    


    with open(outfile, "w+") as f:
        f.write(output)
