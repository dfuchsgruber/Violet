import agb.types

# Define pymap model classes specific for Pokémon Violet

person_behaviour_type = agb.types.ScalarType('u8', constant='person_behaviours')
flag_type = agb.types.ScalarType('u16', constant='flags')
var_type = agb.types.ScalarType('u16', constant='vars')
connection_direction_type = agb.types.ScalarType('u32', constant='map_connections')
song_type = agb.types.ScalarType('u16', constant='songs')
namespace_type = agb.types.ScalarType('u8', constant='map_namespaces')
flash_type_type = agb.types.ScalarType('u8', constant='map_flash_types')
weather_type = agb.types.ScalarType('u8', constant='map_weathers')
types_type = agb.types.ScalarType('u8', constant='map_types')
show_name_type = agb.types.ScalarType('u8', constant='map_show_name_types')
battle_style_type = agb.types.ScalarType('u8', constant='map_battle_styles')

# Events
person_type = agb.types.Structure([
    ('target_index', 'u8'),
    ('picture', 'u8'),
    ('field_2', 'u8'),
    ('field_3', 'u8'),
    ('x', 's16'),
    ('y', 's16'),
    ('level', 'u8'),
    ('behaviour', 'person_behaviour'),
    ('behaviour_range', 'u8'),
    ('field_B', 'u8'),
    ('is_trainer', 'u8'),
    ('field_D', 'u8'),
    ('alert_radius', 'u16'),
    ('script', 'ow_script_pointer'),
    ('flag', 'flag'),
    ('field_16', 'u16')
])


trigger_type = agb.types.Structure([
    ('x', 's16'),
    ('y', 's16'),
    ('level', 'u8'),
    ('field_5', 'u8'),
    ('var', 'var'),
    ('value', 'u16'),
    ('field_A', 'u8'),
    ('field_B', 'u8'),
    ('script', 'ow_script_pointer')
])

signpost_item_type = agb.types.BitfieldType('u32', [
    ('item', 'items', 16),
    ('flag', None, 8),
    ('amount', None, 5),
    ('chunk', None, 3)
])

# Map connections

connection_type = agb.types.Structure([
    ('direction', 'connection.direction'),
    ('displacement', 's32'),
    ('bank', 'u8'),
    ('map_idx', 'u8'),
    ('field_A', 'u8'),
    ('field_B', 'u8')
])

# Map header

header_type = agb.types.Structure([
    ('footer', 'footer_pointer'),
    ('events', 'header.event_header_pointer'),
    ('levelscripts', 'levelscript_header_pointer'),
    ('connections', 'header.connection_header_pointer'),
    ('music', 'song'),
    ('footer_idx', 'u16'),
    ('namespace', 'map_namespace'),
    ('flash_type', 'map_flash_type'),
    ('weather', 'map_weather'),
    ('type', 'map_type'),
    ('field_18', 'u8'),
    ('show_name', 'map_show_name'),
    ('field_1A', 'u8'),
    ('battle_style', 'map_battle_style')
])

# Export new models

models_to_export = {
    'person_behaviour' : person_behaviour_type,
    'flag' : flag_type,
    'var' : var_type,
    'song' : song_type,
    'map_namespace' : namespace_type,
    'map_flash_type' : flash_type_type,
    'map_weather' : weather_type,
    'map_type' : types_type,
    'map_show_name' : show_name_type,
    'map_battle_style' : battle_style_type,
    'event.person' : person_type,
    'event.trigger' : trigger_type,
    'event.signpost_item' : signpost_item_type,
    'connection.direction' : connection_direction_type,
    'connection.connection' : connection_type,
    'header.header' : header_type
}

