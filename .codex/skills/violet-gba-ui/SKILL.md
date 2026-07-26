---
name: violet-gba-ui
description: Build or modify Violet GBA UI flows, menus, app screens, textboxes, backgrounds, OAM sprites, fading transitions, input handlers, and callback lifecycle code in systems such as Pokepad, crafting, worldmap, EV menu, PC, and start menu.
---

# Violet GBA UI

## Core Workflow

1. Start from a nearby UI module in `Violet/src/<feature>/` and its header in `Violet/include/c/<feature>/`.
2. Identify the state struct, usually an `EWRAM <feature>_state_t *`, and follow its allocation, initialization states, idle input callback, exit transition, and free path.
3. Treat the superstate callbacks as frame-level handlers. In this codebase, UI screens usually install a `callback1` with `callback1_set(...)`; that callback either stages setup/teardown or pumps shared systems like `generic_callback1`.
4. Put ordinary input loops, list menu processing, cursor updates, and deferred UI tasks in big callbacks (`big_callback_new`) rather than directly in a long-lived `callback1`.
5. Split UI construction across `initialization_state`, `setup_state`, or `gfx_initialization_state` cases so each frame does a small bounded amount of work.
6. Use `fading_is_active()` or `fading_control.active` plus `dma3_busy(-1)` gates around transitions and VRAM-heavy updates.
7. Free all BG tilemaps, OAM resources, textboxes, callbacks, and heap arrays on exit before returning to the saved continuation.

## Read When Needed

Read `references/ui-patterns.md` for concrete Pokepad/crafting/worldmap patterns, helper APIs, and lifecycle checklists.

Read `references/runtime-lifecycle.md` when auditing callbacks, partial initialization, Pokepad child transitions, worldmap modes, or DMA-backed effects.

Trigger `violet-gba-hardware` or read its references when a UI change is constrained by frame budget, VBlank/HBlank, VRAM/OAM/palette access, DMA, keypad polling, or sprite/BG hardware limits.

## Project Rules

- Allocate BG tilemaps with `malloc_and_clear(0x800)` and free them through `free(bg_get_tilemap(bg))` or stored pointers, following the local module.
- Call `tbox_free_all()` or free individual textboxes during teardown.
- Hide or delete OAMs before reusing VRAM/palette slots; free graphics and palettes with the matching local OAM helper.
- Keep text centered with `string_get_width` or `CENTERED_STR_X`; do not guess fixed pixel offsets for localized labels.
- Preserve the app's callback style: some screens run through `generic_callback1`, others set custom callback1/vblank pairs.
- Keep UI state structs compact, especially `EWRAM` structs. Use the smallest meaningful integer width and bitfields such as `u8 initialized : 1` for booleans; avoid stored `bool` fields because `bool` is 4 bytes in this codebase.
- Prefer the modern staged setup pattern from `crafting_ui` and `item/bag2`: create BGs, tboxes, list menus, scroll indicators, OAMs, and fades in separate states, then switch to `generic_callback1` or a small custom frame pump.
- During setup, avoid proceeding big callbacks until all objects they depend on are valid. `crafting_ui_setup` is explicit about this because a list menu task can run before the screen is fully initialized.
- Use `list_menu_new` for list state, store its returned big-callback index, and call `list_menu_process_input` from your own idle big callback.
- Use `scroll_indicator_new` for arrow OAM pairs and delete the returned callback on teardown.
- For list-menu scroll indicators, keep a `u16` cursor/scroll field in UI state, update it from `list_menu_get_scroll_and_row`, pass its address to `scroll_indicator_new`, and set thresholds to the first and last scrollable offsets. The common up/down indicator graphics use tags `111`; call `scroll_indicator_set_oam_priority` after creation when the arrows need a specific layer priority.
- Text rendering is expensive on GBA UI screens. Avoid printing static text every cursor update or frame; cache visibility/content state, redraw only when it changes, and prefer `tbox_fill_rectangle` to clear the smallest changed text area.

## Fast Checks

```bash
rg -n "<feature>_free|callback1_set|big_callback_new|tbox_free|bg_set_tilemap|fading" Violet/src/<feature> Violet/include/c/<feature>
nix --extra-experimental-features 'nix-command flakes' develop -c make -C Violet bld/src/<feature>/<file>.o
```
