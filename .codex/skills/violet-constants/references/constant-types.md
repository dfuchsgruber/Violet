# Violet Constant Types

## Enum Constants

Use `"type": "enum"` when values are sequential and order is meaningful.

```jsonc
{
	"type": "enum",
	"base": 1,
	"values": [
		"MEGA_EVOLUTION",
		"REGENT_EVOLUTION"
	]
}
```

If `"base"` is omitted, values start at `0`. Existing examples include:

- `constants/evolution_methods.const`
- `constants/pokemon_types.const`
- `constants/items.const`

Generated C shape:

```c
enum mega_evolution_types {
MEGA_EVOLUTION = 1,
REGENT_EVOLUTION = 2,
};
```

Generated assembly shape:

```asm
.equ MEGA_EVOLUTION, 1
.equ REGENT_EVOLUTION, 2
```

## Dict Constants

Use `"type": "dict"` when numeric values are explicit, sparse, externally fixed, or semantically grouped in a way that should not depend on array order.

Before creating a dict, inspect existing dict-style constants in `Violet/constants/` and match their local formatting. Keep numeric values stable unless the user explicitly requests a renumbering.

## Choosing A Table Name

The JSONC filename, the `proj.pmp.constants` key, and generated header path should normally align:

```jsonc
{
	"mega_evolution_types": "constants/mega_evolution_types.const"
}
```

This generates:

```text
Violet/include/c/constants/mega_evolution_types.h
Violet/include/as/constants/mega_evolution_types.s
```

And models refer to:

```python
agb.types.ScalarType("u16", constant="mega_evolution_types")
```
