/*
 * map_control.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_MAP_CONTROL_H_
#define INCLUDE_C_OVERWORLD_MAP_CONTROL_H_

typedef struct{
    u8 _unkown;
    u8 _unkown_2;
    u8 x_start;
    u8 y_start;
} stru_map_displ_cntrl;

stru_map_displ_cntrl *map_displ_cntrl = (stru_map_displ_cntrl*)0x03000E90;

#endif /* INCLUDE_C_OVERWORLD_MAP_CONTROL_H_ */
