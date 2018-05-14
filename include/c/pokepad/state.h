/*
 * state.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_STATE_H_
#define INCLUDE_C_POKEPAD_STATE_H_

#include "types.h"
#include "stdbool.h"

typedef struct pokepad_item {
        u16 flag;
        u8 *string;
        void (*func)(bool from_outdoor);
        u8 *description;
    } pokepad_item;

    typedef struct pokepad_memory {
        u8 items [8];
        u8 current_item;
        u8 item_cnt;
        u8 color_cb;
        u8 arrow_oam;
        u8 l_oam;
        u8 r_oam;
        u8 lr_countdown;
    } pokepad_memory;

#endif /* INCLUDE_C_POKEPAD_STATE_H_ */
