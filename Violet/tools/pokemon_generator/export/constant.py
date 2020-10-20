def strfix(s):
    """ Removes all invalid characters of strings such that
    they match the constants.
    
    Parameters:
    -----------
    s : str
        The string to fix (in upper case letters!)
    
    Returns:
    --------
    fixed : str
        The fixed string.
    """
    for seq, repl in (('Ä', 'AE'), ('Ü', 'UE'), ('Ö', 'OE'), ('-', '_'), (' ', '_'), ('ß', 'SS')):
        s = s.replace(seq, repl)
    return s

def attack_to_constant(project, attack):
    """ Tries to associate an attack with a constant.
    
    Parameters:
    -----------
    project : pymap.project.Project
        The pymap project.
    attack : str
        The attack string.
    
    Returns:
    constant : str or None
        The constant if the attack could be associated or None if not.
    """
    attack = f'ATTACK_{strfix(attack.upper())}'
    if attack in project.constants['attacks']:
        return attack
    else:
        return None

def item_to_constant(project, item):
    """ Tries to associate an item with a constant.
    
    Parameters:
    -----------
    project : pymap.project.Project
        The pymap project.
    item : str
        The item string.
    
    Returns:
    constant : str or None
        The item if the attack could be associated or None if not.
    """
    item = f'ITEM_{strfix(item.upper())}'
    if item in project.constants['items']:
        return item
    else:
        return None
