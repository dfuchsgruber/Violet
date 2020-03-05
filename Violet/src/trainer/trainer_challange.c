#include "types.h"
#include <stdbool.h>
#include "trainer/trainer.h"
#include "trainer/virtual.h"
#include "save.h"
#include "overworld/npc.h"
#include "data_structures.h"
#include "constants/flags.h"
#include "constants/trainerclasses.h"
#include "constants/movements.h"
#include "flags.h"
#include "vars.h"
#include "constants/vars.h"
#include "tile/coordinate.h"
#include "pokepad/pokeradar.h"
#include "constants/trainer_battle_types.h"
#include "debug.h"
#include "music.h"
#include "constants/songs.h"
#include "battle/state.h"

void special_player_facing() {
    coordinate_t position;
    player_get_coordinates(&position.x, &position.y);
    u8 person_idx = (u8) (*var_access(LASTTALKED));
    u8 npc_id;
    if (!npc_get_id_by_overworld_id(person_idx, save1->map, save1->bank, &npc_id)) {
        dprintf("Target npc %d\n", npc_id);
        s16 npc_x = npcs[npc_id].dest_x;
        s16 npc_y = npcs[npc_id].dest_y;
        if (ABS(position.x - npc_x) > ABS(position.y - npc_y)) {
            if (position.x < npc_x) {
                fmem.npc_facing_movements[0] = LOOK_RIGHT;
            } else {
                fmem.npc_facing_movements[0] = LOOK_LEFT;
            } 
        } else {
            if (position.y < npc_y) {
                fmem.npc_facing_movements[0] = LOOK_DOWN;
            } else {
                fmem.npc_facing_movements[0] = LOOK_UP;
            }
        }
        fmem.npc_facing_movements[1] = STOP;
    } else {
        fmem.npc_facing_movements[0] = STOP;
    }
    npc_apply_movement(0xFF, save1->map, save1->bank, fmem.npc_facing_movements);
    npc_movement_target_person_idx = 0xFF;
}

bool special_x36_check_loaded_trainerflag() {
    switch (fmem.current_trainer) {
        case 0: return checkflag(trainer_get_flag());
        case 1: return checkflag(trainerB_get_flag());
    }
    return true; // Don't battle
}

u8 *trainer_get_challange_message() {
    u8 *msg = NULL;
    switch (fmem.current_trainer) {
        case 0: msg = trainer_vars.challange_text; break;
        case 1: msg = fmem.trainer_varsB.challange_text; break;
    }
    return str_null_to_empty(msg);
}

static void trainer_variables_initialize_single_trainer(trainer_variables *vars) {
    vars->kind_of_battle = 0;
    vars->trainer_id = 0;
    vars->challange_text = 0;
    vars->defeat_text = 0;
    vars->victory_text = 0;
    vars->unable_to_battle_text = 0;
    vars->script_later = 0;
    vars->script_continue = 0;
    vars->rival_flags = 0;
}

void trainer_variables_initialize() {
    if (fmem.current_trainer == 0)
        trainer_variables_initialize_single_trainer(&trainer_vars);
    else
        trainer_variables_initialize_single_trainer(&fmem.trainer_varsB);
}

int trainerbattle_initialize_by_npc_idx(u8 npc_idx) {
    int num_trainers = 0;
    u8 *script = npc_get_script(npc_idx);
    if (!script) return 0;
    if (npc_trainer_check_flag(script)) return 0;
    u8 distance = npc_sees_player(npcs + npc_idx);
    if (distance) {
        if (TRAINER_BATTLE_TYPE_IS_DOUBLE(script[1])) {
            if (player_party_get_double_battle_viability()) return 0;
            if (fmem.trainers_cnt >= 1) return 0;
            num_trainers = 2;
        } else {
            num_trainers = 1;
        }
        fmem.trainers_npc_idxs[fmem.trainers_cnt] = npc_idx;
        dprintf("Register script %x for trainer %d\n", script, fmem.trainers_cnt);
        fmem.trainers_scripts[fmem.trainers_cnt] = script;
        fmem.trainers_cnt++;
        trainer_npc_move_to_player(npcs + npc_idx, (u8)(distance - 1)); 
    }
    return num_trainers;
}


bool trigger_npc_spotting() {
    if (trainerbattle_not_initializable())
        return false;
    fmem.trainers_cnt = 0;
    fmem.current_trainer = 0;
    for (u8 i = 0; i < 16; i++) {
        if ((npcs[i].flags.active & 1) && (npcs[i].trainer_trigger == 1 || npcs[i].trainer_trigger == 3)) {
            if (pokeradar_npc_alert(i))
                return true;
            int num = trainerbattle_initialize_by_npc_idx(i);
            if (num == 2) break; // The trainer is a double battle, i.e. don't search for other trainers
            if (num == 0) continue;
            if (num == 1 && player_party_get_double_battle_viability()) break; // Don't search for other trainers, player can't handle it
        }
    }
    if (fmem.trainers_cnt == 1) { // Single battle
        fmem.current_trainer = 0;
        trainerbattle_configure_and_initialize_challange_script(fmem.trainers_npc_idxs[fmem.current_trainer],
            fmem.trainers_scripts[fmem.current_trainer]);
        return true;
    } else if (fmem.trainers_cnt == 2) { // Double trainer battle
        fmem.current_trainer = 0;
        trainerbattle_configure_and_initialize_challange_script(fmem.trainers_npc_idxs[fmem.current_trainer],
            fmem.trainers_scripts[fmem.current_trainer]);
        // Only configure the second trainer, but don't launch a script with it
        fmem.current_trainer = 1;
        trainer_configure_by_overworld_script(fmem.trainers_scripts[fmem.current_trainer] + 1);
        fmem.current_trainer = 0;
        return true;
    }
    return false;
}

u8 trainer_get_current_npc_idx() {
    trainer_npc_idx = fmem.trainers_npc_idxs[fmem.current_trainer];
    *var_access(LASTTALKED) = npcs[trainer_npc_idx].overworld_id;
    return trainer_npc_idx;
}

void trainer_approach_second() {
    dprintf("Trainer approach second %d of %d\n", fmem.current_trainer, fmem.trainers_cnt);
    if (fmem.current_trainer < fmem.trainers_cnt - 1) {
        fmem.current_trainer++;
        npc_update_oam_delay_all(); // Unfreezes npcs
        npc_stop_all_movements_but_one(fmem.trainers_npc_idxs[fmem.current_trainer]);
        *var_access(LASTRESULT) = 1;
    } else {
        *var_access(LASTRESULT) = 0;
    }
}

enum {
    LOAD_BYTE,
    LOAD_HWORD,
    LOAD_WORD,
    CLEAR_BYTE,
    CLEAR_HWORD,
    CLEAR_WORD,
    LOAD_SCRIPT_OFFSET_AND_END,
};

static trainerbattle_configuration trainerbattle_configuration_single_to_trainerB[] = {
    {.dst = &trainer_vars.kind_of_battle, .command = LOAD_BYTE},
    {.dst = &fmem.trainer_varsB.trainer_id, .command = LOAD_HWORD},
    {.dst = &trainer_vars.overworld_target, .command = LOAD_HWORD},
    {.dst = &fmem.trainer_varsB.challange_text, .command = LOAD_WORD},
    {.dst = &fmem.trainer_varsB.defeat_text, .command = LOAD_WORD},
    {.dst = &fmem.trainer_varsB.victory_text, .command = CLEAR_WORD},
    {.dst = &fmem.trainer_varsB.script_continue, .command = LOAD_SCRIPT_OFFSET_AND_END},
};

static trainerbattle_configuration trainerbattle_configuration_two_trainers[] = {
    {.dst = &trainer_vars.kind_of_battle, .command = LOAD_BYTE},
    {.dst = &trainer_vars.trainer_id, .command = LOAD_HWORD},
    {.dst = &fmem.trainer_varsB.trainer_id, .command = LOAD_HWORD},
    {.dst = &trainer_vars.overworld_target, .command = LOAD_HWORD},
    {.dst = &trainer_vars.challange_text, .command = LOAD_WORD},
    {.dst = &trainer_vars.defeat_text, .command = LOAD_WORD},
    {.dst = &fmem.trainer_varsB.defeat_text, .command = LOAD_WORD},
    {.dst = &trainer_vars.victory_text, .command = CLEAR_WORD},
    {.dst = &fmem.trainer_varsB.victory_text, .command = CLEAR_WORD},
    {.dst = &trainer_vars.unable_to_battle_text, .command = CLEAR_WORD},
    {.dst = &trainer_vars.script_later, .command = LOAD_WORD},
    {.dst = &trainer_vars.script_continue, .command = LOAD_SCRIPT_OFFSET_AND_END},

};

void trainer_configuration_print(trainer_variables *v) {
    dprintf("Trainer id %x\n", v->trainer_id);
    dprintf("Ow target %x\n", v->overworld_target);
    dprintf("Padding id %x\n", v->padding);
    dprintf("challange_text id %x\n", v->challange_text);
    dprintf("defeat text %x\n", v->defeat_text);
    dprintf("victory text %x\n", v->victory_text);
    dprintf("unable to battle text %x\n", v->unable_to_battle_text);
    dprintf("scr later %x\n", v->script_later);
    dprintf("scr cont %x\n", v->script_continue);
    dprintf("rival flag %x\n", v->rival_flags);
}

u8 *trainer_configure_by_overworld_script(u8 *ow_script) {
    trainer_variables_initialize();
    u8 kind = ow_script[0];
    switch (kind) {
        case TRAINER_BATTLE_CONTINUE_SCRIPT:
        case TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC:
            trainerbattle_configure(trainerbattle_configuration_single_with_continuation, ow_script);
            trainerbattle_load_target_npc();
            return ow_script_trainerbatte_challange;
        case TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT:
            trainerbattle_configure(trainerbattle_configuration_single_no_intro_text, ow_script);
            trainerbattle_load_target_npc();
            return ow_script_trainerbattle_with_continuation;
        case TRAINER_BATTLE_DOUBLE:
            trainerbattle_configure(trainerbattle_configuration_double, ow_script);
            trainerbattle_load_target_npc();
            return ow_script_trainerbattle_double;
        case TRAINER_BATTLE_REMATCH:
            trainerbattle_configure(trainerbattle_configuration_single, ow_script);
            trainerbattle_load_target_npc();
            trainer_vars.trainer_id = trainer_get_rematch_idx(trainer_vars.trainer_id);
            return ow_script_trainerbattle_rematch;
        case TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE:
        case TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC:
            trainerbattle_configure(trainerbattle_configuration_double_with_continuation, ow_script);
            trainerbattle_load_target_npc();
            return ow_script_trainerbattle_double;
        case TRAINER_BATTLE_REMATCH_DOUBLE:
            trainerbattle_configure(trainerbattle_configuration_double, ow_script);
            trainerbattle_load_target_npc();
            trainer_vars.trainer_id = trainer_get_rematch_idx(trainer_vars.trainer_id);
            return ow_script_trainerbattle_rematch_double;
        case TRAINER_BATTLE_EARLY_RIVAL:
            trainerbattle_configure(trainerbattle_configuration_losable, ow_script);
            trainerbattle_load_target_npc();
            return ow_script_trainerbattle_with_continuation;
        case TRAINER_BATTLE_TWO_TRAINERS:
            fmem.trainers_cnt = 2;
            trainerbattle_configure(trainerbattle_configuration_two_trainers, ow_script);
            trainerbattle_load_target_npc();
            return ow_script_trainerbattle_double;
        case TRAINER_BATTLE_SINGLE:
        default: { // For spotted trainer double battles
            if (fmem.current_trainer == 0) { // Initialize trainerA 
                dprintf("Configure trainerA @%x\n", ow_script);
                trainerbattle_configure(trainerbattle_configuration_single, ow_script);  
                // print_trainer_configuration(&trainer_vars);
                trainerbattle_load_target_npc();
            } else { // Initialize trainerB
                dprintf("Configure trainerB @%x\n", ow_script);
                trainerbattle_configure(trainerbattle_configuration_single_to_trainerB, ow_script);
                *var_access(VAR_SECOND_TRAINER) = fmem.trainer_varsB.trainer_id;
                // print_trainer_configuration(&fmem.trainer_varsB);
            }
            return ow_script_trainerbatte_challange;
        }
    }
    return NULL;
}

void trainer_play_encounter_music() {
    u16 trainer_idx, kind;
    if (fmem.current_trainer == 0) {
        trainer_idx = trainer_vars.trainer_id;
        kind = trainer_vars.kind_of_battle;
    } else {
        trainer_idx = fmem.trainer_varsB.trainer_id;
        kind = fmem.trainer_varsB.kind_of_battle;
    }
    dprintf("Encounter for trainer %d\n", trainer_idx);
    if (kind != TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC && kind != TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC) {
        u16 music;
        switch(trainers[trainer_idx].trainerclass) {
            case TRAINERCLASS_TEAM_VIOLET: 
                music = MUS_VIOLET_ENCOUNTER; break;
            case TRAINERCLASS_REVOLUTIONAER: 
                music = MUS_REVOLUTION; break;
            case TRAINERCLASS_PIRATE: 
                music = MUS_PIRATE; break;
            default:
                music = (u16)((trainers[trainer_idx].encounter_and_gender.encounter % 3) + 283);
        }
        song_play_by_controller(music);
    }
}

u16 trainerB_get_flag() {
    return (u16)(0x500 + fmem.trainer_varsB.trainer_id);
}

void trainer_set_flags() {
    setflag(trainer_get_flag());
    if (battle_flags & BATTLE_TWO_TRAINERS)
        setflag(trainerB_get_flag());
}