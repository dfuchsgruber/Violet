import agb.types

# Define a model for the basestats

pokemon_type_type = agb.types.ScalarType('u8', constant='pokemon_types')
pokemon_growth_rate_type = agb.types.ScalarType('u8', constant='pokemon_grwoth_rates')
pokemon_growth_rate_type = agb.types.ScalarType('u8', constant='pokemon_grwoth_rates')

basestat_type = agb.types.Structure([
    ('KP', 'u8'),
    ('Angriff', 'u8'),
    ('Verteidigung', 'u8'),
    ('Initiative', 'u8'),
    ('Spezialangriff', 'u8'),
    ('Spezialverteidigung', 'u8')
])

stat_type = agb.types.Structure([
    ('basestats', 'stats.basestats'),
    ('type0', 'stats.pokemon_type'),
    ('type1', 'stats.pokemon_type'),
    ('capture_rate', 'u8'),
    ('egg_cycles', 'u8'),
    ('base_happiness', 'u8'),
    ('growth_rate', 'stats.pokemon_growth_rate')
])

default_model = {
    'stats.basestats' : basestat_type,
    'stats.pokemon_type' : pokemon_type_type
    'stats.pokemon_growth_rate' : pokemon_growth_rate_type,
}