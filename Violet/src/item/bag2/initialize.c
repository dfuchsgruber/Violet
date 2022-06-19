#include "types.h"
#include "item/bag2.h"
#include "callbacks.h"
#include "superstate.h"
#include "menu_util.h"
#include "link.h"
#include "agbmemory.h"
#include "bg.h"
#include "dma.h"
#include "oam.h"
#include "fading.h"
#include "list_menu.h"
#include "overworld/map_control.h"
#include "io.h"
#include "bios.h"
#include "save.h"
#include "flags.h"
#include "constants/item_pockets.h"
#include "transparency.h"
#include "language.h"
#include "debug.h"
#include "list_menu.h"
#include "item/item.h"
#include "music.h"
#include "menu_indicators.h"
#include "overworld/pokemon_party_menu.h"
#include "item/tm_hm.h"

static bool bag_cb_initialize_step();

tbox_font_colormap bag_font_colormap_std = {.background = 0, .body = 2, .edge = 3}; 

tboxdata bag_tboxes[NUM_BAG_TBOXES + 1] = {
    [BAG_TBOX_POCKET_NAME] = {.bg_id = 0, .x = 1, .y = 1, .w = 9, .h = 2, .pal = 15, .start_tile = 1},
    [BAG_TBOX_HINT] = {.bg_id = 2, .x = 0, .y = 4, .w = 10, .h = 9, .pal = 11, .start_tile = 1 + 9 * 2},
    [BAG_TBOX_DESCRIPTION] = {.bg_id = 0, .x = 5, .y = 14, .w = 0x19, .h = 6, .pal = 15, .start_tile = 1 + 9 * 2 + 9 * 11},
    [BAG_TBOX_CONTEXT_MENU_TEXT] = {.bg_id = 0, .x = 5, .y = 14, .w = 10, .h = 6, .pal = 15, .start_tile = 1 + 9 * 2 + 9 * 11 + 0x19 * 6}, // same star tile as description, as both are never visible at the same time
    [BAG_TBOX_LIST] = {.bg_id = 0, .x = 11, .y = 1, .w = 18, .h = 12, .pal = 15, .start_tile = 1 + 9 * 2 + 9 * 11 + 0x19 * 6 + 10 * 6},
    [BAG_TBOX_MOVE_INFO] = {.bg_id = 0, .x = 0, .y = 4, .w = 10, .h = 9, .pal = 4, .start_tile = 1 + 9 * 2 + 9 * 11 + 0x19 * 6 + 10 * 6 + 18 * 12},
    [BAG_TBOX_MESSAGE] =  {.bg_id = 0, .x = 2, .y = 15, .w = 26, .h = 4, .pal = 13, .start_tile = 1 + 9 * 2 + 9 * 11 + 0x19 * 6 + 10 * 6 + 18 * 12 + 10 * 9},
    [BAG_TBOX_MESSAGE_WITH_YES_NO] = {.bg_id = 0, .x = 6, .y = 15, .w = 15, .h = 4, .pal = 13, .start_tile = 1 + 9 * 2 + 9 * 11 + 0x19 * 6 + 10 * 6 + 18 * 12 + 10 * 9 + 26 * 4},
    [BAG_TBOX_MESSAGE_WITH_SELL_QUANTITY] = {.bg_id = 0, .x = 6, .y = 15, .w = 10, .h = 4, .pal = 13, .start_tile = 1 + 9 * 2 + 9 * 11 + 0x19 * 6 + 10 * 6 + 18 * 12 + 10 * 9 + 26 * 4 + 15 * 4}, 
    [BAG_TBOX_ROD_DETAILS] = {.bg_id = 2, .x = 0, .y = 10, .w = 10, .h = 4, .pal = 11, .start_tile = 1 + 9 * 2 + 9 * 11 + 0x19 * 6 + 10 * 6 + 18 * 12},
    [NUM_BAG_TBOXES] = {.bg_id = 0xFF},
};

// These will not be drawn onto the standard bag screen on initialize
static u8 bag_tbox_invisible_at_initialize[NUM_BAG_TBOXES] = {
    [BAG_TBOX_CONTEXT_MENU_TEXT] = true,
    [BAG_TBOX_MESSAGE] = true,
    [BAG_TBOX_MESSAGE_WITH_YES_NO] = true,
    [BAG_TBOX_MESSAGE_WITH_SELL_QUANTITY] = true,
    [BAG_TBOX_ROD_DETAILS] = true,
};

extern color_t bag_tboxPal[16];

static bg_config bag_bg_cnfgs[] = {
    [0] = {
        .bg_id = 0,
        .char_base = 0,
        .map_base = 31,
        .priority = 0,
    }, 
    [1] = {
        .bg_id = 1,
        .char_base = 3,
        .map_base = 30,
        .priority = 2,
    },
    [2] = {
        .bg_id = 2,
        .char_base = 0,
        .map_base = 29,
        .priority = 1,
    },
};

void bag_cb_initialize() {
    while (true) {
        if (menu_util_link_is_busy())
            break;
        if (bag_cb_initialize_step())
            break;
        if (menu_util_link_is_active())
            break;
    }
}

static bool bag_allocate_bgs() {
    BAG2_STATE->bg0_map = malloc_and_clear(0x800);
    if (!BAG2_STATE->bg0_map)
        return false;
    BAG2_STATE->bg1_map = malloc_and_clear(0x800);
    if (!BAG2_STATE->bg1_map)
        return false;
    BAG2_STATE->bg2_map = malloc_and_clear(0x800);
    if (!BAG2_STATE->bg2_map)
        return false;
    bg_reset(0);
    bg_reset_control_and_displacement();
    bg_setup(0, bag_bg_cnfgs, ARRAY_COUNT(bag_bg_cnfgs));
    bg_set_tilemap(0, BAG2_STATE->bg0_map);
    bg_set_tilemap(1, BAG2_STATE->bg1_map);
    bg_set_tilemap(2, BAG2_STATE->bg2_map);
    bg_display_sync();
    bg_virtual_sync(0);
    bg_virtual_sync(1);
    bg_virtual_sync(2);
    bg_virtual_sync_reqeust_push(0);
    bg_virtual_sync_reqeust_push(1);
    bg_virtual_sync_reqeust_push(2);
    io_set(IO_DISPCNT, IO_DISPCNT_OAM_CHARACTER_MAPPING_ONE_DIMENSIONAL | IO_DISPCNT_OBJ | IO_DISPCNT_WIN0);
    io_set(IO_BLDCNT, 0);
    io_set(IO_BGHOFS(2), (u16)(-2));
    io_set(IO_BLDCNT, IO_BLDCNT_BG2_FIRST | IO_BLDCNT_ALPHA_BLENDING | IO_BLDCNT_SECOND_ALL);
    io_set(IO_BLDALPHA, IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(7));
    return true;
}

static bool bag_allocate_list() {
    size_t num = 1;
    for (u32 i = 0; i < ARRAY_COUNT(bag_pockets); i++) {
        num = MAX(num, bag_pockets[i].capacity + 1u);
    }
    BAG2_STATE->list_menu_items = malloc(num * sizeof(list_menu_item));
    if (!BAG2_STATE->list_menu_items)
        return false;
    BAG2_STATE->list_menu_item_texts = malloc(num * sizeof(*BAG2_STATE->list_menu_item_texts));
    if (!BAG2_STATE->list_menu_item_texts)
        return false;
    return true;
}

static bool bag_allocate() {
    if (!bag_allocate_bgs())
        return false;
    if (!bag_allocate_list())
        return false;
    // return if the allocation is successful
    return true;
}

static bool bag_load_gfx() {
    // DEBUG("Load gfx step %d\n", BAG2_STATE->gfx_initialization_state);
    switch (BAG2_STATE->gfx_initialization_state) {
        case 0: {
            lz77uncompvram(gfx_bag_backgroundTiles, CHARBASE(3));
            BAG2_STATE->gfx_initialization_state++;
            break;
        }
        case 1: {
            lz77uncompwram(gfx_bag_backgroundMap, BAG2_STATE->bg1_map);
            BAG2_STATE->gfx_initialization_state++;
            break;
        }
        case 2: {
            pal_decompress(gfx_bag_backgroundPal, 0, 32 * sizeof(color_t));
            BAG2_STATE->gfx_initialization_state++;
            break;
        }
        case 3: {
            oam_load_graphic(&bag_graphic_bag);
            BAG2_STATE->gfx_initialization_state++;
            break;
        }
        case 4: {
            u8 pal_idx = oam_allocate_palette(BAG_OAM_TAG);
            if (pal_idx < 16) {
                pal_decompress(gfx_bag2Pal, (u16)(256 + 16 * pal_idx), 16 * sizeof(color_t));
            }
            BAG2_STATE->gfx_initialization_state++;
            break;
        }
        case 5: {
            oam_load_graphic(&bag_graphic_insert_bar);
            BAG2_STATE->gfx_initialization_state++;
            break;
        }
        case 6: {
            u8 pal_idx = oam_allocate_palette(BAG_INSERT_OAM_TAG);
            if (pal_idx < 16) {
                pal_decompress(gfx_bag_insert_barPal, (u16)(256 + 16 * pal_idx), 16 * sizeof(color_t));
            }
            BAG2_STATE->gfx_initialization_state++;
            break;
        }
        case 7: {
            pal_copy(typechart_icon_pal, (u16)(bag_tboxes[BAG_TBOX_MOVE_INFO].pal * 16), 32);
            BAG2_STATE->gfx_initialization_state++;
            break;
        }
        // case 8: {
        //     // background for the tm/hm move info
        //     u16 fill = 0x1111;
        //     cpuset(&fill, (u8*)CHARBASE(bag_bg_cnfgs[2].char_base) + GRAPHIC_SIZE_4BPP(8, 8), CPUSET_FILL | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(8, 8)));
        //     BAG2_STATE->gfx_initialization_state++;
        //     break;
        // }
        default:
            return true;
    }
    return false;
}

static void bag_initialize_oams() {
    BAG2_STATE->oam_idx_bag = oam_new_forward_search(&bag_oam_template, 40, bag_get_context_hint() ? 84 : 72, 0);
    bag_oam_switch_pockets(bag_get_current_pocket());
    BAG2_STATE->oam_item_base_tile = oam_vram_alloc(GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8));
    oam_vram_allocation_table_add(BAG_ITEM_OAM_TAG, BAG2_STATE->oam_item_base_tile, GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8));
    BAG2_STATE->pal_idx_item = oam_allocate_palette(BAG_ITEM_OAM_TAG);
    BAG2_STATE->oam_idx_item = oam_new_forward_search(&bag_oam_template_item, 24, 140, 0);
};

static void bag_show() {
    color_t backdrop = {.rgb = {0, 0, 0}};
    pal_copy(&backdrop, 0, sizeof(color_t));
    io_set(IO_WININ, 0);
    io_set(IO_WINOUT, IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(0, 1) | IO_WININOUT_BG(0, 2) | IO_WININOUT_BG(0, 3) | IO_WININOUT_OBJ(0) | IO_WININOUT_FX(0));
    fadescreen(0xFFFFFFFF, 0, 16, 0, 0);
    if (checkflag(FLAG_BAG_OPEN)) {
        io_set(IO_WIN0H, IO_WINH(0, 240));
        io_set(IO_WIN0V, IO_WINV(0, 0));
    } else {
        io_set(IO_WIN0H, IO_WINH(0, 240));
        io_set(IO_WIN0V, IO_WINV(0, 160));
        setflag(FLAG_BAG_OPEN);
        u8 cb_idx = big_callback_new(bag_win0_animation, 0);
        s16 *params = (s16*)big_callbacks[cb_idx].params;
        params[0] = 192;
        params[1] = -16;
    }
}

static void bag_initialize_tboxes() {
    tbox_free_all();
    tbox_sync_with_virtual_bg_and_init_all(bag_tboxes);
    tbox_init_frame_message(0, BAG_START_TILE_BORDER_MESSAGE, 16 * BAG_PAL_IDX_BORDER_MESSAGE);
    tbox_init_frame_std(0, BAG_START_TILE_BORDER_STD, 16 * BAG_PAL_IDX_BORDER_STD);
    tbox_init_frame_set_style(0, BAG_START_TILE_BORDER_SET_STYLE, 16 * BAG_PAL_IDX_SET_STYLE);
    pal_copy(tbox_palette_transparent, 11 * 16, 16 * sizeof(color_t));
    pal_copy(bag_tboxPal, 15 * 16, 16 * sizeof(color_t));
    pal_copy(pal_hm_symbol, 15 * 16 + 6, sizeof(pal_hm_symbol));
    for (u8 i = 0; bag_tboxes[i].bg_id != 0xFF; i++) {
        if (bag_tbox_invisible_at_initialize[i])
            continue;
        tbox_flush_set(i, 0x00);
        tbox_flush_map(i);
        tbox_tilemap_draw(i);
    }
    bg_virtual_sync_reqeust_push(0);
    bg_virtual_sync_reqeust_push(2);
}


void bag_initialize_compute_item_counts() {
    for (int pocket_idx = 1; pocket_idx < NUM_POCKETS; pocket_idx++) {
        BAG2_STATE->pocket_size[pocket_idx] = 0;
        bag_pocket_t *pocket = bag_pockets + POCKET_TO_BAG_POCKETS_IDX(pocket_idx);
        bag_pocket_compact(pocket->items, pocket->capacity);
        for (int i = 0; i < pocket->capacity; i++) {
            if (pocket->items[i].item_idx == 0)
                break;
            BAG2_STATE->pocket_size[pocket_idx]++;
        }
        BAG2_STATE->pocket_max_shown[pocket_idx] = (u8)MIN(BAG2_STATE->pocket_size[pocket_idx] + 1u, 6u);
    }
}

void bag_initialize_list_cursor_positions() {
    for (int pocket = 1; pocket < NUM_POCKETS; pocket++) {

        u16 *cursor_pos = fmem.bag_cursor_position + pocket - 1;
        u16 *items_above = fmem.bag_cursor_items_above + pocket - 1;

        if (*cursor_pos != 0 && *cursor_pos + BAG2_STATE->pocket_max_shown[pocket] > BAG2_STATE->pocket_size[pocket] + 1) {
            *cursor_pos = (u16)(BAG2_STATE->pocket_size[pocket] + 1 - BAG2_STATE->pocket_max_shown[pocket]);
        }
        if (*cursor_pos + *items_above >= BAG2_STATE->pocket_size[pocket] + 1) {
            if (BAG2_STATE->pocket_size[pocket] + 1 < 2)
                *items_above = 0;
            else
                *items_above = BAG2_STATE->pocket_size[pocket];
        }
    }
}

static sprite bag_insert_bar_sprite = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(1)};

static gfx_frame bag_insert_bar_anim_left[] = {{.data = 0 * 4, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_insert_bar_anim_mid[] = {{.data = 1 * 4, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_insert_bar_anim_right[] = {{.data = 0 * 4, .duration = 0 | GFX_ANIM_HFLIP}, {.data = GFX_ANIM_END}};
static gfx_frame *bag_insert_bar_animations[] = {bag_insert_bar_anim_left, bag_insert_bar_anim_mid, bag_insert_bar_anim_right};

static oam_template bag_oam_template_insert_bar = {
    .tiles_tag = BAG_INSERT_OAM_TAG, .pal_tag = BAG_INSERT_OAM_TAG,
    .oam = &bag_insert_bar_sprite, .graphics = NULL,
    .animation = bag_insert_bar_animations, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

static void bag_create_insert_bars() {
    for (int i = 0; i < 9; i++) {
        BAG2_STATE->oam_idx_move_item_bar[i] = oam_new_forward_search(&bag_oam_template_insert_bar, (s16)(i * 16 + 0x60), 7, 0);
        oam_object *o = oams + BAG2_STATE->oam_idx_move_item_bar[i];
        switch (i) {
            case 0:
                break;
            case 8:
                oam_gfx_anim_start(o, 2);
                break;
            default:
                oam_gfx_anim_start(o, 1);
                break;
        }
        o->flags |= OAM_FLAG_INVISIBLE;
    }
}

static u8 bag_idle_callback_new() {
    switch (fmem.bag_context) {
        default:
            return big_callback_new(bag_idle_callback_default, 0);
    }
}

void bag_free() {
    // TODO
    if (BAG2_STATE->bg0_map)
        free(BAG2_STATE->bg0_map);
    if (BAG2_STATE->bg1_map)
        free(BAG2_STATE->bg1_map);
    if (BAG2_STATE->bg2_map)
        free(BAG2_STATE->bg2_map);
    if (BAG2_STATE->list_menu_items)
        free(BAG2_STATE->list_menu_items);
    if (BAG2_STATE->list_menu_item_texts)
        free(BAG2_STATE->list_menu_item_texts);
    tbox_free_all();
    free(fmem.bag2_state);
}

static void bag_wait_for_fadescreen_and_return(u8 self) {
    if (!fading_control.active) {
        callback1_set(fmem.bag_continuation);
        bag_free();
        big_callback_delete(self);
    }
}

static void bag_fadescreen_and_return() {
    fadescreen(0xFFFFFFFF, (u8)-2, 0, 16, 0);
    callback1_set(bag_cb1);
    vblank_handler_set(bag_vblank_handler);
    big_callback_new(bag_wait_for_fadescreen_and_return, 0);
}


static u8 str_bag_item_count[] = PSTRING("×BUFFER_1");
extern u8 bag_select_icon[];

static void bag_list_menu_item_print_callback(u8 tbox_idx, int idx, u8 y) {
    u8 pocket = bag_get_current_pocket();
    if (idx != LIST_MENU_B_PRESSED && idx != BAG2_STATE->pocket_size[pocket]) {
        u16 item_idx = item_get_idx_by_pocket_position(pocket, (u16)idx);
        u16 count = item_get_quantity_by_pocket_position(pocket, (u16)idx);
        if (pocket != POCKET_KEY_ITEMS && !item_get_importance(item_idx)) {
            itoa(buffer0, count, ITOA_PAD_SPACES, 3);
            string_decrypt(strbuf, str_bag_item_count);
            tbox_print_string(tbox_idx, 0, 0x6e, y, 0, 0, &bag_font_colormap_std, 0xFF, strbuf);
        } else if (save1->registered_item != 0 && save1->registered_item == item_idx) {
            tbox_blit(tbox_idx, bag_select_icon, 0, 0, 24, 16, 0x70, y, 24, 16);
        }
        if (pocket == POCKET_TM_HM && item_is_hm(item_idx)) {
			tm_hm_place_hm_in_tbox(tbox_idx, 10, y);
        }

    }
    // Print the cursor of the item to move when moving items
    if (BAG2_STATE->is_moving_item) {
        if (BAG2_STATE->moving_item_original_position == idx)
            bag_item_list_print_cursor_at(y, 2);
        else
            bag_item_list_print_cursor_at(y, 0xFF);
    }
}

static void bag_list_menu_cursor_move_callback(int idx, u8 is_initializing, list_menu_t *list) {
    (void)list; (void)idx;
    if (!is_initializing) {
        play_sound(245);
        bag_shake_oam();
    }
    if (!BAG2_STATE->is_moving_item) {
        bag_print_item_description((u16)idx);
        bag_print_rod_bait((u16)idx);
        bag_update_item((u16)idx);
    }
    if (bag_get_current_pocket() == POCKET_TM_HM) {
        bag_tm_hm_pocket_load_move_info((u16)idx);
    }
}

void bag_build_item_list() {
    u8 pocket_idx = bag_get_current_pocket();
    bag_pocket_t *pocket = bag_pockets + POCKET_TO_BAG_POCKETS_IDX(pocket_idx);
    // TODO: berries, hms, etc
    u8 num_items = BAG2_STATE->pocket_size[pocket_idx];
    for (int i = 0; i <= num_items; i++) {
        if (i < num_items)
            bag_format_item_string(BAG2_STATE->list_menu_item_texts[i], pocket->items[i].item_idx);
        else
            bag_format_item_string(BAG2_STATE->list_menu_item_texts[i], 0xFFFF);
        BAG2_STATE->list_menu_items[i].idx = i;
        BAG2_STATE->list_menu_items[i].text = BAG2_STATE->list_menu_item_texts[i];
    }
    gp_list_menu_template.items = BAG2_STATE->list_menu_items;
    gp_list_menu_template.item_cnt = (u16)(BAG2_STATE->pocket_size[pocket_idx] + 1);
    gp_list_menu_template.tbox_idx = BAG_TBOX_LIST;
    gp_list_menu_template.header_x = 0;
    gp_list_menu_template.item_x = 9;
    gp_list_menu_template.cursor_x = 1;
    gp_list_menu_template.letter_spacing = 0;
    gp_list_menu_template.item_vertical_padding = 2;
    gp_list_menu_template.up_text_y = 2;
    gp_list_menu_template.max_items_showed = BAG2_STATE->pocket_max_shown[pocket_idx];
    gp_list_menu_template.font = 2;
    gp_list_menu_template.cursor_pal = 2;
    gp_list_menu_template.fill_value = 0;
    gp_list_menu_template.cursor_shadow_color = 3;
    gp_list_menu_template.cursor_kind = 0;
    gp_list_menu_template.scroll_multiple = 0;
    // TODO
    gp_list_menu_template.cursor_moved_callback = bag_list_menu_cursor_move_callback; 
    gp_list_menu_template.item_print_callback = bag_list_menu_item_print_callback;
}

static bool bag_cb_initialize_step() {
    // DEBUG("Init step %d, vlbankcb 0x%x", BAG2_STATE->initialization_state, super.vblank_callback);
    switch (BAG2_STATE->initialization_state) {
        case 0: {
            reset_hblank_and_vblank_callbacks();
            bg_vritual_sync_reset();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 1: {
            dma0_reset_callback();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 2: {
            oam_palette_allocation_reset();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 3: {
            fading_cntrl_reset();
            fading_control.buffer_transfer_disabled = true;
            BAG2_STATE->initialization_state++;
            break;
        }
        case 4: {
            oam_reset();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 5: {
            // ResetItemMenuIconState
            BAG2_STATE->initialization_state++;
            break;
        }
        case 6: {
            if (!menu_util_link_is_active())
                big_callback_delete_all();
            BAG2_STATE->initialization_state++;
            return true; // Go to next frame
        }
        case 7: {
            if (bag_allocate()) {
                BAG2_STATE->initialization_state++;
                break;
            } else {
                bag_fadescreen_and_return();
                return true;
            }
        }
        case 8 : {
            if (bag_load_gfx()) {
                BAG2_STATE->initialization_state++;
            }
            break;
        }
        case 9: {
            bag_initialize_oams();
            BAG2_STATE->initialization_state++;
            break;

        }
        case 10: {
            bag_initialize_tboxes();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 11: {
            bag_load_pocket();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 12: {
            // bag_print_hint(bag_get_context_hint());
            BAG2_STATE->initialization_state++;
            break;
        }
        case 13: {
            u8 pocket_idx = bag_get_current_pocket();
            BAG2_STATE->idle_cb_idx = bag_idle_callback_new();
            BAG2_STATE->list_menu_cb_idx = list_menu_new(&gp_list_menu_template, fmem.bag_cursor_position[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)], fmem.bag_cursor_items_above[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)]);
            BAG2_STATE->initialization_state++;
            break;
        }
        case 14: {
            bag_new_scroll_indicators_pockets();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 15: {
            bag_create_insert_bars();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 16: {
            pal_set_all_to_black();
            bag_show();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 17: {
            fading_control.buffer_transfer_disabled = false;
            bg_sync_display_and_show(0);
            bg_sync_display_and_show(1);
            bg_sync_display_and_show(2);
            bg_display_sync();
            BAG2_STATE->initialization_state++;
            break;
        }
        default: {
            callback1_set(bag_cb1);
            vblank_handler_set(bag_vblank_handler);
            return true;
        }
        // See: LoadBagMenuGraphics for how to build the setup routine
    }

    return false;
}

