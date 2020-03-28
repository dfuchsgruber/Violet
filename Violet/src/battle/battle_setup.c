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
#include "constants/songs.h"
#include "debug.h"
#include "constants/battle/battle_results.h"




void battle_initialize_trainerbattle() {
    battle_flags = BATTLE_TRAINER;
    super.saved_callback = trainerbattle_continuation;
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


void battle_allocate_new() {
    fmem.mega_state = malloc_and_clear(sizeof(mega_state_t));
    fmem.trainer_ai_state2 = malloc_and_clear(sizeof(trainer_ai_state2_t));
    fmem.battle_state2 = malloc_and_clear(sizeof(battle_state2_t));
}

void ally_battle_restore_party() {
    if (battle_flags & BATTLE_ALLY) {
        dprintf("Restoring player party after ally battle...\n");
        pokemon *party = malloc_and_clear(sizeof(pokemon) * 3);
        memcpy(party, player_pokemon, sizeof(pokemon) * 3);
        player_restore_party();
        // Update the pokemon that parttook in the battle
        for (int i = 0; i < 3; i++) {
            if (cmem.ally_battle_selected_party_idxs[i]) {
                memcpy(player_pokemon + cmem.ally_battle_selected_party_idxs[i] - 1, party + i , sizeof(pokemon));
            }
        }
        free(party);
        player_pokemon_compact();
        player_pokemon_recount_pokemon();
    }
}

void ally_battle_revive_pokemon() {
    if ((battle_flags & BATTLE_ALLY) && battle_result == BATTLE_RESULT_WON) {
        // Check if the player has one viable pokemon
        bool has_viable_pokemon = false;
        for (int i = 0; i < player_pokemon_cnt; i++) {
            if (pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_SPECIES, 0) != 0 &&
                !pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_IS_EGG, 0) &&
                pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_CURRENT_HP, 0) > 0) {
                    has_viable_pokemon = true;
                    break;
                }
        }
        if (!has_viable_pokemon) {
            for (int i = 0; i < player_pokemon_cnt; i++) {
                if (pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_SPECIES, 0) != 0 &&
                    !pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_IS_EGG, 0)) {
                    int hp = 1;
                    pokemon_set_attribute(player_pokemon + i, ATTRIBUTE_CURRENT_HP, &hp);
                    break;
                }
            }
        }
    }
}


void battle_end_actions() {
    dprintf("Do battle end actions...\n");
    battle_alternative_forms_revert();
    ally_battle_restore_party();
    ally_battle_revive_pokemon();
    battle_handicap_clear();
}


void battle_free_new() {
    battle_end_actions();
    if (fmem.mega_state) {
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

void wild_battle_legendary_initialize() {
    overworld_script_halt();
    battle_flags = BATTLE_LEGENDARY | 0x40000; // TODO
    super.saved_callback = battle_continuation_wild_legendary_battle_end;
    u16 song = MUS_KAMPF_GEGEN_WILDES_POKEMON;
    switch (pokemon_get_attribute(opponent_pokemon, ATTRIBUTE_SPECIES, 0)) {
        case POKEMON_REGIROCK:
        case POKEMON_REGICE:
        case POKEMON_REGISTEEL:
            song = MUS_REGI_BATTLE;
            break;
    }
    battle_initialize(0, song);
    save_increment_key(7);
    save_increment_key(8);
}