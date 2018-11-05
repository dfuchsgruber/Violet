# Export tm / hm and tutor compatbility

from . import tms, move_tutor


def export_tm_compatibility(stats, project):
    """ Creates a structure for tm / hm compatibility.
    
    Parameters:
    -----------
    stats : list
        A list of dicts representing the updated pokemon.
    project : pymap.project.Project
        The pymap project.
        
    Returns:
    --------
    tm_compatibility : list
        The  tm / hm compatibility.
    """
    return [ tms.get_tm_compatibility(stat['tm_compatiblilty']) for stat in stats]

def export_tutor_compatibility(stats, project):
    """ Creates a structure for tutor compatibility.
    
    Parameters:
    -----------
    stats : list
        A list of dicts representing the updated pokemon.
    project : pymap.project.Project
        The pymap project.
        
    Returns:
    --------
    tutor : list
        The  tutor compatibility.
    """
    return [ move_tutor.get_tutor_compatibility(stat['tutor_compatibility']) for stat in stats]