# Export accessible moves

from . import constant
from functools import partial

def export_accessible_moves(stats, project, language='LANG_GER'):
    """ Creates a structure for accessible moves.
    
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
    accessible_moves : list
        The accessible moves structure.
    """
    accessible_moves = []
    for stat in stats:
        accessible_moveset = stat.get('accessible_moves', None)
        accessible_moveset = list(filter(lambda move: move is not None, map(partial(constant.attack_to_constant, project), stat.get('accessible_moves', None))))
        accessible_moves.append(accessible_moveset)
    return accessible_moves