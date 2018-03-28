/*
 * virtual.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TRAINER_VIRTUAL_H_
#define INCLUDE_C_TRAINER_VIRTUAL_H_

typedef struct trainer_items {
    u16 items[4];
    u8 cnt;

} trainer_items;

typedef struct trainer_variables {
    u16 kind_of_battle;
    u16 trainer_id;
    u16 overworld_target;
    u16 padding;
    u8 *challange_text;
    u8 *defeat_text;
    u16 trainer_var_0;
    u16 trainer_var_1;
    u8 *script_later;
    u8 *script_continue;
    u16 reserved_word_xse;

} trainer_variables;


trainer_variables *trainer_vars = (trainer_variables*) 0x020386AC;
void load_trainer_items(trainer_items *t_items);

#endif /* INCLUDE_C_TRAINER_VIRTUAL_H_ */
