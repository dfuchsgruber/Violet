#include "types.h"
#include "battle/state.h"
#include "save.h"
#include "mega.h"
#include "agbmemory.h"
#include "battle/controller.h"
#include "debug.h"

void battle_allocate_new() {
    fmem.mega_state = malloc_and_clear(sizeof(mega_state_t));
}

void battle_free_new() {
    if (fmem.mega_state) {
        battle_alternative_forms_revert(); // It's whack to have it here, but w/e
        free(fmem.mega_state);
        fmem.mega_state = NULL;
    }
}

void battle_intro_draw_pokemon_or_trainer_sprite_draw_second_trainer() {
    if ((battle_flags & BATTLE_TWO_TRAINERS) && active_battler == BATTLE_POSITION_OPPONENT_RIGHT) {
        battle_controller_emit_draw_trainer_picture(0);
        battler_mark_for_controller_execution(active_battler);
    }
    // TODO: Ally battles
}

void battle_intro_try_second_trainer_ball_throw() {
    if (battle_flags & (BATTLE_MULTI | BATTLE_TWO_TRAINERS) && 
            battler_get_position(active_battler) == BATTLE_POSITION_OPPONENT_RIGHT) {
        dprintf("Add second ball throw \n");
        battle_controller_emit_intro_trainer_ball_throw(0);
        battler_mark_for_controller_execution(active_battler);
    }
}