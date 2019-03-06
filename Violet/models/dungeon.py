import agb.types


species_list_type = agb.types.UnboundedArrayType(
    'species', 0xFFFF
)

item_list_type = agb.types.UnboundedArrayType(
    'item', 0xFFFF
)

models_to_export = {
    'species_list' : species_list_type,
    'item_list' : item_list_type,
}
