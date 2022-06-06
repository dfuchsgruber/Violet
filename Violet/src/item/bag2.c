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

static void bag_cb_initialize();
static bool bag_cb_initialize_step();
static void bag_fadescreen_and_return();
static void bag_free();
static void bag_load_pocket();
static void bag_build_item_list();
static void bag_initialize_compute_item_counts();
static void bag_win0_animation(u8 self);
static void bag_new_scroll_indicators_pockets();
static void bag_switch_pockets(u8 self, int pocket_to);

enum {
    TBOX_POCKET_NAME,
    TBOX_DESCRIPTION,
    TBOX_HINT,
    TBOX_LIST,
    NUM_TBOXES,
};


static tbox_font_colormap font_colormap_std = {.background = 0, .body = 2, .edge = 3}; 

#define BAG2_MAX_ITEMS_SHOWN 6

static u8 bag_pocket_order[] = {
    POCKET_ITEMS, POCKET_MEDICINE, POCKET_POKEBALLS, POCKET_TM_HM, POCKET_BERRIES, POCKET_KEY_ITEMS, POCKET_BAIT,
};

static u8 bag_get_current_pocket() {
    return bag_pocket_order[cmem.bag_pocket];
}

static u8 str_hint_give[] = LANGDEP(PSTRING("Welches Item\ngeben?"), PSTRING("Give which item\nto a Pokémon?"));
static u8 str_hint_deposit[] = LANGDEP(PSTRING("Welches Item\nablegen?"), PSTRING("Deposit which\nitem?"));
static u8 str_hint_recharge[] = LANGDEP(PSTRING("Welche Tm\naufladen?"), PSTRING("Recharge which\nTm?"));
static u8 str_hint_compost[] = LANGDEP(PSTRING("Welche Beere\nkompostieren?"), PSTRING("Compost which\nberry?"));
static u8 str_hint_sell[] = LANGDEP(PSTRING("Welches Item\nverkaufen?"), PSTRING("Sell which\nitem?"));
static u8 str_hint_plant_berry[] = LANGDEP(PSTRING("Welche Beere\npflanzen?"), PSTRING("Plant which\nberry?"));

static u8 *bag_context_hints[NUM_BAG_CONTEXTS] = {
    [BAG_CONTEXT_PARTY_GIVE] = str_hint_give,
    [BAG_CONTEXT_SELL] = str_hint_sell,
    [BAG_CONTEXT_DEPOSIT] = str_hint_deposit,
    [BAG_CONTEXT_BOX_GIVE] = str_hint_give,
    [BAG_CONTEXT_RECHARGE_TM_HM] = str_hint_recharge,
    [BAG_CONTEXT_COMPOST] = str_hint_compost,
    [BAG_CONTEXT_PLANT_BERRY] = str_hint_plant_berry,
};

static u8 *bag_get_context_hint() {
    return bag_context_hints[BAG2_STATE->context];
}

static int bag_pockets_process_input() {
    if (BAG2_STATE->pocket_switching_disabled)
        return 0;
    else if (super.keys_new.keys.left && cmem.bag_pocket > 0)
        return -1;
    else if (super.keys_new.keys.right && cmem.bag_pocket < ARRAY_COUNT(bag_pocket_order) - 1)
        return 1;
    else
        return 0;
}

static void bag_idle_callback_default(u8 self) {
    (void)(self);

    if (fading_control.active || menu_util_link_is_busy() || big_callback_is_active(bag_win0_animation))
        return;
    int switch_pockets_input = bag_pockets_process_input();
    if (switch_pockets_input != 0) {
        play_sound(246);
        bag_switch_pockets(self, cmem.bag_pocket + switch_pockets_input);
        return;
    }
    u8 pocket = bag_get_current_pocket();
    int input = list_menu_process_input(BAG2_STATE->list_menu_cb_idx);
    list_menu_get_scroll_and_row(BAG2_STATE->list_menu_cb_idx, fmem.bag_cursor_position + pocket - 1, fmem.bag_cursor_items_above + pocket - 1);
    switch (input) {
        case LIST_MENU_NOTHING_CHOSEN:
            return;
    }
}

static u8 bag_idle_callback_new() {
    switch (BAG2_STATE->context) {
        default:
            return big_callback_new(bag_idle_callback_default, 0);
    }
}

void bag_cb1(){
    big_callback_proceed();
    tbox_proceed();
    oam_animations_proceed();
    oam_proceed();
    bg_virtual_sync_reqeust_proceed();
    fading_proceed();
}

void bag_vblank_handler() {
    oam_attributes_copy();
    graphic_queue_proceed();
    pal_proceed();
    dma0_proceed();
    dma3_queue_proceed();
}

static void bag_free() {
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
    free(fmem.bag2_state);
}

static void bag_wait_for_fadescreen_and_return(u8 self) {
    if (!fading_control.active) {
        callback1_set(BAG2_STATE->continuation);
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

void bag_open(u8 context, u8 open_which, void (*continuation)()) {
    // Todo reset state
    fmem.bag2_state = malloc_and_clear(sizeof(bag2_state_t));
    if (!fmem.bag2_state) {
        callback1_set(continuation);
        return;
    } else {
        BAG2_STATE->initialization_state = 0;
        BAG2_STATE->context = context;
        BAG2_STATE->open_which = open_which;
        BAG2_STATE->continuation = continuation;
        if (open_which != BAG_OPEN_LAST) {
            for (cmem.bag_pocket = 0; cmem.bag_pocket <= ARRAY_COUNT(bag_pocket_order); cmem.bag_pocket++) {
                if (bag_pocket_order[cmem.bag_pocket] == open_which)
                    break;
            }
        }
        bag_initialize_compute_item_counts();
        callback1_set(bag_cb_initialize);
    }
}

static void bag_cb_initialize() {
    while (true) {
        if (menu_util_link_is_busy())
            break;
        if (bag_cb_initialize_step())
            break;
        if (menu_util_link_is_active())
            break;
    }
}


static bg_config bag_bg_cnfgs[] = {
    {
        .bg_id = 0,
        .char_base = 0,
        .map_base = 31,
        .priority = 1,
    }, {
        .bg_id = 1,
        .char_base = 3,
        .map_base = 30,
        .priority = 2,
    }, {
        .bg_id = 2,
        .char_base = 0,
        .map_base = 29,
        .priority = 0,
    },
};

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
    io_set(IO_BLDALPHA, IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(12));
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



static graphic graphic_bag = {.sprite = gfx_bag2Tiles, .size = 8 * GRAPHIC_SIZE_4BPP(64, 64), .tag = BAG_OAM_TAG};

static bool bag_load_gfx() {
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
            oam_load_graphic(&graphic_bag);
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
        default:
            return true;
    }
    return false;
}

static sprite bag_sprite = {.attr0 = ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE | ATTR0_DSIZE, .attr1 = ATTR1_SIZE_64_64, .attr2 = ATTR2_PRIO(1)};

static gfx_frame bag_anim_idle[] = {{.data = 0, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_items[] = {{.data = 64 * 3, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_key_items[] = {{.data = 64 * 5, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_pokeballs[] = {{.data = 64 * 1, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_berries[] = {{.data = 64 * 2, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_medicine[] = {{.data = 64 * 4, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_bait[] = {{.data = 64 * 6, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_tms[] = {{.data = 64 * 7, .duration = 0}, {.data = GFX_ANIM_END}};

static gfx_frame *bag_anims[] = {
    [POCKET_NONE] = bag_anim_idle,
    [POCKET_ITEMS] = bag_anim_items,
    [POCKET_KEY_ITEMS] = bag_anim_key_items,
    [POCKET_POKEBALLS] = bag_anim_pokeballs,
    [POCKET_BERRIES] = bag_anim_berries,
    [POCKET_MEDICINE] = bag_anim_medicine,
    [POCKET_TM_HM] = bag_anim_tms,
    [POCKET_BAIT] = bag_anim_bait,
};

static rotscale_frame bag_rs_anim_idle[] = {
    {.affine = {.affine_x_value = 0x100, .affine_y_value = 0x100, .rotation = 0, .duration = 0}},
    {.command = {.command = ROTSCALE_ANIM_END}}
};

static rotscale_frame bag_rs_anim_wiggle[] = {
    {.affine = {.rotation = -2, .duration = 2}},
    {.affine = {.rotation = 2, .duration = 4}},
    {.affine = {.rotation = -2, .duration = 4}},
    {.affine = {.rotation = 2, .duration = 2}},
    {.command = {.command = ROTSCALE_ANIM_END}}
};

static rotscale_frame *bag_rs_anims[] = {
    bag_rs_anim_idle,
    bag_rs_anim_wiggle, 
};

static oam_template bag_oam_template = {
    .tiles_tag = BAG_OAM_TAG, .pal_tag = BAG_OAM_TAG,
    .oam = &bag_sprite, .graphics = NULL, .animation = bag_anims,
    .rotscale = bag_rs_anims, .callback = oam_null_callback,
};

void bag_oam_switch_pockets_callback(oam_object *self) {
    if (self->y2 != 0)
        self->y2++;
    else
        self->callback = oam_null_callback;
}

static void bag_oam_switch_pockets(u8 pocket) {
    oam_object *o = oams + BAG2_STATE->oam_idx_bag;
    o->y2 = -5;
    o->callback = bag_oam_switch_pockets_callback;
    oam_gfx_anim_start(o, pocket);
}

static sprite sprite_item = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(1)};

static oam_template oam_template_item = {
    .tiles_tag = BAG_ITEM_OAM_TAG, .pal_tag = BAG_ITEM_OAM_TAG,
    .graphics = NULL, .oam = &sprite_item, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static void bag_initialize_oams() {
    BAG2_STATE->oam_idx_bag = oam_new_forward_search(&bag_oam_template, 40, bag_get_context_hint() ? 84 : 72, 0);
    bag_oam_switch_pockets(bag_get_current_pocket());
    BAG2_STATE->oam_item_base_tile = oam_vram_alloc(GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8));
    oam_vram_allocation_table_add(BAG_ITEM_OAM_TAG, BAG2_STATE->oam_item_base_tile, GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8));
    BAG2_STATE->pal_idx_item = oam_allocate_palette(BAG_ITEM_OAM_TAG);
    BAG2_STATE->oam_idx_item = oam_new_forward_search(&oam_template_item, 24, 140, 0);
};

static void bag_win0_animation(u8 self) {
    s16 *params = (s16*)big_callbacks[self].params;
    params[0] = (s16)(params[0] + params[1]);
    io_set(IO_WIN0V, (u16)IO_WINV(0, MAX(0, MIN(160, params[0]))));
    if ((params[1] > 0 && params[0] >= 160) || (params[1] < 0 && params[0] <= 0))
        big_callback_delete(self);
}

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

static tboxdata bag_tboxes[] = {
    [TBOX_POCKET_NAME] = {.bg_id = 0, .x = 1, .y = 1, .w = 9, .h = 2, .pal = 15, .start_tile = 1},
    [TBOX_HINT] = {.bg_id = 2, .x = 1, .y = 4, .w = 8, .h = 4, .pal = 11, .start_tile = 1 + 9 * 2},
    [TBOX_DESCRIPTION] = {.bg_id = 0, .x = 5, .y = 14, .w = 0x19, .h = 6, .pal = 15, .start_tile = 1 + 9 * 2 + 9 * 4},
    [TBOX_LIST] = {.bg_id = 0, .x = 11, .y = 1, .w = 18, .h = 12, .pal = 15, .start_tile = 1 + 9 * 2 + 9 * 4 + 0x19 * 6},
    [NUM_TBOXES] = {.bg_id = 0xFF},
};

extern color_t bag_tboxPal[16];

static void bag_initialize_tboxes() {
    tbox_free_all();
    tbox_sync_with_virtual_bg_and_init_all(bag_tboxes);
    tbox_message_init_border(0, 0x210, 16 * 12);
    tbox_message_init(0, 0x210, 16 * 13);
    tbox_context_init_border_set_style(0, 0x200, 16 * 14);
    pal_copy(tbox_palette_transparent, 11 * 16, 16 * sizeof(color_t));
    pal_copy(bag_tboxPal, 15 * 16, 16 * sizeof(color_t));
    for (u8 i = 0; bag_tboxes[i].bg_id != 0xFF; i++) {
        tbox_flush_set(i, 0x00);
        tbox_flush_map(i);
        tbox_tilemap_draw(i);
    }
    bg_virtual_sync_reqeust_push(0);
    bg_virtual_sync_reqeust_push(2);
    // tbox_sync(0, TBOX_SYNC_SET);
    // tbox_sync(0, TBOX_SYNC_MAP);
    // tbox_sync(TBOX_HINT, TBOX_SYNC_SET);
    // tbox_sync(TBOX_HINT, TBOX_SYNC_MAP);
}

static tbox_font_colormap font_colormap_pocket_hint = {.background = 0, .body = 2, .edge = 1}; 

static void bag_load_hint() {
    u8 *hint = bag_get_context_hint();
    if (hint) {
        tbox_flush_set(TBOX_HINT, 0x11);
        tbox_tilemap_draw(TBOX_HINT);
        tbox_print_string(TBOX_HINT, 0, 2, 0, 0, 0, &font_colormap_pocket_hint, 0, hint);
    } else {
        tbox_flush_set(TBOX_HINT, 0x00);
        tbox_flush_map(TBOX_HINT);
    }
}

static void bag_initialize_compute_item_counts() {
    for (int pocket_idx = 1; pocket_idx < NUM_POCKETS; pocket_idx++) {
        BAG2_STATE->pocket_size[pocket_idx] = 0;
        bag_pocket_t *pocket = bag_pockets + pocket_idx - 1;
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

static bool bag_cb_initialize_step() {
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
            break;
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
            bag_load_hint();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 13: {
            u8 pocket_idx = bag_get_current_pocket();
            BAG2_STATE->idle_cb_idx = bag_idle_callback_new();
            BAG2_STATE->list_menu_cb_idx = list_menu_new(&gp_list_menu_template, fmem.bag_cursor_position[pocket_idx - 1], fmem.bag_cursor_items_above[pocket_idx - 1]);
            BAG2_STATE->initialization_state++;
            break;
        }
        case 14: {
            bag_new_scroll_indicators_pockets();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 15: {
            bag_show();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 16: {
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

static void bag_wait_for_fadescreen_and_initialize(u8 self) {
    if (!fading_control.active) {
        bag_open(BAG_CONTEXT_OVERWORLD, BAG_OPEN_LAST, map_reload);
        big_callback_delete(self);
    }
}

static u8 str_pocket_items[] = LANGDEP(PSTRING("Items"), ("Items"));
static u8 str_pocket_key_items[] = LANGDEP(PSTRING("Basis-Items"), PSTRING("Key Items"));
static u8 str_pocket_pokeballs[] = LANGDEP(PSTRING("Pokébälle"), PSTRING("Pokéballs"));
static u8 str_pocket_medicine[] = LANGDEP(PSTRING("Medizin"), PSTRING("Medicine"));
static u8 str_pocket_berries[] = LANGDEP(PSTRING("Beeren"), PSTRING("Berries"));
static u8 str_pocket_tms[] = LANGDEP(PSTRING("Tms / Vms"), PSTRING("Tms / Hms"));
static u8 str_pocket_bait[] = LANGDEP(PSTRING("Köder"), PSTRING("Bait"));

static u8 *bag_pocket_names[] = {
    [POCKET_ITEMS] = str_pocket_items,
    [POCKET_KEY_ITEMS] = str_pocket_key_items,
    [POCKET_POKEBALLS] = str_pocket_pokeballs,
    [POCKET_MEDICINE] = str_pocket_medicine,
    [POCKET_BERRIES] = str_pocket_berries,
    [POCKET_TM_HM] = str_pocket_tms,
    [POCKET_BAIT] = str_pocket_bait,
};

static u8 str_bag_font_color_regular[] = PSTRING("COLOR_HIGHLIGHT_SHADOW\x02\x00\x03");
static u8 str_cancel[] = LANGDEP(PSTRING("Zurück"), PSTRING("Cancel"));

static void bag_format_item_string(u8 *dst, u16 item_idx) {
    // TODO: Highlight colors for empty tms
    strcpy(dst, str_bag_font_color_regular);
    DEBUG("Format string called with %d\n", item_idx);
    if (item_idx == 0xFFFF)
        strcat(dst, str_cancel);
    else
        strcat(dst, item_get_name(item_idx));
}

static u8 str_bag_item_count[] = PSTRING("×BUFFER_1");
extern u8 bag_select_icon[];

static void bag_list_menu_cursor_print_callback(u8 tbox_idx, int idx, u8 y) {
    u8 pocket = bag_get_current_pocket();
    if (idx != LIST_MENU_B_PRESSED && idx != BAG2_STATE->pocket_size[pocket]) {
        u16 item_idx = item_get_idx_by_pocket_position(pocket, (u16)idx);
        u16 count = item_get_quantity_by_pocket_position(pocket, (u16)idx);
        if (pocket != POCKET_KEY_ITEMS && !item_get_importance(item_idx)) {
            itoa(buffer0, count, ITOA_PAD_SPACES, 3);
            string_decrypt(strbuf, str_bag_item_count);
            tbox_print_string(tbox_idx, 0, 0x6e, y, 0, 0, &font_colormap_std, 0xFF, strbuf);
        } else if (save1->registered_item != 0 && save1->registered_item == item_idx) {
            tbox_blit(tbox_idx, bag_select_icon, 0, 0, 24, 16, 0x70, y, 24, 16);
        }
    }
}

static void bag_oam_callback_bag_shaking(oam_object *self) {
    if (self->flags & OAM_FLAG_GFX_ROTSCALE_ANIM_END) {
        oam_rotscale_anim_init(self, 0);
        self->callback = oam_null_callback;
    }
}

static void bag_shake_oam() {
    oam_object *o = oams + BAG2_STATE->oam_idx_bag;
    if (o->flags & OAM_FLAG_GFX_ROTSCALE_ANIM_END) {
        oam_rotscale_anim_init(o, 1);
        o->callback = bag_oam_callback_bag_shaking;
    }
}

static u8 str_close_bag[] = LANGDEP(PSTRING("Beutel schließen"), PSTRING("Close bag"));

static tbox_font_colormap font_colormap_description = {.background = 0, .body = 1, .edge = 2};

static void bag_print_item_description(u16 slot) {
    u8 pocket = bag_get_current_pocket();
    u8 *description;
    if (slot == BAG2_STATE->pocket_size[pocket])
        description = str_close_bag;
    else
        description = item_get_description(item_get_idx_by_pocket_position(pocket, slot));
    tbox_flush_set(TBOX_DESCRIPTION, 0x00);
    tbox_print_string(TBOX_DESCRIPTION, 2, 0, 3, 0, 0, &font_colormap_description, 0, description);
}

static void bag_oam_item_callback_update(oam_object *self) {
    switch (self->private[1]) {
        case 0: {
            const u8 *pal = item_get_resource(self->private[0], true);
            pal_decompress(pal, (u16)(256 + 16 * BAG2_STATE->pal_idx_item), 16 * sizeof(color_t));
            break;
        }
        case 1: {
            u16 tile = BAG2_STATE->oam_item_base_tile;
            const u8 *gfx = item_get_resource(self->private[0], false);
            lz77uncompwram(gfx, gp_tmp_buf);
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    cpuset(gp_tmp_buf + (3 * y + x) * GRAPHIC_SIZE_4BPP(8, 8), (u8*)OAMCHARBASE(tile) + (4 * y + x) * GRAPHIC_SIZE_4BPP(8, 8),
                        CPUSET_COPY | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(8, 8) | CPUSET_HALFWORD));
                }
            }
            break;
        }
        default: {
            self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
            self->callback = oam_null_callback;
            break;
        }
    }
    self->private[1]++;
}

static void bag_update_item(u16 slot) {
    u8 pocket = bag_get_current_pocket();
    u16 item_idx;
    if (slot == BAG2_STATE->pocket_size[pocket])
        item_idx = ITEM_NA;
    else
        item_idx = item_get_idx_by_pocket_position(pocket, slot);
    oam_object *o = oams + BAG2_STATE->oam_idx_item;
    o->flags |= OAM_FLAG_INVISIBLE;
    o->private[0] = item_idx;
    o->private[1] = 0;
    o->callback = bag_oam_item_callback_update;
}

static void bag_list_menu_cursor_move_callback(int idx, u8 is_initializing, list_menu_t *list) {
    (void)list; (void)idx;
    if (!is_initializing) {
        play_sound(245);
        bag_shake_oam();
    }
    bag_print_item_description((u16)idx);
    bag_update_item((u16)idx);
}

static void bag_build_item_list() {
    u8 pocket_idx = bag_get_current_pocket();
    bag_pocket_t *pocket = bag_pockets + pocket_idx - 1;
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
    gp_list_menu_template.tbox_idx = TBOX_LIST;
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
    gp_list_menu_template.item_print_callback = bag_list_menu_cursor_print_callback;
}

static void bag_delete_scroll_indcators_items() {
    scroll_indicator_delete(BAG2_STATE->scroll_indicator_items_cb_idx);
}

static void bag_new_scroll_indicators_items() {
    u8 pocket_idx = bag_get_current_pocket();
    scroll_indicator_template indicator_template = {
        .arrow0_type = SCROLL_ARROW_UP, .arrow0_x = 160, .arrow0_y = 8,
        .arrow1_type = SCROLL_ARROW_DOWN, .arrow1_x = 160, .arrow1_y = 104,
        .arrow0_threshold = 0, 
        .arrow1_threshold = (u16) MAX(0, BAG2_STATE->pocket_size[pocket_idx] - BAG2_STATE->pocket_max_shown[pocket_idx] + 1),
        .tiles_tag = 110,
        .pal_tag = 110,
    };
    BAG2_STATE->scroll_indicator_items_cb_idx = scroll_indicator_new(&indicator_template,
        fmem.bag_cursor_position + pocket_idx - 1);
    scroll_indicator_set_oam_priority(BAG2_STATE->scroll_indicator_items_cb_idx, 1, 1);
}

static scroll_indicator_template scroll_indicator_template_pockets = {
    .arrow0_type = SCROLL_ARROW_LEFT, .arrow0_x = 8, .arrow0_y = 72,
    .arrow1_type = SCROLL_ARROW_RIGHT, .arrow1_x = 72, .arrow1_y = 72,
    .arrow0_threshold = 0, .arrow1_threshold = ARRAY_COUNT(bag_pocket_order) - 1,
    .tiles_tag = 111, .pal_tag = 111,
};

static void bag_new_scroll_indicators_pockets() {
    BAG2_STATE->scroll_indicator_pockets_cb_idx = scroll_indicator_new(&scroll_indicator_template_pockets,
        &cmem.bag_pocket);
    scroll_indicator_set_oam_priority(BAG2_STATE->scroll_indicator_pockets_cb_idx, 1, 1);
}

static tbox_font_colormap font_colormap_pocket_name = {.background = 0, .body = 1, .edge = 2}; 

static void bag_load_pocket() {
    u8 pocket = bag_get_current_pocket();
    u8 *name = bag_pocket_names[pocket];
    u16 name_width = string_get_width(2, name, 0);
    tbox_flush_set(TBOX_POCKET_NAME, 0x00);
    tbox_print_string(TBOX_POCKET_NAME, 2, 
        (u16)((bag_tboxes[TBOX_POCKET_NAME].w * 8 - name_width) / 2),
        0, 0, 0, &font_colormap_pocket_name, 0, name
        );
    bag_build_item_list();
    bag_new_scroll_indicators_items();
}

static void bag_oam_switch_pocket_callback(oam_object *self) {
    if (self->y2 < 0)
        self->y2++;
    else
        self->callback = oam_null_callback;
}

static void bag_oam_switch_pocket(u8 pocket_idx) {
    oam_object *o = oams + BAG2_STATE->oam_idx_bag; 
    oam_gfx_anim_start(o, pocket_idx);
    o->y2 = -5;
    o->callback = bag_oam_switch_pocket_callback;
}

void bag_switch_pockets_callback(u8 self) {
    if (menu_util_link_is_busy() || fading_control.active || dma3_busy(-1))
        return;
    switch (big_callbacks[self].params[10]) {
        case 0: {
            u8 pocket_idx = bag_get_current_pocket();
            tbox_flush_map(TBOX_DESCRIPTION);
            tbox_flush_map(TBOX_LIST);
            tbox_flush_map(TBOX_POCKET_NAME);
            bag_delete_scroll_indcators_items();
            oams[BAG2_STATE->oam_idx_item].flags |= OAM_FLAG_INVISIBLE;
            list_menu_remove(BAG2_STATE->list_menu_cb_idx, fmem.bag_cursor_position + pocket_idx - 1, fmem.bag_cursor_items_above + pocket_idx - 1);
            bg_virtual_sync_reqeust_push(0);
            big_callbacks[self].params[10]++;
            break;
        }
        case 1: {
            cmem.bag_pocket = big_callbacks[self].params[11];
            u8 pocket_idx = bag_get_current_pocket();
            bag_load_pocket();
            bag_oam_switch_pocket(pocket_idx);
            BAG2_STATE->list_menu_cb_idx = list_menu_new(&gp_list_menu_template, fmem.bag_cursor_position[pocket_idx - 1], fmem.bag_cursor_items_above[pocket_idx - 1]);
            big_callbacks[self].params[10]++;
            break;
        }
        case 2: {
            tbox_tilemap_draw(TBOX_DESCRIPTION);
            tbox_tilemap_draw(TBOX_LIST);
            tbox_tilemap_draw(TBOX_POCKET_NAME);
            bg_virtual_sync_reqeust_push(0);
            big_callbacks[self].params[10]++;
            break;
        }
        default: {
            big_callback_set_function_to_continuation(self);
            break;
        }
    }
}

void bag_switch_pockets(u8 self, int pocket_idx_to) {
    big_callbacks[self].params[10] = 0; // state
    big_callbacks[self].params[11] = (u16)pocket_idx_to; // state
    big_callback_set_function_and_continuation(self, bag_switch_pockets_callback, big_callbacks[self].function);
    big_callbacks[self].function(self);
}

void test_bag2() {
    fadescreen(0xFFFFFFFF, (u8)-2, 0, 16, 0);
    big_callback_new(bag_wait_for_fadescreen_and_initialize, 0);
}