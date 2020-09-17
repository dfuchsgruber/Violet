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
#include "overworld/script.h"
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
    u8 speed = (u8)*var_access(0x8005);
    npc_move_to(target, pos[0], pos[1], speed);
}

void special_move_npc_to() {
    s16 x = (s16) (*var_access(0x8005) + 7);
    s16 y = (s16) (*var_access(0x8006) + 7);
    u8 speed = (u8) *var_access(0x8007);
    u8 target = (u8) * var_access(0x8004);
    npc_move_to(target, x, y, speed);
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

void npc_move_to_block_movements() {
    fmem.pathfinding_npc_movements_waiting = true;
}

void npc_move_to_unblock_movements() {
    fmem.pathfinding_npc_movements_waiting = false;
}

void npc_move_to_freeing_callback(u8 self) {
    u8 person_idx = (u8) big_callbacks[self].params[2];
    if (npc_movement_callback_is_finished(person_idx, save1->map, save1->bank)) {
        big_callback_delete(self);
    }
}

static void npc_move_to_do_moves(u8 self) {
    if (!fmem.pathfinding_npc_movements_waiting) {
        u8 *moves = (u8*)big_callback_get_int(self, 0);
        u8 person_idx = (u8)big_callbacks[self].params[2];
        npc_apply_movement(person_idx, save1->map, save1->bank, moves);
        npc_movement_target_person_idx = person_idx;
        big_callbacks[self].function = npc_move_to_freeing_callback;
    }
}

static void npc_move_to_wait_for_a_star(u8 self) {
    u8 a_star = (u8)big_callbacks[self].params[6];
    bool a_star_finished = big_callbacks[a_star].params[0];
    if (a_star_finished) {
        overworld_script_resume(); // Calculation of current path finished
        big_callback_delete(a_star);
        big_callbacks[self].function = npc_move_to_do_moves;
        big_callbacks[self].function(self);
    }
}

void npc_move_to(u8 ow_id, s16 dest_x, s16 dest_y, u8 speed) {
    u8 npc_id;
    if (npc_get_id_by_overworld_id(ow_id, save1->map, save1->bank, &npc_id))
        return;
    trainer_npc_idx = npc_id;
    u8 *dyn_move = (u8*) malloc(256); // dynamic space for movement list
    u8 a_star = a_star_compute_path(dyn_move, dest_x, dest_y, &npcs[npc_id], speed, A_STAR_STEPS_PER_FRAME);
    u8 cb = big_callback_new(npc_move_to_wait_for_a_star, 10);
    big_callback_set_int(cb, 0, (int) dyn_move);
    big_callbacks[cb].params[2] = ow_id;
    big_callbacks[cb].params[3] = (u16) dest_x;
    big_callbacks[cb].params[4] = (u16) dest_y;
    big_callbacks[cb].params[5] = 0;
    big_callbacks[cb].params[6] = a_star;
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
    if (!npc_get_id_by_overworld_id(person_idx, save1->map, save1->bank, &npc_idx)) {
        trainer_npc_idx = npc_idx;
    }
}

static void overworld_person_face_to_person(u8 person_idx_facing, u8 person_idx_target) {
    u8 npc_idx_facing;
    if (npc_get_id_by_overworld_id(person_idx_facing, save1->map, save1->bank, &npc_idx_facing))
        return; // No match found, person can't face
    // Get the target position
    s16 target_x = 0;
    s16 target_y = 0;
    u8 npc_target;
    u8 target_direction = DIR_NONE;
    if (!npc_get_id_by_overworld_id(person_idx_target, save1->map, save1->bank, &npc_target)) {
        target_x = npcs[npc_target].dest_x;
        target_y = npcs[npc_target].dest_y;
        target_direction = npcs[npc_target].facing.lower;
    } else { // Get the position from map event
        map_event_person *person_target = map_get_person(person_idx_target, save1->map, save1->bank);
        target_x = (s16)(person_target->x + 7);
        target_y = (s16)(person_target->y + 7);
    }
    int dx = npcs[npc_idx_facing].dest_x - target_x;
    int dy = npcs[npc_idx_facing].dest_y - target_y;
    dprintf("Distance from %d to %d is dx %d dy %d\n", person_idx_facing, person_idx_target, dx, dy);
    bool horizontal = true;
    if (ABS(dy) > ABS(dx)) {
        horizontal = false;
    } else if (ABS(dy) == ABS(dx)) {
        // Prefer the direction the target is facing in
        if (target_direction == DIR_UP || target_direction == DIR_DOWN)
            horizontal = false;
    }
    if (horizontal) {
            if (dx >= 0)
                fmem.npc_facing_movements[0] = LOOK_LEFT;
            else
                fmem.npc_facing_movements[0] = LOOK_RIGHT;
        } else {
            if (dy >= 0)
                fmem.npc_facing_movements[0] = LOOK_UP;
            else
                fmem.npc_facing_movements[0] = LOOK_DOWN;
        }
        fmem.npc_facing_movements[1] = STOP;
        npc_apply_movement(person_idx_facing, save1->map, save1->bank, fmem.npc_facing_movements);
        npc_movement_target_person_idx = person_idx_facing;
}

void special_overworld_person_face_to_person() {
    overworld_person_face_to_person((u8)(*var_access(0x8004)), (u8)(*var_access(0x8005)));
}
