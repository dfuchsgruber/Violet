# Violet Architecture Notes

## Layout

- `Violet/src/`: hand-written C, assembly hooks/scripts, and `.pms` source data discovered recursively by the main makefile.
- `Violet/include/c/`: C declarations for engine structs, FireRed globals, and Violet subsystems.
- `Violet/include/as/`: assembly macro/include files, including generated constants includes.
- `Violet/constants/`: JSONC constant tables. `proj.pmp.constants` maps table names to files.
- `Violet/models/`: pyagb/pymap models for PMS data.
- `Violet/asset/`: source graphics, music, cries, samples, and fonts.
- `Violet/tools/`: build/index generators. `tools/index` reads the built ROM plus symbol dump and writes readable indexes.
- `Violet/patches.asm`, `Violet/patches/`, `Violet/linker.ld`: armips patch entry points and overlay placement.

## Build Flow

- `Violet/makefile` builds `bld/violet.gba` from the base ROM configured in `../.env`.
- C sources are preprocessed by `pypreproc` with `proj.pmp`, then compiled for ARM7TDMI Thumb.
- Assembly sources are preprocessed the same way, then assembled with `arm-none-eabi-as`.
- PNG assets become generated C through `grit`; nearest `default.grit` or file-specific `.grit` is selected by walking up the directory tree.
- `.pms` files become generated assembly through `pymap2s`.
- Constants produce generated C and assembly headers through `pymapconstex`.
- Linker imports objects into ROM space; `patches.asm` opens the base ROM, includes hook files, imports `bld/linked.o` at `0x09000000`, and writes the Violet marker.

## Validation

- For a full build, prefer the existing Nix shell command:

```bash
nix --extra-experimental-features 'nix-command flakes' develop -c make -C Violet bld/violet.gba
```

- For generated data or tools, also run `python -m py_compile` on edited Python files.
- For index output, build `make -C Violet index` after the ROM and symbols exist.

## C/Assembly Integration

- Declare C symbols needed from assembly with `.global` in assembly and `extern` in C headers when C uses them.
- Assembly overworld scripts include generated constants such as `vars.s`, `flags.s`, `items.s`, `specials.s`, `ordinals.s`, and `callstds.s`.
- Use script macros from `include/as/overworld_script.s`; scripts often call C through `callasm` or `special`.
- Keep script text language-specific with `.ifdef LANG_GER` / `.elseif LANG_EN`.

## Strings And Language

- C strings usually use `LANGDEP(PSTRING("German"), PSTRING("English"))`.
- `LANGUAGE=LANG_GER` is the default in `Violet/makefile`; English exists but is not the default.
- Fixed-size localized strings in PMS models use `agb.types.LocalizedStringType`.
- Text control codes are often embedded in `PSTRING`, e.g. `\n`, `\p`, or named token strings consumed by the preprocessor/charmap.

## Save, Flags, And Vars

- `save1` and `save2` mirror FireRed saveblocks. `custom_memory csave` holds Violet-specific persistent state.
- Flags are checked and changed with `checkflag`, `setflag`, and `clearflag`.
- Vars are accessed as pointers with `var_access`; `var_get` treats values `>= 0x4000` as vars.
- Common script result globals are `lastresult`, `lasttalked`, and `player_facing`.

## Assets

- Generated graphic symbols follow source filenames, e.g. `gfx_pokepad_cursorTiles`, `gfx_pokepad_cursorPal`, and `gfx_pokepad_wallpaper_startersMap`.
- OAM sprites use `graphic`, `palette`, `sprite`, and `oam_template` structs from `include/c/oam.h`.
- Background tilemaps are often LZ77-compressed and loaded/decompressed through `bg_*`, `lz77uncompwram`, or `pal_decompress`.

