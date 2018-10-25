#!/usr/bin/env python3
""" 
Webcrawler to fetch data from pokewiki.de and store
results in python pickles
"""

LATEST_GENERATION = 7

import sys, getopt, os
import pokemon_move_generator.pokemon_crawler as crawler
from pokemon_move_generator.pokemon_crawler import Pokemon
import urllib.request
import pprint
import pickle
import os.path
from pymap import project


def fetch_data(output_file, consts):
    """ Fetches data from pokewiki and caches it as python pickles"""
    pkmns = {}
    for i, species in enumerate(consts['species']):
        i = consts['species'][species]
        #for i, species in ((21, 'POKEMON_Mähikel'), (250, 'POKEMON_Ho-Oh')):
        #for old, new in (("ae", "ä"), ("ue", "ü"), ("oe", "ö"), ("AE", "Ä"), ("OE", "Ö"), ("UE", "Ü")):
        #    species = species.replace(old, new)
        species = species[8:].capitalize()
        if species == "Ho_oh": species = "Ho-Oh"
        elif species == "Maehikel": species = "Mähikel"
        elif species == "Porygon_z": species = "Porygon-Z"
        elif species == "Sen_long": species = "Sen-Long"
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
        pkmn = crawler.parse_html(html, gen=LATEST_GENERATION)
        pkmns[i] = pkmn
    
    with open(output_file, "wb") as f:
        pickle.dump(pkmns, f)
        
if __name__ == "__main__":
    argv = sys.argv[1:]
    try:
        opts, args = getopt.getopt(argv, "h", ["help"])
    except getopt.GetoptError:
        print("opterr")
        sys.exit(2)

    #Parse the options
    for opt, arg in opts:
        if opt in ("-h", "--help"):
            print("Usage ./fetch.py directory project\nStores pickles inside directory.")
            exit()

    proj = project.Project(args[1])


    fetch_data(args[0], proj.constants)
