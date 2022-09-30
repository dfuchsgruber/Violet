#include "types.h"
#include "new_game.h"
#include "bios.h"
#include "save.h"
#include "flags.h"
#include "constants/flags.h"
#include "pokepad/incubator.h"
#include "debug.h"
#include "vars.h"
#include "rtc.h"
#include "agbmemory.h"
#include "data_structures.h"
#include "berry.h"
#include "overworld/misc.h"
#include "version.h"
#include "constants/story_states.h"
#include "constants/time_types.h"
#include "overworld/map_control.h"

static void new_game_initialize_custom_flags() {
    setflag(AMONIA_RIVAL_INSIDE_PLAYER_HOUSE);
    setflag(RUNNING_SHOES);
    setflag(BIBOR_QUEST_NOT_TRIGGERED);
    setflag(SILVANIA_FAUN_AND_MIA);
}

static void new_game_initialize_custom_vars() {
    *var_access(POKEPAD_SHORTCUTS) = 0xFFFF;
    *var_access(VAR_STORY_STATE) = STORY_STATE_NONE;
}

static void new_game_initialize_time() {
    *var_access(TIME_TYPE) = TIME_TYPE_RTC; // TODO: get the rtc working!
}

void new_game_initialize_custom_data() {
    memset(&cmem, 0, sizeof(custom_memory));
    setflag(POKERADAR_POKEMON_SPAWNED);  // set corresponds to a pokemon already spawned
    incubator_clear();
    overworld_misc_intialize();
    berry_trees_initialize_all();
    version_init();
    new_game_initialize_time();
    new_game_initialize_custom_vars();
    new_game_initialize_custom_flags();
}

void new_game_warp_to_initial_map() {
    *var_access(VAR_FILTER_COLOR) = 0x71ef;
    setflag(FLAG_FILTER_COLOR_ACTIVE);
    warp_setup(4, 1, 0xFF, 8, 5);
    warp_do();
}