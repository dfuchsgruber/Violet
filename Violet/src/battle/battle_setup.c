#include "types.h"
#include "battle/state.h"
#include "superstate.h"
#include "trainer/virtual.h"
#include "save.h"
#include "overworld/script.h"
#include "constants/trainer_battle_types.h"
#include "battle/ai.h"
#include "mega.h"
#include "agbmemory.h"

void battle_initialize_trainerbattle() {
    battle_flags = BATTLE_TRAINER;
    super.callbacks[2] = trainerbattle_continuation;
    if (fmem.trainers_cnt == 2 || trainer_vars.kind_of_battle == TRAINER_BATTLE_TWO_TRAINERS 
        || trainer_vars.kind_of_battle == TRAINER_BATTLE_ALLY_TWO_TRAINERS) {
        battle_flags |= BATTLE_DOUBLE | BATTLE_TWO_TRAINERS;
    }
    if (trainer_vars.kind_of_battle == TRAINER_BATTLE_ALLY_ONE_TRAINER ||
        trainer_vars.kind_of_battle == TRAINER_BATTLE_ALLY_TWO_TRAINERS) {
        battle_flags |= BATTLE_DOUBLE | BATTLE_ALLY;
    }
    // Note: The oak intro part was removed, we don't need it
    trainerbattle_start();
    overworld_script_halt();
}

bool battle_has_two_opponents() {
    return (battle_flags & (BATTLE_TWO_TRAINERS | BATTLE_MULTI)) > 0;
}


void battle_allocate_new() {
    fmem.mega_state = malloc_and_clear(sizeof(mega_state_t));
    fmem.trainer_ai_state2 = malloc_and_clear(sizeof(trainer_ai_state2_t));
    fmem.battle_state2 = malloc_and_clear(sizeof(battle_state2_t));
}

void battle_free_new() {
    if (fmem.mega_state) {
        battle_alternative_forms_revert(); // It's whack to have it here, but w/e
        free(fmem.mega_state);
        fmem.mega_state = NULL;
    }
    if (TRAINER_AI_STATE2) {
        free(TRAINER_AI_STATE2);
        fmem.trainer_ai_state2 = NULL;
    }
    if (BATTLE_STATE2) {
        free(BATTLE_STATE2);
        fmem.battle_state2 = NULL;
    }
}

void battle_switch_in_clear_new() {
    for (int i = 0; i < 4; i++)
        TRAINER_AI_STATE2->known_moves[active_battler][i] = 0;
}