# C/H Feature Patterns

## Common File Shape

Headers usually contain:

- include guard, often `H_<FEATURE>` or `INCLUDE_C_<PATH>_H_`
- minimal includes: `types.h`, direct struct dependencies, and generated constants
- public enums and structs
- `extern EWRAM` globals for RAM state
- public function declarations
- `extern const` assets, scripts, or generated tables used across files

C files usually contain:

- includes first, starting with `types.h`
- `EWRAM` global definitions near the top, initialized to `NULL` or `{0}`
- static forward declarations for local callbacks
- static const lookup tables and designated initializers
- static helpers
- public functions exported through the header or called by scripts/hooks

## Naming And Style

- Use snake_case for functions, variables, and struct fields.
- Prefix feature functions with the feature name: `bag_*`, `crafting_ui_*`, `ceometria_gym_*`, `weather_snow_*`.
- Use `_t` suffix for typedef structs when the surrounding code does, e.g. `options_state_t`; older files may use bare typedef names.
- Use uppercase constants and enum members, often keyed by generated constants.
- Use designated initializers for tables indexed by constants.
- Use sentinel values heavily: `0xFF`, `0xFFFF`, `NUM_*`, and `NULL`.
- Cast intentionally to `u8`, `u16`, `s16`, or `u32`; the build uses `-Wconversion -Werror`.
- Prefer `ARRAY_COUNT`, `MIN`, `MAX`, `ABS`, `LANGDEP`, and `PSTRING` to local reinventions.
- Keep existing misspellings when they are part of symbols or ABI, e.g. `recipies`, `prepeare`, `challange`, `achivements`.

## Feature Shapes

### Stateless Service

Use for small logic helpers with no screen or long-lived state.

Examples: `fieldmoves/rock_climb.c`, `present/purple_kecleon.c`, `trainer/flag.c`.

Pattern:

- header exposes a few public functions
- C uses local static helpers or direct script globals
- results are returned directly or written to script vars such as `LASTRESULT`

### Table-Driven Registry

Use when adding another selectable option, app, weather, field move, start-menu item, or behavior.

Examples:

- `start_menu_items[]`
- `pokepad2_items[]`
- `options[]`
- `field_move_checks[]`, `field_moves[]`, `field_move_descriptions[]`
- `weather_callbacks[]`

Pattern:

- add enum constant in the relevant constants/header table
- add localized strings if user-facing
- add function pointers and metadata in the registry table
- add any check/initialize/closure functions using the feature prefix

### Heap-Backed UI App

Use for full screens or menus.

Examples: `crafting_ui_state`, `bag2_state`, `options_state`, `worldmap_ui_state`, `pokepad_state`.

Pattern:

- header defines `<feature>_state_t`
- C defines `EWRAM <feature>_state_t *<feature>_state = NULL`
- public initializer allocates state and sets `callback1_set(<feature>_setup)`
- setup advances `initialization_state` or `setup_state` across frames
- idle behavior lives in a big callback or feature callback1
- exit starts a fade, waits for fade/DMA, frees resources, deletes callbacks, and restores a continuation

### Script-Facing Glue

Use for overworld scripts, specials, and `callasm`.

Examples: `special_query_present_code`, `special_overworld_effect_explosion`, `ceometria_gym_waiting_room_person_get_script`.

Pattern:

- scripts pass arguments through vars like `0x8004`, `0x8005`, `LASTRESULT`, or global buffers
- C writes script outcomes to `LASTRESULT`, `buffer0`, `strbuf`, or `overworld_script_virtual_ptr`
- C can start scripts with `overworld_script_init` and `overworld_script_set_active`
- header declares `extern const u8 ow_script_*[]` for script symbols used from C

### Persistent Gameplay State

Use for systems that survive map reloads or saves.

Examples: `csave.ceometria_gym_state`, `csave.pokeradar_person`, `csave.settings`, bag cursor arrays.

Pattern:

- add a compact struct or fields to `custom_memory` only after checking save layout
- initialize through a named public function
- use flags for one-bit world progression and vars for script-visible temporary values
- use generated constants instead of literal flag/var IDs when available

### OAM/Overworld Effect

Use for animated visual effects.

Examples: `overworld/effect/effect.c`, weather particles, cloud upstream, battle mega indicators.

Pattern:

- static `graphic`, `palette`, `sprite`, `gfx_frame`, optional `rotscale_frame`, and `oam_template`
- initializer creates OAM with `oam_new_*_search`, sets `private[]` state, starts animations, and returns `u32`
- OAM callback updates movement/palette/state and deletes/free resources when animation ends
- script-facing wrapper loads `overworld_effect_state` from vars or player position and calls `overworld_effect_new`

## Function Pointer Tables

Function-pointer structs are preferred over long conditionals when features are registered by ID:

```c
typedef struct {
    const u8 *name;
    bool (*available)();
    void (*setter)(int);
    int (*getter)();
} option_t;
```

Keep NULL meaningful: many registries check whether a function pointer exists before calling it.

## Memory And Resource Conventions

- Allocate state with `malloc_and_clear(sizeof(*state))` or `malloc_and_clear(sizeof(state_t))`.
- Free nested allocations before freeing the state pointer.
- BG maps are commonly `0x800` bytes.
- OAM resources must be hidden/deleted and their graphics/palettes freed with the local OAM helpers.
- Big callbacks use `params[0..15]` as `u16` scratch; if storing wider values, follow nearby packing/unpacking patterns.
- OAM callbacks use `private[0..7]`; files often define macros to name those slots.

## Error And Debug

- `DEBUG(...)` is common, even in hot paths; avoid adding noisy logs unless needed.
- `ERROR(...)` is used for impossible states or unknown enum values.
- Doxygen-ish comments appear in headers, but many older comments are incomplete. Prefer concise comments for new public APIs.

