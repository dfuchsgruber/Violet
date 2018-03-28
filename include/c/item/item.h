/*
 * item.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_ITEM_ITEM_H_
#define INCLUDE_C_ITEM_ITEM_H_

#include "item/count.h"


typedef struct {
    u8 name[14];
    u16 index;
    u16 price;
    u8 holding_effect_id;
    u8 holding_effect_param;
    u8 *description_ptr;
    u16 field_18;
    u8 pocket;
    u8 type;
    void (*field_usage)(u8);
    void (*battle_usage_1)(u8);
    void (*battle_usage_2)(u8);
    void (*field_28)(u8);
} item;


item items[ITEM_CNT];

#endif /* INCLUDE_C_ITEM_ITEM_H_ */
