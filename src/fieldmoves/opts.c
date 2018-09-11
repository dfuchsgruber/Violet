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

void pokemon_party_menu_opt_build(pokemon *base, u8 index) {
    pokemon_party_menu_opt_state_t *opt_state = pokemon_party_menu_state.opt_state;
    opt_state->opt_cnt = 0;
    pokemon_party_menu_opt_add(opt_state->opts, &opt_state->opt_cnt, 0); //Adding summary
    //adding field moves
    int i;
    for (i = 0; i < 4; i++) {
        u16 attack = (u16) pokemon_get_attribute(&base[index], ATTRIBUTE_ATTACK1 + i, NULL);
        int j;
        for (j = 0; field_moves[j] != 0xFFFF; j++) {
            if (attack == field_moves[j]) {
                pokemon_party_menu_opt_add(opt_state->opts, &opt_state->opt_cnt, (u8) (j + 0x12));
            }
        }
    }
    //adding switch
    if (pokemon_get_attribute(&base[1], ATTRIBUTE_SPECIES, NULL)) {
        //at least two pokemon are present
        pokemon_party_menu_opt_add(opt_state->opts, &opt_state->opt_cnt, 1); //Adding switch
    }
    //Adding back button and items
    pokemon_party_menu_opt_add(opt_state->opts, &opt_state->opt_cnt, 3);
    //Adding ev menu
    if (!pokemon_get_attribute(&base[index], ATTRIBUTE_IS_EGG, NULL) && opt_state->opt_cnt < 7) {
        pokemon_party_menu_opt_add(opt_state->opts, &opt_state->opt_cnt, 6);
    }
    pokemon_party_menu_opt_add(opt_state->opts, &opt_state->opt_cnt, 2);
}


u16 flags[] = {0x820, 0x821, 0x822, 0x823, 0x824, 0x825, 0x826};

void pokemon_party_menu_opt_outdoor_move(u8 callback_self) {
  pokemon_party_menu_opt_state_t *opt_state = pokemon_party_menu_state.opt_state;
    int index = opt_state->opts[pokemon_party_menu_opt_get_current()] - 0x12; //0x12 is outdoor base
    play_sound(0x5);
    if (field_move_initalizers[index].init_func) {
        //now we have to do some checks and then call the init function
        tbox_flush_and_free_if_present(&opt_state->box_id_question);
        tbox_flush_and_free_if_present(&opt_state->box_id_options);
        if (!field_moves_usable() && !map_is_x40_x0()) {
            //HM Moves are bound to a flag
            if (index <= 6 && !checkflag(flags[index])) {
                //Render text "Neuer Orden muss errungen werden"
                u8 *text_new_badge = (u8*) 0x8416940;
                pokemon_party_menu_init_text_rendering(text_new_badge, 1);
                big_callbacks[callback_self].function = pokemon_party_menu_wait_for_text_rendering;
                return;
            } else {
                if (field_move_initalizers[index].init_func()) {
                    //this is where we finally can do the things related to the outdoor moves
                    switch (index) {
                        case 0:
                        case 1:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        case 11:
                        default:
                            //Return to overworld
                            pokemon_party_menu_state.callback = map_reload;
                            field_move_load_buffers(&player_pokemon[pokemon_party_menu_opt_get_current()], (u8) index);
                            break;
                        case 2:
                            //Fly
                            pokemon_party_menu_state.callback = field_move_fly_init;
                            break;
                        case 7:
                            //Teleport 
                            map_load_namespace(buffer0,
                            		get_mapheader((u8) save1->healingplace.bank,
                            				(u8) save1->healingplace.map)->name_bank);
                            string_decrypt(strbuf, (u8*) 0x084175B5);
                            pokemon_party_menu_print_question(callback_self);
                            *((u16*) ((int) (pokemon_party_menu_state.opt_state) + 0x218)) = (u8) index;
                            return;
                        case 8:
                            //Dig
                            map_load_namespace(buffer0, get_mapheader((u8) save1->last_outdoor_bank, (u8) save1->last_outdoor_map)->name_bank);
                            string_decrypt(strbuf, (u8*) 0x0841758A);
                            pokemon_party_menu_print_question(callback_self);
                            *((u16*) ((int) (pokemon_party_menu_state.opt_state) + 0x218)) = (u8) index;
                            return;
                        case 9:
                        case 10:
                            //Softboiled, etc. -> Select Pokemon for heal
                            field_move_softboiled_init(callback_self);
                            return;
                    }
                    pokemon_party_menu_return_and_execute_callback(callback_self);
                    return;

                } else {
                    //init of the outdoor move failed, now react properly
                    if (index == 4) { //Index is Surfer which has many different error messages and a own function to print the proper one
                        field_move_surfer_print_error();
                    } else {
                        u8 string = (u8) field_move_initalizers[index].not_usable_msg;
                        if (!index) { //Flash has two different error messages
                            if (checkflag(0x806)) {
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
            u8 string = (u8) field_move_initalizers[index].not_usable_msg;
            if (index >= 9 && index <= 10) {
                string = 13;
            }
            pokemon_party_menu_opt_clear_all_and_printstr(string);
        }
        //Wait until player presses key and then return to selection
        big_callbacks[callback_self].function = pokemon_party_menu_wait_for_keypress_and_return_to_opts;
    }
}
