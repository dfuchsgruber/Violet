#include "tile/interaction/pc.h"
#include "debug.h"
#include "overworld/npc.h"
#include "save.h"
#include "tile/block.h"
#include "types.h"
#include "vars.h"
#include "constants/block_arguments.h"

static const struct {
    u16 on;
    u16 off;
} pc_blocks[NUM_PCS] = {
    [PC_GENERIC] = {.on = TILE_INTERACTION_PC_GENERIC_ON, .off = TILE_INTERACTION_PC_GENERIC_OFF},
    [PC_POKESTOP] = {.on = TILE_INTERACTION_PC_POKESTOP_ON, .off = TILE_INTERACTION_PC_POKESTOP_OFF},

};

static void tile_interaction_pc_get_dx_and_dy(s8 *dx, s8 *dy) {
    switch (player_get_facing()) {
    case DIR_UP:
        *dx = 0;
        *dy = -1;
        break;
    case DIR_LEFT:
        *dx = -1;
        *dy = -1;
        break;
    case DIR_RIGHT:
        *dx = 1;
        *dy = -1;
        break;
    default:
        *dx = 0;
        *dy = 0;
    }
}

void tile_interaction_pc_turn_on_set_block(u16 flicker_off) {
    s8 dx, dy;
    tile_interaction_pc_get_dx_and_dy(&dx, &dy);

    int pc_idx = *var_access(0x8004);
    if (pc_idx < 0 || pc_idx >= NUM_PCS) {
        ERROR("Invalid PC type: %d\n", pc_idx);
        return; // Invalid PC type
    }
    u16 block_idx = flicker_off ? pc_blocks[pc_idx].off : pc_blocks[pc_idx].on;
    block_set_by_pos((s16)(save1->x_camera + dx + 7), (s16)(save1->y_camera + dy + 7), block_idx  | BLOCK_SOLID);
}

void tile_interaction_pc_turn_off_set_block_and_redraw_map() {
    s8 dx, dy;
    tile_interaction_pc_get_dx_and_dy(&dx, &dy);
    int pc_idx = *var_access(0x8004);
    if (pc_idx < 0 || pc_idx >= NUM_PCS) {
        ERROR("Invalid PC type: %d\n", pc_idx);
        return; // Invalid PC type
    }
    u16 block_idx = pc_blocks[pc_idx].off;
    block_set_by_pos((s16)(save1->x_camera + dx + 7), (s16)(save1->y_camera + dy + 7), block_idx | BLOCK_SOLID);
    map_redraw_all_blocks();
}