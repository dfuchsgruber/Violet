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

static void bag_cb_initialize();
static bool bag_cb_initialize_step();
static void bag_fadescreen_and_return();
static void bag_free();
static void bag_load_pocket();

enum {
    TBOX_POCKET_NAME,
    TBOX_DESCRIPTION,
    TBOX_HINT,
    NUM_TBOXES,
};

static u8 bag_pocket_order[] = {
    POCKET_ITEMS, POCKET_MEDICINE, POCKET_POKEBALLS, POCKET_TM_HM, POCKET_BERRIES, POCKET_KEY_ITEMS, POCKET_BAIT,
};

static u8 bag_get_current_pocket() {
    return bag_pocket_order[cmem.bag_pocket];
}

static u8 str_hint_give[] = LANGDEP(PSTRING("Welches Item einem\nPokémon geben?"), PSTRING("Give which item\nto a Pokémon?"));
static u8 str_hint_deposit[] = LANGDEP(PSTRING("Welches Item\nablegen?"), PSTRING("Deposit which\nitem?"));
static u8 str_hint_recharge[] = LANGDEP(PSTRING("Welche Tm\naufladen?"), PSTRING("Recharge which\nTm?"));
static u8 str_hint_compost[] = LANGDEP(PSTRING("Welche Beere\nkompostieren?"), PSTRING("Compost which\nberry?"));
static u8 str_hint_sell[] = LANGDEP(PSTRING("Welches Item\nverkaufen?"), PSTRING("Sell which\nitem?"));

static u8 *bag_context_hints[NUM_BAG_CONTEXTS] = {
    [BAG_CONTEXT_PARTY_GIVE] = str_hint_give,
    [BAG_CONTEXT_SELL] = str_hint_sell,
    [BAG_CONTEXT_DEPOSIT] = str_hint_deposit,
    [BAG_CONTEXT_BOX_GIVE] = str_hint_give,
    [BAG_CONTEXT_RECHARGE_TM_HM] = str_hint_recharge,
    [BAG_CONTEXT_COMPOST] = str_hint_compost,
};

static u8 *bag_get_context_hint() {
    return bag_context_hints[BAG2_STATE->context];
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
    free(BAG2_STATE->bg0_map);
    free(BAG2_STATE->bg1_map);
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


static bool bag_allocate_list_menu() {
    size_t num = 0;
    for (int i = 0; i < MAX_NUM_POCKETS - 1; i++)
        num = MAX(bag_pockets[i].capacity, num);
    num++; // For the cancel option
    BAG2_STATE->list_menu_items = malloc_and_clear(num * sizeof(list_menu_item));
    if (!BAG2_STATE->list_menu_items)
        return false;
    BAG2_STATE->list_menu_texts = malloc_and_clear(num * sizeof(u8*));
    if (!BAG2_STATE->list_menu_texts)
        return false;
    return true;
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

static bool bag_allocate() {
    if (!bag_allocate_list_menu())
        return false;
    if (!bag_allocate_bgs())
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
static gfx_frame bag_anim_items[] = {{.data = 0, .duration = 5}, {.data = 64 * 3, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_key_items[] = {{.data = 0, .duration = 5}, {.data = 64 * 5, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_pokeballs[] = {{.data = 0, .duration = 5}, {.data = 64 * 1, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_berries[] = {{.data = 0, .duration = 5}, {.data = 64 * 2, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_medicine[] = {{.data = 0, .duration = 5}, {.data = 64 * 4, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_bait[] = {{.data = 0, .duration = 5}, {.data = 64 * 6, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_tms[] = {{.data = 0, .duration = 5}, {.data = 64 * 7, .duration = 0}, {.data = GFX_ANIM_END}};

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

static void bag_initialize_oams() {
    BAG2_STATE->oam_idx_bag = oam_new_forward_search(&bag_oam_template, 40, bag_get_context_hint() ? 84 : 72, 0);
    bag_oam_switch_pockets(bag_get_current_pocket());
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
            bag_show();
            BAG2_STATE->initialization_state++;
            break;
        }
        case 14: {
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

static tbox_font_colormap font_colormap_pocket_name = {.background = 0, .body = 1, .edge = 2}; 

static void bag_load_pocket() {
    u8 pocket = bag_get_current_pocket();
    u8 *name = bag_pocket_names[pocket];
    u16 name_width = string_get_width(2, name, 0);
    tbox_print_string(TBOX_POCKET_NAME, 2, 
        (u16)((bag_tboxes[TBOX_POCKET_NAME].w * 8 - name_width) / 2),
        0, 0, 0, &font_colormap_pocket_name, 0, name
        );
}

void test_bag2() {
    fadescreen(0xFFFFFFFF, (u8)-2, 0, 16, 0);
    big_callback_new(bag_wait_for_fadescreen_and_initialize, 0);
}