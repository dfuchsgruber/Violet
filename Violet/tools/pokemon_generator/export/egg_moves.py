# Export egg moves

from . import constant
from functools import partial

def export_egg_moves(stats, project, language='LANG_GER'):
    """ Creates a structure for egg moves.
    
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
    egg_moves : list
        The egg moves structure.
    """
    egg_moves = []
    for stat in stats:
        egg_moveset = stat.get('egg_moves', None)
        if egg_moveset is not None:
            # Do not export empty sets
            if len(egg_moveset) == 0:
                egg_moveset = None
            else:
                # Map all moves to their constants and filter invalid moves
                egg_moveset = list(filter(lambda move: move is not None, map(partial(constant.attack_to_constant, project), egg_moveset)))
        egg_moves.append(egg_moveset)
    return egg_moves