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
    'Zauberschein' : ('TM', 41),
    'Fassade' : ('TM', 42),
    'Geheimpower' : ('TM', 43),
    'Erholung' : ('TM', 44),
    'Anziehung' : ('TM', 45),
    'Raub' : ('TM', 46),
    'Stahlflügel' : ('TM', 47),
    'Schwerttanz' : ('TM', 48),
    'Irrlicht' : ('TM', 49),
    'Hitzekoller' : ('TM', 50),

    'Fokusstoß' : ('TM', 51),
    'Gifthieb' : ('TM', 52),
    'Finsteraura' : ('TM', 53),
    'Kreuzschere' : ('TM', 54),
    'Steinkante' : ('TM', 55),
    'Lichtkanone' : ('TM', 56),
    'Energieball' : ('TM', 57),
    'Drachenpuls' : ('TM', 58),
    'Explosion' : ('TM', 59),
    'Steinhagel' : ('TM', 60),
    'Delegator' : ('TM', 61),
    'Donnerwelle' : ('TM', 62),
    'Schlafrede' : ('TM', 63),
    'Angeberei' : ('TM', 64),
    'Geowurf' : ('TM', 65),
    'Ampelleuchte' : ('TM', 66),
    'Dunkelklaue' : ('TM', 67),
    'Abschlag' : ('TM', 68),
    'Zen-Kopfstoß' : ('TM', 69),
    'Trickbetrug' : ('TM', 70),
    'Steinpolitur' : ('TM', 71),
    'Blubbstrahl' : ('TM', 72),
    'Fluch' : ('TM', 73),
    'Ausdauer' : ('TM', 74),
    'Eissturm' : ('TM', 75),
    'Folterknecht' : ('TM', 76),
    'Magiemantel' : ('TM', 77),
    'Erdkräfte' : ('TM', 78),
    'Übernahme' : ('TM', 79),
    'Kraftkoloss' : ('TM', 80),
    'Aufbereitung' : ('TM', 81),
    'Wertewechsel' : ('TM', 82),
    'Rückentzug' : ('TM', 83),
    'Natur-Kraft' : ('TM', 84),
    'Trugschlag' : ('TM', 85),
    'Nitroladung' : ('TM', 86),
    'Walzer' : ('TM', 87),
    'Traumfresser' : ('TM', 88),
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
    compatbililty = [0] * 16
    for move, tm_type in tm_list:
        prefix, idx = tm_type
        idx -= 1
        if prefix == 'VM':
            idx += 100
        compatbililty[idx // 8] |= 1 << (idx & 7)
    return compatbililty