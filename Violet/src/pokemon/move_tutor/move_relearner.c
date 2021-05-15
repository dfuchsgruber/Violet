#include "types.h"
#include "pokemon/virtual.h"
#include "pokemon/moves.h"
#include "pokemon/move_relearner.h"
#include "vars.h"
#include "constants/pokemon_types.h"
#include "attack.h"
#include "language.h"

u8 pokemon_get_accesible_learnable_moves(pokemon *p, u16 *moves, u8 type) {
    u16 species = (u16)pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
    u16 *accesible = pokemon_accessible_moves[species];
    if (!accesible)
        return 0;
    u16 current_moves[4];
    for (int i = 0; i < 4; i++)
        current_moves[i] = (u16) pokemon_get_attribute(p, (u8)(ATTRIBUTE_ATTACK1 + i), 0);
    u8 num_moves = 0;
    for (int i = 0; accesible[i] != 0xFFFF; i++) {
        if (attacks[accesible[i]].type != type)
            continue;
        bool add_to_list = true;
        for (int j = 0; j < 4; j++) {
            if (current_moves[j] == accesible[i]) {
                add_to_list = false;
                break;
            }
        }
        for (int j = 0; j < num_moves; j++) {
            if (moves[j] == accesible[i]) {
                add_to_list = false;
                break;
            }
        }
        if (add_to_list) {
            moves[num_moves++] = accesible[i];
        }
    }
    return num_moves;
}

static u8 str_back[] = LANGDEP(PSTRING("Zurück"), PSTRING("Cancel"));

void move_relearner_initialize_list_menu() {
    u8 nickname[11]; 
    pokemon *p = player_pokemon + move_relearner_state->party_idx;
    u16 type = *var_access(VAR_ACCESIBLE_MOVE_TUTOR_TYPE);
    if (type == 0xFFFF) {
        move_relearner_state->num_learnable_moves = move_relearner_get_moves(p, move_relearner_state->learnable_moves);
    } else {
        move_relearner_state->num_learnable_moves = pokemon_get_accesible_learnable_moves(p, move_relearner_state->learnable_moves, (u8)type);
    }
    u8 count = move_relearner_state->num_learnable_moves;
    for (int i = 0; i < count; i++) {
        u8 *attack_name = attack_names[move_relearner_state->learnable_moves[i]];
        strcpy(move_relearner_state->learnable_move_strings[i], attack_name);
    }
    pokemon_get_attribute(p, ATTRIBUTE_NICKNAME, nickname);
    pokemon_copy_nickname(buffer0, nickname);
    strcpy(move_relearner_state->learnable_move_strings[count], str_back);
    move_relearner_state->num_learnable_moves++;
    for (int i = 0; i < count; i++) {
        move_relearner_state->list_menu_items[i].text = move_relearner_state->learnable_move_strings[i];
        move_relearner_state->list_menu_items[i].idx = i;
    }
    move_relearner_state->list_menu_items[count].text = str_back;
    move_relearner_state->list_menu_items[count].idx = 0xFE;
    gp_list_menu_template = move_relearner_list_menu_template;
    gp_list_menu_template.items = move_relearner_state->list_menu_items;
    gp_list_menu_template.item_cnt = (u16)(count + 1);
}