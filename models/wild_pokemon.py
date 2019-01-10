# Define models for wild pokemon

import agb.types

species_type = agb.types.ScalarType('u16', constant='species')

entry_type = agb.types.Structure([
    ('level_min', 'u8', 0),
    ('level_max', 'u8', 0),
    ('species', 'species', 0)
])

entries_grass_type = agb.types.FixedSizeArrayType(
    'wild_pokemon.entry',
    (lambda project, context: 12)
)

entries_water_type = agb.types.FixedSizeArrayType(
    'wild_pokemon.entry',
    (lambda project, context: 5)
)

entries_other_type = agb.types.FixedSizeArrayType(
    'wild_pokemon.entry',
    (lambda project, context: 5)
)

entries_odd_rod_type = agb.types.FixedSizeArrayType(
    'wild_pokemon.entry',
    (lambda project, context: 2)
)

entries_good_rod_type = agb.types.FixedSizeArrayType(
    'wild_pokemon.entry',
    (lambda project, context: 3)
)

entries_super_rod_type = agb.types.FixedSizeArrayType(
    'wild_pokemon.entry',
    (lambda project, context: 5)
)

entries_rod_type = agb.types.Structure([
    ('odd_rod', 'wild_pokemon.entries_odd_rod', 0),
    ('good_rod', 'wild_pokemon.entries_good_rod', 0),
    ('super_rod', 'wild_pokemon.entries_super_rod', 0)
])

entries_grass_pointer_type = agb.types.PointerType(
    'wild_pokemon.entries_grass',
    (lambda project, context, parents: 'entries_grass')
)

entries_water_pointer_type = agb.types.PointerType(
    'wild_pokemon.entries_water',
    (lambda project, context, parents: 'entries_water')
)

entries_other_pointer_type = agb.types.PointerType(
    'wild_pokemon.entries_other',
    (lambda project, context, parents: 'entries_other')
)

entries_rod_pointer_type = agb.types.PointerType(
    'wild_pokemon.entries_rod',
    (lambda project, context, parents: 'entries_rod')
)

habitat_grass_type = agb.types.Structure([
    ('frequency', 'u8', 0),
    ('field_1', 'u8', 0),
    ('field_2', 'u8', 0),
    ('field_3', 'u8', 0),
    ('wild_pokemon.entries_grass_pointer', 0)
])

habitat_water_type = agb.types.Structure([
    ('frequency', 'u8', 0),
    ('field_1', 'u8', 0),
    ('field_2', 'u8', 0),
    ('field_3', 'u8', 0),
    ('wild_pokemon.entries_water_pointer', 0)
])

habitat_water_type = agb.types.Structure([
    ('frequency', 'u8', 0),
    ('field_1', 'u8', 0),
    ('field_2', 'u8', 0),
    ('field_3', 'u8', 0),
    ('wild_pokemon.entries_water_pointer', 0)
])

habitat_rod_type = agb.types.Structure([
    ('frequency', 'u8', 0),
    ('field_1', 'u8', 0),
    ('field_2', 'u8', 0),
    ('field_3', 'u8', 0),
    ('wild_pokemon.entries_rod_pointer', 0)
])

habitat_other_type = agb.types.Structure([
    ('frequency', 'u8', 0),
    ('field_1', 'u8', 0),
    ('field_2', 'u8', 0),
    ('field_3', 'u8', 0),
    ('wild_pokemon.entries_other_pointer', 0)
])

habitat_grass_pointer_type = agb.types.PointerType(
    'wild_pokemon.habitat_grass',
    (lambda project, context, parents: 'habitat_grass')
)

habitat_water_pointer_type = agb.types.PointerType(
    'wild_pokemon.habitat_water',
    (lambda project, context, parents: 'habitat_water')
)

habitat_other_pointer_type = agb.types.PointerType(
    'wild_pokemon.habitat_other',
    (lambda project, context, parents: 'habitat_other')
)

habitat_rod_pointer_type = agb.types.PointerType(
    'wild_pokemon.habitat_rod',
    (lambda project, context, parents: 'habitat_rod')
)


# Export models

models_to_export = {
    'species' : species_type,
    'wild_pokemon.entry' : entry_type,
    'wild_pokemon.entries_grass' : entries_grass_type,
    'wild_pokemon.entries_water' : entries_water_type,
    'wild_pokemon.entries_other' : entries_other_type,
    'wild_pokemon.entries_rod' : entries_rod_type,
    'wild_pokemon.entries_odd_rod' : entries_odd_rod_type,
    'wild_pokemon.entries_good_rod' : entries_good_rod_type,
    'wild_pokemon.entries_super_rod' : entries_super_rod_type,
    'wild_pokemon.entries_grass_pointer' : entries_grass_pointer_type,
    'wild_pokemon.entries_water_pointer' : entries_water_pointer_type,
    'wild_pokemon.entries_other_pointer' : entries_other_pointer_type,
    'wild_pokemon.entries_rod_pointer' : entries_rod_pointer_type,
    'wild_pokemon.habitat_grass' : habitat_grass_type,
    'wild_pokemon.habitat_water' : habitat_water_type,
    'wild_pokemon.habitat_other' : habitat_other_type,
    'wild_pokemon.habitat_rod' : habitat_rod_type,
    'wild_pokemon.habitat_grass_pointer' : habitat_grass_pointer_type,
    'wild_pokemon.habitat_water_pointer' : habitat_water_pointer_type,
    'wild_pokemon.habitat_other_pointer' : habitat_other_pointer_type,
    'wild_pokemon.habitat_rod_pointer' : habitat_rod_pointer_type
}