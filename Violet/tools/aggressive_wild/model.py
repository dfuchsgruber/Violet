"""Data model for aggressive wild encounters in Pokémon Violet."""

import agb.types

AGGRESSIVE_WILD_ENCOUNTER_DATATYPE = 'aggressive_wild_encounters'

aggressive_wild_entry_type = agb.types.Structure([
    ('flag', 'u16', 'flags'),
    ('despawn_rate', 'u8', 0),
    ('filler', 'u8', 0),
])


aggressive_wild_type = agb.types.UnboundedArrayType(
    'aggressive_wild_entry',
    {'flag' : 0xFFFF, 'despawn_rate': 0, 'filler': 0},
)

model = {
    AGGRESSIVE_WILD_ENCOUNTER_DATATYPE: aggressive_wild_type,
    'aggressive_wild_entry': aggressive_wild_entry_type,
}