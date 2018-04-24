/*
 * fading.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_FADING_H_
#define INCLUDE_C_FADING_H_



typedef struct {
    u32 affects;
    u16 scale;
    u16 color : 15;
    u16 active : 1;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;

} stru_fading_cntrl;

stru_fading_cntrl *fading_cntrl = (stru_fading_cntrl*) 0x02037AB8;

bool is_fading();

#endif /* INCLUDE_C_FADING_H_ */
