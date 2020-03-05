#include "types.h"
#include "battle/state.h"
#include "superstate.h"
#include "overworld/script.h"
#include "pokemon/virtual.h"
#include "constants/species.h"
#include "constants/species.h"
#include "constants/songs.h"
#include "constants/pokemon_attributes.h"
#include "save.h"
#include "constants/sav_keys.h"

void wild_battle_legendary_initialize() {
    overworld_script_halt();
    battle_flags = BATTLE_LEGENDARY | 0x40000; // TODO
    super.callbacks[2] = battle_continuation_wild_legendary_battle_end;
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