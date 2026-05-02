# Violet Model Patterns

## Location And Registration

- Model modules live in `Violet/models/*.py`.
- Each model module imports `agb.types`.
- Export public type names through a `models_to_export` dictionary.
- New model modules must be added to the `"model"` list in `Violet/proj.pmp.config`.

Example:

```python
import agb.types

entry_type = agb.types.Structure([
    ("field_a", "u16", 0),
    ("field_b", "my_domain.constant_field", 0),
])

entries_type = agb.types.UnboundedArrayType(
    "my_domain.entry",
    {"field_a": 0xFFFF, "field_b": "MY_SENTINEL"},
)

models_to_export = {
    "my_domain.entry": entry_type,
    "my_domain.entries": entries_type,
}
```

## Common Types

- `ScalarType("<width>", constant="<constant-table>")`: integer encoded as a named constant in PMS JSONC.
- `Structure([...])`: C-like struct; tuple shape is `(field_name, model_type_name, default)`.
- `FixedSizeArrayType(element_type, size_or_callback)`: arrays with a known count.
- `UnboundedArrayType(element_type, sentinel)`: arrays terminated by a generated sentinel.
- `PointerType(target_type, label_callback)`: pointer fields that emit referenced data labels.
- `UnionType(mapping, selector_callback)`: fields whose active type depends on parent data.

## Widths And Constants

Match the C struct layout exactly. If a C field is `u16`, use `u16`, even if an existing constant-backed model exists with a different width.

Use existing constants tables when available:

```python
species_type = agb.types.ScalarType("u16", constant="species")
item_type = agb.types.ScalarType("u16", constant="items")
move_type = agb.types.ScalarType("u16", constant="attacks")
pokemon_type_type = agb.types.ScalarType("u8", constant="pokemon_types")
```

## Sentinels

Use `UnboundedArrayType` when C loops until a terminal record. The sentinel lives in the model, not in PMS data.

Example from mega evolutions:

```python
mega_evolutions_type = agb.types.UnboundedArrayType(
    "mega_evolution.entry",
    {
        "species": 0xFFFF,
        "mega_item": 0xFFFF,
        "mega_species": 0xFFFF,
        "type": 0xFFFF,
    },
)
```

## Naming

- Domain-prefix internal model names, for example `mega_evolution.entry`.
- Export the top-level PMS type with the name used in the `.pms` `"type"` field, for example `"mega_evolutions"`.
- Choose a PMS `"label"` that is the C/assembly symbol, for example `"mega_evolutions"`.
