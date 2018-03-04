"""
This module provides functions for exporting C code
based on the data that was obtained by the crawler
"""

from . import link
from . import evolutions

def moveset_label_by_id(species_id, constants):
    """ Creates a moveset label based on the
    species id of a pokemon"""
    species = constants.species_table[species_id][8:].lower()
    return "moveset_pokemon_" + species

def export_lvlup_array(lvlup_attacks, label):
    """ Exports a pokemon_move struct array that holds
    all levelup moves."""
    c = "pokemon_move " + label + "[] = {\n"
    for lvl, attack in lvlup_attacks:
        c += "\t{" + attack + ", " + str(lvl) + "},\n"
    c += "\t{0x1FF, 0x7F}\n};\n\n"
    return c

def export_lvlup_attacks(linked, outfile, constants):
    """ Exports the levelup attacks."""
    # First create a preamble
    output = """#include "types.h"
#include "pokemon.h"
#include "basestats.h"
#include "attack.h"\n\n"""

    # Create the moveset table
    table = "pokemon_move *pokemon_moves[POKEMON_CNT] = {\n"
    for i, _link in enumerate(linked):
        link_type, pkmn = _link
        if link_type == link.NULL:
            label = "NULL"
        elif link_type == link.LINKED:
            label = moveset_label_by_id(pkmn, constants)
        elif link_type == link.REAL:
            label = moveset_label_by_id(i, constants)
            # Dump the real moveset
            output += export_lvlup_array(pkmn.attacks_lvlup, label)
        else:
            raise Exception("Unkown link type" + link_type)
        table += "\t" + label + ",\n"
    table += "};\n"

    output += table
    
    # Output the file
    fp = open(outfile, "w+")
    fp.write(output)
    fp.close()


def export_egg_moves(linked, outfile, constants, rom, offset_evolution_table):
    """ Exports egg moves array. Finds basis stage
    pokemon by using knowledge of an evolution table
    of a pokemon rom."""
    # First get the prevolutions array
    prevolutions = evolutions.parse_evolutions(rom, offset_evolution_table, constants)
    # Create a preamble
    output = """#include "types.h"
#include "basestats.h"
#include "attack.h"\n\n
    """
    # Create the egg move list
    output += "u16 egg_moves[] = {\n"
    for i, _link in enumerate(linked):
        link_type, pkmn = _link
        if link_type == link.REAL and evolutions.is_basis_stage(prevolutions, i):
            if not len(pkmn.attacks_breed): continue
            output += "\t// " + constants.species_table[i][8:].capitalize() + "\n"
            output += "\t20000 + " + constants.species_table[i] + ", "
            for attack in pkmn.attacks_breed:
                output += attack + ", "
            output += "\n"
    output += "\t0xFFFF\n};\n"

    fp = open(outfile, "w+")
    fp.write(output)
    fp.close()
        
