# Python file to create an index of all availible items and species
# This is used to keep track of which elements need to be included
# yet to the game

import pymap.project as project
import pymap.config as config
import pymap.mapheader as mapheader
import pymap.mapevent as mapevent
import constants
import os
import re

# Define an index for items that are not found or buyable
item_index = dict((item, []) for item in constants.item_table)

# Define an index for each hidden chunk and flag
hidden_index = {
    0 : dict((i, []) for i in range(256)),
    1 : dict((i, []) for i in range(256)),
    2 : dict((i, []) for i in range(256)),
    3 : dict((i, []) for i in range(256))
}

# Define an index for pokemon that are not wild pokemon
poke_index = dict((species, []) for species in constants.species_table)
poke_index["POKEMON_BISASAM"].append("STARTER")
poke_index["POKEMON_GLUMANDA"].append("STARTER")
poke_index["POKEMON_SCHIGGY"].append("STARTER")
poke_index["POKEMON_LOCKSCHAL"].append("STARTER")
poke_index["POKEMON_WELUNO"].append("STARTER")
poke_index["POKEMON_SEEKID"].append("STARTER")

poke_wondertrade_bronze = (
    "POKEMON_DARTIRI", "POKEMON_HORNLIU", "POKEMON_STARALILI", "POKEMON_SANDAN",
    "POKEMON_NIDORANM", "POKEMON_NIDORANW", "POKEMON_PUMMELUFF", "POKEMON_ZUBAT",
    "POKEMON_MYRAPLA", "POKEMON_DIGDA", "POKEMON_ENTON", "POKEMON_MAGNETILO",
    "POKEMON_TRAUMATO", "POKEMON_LEDYBA", "POKEMON_WEBARAK", "POKEMON_FLABEBE",
    "POKEMON_NATU", "POKEMON_SNUBBULL", "POKEMON_TEDDIURSA", "POKEMON_SCHNECKMAG",
    "POKEMON_FIFFYEN", "POKEMON_ZIGZACHS", "POKEMON_WAUMPEL", "POKEMON_LOTURZEL",
    "POKEMON_SAMURZEL", "POKEMON_FRIZELBLIZ", "POKEMON_MEDITIE", "POKEMON_SCHLUPPUCK",
    "POKEMON_ENECO", "POKEMON_LAMPI", "POKEMON_OWEI"
)

poke_wondertrade_silver = (
    "POKEMON_PIKACHU", "POKEMON_VULPIX", "POKEMON_KASTADUR", "POKEMON_FUKANO",
    "POKEMON_ABRA", "POKEMON_PORENTA", "POKEMON_SLEIMA", "POKEMON_SMOGON",
    "POKEMON_NEBULAK", "POKEMON_SEEPER", "POKEMON_MAGBY", "POKEMON_TRAGOSSO",
    "POKEMON_ELEKID", "POKEMON_MARILL", "POKEMON_GRIFFEL",
    "POKEMON_SHNEBEDECK", "POKEMON_NASGNET", "POKEMON_WABLU",
    "POKEMON_STOLLUNIOR", "POKEMON_STERNDU"
)

poke_wondertrade_gold = (
    "POKEMON_BISASAM", "POKEMON_GLUMANDA", "POKEMON_SCHIGGY",
    "POKEMON_TOGEPI", "POKEMON_CLAVION",
    "POKEMON_PANZAERON",
    "POKEMON_KECLEON"
)

poke_wondertrade_platinum = (
    "POKEMON_CHANEIRA", "POKEMON_IGNIVOR", "POKEMON_EVOLI", "POKEMON_LAPRAS",
    "POKEMON_BARSCHWA", "POKEMON_ABSOL", "POKEMON_SICHLOR"
)

for species in poke_wondertrade_bronze:
    poke_index[species].append("WONDERTRADE(BRONZE)")

for species in poke_wondertrade_silver:
    poke_index[species].append("WONDERTRADE(SILVER)")
    
for species in poke_wondertrade_gold:
    poke_index[species].append("WONDERTRADE(GOLD)")
    
for species in poke_wondertrade_platinum:
    poke_index[species].append("WONDERTRADE(PLATINUM)")

root = "../map"
proj = project.Project.load_project(config.STDPROJ)


def index(out_item_index, out_poke_index, out_hidden_index):
    """
    Creates index files for items and pokemon by iterating
    over all children files of root recursivly. It provides
    output files out_item_index, out_poke_index
    """
    print("Creating index files...")
    for dir, _, files in os.walk(root):
        for file in files:#
            if file.endswith(".asm"):
                path = dir + os.sep + file
                # Extract the bank, map and namespace
                bank, mapid, ns = namespace(dir)
                fp = open(path, "r")
                content = fp.read()
                fp.close()
                if file == "wild_pokemon.asm":
                    index_poke(content, poke_index, bank, mapid, ns)
                index_item_by_giveitem(content, item_index, bank, mapid, ns)
            elif file.endswith(".pmh"):
                path = dir + os.sep + file
                # Load the pmh mapheader file
                bank, mapid, ns = namespace(dir)
                header = mapheader.load(path, proj, instanciate_ts=False)
                index_item_by_hidden_items(header, item_index, bank, mapid, ns)
                index_hidden(header, hidden_index, bank, mapid, ns)

    output = ""
    for species in constants.species_table:
        output += species + ":\n"
        for location in poke_index[species]:
            output += "\t\t" + location + "\n"
    fp = open(out_poke_index, "w+")
    fp.write(output)
    fp.close()
    output = ""
    for item in constants.item_table:
        output += item + ":\n"
        for location in item_index[item]:
            output += "\t\t" + location + "\n"
    fp = open(out_item_index, "w+")
    fp.write(output)
    fp.close()
    output = ""
    for chunk in hidden_index:
        output += "Chunk " + str(chunk) + ":\n"
        for flag in hidden_index[chunk]:
            output += "\t\t" + str(flag) + " : " + ", ".join(hidden_index[chunk][flag]) + "\n"
    fp = open(out_hidden_index, "w+")
    fp.write(output)
    fp.close()


    

def namespace(dir):
    """
    Retrieves bank, map and namespace of a directory.
    :return bank, mapid, namespace
    """
    dirs = dir.split(os.sep)
    try:
        mapid = int(dirs[2])
        bank = int(dirs[1])
        _, _, ns, _ = proj.banks[bank][mapid]
        return bank, mapid, ns
    except:
        raise Exception("Can not retrieve bank, map and namespace from " + dir)

def index_hidden(header: mapheader, hidden_index, bank, mapid, ns):
    """
    Scans the map for hidden items and adds used flags to the respective chunks
    """
    for sign in header.signposts:
        if sign.type == mapevent.MAPEVENT_SIGN and sign.structure == mapevent.SIGN_STRUCTURE_ITEM:
            item_id = sign.item_id
            flag = int(sign.hidden)
            count = eval(str(sign.count))
            # Count actually consists of <1-Bit decector disable><2-Bit hidden chunk><5-Bit count>
            chunk = (count >> 5) & 3
            location =  ns + "(" + str(bank) + "." + str(mapid) + ", " + str(flag) + ")"
            hidden_index[chunk][flag].append(item_id + "@" + location)


def index_poke(content, poke_index, bank, mapid, ns):
    """
    Adds pokemon listet in content to poke_index. The process
    is fairly simple: For each string in constants.species_table
    it checks weather the string is containted in content and if
    true adds the current map to the index. It must be ensured
    that content really holds a wild pokemon file.
    """
    location = ns + "(" + str(bank) + "." + str(mapid) + ")"

    for species in poke_index:
        if species in content:
            poke_index[species].append(location)


def index_item_by_giveitem(content, item_index, bank, mapid, ns):
    """
    Adds items listet in content to item_index. It only scans
    the content for items that are included in a copyvarifnotzero
    directive as used in giveitem macros.
    """
    regex = """copyvarifnotzero\s0x8000\s(.*)"""
    location = ns + "(" + str(bank) + "." + str(mapid) + ")"
    for match in re.findall(regex, content):
        item_index[match].append(location)

def index_item_by_hidden_items(header: mapheader, item_index, bank, mapid, ns):
    """
    Adds items that are hidden on the map given by header.
    """
    for sign in header.signposts:
        if sign.type == mapevent.MAPEVENT_SIGN and sign.structure == mapevent.SIGN_STRUCTURE_ITEM:
            item_id = sign.item_id
            if item_id not in item_index:
                print("Warning. Hidden item", item_id, "not specified and thus could not be listed")
            else:
                flag = sign.hidden
                count = eval(str(sign.count))
                # Count actually consists of <1-Bit decector disable><2-Bit hidden chunk><5-Bit count>
                chunk = (count >> 5) & 3
                if chunk == 0:
                    location =  ns + "(" + str(bank) + "." + str(mapid) + ", hidden@" + str(flag) + ")"
                    item_index[item_id].append(location)

if __name__ == "__main__":
    index("../index/items.txt", "../index/poke.txt", "../index/hidden.txt")
