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
#include "pokemon/virtual.h"

extern u16 field_moves[];

typedef struct {
    bool (*init_func)();
    u32 not_usable_msg;
} field_move_t;

extern field_move_t field_move_initalizers[];

/**
 * Initializes the field move softboiled from the pokemon party menu
 * @param self the own callback id
 */
void field_move_softboiled_init(u8 self);

/**
 * Initializes the field move fly from the pokemon party menu
 */
void field_move_fly_init();

/**
 * Initializes the error message for the fieldmove surfer
 */
void field_move_surfer_print_error();

/**
 * Checks if outdoor moves are usable
 * @return if outdoor moves are usable
 */
bool field_moves_usable();

/**
 * Loads the buffers for executing a field move
 * @param the pokemon executing the field move
 * @param index the field move index
 */
void field_move_load_buffers(pokemon *pokemon, u8 index);

#endif	/* FIELDMOVES_H */

