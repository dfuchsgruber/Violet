
import urllib.request
from html.parser import HTMLParser
from bs4 import BeautifulSoup
import re

# First create a list of all moves valid
move_file = "./pokemon_crawler/pokemon_crawler_all_moves.txt"
lines = open(move_file, "r", encoding="utf-8").read().split("\n")
moves = set(lines)

class Pokemon:
    
    def __init__(self):
        """ Represents a pokemon with all relevant fetched data """
        self.attacks_lvlup = []
        self.attacks_breed = set()
        self.availible_attacks = set()
        self.attacks_tutor = set()
        self.attacks_tm = []

    def __str__(self):
        return str(self.__dict__)
    

class Lvlup_attack_parser(HTMLParser):
    
    def __init__(self, generation=7):
        """ Parses a pokewiki pokemon html and tries to extract the lvlups from a generation """
        super().__init__()
        self.generation = 7

    def handle_startag(self, tag, attrs):
        print(tag)
        if tag == 'a':
            print(tag, attrs)

    def handle_data(self, data):
        pass
    
    def handle_endtag(self, tag):
        pass

def plog(x):
    open("log.txt", "w+", encoding="utf-8").write(str(x))

def is_attack(s):
    """ Checks if a string corresponds to a attack."""
    return s in moves

def parse_attack_string(s):
    """ Parses the ill-formated strings of Pokewiki, i.e removes
    the special characters suffixes"""
    for move in moves:
        try: 
            if s.index(move) == 0: return move
        except: pass
    return "invalid attack : " + s

def parse_html(html, gen=7, tutor_attack_generations=range(1, 8)):
    """ Creates a pokemon based on a html and returns """

    if not html: return None
    soup = BeautifulSoup(html, "html5lib")
    text = soup.get_text()
    # As the document is not well formated (no tree-like structuring)
    # simply parse the plain text
    
    # First remove empty lines and strip for easier parsing
    lines = [l.strip() for l in text.splitlines() if l.strip()]

    pkmn = Pokemon()

    # Get lvlup attacks
    pkmn.attacks_lvlup = get_lvlup_attacks(lines, gen)
    for _, attack in pkmn.attacks_lvlup:
        pkmn.availible_attacks.add(attack)

    # Get egg attacks
    pkmn.attacks_breed = get_egg_attacks(lines, gen)
    pkmn.availible_attacks.update(pkmn.attacks_breed)

    # Get tutor attacks
    for _gen in tutor_attack_generations:
        tutor_attacks = get_tutor_attacks(lines, _gen)
        pkmn.attacks_tutor.update(tutor_attacks)
    
    # Get the tms
    pkmn.attacks_tm = get_tm_attacks(lines, 3)
    for _, attack in pkmn.attacks_tm:
        pkmn.availible_attacks.add(attack)

    pkmn.availible_attacks.update(pkmn.attacks_tutor)



    return pkmn

def get_tm_attacks(lines, generation):
    """ Parses the html lines and returns a
    list of attacks to be obtained by tms/hms
    in one generation.
    """

    # First find the start tag 'Durch TM/VM'
    try:
        index = lines.index('Durch TM/VM')
        index = lines.index(str(generation) + '. Generation', index)
    except: return set()

    tms = []

    # The first attack starts 9 (or 8 if the header
    # does not contain 'Kat.' as in generations
    # <= 3) lines below the start tag
    index += 9 if generation > 3 else 8

    while True:
        # Parse all attacks
        try: int(lines[index][2:])
        except: break
        attack = parse_attack_string(lines[index + 1])
        if not is_attack(attack): break
        tms.append((lines[index], attack))
        index += 5
    
    return tms

def get_tutor_attacks(lines, generation=7):
    """ Parses the html lines and returns a
    list of attacks to be obtained by attack tutors
    in one generation.
    """

    # First find the start tag 'Durch Attacken-Lehrer'
    try:
        index = lines.index('Durch Attacken-Lehrer')
        index = lines.index(str(generation) + '. Generation', index)
    except: return set()

    tutor_attacks = set()

    # The first attack starts 10 (or 9 if the header
    # does not contain 'Kat.' as in generations
    # <= 3) lines below the start tag
    index += 10 if generation > 3 else 9

    while True:
        # Parse all attacks
        attack = parse_attack_string(lines[index])
        if not is_attack(attack): break
        tutor_attacks.add(attack)
        index += 5
    
    return tutor_attacks


def get_egg_attacks(lines, generation=7):
    """ Parses the html and returns a list of
    attacks to be obtained by breeding."""
    
    # First find the start tag 'Vererbbarkeit'
    try:
        index = lines.index('Vererbbarkeit')
        index = lines.index(str(generation) + '. Generation', index)
    except: return set()

    egg_attacks = set()

    # The first attack starts 11 (or 10 if the header
    # does not contain 'Kat.' as in generations
    # <= 3) lines below the start tag
    index += 11 if generation > 3 else 10
    
    while True:
        # Parse all attacks
        attack = parse_attack_string(lines[index])
        if not is_attack(attack): break
        egg_attacks.add(attack)
        index += 5
    
    return egg_attacks


def get_lvlup_attacks(lines, generation=7):
    """ Parses the html lines and returns a list of tuples 
    (lvl : int, attack : string) representing the
    attacks availible by leveling up in one generation. """

    attacks_lvlup = []

    # Find the taglike instance 'Durch LevelaufstiegFolgende Attacken'
    index = 0
    while index < len(lines):
        if lines[index].startswith('Durch LevelaufstiegFolgende'):
            break
        index += 1

    if index >= len(lines): return attacks_lvlup

    # Find the generation taglike instance
    try:
        index = lines.index(str(generation) + '. Generation', index)
    except: return attacks_lvlup
    
    if index >= len(lines): return attacks_lvlup

    # The first attack starts 9 (or 8 if the header
    # does not contain 'Kat.' as in generations
    # <= 3) lines below the start tag
    index += 9 if generation > 3 else 8

    while True:
        # Parse all attacks
        try:
            lvl = int(lines[index]) 
            attack = parse_attack_string(lines[index + 1])
            if not is_attack(attack): raise Exception()
            attacks_lvlup.append((lvl, attack))
        except Exception as e: 
            break
        index += 5

    return attacks_lvlup


def get_htmls(urls):
    """
    Returns a list of htmls from a list of urls
    """
    htmls = []
    for url in urls:
        print('Fetching', url, '...')
        try:
            htmls.append()
        except Exception as e:
            print(e)
            htmls.append(None)
    return htmls


