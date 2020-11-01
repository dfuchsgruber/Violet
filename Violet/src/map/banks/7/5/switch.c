#include "types.h"
#include "overworld/npc.h"
#include "constants/movements.h"
#include "tile/block.h"
#include "save.h"
#include "superstate.h"

static u8 movements_normal[][2] = {
    [DIR_DOWN] = {STEP_DOWN, STOP},
    [DIR_UP] = {STEP_UP, STOP},
    [DIR_LEFT] = {STEP_LEFT, STOP},
    [DIR_RIGHT] = {STEP_RIGHT, STOP},
};

static u8 movements_fast[][2] = {
    [DIR_DOWN] = {STEP_DOWN_FAST, STOP},
    [DIR_UP] = {STEP_UP_FAST, STOP},
    [DIR_LEFT] = {STEP_LEFT_FAST, STOP},
    [DIR_RIGHT] = {STEP_RIGHT_FAST, STOP},
};

void silvania_gym_switch() {
    u8 direction = player_get_facing();
    if (super.keys.keys.B) {
        npc_apply_movement(0xFF, save1->map, save1->bank, movements_fast[direction]);
    } else {
        npc_apply_movement(0xFF, save1->map, save1->bank, movements_normal[direction]);
    }
}
