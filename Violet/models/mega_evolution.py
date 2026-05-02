import agb.types


mega_evolution_species_type = agb.types.ScalarType("u16", constant="species")
mega_evolution_item_type = agb.types.ScalarType("u16", constant="items")
mega_evolution_type_type = agb.types.ScalarType("u16", constant="mega_evolution_types")

mega_evolution_entry_type = agb.types.Structure(
    [
        ("species", "mega_evolution.species", 0),
        ("mega_item", "mega_evolution.item", 0),
        ("mega_species", "mega_evolution.species", 0),
        ("type", "mega_evolution.type", 0),
    ]
)

mega_evolutions_type = agb.types.UnboundedArrayType(
    "mega_evolution.entry",
    {
        "species": 0xFFFF,
        "mega_item": 0xFFFF,
        "mega_species": 0xFFFF,
        "type": 0xFFFF,
    },
)


models_to_export = {
    "mega_evolution.species": mega_evolution_species_type,
    "mega_evolution.item": mega_evolution_item_type,
    "mega_evolution.type": mega_evolution_type_type,
    "mega_evolution.entry": mega_evolution_entry_type,
    "mega_evolutions": mega_evolutions_type,
}
