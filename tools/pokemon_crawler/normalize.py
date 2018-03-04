"""
This module normalizes a pokemon dataset
obtained by the crawler, i.e. removes
all moves that are not in the moveset base
"""


not_in_moveset_base = set()

def normalize_attack_string(attack):
    """ Normalizes an attack string by first replacing
    all 'Sonderzeichen's with proper ascii chars and
    also every '-' with an underscore. Furthermore
    the prefix 'ATTACK_' as added and the string is
    put in capital letters."""
    for old, new in (("ä", "ae"), ("Ä", "AE"), ("ö", "oe"),
    ("Ö", "OE"), ("ü", "ue"), ("Ü", "UE"), ("-", "_"), (" ", "_")):
        attack = attack.replace(old, new)
    return "ATTACK_" + attack.upper()

def normalize_lvlup_attacks(lvlup_attacks, constants):
    """ Normalizes a list of tuples lvl, attack
    and replaces all attack strings with their respective
    constants from the moveset base. If a move can not be matched
    the move will be added to a set that stores all moves
    that were found in movesets but not in the moveset base."""
    normalized = []
    for lvl, attack in lvlup_attacks:
        # Normalize the attack and check if it is
        # part of the moveset base
        normalized_attack = normalize_attack_string(attack)
        if normalized_attack in constants.attack_table:
            normalized.append((lvl, normalized_attack))
        else:
            not_in_moveset_base.add(str((normalized_attack, attack)))
            #print("'" + attack + "' not in moveset base.")
    return normalized


def normalize_attack_set(attacks, constants):
    """ Normalizes a set of attacks and replaces 
    all attack strings with their respective
    constants from the moveset base. If a move can not be matched
    the move will be added to a set that stores all moves
    that were found in movesets but not in the moveset base."""
    normalized = set()
    for attack in attacks:
        # Normalize the attack and check if it is
        # part of the moveset base
        normalized_attack = normalize_attack_string(attack)
        if normalized_attack in constants.attack_table:
            normalized.add(normalized_attack)
        else:
            not_in_moveset_base.add(str((normalized_attack, attack)))
            #print("'" + attack + "' not in moveset base.")
    return normalized

def normalize_tutor_attacks(tutor_attacks, constants):
    """ Normalizes a dict of tuples index -> attack
    and replaces all attack strings with their respective
    constant from the moveset base. If a move can not be matched
    the move will be added to a set that store all moves
    that were found in movesets but not in the moveset base.
    Returns a dict of tuples index -> normalized_attack."""
    normalized = {}
    for index in tutor_attacks:
        # Normalize the attack and check if it is
        # part of the moveset base
        normalized_attack = normalize_attack_string(tutor_attacks[index])
        if normalized_attack in constants.attack_table:
            normalized[index] = normalized_attack
        else:
            not_in_moveset_base.add(str((normalized_attack, tutor_attacks[index])))
    return normalized

def normalize_tm_attacks(tm_attacks, constants):
    """ Normalizes a list of tuples tm, attack
    and replaces all attack strings with their respective
    constants from the moveset base. If a move can not be matched
    the move will be added to a set that stores all moves
    that were found in movesets but not in the moveset base.
    Furthermore the tm is split into a tuple type, number where
    type is either 'tm' or 'hm' and number an integer describing
    the tm. Subsequently a triplet (type, number, normalized_attack)
    is returned."""
    normalized = []
    for tm, attack in tm_attacks:
        # Normalize the attack and check if it is
        # part of the moveset base
        normalized_attack = normalize_attack_string(attack)
        if normalized_attack in constants.attack_table:
            if tm.startswith("TM"):
                normalized.append(("tm", int(tm[2:]), normalized_attack))
            elif tm.startswith("VM"):
                normalized.append(("vm", int(tm[2:]), normalized_attack))
            else: raise Exception("Unkown tm type", tm)
        else:
            not_in_moveset_base.add(str((normalized_attack, attack)))
            #print("'" + attack + "' not in moveset base.")
    return normalized


def normalize_pokemon(pkmn, constants):
    """ Normalizes the data of a pokemon, i.e. removes
    all moves that are not in the moveset base and replaces
    those who are with their respective representation as constant"""
    pkmn.attacks_lvlup = normalize_lvlup_attacks(pkmn.attacks_lvlup, constants)
    pkmn.attacks_breed = normalize_attack_set(pkmn.attacks_breed, constants)
    pkmn.attacks_tutor = normalize_tutor_attacks(pkmn.attacks_tutor, constants)
    pkmn.attacks_tm = normalize_tm_attacks(pkmn.attacks_tm, constants)