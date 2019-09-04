/*
 * custom.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_ITEM_CUSTOM_H_
#define INCLUDE_C_ITEM_CUSTOM_H_

// Custom items
void item_field_nature_stone(u8 self);
void item_ashbag_field(u8 self);
void item_nature_stone(u8 self, void (*failure_func)(u8));

#define GOLDEN_CANDY_LEVEL_INCREASE 3

#define CHOICE_ITEM_BAND 0
#define CHOICE_ITEM_SPECS 2
#define CHOICE_ITEM_SCARF 1

#endif /* INCLUDE_C_ITEM_CUSTOM_H_ */
