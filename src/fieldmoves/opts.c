/* 
 * File:   opts.c
 * Author: Domi
 *
 * Created on 14. Juni 2016, 10:43
 */

#include "types.h"
#include "fieldmoves.h"
#include "romfuncs.h"
#include "pokemon.h"
#include "callbacks.h"
#include "save.h"
#include "pstring.h"
#include "map.h"


void pokemenu_build_opt_by_pokemon(pokemon *base, u8 index){
    pokemenu_opt_state *opt_state = pokemenu_state->opt_state;
    opt_state->opt_cnt = 0;
    list_add(opt_state->opts, &opt_state->opt_cnt, 0); //Adding summary
    //adding field moves
    int i;
    for(i = 0; i < 4; i++){
        u16 attack = (u16)get_pokemons_attribute(&base[index], ATTRIBUTE_ATTACK1+i, NULL);
        int j;
        for (j = 0; table_field_moves[j] != 0xFFFF; j++){
            if(attack == table_field_moves[j]){
                list_add(opt_state->opts, &opt_state->opt_cnt, (u8)(j+0x12));
            }
        }
    }
    //adding switch
    if(!get_pokemons_attribute(&base[1], ATTRIBUTE_SPECIES, NULL)){
        //at least two pokemon are present
        list_add(opt_state->opts, &opt_state->opt_cnt, 1); //Adding summary
    }
    //Adding back button and items
    list_add(opt_state->opts, &opt_state->opt_cnt, 3);
    //Adding ev menu
    if(!get_pokemons_attribute(&base[index], ATTRIBUTE_IS_EGG, NULL) && opt_state->opt_cnt < 7){
        list_add(opt_state->opts, &opt_state->opt_cnt, 6);
    }
    list_add(opt_state->opts, &opt_state->opt_cnt, 2);
}


u16 flags[] = {0x820, 0x821, 0x822, 0x823, 0x824, 0x825, 0x826};

void pokemenu_opt_outdoor_move(u8 callback_self){
    pokemenu_opt_state *opt_state = pokemenu_state->opt_state;
    int index = opt_state->opts[pokemon_menu_context_get_current_item_index()] - 0x12; //0x12 is outdoor base
    sound(0x5);
    if (table_outdoor_move_initializers[index].init_func){
        //now we have to do some checks and then call the init function
        tbox_flush_and_free_if_present(&opt_state->box_id_question);
        tbox_flush_and_free_if_present(&opt_state->box_id_options);
        if (!outdoor_moves_usable() && !map_is_x40_x0()){
            //HM Moves are bound to a flag
            if (index <= 6 && !checkflag(flags[index])){
                //Render text "Neuer Orden muss errungen werden"
                u8 *text_new_badge = (u8*)0x8416940;
                pokemenu_init_textrenderer(text_new_badge, 1);
                big_callbacks[callback_self].function = pokemenu_task_wait_for_textrenderer;
                return;
            }else{
                if(table_outdoor_move_initializers[index].init_func()){
                    //this is where we finally can do the things related to the outdoor moves
                    switch(index){
                        case 0:
                        case 1:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        case 11:
                        default:
                            //Return to overworld
                            pokemenu_state->callback = map_reload;
                            outdoor_move_buffer_load(&player_pokemon[pokemenu_get_selected_poke_index()], (u8)index);
                            break;
                        case 2:
                            //Fly
                            pokemenu_state->callback = pokemenu_init_fly;
                            break;
                        case 7:
                            //Teleport 
                            map_load_namespace(buffer0, get_mapheader((u8)(*save1)->healingplace_bank, (u8)(*save1)->healingplace_map)->name_bank);
                            string_decrypt(gbuffer, (pstring)0x084175B5);
                            pokemenu_print_string_as_yes_no(callback_self);
                            *((u16*)((int)(pokemenu_state->opt_state)+0x218)) = (u8)index;
                            return;
                        case 8:
                            //Dig
                            map_load_namespace(buffer0, get_mapheader((u8)(*save1)->last_outdoor_bank, (u8)(*save1)->last_outdoor_map)->name_bank);
                            string_decrypt(gbuffer, (pstring)0x0841758A);
                            pokemenu_print_string_as_yes_no(callback_self);
                            *((u16*)((int)(pokemenu_state->opt_state)+0x218)) = (u8)index;
                            return;
                        case 9:
                        case 10:
                            //Softboiled, etc. -> Select Pokemon for heal
                            pokemenu_prepeare_softboiled(callback_self);
                            return;
                    }
                    pokemenu_fade_and_execute_callback(callback_self);
                    return;

                }else{
                    //init of the outdoor move failed, now react properly
                    if (index == 4){ //Index is Surfer which has many different error messages and a own function to print the proper one
                        surfer_init_proper_error_message();
                    }else{
                        u8 string = (u8)table_outdoor_move_initializers[index].not_usable_msg;
                        if (!index){ //Flash has two different error messages
                            if(checkflag(0x806)){
                                string = 12;//Flash was already used
                            }else{
                                string = 13; //Hier nicht einsetzbar
                            }
                        }
                        pokemenu_opts_clear_pokemenu_and_printstr(string);
                    }
                    big_callbacks[callback_self].function = pokemenu_task_wait_for_keypress_and_return_to_select;
                }
            }
            
        }else{
            //print string for "Hier nicht einsetzbar"
            u8 string = (u8)table_outdoor_move_initializers[index].not_usable_msg;
            if (index >= 9 && index <= 10){
                string = 13;
            }
            pokemenu_opts_clear_pokemenu_and_printstr(string);
        }
        //Wait until player presses key and then return to selection
        big_callbacks[callback_self].function = pokemenu_task_wait_for_keypress_and_return_to_select;
    }
}