# Export pokedex entries

def export_pokedex_entries(stats, project, pokedex_order, num_entries=386, language='LANG_GER'):
    """ Creates a structure for pokedex entries.
    
    Parameters:
    -----------
    stats : list
        A list of dicts representing the updated pokemon.
    project : pymap.project.Project
        The pymap project.
    pokedex_order : list
        The entry numbers of each species.
    num_entries:
        How many pokedex entries there are.
    language : str
        The language to export the structure in.
        
    Returns:
    --------
    pokedex_entries : list
        The pokedex entries.
    """
    # Create default entries.
    pokedex_entries = [{
        'genus' : 'Unbekannt',
        'height' : 0,
        'weight' : 0,
        'entry_string_0' : None,
        'entry_string_1' : None,
        'field_14' : 0,
        'pokemon_scale' : 0,
        'pokemon_displace' : 0,
        'trainer_scale' : 0,
        'trainer_displace' : 0,
        'field_1E' : 0
    } for i in range(num_entries + 1)] # The 0-th entry is reserved
    for stat, pokedex_number in zip(stats, pokedex_order):
        if pokedex_number > 0:
            # Update the dex entry
            if 'genus' in stat:
                pokedex_entries[pokedex_number]['genus'] = stat['genus'][language]
            if 'dex_entry' in stat:
                pokedex_entries[pokedex_number]['entry_string_0'] = stat['dex_entry'][language]
            if 'weight' in stat:
                pokedex_entries[pokedex_number]['weight'] = stat['weight']
            if 'height' in stat:
                pokedex_entries[pokedex_number]['height'] = stat['height']
    return pokedex_entries