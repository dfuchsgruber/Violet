#include "types.h"
#include "tile/coordinate.h"
#include "constants/map_namespaces.h"
#include "worldmap.h"
#include "map/header.h"
#include "constants/map_types.h"
#include "constants/map_connections.h"
#include "debug.h"
#include "math.h"
#include "save.h"
#include "fading.h"
#include "io.h"
#include "bios.h"
#include "callbacks.h"
#include "dma.h"
#include "agbmemory.h"
#include "overworld/map_control.h"
#include "flags.h"
#include "transparency.h"
#include "text.h"
#include "pokemon/names.h"
#include "language.h"
#include "pokemon/sprites.h"
#include "pokepad/pokedex/operator.h"
#include "bg.h"
#include "music.h"
#include "debug.h"
#include "menu_indicators.h"

const u8 *const worldmap_tilesets[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS] = {
    [WORLDMAP_THETO] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapTiles,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapTiles,
    },
    [WORLDMAP_ISLANDS] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapTiles,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapTiles,
    },
};

const u8 *const worldmap_tilemaps2[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS] = {
    [WORLDMAP_THETO] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapMap,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapMap,
    },
    [WORLDMAP_ISLANDS] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapMap,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapMap,
    },
};

const color_t *const worldmap_pals[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS] = {
    [WORLDMAP_THETO] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapPal,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapPal,
    },
    [WORLDMAP_ISLANDS] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapPal,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapPal,
    },
};

const color_t *const (worldmap_icon_pals[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS]) = {
    [WORLDMAP_THETO] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmap_icon_thetoPal,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmap_icon_theto_cloudsPal,
    },
    [WORLDMAP_ISLANDS] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmap_icon_thetoPal,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmap_icon_thetoPal,
    },
};


const u8 *const (worldmap_icon_tiles[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS]) = {
    [WORLDMAP_THETO] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmap_icon_thetoTiles,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmap_icon_theto_cloudsTiles,
    },
    [WORLDMAP_ISLANDS] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmap_icon_thetoTiles,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmap_icon_thetoTiles,
    },
};

static const u8 str_layer_clouds[] = LANGDEP(
    PSTRING("Wolken"),
    PSTRING("Clouds")
);

static const u8 str_layer_continent[] = LANGDEP(
    PSTRING("Land"),
    PSTRING("Land")
);

const u8 (*const worldmap_layer_names[NUM_WORLDMAP_LAYERS]) = {
    [WORLDMAP_LAYER_GROUND] = str_layer_continent,
    [WORLDMAP_LAYER_CLOUDS] = str_layer_clouds,
};

static const u8 str_worldmap_theto[] = LANGDEP(
    PSTRING("Theto"),
    PSTRING("Theto")
);

static const u8 str_worldmap_islands[] = LANGDEP(
    PSTRING("Inseln"),
    PSTRING("Inseln")
);

const u8 (*const worldmap_names[NUM_WORLDMAPS]) = {
    [WORLDMAP_THETO] = str_worldmap_theto,
    [WORLDMAP_ISLANDS] = str_worldmap_islands,
};

static const color_t black = {.rgb = {.red = 0, .green = 0, .blue = 0}};

extern const LZ77COMPRESSED gfx_hiro_headTiles;
extern const color_t gfx_hiro_headPal[16];
extern const LZ77COMPRESSED gfx_hiroine_headTiles;
extern const color_t gfx_hiroine_headPal[16];
extern const LZ77COMPRESSED gfx_worldmap_cursorTiles;
extern const color_t gfx_worldmap_cursorPal[16];
extern const LZ77COMPRESSED gfx_worldmap_icon_switch_mapsTiles;
extern const color_t gfx_worldmap_icon_switch_mapsPal[16];

static const graphic graphics_player_head[2] = {
    {.sprite = gfx_hiro_headTiles, .tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD, .size=GRAPHIC_SIZE_4BPP(16, 16)},
    {.sprite = gfx_hiroine_headTiles, .tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD, .size=GRAPHIC_SIZE_4BPP(16, 16)},
};

static const graphic graphic_cursor = {
    .sprite = gfx_worldmap_cursorTiles, .tag = WORLDMAP_UI_GFX_TAG_CURSOR,
    .size = 2 * GRAPHIC_SIZE_4BPP(16, 16)
};

static const graphic graphic_icon_switch_maps = {
    .sprite = gfx_worldmap_icon_switch_mapsTiles, .tag = WORLDMAP_UI_GFX_TAG_ICON_SWITCH_MAPS,
    .size = 2 * GRAPHIC_SIZE_4BPP(16, 32)
};

static const palette palettes_player_head[2] = {
    {.pal = gfx_hiro_headPal, .tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD},
    {.pal = gfx_hiroine_headPal, .tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD},
};

static const palette palette_icon_switch_maps = {
    .pal = gfx_worldmap_icon_switch_mapsPal, .tag = WORLDMAP_UI_GFX_TAG_ICON_SWITCH_MAPS
};

static const palette palette_cursor = {
    .pal = gfx_worldmap_cursorPal, .tag = WORLDMAP_UI_GFX_TAG_CURSOR
};

static const sprite oam_player_head = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(3)
};

static const sprite oam_cursor = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(2)
};

static const sprite oam_icon_switch_maps = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(3)
};

static const sprite oam_switch_map_icon = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_64_64, .attr2 = ATTR2_PRIO(0),
};

static const gfx_frame gfx_animation_cursor_unlocked[] = {
    {.data = 0, .duration = 0}, 
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 16},
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 16},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static const gfx_frame gfx_animation_cursor_locked[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END, .duration = 0},
};

static const gfx_frame *const gfx_animations_cursor[] = {gfx_animation_cursor_unlocked, gfx_animation_cursor_locked};

static const gfx_frame gfx_animation_icon_switch_maps[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END, .duration = 0},
};

static const gfx_frame gfx_animation_icon_switch_maps_frame[] = {
    {.data = 4, .duration = 0}, {.data = GFX_ANIM_END, .duration = 0},
};

static const gfx_frame *const gfx_animations_icon_switch_map[2] = {gfx_animation_icon_switch_maps, gfx_animation_icon_switch_maps_frame};

static const oam_template oam_template_player_head = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD, .pal_tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD,
    .oam = &oam_player_head, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
};

static const oam_template oam_template_cursor = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_CURSOR, .pal_tag = WORLDMAP_UI_GFX_TAG_CURSOR,
    .oam = &oam_cursor, .animation = gfx_animations_cursor,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
};

static const oam_template oam_template_icon_switch_maps = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_ICON_SWITCH_MAPS, .pal_tag = WORLDMAP_UI_GFX_TAG_ICON_SWITCH_MAPS,
    .oam = &oam_icon_switch_maps, .animation = gfx_animations_icon_switch_map,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

void oam_callback_switch_map_icon(__attribute__((unused)) oam_object *self) {
    color_t red = {.rgb = {.red = 31, .blue = 0, .green = 0}};
    if (worldmap_ui_state->red_overlay_should_be_active_on_worldmap[worldmap_ui_state->cursor_switch_maps.idx][worldmap_ui_state->cursor_switch_maps.layer]) {
        u8 pal_idx = oam_palette_get_index(WORLDMAP_UI_GFX_TAG_SWITCH_MAP_MINIMAP);
        pal_alpha_blending((u16)(256 + 16 * pal_idx), 16, worldmap_ui_state->red_overlay_intensity, red);
    }
}


static const oam_template oam_template_switch_map_icon = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_SWITCH_MAP_MINIMAP, .pal_tag = WORLDMAP_UI_GFX_TAG_SWITCH_MAP_MINIMAP,
    .oam = &oam_switch_map_icon, .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_callback_switch_map_icon,
};

const u16 worldmap_flags[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS] = {
    [WORLDMAP_THETO] = {
    },
    [WORLDMAP_ISLANDS] = {
    },
};

bool worldmap_cursor_move(s8 direction_worldmap_idx, s8 direction_layer, worldmap_cursor_t *cursor, u8 *dst_worldmap_idx, u8 *dst_layer) {
    int idx = cursor->idx;
    int layer = cursor->layer;
    while(true) {
        idx += direction_worldmap_idx;
        layer += direction_layer;
        if (idx >= 0 && layer >= 0 && idx < NUM_WORLDMAPS && layer < NUM_WORLDMAP_LAYERS) {
            u16 flag = worldmap_flags[idx][layer];
            if (flag == WORLDMAP_FLAG_EMPTY_SLOT)
                continue;
            else if (flag == 0 || checkflag(flag)) {
                *dst_worldmap_idx = (u8)idx;
                *dst_layer = (u8)layer;
                return true;
            }
        } else {
            return false;
        }
    }
}


void worldmap_ui_cb1() {
    big_callback_proceed();
    tbox_proceed();
    oam_animations_proceed();
    oam_proceed();
    bg_virtual_sync_reqeust_proceed();
    fading_proceed();
}

void worldmap_ui_vblank_callback() {
    oam_attributes_copy();
    graphic_queue_proceed();
    pal_proceed();
    dma0_proceed();
    dma3_queue_proceed();
}

bool worldmap_ui_callback_initialize_base() {
    worldmap_ui_cb1();
    if (fading_control.active || dma3_busy(-1))
        return false;
    switch (worldmap_ui_state->initialization_state) {
        case WORLDMAP_UI_INITIALIZATION_STATE_DATA_SETUP: {
            worldmap_locate_player();
            worldmap_set_cursor_to_player();
            return true;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_RESET: {
            reset_hblank_and_vblank_callbacks();
            bg_vritual_sync_reset();
            dma0_reset_callback();
            oam_palette_allocation_reset();
            fading_cntrl_reset();
            fading_control.buffer_transfer_disabled = true;
            oam_reset();
            big_callback_delete_all();
            bg_reset_control_and_displacement();
            big_callback_delete_all();
            return true;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SETUP_BGS: {
            return true;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SETUP_TBOXES: {
            return true;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_LOAD_BG_GFX: {
            pal_copy(&black, 80, sizeof(color_t));
            worldmap_ui_update_worldmap_gfx(worldmap_ui_state->cursor.idx, 
                worldmap_ui_state->cursor.layer, worldmap_ui_state->worldmap_tile_x, worldmap_ui_state->worldmap_tile_y);
            pal_copy(tbox_palette_transparent, 15 * 16, sizeof(tbox_palette_transparent));
            return true;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_LOAD_OAM_GFX: {
            oam_palette_load_if_not_present(palettes_player_head + save2->player_is_female);
            oam_palette_load_if_not_present(&palette_cursor);
            oam_palette_load_if_not_present(&palette_icon_switch_maps);
            worldmap_ui_state->switch_map_icon_pal_idx = oam_allocate_palette(WORLDMAP_UI_GFX_TAG_SWITCH_MAP_MINIMAP);
            oam_load_graphic(graphics_player_head + save2->player_is_female);
            oam_load_graphic(&graphic_cursor);
            oam_load_graphic(&graphic_icon_switch_maps);
            worldmap_ui_state->oam_idx_player = oam_new_forward_search(&oam_template_player_head, 0, 0, 20);
            oams[worldmap_ui_state->oam_idx_player].flags |= OAM_FLAG_CENTERED;
            worldmap_ui_state->oam_idx_cursor = oam_new_forward_search(&oam_template_cursor, 0, 0, 10);
            oams[worldmap_ui_state->oam_idx_cursor].flags |= OAM_FLAG_CENTERED;
            if (worldmap_ui_state->switch_maps_allowed) {
                s16 icon_switch_map_x = (s16)(8 * (worldmap_ui_state->worldmap_tile_x + WORLDMAP_X_MARGIN + worldmap_ui_state->icon_switch_maps_x) + 4);
                s16 icon_switch_map_y = (s16)(8 * (worldmap_ui_state->worldmap_tile_y + WORLDMAP_Y_MARGIN + worldmap_ui_state->icon_switch_maps_y) + 4);
                worldmap_ui_state->oam_idx_icon_switch_map = oam_new_forward_search(&oam_template_icon_switch_maps, icon_switch_map_x, icon_switch_map_y, 11);
                oams[worldmap_ui_state->oam_idx_icon_switch_map].flags |= OAM_FLAG_CENTERED;
                oam_gfx_anim_start_if_not_current(oams + worldmap_ui_state->oam_idx_icon_switch_map, 0);
                worldmap_ui_state->oam_idx_icon_switch_map_frame = oam_new_forward_search(&oam_template_icon_switch_maps, icon_switch_map_x, icon_switch_map_y, 11);
                oams[worldmap_ui_state->oam_idx_icon_switch_map_frame].flags |= OAM_FLAG_CENTERED;
                oam_gfx_anim_start_if_not_current(oams + worldmap_ui_state->oam_idx_icon_switch_map_frame, 1);
                oams[worldmap_ui_state->oam_idx_icon_switch_map_frame].final_oam.attr2 = (u16)((oams[worldmap_ui_state->oam_idx_icon_switch_map_frame].final_oam.attr2 & (~ATTR2_PRIO_MASK)) | ATTR2_PRIO(2));
            }
            worldmap_ui_update_player_head_oam((s16)(8 * (worldmap_ui_state->worldmap_tile_x + WORLDMAP_X_MARGIN)), 
                (s16)(8 * (worldmap_ui_state->worldmap_tile_y +  WORLDMAP_Y_MARGIN)));
            worldmap_ui_update_cursor_oam((s16)(8 * (worldmap_ui_state->worldmap_tile_x + WORLDMAP_X_MARGIN)), 
                (s16)(8 * (worldmap_ui_state->worldmap_tile_y +  WORLDMAP_Y_MARGIN)));
            worldmap_ui_state->switch_map_icon_base_tile = oam_vram_alloc(GRAPHIC_SIZE_4BPP_TO_NUM_TILES(64, 64));
            oam_vram_allocation_table_add(WORLDMAP_UI_GFX_TAG_SWITCH_MAP_MINIMAP, 
                worldmap_ui_state->switch_map_icon_base_tile, GRAPHIC_SIZE_4BPP_TO_NUM_TILES(64, 64));
            return true;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SHOW: {
            pal_set_all_to_black();
            fading_control.buffer_transfer_disabled = false;
            // These sync 
            bg_sync_display_and_show(0);
            bg_sync_display_and_show(1);
            bg_sync_display_and_show(2);
            bg_sync_display_and_show(3);
            bg_display_sync();
            // Those requests are picked up by the vblank callback and copies the tilemaps
            bg_virtual_sync_reqeust_push(0);
            bg_virtual_sync_reqeust_push(1);
            bg_virtual_sync_reqeust_push(2);
            bg_virtual_sync_reqeust_push(3);
            return true;
        }
        default: {
            return true;
        }
    }
}

void worldmap_set_cursor_to_player() {
    worldmap_ui_state->cursor = worldmap_ui_state->player;
}

void worldmap_ui_update_player_head_oam() {
    if (worldmap_ui_state->cursor.idx != worldmap_ui_state->player.idx ||
        worldmap_ui_state->cursor.layer != worldmap_ui_state->player.layer) {
        oams[worldmap_ui_state->oam_idx_player].flags |= OAM_FLAG_INVISIBLE;
    } else {
        oams[worldmap_ui_state->oam_idx_player].flags &= (u16)(~OAM_FLAG_INVISIBLE);
        oams[worldmap_ui_state->oam_idx_player].x = (s16)(8 * worldmap_ui_state->worldmap_tile_x + 
            (worldmap_ui_state->player.x + WORLDMAP_X_MARGIN) * 8 + 4);
        oams[worldmap_ui_state->oam_idx_player].y = (s16)(8 * worldmap_ui_state->worldmap_tile_y + 
            (worldmap_ui_state->player.y + WORLDMAP_Y_MARGIN) * 8 + 4);
    }
}


void worldmap_ui_update_cursor_oam() {
    if (worldmap_ui_state->cursor_invisible) {
        oams[worldmap_ui_state->oam_idx_cursor].flags |= OAM_FLAG_INVISIBLE;
    } else {
        oams[worldmap_ui_state->oam_idx_cursor].flags &= (u16)(~OAM_FLAG_INVISIBLE);
        oams[worldmap_ui_state->oam_idx_cursor].x = (s16)(8 * worldmap_ui_state->worldmap_tile_x + 
            (worldmap_ui_state->cursor.x + WORLDMAP_X_MARGIN) * 8 + 4);
        oams[worldmap_ui_state->oam_idx_cursor].y = (s16)(8 * worldmap_ui_state->worldmap_tile_y + 
            (worldmap_ui_state->cursor.y + WORLDMAP_Y_MARGIN) * 8 + 4);
        oam_gfx_anim_start_if_not_current(oams + worldmap_ui_state->oam_idx_cursor, worldmap_ui_state->cursor_locked);
    }
}

void worldmap_ui_update_worldmap_gfx(u8 worldmap_idx, u8 layer, u8 x_offset, u8 y_offset) {
    lz77uncompvram(worldmap_tilesets[worldmap_idx][layer], CHARBASE(1));
    lz77uncompwram(worldmap_tilemaps2[worldmap_idx][layer], gp_tmp_buf);

    // Unpack the map to a 32 x 20 map
    bg_tile *src = (bg_tile*)gp_tmp_buf;
    bg_tile *dst = (bg_tile*)worldmap_ui_state->bg3_map;
    for (int row = 0; row < WORLDMAP_TOTAL_HEIGHT; row++) {
        cpuset(src + WORLDMAP_TOTAL_WIDTH * row, dst + 32 * (row + y_offset) + x_offset, 
            WORLDMAP_TOTAL_WIDTH * sizeof(bg_tile));
    }
    pal_copy(worldmap_pals[worldmap_idx][layer], 0x0, 80);
}

static void oam_callback_cursor_moving(oam_object *self) {
    s16 *dx = (s16*)(self->private + 0);
    s16 *dy = (s16*)(self->private + 1);
    if (*dx != 0 || *dy != 0) {
        if (*dx > 0) {
            self->x2 = (s16)(self->x2 + 2);
            (*dx)--;
        } else if (*dx < 0) {
            self->x2 = (s16)(self->x2 - 2);
            (*dx)++;
        }
        if (*dy > 0) {
            self->y2 = (s16)(self->y2 + 2);
            (*dy)--;
        } else if (*dy < 0) {
            self->y2 = (s16)(self->y2 - 2);
            (*dy)++;
        }
    } else {
        self->callback = oam_null_callback;
        worldmap_ui_state->cursor_moving = false;
    }
}

static void worldmap_ui_wait_for_cursor_to_stop_moving_and_set_continuation(u8 self) {
    if (!worldmap_ui_state->cursor_moving) {
        big_callback_set_function_to_continuation(self);
        worldmap_ui_state->callback_cursor_moved(self);
        big_callbacks[self].function(self);
    }
}

bool worldmap_ui_handle_inputs_move_cursor(u8 self) {
    if (worldmap_ui_state->cursor_locked)
        return false;
    if (super.keys.keys.up && worldmap_ui_state->cursor.y > 0) {
        worldmap_ui_state->cursor.y--;
        oams[worldmap_ui_state->oam_idx_cursor].private[1] = (u16)(-4);
    } else if (super.keys.keys.down && worldmap_ui_state->cursor.y < WORLDMAP_HEIGHT - 1) {
        worldmap_ui_state->cursor.y++;
        oams[worldmap_ui_state->oam_idx_cursor].private[1] = (u16)(4);
    } else if (super.keys.keys.left && worldmap_ui_state->cursor.x > 0) {
        worldmap_ui_state->cursor.x--;
        oams[worldmap_ui_state->oam_idx_cursor].private[0] = (u16)(-4);
    } else if (super.keys.keys.right && worldmap_ui_state->cursor.x < WORLDMAP_WIDTH - 1) {
        worldmap_ui_state->cursor.x++;
        oams[worldmap_ui_state->oam_idx_cursor].private[0] = (u16)(4);
    } else {
        return false;
    }
    // The cursor has moved in some direction
    DEBUG("Moving cursor to %d,%d\n", worldmap_ui_state->cursor.x, worldmap_ui_state->cursor.y);
    big_callback_set_function_and_continuation(self, worldmap_ui_wait_for_cursor_to_stop_moving_and_set_continuation,
         big_callbacks[self].function);
    oams[worldmap_ui_state->oam_idx_cursor].callback = oam_callback_cursor_moving;
    worldmap_ui_state->callback_cursor_starts_moving(self);
    worldmap_ui_state->cursor_moving = true;
    return true;
}

static const tbox_font_colormap font_colormap_switch_maps = {.background = 0, .body = 2, .edge = 3};

static void worldmap_ui_switch_maps_update_icon(u8 self) {
    lz77uncompvram(worldmap_icon_tiles[worldmap_ui_state->cursor_switch_maps.idx][worldmap_ui_state->cursor_switch_maps.layer],
        OAMCHARBASE(worldmap_ui_state->switch_map_icon_base_tile));
    oams[worldmap_ui_state->switch_map_icon_oam_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
    pal_copy(worldmap_icon_pals[worldmap_ui_state->cursor_switch_maps.idx][worldmap_ui_state->cursor_switch_maps.layer],
        (u16)(256 + 16 * worldmap_ui_state->switch_map_icon_pal_idx), 16 * sizeof(color_t));
    big_callback_set_function_to_continuation(self);
}

static void worldmap_ui_switch_maps_update_scroll_indicators() {
    u8 idx, layer;
    scroll_indicator_state *state_idx = (scroll_indicator_state*)(big_callbacks[worldmap_ui_state->switch_map_dialoge_scroll_indicator_idx_cb_idx].params);
    if (worldmap_cursor_move(-1, 0, &worldmap_ui_state->cursor_switch_maps, &idx, &layer))
        oams[state_idx->arrow0_oam_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
    else
        oams[state_idx->arrow0_oam_idx].flags |= OAM_FLAG_INVISIBLE;
    if (worldmap_cursor_move(1, 0, &worldmap_ui_state->cursor_switch_maps, &idx, &layer))
        oams[state_idx->arrow1_oam_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
    else
        oams[state_idx->arrow1_oam_idx].flags |= OAM_FLAG_INVISIBLE;
    scroll_indicator_state *state_layer = (scroll_indicator_state*)(big_callbacks[worldmap_ui_state->switch_map_dialoge_scroll_indicator_layer_cb_idx].params);
    if (worldmap_cursor_move(0, -1, &worldmap_ui_state->cursor_switch_maps, &idx, &layer))
        oams[state_layer->arrow0_oam_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
    else
        oams[state_layer->arrow0_oam_idx].flags |= OAM_FLAG_INVISIBLE;
    if (worldmap_cursor_move(0, 1, &worldmap_ui_state->cursor_switch_maps, &idx, &layer))
        oams[state_layer->arrow1_oam_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
    else
        oams[state_layer->arrow1_oam_idx].flags |= OAM_FLAG_INVISIBLE;
}

static void worldmap_ui_switch_maps_update(u8 self, void (*continuation)(u8)) {
    tbox_flush_set(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, 0x11);
    const u8 *name = worldmap_names[worldmap_ui_state->cursor_switch_maps.idx];
    tbox_print_string(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, 2, 
        (u16)((WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH * 8 - string_get_width(2, name, 0)) / 2),
        0, 0, 0, &font_colormap_switch_maps, 0, name);
    const u8 *layer_name = worldmap_layer_names[worldmap_ui_state->cursor_switch_maps.layer];
    tbox_print_string(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, 0, 
        (u16)((WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH * 8 - string_get_width(0, layer_name, 0)) / 2),
        11, 0, 0, &font_colormap_switch_maps, 0, layer_name);
    oams[worldmap_ui_state->switch_map_icon_oam_idx].flags |= OAM_FLAG_INVISIBLE;

    // Update scroll indicators
    worldmap_ui_switch_maps_update_scroll_indicators();

    big_callback_set_function_and_continuation(self, worldmap_ui_switch_maps_update_icon, continuation);

}

static void worldmap_ui_switch_maps_dialoge_scroll_indicators_dummy_callback(__attribute__((unused)) u8 self) {}

void worldmap_ui_switch_maps_dialoge_new(u8 self, void (*handle_inputs_callback)(u8)) {
    // dialoge textbox
    tbox_flush_set(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, 0x11);
    worldmap_ui_state->cursor_switch_maps = worldmap_ui_state->cursor;
    tbox_tilemap_draw(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE);
    tbox_frame_draw_outer(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, 2, 13);
    
    // oam for the minimap
    worldmap_ui_state->switch_map_icon_oam_idx = oam_new_forward_search(&oam_template_switch_map_icon,
        (s16)((worldmap_ui_state->switch_map_dialoge_x + (WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH / 2)) * 8),
        (s16)((worldmap_ui_state->switch_map_dialoge_y + (WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT / 2) + 2) * 8), 0);
    oams[worldmap_ui_state->switch_map_icon_oam_idx].flags |= OAM_FLAG_CENTERED;
    tbox_copy_to_vram(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, TBOX_COPY_TILEMAP);

    // scroll indicators
    scroll_indicator_template template_idx = {
        .arrow0_threshold = 0, 
        .arrow1_threshold = NUM_WORLDMAPS, 
        .arrow0_type = SCROLL_ARROW_LEFT, .arrow1_type = SCROLL_ARROW_RIGHT,
        .arrow0_x = (u8)(8 * (worldmap_ui_state->switch_map_dialoge_x + WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH / 2) - 32), 
        .arrow1_x = (u8)(8 * (worldmap_ui_state->switch_map_dialoge_x + WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH / 2) + 32),
        .arrow0_y = (u8)(8 * (worldmap_ui_state->switch_map_dialoge_y + WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT / 2) + 16),
        .arrow1_y = (u8)(8 * (worldmap_ui_state->switch_map_dialoge_y + WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT / 2) + 16),
        .pal_tag = 112, .tiles_tag = 112,
    };
    worldmap_ui_state->switch_map_dialoge_scroll_indicator_idx_cb_idx = scroll_indicator_new(&template_idx, NULL);
    big_callbacks[worldmap_ui_state->switch_map_dialoge_scroll_indicator_idx_cb_idx].function = worldmap_ui_switch_maps_dialoge_scroll_indicators_dummy_callback;
    scroll_indicator_template template_layer = {
        .arrow0_threshold = 0, 
        .arrow1_threshold = NUM_WORLDMAP_LAYERS, 
        .arrow0_type = SCROLL_ARROW_UP, .arrow1_type = SCROLL_ARROW_DOWN,
        .arrow0_x = (u8)(8 * (worldmap_ui_state->switch_map_dialoge_x + WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH / 2)), 
        .arrow1_x = (u8)(8 * (worldmap_ui_state->switch_map_dialoge_x + WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH / 2)),
        .arrow0_y = (u8)(8 * (worldmap_ui_state->switch_map_dialoge_y + 2 + WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT / 2) - 24),
        .arrow1_y = (u8)(8 * (worldmap_ui_state->switch_map_dialoge_y + 2 + WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT / 2) + 24),
        .pal_tag = 112, .tiles_tag = 112,
    };
    worldmap_ui_state->switch_map_dialoge_scroll_indicator_layer_cb_idx = scroll_indicator_new(&template_layer, NULL);
    big_callbacks[worldmap_ui_state->switch_map_dialoge_scroll_indicator_layer_cb_idx].function = worldmap_ui_switch_maps_dialoge_scroll_indicators_dummy_callback;

    worldmap_ui_switch_maps_update(self, handle_inputs_callback);
}

bool worldmap_ui_switch_maps_dialoge_process_input(u8 self) {
    if (dma3_busy(-1))
        return false;
    s8 direction_worldmap_idx = 0, direction_layer = 0;
    if (super.keys_new.keys.left)
        direction_worldmap_idx = -1;
    else if (super.keys_new.keys.right)
        direction_worldmap_idx = 1;
    else if (super.keys_new.keys.down)
        direction_layer = 1;
    else if (super.keys_new.keys.up)
        direction_layer = -1;
    else 
        return false;
    // move the cursor
    u8 worldmap_idx, layer;
    if (worldmap_cursor_move(direction_worldmap_idx, direction_layer, &worldmap_ui_state->cursor_switch_maps,
        &worldmap_idx, &layer)) {
        play_sound(5);
        worldmap_ui_state->cursor_switch_maps.idx = worldmap_idx;
        worldmap_ui_state->cursor_switch_maps.layer = layer;
        worldmap_ui_switch_maps_update(self, big_callbacks[self].function);
        return true;
    } else {
        return false;
    }
}

void worldmap_ui_switch_maps_dialoge_delete() {
    oam_delete(oams + worldmap_ui_state->switch_map_icon_oam_idx);
    tbox_flush_map_and_frame(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE);
    tbox_copy_to_vram(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, TBOX_COPY_TILEMAP);
    scroll_indicator_delete(worldmap_ui_state->switch_map_dialoge_scroll_indicator_idx_cb_idx);
    scroll_indicator_delete(worldmap_ui_state->switch_map_dialoge_scroll_indicator_layer_cb_idx);
}

void worldmap_ui_free_base() {
    free(worldmap_ui_state);
}