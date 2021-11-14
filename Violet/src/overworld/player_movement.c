#include "types.h"
#include "overworld/npc.h"
#include "overworld/sprite.h"
#include "tile/block.h"
#include "tile/coordinate.h"
#include "tile/diagonal_stair.h"
#include "superstate.h"
#include "agbmemory.h"
#include "constants/sav_keys.h"
#include "constants/attacks.h"
#include "constants/overworld/overworld_collisions.h"
#include "save.h"
#include "constants/songs.h"
#include "callbacks.h"
#include "music.h"
#include "overworld/script.h"
#include "superstate.h"
#include "flags.h"
#include "constants/movements.h"
#include "constants/block_behaviour.h"
#include "debug.h"
#include "options.h"
#include "vars.h"
#include "overworld/effect.h"


#define DEBUG_PLAYER_HAS_ALL_CLOUD_FEATURES true

extern u8 ow_script_transition_start_surfing[];
extern u8 ow_script_transition_start_waterfall[];

bool npc_player_attempt_transition_land_to_water() {
    return (checkflag(FRBADGE_4) && player_pokemon_has_surf() && player_can_use_surf_on_tile_faced() && !(player_state.state & PLAYER_STATE_SURFING) && automatic_hm_usage_active());
}

bool npc_player_attempt_surfing_into_waterfall() {
    return (checkflag(FRBADGE_7) && player_can_use_waterfall_on_tile_faced() && automatic_hm_usage_active() && player_pokemon_has_waterfall());
}

bool npc_player_surfing_towards_waterfall(u8 direction) {
    coordinate_t pos;
    pos.x = npcs[player_state.npc_idx].dest_x;
    pos.y = npcs[player_state.npc_idx].dest_y;
    if (direction == DIR_UP) {
        coordinates_apply_direction(direction, &pos.x, &pos.y);
        if (behaviour_is_waterfall((u8)(block_get_behaviour_by_pos(pos.x, pos.y)))) {
            return true;
        }
    }
    return false;
}

bool block_cloud_ledge_triggered(s16 x, s16 y, u8 direction) {
    (void)direction;
    if ((player_state.state & PLAYER_STATE_BIKING) && (checkflag(FLAG_CLOUD_HAS_WINGS) || DEBUG_PLAYER_HAS_ALL_CLOUD_FEATURES)) {
        u16 behaviour = block_get_behaviour_by_pos(x, y);
        if (behaviour == MB_JUMP_ALL_WITH_CLOUD) {
            return true;
        }
    }
    return false;
}

static u8 npc_player_get_collision_after_ledge(npc *player, s16 x, s16 y, u8 direction, u8 jump_over) {
    // Check if the block "after" the ledge yields no collision on its own
    npc dummy = *player;
    for (; jump_over > 0; jump_over--) {
        coordinates_apply_direction(direction, &dummy.dest_x, &dummy.dest_y);
        coordinates_apply_direction(direction, &dummy.from_x, &dummy.from_y);
        coordinates_apply_direction(direction, &x, &y);
    }
    return npc_get_collision(&dummy, x, y, direction);
}


int npc_player_attempt_step(npc *player, s16 x, s16 y, u8 direction, int param_5) {
    (void) param_5; // unused in fire red
    int collision = npc_attempt_diagonal_move(player, x, y, direction);
    if (collision == COLLISION_HEIGHT_MISMATCH && npc_player_attempt_transition_water_to_land(x, y, direction)) {
        return COLLISION_STOP_SURFING;
    } else if (collision == COLLISION_HEIGHT_MISMATCH && npc_player_attempt_transition_land_to_water()) {
        return COLLISION_START_SURFING;
    }
    if (block_ledge_triggered(x, y, direction)) {
        if (npc_player_get_collision_after_ledge(player, x, y, direction, 1) == COLLISION_NONE) {
            save_increment_key(SAV_KEY_LEDGES_JUMPED);
            return COLLISION_LEDGE;
        } else {
            return COLLISION_IMPASSABLE; // There are no special collision events like boulder pushing along ledges
        }
    } else if (block_cloud_ledge_triggered(x, y, direction)) {
        if (npc_player_get_collision_after_ledge(player, x, y, direction, 2) == COLLISION_NONE) {
            save_increment_key(SAV_KEY_LEDGES_JUMPED);
            // dprintf("Return cloud collision\n");
            return COLLISION_CLOUD_LEDGE;
        } else {
            return COLLISION_IMPASSABLE; // There are no special collision events like boulder pushing along ledges
        }
    }
    if (collision == COLLISION_OTHER_NPC && boulder_push_attempt(x, y, direction)) {
        // dprintf("Collision with strength boulder.\n");
        return COLLISION_PUSHED_BOULDER;
    }
    // Update the player's ladder state
    switch (block_get_behaviour_by_pos(player->from_x, player->from_y)) {
        case MB_CLIMBABLE_LADDER_BOTTOM: {
            if (direction == DIR_UP)
                setflag(FLAG_PLAYER_ON_LADDER);
            else
                clearflag(FLAG_PLAYER_ON_LADDER);
            break;
        }
        case MB_CLIMBABLE_LADDER_TOP: {
            if (direction == DIR_DOWN)
                setflag(FLAG_PLAYER_ON_LADDER);
            else
                clearflag(FLAG_PLAYER_ON_LADDER);
            break;
        }
        case MB_CLIMBABLE_LADDER_MIDPOINT: {
            if (direction == DIR_UP || direction == DIR_DOWN)
                setflag (FLAG_PLAYER_ON_LADDER);
            else
                clearflag(FLAG_PLAYER_ON_LADDER);
            break;
        }
    }
    if (checkflag(FLAG_PLAYER_ON_LADDER)) {
        if (collision == COLLISION_NONE && (direction == DIR_DOWN || direction == DIR_UP)) {
            return COLLISION_LADDER;
        } else {
            return COLLISION_LADDER_BLOCKED;
        }      
    }
    return collision;
}

bool block_is_ledge_any_direction(u16 behaviour) {
    return behaviour == MB_JUMP_ALL;
}

extern bool (*block_is_ledge_by_direction[4])(u16);

u8 player_get_ledge_direction(s16 x, s16 y, u8 direction) {
    if (direction == DIR_NONE)
        return DIR_NONE;
    u16 behaviour = block_get_behaviour_by_pos(x, y);
    if (direction > DIR_RIGHT)
        direction = (u8) (direction - 4);
    if (block_is_ledge_by_direction[MIN((int)ARRAY_COUNT(block_is_ledge_by_direction), direction - 1)](behaviour)) {
        return direction;
    }
    if (block_is_ledge_any_direction(behaviour))
        return direction;
    return DIR_NONE;
}

static u8 diagonal_walking_movement_idx_by_collision(u8 collision) {
    switch (collision) {
        case COLLISION_SIDEWAY_STAIRS_NORTH_EAST: return STEP_NORTH_EAST;
        case COLLISION_SIDEWAY_STAIRS_SOUTH_EAST: return STEP_SOUTH_EAST;
        case COLLISION_SIDEWAY_STAIRS_SOUTH_WEST: return STEP_SOUTH_WEST;
        case COLLISION_SIDEWAY_STAIRS_NORTH_WEST: return STEP_NORTH_WEST;
        default: return 0;
    }
}

static void npc_player_init_move_diagonal_walking(u8 collision) {
    npc_player_set_state_and_execute_tile_anim(diagonal_walking_movement_idx_by_collision(collision), 2);
}


static u8 diagonal_running_movement_idx_by_collision(u8 collision) {
    switch (collision) {
        case COLLISION_SIDEWAY_STAIRS_NORTH_EAST: return STEP_NORTH_EAST_RUNNING;
        case COLLISION_SIDEWAY_STAIRS_SOUTH_EAST: return STEP_SOUTH_EAST_RUNNING;
        case COLLISION_SIDEWAY_STAIRS_SOUTH_WEST: return STEP_SOUTH_WEST_RUNNING;
        case COLLISION_SIDEWAY_STAIRS_NORTH_WEST: return STEP_NORTH_WEST_RUNNING;
        default: return 0;
    }
}

static void npc_player_init_move_diagonal_running(u8 collision) {
    npc_player_set_state_and_execute_tile_anim(diagonal_running_movement_idx_by_collision(collision), 2);
}

static u8 diagonal_biking_movement_idx_by_collision(u8 collision) {
    switch (collision) {
        case COLLISION_SIDEWAY_STAIRS_NORTH_EAST: return STEP_NORTH_EAST_RIDING;
        case COLLISION_SIDEWAY_STAIRS_SOUTH_EAST: return STEP_SOUTH_EAST_RIDING;
        case COLLISION_SIDEWAY_STAIRS_SOUTH_WEST: return STEP_SOUTH_WEST_RIDING;
        case COLLISION_SIDEWAY_STAIRS_NORTH_WEST: return STEP_NORTH_WEST_RIDING;
        default: return 0;
    }
}

static void npc_player_init_move_diagonal_biking(u8 collision) {
    npc_player_set_state_and_execute_tile_anim(diagonal_biking_movement_idx_by_collision(collision), 2);
}

static void npc_player_init_move_ladder(u8 direction) {
    if (direction == DIR_UP)
        npc_player_set_state_and_execute_tile_anim(STEP_UP, 2);
    else if (direction == DIR_DOWN)
        npc_player_set_state_and_execute_tile_anim(STEP_WALK_DOWN_FACING_UP, 2);
}

void npc_player_initialize_move_not_biking(u8 direction, key keys) {
    u8 collision = npc_player_collision(direction);
    //dprintf("Non biking collision type %d\n", collision);
    switch (collision) {
        case COLLISION_NONE: {
            if (player_state.state & PLAYER_STATE_SURFING) {
                if (npc_player_surfing_towards_waterfall(direction) && npc_player_attempt_surfing_into_waterfall()) {
                    overworld_script_init(ow_script_transition_start_waterfall);
                    return;
                }
                npc_player_init_move_surfing(direction);
                return;
            }
            if (keys.keys.B && !npc_can_not_run(npcs[player_state.npc_idx].behavior_tile)) {
                if (npc_player_walking_towards_rock_stairs(direction))
                    npc_player_init_move_sliding_on_left_foot(direction);
                else
                    npc_player_init_move_running(direction);
                player_state.state |= 0x80;
            } else {
                if (npc_player_walking_towards_rock_stairs(direction))
                    npc_player_init_move_walking_slow(direction);
                else
                    npc_player_init_move_walking(direction);
            }
            return;
        }
        case COLLISION_LEDGE: {
            npc_player_init_move_jump(direction);
            return;
        }
        case COLLISION_WARP: {
            npc_player_init_move_face(direction);
            return;
        }
        case COLLISION_SIDEWAY_STAIRS_NORTH_EAST:
        case COLLISION_SIDEWAY_STAIRS_NORTH_WEST:
        case COLLISION_SIDEWAY_STAIRS_SOUTH_EAST:
        case COLLISION_SIDEWAY_STAIRS_SOUTH_WEST: {
            // There are none of these tiles where the player can actually surf on (so far), so I dont check
            if (keys.keys.B && !npc_can_not_run(npcs[player_state.npc_idx].behavior_tile))
                npc_player_init_move_diagonal_running(collision);
            else
                npc_player_init_move_diagonal_walking(collision);
            return;
        }
        case COLLISION_PUSHED_BOULDER:
            return;
        case COLLISION_LADDER:
            npc_player_init_move_ladder(direction);
            return;
        case COLLISION_LADDER_BLOCKED:
            npc_player_sound_collision(direction);
            npc_player_set_state_and_execute_tile_anim(PAUSE_32, 2);
            return; 
        case COLLISION_START_SURFING:
            overworld_script_init(ow_script_transition_start_surfing);
            return;
        default: {
            npc_player_init_move_blocked(direction);
            return;
        }
    }
}

void npc_player_turn_in_place(u8 direction) {
    if (!checkflag(FLAG_PLAYER_ON_LADDER)) {
        npc_player_set_facing(direction);
    }
}

static u8 rainbow_movements[5] = {STEP_DOWN_RAINBOW, STEP_DOWN_RAINBOW, STEP_UP_RAINBOW, STEP_LEFT_RAINBOW, STEP_RIGHT_RAINBOW};

void npc_player_init_move_rainbow(u8 direction) {
    // u8 movement_idx = npc_player_get_movement_idx_by_direction_sliding(direction);
    u8 movement_idx = rainbow_movements[MIN(ARRAY_COUNT(rainbow_movements), direction)];
    npc_player_set_state_and_execute_tile_anim(movement_idx, 2);
}

static u8 jump_cloud_movements[5] = {JUMP_DOWN_3, JUMP_DOWN_3, JUMP_UP_3, JUMP_LEFT_3, JUMP_RIGHT_3};

void npc_player_init_move_jump_cloud(u8 direction) {
    u8 movement_idx = jump_cloud_movements[MIN(ARRAY_COUNT(jump_cloud_movements), direction)];
    npc_player_set_state_and_execute_tile_anim(movement_idx, 2);

}

void npc_player_initialize_move_on_bike(u8 direction, u8 unused, key keys_new, key keys_held) {
    (void)unused; (void)keys_new; (void)keys_held;
    // dprintf("move on bike, keys held %d, speed %d\n", keys_held.value, player_state.bike_speed);
    player_state.bike_speed = 0;
    // There is some biking stuff from RSE, which is cut in firered, I don't bother to copy a bunch of stuff that never gets executed
    u8 collision = npc_player_collision_on_bike(direction);
    // dprintf("Biking collision type %d\n", collision);
    switch (collision) {
        case COLLISION_LEDGE:
            // Keep the current biking speed
            npc_player_init_move_jump(direction);
            return;
        case COLLISION_CLOUD_LEDGE: {
            npc_player_init_move_jump_cloud(direction);
            return;
        }
        case COLLISION_STOP_SURFING:
        case COLLISION_PUSHED_BOULDER:
        case COLLISION_WARP:
            // Appearently nothing happens?
            return;
        case COLLISION_NONE:
        case 14:{ // This thing super weird, it is returned when stepping on cracked ice, I suppose 
            if (keys_held.keys.B && (checkflag(FLAG_CLOUD_HAS_HIGH_SPEED) || DEBUG_PLAYER_HAS_ALL_CLOUD_FEATURES)) { // High speed biking
                    // dprintf("High speed biking...\n");
                    player_state.bike_speed = 4;
                    position_t pos;
                    player_get_position(&pos);
                    overworld_effect_state.x = pos.coordinates.x - 7;
                    overworld_effect_state.y = pos.coordinates.y - 7;
                    overworld_effect_state.height = pos.height;
                    overworld_effect_state.target_ow_bank = save1->bank;
                    overworld_effect_state.target_ow_and_their_map = save1->map;
                    overworld_effect_new(OVERWORLD_EFFECT_RAINBOW_SPARKLES);
                    npc_player_init_move_rainbow(direction);
            } else if (collision == 14 || npc_player_walking_towards_rock_stairs(direction)) {
                npc_player_init_move_surfing(direction);
                // dprintf("Special collision event, collision %d, walking towards rock staris %d\n", collision, npc_player_walking_towards_rock_stairs(direction));
            } else {
                npc_player_init_move_bike(direction);
            }
            return;
        }
        case COLLISION_SIDEWAY_STAIRS_NORTH_EAST:
        case COLLISION_SIDEWAY_STAIRS_NORTH_WEST:
        case COLLISION_SIDEWAY_STAIRS_SOUTH_EAST:
        case COLLISION_SIDEWAY_STAIRS_SOUTH_WEST:
            npc_player_init_move_diagonal_biking(collision);
            return;
        default:
            npc_player_init_move_bike_blocked(direction);
            return;
    }
}

extern u8 (*npc_player_bike_transitions[])(u8, u8, key, key);

void player_npc_controll_biking(u8 direction, key keys_new, key keys_held) {
    u8 idx = player_npc_get_bike_transition_state(&direction, keys_new, keys_held);
    npc_player_bike_transitions[idx](direction, direction, keys_new, keys_held); // Don't ask me why there's a duplicate for direction here...
}

void player_transition_water_to_land(u8 direction) {
    overworld_script_set_active();
    npc_stop_all_movements_but_players();
    save_set_player_non_surfing();
    // Adjust the player state depending if on a cloud map
    player_state.state &= (u8)(~PLAYER_STATE_SURFING);
    if (map_is_cloud()) {
        player_state.state |= PLAYER_STATE_MACH_BIKE;
        playsong1(MUS_CLOUDS, 8);
    } else {
        player_state.state |= PLAYER_STATE_WALKING;
        map_current_play_song_if_not_playing();
    }
    player_state.is_locked = 1;
    u8 callback_idx = big_callback_new(player_transition_water_to_land_callback, 255);
    big_callbacks[callback_idx].params[0] = direction;
    player_transition_water_to_land_callback(callback_idx);
}

void player_transition_water_to_land_callback_update_npc(u8 self) {
    npc *n = npcs + player_state.npc_idx;
    if (npc_animation_finished(n)) {
        u8 picture = OVERWORLD_PLAYER_PICTURE_CONTEXT_WALKING;
        if (map_is_cloud()) {
            npc_player_set_bike_state(2);
            picture = OVERWORLD_PLAYER_PICTURE_CONTEXT_BIKING;
        }
        npc_update_picture(n, picture);
        npc_do_facing_move(n, npc_get_facing_movement_by_direction((u8)(big_callbacks[self].params[0])));
        player_state.is_locked = false;
        overworld_script_set_inactive();
        npc_update_oam_delay_all();
        oam_delete(oams + npcs[player_state.npc_idx].oam_surf);
        big_callback_delete(self);
        game_context_update();
    }
}

void player_npc_controll_on_ladder(u8 direction, key keys) {
    if (direction != DIR_NONE) {
        npc_player_initialize_move_not_biking(direction, keys);
    }
}

void player_npc_move(u8 direction, key keys_new, key keys_held) {
    if (checkflag(FLAG_PLAYER_ON_LADDER)) {
        player_npc_controll_on_ladder(direction, keys_held);
    } else if (player_state.state & (PLAYER_STATE_MACH_BIKE | PLAYER_STATE_ACRO_BIKE)) {
        player_npc_controll_biking(direction, keys_new, keys_held);
    } else {
        player_npc_controll_not_biking(direction, keys_held);
    }
}

void special_player_get_position_facing() {
    coordinate_t pos;
    player_get_facing_position(&pos.x, &pos.y);
    *var_access(0x8004) = (u16)(pos.x - 7);
    *var_access(0x8005) = (u16)(pos.y - 7);
}