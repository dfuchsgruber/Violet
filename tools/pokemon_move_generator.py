""" 
This module uses a webcrawler on pokewiki.de as well as predefined
data sets to create movesets, tm compatibility lists and egg moves
for each pokemon which are up to date with the latest generation
"""
LATEST_GENERATION = 7

import pokemon_crawler.pokemon_crawler as crawler
from pokemon_crawler.pokemon_crawler import Pokemon
import constants
import agb
import urllib.request
import pprint
import pickle
import os.path
import pokemon_crawler.link as link
import pokemon_crawler.normalize as normalize
import pokemon_crawler.export as export

def fetch_data(generation=LATEST_GENERATION, output="./pokemon_crawler/"):
    for i, species in enumerate(constants.species_table):
        #for i, species in ((21, 'POKEMON_Mähikel'), (250, 'POKEMON_Ho-Oh')):
        #for old, new in (("ae", "ä"), ("ue", "ü"), ("oe", "ö"), ("AE", "Ä"), ("OE", "Ö"), ("UE", "Ü")):
        #    species = species.replace(old, new)
        species = species[8:].capitalize()
        if species == "Ho_oh": species = "Ho-Oh"
        elif species == "Maehikel": species = "Mähikel"
        try:
            url = 'https://www.pokewiki.de/' + species
            split_url = list(urllib.parse.urlsplit(url))
            split_url[2] = urllib.parse.quote(split_url[2])
            url = urllib.parse.urlunsplit(split_url)
            print("Fetching", url, "for species", i, "...")
            html = urllib.request.urlopen(url)
        except Exception as e:
            print(e)
            continue
        output = "./pokemon_crawler/"
        pkmn = crawler.parse_html(html, gen=7)
        if pkmn:
            output_file = output + str(i).zfill(3) + ".pkl"
            f = open(output_file, "wb")
            pickle.dump(pkmn, f)
            f.close()
            """
            print("lvlup")
            pprint.pprint(pkmn.attacks_lvlup)
            print("egg")
            pprint.pprint(pkmn.attacks_breed)
            print("tutor")
            pprint.pprint(pkmn.attacks_tutor)
            print("tm")
            pprint.pprint(pkmn.attacks_tm)
            """

def load_data(input="./pokemon_crawler/"):
    pkmns = []
    for i, species in enumerate(constants.species_table):
        path = input + str(i).zfill(3) + ".pkl"
        if os.path.exists(path):
            fp = open(path, "rb")
            pkmns.append(pickle.load(fp))
            fp.close()
        else:
            pkmns.append(None)
    return pkmns


if __name__ == "__main__":
    

    pkmns = load_data()
    linked = link.update_and_link(pkmns, constants)
    export.export_lvlup_attacks(linked, "../src/pokemon/pokemon_moves.c", constants)
    built_violet = agb.Agbrom(path="../bld/Pokemon Violet.gba")
    offset_evolution_table = built_violet.pointer(0x42e6c)
    export.export_egg_moves(linked, "../src/pokemon/breeding/egg_moves.c", constants, built_violet, offset_evolution_table)
    export.export_tm_move_compatibility(linked, "../src/pokemon/hm_compatibility.c", constants)
    export.export_move_tutor_compatibility(linked, "../src/pokemon/move_tutor/move_tutor_compatibility.c", constants)
    export.export_inaccessible_attacks(linked, "../src/pokemon/inaccessible_moves.c", constants)
    #pprint.pprint(normalize.not_in_moveset_base)
