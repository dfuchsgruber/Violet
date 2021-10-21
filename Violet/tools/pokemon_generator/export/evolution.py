from . import constant

def export_evolutions(stats, project, language='LANG_GER', evolution_entry_type_name='evolution.entry',
    evolution_argument_type_name='evolution.argument'):
    """ Creates a structure for accessible moves.
    
    Parameters:
    -----------
    stats : list
        A list of dicts representing the updated pokemon.
    project : pymap.project.Project
        The pymap project.
    language : str
        The language to export the structure in.
    evolution_entry_type_name : str
        The type of the evolution entry structure.
    evolution_argument_type_name : str
        The type of the evolution argument union.
        
    Returns:
    --------
    evolutions : list
        The pokemon evolutions
    """
    evolutions = []
    for stat in stats:
        stat_evolutions = stat.get('evolutions', {})
        if len(stat_evolutions) > 0:
            entries = []
            for target in stat_evolutions:
                evolution_entry_type = project.model[evolution_entry_type_name]
                evolution_argument_type = project.model[evolution_argument_type_name]
                evolution_entry_struct = evolution_entry_type(project, [], [])
                evolution_argument_union = evolution_argument_type(project, ['argument'], [evolution_entry_struct])

                # Initialize the entry
                evolution_entry_struct['method'] = f"EVOLUTION_METHOD_{stat_evolutions[target]['trigger'].upper()}"
                evolution_entry_struct['target'] = target
                baby_trigger_item = stat_evolutions[target]['baby_trigger_item']
                if baby_trigger_item is not None:
                    baby_trigger_item = constant.item_to_constant(project, baby_trigger_item)
                if baby_trigger_item is None:
                    baby_trigger_item = 0
                evolution_entry_struct['baby_trigger_item'] = baby_trigger_item

                # Initialize the argument
                active_subtype = evolution_argument_type.name_get(project, ['argument'], [evolution_entry_struct])
                evolution_argument_union[active_subtype] = export_evolution_argument(active_subtype, stat_evolutions[target]['argument'], project)
                evolution_entry_struct['argument'] = evolution_argument_union
                entries.append(evolution_entry_struct)
        else:
            entries = None # Do not export evolutions for this pokemon
        evolutions.append(entries)
    return evolutions

    accessible_moves = []
    for stat in stats:
        accessible_moveset = stat.get('accessible_moves', None)
        accessible_moveset = list(filter(lambda move: move is not None, map(partial(constant.attack_to_constant, project), stat.get('accessible_moves', None))))
        accessible_moves.append(accessible_moveset)
    return accessible_moves

def export_evolution_argument(active_subtype, argument_value, project, evolution_argument_type='evolution.argument'):
    """ Exports the argument for an evolution method.
    
    Parameters:
    -----------
    active_subtype : str
        The name of the active subtype of the argument union type.
    project : pymap.project.Project
        The pymap project.
    evolution_argument_type : str
        The name of the evolution argument type.
    
    Returns:
    --------
    argument : int or str
        The argument for the evolution
    """
    if active_subtype == 'item':
        return constant.item_to_constant(project, argument_value)
    elif active_subtype == 'move':
        return constant.attack_to_constant(project, argument_value)
    elif active_subtype == 'map':
        return argument_value
    elif active_subtype == 'numeric':
        return argument_value
    elif active_subtype == 'pokemon_type':
        return f'TYPE_{argument_value.upper()}'
    else:
        raise RuntimeError(f'Unsupported union type {active_subtype}')
