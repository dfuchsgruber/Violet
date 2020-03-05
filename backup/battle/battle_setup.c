#include "types.h"
#include "battle/state.h"
#include "superstate.h"
#include "trainer/virtual.h"
#include "save.h"
#include "overworld/script.h"

void battle_initialize_trainerbattle() {
    battle_flags = BATTLE_TRAINER;
    super.callbacks[2] = trainerbattle_continuation;
    if (fmem.trainers_cnt == 2) {
        battle_flags |= BATTLE_DOUBLE | BATTLE_TWO_TRAINERS;
    }
    // Note: The oak intro part was removed, we don't need it
    trainerbattle_start();
    overworld_script_halt();
}

bool battle_has_two_opponents() {
    return (battle_flags & (BATTLE_TWO_TRAINERS | BATTLE_MULTI)) > 0;
}