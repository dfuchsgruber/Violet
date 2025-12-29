tutor_moves = [
    '---',
    '---',
    '---',
    'Eiszahn',
    'Donnerzahn',
    '---',
    '---',
    '---',
    'Draco-Meteor',
    '---',
    '---',
    'Feuerzahn',
    '---',
    '---',
    '---',
    'Flora-Statue',
    'Lohekanonade',
    'Aquahaubitze',
    '---',
]

def get_tutor_compatibility(compatible_moves):
    """ Returns the tutor compatibility of a pokemon.
    
    Parameters:
    -----------
    compatible_moves : list
        A list of all tutor moves the pokemon is compatible with.
        
    Returns:
    tutor_compatibility : int
        The tutor compatibility (32-bit).
    """
    tutor_compatibility = 0
    for move in compatible_moves:
        tutor_compatibility |= 1 << (tutor_moves.index(move))
    return tutor_compatibility


