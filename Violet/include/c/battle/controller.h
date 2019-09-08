#ifndef H_BATTLE_CONTROLLER
#define H_BATTLE_CONTROLLER

#include "types.h"

/**
 * Taken from pokeemerald.
 **/ 
void battle_controller_emit_get_pokemon_data(u8 buffer_idx, u8 request_idx, u8 battler_idx);

/**
 * Marks a battler such that is executed by the battle controller.
 * @param battler_idx the battler to mark.
 **/
void battler_mark_for_controller_execution(u8 battler_idx);


#endif