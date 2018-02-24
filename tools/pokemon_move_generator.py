""" 
This module uses a webcrawler on pokewiki.de as well as predefined
data sets to create movesets, tm compatibility lists and egg moves
for each pokemon which are up to date with the latest generation
"""
LATEST_GENERATION = 7

import pokemon_crawler.pokemon_crawler as crawler
import constants
import urllib.request
import pprint
import pickle

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


if __name__ == "__main__":
    fetch_data()
    