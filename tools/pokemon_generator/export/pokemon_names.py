# Export pokemon names

def export_pokemon_names(stats, project):
    """ Creates a structure for names.
    
    Parameters:
    -----------
    stats : list
        A list of dicts representing the updated pokemon.
    project : pymap.project.Project
        The pymap project.
        
    Returns:
    --------
    names : list
        The pokemon names
    """
    return [stat.get('name', '???????') for stat in stats]