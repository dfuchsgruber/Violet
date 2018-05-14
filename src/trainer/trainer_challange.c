#include "types.h"
#include <stdbool.h>
#include "trainer/trainer.h"
#include "trainer/virtual.h"
#include "save.h"
#include "overworld/npc.h"
#include "data_structures.h"
#include "constants/flags.h"
#include "constants/trainerclasses.h"
#include "flags.h"
#include "vars.h"

void special_prepeare_player_facing() {
    s16 coordinates [2];
    player_get_position(&coordinates[0], &coordinates[1]);
    u8 pers_id = (u8) (*var_access(0x800F)); //Get LASTTALKED
    u8 npc_id;
    if (!npc_get_id_by_overworld_id(pers_id, (*save1)->map, (*save1)->bank, &npc_id)) {
        s16 npc_x = npcs[npc_id].dest_x;
        s16 npc_y = npcs[npc_id].dest_y;
        u8 facing = 0;
        if (coordinates[0] < npc_x) {
            //player has to face right
            facing = 3;
        } else if (coordinates[0] > npc_x) {
            //player has to face left
            facing = 2;
        } else if (coordinates[1] < npc_y) {
            //player has to face down
            facing = 0;
        } else if (coordinates[1] > npc_y) {
            //player has to face up
            facing = 1;
        }
        *var_access(0x800D) = (u16) (0xFE00 | facing); //pseudo movement code : FACING, 0xFE
    } else {
        *var_access(0x800D) = 0xFE;
    }
}

bool special_x36_check_loaded_trainerflag() {
    return checktrainerflag(trainer_vars->trainer_id);
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
