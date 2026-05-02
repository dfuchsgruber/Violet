---
name: violet-pms-models
description: Work with Violet project's .pms data files and pymap/pyagb Python data models. Use when adding, changing, reviewing, or interpreting .pms files, models/*.py entries, proj.pmp.config model registration, generated assembly from PMS data, or C globals backed by PMS.
---

# Violet PMS Models

## Core Workflow

1. Inspect an existing nearby `.pms` file and the corresponding `Violet/models/*.py` model before changing anything.
2. Model the binary layout with `agb.types` in a `Violet/models/<domain>.py` file and export all public type names through `models_to_export`.
3. Register new model files in `Violet/proj.pmp.config` under `"model"`.
4. Put project source PMS data under `Violet/src/**/*.pms` unless a local makefile already establishes a different source path. The main makefile discovers `src/**/*.pms` through `PYAGBSRC`.
5. Use PMS files shaped like `{"label": "...", "type": "...", "data": ...}` when creating standalone global data.
6. Keep labels aligned with the C symbol name expected by code, then declare that symbol in the relevant C header with `extern`.
7. Validate by compiling the model, checking JSONC syntax with the project tooling, and building the generated assembly/object through `PYMAP2S` or the existing make target.

## Read When Needed

Read `references/model-patterns.md` when designing or modifying a model type.
Read `references/pms-build-flow.md` when wiring PMS data into C, assembly, or make recipes.

## Project Rules

- Use constants-aware scalar types for fields that should accept named constants, for example `agb.types.ScalarType("u16", constant="species")`.
- Reuse existing exported model names when possible, such as `species`, `item`, or `move`; create domain-prefixed names when the C layout needs different widths or semantics.
- Use `UnboundedArrayType` with a sentinel for C arrays that are traversed until a terminal value.
- Do not hand-write generated assembly from PMS data. Generate it through the make/PYMAP flow.
- PMS files are JSONC: regular JSON plus `//` or `/* ... */` comments. Use comments for human labels such as attack IDs instead of metadata fields that the model does not consume.
- PMS JSONC should store named constants as strings when the model field has an associated constant table.

## Fast Checks

```bash
python -m py_compile Violet/models/<model>.py
nix --extra-experimental-features 'nix-command flakes' develop -c make -C Violet bld/src/path/to/file.s
```
