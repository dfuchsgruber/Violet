"""
This module parses the evolutions
from a pokemon rom in order to
determine if a pokemon evolves from
another (this information is processed
to create egg moves only for pokemon
at basis stage)
"""

from agb import agbrom

#
#TODO: arm-none-eabi-readelf -S linked.o | grep ".text" dumps the location of text segment
#TODO: arm-none-eabi-readelf -s linked.o  | grep "pokemon_evolutions" dumps the offset of the symbol inside the .text segment


def prevolutions_from_elf(elf, elf_text_dump, elf_evolution_table_dump, 
    evolution_table_symbol, constants):
    """ Retrieves the prevolution table from a linked elf
    file (linked.o) and meta data created by following commands:
    elf_text_dump: arm-none-eabi-readelf -S linked.o | grep ".text" > elf_text_dump
    elf_evolution_table_dump: arm-none-eabi-readelf -s linked.o  \ 
    | grep "pokemon_evolutions" > elf_evolution_table_dump
    """
    # Retrieve the offset of the text section
    with open(elf_text_dump, "r") as f:
        text_offset = None
        for line in f.read().splitlines():
            tokens = line.split()
            if tokens[2] == ".text":
                text_offset = int(tokens[5], 16)
                break
        if text_offset is None:
            raise Exception("Elf text dump does not contain .text section")

    # Retrieve the offset of the evolution table in
    # the text section
    with open(elf_evolution_table_dump) as f:
        evolution_table_offset = None
        for line in f.read().splitlines():
            tokens = line.split()
            if tokens[-1] == evolution_table_symbol:
                evolution_table_offset = int(tokens[1], 16)
                break
        if evolution_table_offset is None:
            raise Exception("Elf evolution table dump does not contain {0} entry".format(
                evolution_table_symbol
            ))

    rom = agbrom.Agbrom(elf)
    return parse_evolutions(rom, text_offset + evolution_table_offset, constants)


def parse_evolutions(rom, offset_evolution_table, constants):
    """ Parses the evolution table from a pokemon rom
    and returns a list that holds the prevolution of
    a pokemon or None if no such prevolution"""
    
    species_constants = constants['species']
    num_species = int(species_constants[max(species_constants, key=lambda key: int(species_constants.__getitem__(key)))]) + 1

    prevolutions = [None] * num_species
    # Iterate through the evolution table
    for i in range(num_species):
        for j in range(5):
            offset = offset_evolution_table + i * 40 + j * 8
            method = rom.u16[offset]
            if not method: continue
            target = rom.u16[offset + 4]
            prevolutions[target] = i
    
    return prevolutions

def is_basis_stage(prevolutions, species):
    """ Checks if a pokemon is basis stage and
    does not evolve from any other pokemon."""
    return prevolutions[species] == None

