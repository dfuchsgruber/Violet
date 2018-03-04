"""
This module parses the evolutions
from a pokemon rom in order to
determine if a pokemon evolves from
another (this information is processed
to create egg moves only for pokemon
at basis stage)
"""

def parse_evolutions(rom, offset_evolution_table, constants):
    """ Parses the evolution table from a pokemon rom
    and returns a list that holds the prevolution of
    a pokemon or None if no such prevolution"""
    
    prevolutions = [None for _ in range(len(constants.species_table))]
    # Iterate through the evolution table
    for i in range(len(constants.species_table)):
        for j in range(5):
            offset = offset_evolution_table + i * 40 + j * 8
            method = rom.u16(offset)
            if not method: continue
            target = rom.u16(offset + 4)
            prevolutions[target] = i
    
    return prevolutions

def is_basis_stage(prevolutions, species):
    """ Checks if a pokemon is basis stage and
    does not evolve from any other pokemon."""
    return prevolutions[species] == None

