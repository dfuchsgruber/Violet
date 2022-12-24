#include "types.h"
#include "overworld/npc.h"
#include "tile/block.h"
#include "tile/coordinate.h"
#include "constants/movements.h"
#include "debug.h"
#include "overworld/effect.h"
#include "music.h"

void npc_diag_update_pos(npc *n, oam_object *target, u8 direction) {
    n->dest_x = (s16) (n->from_x + walking_directions[direction].x);
    n->dest_y = (s16) (n->from_y + walking_directions[direction].y);
    target->private[3] = direction;
}

bool npc_anim_diag_ne_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, NPC_ANIM_SPEED_WALK_NORMAL);
    npc_diag_update_pos(n, target, 8);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_nw_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, NPC_ANIM_SPEED_WALK_NORMAL);
    npc_diag_update_pos(n, target, 7);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_se_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, NPC_ANIM_SPEED_WALK_NORMAL);
    npc_diag_update_pos(n, target, 6);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_sw_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, NPC_ANIM_SPEED_WALK_NORMAL);
    npc_diag_update_pos(n, target, 5);
    return npc_anim_walk_is_finished(n, target);
}

bool(*npc_anim_diag_no_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_ne_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_so_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_se_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_sw_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_sw_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_nw_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_nw_init, npc_anim_walk_is_finished, npc_anim_stop};


bool npc_anim_diag_ne_running_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, NPC_ANIM_SPEED_WALK_RUNNING);
    npc_diag_update_pos(n, target, 8);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_nw_running_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, NPC_ANIM_SPEED_WALK_RUNNING);
    npc_diag_update_pos(n, target, 7);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_se_running_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, NPC_ANIM_SPEED_WALK_RUNNING);
    npc_diag_update_pos(n, target, 6);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_sw_running_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, NPC_ANIM_SPEED_WALK_RUNNING);
    npc_diag_update_pos(n, target, 5);
    return npc_anim_walk_is_finished(n, target);
}

bool(*npc_anim_diag_no_running_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_ne_running_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_so_running_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_se_running_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_sw_running_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_sw_running_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_nw_running_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_nw_running_init, npc_anim_walk_is_finished, npc_anim_stop};


bool npc_anim_diag_ne_riding_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, NPC_ANIM_SPEED_WALK_RIDING);
    npc_diag_update_pos(n, target, 8);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_nw_riding_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, NPC_ANIM_SPEED_WALK_RIDING);
    npc_diag_update_pos(n, target, 7);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_se_riding_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, NPC_ANIM_SPEED_WALK_RIDING);
    npc_diag_update_pos(n, target, 6);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_sw_riding_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, NPC_ANIM_SPEED_WALK_RIDING);
    npc_diag_update_pos(n, target, 5);
    return npc_anim_walk_is_finished(n, target);
}

bool(*npc_anim_diag_no_riding_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_ne_riding_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_so_riding_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_se_riding_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_sw_riding_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_sw_riding_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_nw_riding_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_nw_riding_init, npc_anim_walk_is_finished, npc_anim_stop};

bool npc_anim_diag_ne_very_fast_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, NPC_ANIM_SPEED_WALK_VERY_FAST);
    npc_diag_update_pos(n, target, 8);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_nw_very_fast_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, NPC_ANIM_SPEED_WALK_VERY_FAST);
    npc_diag_update_pos(n, target, 7);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_se_very_fast_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, NPC_ANIM_SPEED_WALK_VERY_FAST);
    npc_diag_update_pos(n, target, 6);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_sw_very_fast_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, NPC_ANIM_SPEED_WALK_VERY_FAST);
    npc_diag_update_pos(n, target, 5);
    return npc_anim_walk_is_finished(n, target);
}

bool(*npc_anim_diag_no_very_fast_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_ne_very_fast_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_so_very_fast_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_se_very_fast_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_sw_very_fast_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_sw_very_fast_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_nw_very_fast_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_nw_very_fast_init, npc_anim_walk_is_finished, npc_anim_stop};

bool npc_anim_diag_ne_sliding_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, NPC_ANIM_SPEED_WALK_SLIDE);
    npc_diag_update_pos(n, target, 8);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_nw_sliding_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, NPC_ANIM_SPEED_WALK_SLIDE);
    npc_diag_update_pos(n, target, 7);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_se_sliding_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, NPC_ANIM_SPEED_WALK_SLIDE);
    npc_diag_update_pos(n, target, 6);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_sw_sliding_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, NPC_ANIM_SPEED_WALK_SLIDE);
    npc_diag_update_pos(n, target, 5);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_walk_down_facing_up_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, DIR_UP, NPC_ANIM_SPEED_WALK_NORMAL);
    n->dest_y = (s16) (n->from_y + 1);
    target->private[3] = DIR_DOWN;
    return npc_anim_walk_is_finished(n, target);
}

bool (*npc_anim_walk_down_facing_up[])(npc *n, oam_object *target) = {
    npc_anim_walk_down_facing_up_init, 
    npc_anim_walk_is_finished, 
    npc_anim_stop
};

bool(*npc_anim_diag_no_sliding_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_ne_sliding_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_so_sliding_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_se_sliding_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_sw_sliding_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_sw_sliding_init, npc_anim_walk_is_finished, npc_anim_stop};

bool(*npc_anim_diag_nw_sliding_frames[0x3])(npc *n, oam_object *target) = {npc_anim_diag_nw_sliding_init, npc_anim_walk_is_finished, npc_anim_stop};

bool npc_anim_pause_32_init(npc *n, oam_object *target) {
    npc_anim_pause_init(target, 32);
    return npc_anim_pause_finished(n, target);
}

bool (*npc_anim_pause_32[])(npc *n, oam_object *target) = {
    npc_anim_pause_32_init, 
    npc_anim_pause_finished, 
    npc_anim_stop
};

bool npc_anim_rainbow_down_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, DIR_DOWN, NPC_ANIM_SPEED_WALK_VERY_FAST);
    return npc_anim_walk_is_finished(n, target);
}
bool npc_anim_rainbow_up_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, DIR_UP, NPC_ANIM_SPEED_WALK_VERY_FAST);
    return npc_anim_walk_is_finished(n, target);
}
bool npc_anim_rainbow_left_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, DIR_LEFT, NPC_ANIM_SPEED_WALK_VERY_FAST);
    return npc_anim_walk_is_finished(n, target);
}
bool npc_anim_rainbow_right_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, DIR_RIGHT, NPC_ANIM_SPEED_WALK_VERY_FAST);
    return npc_anim_walk_is_finished(n, target);
}

bool(*npc_anim_rainbow_down[0x3])(npc *n, oam_object *target) = {npc_anim_rainbow_down_init, npc_anim_walk_is_finished, npc_anim_stop};
bool(*npc_anim_rainbow_up[0x3])(npc *n, oam_object *target) = {npc_anim_rainbow_up_init, npc_anim_walk_is_finished, npc_anim_stop};
bool(*npc_anim_rainbow_left[0x3])(npc *n, oam_object *target) = {npc_anim_rainbow_left_init, npc_anim_walk_is_finished, npc_anim_stop};
bool(*npc_anim_rainbow_right[0x3])(npc *n, oam_object *target) = {npc_anim_rainbow_right_init, npc_anim_walk_is_finished, npc_anim_stop};

// This is the delta that is applied when starting the jump.
static u16 npc_anim_jump_deltas_initialize[4] = {0, 0, 1, 1};
// This is the delta that is applied every 16 frames (or rather everytime `JUMP_MOVED_ONE_BLOCK` is returned by `npc_normal_jump_proceed`)
static u16 npc_anim_jump_deltas_every_block[4] = {0, 1, 1, 1}; 
// This is how long a jump takes in frames
static s16 npc_jump_durations[4] = {16, 16, 32, 48};
// Basically the jump type's duration / 16, so all 16 jumping frames are evenly spaced out
static u8 npc_jump_divs[4] = {1, 1, 2, 3}; 

enum {
    JUMP_PROCEEDING = 0,
    JUMP_MOVED_ONE_BLOCK = 1,
    JUMP_FINISHED = -1,
};

static void overworld_effect_feathers_at_npc(npc *n) {
    overworld_effect_state.x = n->from_x - 7;
    overworld_effect_state.y = n->from_y - 7;
    overworld_effect_state.height = n->height.current;
    overworld_effect_state.target_ow_bank = n->bank;
    overworld_effect_state.target_ow_and_their_map = n->map;
    overworld_effect_new(OVERWORLD_EFFECT_FEATHERS);
    play_sound(150);
}

#define tdirection private[3]
#define tspeed private[4]
#define theight private[5]
#define tclk private[6]

s8 npc_normal_jump_proceed(oam_object *target) {
    if (target->tspeed != 0)
        npc_oam_apply_direction(target, (u8)target->tdirection);
    target->y2 = (s16)npc_jump_get_y((u8)(target->tclk / npc_jump_divs[target->tspeed]), (u8)target->theight);
    target->tclk++;

    if (target->tclk >= npc_jump_durations[target->tspeed]) {
        target->y2 = 0;
        return JUMP_FINISHED;
    } else if (target->tclk % 16 == 0) { // Moved by 16 pixels (i.e. one block)
        return JUMP_MOVED_ONE_BLOCK;
    } else {
        return JUMP_PROCEEDING;
    }
}

s8 npc_normal_jump_proceed_and_update_position(npc *n, oam_object *target, s8(*jump_proceed)(oam_object*)) {
    s8 result = jump_proceed(target);
    if (result == JUMP_MOVED_ONE_BLOCK && target->tspeed != JUMP_SPEED_IN_PLACE) {
        s16 x = 0; s16 y = 0;
        coordiantes_move_direction(n->direction.movement, &x, &y, 
            npc_anim_jump_deltas_every_block[target->tspeed], npc_anim_jump_deltas_every_block[target->tspeed]);
        npc_update_coordinates(n, (s16)(n->dest_x + x), (s16)(n->dest_y + y));
        n->flags.trigger_ground_effects_on_move = true;
        n->flags.covering_ground_effects_disabled = true;
        if (target->tspeed == JUMP_SPEED_3) { // Create the overworld effect for feathers
            overworld_effect_feathers_at_npc(n);
        }

    } else if (result == JUMP_FINISHED) {
        npc_update_coordinates_with_current(n);
        n->flags.trigger_ground_effects_on_stop = true;
        n->flags.landing_jump = true;
        target->gfx_anim_paused = true;
    }
    return result;
}

#undef tdirection
#undef tspeed
#undef theight
#undef tclk

void npc_apply_jump(npc *n, oam_object *target, u8 direction, u8 speed, u8 height) {
    npc_set_direction(n, direction);
    s16 x = 0;
    s16 y = 0;
    coordiantes_move_direction(direction, &x, &y, npc_anim_jump_deltas_initialize[speed], npc_anim_jump_deltas_initialize[speed]);
    npc_update_coordinates(n, (s16)(n->dest_x + x), (s16)(n->dest_y + y));
    npc_oam_set_jump_parameters(target, direction, speed, height);
    target->private[2] = 1;
    target->gfx_anim_paused = true;
    n->flags.trigger_ground_effects_on_move = true;
    n->flags.covering_ground_effects_disabled = true;
}

static void npc_anim_init_jump_no_shadow(npc *n, oam_object *target, u8 direction, u8 speed, u8 height) {
    DEBUG("jump no shadow with dir %d, speed %d, height %d\n", direction, speed, height);
    npc_apply_jump(n, target, direction, speed, height);
    u8 anim_idx = npc_get_animation_idx_by_movement_direction(n->direction.facing);
    npc_apply_animation_looping(n, target, anim_idx);
}

bool npc_anim_jump_down_3_init(npc *n, oam_object *target) {
    npc_anim_init_jump_no_shadow(n, target, DIR_DOWN, JUMP_SPEED_3, JUMP_HEIGHT_10);
    return npc_anim_jump_is_finished(n, target);
}

bool npc_anim_jump_up_3_init(npc *n, oam_object *target) {
    npc_anim_init_jump_no_shadow(n, target, DIR_UP, JUMP_SPEED_3, JUMP_HEIGHT_10);
    return npc_anim_jump_is_finished(n, target);
}

bool npc_anim_jump_left_3_init(npc *n, oam_object *target) {
    npc_anim_init_jump_no_shadow(n, target, DIR_LEFT, JUMP_SPEED_3, JUMP_HEIGHT_10);
    return npc_anim_jump_is_finished(n, target);
}

bool npc_anim_jump_right_3_init(npc *n, oam_object *target) {
    npc_anim_init_jump_no_shadow(n, target, DIR_RIGHT, JUMP_SPEED_3, JUMP_HEIGHT_10);
    return npc_anim_jump_is_finished(n, target);
}

bool npc_anim_jump_3_is_feathers_finished(npc *n, oam_object *target) {
    (void)n; (void)target;
    return !overworld_effect_is_active(OVERWORLD_EFFECT_FEATHERS);
}

bool(*npc_anim_jump_down_3[0x4])(npc *n, oam_object *target) = {npc_anim_jump_down_3_init, npc_anim_jump_is_finished, npc_anim_jump_3_is_feathers_finished, npc_anim_stop};
bool(*npc_anim_jump_up_3[0x4])(npc *n, oam_object *target) = {npc_anim_jump_up_3_init, npc_anim_jump_is_finished, npc_anim_jump_3_is_feathers_finished, npc_anim_stop};
bool(*npc_anim_jump_left_3[0x4])(npc *n, oam_object *target) = {npc_anim_jump_left_3_init, npc_anim_jump_is_finished, npc_anim_jump_3_is_feathers_finished, npc_anim_stop};
bool(*npc_anim_jump_right_3[0x4])(npc *n, oam_object *target) = {npc_anim_jump_right_3_init, npc_anim_jump_is_finished, npc_anim_jump_3_is_feathers_finished, npc_anim_stop};

bool(**npc_anims[])(npc *n, oam_object *target) = {
    [FACE_DOWN] = (bool (**)(npc*, oam_object*)) 0x83a6728,
    [LOOK_UP] = (bool (**)(npc*, oam_object*)) 0x83a6730,
    [LOOK_LEFT] = (bool (**)(npc*, oam_object*)) 0x83a6738,
    [LOOK_RIGHT] = (bool (**)(npc*, oam_object*)) 0x83a6740,
    [LOOK_DOWN] = (bool (**)(npc*, oam_object*)) 0x83a68f4,
    [0x5] = (bool (**)(npc*, oam_object*)) 0x83a68fc,
    [0x6] = (bool (**)(npc*, oam_object*)) 0x83a6904,
    [0x7] = (bool (**)(npc*, oam_object*)) 0x83a690c,
    [STEP_DOWN_VERY_SLOW] = (bool (**)(npc*, oam_object*)) 0x83a678c,
    [STEP_UP_VERY_SLOW] = (bool (**)(npc*, oam_object*)) 0x83a6798,
    [STEP_LEFT_VERY_SLOW] = (bool (**)(npc*, oam_object*)) 0x83a67a4,
    [STEP_RIGHT_VERY_SLOW] = (bool (**)(npc*, oam_object*)) 0x83a67b0,
    [STEP_DOWN_SLOW] = (bool (**)(npc*, oam_object*)) 0x83a67c8,
    [STEP_UP_SLOW] = (bool (**)(npc*, oam_object*)) 0x83a67bc,
    [STEP_LEFT_SLOW] = (bool (**)(npc*, oam_object*)) 0x83a67d4,
    [STEP_RIGHT_SLOW] = (bool (**)(npc*, oam_object*)) 0x83a67e0,
    [STEP_DOWN] = (bool (**)(npc*, oam_object*)) 0x83a67ec,
    [STEP_UP] = (bool (**)(npc*, oam_object*)) 0x83a67f8,
    [STEP_LEFT] = (bool (**)(npc*, oam_object*)) 0x83a6804,
    [STEP_RIGHT] = (bool (**)(npc*, oam_object*)) 0x83a6810,
    [JUMP_DOWN2] = (bool (**)(npc*, oam_object*)) 0x83a6828,
    [JUMP_UP2] = (bool (**)(npc*, oam_object*)) 0x83a6834,
    [JUMP_LEFT2] = (bool (**)(npc*, oam_object*)) 0x83a6840,
    [JUMP_RIGHT2] = (bool (**)(npc*, oam_object*)) 0x83a684c,
    [PAUSE_1] = (bool (**)(npc*, oam_object*)) 0x83a6858,
    [PAUSE_2] = (bool (**)(npc*, oam_object*)) 0x83a6864,
    [PAUSE_4] = (bool (**)(npc*, oam_object*)) 0x83a6870,
    [PAUSE_8] = (bool (**)(npc*, oam_object*)) 0x83a687c,
    [PAUSE_16] = (bool (**)(npc*, oam_object*)) 0x83a6888,
    [STEP_DOWN_FAST] = (bool (**)(npc*, oam_object*)) 0x83a6894,
    [STEP_UP_FAST] = (bool (**)(npc*, oam_object*)) 0x83a68a0,
    [STEP_LEFT_FAST] = (bool (**)(npc*, oam_object*)) 0x83a68ac,
    [STEP_RIGHT_FAST] = (bool (**)(npc*, oam_object*)) 0x83a68b8,
    [STEP_IN_PLACE_DOWN] = (bool (**)(npc*, oam_object*)) 0x83a6914,
    [STEP_IN_PLACE_UP] = (bool (**)(npc*, oam_object*)) 0x83a6920,
    [STEP_IN_PLACE_LEFT] = (bool (**)(npc*, oam_object*)) 0x83a692c,
    [STEP_IN_PLACE_RIGHT] = (bool (**)(npc*, oam_object*)) 0x83a6938,
    [STEP_IN_PLACE_DOWN_FAST] = (bool (**)(npc*, oam_object*)) 0x83a6944,
    [STEP_IN_PLACE_UP_FAST] = (bool (**)(npc*, oam_object*)) 0x83a6950,
    [STEP_IN_PLACE_LEFT_FAST] = (bool (**)(npc*, oam_object*)) 0x83a695c,
    [STEP_IN_PLACE_RIGHT_FAST] = (bool (**)(npc*, oam_object*)) 0x83a6968,
    [STEP_IN_PLACE_DOWN_VERY_FAST] = (bool (**)(npc*, oam_object*)) 0x83a6974,
    [STEP_IN_PLACE_UP_VERY_FAST] = (bool (**)(npc*, oam_object*)) 0x83a6980,
    [STEP_IN_PLACE_LEFT_VERY_FAST] = (bool (**)(npc*, oam_object*)) 0x83a698c,
    [STEP_IN_PLACE_RIGHT_VERY_FAST] = (bool (**)(npc*, oam_object*)) 0x83a6998,
    [LOOK_DOWN_DELAYED] = (bool (**)(npc*, oam_object*)) 0x83a69a4,
    [LOOK_UP_DELAYED] = (bool (**)(npc*, oam_object*)) 0x83a69b0,
    [LOOK_LEFT_DELAYED] = (bool (**)(npc*, oam_object*)) 0x83a69bc,
    [LOOK_RIGHT_DELAYED] = (bool (**)(npc*, oam_object*)) 0x83a69c8,
    [SLIDE_DOWN] = (bool (**)(npc*, oam_object*)) 0x83a69d4,
    [SLIDE_UP] = (bool (**)(npc*, oam_object*)) 0x83a69e0,
    [SLIDE_LEFT] = (bool (**)(npc*, oam_object*)) 0x83a69ec,
    [SLIDE_RIGHT] = (bool (**)(npc*, oam_object*)) 0x83a69f8,
    [0x35] = (bool (**)(npc*, oam_object*)) 0x83a6a04,
    [0x36] = (bool (**)(npc*, oam_object*)) 0x83a6a10,
    [0x37] = (bool (**)(npc*, oam_object*)) 0x83a6a1c,
    [0x38] = (bool (**)(npc*, oam_object*)) 0x83a6a28,
    [0x39] = (bool (**)(npc*, oam_object*)) 0x83a6a34,
    [0x3a] = (bool (**)(npc*, oam_object*)) 0x83a6a40,
    [0x3b] = (bool (**)(npc*, oam_object*)) 0x83a6a4c,
    [0x3c] = (bool (**)(npc*, oam_object*)) 0x83a6a58,
    [SLIDE_DOWN_ON_RIGHT_FOOT] = (bool (**)(npc*, oam_object*)) 0x83a6a64,
    [SLIDE_UP_ON_RIGHT_FOOT] = (bool (**)(npc*, oam_object*)) 0x83a6a70,
    [SLIDE_LEFT_ON_RIGHT_FOOT] = (bool (**)(npc*, oam_object*)) 0x83a6a7c,
    [SLIDE_RIGHT_ON_RIGHT_FOOT] = (bool (**)(npc*, oam_object*)) 0x83a6a88,
    [SLIDE_DOWN_ON_LEFT_FOOT] = (bool (**)(npc*, oam_object*)) 0x83a6a94,
    [SLIDE_UP_ON_LEFT_FOOT] = (bool (**)(npc*, oam_object*)) 0x83a6aa0,
    [SLIDE_LEFT_ON_LEFT_FOOT] = (bool (**)(npc*, oam_object*)) 0x83a6aac,
    [SLIDE_RIGHT_ON_LEFT_FOOT] = (bool (**)(npc*, oam_object*)) 0x83a6ab8,
    [RUN_INFINITLY] = (bool (**)(npc*, oam_object*)) 0x83a6ac4,
    [JUMP_DOWN_RUNNING] = (bool (**)(npc*, oam_object*)) 0x83a6ad0,
    [JUMP_UP_RUNNING] = (bool (**)(npc*, oam_object*)) 0x83a6adc,
    [JUMP_LEFT_RUNNING] = (bool (**)(npc*, oam_object*)) 0x83a6ae8,
    [JUMP_RIGHT_RUNNING] = (bool (**)(npc*, oam_object*)) 0x83a6af4,
    [FACE_PLAYER] = (bool (**)(npc*, oam_object*)) 0x83a6b30,
    [FACE_AWAY_FROM_PLAYER] = (bool (**)(npc*, oam_object*)) 0x83a6b38,
    [0x4c] = (bool (**)(npc*, oam_object*)) 0x83a6b40,
    [0x4d] = (bool (**)(npc*, oam_object*)) 0x83a6b48,
    [JUMP_DOWN] = (bool (**)(npc*, oam_object*)) 0x83a6b50,
    [JUMP_UP] = (bool (**)(npc*, oam_object*)) 0x83a6b5c,
    [JUMP_LEFT] = (bool (**)(npc*, oam_object*)) 0x83a6b68,
    [JUMP_RIGHT] = (bool (**)(npc*, oam_object*)) 0x83a6b74,
    [JUMP_IN_PLACE_FACE_DOWN] = (bool (**)(npc*, oam_object*)) 0x83a6b80,
    [JUMP_IN_PLACE_FACE_UP] = (bool (**)(npc*, oam_object*)) 0x83a6b8c,
    [JUMP_IN_PLACE_FACE_LEFT] = (bool (**)(npc*, oam_object*)) 0x83a6b98,
    [JUMP_IN_PLACE_FACE_RIGHT] = (bool (**)(npc*, oam_object*)) 0x83a6ba4,
    [JUMP_IN_PLACE_FACE_DOWN_TO_UP] = (bool (**)(npc*, oam_object*)) 0x83a6bb0,
    [JUMP_IN_PLACE_FACE_UP_TO_DOWN] = (bool (**)(npc*, oam_object*)) 0x83a6bbc,
    [JUMP_IN_PLACE_FACE_LEFT_TO_RIGHT] = (bool (**)(npc*, oam_object*)) 0x83a6bc8,
    [JUMP_IN_PLACE_FACE_RIGHT_TO_LEFT] = (bool (**)(npc*, oam_object*)) 0x83a6bd4,
    [0x5a] = (bool (**)(npc*, oam_object*)) 0x83a6be0,
    [0x5b] = (bool (**)(npc*, oam_object*)) 0x83a6be8,
    [0x5c] = (bool (**)(npc*, oam_object*)) 0x83a6bf4,
    [0x5d] = (bool (**)(npc*, oam_object*)) 0x83a6bfc,
    [0x5e] = (bool (**)(npc*, oam_object*)) 0x83a6c04,
    [0x5f] = (bool (**)(npc*, oam_object*)) 0x83a6c0c,
    [HIDE_SPRITE] = (bool (**)(npc*, oam_object*)) 0x83a6c14,
    [SHOW_SPRITE] = (bool (**)(npc*, oam_object*)) 0x83a6c1c,
    [SAY_EXCLAM] = (bool (**)(npc*, oam_object*)) 0x83a6c24,
    [SAY_QUESTION] = (bool (**)(npc*, oam_object*)) 0x83a6c2c,
    [SAY_X] = (bool (**)(npc*, oam_object*)) 0x83a6c34,
    [SAY_DOUBLE_EXCLAM] = (bool (**)(npc*, oam_object*)) 0x83a6c3c,
    [SAY_SMILE] = (bool (**)(npc*, oam_object*)) 0x83a6c44,
    [0x67] = (bool (**)(npc*, oam_object*)) 0x83a6c4c,
    [0x68] = (bool (**)(npc*, oam_object*)) 0x83a6c58,
    [0x69] = (bool (**)(npc*, oam_object*)) 0x83a6c68,
    [0x6a] = (bool (**)(npc*, oam_object*)) 0x83a6c78,
    [0x6b] = (bool (**)(npc*, oam_object*)) 0x83a6c80,
    [0x6c] = (bool (**)(npc*, oam_object*)) 0x83a6c88,
    [0x6d] = (bool (**)(npc*, oam_object*)) 0x83a6c90,
    [MOVEX_DOWN] = (bool (**)(npc*, oam_object*)) 0x83a6c98,
    [MOVEY_DOWN] = (bool (**)(npc*, oam_object*)) 0x83a6ca4,
    [0x70] = (bool (**)(npc*, oam_object*)) 0x83a6cb0,
    [0x71] = (bool (**)(npc*, oam_object*)) 0x83a6cb8,
    [0x72] = (bool (**)(npc*, oam_object*)) 0x83a6cc0,
    [0x73] = (bool (**)(npc*, oam_object*)) 0x83a6cc8,
    [0x74] = (bool (**)(npc*, oam_object*)) 0x83a6cd0,
    [0x75] = (bool (**)(npc*, oam_object*)) 0x83a6cdc,
    [0x76] = (bool (**)(npc*, oam_object*)) 0x83a6ce8,
    [0x77] = (bool (**)(npc*, oam_object*)) 0x83a6cf4,
    [LOOK_RIGHT_LEFT_DOWNFACING] = (bool (**)(npc*, oam_object*)) 0x83a6d00,
    [0x79] = (bool (**)(npc*, oam_object*)) 0x83a6d0c,
    [0x7a] = (bool (**)(npc*, oam_object*)) 0x83a6d18,
    [0x7b] = (bool (**)(npc*, oam_object*)) 0x83a6d24,
    [0x7c] = (bool (**)(npc*, oam_object*)) 0x83a6d60,
    [0x7d] = (bool (**)(npc*, oam_object*)) 0x83a6d6c,
    [0x7e] = (bool (**)(npc*, oam_object*)) 0x83a6d78,
    [0x7f] = (bool (**)(npc*, oam_object*)) 0x83a6d84,
    [0x80] = (bool (**)(npc*, oam_object*)) 0x83a6d90,
    [0x81] = (bool (**)(npc*, oam_object*)) 0x83a6d9c,
    [0x82] = (bool (**)(npc*, oam_object*)) 0x83a6da8,
    [0x83] = (bool (**)(npc*, oam_object*)) 0x83a6db4,
    [0x84] = (bool (**)(npc*, oam_object*)) 0x83a6dc0,
    [0x85] = (bool (**)(npc*, oam_object*)) 0x83a6dcc,
    [0x86] = (bool (**)(npc*, oam_object*)) 0x83a6dd8,
    [0x87] = (bool (**)(npc*, oam_object*)) 0x83a6de4,
    [0x88] = (bool (**)(npc*, oam_object*)) 0x83a6df0,
    [0x89] = (bool (**)(npc*, oam_object*)) 0x83a6dfc,
    [0x8a] = (bool (**)(npc*, oam_object*)) 0x83a6e08,
    [0x8b] = (bool (**)(npc*, oam_object*)) 0x83a6e14,
    [0x8c] = (bool (**)(npc*, oam_object*)) 0x83a6e20,
    [0x8d] = (bool (**)(npc*, oam_object*)) 0x83a6e2c,
    [0x8e] = (bool (**)(npc*, oam_object*)) 0x83a6e38,
    [0x8f] = (bool (**)(npc*, oam_object*)) 0x83a6e44,
    [0x90] = (bool (**)(npc*, oam_object*)) 0x83a6e50,
    [0x91] = (bool (**)(npc*, oam_object*)) 0x83a6e5c,
    [0x92] = (bool (**)(npc*, oam_object*)) 0x83a6e68,
    [0x93] = (bool (**)(npc*, oam_object*)) 0x83a6e74,
    [0x94] = (bool (**)(npc*, oam_object*)) 0x83a6e80,
    [0x95] = (bool (**)(npc*, oam_object*)) 0x83a6e8c,
    [0x96] = (bool (**)(npc*, oam_object*)) 0x83a6e98,
    [0x97] = (bool (**)(npc*, oam_object*)) 0x83a6ea4,
    [0x98] = (bool (**)(npc*, oam_object*)) 0x83a6eb0,
    [0x99] = (bool (**)(npc*, oam_object*)) 0x83a6eb8,
    [0x9a] = (bool (**)(npc*, oam_object*)) 0x83a6ec0,
    [0x9b] = (bool (**)(npc*, oam_object*)) 0x83a675c,
    [0x9c] = (bool (**)(npc*, oam_object*)) 0x83a6768,
    [0x9d] = (bool (**)(npc*, oam_object*)) 0x83a6774,
    [0x9e] = (bool (**)(npc*, oam_object*)) 0x83a6780,
    [0x9f] = (bool (**)(npc*, oam_object*)) 0x83a6ec8,
    [LIFT_DOWN] = (bool (**)(npc*, oam_object*)) 0x83a68c4,
    [LIFT_UP] = (bool (**)(npc*, oam_object*)) 0x83a68d0,
    [LIFT_LEFT] = (bool (**)(npc*, oam_object*)) 0x83a68dc,
    [LIFT_RIGHT] = (bool (**)(npc*, oam_object*)) 0x83a68e8,
    [0xa4] = (bool (**)(npc*, oam_object*)) 0x83a6ed0,
    [FLY_OUT_OF_SCREEN] = (bool (**)(npc*, oam_object*)) 0x83a6edc,
    [FLY_FROM_SCREEN] = (bool (**)(npc*, oam_object*)) 0x83a6b00,
    [0xa7] = (bool (**)(npc*, oam_object*)) 0x83a6b0c,
    [0xa8] = (bool (**)(npc*, oam_object*)) 0x83a6b18,
    [0xa9] = (bool (**)(npc*, oam_object*)) 0x83a6b24,
    [STEP_NORTH_EAST] = npc_anim_diag_no_frames,
    [STEP_SOUTH_EAST] = npc_anim_diag_so_frames,
    [STEP_SOUTH_WEST] = npc_anim_diag_sw_frames,
    [STEP_NORTH_WEST] = npc_anim_diag_nw_frames,
    [STEP_NORTH_EAST_RUNNING] = npc_anim_diag_no_running_frames,
    [STEP_SOUTH_EAST_RUNNING] = npc_anim_diag_so_running_frames,
    [STEP_SOUTH_WEST_RUNNING] = npc_anim_diag_sw_running_frames,
    [STEP_NORTH_WEST_RUNNING] = npc_anim_diag_nw_running_frames,
    [STEP_NORTH_EAST_RIDING] = npc_anim_diag_no_riding_frames,
    [STEP_SOUTH_EAST_RIDING] = npc_anim_diag_so_riding_frames,
    [STEP_SOUTH_WEST_RIDING] = npc_anim_diag_sw_riding_frames,
    [STEP_NORTH_WEST_RIDING] = npc_anim_diag_nw_riding_frames,
    [STEP_NORTH_EAST_VERY_FAST] = npc_anim_diag_no_very_fast_frames,
    [STEP_SOUTH_EAST_VERY_FAST] = npc_anim_diag_so_very_fast_frames,
    [STEP_SOUTH_WEST_VERY_FAST] = npc_anim_diag_sw_very_fast_frames,
    [STEP_NORTH_WEST_VERY_FAST] = npc_anim_diag_nw_very_fast_frames,
    [STEP_NORTH_EAST_SLIDING] = npc_anim_diag_no_sliding_frames,
    [STEP_SOUTH_EAST_SLIDING] = npc_anim_diag_so_sliding_frames,
    [STEP_SOUTH_WEST_SLIDING] = npc_anim_diag_sw_sliding_frames,
    [STEP_NORTH_WEST_SLIDING] = npc_anim_diag_nw_sliding_frames,
    [STEP_WALK_DOWN_FACING_UP] = npc_anim_walk_down_facing_up,
    [PAUSE_32] = npc_anim_pause_32,
    [STEP_DOWN_RAINBOW] = npc_anim_rainbow_down,
    [STEP_UP_RAINBOW] = npc_anim_rainbow_up,
    [STEP_LEFT_RAINBOW] = npc_anim_rainbow_left,
    [STEP_RIGHT_RAINBOW] = npc_anim_rainbow_right,
    [JUMP_DOWN_3] = npc_anim_jump_down_3,
    [JUMP_UP_3] = npc_anim_jump_up_3,
    [JUMP_LEFT_3] = npc_anim_jump_left_3,
    [JUMP_RIGHT_3] = npc_anim_jump_right_3,
};
