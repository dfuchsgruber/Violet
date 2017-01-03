/* 
 * File:   fieldmoves.h
 * Author: Domi
 *
 * Created on 12. Juni 2016, 19:05
 */

#ifndef FIELDMOVES_H
#define	FIELDMOVES_H

#include "types.h"
#include "stdbool.h"
#include "pokemon.h"

extern u16 *table_field_moves;

typedef struct pokmenu_opt_state {
    void *callback;
    u16 field_4;
    u16 field_6;
    u16 field_8;
    u16 field_A;
    u8 box_id_question;
    u8 box_id_options;
    u8 box_id_description;
    u8 opts[4];
    u8 field_13;
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 opt_cnt;

} pokemenu_opt_state;

typedef struct s_pokemenu_state {
    pokemenu_opt_state *opt_state;
    void *callback;
} s_pokemenu_state;

typedef struct outdoor_move {
    bool (*init_func)();
    u32 not_usable_msg;
} outdoor_move;

extern outdoor_move table_outdoor_move_initializers[];

s_pokemenu_state *pokemenu_state = (s_pokemenu_state*) 0x0203B09C;
u8 *pokemenu_team_index = (u8*) 0x0203B0A9;

void pokemenu_opt_outdoor_move(u8 callback_self);
void pokemenu_build_opt_by_pokemon(pokemon *base, u8 index);

#endif	/* FIELDMOVES_H */

