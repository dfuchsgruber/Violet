#include "types.h"
#include "romfuncs.h"
#include "oams.h"
#include "callbacks.h"
#include "battle.h"
#include "basestats.h"
#include "mega.h"
#include <stdbool.h>


void trigger_opponents_mega(){
	u8 pokemon_in_battle = *((u8*)0x02023BCC);
	int i = 0;
	while (i < pokemon_in_battle){
		
		if (is_opponent((u8)i)){
			
			//try to trigger the opponents pokemon for mega evolution
			battler* b = &battlers[i];
			u16 target = can_mega_evolve(b);
			if (target != 0xFFFF){
				b->trigger = 1;
			}
		}
		i++;
	}
	*((int*)0x03004ED4) = (int)battle_cb_do_megas;
}

//this is the callback that executes megas
void battle_cb_do_megas (){
	
	//if a execution callback is currently active, skip
	if (is_function_listed_as_callback(cb_mega_anim)){
		return;
	}
	
	//first we check if we have megas left to execute
	u8 pokemon_in_battle = *((u8*)0x02023BCC);
	int i = 0;
	while(i < pokemon_in_battle){
	
		//we execute mega evolution in the same order the pokemon attack
		u8 current_index = *((u8*)(0x02023BDE + i));
		if (current_index < pokemon_in_battle){
			
			//we check if the pokemon can perform a mega evolution
			battler* current_battler = &battlers[current_index];
			
			if (current_battler->trigger){
				
				if (!is_opponent(current_index) && !(get_mega_if_can_mega_evolve(current_battler)->regent )){
					setflag(0x920);
				}
				
				current_battler->trigger = 0;
				
				//Change the species
				
				void* pokemon_offset = get_pokemon_offset_by_index(current_index);
				u16 target = can_mega_evolve(current_battler);
				set_pokemons_attribute (pokemon_offset, 0xB, &target);
				recalculate_stats(pokemon_offset);
				//Now we need to update the battler data
				current_battler->species = target;
				
				int j ;
				for (j=0; j < 5; j++){
					current_battler->stats[i] = (u16)get_pokemons_attribute(pokemon_offset, (u8)(0x3B + j), 0);
				}
				current_battler->current_hp = (u16)get_pokemons_attribute(pokemon_offset,0x39, 0);
				current_battler->max_hp = (u16)get_pokemons_attribute(pokemon_offset,0x3A, 0);
				
				//Ability update, we need ability bit and coolness information
				u32 ability_bit = get_pokemons_attribute(pokemon_offset,0x2E, 0) & 1;
				u32 hidden_bit = (get_pokemons_attribute(pokemon_offset, 0x16, 0) & 0x80) >> 6;
				u8 fields = (u8)(ability_bit | hidden_bit);
				current_battler->ability = get_ability(target, fields);
				
				//Type update
				current_battler->type1 = bstats[target].type1;
				current_battler->type2 = bstats[target].type2;
				
				u8 cb_id = spawn_big_callback(cb_mega_anim, 10);
				big_callback* cb_o = CALLBACK_OBJECT(cb_id);
				 cb_o-> params[1] = current_index;
				return;
			}
		}
		i++;
	}
	//no pokemon was triggered for mega evolution -> writing attack execution at battle callback
	*((u32*)0x03004ED4) = 0x0801554D;
}


void* get_pokemon_offset_by_index(u8 index){

	int base = is_opponent(index) ? 0x0202402C : 0x02024284;
	u16 id = *((u16*)(0x02023BCE + index*2));
	return (void*) base + id*100;
	
}

/** checks if the player can still trigger a mega evolution
**/
bool can_player_trigger_mega(){
	
	if (checkflag (0x920) || !checkflag(0x921)){
		return 0;
	}
	
	int i;
	u8 pokemon_in_battle = *((u8*)0x02023BCC);
	for (i = 0; i < pokemon_in_battle; i++){
		if (battlers[i].trigger && ! is_opponent((u8)i)){
			return 0;
		}
	}
	return 1;
}