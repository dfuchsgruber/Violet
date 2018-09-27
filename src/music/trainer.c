/* 
 * File:   trainer_encounter.c
 * Author: Domi
 *
 * Created on 9. Juni 2016, 11:49
 */


#include "types.h"
#include "stdbool.h"
#include "trainer/trainer.h"
#include "music.h"
#include "battle/state.h"
#include "flags.h"
#include "constants/vars.h"
#include "constants/songs.h"
#include "constants/trainerclasses.h"
#include "vars.h"

u16 trainer_get_encounter_song(u16 trainer_id) {
    if (trainers[trainer_id].trainerclass == TRAINERCLASS_TEAM_VIOLET) {
        return MUS_VIOLET_ENCOUNTER;
    } else if (trainers[trainer_id].trainerclass == TRAINERCLASS_REVOLUTIONAER) {
        return MUS_REVOLUTION;
    }
    //Get encounter music by field inside trainer and modulo
    return (u16) ((trainers[trainer_id].encounter_and_gender.encounter % 3) + 283);
}

short_pair trainer_music_table [] = {
    {TRAINERCLASS_RIVALE, MUS_RIVAL_BATTLE},
    {TRAINERCLASS_TEAM_VIOLET, MUS_VIOLET_BATTLE},
    {TRAINERCLASS_ARENALEITER, MUS_KAMPF_GEGEN_ARENALEITER_KANTO},
    {TRAINERCLASS_REVOLUTIONAER, MUS_REVOLUTIONARY_BATTLE},
    {0xFFFF, 0xFFFF}
};

u16 battle_get_song() {
    u16 *battle_music = var_access(BATTLE_SONG_OVERRIDE);
    if (*battle_music) {
        u16 forced_mus = *battle_music;
        *battle_music = 0;
        return forced_mus;
    }
    if (battle_flags.trainer_battle) {
        //scan a lo_table
        int i = 0;
        while (trainer_music_table[i].id != 0xFFFF) {
            if (trainer_music_table[i].id == trainers[battle_trainer_id].trainerclass) {
                return trainer_music_table[i].value;
            }
            i++;
        }
        return MUS_KAMPF_GEGEN_RIVALEN_GARY;
    }
    if (battle_flags.flag_C || battle_flags.flag_D) {
        return MUS_KAMPF_GEGEN_WILDES_POKEMON;
    }
    return MUS_KAMPF_GEGEN_WILDES_POKEMON;
}
