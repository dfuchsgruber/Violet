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

def parse_html(text, generation=7):
    """ Parses the html of a pokemon. 
    
    Parameters:
    -----------
    text : list of str
        The non-empty lines of the html.
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

    
    with open('test.txt', 'w+') as f:
        f.write('\n'.join(text))


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

    # Parse basestats
    pokemon['basestats'] = parse_basestats(text)
    pokemon['ev_yield'] = parse_ev_yield(text)

    # Parse abilities
    pokemon['abilities'], pokemon['hidden_ability'] = parse_abilities(text)

    # Parse catch rate, base friendship
    pokemon['catch_rate'] = int(text[text.index('Fangrate') + 1].split(' ')[0])
    pokemon['base_friendship'] = int(text[text.index('Start-Freundschaft')+ 1])
    pokemon['gender'] = text[text.index('Geschlecht') + 1]
    pokemon['egg_groups'] = parse_egg_groups(text)
    pokemon['egg_cycles'] = parse_egg_cycles(text)
    pokemon['exp_type'] = text[text.index('EP bis Lv. 100') + 1]
    pokemon['category'] = text[text.index('Kategorie') + 1]
    pokemon['height'] = float(text[text.index('Größe') + 1].split(' ')[0].replace(',', '.'))
    pokemon['weight'] = float(text[text.index('Gewicht') + 1].split(' ')[0].replace(',', '.'))
    pokemon['dex_entry'] = parse_dex_entry(text)
    
    # A lot of data can not be crawled
    pokemon['types'] = [None, None]
    pokemon['exp_yield'] = None
    pokemon['safari'] = None
    pokemon['flip_and_color'] = None
    pokemon['items'] = [None, None] # Parsing items is a pain, we use our post-linking system to fix this
    pokemon['form'] = None

def parse_egg_cycles(text):
    """ Parses the egg cycles of a pokemon.
    
    Parameters:
    -----------
    text : list of str
        The non-empty lines of the html.

    Returns:
    --------
    egg_cycles : int
        The egg cycles of this pokemon.
    """
    egg_cylces_text = text[text.index('Ei-Zyklen') + 1]
    if egg_cylces_text == 'unbekannt':
        return 1
    return int(egg_cylces_text)

def parse_dex_entry(text, games=('X', 'XY')):
    """ Parses the dex entry of a pokemon.
    
    Parameters:
    -----------
    text : list of str
        The non-empty lines of the html.
    games : iterable of strings
        The abbreviations for the game of which the text to obtain from
        in decreasing order.
        Default: ('X', 'XY') for Pokémon X.

    Returns:
    --------
    egg_groups : list of str
        The egg groups of a pokemon.
    """
    idx = text.index('Pokédex-Einträge')
    for game in games:
        try:
            idx = text.index(game, idx) + 1
            break
        except:
            continue
    return text[idx]


def parse_egg_groups(text):
    """ Parses the egg group(s) of a pokemon.
    
    Parameters:
    -----------
    text : list of str
        The non-empty lines of the html.

    Returns:
    --------
    egg_groups : list of str
        The egg groups of a pokemon.
    """
    if 'Ei-Gruppe' in text:
        # Only one egg group
        egg_group = text[text.index('Ei-Gruppe') + 1]
        return [egg_group, egg_group]
    elif 'Ei-Gruppen' in text:
        # Two egg groups
        return text[text.index('Ei-Gruppen') + 1].split(', ')




def parse_abilities(text):
    """ Parses the abilities attacks of a pokemon. 
    
    Parameters:
    -----------
    text : list of str
        The non-empty lines of the html.

    Returns:
    --------
    abilities, hidden_ability : list, str or None
        Dict mapping from basestat names to their values.
    """
    hidden_ability = None
    try:
        idx = text.index('Fähigkeiten') + 1
    except:
        # If the pokemon only has one ability the stirng is truncated
        idx = text.index('Fähigkeit') + 1
    sections = text[idx].split('  ')
    if len(sections) > 1:
        # Section[1] contains hidden abilitiy and mega ability
        subsections = sections[1].split(' ')
        for ability, ability_type in zip(subsections[0::2], subsections[1::2]):
            if ability_type == '(VF)':
                hidden_ability = ability
                break
    
    abilities = sections[0].split(' ')
    if len(abilities) == 1:
        abilities.append(None)
    
    return abilities, hidden_ability
    



def parse_basestats(text):
    """ Parses the basestats attacks of a pokemon. 
    
    Parameters:
    -----------
    text : list of str
        The non-empty lines of the html.

    Returns:
    --------
    basestats : dict
        Dict mapping from basestat names to their values.
    """
    basestats = {}

    # Find the start tag 'Basiswerte'
    idx = text.index('Basiswerte') + 10
    for idx in range(idx, idx + 6 * 9, 9):
        basestats[text[idx]] = int(text[idx + 2])
    return basestats

def parse_ev_yield(text):
    """ Parses the basestats ev yield of a pokemon. 
    
    Parameters:
    -----------
    text : list of str
        The non-empty lines of the html.

    Returns:
    --------
    ev_yield : dict
        Dict mapping from basestat names to their values.
    """
    ev_yield = {}

    # Find the start tag 'Basiswerte'
    idx = text.index('Basiswerte') + 10
    for idx in range(idx, idx + 6 * 9, 9):
        ev_yield_text = text[idx + 1]
        # Some Pokémon had their ev yield changed
        if '*' in ev_yield_text:
            ev_yield_text = ev_yield_text[:ev_yield_text.index('*')]
        ev_yield[text[idx]] = int(ev_yield_text)
    return ev_yield

def parse_levelup_attacks(text, generation=7):
    """ Parses the levelup attacks of a pokemon. 
    
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

    # Appearantly pokewiki now holds sites /{number}.html for each entry...
    # Thus all POKEMON_{number} paddings have to be ignored by force
    try:
        int(species_lowercase, 0)
        species_lowercase = f'not_dex_{species_lowercase}'
    except:
        pass

    # Build url
    try:
        url = f'https://www.pokewiki.de/{species_lowercase}'
        url_split = list(urllib.parse.urlsplit(url))
        url_split[2] = urllib.parse.quote(url_split[2])
        url = urllib.parse.urlunsplit(url_split)
        # print(f'Fetching {url} for species {species_lowercase}')
        html = urllib.request.urlopen(url)
        soup = BeautifulSoup(html, "html5lib")
        text = [line.strip() for line in soup.get_text().splitlines() if line.strip()]
    except Exception as e:
        warnings.warn(f'Could not fetch {url}: {e}')
        # Dump None
        with open(args.output, 'wb') as f:
            pickle.dump(None, f)
        exit(0)

    pokemon = parse_html(text, generation=args.generation)
    with open(args.output, 'wb') as f:
        pickle.dump(pokemon, f)


    
    
