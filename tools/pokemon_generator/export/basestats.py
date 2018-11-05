# Export pokemon basestats

from . import constant

def export_basestats(stats, project, basestat_type='basestats'):
    """ Creates a structure for pokemon basestats.
    
    Parameters:
    -----------
    stats : list
        A list of dicts representing the updated pokemon.
    project : pymap.project.Project
        The pymap project.
        
    Returns:
    --------
    basestats : list
        The pokemon basestats.
    """
    basestats = []
    for stat in stats:
        # Copy all members from stat except sets (which are not seriazible).
        # This of course exports unneccessary attributes, which however will
        # be ignored by pymap2s.
        basestat = stat.copy()
        set_keys = []
        for key in basestat.keys():
            if isinstance(basestat[key], set):
                set_keys.append(key)
        for key in set_keys:
            del basestat[key]

        # Add prefixes to match the constants
        for keys, prefix in ((('type_0', 'type_1'), 'TYPE_'),
            (('growth_rate', ), 'GROWTH_RATE_'),
            (('egg_group_0', 'egg_group_1'), 'EGG_GROUP_'),
            (('ability_0', 'ability_1', 'hidden_ability'), ''),
            (('shape',), 'SHAPE_')):
            for key in keys:
                if basestat[key] is not None:
                    basestat[key] = constant.strfix(f'{prefix}{basestat[key]}'.upper())
                else:
                    basestat[key] = 0
        # The color is nested, treat it differently
        color = basestat['color_and_flip'][1]
        basestat['color_and_flip'][1] = constant.strfix(f'POKEMON_COLOR_{color}'.upper())
        # The item may not be present
        for key in ('common_item', 'rare_item'):
            item = basestat[key]
            basestat[key] = 0
            if item is not None:
                item = constant.item_to_constant(project, str(item))
                if item is not None:
                    basestat[key] = item
        basestats.append(basestat)
    return basestats