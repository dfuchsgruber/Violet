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
#include "trainer/virtual.h"
#include "constants/movements.h"
#include "debug.h"

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

void overworld_person_get_position() {
    u8 person_idx = (u8) (*var_access(0x8004));
    u8 npc_id;
    if (npc_get_id_by_overworld_id(person_idx, save1->map, save1->bank, &npc_id))
        return;
    *var_access(0x8004) = (u16)(npcs[npc_id].dest_x - 7);
    *var_access(0x8005) = (u16)(npcs[npc_id].dest_y - 7);
    dprintf("Player @(%d, %d)\n", *var_access(0x8004), *var_access(0x8005));
}


void npc_move_to(u8 ow_id, s16 dest_x, s16 dest_y) {
    u8 npc_id;
    if (npc_get_id_by_overworld_id(ow_id, save1->map, save1->bank, &npc_id))
        return;
    trainer_npc_idx = npc_id;
    u8 *dyn_move = (u8*) malloc(256); // dynamic space for movement list
    a_star_compute_path(dyn_move, dest_x, dest_y, &npcs[npc_id]);
    npc_apply_movement(ow_id, save1->map, save1->bank, dyn_move);
    u8 cb = big_callback_new(npc_move_to_freeing_callback, 10);
    big_callback_set_int(cb, 0, (int) dyn_move);
    big_callbacks[cb].params[2] = ow_id;
    big_callbacks[cb].params[3] = (u16) dest_x;
    big_callbacks[cb].params[4] = (u16) dest_y;
    npc_movement_target_person_idx = ow_id;
}

void npc_move_to_freeing_callback(u8 self) {
    big_callbacks[self].params[5]++;
    u8 npc_id;
    if (npc_get_id_by_overworld_id((u8) big_callbacks[self].params[2], save1->map, save1->bank, &npc_id))
        return;
    if (npcs[npc_id].dest_x == (s16) (big_callbacks[self].params[3]) &&
            npcs[npc_id].dest_y == (s16) (big_callbacks[self].params[4])) {
        big_callback_delete(self);
    }
}

void npc_move_camera_to() {
    s16 x_destination = (s16) (*var_access(0x8004) + 7);
    s16 y_destination = (s16) (*var_access(0x8005) + 7); 
    u8 npc_idx = 0;
    if (npc_get_id_by_overworld_id(0x7F, save1->map, save1->bank, &npc_idx))
        return;
    trainer_npc_idx = npc_idx;
    s16 x = npcs[npc_idx].dest_x;
    s16 y = npcs[npc_idx].dest_y;
    int i = 0;
    u8 *moves = (u8*) malloc(256); 

    bool horizontal = ABS(x - x_destination) > ABS(y - y_destination);

    while (x != x_destination || y != y_destination) {
        if (horizontal) {
            if (x_destination > x) {
                moves[i++] = STEP_RIGHT;
                x++;
            } else {
                moves[i++] = STEP_LEFT;
                x--;
            }
            if (x == x_destination) horizontal = false;
        } else if (!horizontal) {
            if (y_destination > y) {
                moves[i++] = STEP_DOWN;
                y++;
            } else {
                moves[i++] = STEP_UP;
                y--;
            }
            if (y == y_destination) horizontal = true;
        }
    }
    moves[i++] = STOP;
    npc_apply_movement(0x7F, save1->map, save1->bank, moves);
    u8 cb = big_callback_new(npc_move_to_freeing_callback, 10);
    big_callback_set_int(cb, 0, (int)moves);
    big_callbacks[cb].params[2] = 0x7F;
    big_callbacks[cb].params[3] = (u16) x_destination;
    big_callbacks[cb].params[4] = (u16) y_destination;
    npc_movement_target_person_idx = 0x7F;
}

void overworld_target_npc_set_to_var() {
    u8 person_idx = (u8)(*var_access(0x8004));
    u8 npc_idx = 0;
    if (npc_get_id_by_overworld_id(person_idx, save1->map, save1->bank, &npc_idx)) {
        trainer_npc_idx = npc_idx;
    }
}