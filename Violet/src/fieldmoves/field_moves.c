/* 
 * File:   opts.c
 * Author: Domi
 *
 * Created on 14. Juni 2016, 10:43
 */

#include "types.h"
#include "field_move.h"
#include "pokemon/virtual.h"
#include "overworld/pokemon_party_menu.h"
#include "constants/pokemon_attributes.h"
#include "callbacks.h"
#include "save.h"
#include "text.h"
#include "music.h"
#include "flags.h"
#include "map/namespace.h"
#include "overworld/map_control.h"
#include "constants/map_types.h"
#include "constants/flags.h"
#include "constants/field_moves.h"
#include "constants/attacks.h"
#include "constants/flags.h"
#include "superstate.h"

static field_move_t field_move_checks[NUM_FIELD_MOVES] = {
    [FIELD_MOVE_FLASH] = {.function = field_move_check_flash, .failure_message_idx = 13},
	[FIELD_MOVE_CUT] = {.function = field_move_check_cut, .failure_message_idx = 7},
	[FIELD_MOVE_FLY] = {.function = field_move_check_fly, .failure_message_idx = 13},
	[FIELD_MOVE_STRENGTH] = {.function = field_move_check_strength, .failure_message_idx = 13},
	[FIELD_MOVE_SURF] = {.function = field_move_check_surf, .failure_message_idx = 8},
	[FIELD_MOVE_ROCK_SMASH] = {.function = field_move_check_rock_smash, .failure_message_idx = 13},
	[FIELD_MOVE_WATERFALL] = {.function = field_move_check_waterfall, .failure_message_idx = 13},
	[FIELD_MOVE_ROCK_CLIMB] = {.function = field_move_check_rock_climb, .failure_message_idx = 13},
	[FIELD_MOVE_TELEPORT] = {.function = field_move_check_teleport, .failure_message_idx = 13},
	[FIELD_MOVE_DIG] = {.function = field_move_check_dig, .failure_message_idx = 13},
	[FIELD_MOVE_MILK_DRINK] = {.function = field_move_check_softboiled, .failure_message_idx = 16},
	[FIELD_MOVE_SOFTBOILED] = {.function = field_move_check_softboiled, .failure_message_idx = 16},
	[FIELD_MOVE_SWEET_SCENT] = {.function = field_move_check_sweet_scent, .failure_message_idx = 13},
	[FIELD_MOVE_SECRET_POWER] = {.function = field_move_check_secret_power, .failure_message_idx = 13},
};

u16 field_moves[NUM_FIELD_MOVES + 1] = {
    [FIELD_MOVE_FLASH] = ATTACK_BLITZ,
	[FIELD_MOVE_CUT] = ATTACK_ZERSCHNEIDER,
	[FIELD_MOVE_FLY] = ATTACK_FLIEGEN,
	[FIELD_MOVE_STRENGTH] = ATTACK_STAERKE,
	[FIELD_MOVE_SURF] = ATTACK_SURFER,
	[FIELD_MOVE_ROCK_SMASH] = ATTACK_ZERTRUEMMERER,
	[FIELD_MOVE_WATERFALL] = ATTACK_KASKADE,
	[FIELD_MOVE_ROCK_CLIMB] = ATTACK_KRAXLER,
	[FIELD_MOVE_TELEPORT] = ATTACK_TELEPORT,
	[FIELD_MOVE_DIG] = ATTACK_SCHAUFLER,
	[FIELD_MOVE_MILK_DRINK] = ATTACK_MILCHGETRAENK,
	[FIELD_MOVE_SOFTBOILED] = ATTACK_WEICHEI,
	[FIELD_MOVE_SWEET_SCENT] = ATTACK_LOCKDUFT,
	[FIELD_MOVE_SECRET_POWER] = ATTACK_GEHEIMPOWER,
    [NUM_FIELD_MOVES] = 0xFFFF
};

u8 *field_move_descriptions[NUM_FIELD_MOVES] = {
    [FIELD_MOVE_FLASH] = str_field_move_description_flash,
	[FIELD_MOVE_CUT] = str_field_move_description_cut,
	[FIELD_MOVE_FLY] = str_field_move_description_fly,
	[FIELD_MOVE_STRENGTH] = str_field_move_description_strength,
	[FIELD_MOVE_SURF] = str_field_move_description_surf,
	[FIELD_MOVE_ROCK_SMASH] = str_field_move_description_rock_smash,
	[FIELD_MOVE_WATERFALL] = str_field_move_description_waterfall,
	[FIELD_MOVE_ROCK_CLIMB] = str_field_move_description_rock_climb,
	[FIELD_MOVE_TELEPORT] = str_field_move_description_teleport,
	[FIELD_MOVE_DIG] = str_field_move_description_dig,
	[FIELD_MOVE_MILK_DRINK] = str_field_move_description_milk_drink,
	[FIELD_MOVE_SOFTBOILED] = str_field_move_description_softboiled,
	[FIELD_MOVE_SWEET_SCENT] = str_field_move_description_sweet_scent,
	[FIELD_MOVE_SECRET_POWER] = str_field_move_description_secret_power,
};

u16 field_move_flags[] = {FRBADGE_1, FRBADGE_2, FRBADGE_3, FRBADGE_5, FRBADGE_4, FRBADGE_6,
		FRBADGE_7, FRBADGE_8};


void pokemon_party_menu_option_outdoor_move(u8 callback_self) {
  pokemon_party_menu_options_state_t *options_state = pokemon_party_menu_state.options_state;
    int index = options_state->options[pokemon_party_menu_opt_get_current()] - 0x12; //0x12 is outdoor base
    play_sound(0x5);
    if (field_move_checks[index].function) {
        //now we have to do some checks and then call the init function
        tbox_flush_and_free_if_present(&options_state->tbox_idx_question);
        tbox_flush_and_free_if_present(&options_state->tbox_idx_options);
        if (!sub_080bf8d8() && !map_is_x40_x0()) {
            // HM Moves are bound to a flag
            if (index <= 7 && !checkflag(field_move_flags[index])) {
                //Render text "Neuer Orden muss errungen werden"
                pokemon_party_menu_init_text_rendering(str_field_move_usable_with_new_badge, 1);
                big_callbacks[callback_self].function = pokemon_party_menu_wait_for_text_rendering;
                return;
            } else {
                if (field_move_checks[index].function()) {
                    //this is where we finally can do the things related to the outdoor moves
                    switch (index) {
                        default:
                            // Return to overworld
                            pokemon_party_menu_state.callback = map_reload;
                            field_move_load_buffers(&player_pokemon[pokemon_party_menu_opt_get_current()], (u8) index);
                            break;
                        case FIELD_MOVE_FLY:
                            //Fly
                            pokemon_party_menu_state.callback = field_move_fly_init;
                            break;
                        case FIELD_MOVE_TELEPORT:
                            //Teleport 
                            map_load_namespace(buffer0,
                            		get_mapheader((u8) save1->healingplace.bank,
                            				(u8) save1->healingplace.map)->map_namespace);
                            string_decrypt(strbuf, str_field_move_return_to_healing_place);
                            pokemon_party_menu_print_question(callback_self);
                            options_state->outdoor_move_idx = (u8) index;
                            return;
                        case FIELD_MOVE_DIG:
                            //Dig
                            map_load_namespace(buffer0,
                            		get_mapheader(save1->last_outdoor_map.bank,
                            				save1->last_outdoor_map.map)->map_namespace);
                            string_decrypt(strbuf, (u8*) str_field_move_return_dig);
                            pokemon_party_menu_print_question(callback_self);
                            options_state->outdoor_move_idx = (u8) index;
                            return;
                        case FIELD_MOVE_SOFTBOILED:
                        case FIELD_MOVE_MILK_DRINK:
                            //Softboiled, etc. -> Select Pokemon for heal
                            field_move_softboiled_init(callback_self);
                            return;
                    }
                    pokemon_party_menu_return_and_execute_callback(callback_self);
                    return;

                } else {
                    //init of the outdoor move failed, now react properly
                    if (index == FIELD_MOVE_SURF) { //Index is Surfer which has many different error messages and a own function to print the proper one
                        field_move_surfer_print_error();
                    } else {
                        u8 string = (u8) field_move_checks[index].failure_message_idx;
                        if (index == FIELD_MOVE_FLASH) { //Flash has two different error messages
                            if (checkflag(FLASH_USED)) {
                                string = 12; //Flash was already used
                            } else {
                                string = 13; //Hier nicht einsetzbar
                            }
                        }
                        pokemon_party_menu_opt_clear_all_and_printstr(string);
                    }
                    big_callbacks[callback_self].function = pokemon_party_menu_wait_for_keypress_and_return_to_opts;
                }
            }

        } else {
            //print string for "Hier nicht einsetzbar"
            u8 string = (u8) field_move_checks[index].failure_message_idx;
            if (index == FIELD_MOVE_SOFTBOILED || index == FIELD_MOVE_MILK_DRINK) {
                string = 13;
            }
            pokemon_party_menu_opt_clear_all_and_printstr(string);
        }
        //Wait until player presses key and then return to selection
        big_callbacks[callback_self].function = pokemon_party_menu_wait_for_keypress_and_return_to_opts;
    }
}

bool map_type_enables_fly_or_teleport(u8 type) {
	return (type == MAP_TYPE_ROUTE || type == MAP_TYPE_VILLAGE || type == MAP_TYPE_TYPE_06 ||
			type == MAP_TYPE_CITY || type == MAP_TYPE_CLOUD);
}
