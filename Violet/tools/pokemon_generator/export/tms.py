tms = {    
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

def get_tm_compatibility(tm_list):
    """ Creates the 8-byte compatibility array based on a list of tm / hm moves.
    
    Parameters:
    -----------
    tm_list : list
        List of tuples move, tm_type indicating the compatible moves.
    
    Returns:
    --------
    compatbililty : list
        Eight bytes indicating the tm / hm compatbility of a pokemon.
    """
    compatbililty = [0] * 8
    for move, tm_type in tm_list:
        prefix, idx = tm_type
        idx -= 1
        if prefix == 'VM':
            idx += 50
        compatbililty[idx // 8] |= 1 << (idx & 7)
    return compatbililty
