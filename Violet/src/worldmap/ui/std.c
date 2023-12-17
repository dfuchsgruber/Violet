#include "types.h"
#include "worldmap.h"
#include "io.h"
#include "language.h"
#include "map/namespace.h"
#include "debug.h"
#include "fading.h"
#include "callbacks.h"
#include "agbmemory.h"
#include "dma.h"
#include "music.h"
#include "overworld/map_control.h"
#include "bios.h"

extern const LZ77COMPRESSED gfx_worldmap_ui_std_frameTiles;
extern const LZ77COMPRESSED gfx_worldmap_ui_std_frameMap;
extern const color_t gfx_worldmap_ui_std_framePal[16];

static void worldmap_ui_std_update_namespace_by_cursor_position(bool print_if_namespace_not_changed);

static const tboxdata worldmap_ui_habitat_tboxes[NUM_WORLDMAP_UI_STD_TBOXES + 1] = {
    [WORLDMAP_UI_TBOX_IDX_NAMESPACE] = {.bg_id = 2, .x = 3, .y = 2, .w = 18, .h = 2, .pal = 15, .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE] = {.bg_id = 0, .x = WORLDMAP_SWITCH_MAPS_DIALOGE_X_HABITAT, .y = WORLDMAP_SWITCH_MAPS_DIALOGE_Y_HABITAT, .w = WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH, .h = WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT, .pal = 13, .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES + 2 * 18},
    [WORLDMAP_UI_STD_TBOX_HEADER] = {.bg_id = 0, .x = 7, .y = 0, .w = 18, .h = 2, .pal = 15, .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES + 18 * 2 + WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH * WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT},
    [WORLDMAP_UI_STD_TBOX_FOOTER] = {.bg_id = 0, .x = 3, .y = 18, .w = 23, .h = 2, .pal = 14, .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES + 18 * 2 + WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH * WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT + 18 * 2},
    [NUM_WORLDMAP_UI_STD_TBOXES] = {.bg_id = 0xFF},
};

static void worldmap_ui_std_cursor_moved(__attribute__ ((unused)) u8 self) {
    worldmap_ui_std_update_namespace_by_cursor_position(false);
}

static void worldmap_ui_std_cursor_starts_moving(u8 self) {
    (void)self;
}

static const bg_config worldmap_ui_bg_configs[] = {
    [0] = { // Text layer on UI
        .bg_id = 0, .char_base = 0, .map_base = 28, .priority = 0, .size = 0,
    },
    [1] = { // Frame layer
        .bg_id = 1, .char_base = 2, .map_base = 29, .priority = 1, .size = 0,
    },
    [2] = { // Text layer for namespace label and habitat over
        .bg_id = 2, .char_base = 0, .map_base = 30, .priority = 2, .size = 0,
    },
    [3] = { // Worldmap layer
        .bg_id = 3, .char_base = 1, .map_base = 31, .priority = 3, .size = 0, .color_mode = 1,

    },
};

static const tbox_font_colormap font_colormap_transparent = {.background = 0, .body = 2, .edge = 0};
static const tbox_font_colormap font_colormap_non_transparent = {.background = 1, .body = 2, .edge = 0};
static const tbox_font_colormap font_colormap_transparent_footer = {.background = 0, .body = 1, .edge = 0};


static const u8 str_footer_key_dpad[] = PSTRING("KEY_DPAD");
static const u8 str_footer_key_b[] = PSTRING("KEY_B");

static const u8 str_footer_move[] = LANGDEP(
    PSTRING("Bewegen"),
    PSTRING("Move")
);

static const u8 str_footer_back[] = LANGDEP(
    PSTRING("Zurück"),
    PSTRING("Back")
);

static const u8 str_header[] = LANGDEP(
    PSTRING("Eine Karte von BUFFER_1"),
    PSTRING("A map of BUFFER_1")
);

static void worldmap_ui_std_update_namespace_by_cursor_position(bool print_if_namespace_not_changed) {
    const u8 *str = NULL;
    u8 namespace_idx = worldmap_get_namespace_by_pos(worldmap_ui_state->cursor.idx, worldmap_ui_state->cursor.layer,
        worldmap_ui_state->cursor.x, worldmap_ui_state->cursor.y);
    if ((namespace_idx != worldmap_ui_state->current_namespace || print_if_namespace_not_changed) 
            && namespace_idx != MAP_NAMESPACE_NONE) {
        worldmap_ui_state->current_namespace = namespace_idx;
        str = map_namespaces[MAP_NAMESPACE_TO_IDX(namespace_idx)];
    }
    if (str) {
        tbox_flush_set(WORLDMAP_UI_TBOX_IDX_NAMESPACE, 0x11);
        tbox_print_string(WORLDMAP_UI_TBOX_IDX_NAMESPACE, 2, 4, 0, 0, 0, &font_colormap_non_transparent, 0, str);
    } else {
        tbox_flush_set(WORLDMAP_UI_TBOX_IDX_NAMESPACE, 0x00);
        tbox_sync(WORLDMAP_UI_TBOX_IDX_NAMESPACE, TBOX_SYNC_SET);
    }
}

static void worldmap_ui_std_free() {
    tbox_free_all();
    free(worldmap_ui_state->bg0_map);
    free(worldmap_ui_state->bg1_map);
    free(worldmap_ui_state->bg2_map);
    free(worldmap_ui_state->bg3_map);
    worldmap_ui_free_base();
}

static void worldmap_ui_exit(u8 self) {
    if (!fading_control.active) {
        callback1_set(worldmap_ui_state->continuation);
        worldmap_ui_std_free();
        big_callback_delete(self);
    }
}

static void worldmap_ui_handle_inputs_std(u8 self) {
    if (dma3_busy(-1) || fading_control.active)
        return;
    if (worldmap_ui_handle_inputs_move_cursor(self))
        return;
    if (super.keys_new.keys.B) {
        play_sound(5);
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = worldmap_ui_exit;
    }
}

void worldmap_ui_callback_initialize_std() {
    if (!worldmap_ui_callback_initialize_base())
        return;
    switch (worldmap_ui_state->initialization_state) {
        case WORLDMAP_UI_INITIALIZATION_STATE_DATA_SETUP: {
            worldmap_ui_state->initialization_state++;
            worldmap_ui_state->callback_cursor_moved = worldmap_ui_std_cursor_moved;
            worldmap_ui_state->callback_cursor_starts_moving = worldmap_ui_std_cursor_starts_moving;
            worldmap_ui_state->worldmap_tile_x = WORLDMAP_X_OFFSET_STD;
            worldmap_ui_state->worldmap_tile_y = WORLDMAP_Y_OFFSET_STD;
            worldmap_ui_state->icon_switch_maps_x = WORLDMAP_BUTTON_SWITCH_MAPS_STD_X;
            worldmap_ui_state->icon_switch_maps_y = WORLDMAP_BUTTON_SWITCH_MAPS_STD_Y;
            worldmap_ui_state->switch_map_dialoge_x = WORLDMAP_SWITCH_MAPS_DIALOGE_X_STD;
            worldmap_ui_state->switch_map_dialoge_y = WORLDMAP_SWITCH_MAPS_DIALOGE_Y_STD;
            worldmap_ui_state->switch_maps_allowed = false;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_RESET: {
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SETUP_BGS: {
            bg_reset(0);
            bg_reset_control_and_displacement();
            bg_setup(0, worldmap_ui_bg_configs, ARRAY_COUNT(worldmap_ui_bg_configs));
            worldmap_ui_state->bg0_map = malloc_and_clear(0x800);
            bg_set_tilemap(0, worldmap_ui_state->bg0_map);
            worldmap_ui_state->bg1_map = malloc_and_clear(0x800);
            bg_set_tilemap(1, worldmap_ui_state->bg1_map);
            worldmap_ui_state->bg2_map = malloc_and_clear(0x800);
            bg_set_tilemap(2, worldmap_ui_state->bg2_map);
            worldmap_ui_state->bg3_map = malloc_and_clear(0x800);
            bg_set_tilemap(3, worldmap_ui_state->bg3_map);
            bg_display_sync();
            bg_virtual_sync(0);
            bg_virtual_sync(1);
            bg_virtual_sync(2);
            bg_virtual_sync(3);
            io_set(IO_WININ, IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(0, 1) | IO_WININOUT_BG(0, 2) | IO_WININOUT_BG(0, 3) |
                IO_WININOUT_BG(1, 0) | IO_WININOUT_BG(1, 1) | IO_WININOUT_BG(1, 2) | IO_WININOUT_BG(1, 3) | IO_WININOUT_FX(0) |
                IO_WININOUT_FX(1) | IO_WININOUT_OBJ(0) | IO_WININOUT_OBJ(1));
            io_set(IO_DISPCNT, IO_DISPCNT_OAM_CHARACTER_MAPPING_ONE_DIMENSIONAL | IO_DISPCNT_OBJ | IO_DISPCNT_WIN0);
            io_set(IO_BLDCNT, IO_BLDCNT_NONE);
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SETUP_SCANLINE: {
            dma0_reset_callback();
            io_set(IO_BLDCNT, IO_BLDCNT_BG2_FIRST | IO_BLDCNT_ALPHA_BLENDING | IO_BLDCNT_BG0_SECOND |
                    IO_BLDCNT_BG1_SECOND | IO_BLDCNT_BG2_SECOND | IO_BLDCNT_BG3_SECOND | IO_BLDCNT_OBJ_SECOND |
                    IO_BLDCNT_BACKDROP_SECOND); 
            for (int i = 0; i < 32; i++) {
                dma0_scanline_frames[0][i] = IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(10);
                dma0_scanline_frames[1][i] = IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(10);
            }
            for (int i = 32; i < 160 - 16; i++) {
                dma0_scanline_frames[0][i] = IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(0);
                dma0_scanline_frames[1][i] = IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(0);
            }
            dma0_scanline_flipflop_t flipflop = {.bytes = {.flipflop_cntrl = 1, .defaults_field_16_17 = 0}};
            dma0_init_scanline((void*)(IO_ADDRESS + IO_BLDALPHA),
                    DMA_ENABLE | DMA_TIMING_HBLANK | DMA_REPEAT | DMA_SRC_INCREMENT | DMA_DST_RELOAD |
                    DMA_SIZE(1),
                    flipflop);
                    worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SETUP_TBOXES: {
            tbox_free_all();
            tbox_sync_with_virtual_bg_and_init_all(worldmap_ui_habitat_tboxes);
            tbox_init_frame_set_style(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, 2, 13 * 16);
            for (u8 i = 0; worldmap_ui_habitat_tboxes[i].bg_id != 0xFF; i++) {
                tbox_flush_set(i, 0x00);
                tbox_flush_map(i);
                tbox_tilemap_draw(i);
                bg_virtual_sync_reqeust_push(worldmap_ui_habitat_tboxes[i].bg_id);
            }
            tbox_sync(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, TBOX_SYNC_SET);
            strcpy(buffer0, worldmap_names[worldmap_ui_state->cursor.idx]);
            string_decrypt(strbuf, str_header);
            tbox_print_string(WORLDMAP_UI_STD_TBOX_HEADER, 2, 
                (u16)((worldmap_ui_habitat_tboxes[WORLDMAP_UI_STD_TBOX_HEADER].w * 8 - string_get_width(2, strbuf, 0)) / 2), 
                1, 0, 0, &font_colormap_transparent, 0, strbuf);
            tbox_sync(WORLDMAP_UI_STD_TBOX_HEADER, TBOX_SYNC_SET);
            tbox_print_string(WORLDMAP_UI_STD_TBOX_FOOTER, 2, 82 - 76, 1, 0, 0, &font_colormap_transparent, 0, str_footer_key_dpad);
            tbox_print_string(WORLDMAP_UI_STD_TBOX_FOOTER, 2, 92 - 76, 1, 0, 0, &font_colormap_transparent_footer, 0, str_footer_move);
            tbox_print_string(WORLDMAP_UI_STD_TBOX_FOOTER, 2, 138 - 76, 1, 0, 0, &font_colormap_transparent, 0, str_footer_key_b);
            tbox_print_string(WORLDMAP_UI_STD_TBOX_FOOTER, 2, 148 - 76, 1, 0, 0, &font_colormap_transparent_footer, 0, str_footer_back);
            u8 namespace_idx = worldmap_get_namespace_by_pos(worldmap_ui_state->cursor.idx, worldmap_ui_state->cursor.layer,
                worldmap_ui_state->cursor.x, worldmap_ui_state->cursor.y);
            worldmap_ui_std_update_namespace_by_cursor_position(true);
            worldmap_ui_state->current_namespace = namespace_idx;
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_LOAD_BG_GFX: {
            pal_copy(gfx_worldmap_ui_std_framePal, 80, sizeof(gfx_worldmap_ui_std_framePal));
            lz77uncompvram(gfx_worldmap_ui_std_frameTiles, CHARBASE(2));
            lz77uncompwram(gfx_worldmap_ui_std_frameMap, worldmap_ui_state->bg1_map);
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_LOAD_OAM_GFX: {
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SHOW: {
            worldmap_ui_state->initialization_state++;
            break;
        }
        default: {
            fading_control.buffer_transfer_disabled = false;
            worldmap_ui_state->cb_idx_handle_inputs = big_callback_new(worldmap_ui_handle_inputs_std, 10);
            callback1_set(worldmap_ui_cb1);
            vblank_handler_set(worldmap_ui_vblank_callback);
            fadescreen(0xFFFFFFFF, 0, 16, 0, 0);
            break;
        }
    }
}

void worldmap_ui_std_new(void (*continuation)()) {
    worldmap_ui_state = malloc_and_clear(sizeof(worldmap_ui_state_t));
    worldmap_ui_state->continuation = continuation;
    callback1_set(worldmap_ui_callback_initialize_std);
}

void special_worldmap_ui_std() {
    worldmap_ui_std_new(map_reload);
}