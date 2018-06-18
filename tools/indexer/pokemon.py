""" File to managa pokemon raw data """

POKEMON_NAME_SIZE = 11
POKEMON_NAMES_SYMBOL = "pokemon_names"

def species_to_name(species_idx, rom, proj, ps, symbols):
    """ Transforms a species index to a pokemon name 
    
    Parameters:
    species_idx : species (int)
    rom : Agbrom rom
    proj : Pymap project
    ps : Pstring instance to parse hex to string
    symbols : dict symbol -> offset """
    pokemon_names = symbols[POKEMON_NAMES_SYMBOL]
    return ps.hex2str(rom, pokemon_names + species_idx * POKEMON_NAME_SIZE)