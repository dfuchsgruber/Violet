# Violet UI Patterns

## Frame Callback Model

`super` has two main frame callbacks, `callback0` and `callback1`, plus vblank and other interrupt callbacks. The local UI code normally works through `callback1_set(...)`; older comments and vanilla naming may refer to callback2-style concepts, but the practical screen hook in this repo is the installed `callback1`.

`generic_callback1()` is the default UI/game pump:

- `big_callback_proceed()`
- `fading_proceed()`
- `tbox_proceed()`
- `oam_animations_proceed()`
- `oam_proceed()`

`generic_vblank_handler()` flushes queued OAM attributes, graphics, palettes, and DMA work. Custom screen callbacks should either call `generic_callback1()` when appropriate or reproduce only the same small pump pieces they need. `overworld_proceed()` is the larger overworld variant: it proceeds scripts, big callbacks, camera, OAM, fading, tileset animation, and BG copy work.

Use `callback1` for high-level frame state:

- staged setup and teardown,
- fade transitions,
- changing between screen modes,
- a small per-frame pump after setup.

Use big callbacks for ordinary UI work:

- input handlers,
- list menu processing,
- cursor movement,
- delayed callbacks,
- lightweight state updates that can run while the frame pump is active.

This distinction matters on GBA hardware. A screen that creates every BG, tbox, OAM, list menu, palette, and decompressed graphic in one frame can hitch badly or race DMA/fade state.

## Common Lifecycle

1. Public initializer allocates an `EWRAM` state pointer and stores any continuation.
2. Initializer sets `callback1_set(<feature>_setup)` and often `vblank_handler_set(generic_vblank_handler)`.
3. Setup function advances `state->initialization_state` across frames:
   - clear callbacks/fading/OAMs,
   - reset BGs and allocate tilemaps,
   - load graphics/palettes/tilemaps/textbox data,
   - create OAMs and big callbacks,
   - fade in and enter idle state.
4. Idle big callback reads `super.keys_new` or `super.keys_new_and_repeated`.
5. Exit starts a fade, waits for fade/DMA, frees resources, deletes callback(s), and restores continuation or overworld.

## Staged Setup

Prefer a setup callback that handles one bounded step per frame:

- gate at the top on `fading_is_active()`, `fading_control.active`, `dma3_busy(-1)`, or link state where the nearby code does,
- reset callbacks/OAM/fading/DMA before creating new screen resources,
- allocate BG tilemaps before `bg_set_tilemap`,
- load graphics, tilemaps, and palettes in separate states,
- initialize tboxes before any list menu that renders into them,
- create list menus and scroll indicators after their backing arrays/cursor pointers are stable,
- fade in as the last setup step,
- then switch to `generic_callback1` or a compact custom frame callback.

Good current examples:

- `Violet/src/crafting/ui.c`: `crafting_ui_setup()` deliberately does not call `big_callback_proceed()` while building the screen, because the list menu task would run while setup is incomplete. It splits BG setup, tilemap allocation, graphics, tboxes, list menu, text updates, palettes, scroll indicators, OAMs, show/sync, fade, and final `callback1_set(generic_callback1)` into states.
- `Violet/src/item/bag2/initialize.c`: `bag_cb_initialize_step()` spreads setup across many states and has a nested `bag_load_gfx()` state machine for graphics loading. Once ready, `bag_cb1()` becomes a small frame pump and `bag_idle_callback_default()` handles input as a big callback.
- `Violet/src/overworld/callback.c`: `overworld_proceed()` shows the full per-frame world pump and has benchmark hooks around expensive pieces.

Older screens may still perform more setup in one function. They can be useful references for APIs, but prefer the staged construction style above for new work.

## Construction Recipe

When adding a new UI feature, copy the closest existing feature shape:

- Full menu/app: `bag2`, `crafting_ui`, `options`, `worldmap_ui`.
- Pokepad app launched from the grid: add a `pokepad2_item` entry with flag, name, description, initializer, icon graphic, and icon palette.
- Simple start-menu command: add a `start_menu_item_t` entry and matching description.
- List-driven screen: define `list_menu_item` storage, `list_menu_template`, cursor callback, item print callback, and scroll indicators.

Define the public launcher in the header, keep setup/free helpers static in C, and add only the state fields needed by callbacks that persist across frames.

## Useful Examples

- `Violet/src/pokepad/pokepad2.c`: app grid, shortcut indicators, wallpaper list, icon OAMs, and app launch from start menu.
- `Violet/src/crafting/ui.c`: multi-BG screen with list menu, item OAM refresh, yes/no/message flow, and thorough teardown.
- `Violet/src/item/bag2/initialize.c` and `Violet/src/item/bag2/bag2.c`: staged setup, nested graphics loading, custom frame pump, idle big callback input, list menus, and scroll indicators.
- `Violet/src/worldmap/ui/*.c`: screens with stored BG map pointers and custom vblank callbacks.
- `Violet/src/start_menu/start_menu.c`: compact menu item table and description table.
- `Violet/src/ev_menu/ev_menu.c`: party selection integration and return-to-continuation behavior.
- `Violet/src/overworld/detector.c`: good OAM arrow split. A big callback recomputes detector state only when player position/map/flags change; the OAM callback only does lightweight per-frame position/animation.
- `Violet/src/map/banks/3/5/wanted_posters.c`: useful list menu and scroll indicator example, but setup is more monolithic than the preferred modern pattern.

## Textboxes

- `tboxdata` uses tile coordinates and a `start_tile`; keep tile reservations non-overlapping.
- Arrays are terminated by `{.bg_id = 0xFF}` or `TBOX_SETUP_TAIL`.
- Clear text with `tbox_flush_set`, draw with `tbox_print_string`, and sync/copy to VRAM as local code does.
- Font color maps are explicit `tbox_font_colormap` structs.
- Reuse start tiles when boxes are mutually exclusive; `bag_tboxes` does this for description/context/message boxes.

## Backgrounds

- `bg_config` sets `bg_id`, `char_base`, `map_base`, size, color mode, and priority.
- Use `bg_setup`, `bg_set_tilemap`, `bg_sync_display_and_show`, `bg_virtual_sync_reqeust_push`, `bg_copy_rectangle`, and `bg_decompress_vram` rather than direct VRAM writes unless nearby code does so.
- Tilemaps are usually 0x800 bytes for 32x32 text BG maps.

## OAM

- Static declarations usually include `graphic`, `palette`, `sprite`, and `oam_template`.
- Tag values must be unique in the active screen. Many screens define enum tag bases.
- Use `GRAPHIC_SIZE_4BPP(width, height)` and matching shape/size attrs.
- OAM callbacks can animate palettes or positions each frame; check `fading_is_active()` before palette writes during fades.
- Reused item/Pokemon icons often copy decompressed 8x8 tile chunks into an already allocated OAM tile block.
- Keep OAM callbacks lightweight. Put expensive searches, map scans, or list-state decisions in a big callback, then let the OAM callback only follow coordinates, bob, rotate, or toggle visibility.

## List Menus

`list_menu_new()` creates a list menu and returns the big-callback index that owns its state. Store that index in the screen state and use it for all later operations:

- call `list_menu_process_input(list_menu_cb_idx)` from your own idle big callback,
- call `list_menu_get_scroll_and_row(...)` before removing or rebuilding a list,
- call `list_menu_remove(...)` during teardown or when replacing the menu,
- use `list_menu_print(...)` after attribute changes that require redraw.

A `list_menu_template` usually points at:

- a stable `list_menu_item` array,
- `cursor_moved_callback` for side panels, descriptions, sounds, or OAM refresh,
- `item_print_callback` for custom row rendering,
- a tbox index that has already been initialized.

Do not create the list menu before the backing item array, tbox, and cursor state are valid. Do not process it during setup unless the screen is fully initialized.

## Arrows And Scroll Indicators

Use `scroll_indicator_new()` for standard arrow pairs. It creates the arrow OAMs and a big callback that animates/updates them. Store the returned callback index and delete it with `scroll_indicator_delete()` on teardown.

The `scroll_indicator_template` controls arrow direction, position, thresholds, and OAM tags. Pass a pointer to the cursor/scroll value that should drive visibility. Common patterns:

- up/down list arrows driven by the current row or scroll offset,
- left/right category arrows driven by a type/category index,
- quantity arrows driven by the current amount in toss/sell dialogs,
- custom callback-param pointers in small script UIs such as wanted posters.

`scroll_indicator_set_oam_priority()` adjusts arrow priority after creation when the arrows need to sit above or below a particular BG.

## Input

- Use `super.keys_new` for one-shot inputs.
- Use `super.keys_new_and_repeated` for held directional movement.
- Play selection/cancel sounds using existing sound IDs from nearby code.
- Keep `B`/cancel paths symmetrical with explicit cleanup or fade-to-exit.
- Keep input in an idle big callback. The screen callback should proceed that task through `generic_callback1` or a custom frame pump.

## UI State Fields

Common state fields:

- `initialization_state`, `setup_state`, or `gfx_initialization_state`
- callback IDs: `callback_idx`, `idle_cb_idx`, `list_menu_cb_idx`, scroll indicator callback IDs
- OAM IDs and allocated palette/tile IDs
- cursor position and items-above scroll offsets
- continuation function pointer
- arrays for list menu items and per-row strings

Use `0xFF` as the inactive callback/OAM/textbox marker where the local module does.
