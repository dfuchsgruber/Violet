from entry import IndexEntry

""" Adds the wondertrade pokemon to the index """

SYMBOL_WONDERTRADE_BRONZE = "wondertrade_pokemon_bronze"
SYMBOL_WONDERTRADE_SILVER = "wondertrade_pokemon_silver"
SYMBOL_WONDERTRADE_GOLD = "wondertrade_pokemon_gold"
SYMBOL_WONDERTRADE_PLATINUM = "wondertrade_pokemon_platinum"
SPECIES_MEW = 151

def index_wondertrade(species_index, symbols, rom):
    """ Adds the wondertrade to the index.
    
    Parameters:
    species_index : A list of lists containing the IndexEntry
                    instances for each species
    symbols : A dict of symbol -> location in rom file
    rom : An agbrom instance to obtain data from
    """
    index_wondertrade_table(species_index, symbols[SYMBOL_WONDERTRADE_BRONZE],
    rom, "Wondertrade", "Bronze", "")
    index_wondertrade_table(species_index, symbols[SYMBOL_WONDERTRADE_SILVER],
    rom, "Wondertrade", "Silver", "")
    index_wondertrade_table(species_index, symbols[SYMBOL_WONDERTRADE_GOLD],
    rom, "Wondertrade", "Gold", "")
    index_wondertrade_table(species_index, symbols[SYMBOL_WONDERTRADE_PLATINUM],
    rom, "Wondertrade", "Platinum", "")
    
    # Add mew
    species_index[SPECIES_MEW].append(IndexEntry(where="Wondertrade", how="Silver",
    comment="Once with 0.390625 % chance"))

def index_wondertrade_table(species_index, offset, rom, where, how, comment):
    """ Adds a list of species to the species index

    Parameters:
    species_index: A list of lists containing the EntryIndex
                    instances for each species
    offset : Offset of a 0xFFFF terminated list of species
    rom : The Agbrom instance to abtain data from
    where : Where field of the EnryIndex
    how : How field of the EntryIndex
    comment : Comment field of the EntryIndex
    """
    while True:
        species = rom.u16(offset)
        if species == 0xFFFF: return
        entry = IndexEntry(where=where, how=how, comment=comment)
        species_index[species].append(entry)
        offset += 2