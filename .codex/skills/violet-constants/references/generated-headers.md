# Violet Generated Constants Headers

## Registration

Constants are registered in `Violet/proj.pmp.constants`:

```jsonc
{
	"items": "constants/items.const",
	"species": "constants/species.const"
}
```

The key is the constant table name used by pymap/pyagb. The path points to the `.const` JSONC file.

## Generation

The main makefile discovers constants with:

```make
CONSTANTS=$(call rwildcard,constants/,*.const)
CONSTANTSHAS=$(CONSTANTS:%.const=include/as/%.s)
CONSTANTSHC=$(CONSTANTS:%.const=include/c/%.h)
```

Generate specific headers with:

```bash
nix --extra-experimental-features 'nix-command flakes' develop -c \
  make -C Violet include/c/constants/<name>.h include/as/constants/<name>.s
```

Generated headers are ignored by git in this repo. Do not hand-edit them.

## C Usage

Include generated C constants where symbolic constants are used directly:

```c
#include "constants/items.h"
#include "constants/mega_evolution_types.h"
```

Prefer generated constants headers over local `#define` duplicates when the values also need to be used by PMS data or models.

## Assembly Usage

Generated PMS assembly includes the relevant assembly constants automatically when a model field uses a constant table.

Example generated assembly for a model with species/items/type constants may include:

```asm
.include "species.s"
.include "items.s"
.include "mega_evolution_types.s"
```

## Data Model Usage

Use the `proj.pmp.constants` key in `ScalarType`:

```python
species_type = agb.types.ScalarType("u16", constant="species")
item_type = agb.types.ScalarType("u16", constant="items")
evolution_type = agb.types.ScalarType("u16", constant="mega_evolution_types")
```

Then PMS data may use symbolic values:

```jsonc
{
	"species": "POKEMON_GEOWAZ",
	"mega_item": "ITEM_GEOWAZNIT",
	"type": "MEGA_EVOLUTION"
}
```
