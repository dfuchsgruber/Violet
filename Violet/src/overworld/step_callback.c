#include "overworld/step_callback.h"
#include "constants/block_behaviour.h"
#include "debug.h"
#include "music.h"
#include "tile/block.h"
#include "tile/coordinate.h"
#include "types.h"
#include "vars.h"

static void overworld_step_callback_none(u8 self) {
    (void)self;
}

static void overworld_step_callback_route_5_cave(u8 self) {
    position_t pos;
    player_get_position(&pos);
    u16 *params = big_callbacks[self].params;
    switch (params[OVERWORLD_STEP_CALLBACK_STATE]) {
        case 0: { // Initialize with the current position
            params[2] = (u16)pos.coordinates.x;
            params[3] = (u16)pos.coordinates.y;
            params[OVERWORLD_STEP_CALLBACK_STATE] = 1;
            break;
        }
        case 1: { // Check if the player stepped, i.e. position changed
            if (pos.coordinates.x != params[2] || pos.coordinates.y != params[3]) {
                params[2] = (u16)pos.coordinates.x;
                params[3] = (u16)pos.coordinates.y;
                u16 behaviour = block_get_behaviour_by_pos(pos.coordinates.x, pos.coordinates.y);
                if (behaviour == MB_CRACKED_ICE) {
                    params[4] = 4; // Delay for 4 frames
                    params[OVERWORLD_STEP_CALLBACK_STATE] = 2;
                }
            }
            break;
        }
        case 2: { // Player falls, the script is triggered via levelscripts
            if (params[4]) {
                --params[4];
            } else {
                s16 x = (s16)params[2];
                s16 y = (s16)params[3];
                block_set_by_pos(x, y, (u16)(block_get_by_pos(x, y) + 1));
                map_redraw_block_at_position(x, y);
                *var_access(0x4001) = 1;
                params[OVERWORLD_STEP_CALLBACK_STATE] = 1;
                play_sound(35);
            }
            break;
        }
    }
}

void (*overworld_step_callbacks[])(u8) = {
    [OVERWORLD_STEP_CALLBACK_NONE] = overworld_step_callback_none,
    [OVERWORLD_STEP_CALLBACK_ROUTE_5_CAVE] = overworld_step_callback_route_5_cave,
};

void overworld_step_callback_proceed(u8 self) {
    int idx = big_callbacks[self].params[OVERWORLD_STEP_CALLBACK_IDX];
    overworld_step_callbacks[idx](self);
}

void overworld_step_callback_set(u8 idx) {
    u8 cb_idx = big_callback_get_id(overworld_step_callback_proceed);
    if (cb_idx != 0xFF) {
        for (size_t i = 0; i < 16; i++) {
            big_callbacks[cb_idx].params[i] = 0;
        }
        if (idx > ARRAY_COUNT(overworld_step_callbacks) || overworld_step_callbacks[idx] == NULL) {
            big_callbacks[cb_idx].params[OVERWORLD_STEP_CALLBACK_IDX] = OVERWORLD_STEP_CALLBACK_NONE;
        } else {
            big_callbacks[cb_idx].params[OVERWORLD_STEP_CALLBACK_IDX] = idx;
        }
    }
}
