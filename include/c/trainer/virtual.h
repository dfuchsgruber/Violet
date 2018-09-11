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


extern trainer_variables trainer_vars;

/**
 * Loads the items of a trainer into the virutal trainer state
 * @param t_items the items a trainer possesses
 */
void load_trainer_items(trainer_items *t_items);

/**
 * Reads an unaligned hword form the trainer build mini script
 * @param src the source to read from
 * @return the hword that was read
 */
u16 trainer_get_unaligned_hword(void *src);

/**
 * Returns the flag associated with the current trainer
 * @return the flag
 */
u16 trainer_get_flag();

/**
 * Continuation that is called after a trainerbattle ends
 */
void trainerbattle_continuation();

#endif /* INCLUDE_C_TRAINER_VIRTUAL_H_ */
