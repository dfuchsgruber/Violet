# Export pokemon names

def export_pokemon_names(stats, project, language='LANG_GER'):
    """ Creates a structure for names.
    
    Parameters:
    -----------
    stats : list
        A list of dicts representing the updated pokemon.
    project : pymap.project.Project
        The pymap project.
    language : str
        The language to export the structure in.
        
    Returns:
    --------
    names : list
        The pokemon names
    """
    return [stat.get('name', {language : '???????'})[language] for stat in stats]
