#include "types.h"
#include "pokemon/virtual.h"
#include "item/item.h"
#include "overworld/pokemon_party_menu.h"
#include "abilities.h"
#include "bg.h"
#include "text.h"
#include "music.h"
#include "callbacks.h"
#include "language.h"
#include "pokemon/basestat.h"
#include "debug.h"
#include "list_menu.h"
#include "agbmemory.h"

static u8 str_success[] = LANGDEP(
    PSTRING("Die Fähigkeit von BUFFER_2\nwurde zu BUFFER_1.PAUSE_UNTIL_PRESS"), 
    PSTRING("The ability of BUFFER_2\nwas changed to BUFFER_1.PAUSE_UNTIL_PRESS")
);
static u8 str_ask_change_ability[] = LANGDEP(
    PSTRING("Die Fähigkeit von BUFFER_2\nzu BUFFER_1 ändern?"),
    PSTRING("Change BUFFER_2's\nability to BUFFER_1?")
);

static tboxdata tboxdata_ability_description = {
    .bg_id = 2, .x = 1, .y = 1, .w = 28, .h = 4, .pal = 15, .start_tile = 0x2BF + 6 * 4
};

static u8 pokemon_party_menu_ability_description_new(u8 ability) {
    u8 tbox_idx = tbox_new(&tboxdata_ability_description);
    DEBUG("New box is %d\n", tbox_idx);
    tbox_flush_set(tbox_idx, 0x11);
    tbox_tilemap_draw(tbox_idx);
    tbox_draw_std_frame_by_base_tile_and_pal(tbox_idx, false, 88, 15);
    tbox_font_colormap fontcolmap = {.background = 1, .body = 2, .edge = 3};
    tbox_print_string(tbox_idx, 0, 8, 0, 0, 0, &fontcolmap, 0xFF, ability_names[ability]);
    tbox_print_string(tbox_idx, 2, 0, 16, 0, 0, &fontcolmap, 0, ability_descriptions[ability]);
    return tbox_idx;
}

static void wait_sound_and_print_success_text(u8 self) {
    if (!sound_is_playing()) {
        u8 party_idx = pokemon_party_menu_current_index;
        pokemon_party_menu_use_return_callback = false;
        u8 ability = pokemon_get_ability(player_pokemon + party_idx);
        strcpy(buffer0, ability_names[ability]);
        u8 nickname[11];
        pokemon_get_attribute(player_pokemon + party_idx, ATTRIBUTE_NICKNAME, nickname);
        pokemon_copy_nickname(buffer1, nickname);
        string_decrypt(strbuf, str_success);
        pokemon_party_menu_init_text_rendering(strbuf, self);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = pokemon_party_menu_wait_for_text_and_close;
    }
}

static void item_callback_ability_change_handle_yes_no(u8 self) {
    switch (gp_list_menu_process_input_and_close_on_selection()) {
        case 0: { // yes
            u8 tbox_idx_ability_description = (u8)(u8)big_callbacks[self].params[0];
            tbox_flush_map_and_frame(tbox_idx_ability_description);
            tbox_free(tbox_idx_ability_description);
            u8 party_idx = pokemon_party_menu_current_index;
            void (*ability_change_function)(pokemon*) = (void (*)(pokemon*)) big_callback_get_int(self, 1);
            ability_change_function(player_pokemon + party_idx);
            play_sound(27);
            item_remove(item_activated, 1);
            big_callbacks[self].function = wait_sound_and_print_success_text;
            break;
        }
        case 1:
        case GP_LIST_MENU_B_PRESSED: { // no
            u8 tbox_idx_ability_description = (u8)(u8)big_callbacks[self].params[0];
            tbox_flush_map_and_frame(tbox_idx_ability_description);
            tbox_free(tbox_idx_ability_description);
            
            bg_virtual_sync_reqeust_push(2);
            big_callbacks[self].function = pokemon_party_menu_wait_for_text_and_close;
            break;
        }
    }
}

static void item_callback_ability_change_wait_for_question(u8 self) {
    if (!pokemon_party_menu_tbox_printer_is_active()) {
        pokemon_party_menu_yes_no_menu_new();
        big_callbacks[self].function = item_callback_ability_change_handle_yes_no;
    }
}

static void item_callback_ability_enable_hidden_ability(pokemon *p) {
    pokemon_set_hidden_ability(&p->box);
}

static void item_callback_ability_disable_hidden_ability(pokemon *p) {
    pokemon_remove_hidden_ability(&p->box);
}

static void item_callback_ability_switch_abilities(pokemon *p) {
    bool ability = (bool)pokemon_get_attribute(p, ATTRIBUTE_ABILITY, NULL);
    ability ^= 1;
    pokemon_set_attribute(p, ATTRIBUTE_ABILITY, &ability);
}

static void item_callback_ability_ask_change_abilities(u8 self, void (*ability_changer)(pokemon*)) {
    u8 party_idx = pokemon_party_menu_current_index;
    pokemon_party_menu_use_return_callback = false;
    // To find the new ability, change the ability of a copy of the original
    pokemon *tmp = malloc(sizeof(pokemon));
    memcpy(tmp, player_pokemon + party_idx, sizeof(pokemon));
    ability_changer(tmp);
    u8 ability = pokemon_get_ability(tmp);
    strcpy(buffer0, ability_names[ability]);
    u8 nickname[11];
    pokemon_get_attribute(player_pokemon + party_idx, ATTRIBUTE_NICKNAME, nickname);
    pokemon_copy_nickname(buffer1, nickname);
    string_decrypt(strbuf, str_ask_change_ability);
    pokemon_party_menu_print_string_and_wait(strbuf, true);
    big_callbacks[self].params[0] = pokemon_party_menu_ability_description_new(ability);
    big_callback_set_int(self, 1, (int)ability_changer);
    big_callbacks[self].function = item_callback_ability_change_wait_for_question;
    bg_virtual_sync_reqeust_push(2);
    free(tmp);
}

static void item_callback_ability_patch(u8 self, void (*exit_continuation)(u8)) {
    u8 party_idx = pokemon_party_menu_current_index;
    if (pokemon_has_hidden_ability(&player_pokemon[party_idx].box)) { 
        pokemon_party_menu_use_return_callback = false;
        pokemon_party_menu_init_text_rendering(str_item_has_no_effect, self);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = exit_continuation;
    } else {
        item_callback_ability_ask_change_abilities(self, item_callback_ability_enable_hidden_ability);
    }
}

void item_ability_patch_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_ability_patch;
    item_field_fade_to_scene_and_execute_callback(self);
}

static void item_callback_anti_ability_patch(u8 self, void (*exit_continuation)(u8)) {
    u8 party_idx = pokemon_party_menu_current_index;
    if (!pokemon_has_hidden_ability(&player_pokemon[party_idx].box)) { 
        pokemon_party_menu_use_return_callback = false;
        pokemon_party_menu_init_text_rendering(str_item_has_no_effect, self);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = exit_continuation;
    } else {
        item_callback_ability_ask_change_abilities(self, item_callback_ability_disable_hidden_ability);
    }
}

void item_anti_ability_patch_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_anti_ability_patch;
    item_field_fade_to_scene_and_execute_callback(self);
}

static void item_callback_ability_capsule(u8 self, void (*exit_continuation)(u8)) {
    u8 party_idx = pokemon_party_menu_current_index;
    u16 species = (u16)pokemon_get_attribute(player_pokemon + party_idx, ATTRIBUTE_SPECIES2, NULL);
    // DEBUG("Pokemon has ability0 %d and ability 1 %d @0x%x\n", basestats[species].ability1, basestats[species].ability2, &basestats[species].ability1);
    if (pokemon_has_hidden_ability(&player_pokemon[party_idx].box) || basestats[species].ability1 == basestats[species].ability2 || basestats[species].ability2 == 0) { 
        pokemon_party_menu_use_return_callback = false;
        pokemon_party_menu_init_text_rendering(str_item_has_no_effect, self);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = exit_continuation;
    } else {
        item_callback_ability_ask_change_abilities(self, item_callback_ability_switch_abilities);
    }
}

void item_ability_capsule_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_ability_capsule;
    item_field_fade_to_scene_and_execute_callback(self);
}