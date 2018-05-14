"""
This module provides all move tutors that the
hack provides and creates sets that describe
the compatibility for a pokemon with those
move tutors.
"""

move_tutors = [
    'Fokusstoß',
    'Gifthieb',
    'Finsteraura',
    'Eiszahn',
    'Donnerzahn',
    'Kreuzschere',
    'Steinkante',
    'Lichtkanone',
    'Draco-Meteor',
    'Energieball',
    'Drachenpuls',
    'Feuerzahn',
    'Explosion',
    'Steinhagel',
    'Delegator',
    'Flora-Statue',
    'Lohekanonade',
    'Aquahaubitze',
    'Donnerwelle'
]

def pkmn_get_move_tutor_compatibility(availible_attacks):
    """ Creates a list of tuples index, attack that
    describes the move tutor compatibility of a pokemon
    given its availible attacks."""
    move_tutor_compatibility = {}
    for attack in availible_attacks:
        if attack in move_tutors:
            move_tutor_compatibility[move_tutors.index(attack)] = attack
    return move_tutor_compatibility


