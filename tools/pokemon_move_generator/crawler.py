#!/usr/bin/env python3

# Module to fetch data from pokewiki.de

import urllib.request
from html.parser import HTMLParser
from bs4 import BeautifulSoup
import re
import argparse
import pickle
import pymap.project
import warnings
import valid_attacks

def parse_html(html, generation=7):
    """ Parses the html of a pokemon. 
    
    Parameters:
    -----------
    html : str
        The html to parse.
    generation : int
        The generation the movesets are based on.

    Returns:
    --------
    pokemon : dict
        The values of the pokemon retrieved from the html.
    """
    # The html of pokewiki unfortunately are not well formatted.
    # Therefore we use *URGH* RegEx to parse an html (never do that, I guess...)
    # Works here though...
    soup = BeautifulSoup(html, "html5lib")
    text = [line.strip() for line in soup.get_text().splitlines() if line.strip()]

    pokemon = {
        'accessible_attacks' : set()
    }

    # Parse levelup attacks
    pokemon['levelup_attacks'] = parse_levelup_attacks(text, generation=generation)
    pokemon['accessible_attacks'].update(tpl[1] for tpl in pokemon['levelup_attacks'])

    # Parse egg attacks
    pokemon['egg_attacks'] = parse_egg_attacks(text, generation=generation)
    pokemon['accessible_attacks'].update(pokemon['egg_attacks'])

    # Parse tutor attacks
    pokemon['accessible_attacks'].update(parse_tutor_attacks(text, generation=generation))

    # Parse tm / hm attacks
    pokemon['accessible_attacks'].update()




def parse_levelup_attacks(text, generation=7):
    """ Parses the html of a pokemon. 
    
    Parameters:
    -----------
    text : list of str
        The non-empty lines of the html.
    generation : int
        The generation the movesets are based on.

    Returns:
    --------
    levelup_attacks : list of tuples
        A list of tuples int, str representing the levelup attacks of this pokemon.
    """
    
    attacks = []

    # Find the 'start tag': 'Durch LevelaufstiegFolgende' and right generation
    for idx in range(len(text)):
        if text[idx].startswith('Durch LevelaufstiegFolgende'): break
    idx = text.index(f'{generation}. Generation', idx)

    # The actual data starts 9 or 8 lines below the tag, depending on the generation
    # Generation <= 3 does not contain the category column.
    idx += 9 if generation > 3 else 8

    while True:
        try:
            if text[idx].startswith("Ent"):
                # This move is obtained at any level up. We fetch it with level
                # set to 1.
                level = 1
            else:
                level = int(text[idx]) 
            attack = parse_attack_string(text[idx + 1])
            attacks.append((level, attack))
        except Exception as e:
            # No more attacks parsable 
            break
        idx += 5

    # Sort the attacks by their level
    return sorted(attacks, key=lambda tpl: tpl[0])

def parse_egg_attacks(text, generation=7):
    """ Parses the egg attacks of an pokemon.. 
    
    Parameters:
    -----------
    text : list of str
        The non-empty lines of the html.
    generation : int
        The generation the movesets are based on.

    Returns:
    --------
    egg_attacks : set of str
        The egg attacks in the html.
    """

    # Find the start tag 'Vererbbarkeit'
    try:
        idx = text.index('Vererbbarkeit')
        idx = text.index(f'{generation}. Generation', idx)
    except:
        return set()

    egg_attacks = set()

    # The actual data starts 11 or 10 lines below the tag, depending on the generation
    # Generation <= 3 does not contain the category column.
    idx += 11 if generation > 3 else 10
    
    while True:
        # Parse egg attacks
        try:
            attack = parse_attack_string(text[idx])
        except:
            break
        egg_attacks.add(attack)
        idx += 5
    
    return egg_attacks


def parse_tutor_attacks(text, generation=7):
    """ Parses the attacks a pokemon can be taught by a tutor. 
    
    Parameters:
    -----------
    text : list of str
        The non-empty lines of the html.
    generation : int
        The generation the movesets are based on.

    Returns:
    --------
    tutor_attacks : set of str
        The tutor attacks in the html.
    """

    # Find the start tag 'Durch Attacken-Lehrer'
    try:
        idx = text.index('Durch Attacken-Lehrer')
        idx = text.index(f'{generation}. Generation', idx)
    except:
        return set()

    tutor_attacks = set()

    # The actual data starts 10 or 9 lines below the tag, depending on the generation
    # Generation <= 3 does not contain the category column.
    idx += 10 if generation > 3 else 9

    while True:
        # Parse all attacks
        try:
            attack = parse_attack_string(text[idx])
        except:
            break
        tutor_attacks.add(attack)
        idx += 5
    
    return tutor_attacks

def parse_tm_hm_attacks(text, generation=7):
    """ Parses the attacks a pokemon can learn via tm or hm. 
    
    Parameters:
    -----------
    text : list of str
        The non-empty lines of the html.
    generation : int
        The generation the movesets are based on.

    Returns:
    --------
    tm_hm_attacks : set of str
        The tm / hm attacks in the html.
    """

    # Find the start tag 'Durch Attacken-Lehrer'
    try:
        idx = text.index('Durch TM/VM')
        idx = text.index(f'{generation}. Generation', idx)
    except:
        return set()

    tm_hm_attacks = set()

    # The actual data starts 9 or 89 lines below the tag, depending on the generation
    # Generation <= 3 does not contain the category column.
    idx += 9 if generation > 3 else 8

    while True:
        # Parse all attacks
        try:
            attack = parse_attack_string(text[idx])
        except:
            break
        tm_hm_attacks.add(attack)
        idx += 5
    
    return tm_hm_attacks


def parse_attack_string(attack):
    """ Parses an attack string of the pokewiki data. Suffixes are removed.
    
    Parameters:
    -----------
    attack : str
        The original attack string to parse
    
    Returns:
    --------
    attack : str
        The parsed attack string.
    """
    for valid_attack in valid_attacks.valid_attacks:
        try: 
            if attack.index(valid_attack) == 0:
                return valid_attack
        except: pass
    raise RuntimeError(f'Could not parse attack {attack}')

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Fetches and preprocesses data for each pokemon from pokewiki.de.')
    parser.add_argument('species', help='The constant value of the species to fetch.')
    parser.add_argument('output', help='The output pickle file containing all pokemon.')
    parser.add_argument('-g', '--generation', type=int, dest='generation', help='The generation the movesets are based on.', default=7)
    args = parser.parse_args()

    # Start fetching urls
    #for species in project.constants['species']:
    species_lowercase = args.species[8:].capitalize()
    # Special cases for certain species
    if species_lowercase == "Ho_oh":
        species_lowercase = "Ho-Oh"
    elif species_lowercase == "Maehikel":
        species_lowercase = "Mähikel"
    elif species_lowercase == "Porygon_z":
        species_lowercase = "Porygon-Z"
    elif species_lowercase == "Sen_long":
        species_lowercase = "Sen-Long"
    # Build url
    try:
        url = f'https://www.pokewiki.de/{species_lowercase}'
        url_split = list(urllib.parse.urlsplit(url))
        url_split[2] = urllib.parse.quote(url_split[2])
        url = urllib.parse.urlunsplit(url_split)
        # print(f'Fetching {url} for species {species_lowercase}')
        html = urllib.request.urlopen(url)
        pokemon = parse_html(html, generation=args.generation)
    except Exception as e:
        warnings.warn(f'Could not fetch {url}: {e}')
        pokemon = None
    
    with open(args.output, 'wb') as f:
        pickle.dump(pokemon, f)


    
    
