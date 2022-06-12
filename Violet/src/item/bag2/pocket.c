#include "types.h"
#include "item/bag2.h"
#include "oam.h"
#include "fading.h"
#include "callbacks.h"
#include "link.h"
#include "dma.h"
#include "language.h"
#include "text.h"
#include "constants/pokemon_types.h"

static tbox_font_colormap font_colormap_pocket_name = {.background = 0, .body = 1, .edge = 2}; 

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

void bag_load_pocket() {
    u8 pocket = bag_get_current_pocket();
    switch (pocket) {
        case POCKET_TM_HM: {
            bag_tm_hm_sort();
            bag_tm_hm_pocket_load_move_info_icons();
            break;
        }
        case POCKET_BERRIES:
            bag_berries_sort();
            FALL_THROUGH;
        default:
            bag_tm_hm_pocket_delete_move_info_icons();
            break;
    }
    // Reload the hint / black box for tm / hms
    bag_print_hint(bag_get_context_hint());

    bg_virtual_sync_reqeust_push(bag_tboxes[BAG_TBOX_MOVE_INFO].bg_id);
    u8 *name = bag_pocket_names[pocket];
    u16 name_width = string_get_width(2, name, 0);
    tbox_flush_set(BAG_TBOX_POCKET_NAME, 0x00);
    tbox_print_string(BAG_TBOX_POCKET_NAME, 2, 
        (u16)((bag_tboxes[BAG_TBOX_POCKET_NAME].w * 8 - name_width) / 2),
        0, 0, 0, &font_colormap_pocket_name, 0, name
        );
    bag_build_item_list();
    bag_new_scroll_indicators_items();


	// Draw the background box tilemap
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

static void bag_switch_pockets_callback(u8 self) {
    if (menu_util_link_is_busy() || fading_control.active || dma3_busy(-1))
        return;
    switch (big_callbacks[self].params[10]) {
        case 0: {
            u8 pocket_idx = bag_get_current_pocket();
            tbox_flush_map(BAG_TBOX_DESCRIPTION);
            tbox_flush_map(BAG_TBOX_LIST);
            tbox_flush_map(BAG_TBOX_POCKET_NAME);
            tbox_flush_map(BAG_TBOX_MOVE_INFO);
            bag_delete_scroll_indicators_items();
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
            tbox_tilemap_draw(BAG_TBOX_DESCRIPTION);
            tbox_tilemap_draw(BAG_TBOX_LIST);
            tbox_tilemap_draw(BAG_TBOX_POCKET_NAME);
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
