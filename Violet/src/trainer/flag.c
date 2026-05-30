#include "types.h"
#include "flags.h"
#include "pokepad/vs_seeker.h"
#include "trainer/trainer.h"

void trainerflag_set(u16 trainer_id) {
    setflag((u16)(FLAG_TRAINER_BASE + trainer_id));
    if (trainers[trainer_id].rematch_flag_idx) {
        // If a trainer is defeated, the rematch flag should be cleared so they don't immediately want to rematch
        vs_seeker_clear_rematch_flag(trainers[trainer_id].rematch_flag_idx);
    }
}