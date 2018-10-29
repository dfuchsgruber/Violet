import agb.types

# Define a model for the basestats

pokemon_type_type = agb.types.ScalarType('u8', constant='pokemon_types')
pokemon_growth_rate_type = agb.types.ScalarType('u8', constant='pokemon_growth_rates')
egg_group_type = agb.types.ScalarType('u8', constant='egg_groups')
item_type = agb.types.ScalarType('u16', constant='items')
ability_type = agb.types.ScalarType('u8', constant='abilities')
pokemon_shape_type = agb.types.ScalarType('u8', constant='pokemon_shapes')

basestat_type = agb.types.Structure([
    ('KP', 'u8'),
    ('Angriff', 'u8'),
    ('Verteidigung', 'u8'),
    ('Initiative', 'u8'),
    ('Spezialangriff', 'u8'),
    ('Spezialverteidigung', 'u8')
])

ev_yield_type = agb.types.BitfieldType('u16', [
    ('KP', None, 2),
    ('Angriff', None, 2),
    ('Verteidigung', None, 2),
    ('Initiative', None, 2),
    ('Spezialangriff', None, 2),
    ('Spezialverteidigung', None, 2),
    ('Padding', None, 4)
])

stat_type = agb.types.Structure([
    ('basestats', 'stats.basestats'),
    ('type_0', 'stats.pokemon_type'),
    ('type_1', 'stats.pokemon_type'),
    ('capture_rate', 'u8'),
    ('exp_yield', 'u8'),
    ('ev_yield', 'stats.ev_yield'),
    ('common_item', 'item'),
    ('rare_item', 'item'),
    ('gender_ratio', 'u8'),
    ('egg_cycles', 'u8'),
    ('base_happiness', 'u8'),
    ('growth_rate', 'stats.pokemon_growth_rate'),
    ('egg_group_0', 'egg_group'),
    ('egg_group_1', 'egg_group'),
    ('ability_0', 'ability'),
    ('ability_1', 'ability'),
    ('safari_rate', 'u8'),
    ('color', 'u8'),
    ('hidden_ability', 'ability'),
    ('form', 'pokemon_shape')
])

stats_type = agb.types.ArrayType(
    'stats.stat',
    (lambda project, parents: len(project.constants['species']))
)



models_to_export = {
    'stats.basestats' : basestat_type,
    'stats.pokemon_type' : pokemon_type_type,
    'stats.pokemon_growth_rate' : pokemon_growth_rate_type,
    'stats.ev_yield' : ev_yield_type,
    'item' : item_type,
    'egg_group' : egg_group_type,
    'ability' : ability_type,
    'pokemon_shape' : pokemon_shape_type,
    'stats.stat' : stat_type,
    'stats.stats' : stats_type
}
