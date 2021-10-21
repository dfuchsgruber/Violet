#include "pc.h"
#include "callbacks.h"
#include "constants/pokemon_attributes.h"
#include "constants/vars.h"
#include "debug.h"
#include "fading.h"
#include "list_menu.h"
#include "music.h"
#include "overworld/map_control.h"
#include "pokemon/virtual.h"
#include "pokepad/incubator.h"
#include "pokepad/wondertrade.h"
#include "save.h"
#include "superstate.h"
#include "text.h"
#include "types.h"
#include "vars.h"

void pc_initialize_for_selection_big_callback(u8 self) {
    if (!fading_control.active) {
        overworld_free();
        pc_initialize(PC_MODE_SELECT);
        big_callback_delete(self);
    }
}

void special_initialize_pc_for_selection() {
    *var_access(0x8004) = 0x0;
    *var_access(0x8005) = 0x0;
    *var_access(0x8006) = 0x0;
    fmem.pc_selection_context = PC_SELECTION_CONTEXT_ANY;
    fadescreen_all(1, 0);
    big_callback_new(pc_initialize_for_selection_big_callback, 0);
}

void pc_exit() {
    pc_last_used_mode = pc_get_mode();
    if (pc_get_mode() == PC_MODE_SELECT) {
        switch (fmem.pc_selection_context) {
            case PC_SELECTION_CONTEXT_CHOOSE_WONDERTRADE:
                callback1_set(wondertrade_callback_after_selection);
                vblank_handler_set(generic_vblank_handler);
                return;
            case PC_SELECTION_CONTEXT_CHOOSE_EGG:
                callback1_set(incubator_callback1_party_menu_continuation);
                vblank_handler_set(generic_vblank_handler);
                return;
        }
    }
    map_reload_continuation = pc_reinitialize_selection;
    callback1_set(map_reload);
}

static void pc_selection_eligible(u8 self) {
    (void)self;
    switch (pc_state->state) {
        case 0: {
            box_pokemon *p = pokemon_get_by_box(pc_box_idx_get(), pc_slot_in_box);
            switch (fmem.pc_selection_context) {
                case PC_SELECTION_CONTEXT_ANY:
                    pc_state->state = 2;
                    break;
                case PC_SELECTION_CONTEXT_CHOOSE_EGG: {
                    if (box_pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, NULL)) {
                        pc_state->state = 2;
                    } else {
                        pc_context_menu_print_text(PC_CONTEXT_TEXT_SELECT_EGG);
                        pc_state->state++;
                    }
                    break;
                }
                case PC_SELECTION_CONTEXT_CHOOSE_WONDERTRADE: {
                    if (box_pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, NULL)) {
                        pc_context_menu_print_text(PC_CONTEXT_TEXT_CANT_TRADE_EGGS);
                        pc_state->state++;
                    } else if (pokemon_knows_hm(p)) {
                        pc_context_menu_print_text(PC_CONTEXT_TEXT_CANT_TRADE_HM_USER);
                        pc_state->state++;
                    } else {
                        pc_state->state = 2;
                        break;
                    }
                }
            }
            break;
        }
        case 1: {
            if (super.keys_new.keys.A || super.keys_new.keys.B || super.keys_new.keys.up || super.keys_new.keys.down || super.keys_new.keys.right || super.keys_new.keys.left) {
                pc_context_menu_flush();
                pc_set_callback(pc_callback);
            }
            break;
        }
        case 2: {
            *var_access(0x8004) = pc_box_idx_get();
            *var_access(0x8005) = pc_slot_in_box;
            *var_access(0x8006) = true;
            pc_close_animation_start(0x14, 0, 1);
            pc_state->state++;
            break;
        }
        case 3: {
            if (!pc_close_animation_is_running()) {
                pc_close_update_flags_and_vars();
                player_pokemon_recount_pokemon();
                pc_state->continuation_type = 0;
                pc_set_callback(pc_close_continuation);
            }
            break;
        }
    }
}

static void pc_handle_confirm_selection(u8 self) {
    (void)self;
    switch (pc_state->state) {
        case 0:
            pc_context_menu_print_text(PC_CONTEXT_TEXT_SELECT_THIS_ONE);
            pc_show_yes_no(-1);
            pc_state->state++;
            break;
        case 1: {
            switch (gp_list_menu_process_input_and_close_on_selection()) {
                case -1: // For some odd reason, a B-press is indicated by -1 instead of LIST_MENU_B_PRESSED...
                case 1:
                    pc_context_menu_flush();
                    pc_set_callback(pc_callback);
                    break;
                case 0:
                    pc_context_menu_flush();
                    pc_set_callback(pc_selection_eligible);
                    break;
            }
            break;
        }
    }
}

void pc_handle_context_on_pokemon_consider_new_modes() {
    dprintf("Pc context on mon.\n");
    // Wrapper arround the original function, as it is big and I am too lazy to reimplement and test it from scratch...
    if (pc_state->mode == PC_MODE_SELECT && pc_state->state == 2) {
        switch (pc_context_menu_handle_inputs()) {
            case -1:
            case PC_CONTEXT_MENU_ITEM_CANCEL:
                pc_context_menu_flush();
                pc_set_callback(pc_callback);
                break;
            case PC_CONTEXT_MENU_ITEM_SUMMARY:
                play_sound(5);
                pc_set_callback(pc_callback_show_summary);
                break;
            case PC_CONTEXT_MENU_ITEM_SELECT:
                play_sound(5);
                pc_set_callback(pc_handle_confirm_selection);
                break;
        }
    } else {
        pc_handle_context_on_pokemon();
    }
}

static bool pc_context_menu_build_context_on_pokemon_select() {
    if (pc_get_current_species()) {
        pc_context_menu_add_item(PC_CONTEXT_MENU_ITEM_SELECT);
        pc_context_menu_add_item(PC_CONTEXT_MENU_ITEM_SUMMARY);
        pc_context_menu_add_item(PC_CONTEXT_MENU_ITEM_CANCEL);
        return true;
    }
    return false;
}

bool pc_context_menu_build_context_on_pokemon() {
    pc_context_menu_reset();
    switch (pc_state->mode) {
        case PC_MODE_MOVE_ITEMS:
            return pc_context_menu_build_context_on_pokemon_move_items();
        case PC_MODE_SELECT:
            return pc_context_menu_build_context_on_pokemon_select();
        default:
            return pc_context_menu_build_context_on_pokemon_dont_move_items();
    }
}
