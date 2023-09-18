
#include "types.h"
#include "constants/attacks.h"
#include "constants/items.h"
#include "item/item.h"
#include "bios.h"
#include "save.h"
#include "item/tm_hm.h"
#include "attack.h"
#include "language.h"
#include "agbmemory.h"
#include "text.h"
#include "pokemon/virtual.h"
#include "overworld/pokemon_party_menu.h"
#include "item/bag.h"
#include "callbacks.h"
#include "music.h"
#include "superstate.h"
#include "item/bag2.h"
#include "debug.h"
#include "attack.h"
#include "constants/attacks.h"

const u16 tm_hm_to_attack[NUM_TMS + NUM_HMS] = {
	 ATTACK_POWER_PUNCH,
	 ATTACK_DRACHENKLAUE,
	 ATTACK_AQUAWELLE,
	 ATTACK_GEDANKENGUT,
	 ATTACK_BRUELLER,
	 ATTACK_TOXIN,
	 ATTACK_HAGELSTURM,
	 ATTACK_PROTZER,
	 ATTACK_KUGELSAAT,
	 ATTACK_KRAFTRESERVE,
	 ATTACK_SONNENTAG,
	 ATTACK_VERHOEHNER,
	 ATTACK_EISSTRAHL,
	 ATTACK_BLIZZARD,
	 ATTACK_HYPERSTRAHL,
	 ATTACK_LICHTSCHILD,
	 ATTACK_SCHUTZSCHILD,
	 ATTACK_REGENTANZ,
	 ATTACK_GIGASAUGER,
	 ATTACK_BODYGUARD,
	 ATTACK_FRUSTRATION,
	 ATTACK_SOLARSTRAHL,
	 ATTACK_EISENSCHWEIF,
	 ATTACK_DONNERBLITZ,
	 ATTACK_DONNER,
	 ATTACK_ERDBEBEN,
	 ATTACK_RUECKKEHR,
	 ATTACK_SCHAUFLER,
	 ATTACK_PSYCHOKINESE,
	 ATTACK_SPUKBALL,
	 ATTACK_DURCHBRUCH,
	 ATTACK_DOPPELTEAM,
	 ATTACK_REFLEKTOR,
	 ATTACK_SCHOCKWELLE,
	 ATTACK_FLAMMENWURF,
	 ATTACK_MATSCHBOMBE,
	 ATTACK_SANDSTURM,
	 ATTACK_FEUERSTURM,
	 ATTACK_FELSGRAB,
	 ATTACK_AERO_ASS,
	 ATTACK_ZAUBERSCHEIN,
	 ATTACK_FASSADE,
	 ATTACK_GEHEIMPOWER,
	 ATTACK_ERHOLUNG,
	 ATTACK_ANZIEHUNG,
	 ATTACK_RAUB,
	 ATTACK_STAHLFLUEGEL,
	 ATTACK_SCHWERTTANZ,
	 ATTACK_IRRLICHT,
	 ATTACK_HITZEKOLLER,
	 ATTACK_ZERSCHNEIDER,
	 ATTACK_FLIEGEN,
	 ATTACK_SURFER,
	 ATTACK_STAERKE,
	 ATTACK_BLITZ,
	 ATTACK_ZERTRUEMMERER,
	 ATTACK_KASKADE,
	 ATTACK_KRAXLER
};

bool item_is_tm(u16 item_idx) {
	switch(item_idx) {
		case ITEM_TM01 ... ITEM_TM50: return true;
		default: return false;
	}
}

bool item_is_hm(u16 item_idx) {
	switch(item_idx) {
		case ITEM_VM01:
		case ITEM_VM02:
		case ITEM_VM03:
		case ITEM_VM04:
		case ITEM_VM05:
		case ITEM_VM06:
		case ITEM_VM07:
		case ITEM_VM08:
			return true;
		default:
			return false;
	}
}

bool item_is_sellable(u16 item_idx) {
	if (item_get_price(item_idx) == 0) return false;
	if (item_is_hm(item_idx) || item_is_tm(item_idx)) return false;
	return true;
}

void tm_used_initialize() {
	int zero = 0;
	cpuset(&zero, save1->tm_used_flags, CPUSET_FILL | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(sizeof(save1->tm_used_flags)));
}

bool tm_is_used(int tm_idx) {
	int idx = tm_idx >> 3;
	int mask = 1 << (tm_idx & 7);
	return (save1->tm_used_flags[idx] & mask) != 0;
}

void tm_set_used(int tm_idx) {
	int idx = tm_idx >> 3;
	int mask = 1 << (tm_idx & 7);
	save1->tm_used_flags[idx] = (u8)(save1->tm_used_flags[idx] | mask);
}

void tm_set_unused(int tm_idx) {
	int idx = tm_idx >> 3;
	int mask = 1 << (tm_idx & 7);
	save1->tm_used_flags[idx] = (u8)(save1->tm_used_flags[idx] & ~(mask));
}

void tm_set_used_by_item_idx(u16 item_idx) {
	int tm_idx = ITEM_IDX_TO_TM_IDX(item_idx);
	if (tm_idx >= 0 && tm_idx < NUM_TMS)
		tm_set_used(tm_idx);
}

void tm_vm_print_item(u8 tbox_idx, int item_idx, u8 y) {
	if (item_idx != -2) {
		if (item_is_hm(item_get_idx_by_pocket_position(POCKET_TM_HM, (u16)item_idx))) {
			tm_hm_place_hm_in_tbox(tbox_idx, 8, y);
		}
	}
}

static const u8 str_text_small[] = PSTRING("FONT_SIZE_SMALL");
static const u8 str_color_red[] = PSTRING("COLOR_FG_BG_SHADOW\x04\x00\x05"); //PSTRING("TEXT_SET_FG\x04TEXT_SET_SHADOW\x05");
static const u8 str_color_grey[] = PSTRING("COLOR_FG_BG_SHADOW\x02\x00\x03"); //PSTRING("TEXT_SET_FG\x02TEXT_SET_SHADOW\x03");
static const u8 str_clear_to_x12[] = PSTRING("CLEAR_TO\x12");
static const u8 str_clear_to_x13[] = PSTRING("CLEAR_TO\x13");
static const u8 str_clear_to_xtm[] = PSTRING("CLEAR_TO\x17");
static const u8 str_xf9_x08_clear_to_x1[] = {0xF9, 0x8, 0xFC, 0x11, 0x1, 0xFF};
static const u8 str_space[] = PSTRING(" ");
static const u8 str_font_size_big[] = PSTRING("FONT_SIZE_BIG");

void tm_hm_get_str_number_and_name(u8 *dst, u16 item_idx) {
	strcpy(strbuf, str_text_small);
	if (item_is_hm(item_idx)) {
		strcat(strbuf, str_clear_to_x13);
		// strcat(strbuf, str_xf9_x08_clear_to_x1);
		(void)str_clear_to_x12;
		(void)str_clear_to_xtm;
		itoa(buffer0, ITEM_IDX_TO_HM_IDX(item_idx) + 1, ITOA_PAD_ZEROS, 1);
		strcat(strbuf, buffer0);
	} else {
		if (tm_is_used(ITEM_IDX_TO_TM_IDX(item_idx))) {
			strcat(strbuf, str_color_red);
		}
		strcat(strbuf, str_xf9_x08_clear_to_x1);
		itoa(buffer0, ITEM_IDX_TO_TM_IDX(item_idx) + 1, ITOA_PAD_ZEROS, 2);
		strcat(strbuf, buffer0);
		strcat(strbuf, str_clear_to_xtm);
	}
	strcat(strbuf, str_space);
	strcat(strbuf, str_font_size_big);
	strcat(strbuf, attack_names[item_idx_to_attack(item_idx)]);
	strcat(strbuf, str_color_grey);
	strcpy(dst, strbuf);
	// DEBUG("Formatted item %d (is hm %d) to 0x%x\n", item_idx, item_is_hm(item_idx), dst);
}

static inline int bag_tm_hm_sort_cmp(u16 item_first, u16 item_second) {
	int key_first = (item_is_hm(item_first) << 16) | item_first;
	int key_second = (item_is_hm(item_second) << 16) | item_second;
	return key_first - key_second;
}

void bag_tm_hm_sort() {
	bag_item_t *list = bag_pockets[POCKET_TO_BAG_POCKETS_IDX(POCKET_TM_HM)].items;
	size_t list_size = 0;
	while (list[list_size].item_idx != ITEM_NONE)
		list_size++;
	bag_sort_pocket(list, list_size, bag_tm_hm_sort_cmp);
}

void bag_tm_hm_pocket_load_move_info_icons() {
	tbox_flush_set(BAG_TBOX_MOVE_INFO, 0x00);
	tbox_tilemap_draw(BAG_TBOX_MOVE_INFO);
	tbox_blit_move_info_icon(BAG_TBOX_MOVE_INFO, MOVE_INFO_TYPE, 3, 0 + 1);
	tbox_blit_move_info_icon(BAG_TBOX_MOVE_INFO, MOVE_INFO_CATEGORY, 3, 14 * 1 + 1);
	tbox_blit_move_info_icon(BAG_TBOX_MOVE_INFO, MOVE_INFO_POWER, 3, 14 * 2 + 1);
	tbox_blit_move_info_icon(BAG_TBOX_MOVE_INFO, MOVE_INFO_ACCURACY, 3, 14 * 3 + 1);
	tbox_blit_move_info_icon(BAG_TBOX_MOVE_INFO, MOVE_INFO_PP, 3, 14 * 4 + 1);
	tbox_sync(BAG_TBOX_MOVE_INFO, TBOX_SYNC_SET);
}

void bag_tm_hm_pocket_delete_move_info_icons() {
	tbox_flush_map(BAG_TBOX_MOVE_INFO);
}

static const u8 str_move_info_none[] = PSTRING("---");
static const tbox_font_colormap font_colmap_move_info = {.background = 0, .body = 15, .edge = 14};

void bag_tm_hm_pocket_load_move_info(u16 slot) {


	u8 pocket_idx = bag_get_current_pocket();
	u8 power = 0, accuracy = 0, type = 0xFF, pp = 0, category = 0xFF;
	if (slot < BAG2_STATE->pocket_size[pocket_idx]) {
		u16 attack_idx = tm_hm_to_attack[ITEM_IDX_TO_TM_IDX(item_get_idx_by_pocket_position(pocket_idx, slot))];
		if (attack_idx < ATTACK_CNT) {
			power = attacks[attack_idx].base_power;
			accuracy = attacks[attack_idx].accuracy;
			pp = attacks[attack_idx].pp;
			type = attacks[attack_idx].type;
			category = attacks[attack_idx].category;
		}
	}

	// tbox_flush_set(BAG_TBOX_ATTACK_DETAILS_HEADER, 0x00);
	tbox_fill_rectangle(BAG_TBOX_MOVE_INFO, 0x00, 40 + 4, 0, (u16)(bag_tboxes[BAG_TBOX_MOVE_INFO].w * 8 - 40 + 4), (u16)(bag_tboxes[BAG_TBOX_MOVE_INFO].h * 8));

	if (type != 0xFF)
		tbox_blit_move_info_icon(BAG_TBOX_MOVE_INFO, (u8)(MOVE_INFO_TYPE_BASE + type), 
			40 + 4, 0 * 14 + 2);
	else
		tbox_print_string(BAG_TBOX_MOVE_INFO, 2, 40 + 17, 0 * 14 + 2, 0, 0, 
			&font_colmap_move_info, 0, str_move_info_none);

	if (category != 0xFF)
		tbox_blit_move_info_icon(BAG_TBOX_MOVE_INFO, (u8)(MOVE_INFO_PHYSICAL + category), 40 + 4, 1 * 14 + 2);
	else
		tbox_print_string(BAG_TBOX_MOVE_INFO, 2, 40 + 17, 1 * 14 + 2, 0, 0, 
			&font_colmap_move_info, 0, str_move_info_none);

	if (power)
		itoa(buffer0, power, ITOA_PAD_SPACES, 3);
	else
		strcpy(buffer0, str_move_info_none);
	tbox_print_string(BAG_TBOX_MOVE_INFO, 2, 40 + 17, 2 * 14 + 2, 0, 0, 
		&font_colmap_move_info, 0, buffer0);

	if (accuracy)
		itoa(buffer1, accuracy, ITOA_PAD_SPACES, 3);
	else
		strcpy(buffer1, str_move_info_none);
	tbox_print_string(BAG_TBOX_MOVE_INFO, 2, 40 + 17, 3 * 14 + 2, 0, 0, 
		&font_colmap_move_info, 0, buffer1);

	if (pp)
		itoa(buffer2, pp, ITOA_PAD_SPACES, 3);
	else
		strcpy(buffer2, str_move_info_none);
	tbox_print_string(BAG_TBOX_MOVE_INFO, 2, 40 + 17, 4 * 14 + 2, 0, 0, 
		&font_colmap_move_info, 0, buffer2);
}

static void tm_hm_recharge_continuation() {
	bag_open(BAG_CONTEXT_OVERWORLD, BAG_OPEN_ITEMS, NULL);
}

static void tm_hm_intialize_from_recharge() {
	bag_open(BAG_CONTEXT_RECHARGE_TM_HM, BAG_OPEN_TM_HM, NULL);
	bag_set_continuation(tm_hm_recharge_continuation);
}

void item_field_effect_energiedisk(u8 self) {
	bag_set_continuation(tm_hm_intialize_from_recharge);
	bag_fade_out_and_continuation(self);
}

static const u8 str_needs_to_be_recharged[] = LANGDEP(PSTRING("BUFFER_1 muss erst\nwieder aufgeladen werden!"), PSTRING("BUFFER_1 needs to\nbe recharged first!"));

void tm_hm_field_function(u8 self) {
	if (item_is_tm(item_activated) && tm_is_used(ITEM_IDX_TO_TM_IDX(item_activated))) {
		strcpy(buffer0, item_get_name(item_activated));
		string_decrypt(strbuf, str_needs_to_be_recharged);
		bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
	} else {
		item_callback_after_pokemon_selected = item_use_callback_tm_hm;
		bag_set_continuation(pokemon_party_menu_open_for_item_use);
		bag_fade_out_and_continuation(self);
	}
}