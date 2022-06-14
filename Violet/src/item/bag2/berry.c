#include "types.h"
#include "item/item.h"
#include "item/berry_pouch.h"
#include "save.h"
#include "berry.h"
#include "debug.h"
#include "flags.h"
#include "language.h"
#include "bg.h"
#include "overworld/map_control.h"
#include "fading.h"
#include "callbacks.h"
#include "overworld/script.h"
#include "text.h"
#include "superstate.h"
#include "music.h"
#include "constants/berry_pouch_contexts.h"
#include "vars.h"
#include "constants/sav_keys.h"
#include "overworld/pokemon_party_menu.h"
#include "item/bag2.h"

static void composter_big_callback_free_overworld_and_initialize(u8 self) {
    if (!fading_is_active()) {
        overworld_free();
        bag_open(BAG_CONTEXT_COMPOST, BAG_OPEN_BERRIES, map_reload);
        // berry_pouch_initialize(BERRY_POUCH_CONTEXT_COMPOSTING, map_reload, true);
        overworld_script_resume();
        big_callback_delete(self);
    }
}

void composter_initialize() {
    overworld_pokemon_league_stop_lighting_effect();
    fadescreen_all(1, 0);
    big_callback_new(composter_big_callback_free_overworld_and_initialize, 0);
}


static inline int bag_berry_sort_cmp(u16 item_first, u16 item_second) {
	return ITEM_IDX_TO_BERRY_IDX(item_first) - ITEM_IDX_TO_BERRY_IDX(item_second);
}

void bag_berries_sort() {
	bag_item_t *list = bag_pockets[POCKET_BERRIES - 1].items;
	size_t list_size = 0;
	while (list[list_size].item_idx != ITEM_NONE)
		list_size++;
	bag_sort_pocket(list, list_size, bag_berry_sort_cmp);
}

static u8 str_text_small[] = PSTRING("FONT_SIZE_SMALL");
static u8 str_clear_to_xtm[] = PSTRING("CLEAR_TO\x17");
static u8 str_xf9_x08_clear_to_x1[] = {0xF9, 0x8, 0xFC, 0x11, 0x1, 0xFF};
static u8 str_space[] = PSTRING(" ");
static u8 str_font_size_big[] = PSTRING("FONT_SIZE_BIG");

void berry_get_str_number_and_name(u8 *dst, u16 item_idx) {
	strcpy(strbuf, str_text_small);
    strcat(strbuf, str_xf9_x08_clear_to_x1);
    itoa(buffer0, ITEM_IDX_TO_BERRY_IDX(item_idx) + 1, ITOA_PAD_ZEROS, 2);
    strcat(strbuf, buffer0);
    strcat(strbuf, str_clear_to_xtm);
	strcat(strbuf, str_space);
	strcat(strbuf, str_font_size_big);
	strcat(strbuf, item_get_name(item_idx));
	// strcat(strbuf, str_color_grey);
	strcpy(dst, strbuf);
}