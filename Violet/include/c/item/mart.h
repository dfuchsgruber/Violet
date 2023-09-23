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
} mart_item;

typedef struct{
    void (*end_callback)();
    u16 *item_list;
} mart_state_t;


extern EWRAM u16 dynamic_mart[32];
extern mart_state_t mart_state;

/**
 * Opens a pokemart
 * @param list the item list to sell (terminated by 0)
 */
void pokemart(u16 *list);

/**
 * Sets the continuation callback for the current pokemart
 */
void mart_set_continuation_callback(void (*func)());

#endif /* INCLUDE_C_ITEM_MART_H_ */
