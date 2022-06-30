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

static u8 str_success[] = LANGDEP(PSTRING("Die Fähigkeit von BUFFER_2\nwurde zu BUFFER_1.PAUSE_UNTIL_PRESS"), PSTRING("The ability of BUFFER_2\nwas changed to BUFFER_1.PAUSE_UNTIL_PRESS"));

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

static void item_callback_ability_patch(u8 self, void (*exit_continuation)(u8)) {
    u8 party_idx = pokemon_party_menu_current_index;
    if (pokemon_has_hidden_ability(&player_pokemon[party_idx].box)) {
        pokemon_party_menu_use_return_callback = false;
        pokemon_party_menu_init_text_rendering(str_item_has_no_effect, self);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = exit_continuation;
    } else {
        pokemon_set_hidden_ability(&player_pokemon[party_idx].box);
        play_sound(27);
        item_remove(item_activated, 1);
        big_callbacks[self].function = wait_sound_and_print_success_text;
    }
}

void item_ability_patch_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_ability_patch;
    item_field_fade_to_scene_and_execute_callback(self);
}