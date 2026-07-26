# UI Runtime And Resource Lifecycle

`generic_callback1` advances big callbacks, fades, textboxes, OAM animation/proceeding, and a fixed engine halfword. Its VBlank path flushes shadow OAM, queued sprite graphics, palettes, DMA0, and DMA3. The overworld callback additionally advances scripts, camera/panning, tileset animation, and BG synchronization.

## Screen Contract

1. Allocate state and initialize every resource handle to a known invalid value.
2. Stage BG, textbox, menu, sprite, palette, and callback construction across frames.
3. Do not let dependent big callbacks run before construction completes.
4. Put input/application work in frame callbacks, not VBlank.
5. On every exit, stop callbacks and DMA producers before freeing their buffers.
6. Remove menus/OAM, free graphics/palettes/maps/textboxes/state, wait for fade/DMA completion, then restore the saved continuation.

Handle allocation and `0xFF` resource failures. Teardown must be safe after every partial initialization state.

## Coupled Systems

- Pokepad children must deliberately choose full free, Pokepad reinitialization, or direct overworld continuation.
- Worldmap owns cursor/player/map-switch OAM and four BG maps; info/habitat modes add tasks and resources.
- Habitat mode uses DMA0 scanline blending. Disable DMA0 and its producer callback before replacing or freeing buffers.
- Habitat scans sentinel-terminated wild data and dynamic arrays, so validate counts before sprite/list allocation.

High-risk lifecycle surfaces are worldmap habitat/info, Pokédex entry pages, incubator, treasure map, and achievements.
