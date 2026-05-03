import agb.types


def get_attack_count(project, context):
    return project.constants["attacks"]["ATTACK_CNT"]


attack_type_type = agb.types.ScalarType("u8", constant="pokemon_types")
attack_affects_whom_type = agb.types.ScalarType("u8", constant="attack_affects_whom_flags")
attack_flags_type = agb.types.ScalarType("u8", constant="attack_flags")
attack_category_type = agb.types.ScalarType("u8", constant="attack_categories")

attack_entry_type = agb.types.Structure(
    [
        ("effect", "u8", 0),
        ("base_power", "u8", 0),
        ("type", "attack.type", 0),
        ("accuracy", "u8", 0),
        ("pp", "u8", 0),
        ("effect_accuracy", "u8", 0),
        ("affects_whom", "attack.affects_whom", 0),
        ("priority", "s8", 0),
        ("flags", "attack.flags", 0),
        ("effect_table", "u8", 0),
        ("category", "attack.category", 0),
        ("rating", "u8", 0),
    ]
)

attack_table_type = agb.types.FixedSizeArrayType("attack.entry", get_attack_count)

attack_name_type = agb.types.LocalizedStringType(fixed_size=13, default_language="LANG_GER")
attack_names_table = agb.types.FixedSizeArrayType("attack.name", get_attack_count)

models_to_export = {
    "attack.type": attack_type_type,
    "attack.affects_whom": attack_affects_whom_type,
    "attack.flags": attack_flags_type,
    "attack.category": attack_category_type,
    "attack.entry": attack_entry_type,
    "attack.table": attack_table_type,
    "attack.name": attack_name_type,
    "attack.names": attack_names_table,
}
