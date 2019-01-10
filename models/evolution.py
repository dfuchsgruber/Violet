import agb.types

evolution_method_type = agb.types.ScalarType('u16', constant='evolution_methods')

evolution_entry_type = agb.types.Structure([
    ('method', 'evolution.method', 0),
    ('argument', 'evolution.argument', 0),
    ('target', 'species'), # Defined in wild_pokemon model
    ('baby_trigger_item', 'item', 0)
])

evolution_entries_type = agb.types.UnboundedArrayType(
    'evolution.entry', {
        'method' : 'EVOLUTION_METHOD_NONE',
        'argument' : {
            'numeric' : 0
        },
        'target' : 0,
        'baby_trigger_item' : 0
    }
)

evolution_entries_pointer_type = agb.types.PointerType(
    'evolution.entries',
    lambda project, context, parents: (f'entries_{context[-1]}', 2, None)
)

evolution_argument_map_type = agb.types.Structure([
    ('bank', 'u8', 0),
    ('map_idx', 'u8', 0)
])

evolutions_type = agb.types.FixedSizeArrayType(
    'evolution.entries_pointer',
    lambda project, context: len(project.constants['species'])
)

def evolution_argument_get_type(project, context, parents):
    """ Determines the type of the evolution method.
    
    Parameters:
    -----------
    project : pymap.project.Project
        The pymap project.
    context : object
        The context.
    parents : object
        The parents of the union.
    
    Returns:
    --------
    union_type : str
        The union type.
    """
    method = parents[-1]['method']
    if method in ('EVOLUTION_METHOD_TRADE_HOLD_ITEM', 'EVOLUTION_METHOD_STONE',
        'EVOLUTION_METHOD_HOLD_ITEM', 'EVOLUTION_METHOD_LINK_CABLE_AND_ITEM', 'EVOLUTION_METHOD_MALE_AND_STONE',
        'EVOLUTION_METHOD_HOLD_ITEM_AND_NIGHT', 'EVOLUTION_METHOD_FEMALE_AND_STONE',
        'EVOLUTION_METHOD_HOLD_ITEM_AND_DAY'):
        return 'item'
    elif method in ('EVOLUTION_METHOD_KNOW_MOVE',):
        return 'move'
    elif method in ('EVOLUTION_METHOD_ON_MAP',):
        return 'map'
    elif method in ('EVOLUTION_METHOD_KNOW_MOVE_TYPE',):
        return 'pokemon_type'
    else:
        return 'numeric'

evolution_argument_union_type = agb.types.UnionType(
    {
        'numeric' : 'u16', # Numeric trigger such as level, friendship, etc.
        'item' : 'item', # Item type is defined in basestats models
        'move' : 'move', # Move type is defined in basestats models
        'map' : 'evolution.argument.map',
        'pokemon_type' : 'basestats.pokemon_type'
    },
    evolution_argument_get_type
)

# Define evolution triggers

models_to_export = {
    'evolution.method' : evolution_method_type,
    'evolution.argument' : evolution_argument_union_type,
    'evolution.argument.map' : evolution_argument_map_type,
    'evolution.entry' : evolution_entry_type,
    'evolution.entries' : evolution_entries_type,
    'evolution.entries_pointer' : evolution_entries_pointer_type,
    'evolutions' : evolutions_type,
}