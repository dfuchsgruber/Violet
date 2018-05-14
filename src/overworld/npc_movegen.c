/* 
 * File:   npc_movegen.c
 * Author: Domi
 *
 * Created on 6. Juli 2016, 22:46
 */
#include "types.h"
#include "stdbool.h"
#include "math.h"
#include "overworld/npc.h"
#include "save.h"
#include "callbacks.h"
#include "data_structures.h"
#include "vars.h"
#include "agbmemory.h"

void special_move_npc_to_player() {
    s16 pos[2];
    player_get_facing_position(&pos[0], &pos[1]);
    u8 target = (u8) * var_access(0x8004);
    npc_move_to(target, pos[0], pos[1]);
}

void special_move_npc_to() {
    s16 x = (s16) (*var_access(0x8005) + 7);
    s16 y = (s16) (*var_access(0x8006) + 7);
    u8 target = (u8) * var_access(0x8004);
    npc_move_to(target, x, y);
}

//static u8 facings[] = {0xFF, 0x1, 0x0, 0x3, 0x2};

void npc_move_to(u8 ow_id, s16 dest_x, s16 dest_y) {

    u8 npc_id;
    if (npc_get_id_by_overworld_id(ow_id, (*save1)->map, (*save1)->bank, &npc_id))
        return;
    *((u8*) 0x03004FC4) = npc_id;
    /**
    s16 x_from = npcs[npc_id].dest_x;
    s16 y_from = npcs[npc_id].dest_y;
     **/
    u8 *dyn_move = (u8*) malloc(256); //dynamic space for movement list

    a_star_compute_path(dyn_move, dest_x, dest_y, &npcs[npc_id]);
    //dprintf("path is %x\n", dyn_move);
    /**Now we generate a move list
    int processed = 0;
    processed += move_npc_to_player_movegen(horizontal_first ? x_from : y_from, horizontal_first ? dest_x : dest_y, dyn_move, horizontal_first, processed);
    processed += move_npc_to_player_movegen(horizontal_first ? y_from : x_from, horizontal_first ? dest_y : dest_x, dyn_move, !horizontal_first, processed);
     **/

    npc_apply_movement(ow_id, (*save1)->map, (*save1)->bank, dyn_move);

    u8 cb = big_callback_new(npc_move_to_freeing_callback, 10);
    big_callback_set_int(cb, 0, (int) dyn_move);
    big_callbacks[cb].params[2] = ow_id;
    big_callbacks[cb].params[3] = (u16) dest_x;
    big_callbacks[cb].params[4] = (u16) dest_y;


    *((u16*) 0x20370B0) = ow_id;
}

void npc_move_to_freeing_callback(u8 self) {
    big_callbacks[self].params[5]++;
    u8 npc_id;
    if (npc_get_id_by_overworld_id((u8) big_callbacks[self].params[2], (*save1)->map, (*save1)->bank, &npc_id))
        return;

    if (npcs[npc_id].dest_x == (s16) (big_callbacks[self].params[3]) &&
            npcs[npc_id].dest_y == (s16) (big_callbacks[self].params[4])) {
        //free((void*)big_callback_get_int(self, 0));
        big_callback_delete(self);
    }
}

