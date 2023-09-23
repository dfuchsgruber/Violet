#include "types.h"
#include "battle/ai.h"
#include "battle/state.h"
#include "battle/controller.h"
#include "prng.h"
#include "debug.h"
#include "constants/battle/battle_actions.h"
#include "battle/ressources.h"
#include "agbmemory.h"
#include "trainer/trainer.h"
#include "battle/attack.h"
#include "constants/trainer_ai_flags.h"
#include "vars.h"
#include "constants/difficulties.h"

enum {
    ACTION_SWITCH = 1, ACTION_ITEM, ACTION_MOVE
};

void battle_ai_choose_action() {
    DEBUG("*** AI ACTION CHOOSING (battler %d) ***\n", active_battler);
    int scores[3] = {0};
    u8 actions[3] = {0};
    size_t num_actions = 0;

    // A move is always a valid action
    actions[0] = ACTION_MOVE;
    scores[0] = 0;
    num_actions++;

    u8 switch_into = battle_ai_should_switch(scores + num_actions);
    if (switch_into != 6) {
        actions[num_actions++] = ACTION_SWITCH;
    }
    u8 item_idx_to_use = battle_ai_should_use_item(scores + num_actions);
    if (item_idx_to_use != 4) {
        actions[num_actions++] = ACTION_ITEM;
    }

    // Normalize scores to [-16, 16]
    for (size_t i = 0; i < num_actions; i++) {
        scores[i] = MIN(16, MAX(-16, scores[i]));
        DEBUG("Score for action %d is %d\n", actions[i], scores[i]);
    }
    // Select an action
    size_t chosen_action = softmax_choice(scores, num_actions, -16, 16, NULL);
    switch (actions[chosen_action]) {
        case ACTION_ITEM: {
            DEBUG("Use item.\n");
            trainer_ai_state2->chosen_item_idxs[active_battler] = item_idx_to_use;
            battle_scripting.battler_idx = active_battler;
            battle_controller_emit_two_values(1, BATTLE_ACTION_USE_ITEM, 0);
            break;
        }
        case ACTION_SWITCH: {
            DEBUG("Switch.\n");
            battle_state->battler_to_switch_into[active_battler] = switch_into;
            battle_scripting.battler_idx = active_battler;
            battle_state->ai_switch_target_chosen &= (u8) int_bitmasks[active_battler];
            battle_controller_emit_two_values(1, BATTLE_ACTION_SWITCH, 0);
            break;
        }
        case ACTION_MOVE: {
            DEBUG("Use move.\n");
            battle_controller_emit_two_values(1, BATTLE_ACTION_USE_MOVE, (u16)(OPPONENT(active_battler) << 8));
            break;
        }
    }
    return;

}

void ai_setup(u16 trainer_idx) {
    DEBUG("AI is setup for trainer %d.\n", trainer_idx);
    ai_thinking_state_t *ai = battle_ressources->ai;
    memset(ai, 0, sizeof(ai_thinking_state_t));
    battle_state2->fleeing_rng_seed = (u32)(rnd16() | (rnd16() << 16));
    u8 move_limitations = battler_check_move_limitations(active_battler, 0, MOVE_LIMITATION_ALL);
    for (int i = 0; i < 4; i++) {
        if (move_limitations & int_bitmasks[i])
            ai->scores[i] = 0;
        else
            ai->scores[i] = 100;
        ai->simulated_rng[i] = (u8)(100 - (rnd16() % 16));
    }
    battle_ressources->ai_scripts_stack->size = 0;
    attacking_battler = active_battler;
    defending_battler = OPPONENT(attacking_battler);
    // Decide an attacking target
    if (battle_flags & BATTLE_DOUBLE && (rnd16() & 1) != 0) {
        defending_battler = PARTNER(defending_battler);
    }
    if (battle_flags & BATTLE_SAFARI) {
        ai->ai_flags = TRAINER_AI_SAFARI_ZONE;
    } else if (battle_flags & BATTLE_ROAMER) {
        ai->ai_flags = TRAINER_AI_FLEE;
    } else if (battle_flags & (BATTLE_TOWER | BATTLE_EREADER)) {
        ai->ai_flags = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE;
    } else if (battle_flags & BATTLE_WILD_SCRIPTED) {
        ai->ai_flags = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS;
    } else if (battle_flags & BATTLE_LEGENDARY) {
        ai->ai_flags = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE;
    } else if (battle_flags & BATTLE_TRAINER) {
        ai->ai_flags = trainers[trainer_idx].ai;
    }
    if (battle_flags & BATTLE_FLEEING_WILD) {
        ai->ai_flags |= TRAINER_AI_CONSIDER_FLEEING;
    }
    if (*var_access(DIFFICULTY) == DIFFICULTY_HARD && !(battle_flags & (BATTLE_TRAINER | BATTLE_LEGENDARY | BATTLE_WILD_SCRIPTED))) {
        ai->ai_flags |= TRAINER_AI_CONSIDER_FLEEING; // Normal wild encounters might flee in hard mode
    }
    DEBUG("AI flags 0x%x, battle flags 0x%x\n", ai->ai_flags, battle_flags);
}