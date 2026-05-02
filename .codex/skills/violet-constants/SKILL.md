---
name: violet-constants
description: Work with Violet project's constants/*.const files and generated constants headers. Use when adding, changing, reviewing, or using project constants, enum/dict constant tables, proj.pmp.constants registration, constants-backed data model fields, or generated include/c/constants/*.h and include/as/constants/*.s files.
---

# Violet Constants

## Core Workflow

1. Inspect similar files in `Violet/constants/**/*.const` before choosing a shape.
2. Add or edit a JSON `.const` file under `Violet/constants/`.
3. Register new constants in `Violet/proj.pmp.constants` with the table name used by models and project code.
4. Use the registered table name in model fields with `agb.types.ScalarType(width, constant="<table-name>")`.
5. Include generated C headers from `include/c/constants/<name>.h` where C code needs symbolic names.
6. Include generated assembly headers from `include/as/constants/<name>.s` where assembly needs symbolic names.
7. Validate JSON and generate the headers with make; generated headers are ignored by git in this repo.

## Read When Needed

Read `references/constant-types.md` when choosing between enum and dict constants.
Read `references/generated-headers.md` when wiring constants into C, assembly, or data models.

## Project Rules

- Constants files are JSON, not C headers. Do not add hand-maintained `#define` constants when a `.const` table is appropriate.
- The key in `proj.pmp.constants` is the constant table name used by `ScalarType(..., constant="<key>")`.
- Enum constants generate sequential values starting at `"base"` or `0` when omitted.
- Dict constants preserve explicit numeric mappings.
- Regenerate generated headers instead of editing files under `Violet/include/c/constants/` or `Violet/include/as/constants/` by hand.

## Fast Checks

```bash
python -m json.tool Violet/constants/<name>.const >/dev/null
nix --extra-experimental-features 'nix-command flakes' develop -c \
  make -C Violet include/c/constants/<name>.h include/as/constants/<name>.s
```
