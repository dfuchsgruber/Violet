# Export levelup movesets

from . import constant

def export_levelup_moves(stats, project):
    """ Creates a structure for levelup moves.
    
    Parameters:
    -----------
    stats : list
        A list of dicts representing the updated pokemon.
    project : pymap.project.Project
        The pymap project.
        
    Returns:
    --------
    levelup_moves : list
        The levelup moves structure.
    """
    levelup_moves = []
    for stat in stats:
        moveset = stat.get('levelup_moves', None)
        if moveset is not None:
            # Each move is a tuple name, level
            moveset = map(lambda move: (constant.attack_to_constant(project, move[0]), move[1]), moveset)
            # Only consider moves in the game
            moveset = filter(lambda move: move[0] is not None, moveset)
            # Sort moveset by level
            moveset = sorted(moveset, key=lambda move: move[1])
        levelup_moves.append(moveset)
    return levelup_moves
