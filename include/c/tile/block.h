/*
 * block.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_BLOCK_H_
#define INCLUDE_C_TILE_BLOCK_H_

typedef struct bdata {
    u32 behavior : 9;
    u32 hm_usage : 5;
    u32 field_2 : 4;
    u32 field_3 : 6;
    u32 field_4 : 3; //if 0 no wildbattle triggered, 1 fetch data from wild grass table, 2
    u32 field_5 : 2;
    u32 field_6 : 2;
    u32 field_7 : 1;

} bdata;

typedef union union_block_data {
    bdata data;
    u32 value;
} block_data;


#define FIELD_BEHAVIOR 0
#define FIELD_HM_USAGE 1

// Coordinate displacements for walking directions

#define DIR_NONE 0
#define DIR_DOWN 1
#define DIR_UP 2
#define DIR_LEFT 3
#define DIR_RIGHT 4
#define DIR_DIANW 5
#define DIR_DIANE 6
#define DIR_DIASE 7
#define DIR_DIASW 8

coordinate *walking_directions = (coordinate*) 0x083A638C;


/**
 * Redraws a singular block in the map
 * @param x the AM x coordiante + 7 (camera origin relative)
 * @param y the AM y coordinate + 7 (camera origin relative)
 */
void map_draw_block(s16 x, s16 y);

#endif /* INCLUDE_C_TILE_BLOCK_H_ */
