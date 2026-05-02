# Violet PMS Build Flow

## Source Shape

Standalone PMS data normally looks like this:

```jsonc
{
	"label": "global_symbol_name",
	"type": "exported_model_type",
	"data": []
}
```

The `"type"` value must exist in `models_to_export`. The `"label"` becomes the generated assembly/C symbol.

PMS files use JSONC. Prefer comments for entry labels:

```jsonc
{
	"label": "attacks",
	"type": "attack.table",
	"data": [
		// ATTACK_NONE
		{
			"effect": 0
		}
	]
}
```

## Makefile Discovery

The main `Violet/makefile` discovers project PMS sources with:

```make
PYAGBSRC:=$(call rwildcard,src/,*.pms)
PYAGBS=$(PYAGBSRC:%.pms=$(BLDPATH)/%.s)
PYAGBOBJS=$(PYAGBS:%.s=%.o)
```

The generation rule is:

```make
$(PYAGBS): $(BLDPATH)/%.s: %.pms
	$(PYMAP2S) $< $(MAPPROJ) -o $@
```

So `Violet/src/foo/bar.pms` produces:

```text
Violet/bld/src/foo/bar.s
Violet/bld/src/foo/bar.o
```

## C Integration

When PMS replaces a C table:

1. Move the initializer into `.pms`.
2. Keep the C struct typedef in a header or shared C include.
3. Add `extern <struct_type> <label>[];` to the header.
4. Remove redundant constants includes from the C file if the PMS model now owns those constants.
5. Keep C traversal logic unchanged if the model emits the same sentinel.

## Validation

Run small checks first:

```bash
python -m py_compile Violet/models/<model>.py
```

Then build the generated assembly/object:

```bash
nix --extra-experimental-features 'nix-command flakes' develop -c \
  make -C Violet bld/src/path/to/data.s bld/src/path/to/data.o
```

Inspect generated assembly when sentinel layout or constants matter:

```bash
sed -n '1,160p' Violet/bld/src/path/to/data.s
```
