#include "types.h"
#include "romfuncs.h"
#include "oam.h"
#include "callbacks.h"
#include "battle/battler.h"
#include "pokemon/basestat.h"
#include "pokemon/virtual.h"
#include "mega.h"
#include <stdbool.h>
#include "constants/flags.h"
#include "constants/pokemon_attributes.h"

void trigger_opponents_mega() {
    u8 pokemon_in_battle = *battler_cnt;
    int i = 0;
    while (i < pokemon_in_battle) {

        if (is_opponent((u8) i)) {

            //try to trigger the opponents pokemon for mega evolution
            battler* b = &battlers[i];
            u16 target = can_mega_evolve(b);
            if (target != 0xFFFF) {
                b->trigger = 1;
            }
        }
        i++;
    }
    *((void(**)()) 0x03004ED4) = battle_cb_do_megas;
}

//this is the callback that executes megas

void battle_cb_do_megas() {

    //if a execution callback is currently active, skip
    if (is_function_listed_as_callback(cb_mega_anim)) {
        return;
    }

    //first we check if we have megas left to execute
    u8 pokemon_in_battle = *battler_cnt;
    int i = 0;
    while (i < pokemon_in_battle) {

        //we execute mega evolution in the same order the pokemon attack
        u8 current_index = battler_attacking_order[i];
        if (current_index < pokemon_in_battle) {

            //we check if the pokemon can perform a mega evolution
            battler* current_battler = &battlers[current_index];

            if (current_battler->trigger) {

                if (!is_opponent(current_index) && !(get_mega_if_can_mega_evolve(current_battler)->regent)) {
                    setflag(MEGA_EVOLUTION_PERFORMED);
                }

                current_battler->trigger = 0;
                u8 slot = current_index;
                *((u8*)0x020370D0) = slot;

                //Change the species

                void* pokemon_offset = get_pokemon_offset_by_index(current_index);
                
                u16 target = can_mega_evolve(current_battler);
                set_pokemons_attribute(pokemon_offset, 0xB, &target);
                recalculate_stats(pokemon_offset);
                //Now we need to update the battler data
                current_battler->species = target;

                int j;
                for (j = 0; j < 5; j++) {
                    current_battler->stats[i] = (u16) get_pokemons_attribute(pokemon_offset, (u8) (ATTRIBUTE_ATK + j), 0);
                }
                current_battler->current_hp = (u16) get_pokemons_attribute(pokemon_offset, 0x39, 0);
                current_battler->max_hp = (u16) get_pokemons_attribute(pokemon_offset, 0x3A, 0);

                
                current_battler->ability = get_pokemons_ability(pokemon_offset);

                //Type update
                current_battler->type1 = basestats[target].type1;
                current_battler->type2 = basestats[target].type2;

                u8 cb_id = spawn_big_callback(cb_mega_anim, 10);
                big_callbacks[cb_id].params[1] = slot;
                return;
            }
        }
        i++;
    }
    //no pokemon was triggered for mega evolution -> writing attack execution at battle callback
    *((void(**)()) 0x03004ED4) = (void(*)()) 0x0801554D;
}

void* get_pokemon_offset_by_index(u8 index) {

	if(is_opponent(index))
		return &opponent_pokemon[index];
	else
		return &player_pokemon[index];


}

/** checks if the player can still trigger a mega evolution
 **/
bool can_player_trigger_mega() {

    if (checkflag(MEGA_EVOLUTION_PERFORMED) || !checkflag(PLAYER_ABLE_TO_MEGA_EVOLVE)) {
        return 0;
    }

    int i;
    u8 pokemon_in_battle = *battler_cnt;
    for (i = 0; i < pokemon_in_battle; i++) {
        if (battlers[i].trigger && !is_opponent((u8) i)) {
            return 0;
        }
    }
    return 1;
}
