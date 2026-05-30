#include "types.h"
#include "pokepad/vs_seeker.h"
#include "save.h"
#include "prng.h"
#include "trainer/trainer.h"
#include "trainer/virtual.h"
#include "vars.h"
#include "debug.h"

bool vs_seeker_get_rematch_flag(u16 rematch_idx) {
    if (rematch_idx >= VS_SEEKER_NUM_FLAGS) return false;
    u16 byte_idx = rematch_idx / 8;
    u8 bit_idx = rematch_idx % 8;
    return (save1->trainer_rematch_flags[byte_idx] & (1 << bit_idx)) != 0;
}

void vs_seeker_set_rematch_flag(u16 rematch_idx) {
    if (rematch_idx >= VS_SEEKER_NUM_FLAGS) return;
    u16 byte_idx = rematch_idx / 8;
    u8 bit_idx = rematch_idx % 8;
    save1->trainer_rematch_flags[byte_idx] |= (1 << bit_idx);
}

void vs_seeker_clear_rematch_flag(u16 rematch_idx) {
    if (rematch_idx >= VS_SEEKER_NUM_FLAGS) return;
    u16 byte_idx = rematch_idx / 8;
    u8 bit_idx = rematch_idx % 8;
    save1->trainer_rematch_flags[byte_idx] &= (u8)(~(1 << bit_idx));
}

void vs_seeker_reset_rematch_flags() {
    for (size_t i = 0; i < ARRAY_COUNT(save1->trainer_rematch_flags); i++) {
        save1->trainer_rematch_flags[i] = 0;
    }
}


void vs_seeker_randomly_set_rematch_flags() {
    size_t num_iterations = 1; // TODO: based on level?
    for (size_t i = 0; i < ARRAY_COUNT(save1->trainer_rematch_flags); i++) {
        for (size_t j = 0; j < num_iterations; j++) {
            save1->trainer_rematch_flags[i] |= (u8)rnd16();
        }
    }
}

void vs_seeker_set_all_rematch_flags() {
    for (size_t i = 0; i < ARRAY_COUNT(save1->trainer_rematch_flags); i++) {
        save1->trainer_rematch_flags[i] = 0xFF;
    }
}

bool vs_seeker_trainer_wants_rematch(u16 trainer_idx) {
    u16 rematch_idx = trainers[trainer_idx].rematch_flag_idx;
    if (rematch_idx == 0) return false;
    return vs_seeker_get_rematch_flag(rematch_idx);
}

void vs_seeker_person_set_rematch_triggered(u8 person_idx) {
    size_t byte_idx = person_idx / 8;
    size_t bit_idx = person_idx % 8;
    save1->trainer_rematch_triggered[byte_idx] |= (1 << bit_idx);
}

void vs_seeker_person_clear_rematch_triggered(u8 person_idx) {
    size_t byte_idx = person_idx / 8;
    size_t bit_idx = person_idx % 8;
    save1->trainer_rematch_triggered[byte_idx] &= (u8)(~(1 << bit_idx));
}


bool vs_seeker_person_get_rematch_triggered(u8 person_idx) {
    size_t byte_idx = person_idx / 8;
    size_t bit_idx = person_idx % 8;
    return (save1->trainer_rematch_triggered[byte_idx] & (1 << bit_idx)) != 0;
}

void vs_seeker_person_clear_rematch_triggered_for_all() {
    for (size_t i = 0; i < ARRAY_COUNT(save1->trainer_rematch_triggered); i++) {
        save1->trainer_rematch_triggered[i] = 0;
    }
}

void vs_seeker_check_lasttalked_trainer_rematch_triggered() {
    bool rematch_triggered = true;
    DEBUG("Checking rematch triggered for lasttalked %d: %d", (u8)lasttalked, vs_seeker_person_get_rematch_triggered((u8)lasttalked));
    if (!vs_seeker_person_get_rematch_triggered((u8)lasttalked))
        rematch_triggered = false;
    // Check the trainer flag
    u16 trainer_idx = trainer_vars.trainer_id;
    if (trainers[trainer_idx].rematch_flag_idx == 0)
        rematch_triggered = false;
    DEBUG("Checking rematch flag idx %d for trainer %d: %d", trainers[trainer_idx].rematch_flag_idx, trainer_idx, vs_seeker_get_rematch_flag(trainers[trainer_idx].rematch_flag_idx));
    if (!vs_seeker_get_rematch_flag(trainers[trainer_idx].rematch_flag_idx))
        rematch_triggered = false;
    if (rematch_triggered) {
        lastresult = 1;
    } else {
        lastresult = 0;
    }
}


void vs_seeker_set_rematch_flags_after_battle_lasttalked_trainer() {
    DEBUG("Setting rematch flags after battle for lasttalked %d", (u8)lasttalked);
    vs_seeker_person_clear_rematch_triggered((u8)lasttalked);
    u16 trainer_idx = trainer_vars.trainer_id;
    vs_seeker_clear_rematch_flag(trainers[trainer_idx].rematch_flag_idx);
}