/*
 * tm_hm.c
 *
 *  Created on: Oct 1, 2018
 *      Author: dominik
 */
#include "item/tm_hm.h"
#include "agbmemory.h"
#include "attack.h"
#include "bios.h"
#include "callbacks.h"
#include "constants/attacks.h"
#include "constants/items.h"
#include "item/bag.h"
#include "item/item.h"
#include "language.h"
#include "music.h"
#include "overworld/pokemon_party_menu.h"
#include "pokemon/virtual.h"
#include "save.h"
#include "superstate.h"
#include "text.h"
#include "types.h"

u16 tm_hm_to_attack[NUM_TMS + NUM_HMS] = {
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
    ATTACK_FOLTERKNECHT,
    ATTACK_FASSADE,
    ATTACK_GEHEIMPOWER,
    ATTACK_ERHOLUNG,
    ATTACK_ANZIEHUNG,
    ATTACK_RAUB,
    ATTACK_STAHLFLUEGEL,
    ATTACK_WERTEWECHSEL,
    ATTACK_UEBERNAHME,
    ATTACK_HITZEKOLLER,
    ATTACK_ZERSCHNEIDER,
    ATTACK_FLIEGEN,
    ATTACK_SURFER,
    ATTACK_STAERKE,
    ATTACK_BLITZ,
    ATTACK_ZERTRUEMMERER,
    ATTACK_KASKADE,
    ATTACK_KRAXLER};

bool item_is_tm(u16 item_idx) {
    switch (item_idx) {
        case ITEM_TM01 ... ITEM_TM50:
            return true;
        default:
            return false;
    }
}

bool item_is_hm(u16 item_idx) {
    switch (item_idx) {
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
    if (item_get_price(item_idx) == 0)
        return false;
    if (item_is_hm(item_idx) || item_is_tm(item_idx))
        return false;
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

void tm_hm_alloc_list_menu_buffers() {
    tm_hm_list_menu_items = malloc(bag_pockets[POCKET_TM_HM - 1].capacity * sizeof(list_menu_item));
    tm_hm_list_menu_strs = malloc((size_t)(tm_hm_state->num_tms * TM_HM_LIST_MENU_STR_LENGTH));
}

static u8 str_text_small[] = PSTRING("FONT_SIZE_SMALL");
static u8 str_color_red[] = PSTRING("COLOR_FG_BG_SHADOW\x04\x00\x05");  //PSTRING("TEXT_SET_FG\x04TEXT_SET_SHADOW\x05");
static u8 str_color_grey[] = PSTRING("COLOR_FG_BG_SHADOW\x02\x00\x03"); //PSTRING("TEXT_SET_FG\x02TEXT_SET_SHADOW\x03");
static u8 str_clear_to_x12[] = PSTRING("CLEAR_TO\x12");
static u8 str_xf9_x08_clear_to_x1[] = {0xF9, 0x8, 0xFC, 0x11, 0x1, 0xFF};
static u8 str_space[] = PSTRING(" ");
static u8 str_font_size_big[] = PSTRING("FONT_SIZE_BIG");

void tm_hm_get_str_number_and_name(u8 *dst, u16 item_idx) {
    strcpy(strbuf, str_text_small);
    if (item_is_hm(item_idx)) {
        strcat(strbuf, str_clear_to_x12);
        strcat(strbuf, str_xf9_x08_clear_to_x1);
        itoa(buffer0, ITEM_IDX_TO_HM_IDX(item_idx) + 1, ITOA_PAD_ZEROS, 1);
        strcat(strbuf, buffer0);
    } else {
        if (tm_is_used(ITEM_IDX_TO_TM_IDX(item_idx))) {
            strcat(strbuf, str_color_red);
        }
        strcat(strbuf, str_xf9_x08_clear_to_x1);
        itoa(buffer0, ITEM_IDX_TO_TM_IDX(item_idx) + 1, ITOA_PAD_ZEROS, 2);
        strcat(strbuf, buffer0);
    }
    strcat(strbuf, str_space);
    strcat(strbuf, str_font_size_big);
    strcat(strbuf, attack_names[item_idx_to_attack(item_idx)]);
    strcat(strbuf, str_color_grey);
    strcpy(dst, strbuf);
}

u8 str_lb_is_selected[] = LANGDEP(PSTRING(" \nist ausgewählt!"), PSTRING(" \nis selected!"));

static u8 str_close[] = LANGDEP(PSTRING("Schliessen"), PSTRING("Close"));

void tm_hm_initialize_list_menu() {
    bag_pocket_t *pocket = bag_pockets + POCKET_TM_HM - 1;
    u16 i;
    for (i = 0; i < tm_hm_state->num_tms; i++) {
        tm_hm_get_str_number_and_name(tm_hm_list_menu_strs[i], pocket->items[i].item_idx);
        tm_hm_list_menu_items[i].text = tm_hm_list_menu_strs[i];
        tm_hm_list_menu_items[i].idx = i;
    }
    tm_hm_list_menu_items[i].text = str_close;
    tm_hm_list_menu_items[i].idx = -2;
    gp_list_menu_template.items = tm_hm_list_menu_items;
    gp_list_menu_template.item_cnt = (u16)(tm_hm_state->num_tms + 1);
    gp_list_menu_template.tbox_idx = 0;
    gp_list_menu_template.header_x = 0;
    gp_list_menu_template.item_x = 8;
    gp_list_menu_template.cursor_x = 0;
    gp_list_menu_template.letter_spacing = 0;
    gp_list_menu_template.item_vertical_padding = 2;
    gp_list_menu_template.up_text_y = 2;
    gp_list_menu_template.max_items_showed = tm_hm_state->max_tms_shown;
    gp_list_menu_template.font = 2;
    gp_list_menu_template.cursor_pal = 2;
    gp_list_menu_template.fill_value = 0;
    gp_list_menu_template.cursor_shadow_color = 3;
    gp_list_menu_template.cursor_moved_callback = tm_hm_list_menu_cursor_moved_callback;
    gp_list_menu_template.item_print_callback = tm_vm_print_item;
    gp_list_menu_template.cursor_kind = 0;
    gp_list_menu_template.scroll_multiple = 0;
}

static u8 str_hm_used[] = LANGDEP(
    PSTRING("Diese Tm wurde verbraucht und muss\nerst wieder aufgeladen werden!"),
    PSTRING("This Tm was already used and has to be\nrecharged before use!"));

static void tm_hm_print_hm_used(u8 self) {
    tm_hm_print_string_with_continuation(self, 2, str_hm_used, tm_hm_wait_for_keypress_after_error_message);
}

void tm_hm_context_menu_action_use(u8 self) {
    tm_hm_context_menu_delete(&tm_hm_state->tbox_idx_context);
    tbox_flush_set(2, 0);
    tbox_border_flush(2);
    tbox_flush_map(2);
    tbox_tilemap_draw(0);
    bg_virtual_sync_reqeust_push(0);
    bg_virtual_sync_reqeust_push(1);
    if (player_pokemon_recount_pokemon() == 0) {
        tm_hm_print_no_pokemon(self);
    } else if (tm_is_used(ITEM_IDX_TO_TM_IDX(item_activated))) {
        tm_hm_print_hm_used(self);
    } else {
        item_callback_after_pokemon_selected = item_use_callback_tm_hm;
        tm_hm_state->saved_callback = pokemon_party_menu_open_for_item_use;
        tm_hm_fade_out_and_exit(self);
    }
}

static u8 str_hms_cant_be_recharged[] = LANGDEP(
    PSTRING("Vms müssen nicht aufgeladen werden!"),
    PSTRING("Hms don't need to be recharged!"));

static u8 str_tm_doesnt_need_recharge[] = LANGDEP(
    PSTRING("\nmuss nicht aufgeladen werden!"),
    PSTRING("\ndoesn't need to be recharged!"));

static u8 str_tm_recharged[] = LANGDEP(
    PSTRING("\nwurde wieder aufgeladen."),
    PSTRING("\nwas recharged."));

static void tm_hm_wait_for_keypress_and_exit(u8 self) {
    if (super.keys_remapped.keys.A) {
        tm_hm_fade_out_and_exit(self);
    }
}

static void tm_hm_recharge_wait_for_sound(u8 self) {
    u16 *data = big_callbacks[self].params;
    u16 item_idx = item_get_idx_by_pocket_position(POCKET_TM_HM, data[1]);
    if (!sound_is_playing()) {
        tm_hm_initialize_list_menu(); // Re-build the list menu items to show that the tm is no longer affected
        u16 scroll_offset = 0;
        u16 selected_row = 0;
        list_menu_remove((u8)data[0], &scroll_offset, &selected_row);
        data[0] = (u8)list_menu_new(&gp_list_menu_template, scroll_offset, selected_row);
        tm_hm_get_str_number_and_name(strbuf, item_idx);
        strcat(strbuf, str_tm_recharged);
        tm_hm_print_string_with_continuation(self, 2, strbuf, tm_hm_wait_for_keypress_and_exit);
    }
}

void tm_hm_context_callback_recharge(u8 self) {
    u16 *data = big_callbacks[self].params;
    u16 item_idx = item_get_idx_by_pocket_position(POCKET_TM_HM, data[1]);
    if (item_idx >= ITEM_VM01) { // Can't recharge hms
        tm_hm_print_string_with_continuation(self, 2, str_hms_cant_be_recharged, tm_hm_wait_for_keypress_after_error_message);
    } else if (!tm_is_used(ITEM_IDX_TO_TM_IDX(item_idx))) { // This tm doesn't need recharge
        tm_hm_get_str_number_and_name(strbuf, item_idx);
        strcat(strbuf, str_tm_doesnt_need_recharge);
        tm_hm_print_string_with_continuation(self, 2, strbuf, tm_hm_wait_for_keypress_after_error_message);
    } else { // Recharge tm
        item_remove(ITEM_ENERGIEDISK, 1);
        tm_set_unused(ITEM_IDX_TO_TM_IDX(item_idx));
        play_sound(27);
        big_callbacks[self].function = tm_hm_recharge_wait_for_sound;
    }
}

static void tm_hm_intialize_from_recharge() {
    tm_hm_initialize(TMHM_FROM_RECHARGE, bag_initialize_from_start_menu, 0);
}

void item_field_effect_energiedisk(u8 self) {
    bag_set_continuation(tm_hm_intialize_from_recharge);
    bag_fade_out_and_continuation(self);
}
