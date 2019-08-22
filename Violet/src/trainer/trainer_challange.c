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

void special_player_facing() {
    s16 coordinates [2];
    player_get_coordinates(&coordinates[0], &coordinates[1]);
    u8 pers_id = (u8) (*var_access(LASTTALKED)); //Get LASTTALKED
    u8 npc_id;
    if (!npc_get_id_by_overworld_id(pers_id, save1->map, save1->bank, &npc_id)) {
        s16 npc_x = npcs[npc_id].dest_x;
        s16 npc_y = npcs[npc_id].dest_y;
        if (coordinates[0] < npc_x) {
            //player has to face right
            fmem.npc_facing_movements[0] = LOOK_RIGHT;
        } else if (coordinates[0] > npc_x) {
            //player has to face left
            fmem.npc_facing_movements[0] = LOOK_LEFT;
        } else if (coordinates[1] < npc_y) {
            //player has to face down
            fmem.npc_facing_movements[0] = LOOK_DOWN;
        } else if (coordinates[1] > npc_y) {
            //player has to face up
            fmem.npc_facing_movements[0] = LOOK_UP;
        }
        fmem.npc_facing_movements[1] = STOP;
    } else {
        fmem.npc_facing_movements[0] = STOP;
    }
    npc_apply_movement(0xFF, save1->map, save1->bank, fmem.npc_facing_movements);
    npc_movement_target_person_idx = 0xFF;
}

bool special_x36_check_loaded_trainerflag() {
    return checktrainerflag(trainer_vars.trainer_id);
}

bool checktrainerflag(u16 trainer_id) {
    if (trainer_will_challange_player(trainer_id)) {
        return checkflag((u16) (trainer_id + 0x500));
    }
    return true;
}

bool trainer_will_challange_player(u16 trainer_id) {
    if (trainers[trainer_id].trainerclass == TRAINERCLASS_REVOLUTIONAER) {
        //check if a revolutionary wants to challange you
        if (checkflag(FRACTION_CHOSEN) && checkflag(REVOLUTION_FRACTION)) {

            return false;
        }
    }
    return true;
}
