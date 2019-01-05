import agb.types

pokedex_order_type = agb.types.FixedSizeArrayType(
    'u16',
    lambda project, context: len(project.constants['species']) - 1
)

pokedex_entry_string_type = agb.types.StringType(box_size=(35, 255))

pokdex_entry_string_pointer_type = agb.types.PointerType(
    'pokedex.entry_string',
    lambda project, context, parents: (f'pokedex_entry_{context[-2]}', 0, False)
)

pokedex_genus_string_type = agb.types.StringType(fixed_size=12)

pokdex_entry_type = agb.types.Structure([
    ('genus', 'pokedex.genus_string'),
    ('height', 'u16'),
    ('weight', 'u16'),
    ('entry_string_0', 'pokedex.entry_string_pointer'),
    ('entry_string_1', 'pokedex.entry_string_pointer'),
    ('field_14', 'u16'),
    ('pokemon_scale', 'u16'),
    ('pokemon_displace', 'u16'),
    ('trainer_scale', 'u16'),
    ('trainer_displace', 'u16'),
    ('field_1E', 'u16')
])

pokedex_entries_type = agb.types.FixedSizeArrayType(
    'pokedex.entry',
    lambda project, context: 386 + 1
)

models_to_export = {
    'pokedex_order' : pokedex_order_type,
    'pokedex.entry_string' : pokedex_entry_string_type,
    'pokedex.entry_string_pointer' : pokdex_entry_string_pointer_type,
    'pokedex.genus_string' : pokedex_genus_string_type,
    'pokedex.entry' : pokdex_entry_type,
    'pokedex_entries' : pokedex_entries_type,
}