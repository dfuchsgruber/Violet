#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "text.h"
#include "trainer/virtual.h"
#include "trainer/trainer.h"
#include "save.h"

void battler_get_trainer_name (u8 battler_idx, u8 *dst) {
    if (battler_is_opponent(battler_idx)) {
        // TODO: multiple trainers
        strcpy(dst, trainers[trainer_vars.trainer_id].name);
    } else {
        // TODO: link partners
        strcpy(dst, save2->player_name);
    }
}