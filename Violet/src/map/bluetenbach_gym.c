#include "map/bluetenbach_gym.h"
#include "bios.h"
#include "debug.h"
#include "flags.h"
#include "map/header.h"
#include "oam.h"
#include "overworld/map_control.h"
#include "save.h"
#include "types.h"
#include "vars.h"

extern map_footer_t map_footer_meriana_city_gym_rotating_door_0;
extern map_footer_t map_footer_meriana_city_gym_rotating_door_1;
extern map_footer_t map_footer_meriana_city_gym_rotating_wall_2;
extern map_footer_t map_footer_meriana_city_gym_rotating_wall_3;
extern map_footer_t map_footer_meriana_city_gym_rotating_wall_4;
extern map_footer_t map_footer_meriana_city_gym_rotating_wall_5;
extern map_footer_t map_footer_meriana_city_gym_rotating_wall_6;
extern map_footer_t map_footer_meriana_city_gym_rotating_wall_7;

static bluetenbach_gym_rotating_wall_t rotating_walls[] = {
    [0] = {.footer = &map_footer_meriana_city_gym_rotating_door_0, .x = 6 + 7, 8 + 7},
    [1] = {.footer = &map_footer_meriana_city_gym_rotating_door_1, .x = 0 + 7, 6 + 7},
    [2] = {.footer = &map_footer_meriana_city_gym_rotating_wall_2, .x = 0xb + 7, 0x5 + 7},
    [3] = {.footer = &map_footer_meriana_city_gym_rotating_wall_3, .x = 0x19 + 7, 0x8 + 7},
    [4] = {.footer = &map_footer_meriana_city_gym_rotating_wall_4, .x = 0x24 + 7, 0x5 + 7},
    [5] = {.footer = &map_footer_meriana_city_gym_rotating_wall_5, .x = 0x0 + 7, 0x20 + 7},
    [6] = {.footer = &map_footer_meriana_city_gym_rotating_wall_6, .x = 0x7 + 7, 0x22 + 7},
    [7] = {.footer = &map_footer_meriana_city_gym_rotating_wall_7, .x = 0x19 + 7, 0x24 + 7},
};

static void rotating_doors_set_blocks() {
    u16 rotation = *var_access(VAR_BLUETENBACH_GYM_ROTATION);
    for (u8 idx = 0; idx < ARRAY_COUNT(rotating_walls); idx++) {
        u32 height = rotating_walls[idx].footer->height / 4; // Each footer has all 4 "frames" already
        // dprintf("Drawing wall %d, rotation %d at height %d\n", idx, rotation, height);
        for (u16 i = 0; i < rotating_walls[idx].footer->width; i++) {
            for (u16 j = 0; j < height; j++) {
                u32 block_idx = (rotation * height + j) * rotating_walls[idx].footer->width + i;
                // dprintf("At (%d, %d) get block idx %d\n", i, j, block_idx);
                u16 block = rotating_walls[idx].footer->map[block_idx].block_id;
                block = (u16)(block | (rotating_walls[idx].footer->map[block_idx].level << 10));
                block_set_by_pos((s16)(rotating_walls[idx].x + i), (s16)(rotating_walls[idx].y + j), block);
            }
        }
    }
}

void bluetenbach_gym_set_rotating_doors_blocks() {
    rotating_doors_set_blocks();
}

void bluetenbach_gym_rotate_walls() {
    *var_access(VAR_BLUETENBACH_GYM_ROTATION) = (u16)((*var_access(VAR_BLUETENBACH_GYM_ROTATION) + 1) % 4);
    rotating_doors_set_blocks();
}
