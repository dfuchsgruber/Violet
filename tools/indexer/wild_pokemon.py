from agb import agbrom
from entry import IndexEntry
import map_namespace

""" Adds wild pokemon to the index """

WILD_POKEMON = "wild_pokemon"
WILD_POKEMON_GRASS_PDF = "wild_pokemon_grass_pdf"
WILD_POKEMON_WATER_PDF = "wild_pokemon_water_pdf"
WILD_POKEMON_OTHER_PDF = "wild_pokemon_other_pdf"
WILD_POKEMON_ROD_PDF = "wild_pokemon_rod_pdf"
WILD_POKEMON_GOOD_ROD_PDF = "wild_pokemon_good_rod_pdf"
WILD_POKEMON_SUPER_ROD_PDF = "wild_pokemon_super_rod_pdf"

def index_wild_pokemon(species_index, symbols, rom, proj, ps, wild_pokemon_table_symbol="wild_pokemon"):
    """ Adds the wild pokemon to the index of species
    Parameters:
    species_index : A list of lists containing the IndexEntry
                    instances for each species
    symbols : A dict of symbol -> location in rom file
    rom : An agbrom instance to obtain data from 
    proj : A pymap project (needed for retrieving namespaces)
    ps : A Pstring instance for parsing hex to string 
    wild_pokemon_table_symbol : symbol that refers to the wild pokemon table"""

    offset = symbols[wild_pokemon_table_symbol]

    while True:
        bank = rom.u8(offset)
        if bank == 0xFF: break
        map = rom.u8(offset + 1)
        grass = rom.nullable_pointer(offset + 4)
        water = rom.nullable_pointer(offset + 8)
        other = rom.nullable_pointer(offset + 12)
        rod = rom.nullable_pointer(offset + 16)
        offset += 20
        namespace = proj.banks[bank][map][2]
        if grass:
            index_habitat_grass(bank, map, namespace, species_index, symbols, rom, proj, ps, grass)
        if water:
            index_habitat_water(bank, map, namespace, species_index, symbols, rom, proj, ps, water)
        if other:
            index_habitat_other(bank, map, namespace, species_index, symbols, rom, proj, ps, other)
        if rod:
            index_habitat_rod(bank, map, namespace, species_index, symbols, rom, proj, ps, rod)


def index_habitat_grass(bank, map, namespace, species_index, symbols, rom, proj, ps, offset):
    """ Adds wild pokemon to the index of species for grass habitats
    Parameters:
    bank : the map bank
    map : the map id
    species_index : A list of lists containing the IndexEntry
                    instances for each species
    symbols : A dict of symbol -> location in rom file
    rom : An agbrom instance to obtain data from
    proj : The pymap project
    ps : A Pstring instance to parse hex to string
    offset : offset of the grass habitat """
    frequency = rom.u8(offset)
    if not frequency: return # No pokemon appear
    entries = rom.pointer(offset + 4)
    num_entries = 12
    pdf_offset = symbols[WILD_POKEMON_GRASS_PDF]
    habitat = habitat_get_with_pdf(rom, entries, num_entries, pdf_offset)
    where = "{0} @ {1}.{2}".format(map_namespace.map_namespace_to_string(namespace, rom, proj, ps, symbols), bank, map)
    index_add_habitat(species_index, habitat, where, "Nature")
    
def index_habitat_water(bank, map, namespace, species_index, symbols, rom, proj, ps, offset):
    """ Adds wild pokemon to the index of species for water habitats
    Parameters:
    bank : the map bank
    map : the map id
    species_index : A list of lists containing the IndexEntry
                    instances for each species
    symbols : A dict of symbol -> location in rom file
    rom : An agbrom instance to obtain data from
    proj : The pymap project
    ps : A Pstring instance to parse hex to string
    offset : offset of the grass habitat """
    frequency = rom.u8(offset)
    if not frequency: return # No pokemon appear
    entries = rom.pointer(offset + 4)
    num_entries = 5
    pdf_offset = symbols[WILD_POKEMON_WATER_PDF]
    habitat = habitat_get_with_pdf(rom, entries, num_entries, pdf_offset)
    where = "{0} @ {1}.{2}".format(map_namespace.map_namespace_to_string(namespace, rom, proj, ps, symbols), bank, map)
    index_add_habitat(species_index, habitat, where, "Water")

def index_habitat_other(bank, map, namespace, species_index, symbols, rom, proj, ps, offset):
    """ Adds wild pokemon to the index of species for other habitats
    Parameters:
    bank : the map bank
    map : the map id
    species_index : A list of lists containing the IndexEntry
                    instances for each species
    symbols : A dict of symbol -> location in rom file
    rom : An agbrom instance to obtain data from
    proj : The pymap project
    ps : A Pstring instance to parse hex to string
    offset : offset of the grass habitat """
    frequency = rom.u8(offset)
    if not frequency: return # No pokemon appear
    entries = rom.pointer(offset + 4)
    num_entries = 5
    pdf_offset = symbols[WILD_POKEMON_OTHER_PDF]
    habitat = habitat_get_with_pdf(rom, entries, num_entries, pdf_offset)
    where = "{0} @ {1}.{2}".format(map_namespace.map_namespace_to_string(namespace, rom, proj, ps, symbols), bank, map)
    index_add_habitat(species_index, habitat, where, "Radar")

def index_habitat_rod(bank, map, namespace, species_index, symbols, rom, proj, ps, offset):
    """ Adds wild pokemon to the index of species for rod habitats
    Parameters:
    bank : the map bank
    map : the map id
    species_index : A list of lists containing the IndexEntry
                    instances for each species
    symbols : A dict of symbol -> location in rom file
    rom : An agbrom instance to obtain data from
    proj : The pymap project
    ps : A Pstring instance to parse hex to string
    offset : offset of the grass habitat """
    frequency = rom.u8(offset)
    if not frequency: return # No pokemon appear
    entries_rod = rom.pointer(offset + 4)
    where = "{0} @ {1}.{2}".format(map_namespace.map_namespace_to_string(namespace, rom, proj, ps, symbols), bank, map)
    num_entries_rod = 2
    pdf_offset_rod = symbols[WILD_POKEMON_ROD_PDF]
    entries_good_rod = entries_rod + 4 * num_entries_rod
    num_entries_good_rod = 3
    pdf_offset_good_rod = symbols[WILD_POKEMON_GOOD_ROD_PDF]
    entries_super_rod = entries_good_rod + 4 * num_entries_good_rod
    num_entries_super_rod = 5
    pdf_offset_super_rod = symbols[WILD_POKEMON_SUPER_ROD_PDF]

    habitat_rod = habitat_get_with_pdf(rom, entries_rod, num_entries_rod, pdf_offset_rod)
    index_add_habitat(species_index, habitat_rod, where, "Rod")
    habitat_good_rod = habitat_get_with_pdf(rom, entries_good_rod, num_entries_good_rod, pdf_offset_good_rod)
    index_add_habitat(species_index, habitat_good_rod, where, "Good Rod")
    habitat_super_rod = habitat_get_with_pdf(rom, entries_super_rod, num_entries_super_rod, pdf_offset_super_rod)
    index_add_habitat(species_index, habitat_super_rod, where, "Super Rod")

def index_add_habitat(species_index, habitat, where, how):
    """ Adds all entries of a habitat to the species_index
    
    Parameters:
    species_index : A list containing the EntryIndex instances
                    for each species
    habitat : A dict of species_idx -> [probability, level_min, level_max]
    where : A string describing the 'where' field of the EntryIndex
    how : A string describing the 'how' field of the EntryIndex
    """
    for species in habitat:
        p, level_min, level_max = habitat[species]
        comment = "Level {0}-{1}, {2}%".format(level_min, level_max, p)
        entry = IndexEntry(where=where, how=how, comment=comment)
        species_index[species].append(entry)

def habitat_get_with_pdf(rom, entries_offset, num_entries, pdf_offset):
    """ Returns the species that can appear in a habitat
    Parameters:
    rom : the rom file
    entries_offset : Offset of the entry array
    num_entries : Size of entry array
    pdf_offset : Offset of the pdf array 

    Returns:
    A dict : species -> [probabilty, level_min, level_max]"""
    habitat = {}
    for i in range(num_entries):
        p = rom.u8(pdf_offset + i)
        offset = entries_offset + 4 * i
        level_min = rom.u8(offset)
        level_max = rom.u8(offset + 1)
        species = rom.u16(offset + 2)
        if species not in habitat:
            habitat[species] = [p, level_min, level_max]
        else:
            habitat[species][0] += p
            habitat[species][1] = min(habitat[species][1], level_min)
            habitat[species][2] = max(habitat[species][2], level_max)
    
    return habitat



