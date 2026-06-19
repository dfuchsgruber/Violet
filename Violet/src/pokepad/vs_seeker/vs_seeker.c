#include "pokepad/vs_seeker.h"
#include "agbmemory.h"
#include "callbacks.h"
#include "constants/movements.h"
#include "constants/person_behaviours.h"
#include "fading.h"
#include "music.h"
#include "overworld/effect.h"
#include "overworld/map_control.h"
#include "overworld/script.h"
#include "pokepad/pokepad2.h"
#include "superstate.h"
#include "trainer/trainer.h"
#include "trainer/virtual.h"
#include "types.h"
#include "vars.h"
#include "debug.h"
#include "battle/state.h"

void vs_seeker_callback_return_to_ow_and_init_script() {
    generic_callback1();
    if (!fading_is_active()) {
        pokepad2_free();
        overworld_script_init(ow_script_vs_seeker);
        map_reload();
    }
}

void vs_seeker_initialize(bool is_outdoor) {
    if (is_outdoor) {
        overworld_script_init(ow_script_vs_seeker);
    } else {
        fadescreen_all(1, 0);
        callback1_set(vs_seeker_callback_return_to_ow_and_init_script);
    }
}

static const u8 movements_trainer_unfought[] = {SAY_EXCLAM, STOP};
static const u8 movements_trainer_rematchable[] = {LOOK_DOWN_DELAYED, 101, STOP};
static const u8 movements_trainer_no_rematch[] = {SAY_X, STOP};
static const u8 movements_player_wait[] = {PAUSE_16, PAUSE_16, PAUSE_16, STOP};

u8 vs_seeker_get_movement_type_by_sprite_idx(u8 sprite_idx) {
    switch (sprite_idx) {
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x25:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2d:
    case 0x2e:
    case 0x36:
    case 0x38:
    case 0x3e:
        return BEHAVIOUR_RAISE_HAND_AND_JUMP;
    default:
        return BEHAVIOUR_RAISE_HAND_AND_STOP;
    case 0x24:
    case 0x2b:
    case 0x2c:
        return BEHAVIOUR_RAISE_HAND_AND_SWIM;
    }
}

u8 vs_seeker_get_response_by_visible_trainers() {
    for (size_t i = 0; vs_seeker_state->trainers[i].person_idx != 0xFF; i++) {
        vs_seeker_trainer_t *trainer = vs_seeker_state->trainers + i;
        if (vs_seeker_is_trainer_visible(trainer)) {
            if (!checktrainerflag(trainer->trainer_idx)) {
                vs_seeker_trainer_applymovement(trainer, movements_trainer_unfought);
                vs_seeker_state->trainer_has_not_been_fought = 1;
            } else if (vs_seeker_trainer_wants_rematch(trainer->trainer_idx)) {
                vs_seeker_state->behaviours[vs_seeker_state->num_rematchable_trainers] = vs_seeker_get_movement_type_by_sprite_idx(
                    trainer->sprite_idx
                );
                vs_seeker_person_set_rematch_triggered(trainer->person_idx);
                vs_seeker_state->trainer_idxs[vs_seeker_state->num_rematchable_trainers] = trainer->trainer_idx;
                vs_seeker_state->num_rematchable_trainers++;
                npc_update_coordinates_with_current(npcs + trainer->npc_idx);
                vs_seeker_trainer_applymovement(trainer, movements_trainer_rematchable);
                vs_seeker_state->trainer_wants_rematch = 1;
                // DEBUG("Trainer %d wants rematch", trainer->trainer_idx);
            } else {
                vs_seeker_trainer_applymovement(trainer, movements_trainer_no_rematch);
                vs_seeker_state->trainer_does_not_want_rematch = 1;
            }
        }
    }
    if (vs_seeker_state->trainer_wants_rematch) {
        play_sound(0x15);
        return VSSEEKER_RESPONSE_FOUND_REMATCHES;
    } else if (vs_seeker_state->trainer_has_not_been_fought)
        return VSSEEKER_RESPONSE_UNFOUGHT_TRAINERS;
    else if (vs_seeker_state->trainer_does_not_want_rematch)
        return VSSEEKER_RESPONSE_NO_REMATCHES_FOUND;
    return VSSEEKER_RESPONSE_NO_VISIBLE_TRAINERS;
}

bool vs_seeker_is_any_rematchable_trainer_visible() {
    for (size_t vs_seeker_idx = 0; vs_seeker_state->trainers[vs_seeker_idx].person_idx != 0xFF; vs_seeker_idx++) {
        if (vs_seeker_is_trainer_visible(vs_seeker_state->trainers + vs_seeker_idx)) {
            return true;
        }
    }
    return false;
}

void vs_seeker_rematch_trainers_start_idle_movement() {
    for (size_t i = 0; i < vs_seeker_state->num_rematchable_trainers; i++) {
        // Find matching trainer in vs_seeker_state
        for (size_t j = 0; vs_seeker_state->trainers[j].person_idx != 0xFF; j++) {
            if (vs_seeker_state->trainers[j].trainer_idx == vs_seeker_state->trainer_idxs[i]) {
                u8 npc_idx = vs_seeker_state->trainers[j].npc_idx;
                if (npc_idx_is_sane(npc_idx)) {
                    npc_set_trainer_movement_type(npcs + npc_idx, vs_seeker_state->behaviours[i]);
                }
                npc_override_movement_type(npcs + npc_idx, vs_seeker_state->behaviours[i]);
            }
        }
    }
}

void vs_seeker_callback_step_3_wait_for_movement(u8 self) {
    if (npc_movement_callback_is_finished(0xFF, save1->map, save1->bank)) {
        overworld_script_resume();
        if (vs_seeker_state->response_code == VSSEEKER_RESPONSE_NO_VISIBLE_TRAINERS ||
            vs_seeker_state->response_code == VSSEEKER_RESPONSE_NO_REMATCHES_FOUND) {
            lastresult = 2;
        } else {
            if (vs_seeker_state->response_code == VSSEEKER_RESPONSE_FOUND_REMATCHES)
                vs_seeker_rematch_trainers_start_idle_movement();
            tbox_clear_message(0, true);
            npc_player_clear_held_movement_and_unlock_npcs();
            lastresult = 1;
        }
        free(vs_seeker_state);
        big_callback_delete(self);
    }
}

void vs_seeker_callback_step_2_sound_effect(u8 self) {
    s16 *data = (s16 *)big_callbacks[self].params;

    if (data[2] != 2 && --data[1] == 0) {
        play_sound(0x5E);
        data[1] = 11;
        data[2]++;
    }

    if (!overworld_effect_is_active(OVERWORLD_EFFECT_USE_VS_SEEKER)) {
        data[1] = 0;
        data[2] = 0;
        vs_seeker_state->response_code = (u8)(vs_seeker_get_response_by_visible_trainers() & 7);
        npc_apply_movement(0xFF, save1->map, save1->bank, movements_player_wait);
        big_callbacks[self].function = vs_seeker_callback_step_3_wait_for_movement;
    }
}

void vs_seeker_callback_step_1_wait(u8 self) {
    u16 *data = big_callbacks[self].params;
    if (--data[0] == 0) {
        big_callbacks[self].function = vs_seeker_callback_step_2_sound_effect;
        data[1] = 16;
    }
}

void vs_seeker_callback_step_0_initialize(u8 self) {
    for (size_t i = 0; i < ARRAY_COUNT(big_callbacks[self].params); i++) {
        big_callbacks[self].params[i] = 0;
    }
    vs_seeker_state = malloc_and_clear(sizeof(vs_seeker_state_t));
    vs_seeker_state_initialize_by_persons();
    if (!vs_seeker_is_any_rematchable_trainer_visible()) {
        lastresult = 0;
        big_callback_delete(self);
        overworld_script_resume();
        free(vs_seeker_state);
    } else {
        big_callbacks[self].function = vs_seeker_callback_step_1_wait;
        big_callbacks[self].params[0] = 15;
        overworld_effect_new(OVERWORLD_EFFECT_USE_VS_SEEKER);
    }
}

void vs_seeker() {
    big_callback_new(vs_seeker_callback_step_0_initialize, 10);
}

void vs_seeker_reset_on_map(UNUSED u8 bank, UNUSED u8 map_idx) {
    vs_seeker_person_clear_rematch_triggered_for_all();
}


void vs_seeker_do_rematch_trainerbattle() {
    battle_flags = BATTLE_TRAINER | BATTLE_VS_SEEKER;
    super.saved_callback = trainerbattle_continuation;
    trainerbattle_start();
    *var_access(VAR_TRAINERBATTLE_REMATCHES_FOUGHT) = MIN(9999, *var_access(VAR_TRAINERBATTLE_REMATCHES_FOUGHT) + 1);
    overworld_script_halt();
}

static const u8 vs_seeker_visible_rematch_movements[] = {LOOK_DOWN_DELAYED, 101, 95, STOP};

bool vs_seeker_new_rematches_visible() {
    if (!checkflag(FLAG_VS_SEEKER)) return false;
    if (!checkflag(FLAG_REMATCHES_ACHIEVEMENT_50_REWARD)) return false;
    
    vs_seeker_state = malloc_and_clear(sizeof(vs_seeker_state_t));
    vs_seeker_state_initialize_by_persons();
    // DEBUG("Checking for new rematches, num trainers %d\n", vs_seeker_state->num_rematchable_trainers);
    bool result = false;
    for (size_t i = 0; vs_seeker_state->trainers[i].person_idx != 0xFF; i++) {
        // DEBUG("Trainer %d, visible %d, flag %d, wants rematch %d, rematch triggered %d\n",
        //     i,
        //     vs_seeker_is_trainer_visible(vs_seeker_state->trainers + i),
        //     checktrainerflag(vs_seeker_state->trainers[i].trainer_idx),
        //      vs_seeker_trainer_wants_rematch(vs_seeker_state->trainers[i].trainer_idx),
        //     vs_seeker_person_get_rematch_triggered(vs_seeker_state->trainers[i].person_idx)
        // );
        if (vs_seeker_is_trainer_visible(vs_seeker_state->trainers + i) &&
            checktrainerflag(vs_seeker_state->trainers[i].trainer_idx) &&
            vs_seeker_trainer_wants_rematch(vs_seeker_state->trainers[i].trainer_idx) &&
            !vs_seeker_person_get_rematch_triggered(vs_seeker_state->trainers[i].person_idx)) {
                result = true;
                // DEBUG("Trainer %d wants rematch", vs_seeker_state->trainers[i].trainer_idx);
                vs_seeker_trainer_t *trainer = vs_seeker_state->trainers + i;
                 vs_seeker_state->behaviours[vs_seeker_state->num_rematchable_trainers] = vs_seeker_get_movement_type_by_sprite_idx(
                    trainer->sprite_idx
                );
                vs_seeker_person_set_rematch_triggered(trainer->person_idx);
                vs_seeker_state->trainer_idxs[vs_seeker_state->num_rematchable_trainers] = trainer->trainer_idx;
                vs_seeker_state->num_rematchable_trainers++;
                npc_update_coordinates_with_current(npcs + trainer->npc_idx);
                // u8 npc_idx = vs_seeker_state->trainers[i].npc_idx;
                // if (npc_idx_is_sane(npc_idx)) {
                //     npc_set_trainer_movement_type(npcs + npc_idx, vs_seeker_state->behaviours[i]);
                // }
                // npc_override_movement_type(npcs + npc_idx, vs_seeker_state->behaviours[i]);
                vs_seeker_trainer_applymovement(trainer, vs_seeker_visible_rematch_movements);
        }
    }
    if (result) {
        vs_seeker_rematch_trainers_start_idle_movement();
    }
    free(vs_seeker_state);
    return result;
}