""" This module is responsible for creating a tm/hm
compatibilty list for the 3rd generation based
on all moves obtainable for a pokemon."""

tms_3rd_gen = {    
    'Power-Punch' : ('TM', 1),
    'Drachenklaue' : ('TM', 2),
    'Aquawelle' : ('TM', 3),
    'Gedankengut' : ('TM', 4),
    'Brüller' : ('TM', 5),
    'Toxin' : ('TM', 6),
    'Hagelsturm' : ('TM', 7),
    'Protzer' : ('TM', 8),
    'Kugelsaat' : ('TM', 9),
    'Kraftreserve' : ('TM', 10),
    'Sonnentag' : ('TM', 11),
    'Verhöhner' : ('TM', 12),
    'Eisstrahl' : ('TM', 13),
    'Blizzard' : ('TM', 14),
    'Hyperstrahl' : ('TM', 15),
    'Lichtschild' : ('TM', 16),
    'Schutzschild' : ('TM', 17),
    'Regentanz' : ('TM', 18),
    'Gigasauger' : ('TM', 19),
    'Bodyguard' : ('TM', 20),
    'Frustration' : ('TM', 21),
    'Solarstrahl' : ('TM', 22),
    'Eisenschweif' : ('TM', 23),
    'Donnerblitz' : ('TM', 24),
    'Donner' : ('TM', 25),
    'Erdbeben' : ('TM', 26),
    'Rückkehr' : ('TM', 27),
    'Schaufler' : ('TM', 28),
    'Psychokinese' : ('TM', 29),
    'Spukball' : ('TM', 30),
    'Durchbruch' : ('TM', 31),
    'Doppelteam' : ('TM', 32),
    'Reflektor' : ('TM', 33),
    'Schockwelle' : ('TM', 34),
    'Flammenwurf' : ('TM', 35),
    'Matschbombe' : ('TM', 36),
    'Sandsturm' : ('TM', 37),
    'Feuersturm' : ('TM', 38),
    'Felsgrab' : ('TM', 39),
    'Aero-Ass' : ('TM', 40),
    'Folterknecht' : ('TM', 41),
    'Fassade' : ('TM', 42),
    'Geheimpower' : ('TM', 43),
    'Erholung' : ('TM', 44),
    'Anziehung' : ('TM', 45),
    'Raub' : ('TM', 46),
    'Stahlflügel' : ('TM', 47),
    'Wertewechsel' : ('TM', 48),
    'Übernahme' : ('TM', 49),
    'Hitzekoller' : ('TM', 50),
    'Zerschneider' : ('VM', 1),
    'Fliegen' : ('VM', 2),
    'Surfer' : ('VM', 3),
    'Stärke' : ('VM', 4),
    'Blitz' : ('VM', 5),
    'Zertrümmerer' : ('VM', 6),
    'Kaskade' : ('VM', 7),
    'Kraxler' : ('VM', 8)
}

def tm_list_by_availible_moves(availible_moves):
    """ Creates a 3rd generation tm list of tuples XXYY, attack
    where XX is either 'tm' or 'hm' and YY is the corresponding
    number based on the total movepool of a pokemon."""
    tms = []
    for attack in availible_moves:
        if attack in tms_3rd_gen:
            type, num = tms_3rd_gen[attack]
            prefix = type.upper() + str(num).zfill(2)
            tms.append((prefix, attack))
    return tms