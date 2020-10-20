

def get_friendship_evolution(evolution_details):
    """ Returns method for friendship based evolution triggers.
    
    Parameters:
    -----------
    evolution_details : dict
        The evolution details.
    
    Returns:
    --------
    evolution_method : str
        The evolution method.
    """
    if evolution_details['time_of_day'] == 'day':
        return 'Friendship_Day'
    elif evolution_details['time_of_day'] == 'night':
        return 'Friendship_Night'
    elif evolution_details['time_of_day'] is None or evolution_details['time_of_day'] == '':
        return 'Friendship'
    else:
        raise RuntimeError(f'Unknown friendship induced evolution with details {evolution_details}')
    
def get_physical_stat_based_evolution(evolution_details):
    """ Returns method for evolution triggers based on the physical stats.
    
    Parameters:
    -----------
    evolution_details : dict
        The evolution details.
    
    Returns:
    --------
    evolution_method : str
        The evolution method.
    """
    if evolution_details['relative_physical_stats'] == 1:
        return 'Atk_gt_Def'
    elif evolution_details['relative_physical_stats'] == -1:
        return 'Atk_lt_Def'
    elif evolution_details['relative_physical_stats'] == 0:
        return 'Atk_eq_Def'
    else:
        raise RuntimeError(f'Unkown physical stat based evolution with details {evolution_details}')

def get_held_item_based_evolution(evolution_details):
    """ Returns method for evolution triggers based on the held item.
    
    Parameters:
    -----------
    evolution_details : dict
        The evolution details.
    
    Returns:
    --------
    evolution_method : str
        The evolution method.
    """
    if evolution_details['time_of_day'] == 'day':
        return 'Hold_Item_and_Day'
    elif evolution_details['time_of_day'] == 'night':
        return 'Hold_Item_and_Night'
    elif evolution_details['time_of_day'] is None:
        return 'Hold_item'
    else:
        raise RuntimeError(f'Unknown held item induced evolution with details {evolution_details}') 
    
def get_stone_based_evolution(evolution_details):
    """ Returns method for evolution triggers based on evolutionary stones.
    
    Parameters:
    -----------
    evolution_details : dict
        The evolution details.
    
    Returns:
    --------
    evolution_method : str
        The evolution method.
    """
    if evolution_details['gender'] == 1:
        return 'Female_and_Stone'
    elif evolution_details['gender'] == 2:
        return 'Male_and_Stone'
    elif evolution_details['gender'] is None:
        return 'Stone'
    else:
        raise RuntimeError(f'Unkown stone induced evolution with details {evolution_details}')
