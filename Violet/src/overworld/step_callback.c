#include "types.h"
#include "overworld/step_callback.h"
#include "debug.h"
#include "tile/coordinate.h"
#include "tile/block.h"
#include "constants/block_behaviour.h"
#include "vars.h"
#include "music.h"
#include "overworld/npc.h"

static void overworld_step_callback_none(u8 self){
    (void)self;
}

static void overworld_step_callback_generic_cracked_floor(u8 self, u16 (*get_cracked_block_idx)(s16, s16), 
        u16 crack_sound_idx, bool bike_fast_speed_bypass) {
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
            // There is two 4-frame clocks for the countdown since player speed 4 is too fast
            if (params[4] != 0 && --params[4] == 0) {
                s16 x = (s16)params[5]; s16 y = (s16)params[6];
                block_set_by_pos(x, y, get_cracked_block_idx(x, y));
                map_redraw_block_at_position(x, y);
                // DEBUG("Clk 0 draws at %d, %d\n", x, y);
                if (crack_sound_idx)
                    play_sound(crack_sound_idx);
            }
            if (params[8] != 0 && --params[8] == 0) {
                s16 x = (s16)params[9]; s16 y = (s16)params[10];
                block_set_by_pos(x, y, get_cracked_block_idx(x, y));
                map_redraw_block_at_position(x, y);
                // DEBUG("Clk 1 draws at %d, %d\n", x, y);
                if (crack_sound_idx)
                    play_sound(crack_sound_idx);
            }
            u16 behaviour = block_get_behaviour_by_pos(pos.coordinates.x, pos.coordinates.y);
            if (behaviour == MB_CRACKED_ICE_HOLE) {
                *var_access(0x4001) = 1;
            }
            if (pos.coordinates.x != params[2] || pos.coordinates.y != params[3]) {
                // Player position has changed
                params[2] = (u16)pos.coordinates.x;
                params[3] = (u16)pos.coordinates.y;
                if (behaviour == MB_CRACKED_ICE) {
                    if (player_state.bike_speed != 4 || !bike_fast_speed_bypass) {
                        // Player only falls down when he is not on highest speed
                        *var_access(0x4001) = 1;
                    }
                    // Get one of the two clocks for the 4 frame countdown
                    if (params[4] == 0) {
                        params[4] = 3;
                        params[5] = (u16)pos.coordinates.x;
                        params[6] = (u16)pos.coordinates.y;
                    } else if (params[8] == 0) {
                        params[8] = 3;
                        params[9] = (u16)pos.coordinates.x;
                        params[10] = (u16)pos.coordinates.y;
                    } else {
                        ERROR("On step callback fall through cracked floor: Player is too fast, no free clock to store tiles!");
                    }
                }
            }
        }
    }
}

static u16 overworld_step_callback_route_5_get_cracked_floor_block_idx(s16 x, s16 y) {
    u16 block_idx = block_get_by_pos(x, y);
    if (block_idx == 0x2a0)
        return 0x2a1;
    else if (block_idx == 0x2aa)
        return 0x2ab;
    return 0;
}

static void overworld_step_callback_route_5_cave(u8 self) {
    overworld_step_callback_generic_cracked_floor(self, overworld_step_callback_route_5_get_cracked_floor_block_idx, 35, true);
}

void (*const overworld_step_callbacks[])(u8) = {
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