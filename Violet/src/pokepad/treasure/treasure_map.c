#include "types.h"
#include "flags.h"
#include "vars.h"
#include "pokepad/treasure_map.h"
#include "fading.h"
#include "dma.h"
#include "bg.h"
#include "text.h"
#include "callbacks.h"
#include "overworld/map_control.h"
#include "agbmemory.h"
#include "bios.h"
#include "map/header.h"
#include "debug.h"
#include "language.h"
#include "music.h"
#include "pokepad/pokepad2.h"
#include "menu_indicators.h"
#include "overworld/script.h"


static u8 treasure_map_context_has_scroll_indicators[NUM_TREASURE_MAP_CONTEXTS] = {
    [TREASURE_MAP_CONTEXT_NONE] = true,
};

static void treasure_map_free() {
    list_menu_remove(TREASURE_MAP_STATE->list_menu_cb_idx, &fmem.treasure_map_cursor_position, &fmem.treasure_map_items_above);
    free(TREASURE_MAP_STATE->bg0_map);
    free(TREASURE_MAP_STATE->bg1_map);
    free(TREASURE_MAP_STATE->bg2_map);
    free(TREASURE_MAP_STATE->bg3_map);
    oam_free(oams + TREASURE_MAP_STATE->oam_idx_cross);
    if (treasure_map_context_has_scroll_indicators[TREASURE_MAP_STATE->context])
        scroll_indicator_delete(TREASURE_MAP_STATE->scroll_indicator_cb_idx);
    tbox_free_all();
    free(TREASURE_MAP_STATE);
}

static void treasure_map_continue_ow_script(u8 self) {
    if (!fading_control.active && super.callback1 == overworld_callback1) {
        big_callback_delete(self);
    }
}

static void treasure_map_free_callback(u8 self) {
    if (!fading_control.active) {
        if (TREASURE_MAP_STATE->from_outdoor) {
            callback1_set(map_reload);
            overworld_script_resume();
            big_callbacks[self].function = treasure_map_continue_ow_script;
        } else {
            callback1_set(pokepad2_callback_initialize);
            big_callback_delete(self);
        }
        treasure_map_free();
    }
}

static void treasure_map_idle_callback_none(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    int item_idx = list_menu_process_input(TREASURE_MAP_STATE->list_menu_cb_idx);
    list_menu_get_scroll_and_row(TREASURE_MAP_STATE->list_menu_cb_idx, &fmem.treasure_map_cursor_position, &fmem.treasure_map_items_above);
    if (item_idx >= NUM_TREASURE_MAPS || super.keys_new.keys.B) {
        play_sound(5);
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = treasure_map_free_callback;
    }
}

static void treasure_map_idle_callback_show(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    list_menu_get_scroll_and_row(TREASURE_MAP_STATE->list_menu_cb_idx, &fmem.treasure_map_cursor_position, &fmem.treasure_map_items_above);
    if (super.keys_new.keys.A || super.keys_new.keys.B) {
        play_sound(5);
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = treasure_map_free_callback;
    }
}

static void (*treasure_map_idle_callbacks[NUM_TREASURE_MAP_CONTEXTS])(u8) = {
    [TREASURE_MAP_CONTEXT_NONE] = treasure_map_idle_callback_none,
    [TREASURE_MAP_CONTEXT_SHOW] = treasure_map_idle_callback_show,
};

static void treasure_map_cb1() {
    big_callback_proceed();
    tbox_proceed();
    oam_animations_proceed();
    oam_proceed();
    bg_virtual_sync_reqeust_proceed();
    fading_proceed();
}

static void treasure_map_vblank_callback() {
    oam_attributes_copy();
    graphic_queue_proceed();
    pal_proceed();
    dma0_proceed();
    dma3_queue_proceed();
}

static bg_config treasure_map_bg_configs[] = {
    [0] = {
        .bg_id = 0, .char_base = 0, .map_base = 28, .priority = 1,
    },
    [1] = {
        .bg_id = 1, .char_base = 0, .map_base = 29, .priority = 2,
    },
    [2] = {
        .bg_id = 2, .char_base = 0, .map_base = 30, .priority = 3,
    },
    [3] = {
        .bg_id = 3, .char_base = 2, .map_base = 31, .priority = 0, .size = 0,
    },
};

static tboxdata treasure_map_tboxes[NUM_TREASURE_MAP_TBOXES + 1] = {
    [TREASURE_MAP_TBOX_LIST] = {.bg_id = 3, .x = 1, .y = 1, .w = 7, .h = 18, .start_tile = 400, .pal = 15},
    [NUM_TREASURE_MAP_TBOXES] = {.bg_id = 0xFF},
};

enum {
    RESET = 0,
    SETUP_BGS,
    SETUP_TBOXES,
    SETUP_LIST,
    LOAD_GFX,
    LOAD_OAM_GFX,
    SETUP_OAM,
    SETUP_SCROLL_INDICATORS,
    SHOW,
};

static u8 str_text_small[] = PSTRING("FONT_SIZE_SMALL");
static u8 str_xf9_x08_clear_to_x1[] = {0xF9, 0x8, 0xFC, 0x11, 0x3, 0xFF};
static u8 str_clear_to_xtm[] = PSTRING("CLEAR_TO\x17");
static u8 str_space[] = PSTRING(" ");
static u8 str_font_size_big[] = PSTRING("FONT_SIZE_BIG");
static u8 str_question_mark[] = PSTRING("???");
static u8 str_back[] = LANGDEP(PSTRING("Zurück"), PSTRING("Cancel"));

static void treasure_map_format_string(size_t treasure_map_idx, bool map_found, bool treasure_found, u8 *dst) {
    (void)treasure_found;
    if (map_found) {
        strcpy(strbuf, str_text_small);
        strcat(strbuf, str_xf9_x08_clear_to_x1);
        itoa(buffer0, (int)treasure_map_idx + 1, ITOA_PAD_ZEROS, 2);
        strcat(strbuf, buffer0);
        strcat(strbuf, str_clear_to_xtm);
        strcat(strbuf, str_space);
        strcat(strbuf, str_font_size_big);
    } else {
        strcpy(strbuf, str_question_mark);
    }
    // TODO
    strcpy(dst, strbuf);
}

static void treasure_map_update_treasure_map_tilemap(bool treasure_map_visible) {
    bg_tile *src = (!treasure_map_visible) ? gfx_treasure_map_ui_backgroundMap + 32 * 32 : gfx_treasure_map_ui_backgroundMap;
    for (int x = 8; x <= 30; x++) {
        for (int y = 0; y <= 20; y++) {
            TREASURE_MAP_STATE->bg3_map[32 * y + x] = src[32 * y + x];
        }
    }
    bg_virtual_sync_reqeust_push(3);
}

static color_t map_over = {.rgb = {.red = 31, .green = 26, .blue = 13}};
static color_t black = {.rgb = {.red = 0, .green = 0, .blue = 0}};

static inline color_t treasure_map_minimize_color_loss(color_t c, color_t target) {
    // finds a color that is linearly dependent on `target`, i.e. a coefficient coef * target that is closest to `c`
    // the optimal coef should be alpha = <c, target> / <target, target>
    int coef = (c.rgb.red * target.rgb.red + c.rgb.blue * target.rgb.blue + c.rgb.green + target.rgb.green) << 5;
    coef /= target.rgb.red * target.rgb.red + target.rgb.blue + target.rgb.blue + target.rgb.green + target.rgb.green;
    color_t result = {
        .rgb = {
            .red = (u16)(MIN(31, coef * target.rgb.red >> 5) & 31),
            .blue = (u16)(MIN(31, coef * target.rgb.blue >> 5) & 31),
            .green = (u16)(MIN(31, coef * target.rgb.green >> 5) & 31),
        }
    };
    return result;
}

static void treasure_map_minimize_palette_loss(u16 dst_color, u16 num_colors) {
    for (int i = 0; i < num_colors; i++) {
        pals[dst_color + i] = treasure_map_minimize_color_loss(pal_restore[dst_color + i], map_over);
    }
}

static void treasure_map_update_callback(u8 self) {
    u16 *state = big_callbacks[self].params + 1;
    u16 treasure_map_idx = big_callbacks[self].params[0];
    map_header_t *header = get_mapheader(treasure_maps[treasure_map_idx].bank, treasure_maps[treasure_map_idx].map_idx);
    map_event_signpost *sign = header->events->signposts + treasure_maps[treasure_map_idx].sign_idx;
    (void)sign;
    switch (*state) {
        case 0: {
            treasure_map_update_treasure_map_tilemap(false);
            oams[TREASURE_MAP_STATE->oam_idx_cross].flags |= OAM_FLAG_INVISIBLE;
            // Settings are synced (`bg_display_sync`) a frame later to be in the same frame as the disappearance of the map
            bg_hide(0);
            bg_hide(1);
            bg_hide(2);
            (*state)++;
            break;
        }
        case 1: { // Load pals
            bg_display_sync();
            if (treasure_map_idx >= NUM_TREASURE_MAPS) {
                // Done updating, we just delete everything on the screen
                TREASURE_MAP_STATE->is_updating = false;
                big_callback_delete(self);
            } else {
                overworld_load_tileset_pals_without_palette_effects(header->footer);
                // pal_color_multiply(0, 13 * 16, map_over);
                // pal_color_multiply(0, 13 * 16, map_over);
                // pal_alpha_blending(0, 13 * 16, 5, map_over);
                treasure_map_minimize_palette_loss(0, 13 * 16);
                cpuset(pals, pal_restore, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(sizeof(color_t) * 16 * 13));
                pal_copy(&black, 0, sizeof(color_t)); // backdrop
                (*state)++;
            }
            break;
        }
        case 2: { // Load tiles
            overworld_load_tilesets(header->footer);
            (*state)++;
            break;
        }
        case 3: { // Compute tilemaps
            // We show 9x7 blocks of the tilemap centered at the treasure
            tileset *tsp = header->footer->tileset1;
            tileset *tss = header->footer->tileset2;
            int x_center = sign->x + sign->value.treasure_map.center_x;
            int y_center = sign->y + sign->value.treasure_map.center_y;
            bg_tile *targets[3] = {
                TREASURE_MAP_STATE->bg2_map,
                TREASURE_MAP_STATE->bg1_map,
                TREASURE_MAP_STATE->bg0_map,
            };
            oams[TREASURE_MAP_STATE->oam_idx_cross].x2 = (s16)(-sign->value.treasure_map.center_x * 16);
            oams[TREASURE_MAP_STATE->oam_idx_cross].y2 = (s16)(-sign->value.treasure_map.center_y * 16);
            oam_gfx_anim_start(oams + TREASURE_MAP_STATE->oam_idx_cross, (u8)checkflag(treasure_map_get_flag(treasure_map_idx)));
            for (int xx = 0; xx < 9; xx++) {
                for (int yy = 0; yy < 7; yy++) {
                    int x = x_center + xx - 4;
                    int y = y_center + yy - 3;
                    if (x >= 0 && y >= 0 && x < (int)header->footer->width && y < (int)header->footer->height) {
                        map_block *block = header->footer->map + y * (int)header->footer->width + x;
                        bg_tile *tilemap = block->block_id < 0x280 ? tsp->blocks + 12 * block->block_id : tss->blocks + 12 * (block->block_id - 0x280);
                        for (int i = 0; i < 3; i++) {
                            targets[i][32 * (TREASURE_MAP_Y + 2 * yy) + TREASURE_MAP_X + 2 * xx] = tilemap[4 * i ];
                            targets[i][32 * (TREASURE_MAP_Y + 2 * yy) + TREASURE_MAP_X + 2 * xx + 1] = tilemap[4 * i + 1];
                            targets[i][32 * (TREASURE_MAP_Y + 2 * yy + 1) + TREASURE_MAP_X + 2 * xx] = tilemap[4 * i + 2];
                            targets[i][32 * (TREASURE_MAP_Y + 2 * yy + 1) + TREASURE_MAP_X + 2 * xx + 1] = tilemap[4 * i + 3];
                        }
                    } else {
                        // TODO: do we handle this? Border blocks and connections...
                        // For now: leave it as is
                    }
                }
            }
            // TODO
            bg_virtual_sync_reqeust_push(0);
            bg_virtual_sync_reqeust_push(1);
            bg_virtual_sync_reqeust_push(2);
            (*state)++;
            break;
        }
        case 4: { // Done
            treasure_map_update_treasure_map_tilemap(true);
            bg_update_and_show(0);
            bg_update_and_show(1);
            bg_update_and_show(2);
            bg_display_sync();
            oams[TREASURE_MAP_STATE->oam_idx_cross].flags &= (u16)(~OAM_FLAG_INVISIBLE);
            TREASURE_MAP_STATE->is_updating = false;
            big_callback_delete(self);
            break;
        }
    }
}

static void treasure_map_update(int treasure_map_idx) {
    // Hide the treasure map background, i.e. switch bg3s
    u8 cb_idx;
    if (big_callback_is_active(treasure_map_update_callback)) {
        cb_idx = big_callback_get_id(treasure_map_update_callback);
    } else {   
        cb_idx = big_callback_new(treasure_map_update_callback, 0);
    }
    big_callbacks[cb_idx].params[0] = (u16)treasure_map_idx;
    big_callbacks[cb_idx].params[1] = 0;
    TREASURE_MAP_STATE->is_updating = true;
}

static void treasure_map_print_item_callback(u8 tbox_idx, int idx, u8 y) {
    if (idx < NUM_TREASURE_MAPS) {
        if (checkflag(treasure_map_get_flag(idx))) {
            tbox_blit(tbox_idx, gfx_treasure_map_check_markTiles, 0, 0, 16, 8, 38, (u16)(y + 4), 15, 7);
        }
    }
}

static void treasure_map_cursor_move_callback(int idx, u8 on_initialize, list_menu *list) {
    (void)list;
    if (!on_initialize)
        play_sound(5);
    treasure_map_update(idx);
}

static graphic treasure_map_cross_graphic = {.sprite = gfx_treasure_map_crossTiles, .tag = TREASURE_MAP_OAM_TAG_CROSS, .size = GRAPHIC_SIZE_4BPP(32, 64)};
static palette treasure_map_cross_palette = {.pal = gfx_treasure_map_crossPal, .tag = TREASURE_MAP_OAM_TAG_CROSS};
static sprite treasure_map_cross_sprite = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(0)};
static gfx_frame treasure_map_cross_animation_cross[] = {{.data = 0, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame treasure_map_cross_animation_check_mark[] = {{.data = GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32) * 1, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame *treasure_map_cross_animations[] = {[false] = treasure_map_cross_animation_cross, [true] = treasure_map_cross_animation_check_mark};
static oam_template treasure_map_cross_template = {
    .tiles_tag = TREASURE_MAP_OAM_TAG_CROSS, .pal_tag = TREASURE_MAP_OAM_TAG_CROSS, .oam = &treasure_map_cross_sprite,
    .animation = treasure_map_cross_animations, .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static graphic treasure_map_white_square_graphic = {.sprite = gfx_treasure_map_white_squareTiles, .tag = TREASURE_MAP_OAM_TAG_WHITE_SQUARE, .size = GRAPHIC_SIZE_4BPP(64, 64)};
static palette treasure_map_white_square_palette = {.pal = gfx_treasure_map_white_squarePal, .tag = TREASURE_MAP_OAM_TAG_WHITE_SQUARE};
static sprite treasure_map_white_square_sprite = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_64_64, .attr2 = ATTR2_PRIO(3)};
static oam_template treasure_map_white_square_template = {
    .tiles_tag = TREASURE_MAP_OAM_TAG_WHITE_SQUARE, .pal_tag = TREASURE_MAP_OAM_TAG_WHITE_SQUARE, .oam = &treasure_map_white_square_sprite,
    .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static void treasure_map_callback_initialize() {
    treasure_map_cb1();
    if (fading_control.active || dma3_busy(-1))
        return;
    switch (TREASURE_MAP_STATE->initialization_state) {
        case RESET: {
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
            TREASURE_MAP_STATE->initialization_state++;
            break;
        }
        case SETUP_BGS: {
            bg_reset(0);
            bg_reset_control_and_displacement();
            bg_setup(0, treasure_map_bg_configs, ARRAY_COUNT(treasure_map_bg_configs));
            TREASURE_MAP_STATE->bg0_map = malloc_and_clear(0x800);
            bg_set_tilemap(0, TREASURE_MAP_STATE->bg0_map);
            TREASURE_MAP_STATE->bg1_map = malloc_and_clear(0x800);
            bg_set_tilemap(1, TREASURE_MAP_STATE->bg1_map);
            TREASURE_MAP_STATE->bg2_map = malloc_and_clear(0x800);
            bg_set_tilemap(2, TREASURE_MAP_STATE->bg2_map);
            TREASURE_MAP_STATE->bg3_map = malloc_and_clear(0x800);
            bg_set_tilemap(3, TREASURE_MAP_STATE->bg3_map);
            bg_display_sync();
            bg_virtual_sync(0);
            bg_virtual_sync(1);
            bg_virtual_sync(2);
            bg_virtual_sync(3);
            io_set(IO_DISPCNT, IO_DISPCNT_OAM_CHARACTER_MAPPING_ONE_DIMENSIONAL | IO_DISPCNT_OBJ | IO_DISPCNT_WIN0);
            io_set(IO_BLDCNT, IO_BLDCNT_NONE);
            TREASURE_MAP_STATE->initialization_state++;
            break;
        }
        case SETUP_TBOXES: {
            tbox_free_all();
            tbox_sync_with_virtual_bg_and_init_all(treasure_map_tboxes);
            tbox_init_frame_std(TREASURE_MAP_TBOX_LIST, TREASURE_MAP_START_TILE_BORDER_STD, 
                16 * TREASURE_MAP_PAL_IDX_BORDER_STD);
            TREASURE_MAP_STATE->initialization_state++;
            for (u8 i = 0; treasure_map_tboxes[i].bg_id != 0xFF; i++) {
                tbox_flush_set(i, 0x00);
                tbox_flush_map(i);
                tbox_tilemap_draw(i);
                bg_virtual_sync_reqeust_push(treasure_map_tboxes[i].bg_id);
            }
            break;
        }
        case SETUP_LIST: {
            TREASURE_MAP_STATE->num_list_menu_items = 0;
            for (size_t i = 0; i < ARRAY_COUNT(treasure_maps); i++) {
                treasure_map_t *map = treasure_maps + i;
                if (map->bank != 0xFF) {
                    map_header_t *header = get_mapheader(map->bank, map->map_idx);
                    map_event_signpost *sign = header->events->signposts + map->sign_idx;
                    if (sign->type != SIGNPOST_HIDDEN_TREASURE)
                        ERROR("Treasure map at map %d.%d, idx %d is not a treasure map!\n", map->bank, map->map_idx, map->sign_idx);
                    bool map_found = checkflag(treasure_map_get_map_flag(sign->value.treasure_map.idx));
                    bool treasure_found = checkflag(treasure_map_get_flag(sign->value.treasure_map.idx));
                    if (map_found) {
                        u8 *text = TREASURE_MAP_STATE->list_menu_item_texts[TREASURE_MAP_STATE->num_list_menu_items];
                        treasure_map_format_string(i, map_found, treasure_found, text);
                        TREASURE_MAP_STATE->list_menu_items[TREASURE_MAP_STATE->num_list_menu_items].idx = (u8)(i);
                        TREASURE_MAP_STATE->list_menu_items[TREASURE_MAP_STATE->num_list_menu_items].text = text;
                        TREASURE_MAP_STATE->num_list_menu_items++;
                    }
                }
            }
            // Add the "back" option
            TREASURE_MAP_STATE->list_menu_items[TREASURE_MAP_STATE->num_list_menu_items].idx = NUM_TREASURE_MAPS;
            TREASURE_MAP_STATE->list_menu_items[TREASURE_MAP_STATE->num_list_menu_items].text = str_back;
                        TREASURE_MAP_STATE->num_list_menu_items++;
            gp_list_menu_template.items = TREASURE_MAP_STATE->list_menu_items;
            gp_list_menu_template.item_cnt = (u16)(TREASURE_MAP_STATE->num_list_menu_items);
            gp_list_menu_template.tbox_idx = TREASURE_MAP_TBOX_LIST;
            gp_list_menu_template.header_x = 0;
            gp_list_menu_template.item_x = 9;
            gp_list_menu_template.cursor_x = 1;
            gp_list_menu_template.letter_spacing = 0;
            gp_list_menu_template.item_vertical_padding = 2;
            gp_list_menu_template.up_text_y = 2;
            gp_list_menu_template.max_items_showed = 9;
            gp_list_menu_template.font = 2;
            gp_list_menu_template.cursor_pal = 2;
            gp_list_menu_template.fill_value = 0;
            gp_list_menu_template.cursor_shadow_color = 3;
            gp_list_menu_template.cursor_kind = 0;
            gp_list_menu_template.scroll_multiple = 0;
            // TODO
            gp_list_menu_template.cursor_moved_callback = treasure_map_cursor_move_callback; 
            gp_list_menu_template.item_print_callback = treasure_map_print_item_callback;
            TREASURE_MAP_STATE->initialization_state++;
            break;
        }
        case LOAD_GFX: {
            pal_copy(&black, 0, sizeof(color_t));
            lz77uncompvram(gfx_treasure_map_ui_backgroundTiles, CHARBASE(2));
            cpuset(gfx_treasure_map_ui_backgroundMap, TREASURE_MAP_STATE->bg3_map, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(32 * 32 * sizeof(bg_tile)));
            pal_decompress(gfx_treasure_map_ui_backgroundPal, 16 * 13, 32 * sizeof(color_t));
            TREASURE_MAP_STATE->initialization_state++;
            break;
        }
        case LOAD_OAM_GFX: {
            oam_load_graphic(&treasure_map_cross_graphic);
            oam_load_graphic(&treasure_map_white_square_graphic);
            oam_palette_load_if_not_present(&treasure_map_cross_palette);
            oam_palette_load_if_not_present(&treasure_map_white_square_palette);
            TREASURE_MAP_STATE->initialization_state++;
            break;
        }
        case SETUP_OAM: {
            // (void)treasure_map_cross_template;
            TREASURE_MAP_STATE->oam_idx_cross = oam_new_forward_search(&treasure_map_cross_template,
                152, 80, 0);
            oams[TREASURE_MAP_STATE->oam_idx_cross].flags |= OAM_FLAG_CENTERED;
            // We're out of bgs for the white text background, so we just use oams
            oams[oam_new_forward_search(&treasure_map_white_square_template, 40, 40, 0)].flags |= OAM_FLAG_CENTERED;
            oams[oam_new_forward_search(&treasure_map_white_square_template, 40, 40 + 64, 0)].flags |= OAM_FLAG_CENTERED;
            oams[oam_new_forward_search(&treasure_map_white_square_template, 40, 40 + 128, 0)].flags |= OAM_FLAG_CENTERED;
            TREASURE_MAP_STATE->initialization_state++;
            break;
        }
        case SETUP_SCROLL_INDICATORS: {
            scroll_indicator_template template_list = {
                .arrow0_threshold = 0, 
                .arrow1_threshold = (u16)MAX(0, TREASURE_MAP_STATE->num_list_menu_items - TREASURE_MAP_NUM_MAPS_SHOWN), 
                .arrow0_type = SCROLL_ARROW_UP, .arrow1_type = SCROLL_ARROW_DOWN,
                .arrow0_x = 40, .arrow1_x = 40,
                .arrow0_y = 7, .arrow1_y = 152,
                .pal_tag = 112, .tiles_tag = 112,
            };
            if (treasure_map_context_has_scroll_indicators[TREASURE_MAP_STATE->context])
                TREASURE_MAP_STATE->scroll_indicator_cb_idx = scroll_indicator_new(&template_list, &fmem.treasure_map_cursor_position);
            TREASURE_MAP_STATE->initialization_state++;
            break;
        }
        case SHOW: {
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
            TREASURE_MAP_STATE->initialization_state++;
            break;
        }
        default: {
            TREASURE_MAP_STATE->list_menu_cb_idx = list_menu_new(&gp_list_menu_template, 
                fmem.treasure_map_cursor_position, fmem.treasure_map_items_above);
            if (TREASURE_MAP_STATE->context == TREASURE_MAP_CONTEXT_SHOW)
                list_menu_search(TREASURE_MAP_STATE->list_menu_cb_idx, TREASURE_MAP_STATE->treasure_map_idx_to_show,
                    true);
            fading_control.buffer_transfer_disabled = false;
            callback1_set(treasure_map_cb1);
            vblank_handler_set(treasure_map_vblank_callback);
            fadescreen(0xFFFFFFFF, 0, 16, 0, 0);
            big_callback_new(treasure_map_idle_callbacks[TREASURE_MAP_STATE->context], 0);
            break;
        }
    }
}

static void treasure_map_wait_for_fadescreen_and_initialize_ui(u8 self) {
    if (!fading_control.active) {
        big_callback_delete(self);
        if (TREASURE_MAP_STATE->from_outdoor) {
            overworld_free();
        } else {
            pokepad2_free();
        }
        callback1_set(treasure_map_callback_initialize);
    }
}


void treasure_map_initialize(bool from_outdoor) {
    overworld_rain_sound_fade_out();
    fmem.gp_state = malloc_and_clear(sizeof(treasure_map_state_t));
    TREASURE_MAP_STATE->from_outdoor = from_outdoor;
    TREASURE_MAP_STATE->context = TREASURE_MAP_CONTEXT_NONE;
    if (from_outdoor)
        fadescreen_all(1, 0);
    else
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
    callback1_set(treasure_map_cb1);
    big_callback_new(treasure_map_wait_for_fadescreen_and_initialize_ui, 0);
}

void treasure_map_initialize_show() {
    overworld_rain_sound_fade_out();
    fmem.gp_state = malloc_and_clear(sizeof(treasure_map_state_t));
    TREASURE_MAP_STATE->from_outdoor = true;
    TREASURE_MAP_STATE->context = TREASURE_MAP_CONTEXT_SHOW;
    TREASURE_MAP_STATE->treasure_map_idx_to_show = (u8)(*var_access(0x8004));
    if (TREASURE_MAP_STATE->from_outdoor)
        fadescreen_all(1, 0);
    else
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
    callback1_set(treasure_map_cb1);
    big_callback_new(treasure_map_wait_for_fadescreen_and_initialize_ui, 0);

}

u16 treasure_map_get_flag(int idx) {
    return (u16)(FLAG_TREASURE_BASE + idx);
}

u16 treasure_map_get_map_flag(int idx) {
    return (u16)(FLAG_TREASURE_MAP_BASE + idx);
}

void treasure_map_set_flag() {
    setflag(treasure_map_get_map_flag(*var_access(0x8004)));
}

void treasure_map_buffer_number() {
    itoa(buffer0, *var_access(0x8004) + 1, ITOA_PAD_ZEROS, 2);
}