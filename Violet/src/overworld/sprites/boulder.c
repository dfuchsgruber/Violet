#include "types.h"
#include "overworld/sprite.h"
#include "overworld/script.h"
#include "color.h"
#include "constants/items.h"
#include "save.h"
#include "debug.h"
#include "flags.h"
#include "vars.h"
#include "agbmemory.h"
#include "prng.h"
#include "overworld/misc.h"
#include "math.h"
#include "music.h"
#include "constants/person_script_stds.h"
#include "overworld/npc.h"
#include "constants/block_behaviour.h"
#include "constants/overworld/overworld_collisions.h"
#include "constants/movements.h"
#include "flags.h"
#include "callbacks.h"
#include "music.h"
#include "map/event.h"
#include "constants/person_behaviours.h"

static const graphic overworld_gfx_boulder_gym_puzzle_unidirectional[] = {
    [0] = {gfx_ow_boulder_gym_puzzleTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [1] = {gfx_ow_boulder_gym_puzzleTiles + 1 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [2] = {gfx_ow_boulder_gym_puzzleTiles + 2 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [3] = {gfx_ow_boulder_gym_puzzleTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [4] = {gfx_ow_boulder_gym_puzzleTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [5] = {gfx_ow_boulder_gym_puzzleTiles + 1 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [6] = {gfx_ow_boulder_gym_puzzleTiles + 1 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [7] = {gfx_ow_boulder_gym_puzzleTiles + 2 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [8] = {gfx_ow_boulder_gym_puzzleTiles + 2 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
};

static const graphic overworld_gfx_boulder_gym_puzzle_bidirectional[] = {
    [0] = {gfx_ow_boulder_gym_puzzleTiles + 3 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [1] = {gfx_ow_boulder_gym_puzzleTiles + 3 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [2] = {gfx_ow_boulder_gym_puzzleTiles + 4 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [3] = {gfx_ow_boulder_gym_puzzleTiles + 3 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [4] = {gfx_ow_boulder_gym_puzzleTiles + 3 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [5] = {gfx_ow_boulder_gym_puzzleTiles + 3 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [6] = {gfx_ow_boulder_gym_puzzleTiles + 3 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [7] = {gfx_ow_boulder_gym_puzzleTiles + 4 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
    [8] = {gfx_ow_boulder_gym_puzzleTiles + 4 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0,},
};

const overworld_sprite overworld_boulder_gym_puzzle_unidirectional = {
    .tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BOULDER_GYM_PUZZLE,
    .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 16), .width = 16, .height = 16,
    .final_oam = &ow_final_oam_16_16, .subsprite_table = &ow_formation_16_16, .gfx_animation = ow_anim_standard_npc,
    .graphics = overworld_gfx_boulder_gym_puzzle_unidirectional, .rotscale_animation = oam_rotscale_anim_table_null, .inanimate = false,
};

const overworld_sprite overworld_boulder_gym_puzzle_bidirectional = {
    .tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BOULDER_GYM_PUZZLE,
    .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 16), .width = 16, .height = 16,
    .final_oam = &ow_final_oam_16_16, .subsprite_table = &ow_formation_16_16, .gfx_animation = ow_anim_standard_npc,
    .graphics = overworld_gfx_boulder_gym_puzzle_bidirectional, .rotscale_animation = oam_rotscale_anim_table_null, .inanimate = false,
};

const palette overworld_boulder_gym_puzzle_palette = {
    .pal = gfx_ow_boulder_gym_puzzlePal, .tag = OW_PAL_TAG_BOULDER_GYM_PUZZLE,
};

static const graphic overworld_gfx_boulder_hay_bale[] = {
    [0] = {gfx_ow_boulder_hayTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0,},
    [1] = {gfx_ow_boulder_hayTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0,},
    [2] = {gfx_ow_boulder_hayTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0,},
    [3] = {gfx_ow_boulder_hayTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0,},
    [4] = {gfx_ow_boulder_hayTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0,},
    [5] = {gfx_ow_boulder_hayTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0,},
    [6] = {gfx_ow_boulder_hayTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0,},
    [7] = {gfx_ow_boulder_hayTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0,},
    [8] = {gfx_ow_boulder_hayTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0,},
};

const overworld_sprite overworld_boulder_hay_bale = {
    .tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BOULDER_HAY_BALE,
    .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
    .final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = ow_anim_standard_npc,
    .graphics = overworld_gfx_boulder_hay_bale, .rotscale_animation = oam_rotscale_anim_table_null, .inanimate = true,
};

const palette overworld_boulder_hay_bale_palette = {
    .pal = gfx_ow_boulder_hayPal, .tag = OW_PAL_TAG_BOULDER_HAY_BALE,
};

const overworld_sprite *overworld_sprite_get_by_boulder_person_script_std(u8 person_script_std, u16 value) {
    switch (person_script_std) {
        case PERSON_PUZZLE_BOULDER:
            if (value)
                return &overworld_boulder_gym_puzzle_bidirectional;
            else
                return &overworld_boulder_gym_puzzle_unidirectional;
        case PERSON_HAY_BALE:
            return &overworld_boulder_hay_bale;
        default:
            return &overworld_sprite_strength_boulder;
    }
}

const palette *overworld_palette_get_gym_puzzle_boulder() {
    return &overworld_boulder_gym_puzzle_palette;
}

const palette *overworld_palette_get_hay_bale_boulder() {
    return &overworld_boulder_hay_bale_palette;
}

static u32 gym_puzzle_boulder_get_pushable_directions(u8 npc_idx) {
    npc *n = npcs + npc_idx;
    const map_event_person *person = map_get_person(n->overworld_id, n->map, n->bank);
    u32 pushable_directions = int_bitmasks[n->direction.facing];
    bool bidirectional = person->value != 0;
    if (bidirectional) {
        pushable_directions |= int_bitmasks[direction_get_opposite(n->direction.facing)];
    }
    return pushable_directions;
}

static bool gym_puzzle_behaviour_is_pushable_lane(u16 behaviour) {
    return behaviour == MB_BOULDER_LANE || behaviour == MB_STRENGTH_BUTTON;
}

/**
static void bruchfels_gym_facing_movement_free_callback(u8 self) {
    u8 npc_idx = (u8) big_callbacks[self].params[0];
    npc *n = npcs + npc_idx;
    if (!npc_movement_callback_is_active(n->overworld_id, n->map, n->bank)) {
        u8 *sequence = (u8*) big_callback_get_int(self, 2);
        DEBUG("Boulder rotation / mirroring finished.\n");
        free(sequence);
        big_callback_delete(self);
    }
}

static void bruchfels_gym_execute_facing_movement(u8 npc_idx, u8 movement) {
    npc *n = npcs + npc_idx;
    u8 *sequence = malloc_and_clear(4 * sizeof(u8));
    sequence[0] = movement;
    sequence[1] = STOP;
    npc_apply_movement(n->overworld_id, n->map, n->bank, sequence);
    u8 cb_idx = big_callback_new(bruchfels_gym_facing_movement_free_callback, 5);
    big_callbacks[cb_idx].params[0] = npc_idx;
    big_callback_set_int(cb_idx, 2, (int)sequence);
}

void bruchfels_gym_puzzle_rotate_boulders() {
    for (u8 idx = 0; idx < NUM_NPCS; idx++) {
        if (npcs[idx].flags.active && npcs[idx].sprite == OVERWORLD_SPRITE_STRENGTH_BOULDER) {
            npc *n = npcs + idx;
            u8 script_std =  map_get_person(n->overworld_id, n->map, n->bank)->script_std;
            if (script_std == PERSON_PUZZLE_BOULDER) {
                u8 facing = n->direction.facing;
                switch (facing) {
                    case DIR_DOWN:
                        bruchfels_gym_execute_facing_movement(idx, LOOK_LEFT); break;
                    case DIR_LEFT:
                        bruchfels_gym_execute_facing_movement(idx, LOOK_UP); break;
                    case DIR_UP:
                        bruchfels_gym_execute_facing_movement(idx, LOOK_RIGHT); break;
                    case DIR_RIGHT:
                        bruchfels_gym_execute_facing_movement(idx, LOOK_DOWN); break;
                }
            }
        }
    }
}


static void bruchfels_gym_puzzle_flip_boulders(bool horizontal, bool vertical) {
    for (u8 idx = 0; idx < NUM_NPCS; idx++) {
        if (npcs[idx].flags.active && npcs[idx].sprite == OVERWORLD_SPRITE_STRENGTH_BOULDER) {
            npc *n = npcs + idx;
            u8 script_std =  map_get_person(n->overworld_id, n->map, n->bank)->script_std;
            if (script_std == PERSON_PUZZLE_BOULDER) {
                u8 facing = n->direction.facing;
                switch (facing) {
                    case DIR_DOWN:
                        if (vertical) {
                            bruchfels_gym_execute_facing_movement(idx, LOOK_UP); 
                            break;
                        }
                    case DIR_LEFT:
                        if (horizontal) {
                            bruchfels_gym_execute_facing_movement(idx, LOOK_RIGHT); 
                            break;
                        }
                    case DIR_UP:
                        if (vertical) {
                            bruchfels_gym_execute_facing_movement(idx, LOOK_DOWN); 
                            break;
                        }
                    case DIR_RIGHT:
                        if (horizontal) {
                            bruchfels_gym_execute_facing_movement(idx, LOOK_LEFT); 
                            break;
                        }
                }
            }
        }
    }
}
**/

static u8 direction_flip_and_rotate(u8 direction, bool horizontal, bool vertical, bool rotate) {
    // First rotate
    if (rotate) {
        switch (direction) {
            case DIR_UP:
                direction = DIR_RIGHT;
                break;
            case DIR_RIGHT:
                direction = DIR_DOWN;
                break;
            case DIR_DOWN:
                direction = DIR_LEFT;
                break;
            case DIR_LEFT:
                direction = DIR_UP;
                break;
        }
    }
    switch (direction) {
        case DIR_UP:
            if (vertical)
                direction = DIR_DOWN;
            break;
        case DIR_DOWN:
            if (vertical)
                direction = DIR_UP;
            break;
        case DIR_LEFT:
            if (horizontal)
                direction = DIR_RIGHT;
            break;
        case DIR_RIGHT:
            if (horizontal)
                direction = DIR_LEFT;
            break;
    }
    return direction;
}

bool boulder_push_attempt(s16 x, s16 y, u8 direction) {
    u8 npc_idx = npc_get_by_position(x, y);
    DEBUG("Boulder push for npc %d @0x%x, 0x%x\n", npc_idx, x, y);
    if (npc_idx == NUM_NPCS || npcs[npc_idx].sprite != OVERWORLD_SPRITE_STRENGTH_BOULDER) 
        return false;
    npc *n = npcs + npc_idx;
    u8 script_std =  map_get_person(n->overworld_id, n->map, n->bank)->script_std;
    s16 dest_x = n->dest_x;
    s16 dest_y = n->dest_y;
    coordinates_apply_direction(direction, &dest_x, &dest_y);
    u16 behaviour = block_get_behaviour_by_pos(dest_x, dest_y);
    switch (script_std) {
        default: {
            if (behaviour == MB_FALL_WARP || (npc_get_collision(n, dest_x, dest_y, direction) == COLLISION_NONE && checkflag(STRENGTH_USED) && !behaviour_is_non_animated_warp((u8)behaviour))) {
                    boulder_animation_start(npc_idx, direction);
                    return true;
            }
            break;
        }
        case PERSON_PUZZLE_BOULDER: {
            u32 pushable_directions = gym_puzzle_boulder_get_pushable_directions(npc_idx);
            DEBUG("Try to push boulder in direction %d with flags 0x%x\n", direction, pushable_directions);
            if ((pushable_directions & int_bitmasks[direction]) && npc_get_collision(n, dest_x, dest_y, direction) == COLLISION_NONE && 
                !behaviour_is_non_animated_warp((u8)behaviour) && gym_puzzle_behaviour_is_pushable_lane(behaviour)) {
                    DEBUG("Boulder pushed\n");
                    boulder_animation_start(npc_idx, direction);
                    return true;
            }
            break;
        }
    }
    return false;
}

static void npc_save_position_and_facing_to_person(npc *n) {
    DEBUG("Update boulder position for person %d to 0x%x, 0x%x\n", n->overworld_id, (u16)(n->dest_x - 7), (u16)(n->dest_y - 7));
    person_set_position(n->overworld_id, (s16)(n->dest_x - 7), (s16)(n->dest_y - 7));
    DEBUG("update facing to %d\n", n->direction.facing);
    switch (n->direction.facing) {
        case DIR_DOWN:
            person_set_behaviour(n->overworld_id, BEHAVIOUR_FACE_DOWN); break;
        case DIR_UP:
            person_set_behaviour(n->overworld_id, BEHAVIOUR_FACE_UP); break;
        case DIR_LEFT:
            person_set_behaviour(n->overworld_id, BEHAVIOUR_FACE_LEFT); break;
        case DIR_RIGHT:
            person_set_behaviour(n->overworld_id, BEHAVIOUR_FACE_RIGHT); break;
    }
}

void npc_boulder_fall_trough_hole_and_update_person_coordinates(npc *n) {
    u16 behaviour = block_get_behaviour_by_pos(n->dest_x, n->dest_y);
    if (behaviour == MB_FALL_WARP) {
        play_sound(37);
        person_delete_npc_if_present(n->overworld_id, n->map, n->bank);
        clearflag(npc_get_strength_flag(n->overworld_id, n->map, n->bank));
    } else if (behaviour == MB_BOULDER_LANE) {
        npc_save_position_and_facing_to_person(n);
    }
}


static void bruchfels_gym_puzzle_flip_and_rotate_boulders(bool horizontal, bool vertical, bool rotate) {
    for (u8 i = 0; i < ARRAY_COUNT(save1->persons); i++) {
        const map_event_person *p = save1->persons + i;
        if (p->script_std == PERSON_PUZZLE_BOULDER) {
            u8 direction = DIR_NONE;
            switch (p->behavior) {
                case BEHAVIOUR_FACE_DOWN:
                    direction = DIR_DOWN;
                    break;
                case BEHAVIOUR_FACE_UP: 
                    direction = DIR_UP;
                    break;
                case BEHAVIOUR_FACE_LEFT:
                    direction = DIR_LEFT;
                    break;
                case BEHAVIOUR_FACE_RIGHT:
                    direction = DIR_RIGHT;
                    break;
            }
            u8 direction_new = direction_flip_and_rotate(direction, horizontal, vertical, rotate);
            u8 npc_idx = 0;
            if (!npc_get_id_by_overworld_id(p->target_index, save1->map, save1->bank, &npc_idx)) {
                if (direction != npcs[npc_idx].direction.facing) {
                    DEBUG("Warning: Boulder with person idx %d had person direction %d but npc direction %d\n", i, direction, npcs[npc_idx].direction.facing);
                    direction = npcs[npc_idx].direction.facing;
                    direction_new = direction_flip_and_rotate(direction, horizontal, vertical, rotate);
                }
                DEBUG("Npc %d gets a new direction %d (person is %d)\n", npc_idx, direction_new, p->target_index);
                npc *n = npcs + npc_idx;
                npc_set_facing(n, direction_new);
                npc_save_position_and_facing_to_person(n);
            }
            switch (direction_new) {
                case DIR_DOWN:
                    person_set_behaviour(p->target_index, BEHAVIOUR_FACE_DOWN);
                    break;
                case DIR_UP:
                    person_set_behaviour(p->target_index, BEHAVIOUR_FACE_UP);
                    break;
                case DIR_LEFT:
                    person_set_behaviour(p->target_index, BEHAVIOUR_FACE_LEFT);
                    break;
                case DIR_RIGHT:
                    person_set_behaviour(p->target_index, BEHAVIOUR_FACE_RIGHT);
                    break;
            }
        }
    }
}


void bruchfels_gym_puzzle_flip_boulders_horizontally() {
    bruchfels_gym_puzzle_flip_and_rotate_boulders(true, false, false);
}  

void bruchfels_gym_puzzle_flip_boulders_vertically() {
    bruchfels_gym_puzzle_flip_and_rotate_boulders(false, true, false);
}  

void bruchfels_gym_puzzle_rotate_boulders() {
    bruchfels_gym_puzzle_flip_and_rotate_boulders(false, false, true);
}
