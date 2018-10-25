def merge(target, source):
    """ Merges all keys from target recursively into source.
    Dicts are merged, lists are appended, other values simply replaced.
    
    Parameters:
    -----------
    target : dict
        The target dict that will be extended and overwritten.
    source : dict
        The source dict from which overwrite values are taken.
    """
    for key in source:
        if key in target:
            if not type(source[key]) == type(target[key]):
                raise RuntimeError(f'Type mismatch for key {key}. Have {type(source[key])} but expected {type(target[key])}')
            # Decide what to do based on the type of the value
            if isinstance(target[key], list):
                target[key] += source[key]
            elif isinstance(target[key], dict):
                merge(target[key], source[key])
            else:
                target[key] = source[key]
        else:
            target[key] = source[key]

def update_pokemon(base, update):
    """ Updates a pokemon dictionary with new values.
    
    Parameters:
    -----------
    base : dict
        The pokemon base (fetched from PokeApi).
    update : dict
        The custom update for this pokemon.
    
    Returns:
    --------
    updated : dict
        The updated pokemon.
    """
    updated = base.copy()
    merge(updated, update)
    return updated


    