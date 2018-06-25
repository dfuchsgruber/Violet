import wild_pokemon, wondertrade, pokemon

def index_species(symbols, rom, proj, ps):
    """ Creates an index for all species 
    Parameters:
    symbols : The symbol table
    rom : The rom
    proj : The pymap project
    ps : The Pstring parser

    Returns: A list of lists containing IndexEntry instances """
    species_index = [[] for _ in proj.constants.values("species")]

    wild_pokemon.index_wild_pokemon(species_index, symbols, rom, proj, ps, wild_pokemon_table_symbol="wild_pokemon")
    wondertrade.index_wondertrade(species_index, symbols, rom)
    for i, species in enumerate(proj.constants.values("species")):
        for entry in species_index[i]:
            print("Species", pokemon.species_to_name(i, rom, proj, ps, symbols), entry.__dict__)