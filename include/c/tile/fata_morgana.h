/*
 * morgana.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_FATA_MORGANA_H_
#define INCLUDE_C_TILE_FATA_MORGANA_H_


#define DESERT_MAP 21
#define DESERT_BANK 3

void do_fata_morgana();

typedef struct morgana_anim {
    u16 blocks[4];
    u16 walkfield;
} morgana_anim;


#endif /* INCLUDE_C_TILE_FATA_MORGANA_H_ */
