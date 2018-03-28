/*
 * mart.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_ITEM_MART_H_
#define INCLUDE_C_ITEM_MART_H_

typedef struct{
    u16 flag;
    u16 item;
}mart_item;

typedef struct{
    void (*end_callback)();
    u16 *item_list;
}mart_state_t;


mart_state_t *mart_state = (mart_state_t*)0x02039934;

#endif /* INCLUDE_C_ITEM_MART_H_ */
