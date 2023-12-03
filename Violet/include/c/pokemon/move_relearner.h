#ifndef H_POKEMON_MOVE_RELEARNER
#define H_POKEMON_MOVE_RELEARNER

#include "types.h"
#include "list_menu.h"
#include "pokemon/virtual.h"
#include "constants/move_tutor.h"

typedef struct {
    u8 state;
    u8 unk_01;
    u8 unk_02;
    u8 oam_idxs[2];
    u8 filler_05[0x13];
    u8 unk_18;
    u8 scroll_position_maybe;
    u8 num_learnable_moves;
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    list_menu_item list_menu_items[25];
    u16 learnable_moves[25];
    u8 learnable_move_strings[25][13];
    u8 move_info_update_scheduled;
    u8 party_idx;
    u8 pokemon_move_idx;
    u8 unk_262;
    u8 list_menu_callback_idx;
    u8 bg1_tilemap[0x800];
    u8 text_color[3];
    u8 move_idx;
    u16 list_menu_scroll;
    u16 list_menu_row;
} move_relearner_state_t;

typedef struct {
    u8 bank;
    u8 map_idx;
    u8 person_idx;
    u8 filler;
} move_tutor_t;

extern const move_tutor_t move_tutors[NUM_MOVE_TUTORS];

extern move_relearner_state_t *move_relearner_state;


/**
 * Gets all moves relearnable by a pokemon.
 * @param p the pokemon to get relearnable moves of
 * @param moves where to put the moves
 * @return how many moves are relearnable and where put
 **/
u8 move_relearner_get_moves(const pokemon *p, u16 *moves);

/**
 * Prints a string.
 * @param tbox_idx in which box to print
 * @param str the text to print
 * @param x x coordinate within box
 * @param y y coordinate within box
 * @param speed text speed for the printer
 * @param color_idx which color to use
 **/
void move_relearner_print_string(u8 tbox_idx, const u8 *str, u8 x, u8 y, int speed, int color_idx);

extern const list_menu_template move_relearner_list_menu_template; // static ROM structure

/**
 * @brief Gets the moves to be learned by a accessible move tutor of a type
 * 
 * @param p the pokemon
 * @param moves where to put the moves
 * @param type the type of the move tutor
 * @return u8 how many moves are applicable
 */
u8 pokemon_get_accesible_learnable_moves(const pokemon *p, u16 *moves, u8 type);

/**
 * Sets the flag of a move tutor
 * @param move_tutor the move tutor
*/
void move_tutor_set_flag(u8 move_tutor);

#endif