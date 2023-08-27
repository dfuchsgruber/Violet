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

u8 *worldmap_tilesets[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS] = {
    [WORLDMAP_THETO] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapTiles,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapTiles,
    },
    [WORLDMAP_ISLANDS] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapTiles,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapTiles,
    },
};

u8 *worldmap_tilemaps2[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS] = {
    [WORLDMAP_THETO] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapMap,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapMap,
    },
    [WORLDMAP_ISLANDS] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapMap,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapMap,
    },
};

color_t *worldmap_pals[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS] = {
    [WORLDMAP_THETO] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapPal,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapPal,
    },
    [WORLDMAP_ISLANDS] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmapPal,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmapPal,
    },
};

color_t *(worldmap_icon_pals[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS]) = {
    [WORLDMAP_THETO] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmap_icon_thetoPal,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmap_icon_thetoPal,
    },
    [WORLDMAP_ISLANDS] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmap_icon_thetoPal,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmap_icon_thetoPal,
    },
};


u8 *(worldmap_icon_tiles[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS]) = {
    [WORLDMAP_THETO] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmap_icon_thetoTiles,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmap_icon_thetoTiles,
    },
    [WORLDMAP_ISLANDS] = {
        [WORLDMAP_LAYER_GROUND] = gfx_worldmap_icon_thetoTiles,
        [WORLDMAP_LAYER_CLOUDS] = gfx_worldmap_icon_thetoTiles,
    },
};

static u8 str_layer_clouds[] = LANGDEP(
    PSTRING("Wolken"),
    PSTRING("Clouds")
);

static u8 str_layer_continent[] = LANGDEP(
    PSTRING("Land"),
    PSTRING("Land")
);

u8 (*worldmap_layer_names[NUM_WORLDMAP_LAYERS]) = {
    [WORLDMAP_LAYER_GROUND] = str_layer_continent,
    [WORLDMAP_LAYER_CLOUDS] = str_layer_clouds,
};

static u8 str_worldmap_theto[] = LANGDEP(
    PSTRING("Theto"),
    PSTRING("Theto")
);

static u8 str_worldmap_islands[] = LANGDEP(
    PSTRING("Inseln"),
    PSTRING("Inseln")
);

u8 (*worldmap_names[NUM_WORLDMAPS]) = {
    [WORLDMAP_THETO] = str_worldmap_theto,
    [WORLDMAP_ISLANDS] = str_worldmap_islands,
};

static color_t black = {.rgb = {.red = 0, .green = 0, .blue = 0}};

extern LZ77COMPRESSED gfx_hiro_headTiles;
extern color_t gfx_hiro_headPal[16];
extern LZ77COMPRESSED gfx_hiroine_headTiles;
extern color_t gfx_hiroine_headPal[16];
extern LZ77COMPRESSED gfx_worldmap_cursorTiles;
extern color_t gfx_worldmap_cursorPal[16];
extern LZ77COMPRESSED gfx_worldmap_icon_switch_mapsTiles;
extern color_t gfx_worldmap_icon_switch_mapsPal[16];

static graphic graphics_player_head[2] = {
    {.sprite = gfx_hiro_headTiles, .tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD, .size=GRAPHIC_SIZE_4BPP(16, 16)},
    {.sprite = gfx_hiroine_headTiles, .tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD, .size=GRAPHIC_SIZE_4BPP(16, 16)},
};

static graphic graphic_cursor = {
    .sprite = gfx_worldmap_cursorTiles, .tag = WORLDMAP_UI_GFX_TAG_CURSOR,
    .size = 2 * GRAPHIC_SIZE_4BPP(16, 16)
};

static graphic graphic_icon_switch_maps = {
    .sprite = gfx_worldmap_icon_switch_mapsTiles, .tag = WORLDMAP_UI_GFX_TAG_ICON_SWITCH_MAPS,
    .size = 2 * GRAPHIC_SIZE_4BPP(16, 32)
};

static palette palettes_player_head[2] = {
    {.pal = gfx_hiro_headPal, .tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD},
    {.pal = gfx_hiroine_headPal, .tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD},
};

static palette palette_icon_switch_maps = {
    .pal = gfx_worldmap_icon_switch_mapsPal, .tag = WORLDMAP_UI_GFX_TAG_ICON_SWITCH_MAPS
};

static palette palette_cursor = {
    .pal = gfx_worldmap_cursorPal, .tag = WORLDMAP_UI_GFX_TAG_CURSOR
};

static sprite oam_player_head = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(3)
};

static sprite oam_cursor = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(2)
};

static sprite oam_icon_switch_maps = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(3)
};

static gfx_frame gfx_animation_cursor_unlocked[] = {
    {.data = 0, .duration = 0}, 
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 16},
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 16},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame gfx_animation_cursor_locked[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END, .duration = 0},
};

static gfx_frame *gfx_animations_cursor[] = {gfx_animation_cursor_unlocked, gfx_animation_cursor_locked};

static gfx_frame gfx_animation_icon_switch_maps[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END, .duration = 0},
};

static gfx_frame gfx_animation_icon_switch_maps_frame[] = {
    {.data = 4, .duration = 0}, {.data = GFX_ANIM_END, .duration = 0},
};

static gfx_frame *gfx_animations_icon_switch_map[2] = {gfx_animation_icon_switch_maps, gfx_animation_icon_switch_maps_frame};

static oam_template oam_template_player_head = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD, .pal_tag = WORLDMAP_UI_GFX_TAG_PLAYER_HEAD,
    .oam = &oam_player_head, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
};

static oam_template oam_template_cursor = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_CURSOR, .pal_tag = WORLDMAP_UI_GFX_TAG_CURSOR,
    .oam = &oam_cursor, .animation = gfx_animations_cursor,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
};

static oam_template oam_template_icon_switch_maps = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_ICON_SWITCH_MAPS, .pal_tag = WORLDMAP_UI_GFX_TAG_ICON_SWITCH_MAPS,
    .oam = &oam_icon_switch_maps, .animation = gfx_animations_icon_switch_map,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

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

u16 worldmap_flags[NUM_WORLDMAPS] = {

};

bool worldmap_ui_callback_initialize_base() {
    worldmap_ui_cb1();
    if (fading_control.active || dma3_busy(-1))
        return false;
    switch (WORLDMAP_UI_STATE->initialization_state) {
        case WORLDMAP_UI_INITIALIZATION_STATE_DATA_SETUP: {
            worldmap_locate_player();
            worldmap_set_cursor_to_player();
            WORLDMAP_UI_STATE->num_worldmaps = 0;
            for (u8 i = 0; i < ARRAY_COUNT(worldmap_flags); i++) {
                if ((worldmap_flags[i] == 0) || checkflag(worldmap_flags[i]))
                    WORLDMAP_UI_STATE->worldmaps[WORLDMAP_UI_STATE->num_worldmaps++] = i;
            }
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
            tbox_init_frame_set_style()

            return true;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_LOAD_BG_GFX: {
            pal_copy(&black, 80, sizeof(color_t));
            worldmap_ui_update_worldmap_gfx(WORLDMAP_UI_STATE->worldmaps[WORLDMAP_UI_STATE->cursor.idx], 
                WORLDMAP_UI_STATE->cursor.layer, WORLDMAP_UI_STATE->worldmap_tile_x, WORLDMAP_UI_STATE->worldmap_tile_y);
            pal_copy(tbox_palette_transparent, 15 * 16, sizeof(tbox_palette_transparent));
            return true;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_LOAD_OAM_GFX: {
            oam_palette_load_if_not_present(palettes_player_head + save2->player_is_female);
            oam_palette_load_if_not_present(&palette_cursor);
            oam_palette_load_if_not_present(&palette_icon_switch_maps);
            oam_load_graphic(graphics_player_head + save2->player_is_female);
            oam_load_graphic(&graphic_cursor);
            oam_load_graphic(&graphic_icon_switch_maps);
            WORLDMAP_UI_STATE->oam_idx_player = oam_new_forward_search(&oam_template_player_head, 0, 0, 20);
            oams[WORLDMAP_UI_STATE->oam_idx_player].flags |= OAM_FLAG_CENTERED;
            WORLDMAP_UI_STATE->oam_idx_cursor = oam_new_forward_search(&oam_template_cursor, 0, 0, 10);
            oams[WORLDMAP_UI_STATE->oam_idx_cursor].flags |= OAM_FLAG_CENTERED;
            s16 icon_switch_map_x = (s16)(8 * (WORLDMAP_UI_STATE->worldmap_tile_x + WORLDMAP_X_MARGIN + WORLDMAP_UI_STATE->icon_switch_maps_x) + 4);
            s16 icon_switch_map_y = (s16)(8 * (WORLDMAP_UI_STATE->worldmap_tile_y + WORLDMAP_Y_MARGIN + WORLDMAP_UI_STATE->icon_switch_maps_y) + 4);
            WORLDMAP_UI_STATE->oam_idx_icon_switch_map = oam_new_forward_search(&oam_template_icon_switch_maps, icon_switch_map_x, icon_switch_map_y, 11);
            oams[WORLDMAP_UI_STATE->oam_idx_icon_switch_map].flags |= OAM_FLAG_CENTERED;
            oam_gfx_anim_start_if_not_current(oams + WORLDMAP_UI_STATE->oam_idx_icon_switch_map, 0);
            WORLDMAP_UI_STATE->oam_idx_icon_switch_map_frame = oam_new_forward_search(&oam_template_icon_switch_maps, icon_switch_map_x, icon_switch_map_y, 11);
            oams[WORLDMAP_UI_STATE->oam_idx_icon_switch_map_frame].flags |= OAM_FLAG_CENTERED;
            oam_gfx_anim_start_if_not_current(oams + WORLDMAP_UI_STATE->oam_idx_icon_switch_map_frame, 1);
            oams[WORLDMAP_UI_STATE->oam_idx_icon_switch_map_frame].final_oam.attr2 = (u16)((oams[WORLDMAP_UI_STATE->oam_idx_icon_switch_map_frame].final_oam.attr2 & (~ATTR2_PRIO_MASK)) | ATTR2_PRIO(2));
            worldmap_ui_update_player_head_oam((s16)(8 * (WORLDMAP_UI_STATE->worldmap_tile_x + WORLDMAP_X_MARGIN)), 
                (s16)(8 * (WORLDMAP_UI_STATE->worldmap_tile_y +  WORLDMAP_Y_MARGIN)));
            worldmap_ui_update_cursor_oam((s16)(8 * (WORLDMAP_UI_STATE->worldmap_tile_x + WORLDMAP_X_MARGIN)), 
                (s16)(8 * (WORLDMAP_UI_STATE->worldmap_tile_y +  WORLDMAP_Y_MARGIN)));
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

void worldmap_locate_player() {
	u8 bank = save1->bank;
	u8 map_idx = save1->map;
	s16 x = save1->x_cam_orig;
	s16 y = save1->y_cam_orig;
	map_header_t *header = get_mapheader(bank, map_idx);
	int width = (int)(header->footer->width);
	int height = (int)(header->footer->height);
	WORLDMAP_UI_STATE->player.namespace = get_mapheader(bank, map_idx)->map_namespace;
	int segment_width = MAX(1, width / worldmap_positions[bank][map_idx].width);
	int segment_height = MAX(1, height / worldmap_positions[bank][map_idx].height);
	int segment_x = x / segment_width;
	int segment_y = y / segment_height;
	WORLDMAP_UI_STATE->player.x  = (u8)(worldmap_positions[bank][map_idx].x + segment_x);
	WORLDMAP_UI_STATE->player.y = (u8)(worldmap_positions[bank][map_idx].y + segment_y);
    WORLDMAP_UI_STATE->player.idx = WORLDMAP_THETO;
    WORLDMAP_UI_STATE->player.layer = WORLDMAP_LAYER_GROUND;
	// DEBUG("Map width %d, height %d\n", width, height);
	// DEBUG("Segment width %d, height %d\n", segment_width, segment_height);
	// DEBUG("Segment x %d, y %d\n", segment_x, segment_y);
}

void worldmap_set_cursor_to_player() {
    WORLDMAP_UI_STATE->cursor = WORLDMAP_UI_STATE->player;
}

void worldmap_ui_update_player_head_oam() {
    if (WORLDMAP_UI_STATE->cursor.idx != WORLDMAP_UI_STATE->player.idx ||
        WORLDMAP_UI_STATE->cursor.layer != WORLDMAP_UI_STATE->player.layer) {
        oams[WORLDMAP_UI_STATE->oam_idx_player].flags |= OAM_FLAG_INVISIBLE;
    } else {
        oams[WORLDMAP_UI_STATE->oam_idx_player].flags &= (u16)(~OAM_FLAG_INVISIBLE);
        oams[WORLDMAP_UI_STATE->oam_idx_player].x = (s16)(8 * WORLDMAP_UI_STATE->worldmap_tile_x + 
            (WORLDMAP_UI_STATE->player.x + WORLDMAP_X_MARGIN) * 8 + 4);
        oams[WORLDMAP_UI_STATE->oam_idx_player].y = (s16)(8 * WORLDMAP_UI_STATE->worldmap_tile_y + 
            (WORLDMAP_UI_STATE->player.y + WORLDMAP_Y_MARGIN) * 8 + 4);
    }
}


void worldmap_ui_update_cursor_oam() {
    if (WORLDMAP_UI_STATE->cursor_invisible) {
        oams[WORLDMAP_UI_STATE->oam_idx_cursor].flags |= OAM_FLAG_INVISIBLE;
    } else {
        oams[WORLDMAP_UI_STATE->oam_idx_cursor].flags &= (u16)(~OAM_FLAG_INVISIBLE);
        oams[WORLDMAP_UI_STATE->oam_idx_cursor].x = (s16)(8 * WORLDMAP_UI_STATE->worldmap_tile_x + 
            (WORLDMAP_UI_STATE->cursor.x + WORLDMAP_X_MARGIN) * 8 + 4);
        oams[WORLDMAP_UI_STATE->oam_idx_cursor].y = (s16)(8 * WORLDMAP_UI_STATE->worldmap_tile_y + 
            (WORLDMAP_UI_STATE->cursor.y + WORLDMAP_Y_MARGIN) * 8 + 4);
        oam_gfx_anim_start_if_not_current(oams + WORLDMAP_UI_STATE->oam_idx_cursor, WORLDMAP_UI_STATE->cursor_locked);
    }
}

void worldmap_ui_update_worldmap_gfx(u8 worldmap_idx, u8 layer, u8 x_offset, u8 y_offset) {
    lz77uncompvram(worldmap_tilesets[worldmap_idx][layer], CHARBASE(1));
    lz77uncompwram(worldmap_tilemaps2[worldmap_idx][layer], gp_tmp_buf);

    // Unpack the map to a 32 x 20 map
    bg_tile *src = (bg_tile*)gp_tmp_buf;
    bg_tile *dst = (bg_tile*)WORLDMAP_UI_STATE->bg3_map;
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
        WORLDMAP_UI_STATE->cursor_moving = false;
    }
}

static void worldmap_ui_wait_for_cursor_to_stop_moving_and_set_continuation(u8 self) {
    if (!WORLDMAP_UI_STATE->cursor_moving) {
        big_callback_set_function_to_continuation(self);
        WORLDMAP_UI_STATE->callback_cursor_moved(self);
        big_callbacks[self].function(self);
    }
}

bool worldmap_ui_handle_inputs_move_cursor(u8 self) {
    if (WORLDMAP_UI_STATE->cursor_locked)
        return false;
    if (super.keys.keys.up && WORLDMAP_UI_STATE->cursor.y > 0) {
        WORLDMAP_UI_STATE->cursor.y--;
        oams[WORLDMAP_UI_STATE->oam_idx_cursor].private[1] = (u16)(-4);
    } else if (super.keys.keys.down && WORLDMAP_UI_STATE->cursor.y < WORLDMAP_HEIGHT - 1) {
        WORLDMAP_UI_STATE->cursor.y++;
        oams[WORLDMAP_UI_STATE->oam_idx_cursor].private[1] = (u16)(4);
    } else if (super.keys.keys.left && WORLDMAP_UI_STATE->cursor.x > 0) {
        WORLDMAP_UI_STATE->cursor.x--;
        oams[WORLDMAP_UI_STATE->oam_idx_cursor].private[0] = (u16)(-4);
    } else if (super.keys.keys.right && WORLDMAP_UI_STATE->cursor.x < WORLDMAP_WIDTH - 1) {
        WORLDMAP_UI_STATE->cursor.x++;
        oams[WORLDMAP_UI_STATE->oam_idx_cursor].private[0] = (u16)(4);
    } else {
        return false;
    }
    // The cursor has moved in some direction
    DEBUG("Moving cursor to %d,%d\n", WORLDMAP_UI_STATE->cursor.x, WORLDMAP_UI_STATE->cursor.y);
    big_callback_set_function_and_continuation(self, worldmap_ui_wait_for_cursor_to_stop_moving_and_set_continuation,
         big_callbacks[self].function);
    oams[WORLDMAP_UI_STATE->oam_idx_cursor].callback = oam_callback_cursor_moving;
    WORLDMAP_UI_STATE->callback_cursor_starts_moving(self);
    WORLDMAP_UI_STATE->cursor_moving = true;
    return true;
}

void worldmap_ui_free_base() {
    free(WORLDMAP_UI_STATE);
}