#include "types.h"
#include "battle/battler.h"
#include "battle/attack.h"
#include "battle/state.h"
#include "battle/battlescript.h"
#include "attack.h"
#include "debug.h"
#include "oam.h"
#include "callbacks.h"
#include "color.h"
#include "mega.h"
#include "save.h"
#include "pokemon/basestat.h"
#include "pokemon/cry.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/species.h"
#include "constants/attacks.h"
#include "constants/attack_flags.h"
#include "constants/pokemon_attributes.h"
#include "constants/attack_categories.h"
#include "prng.h"
#include "battle/battle_string.h"
#include "battle/attack.h"
#include "constants/battle/battle_handicaps.h"
#include "constants/battle/battle_statuses.h"
#include "constants/pokemon_types.h"

extern u8 bsc_wandlungskunst[];
extern u8 bsc_stance_change_to_attack[];
extern u8 bsc_stance_change_to_defense[];
extern u8 bsc_ap_sparer[];
extern u8 battlescript_handicap_floating_rocks_apply[];

void stance_change_change_species(u8 target, u16 species){
    void *pokemon = (battler_is_opponent(target) ? opponent_pokemon : player_pokemon) + battler_idx_to_party_idx(target);
    pokemon_set_attribute(pokemon, ATTRIBUTE_SPECIES, &species);
    pokemon_calculate_stats(pokemon);

    //Update the battler slot
    battlers[target].species = species;
    int j;
    for(j = 0; j < 5; j++){
        battlers[target].stats[j] =
                (u16) pokemon_get_attribute(pokemon, (u8)(j + ATTRIBUTE_ATK), 0);
    }
    battlers[target].current_hp = (u16) pokemon_get_attribute(pokemon,
            ATTRIBUTE_CURRENT_HP, 0);
    battlers[target].max_hp = (u16) pokemon_get_attribute(pokemon,
             ATTRIBUTE_TOTAL_HP, 0);
    battlers[target].ability = pokemon_get_ability(pokemon);
    battlers[target].type1 = basestats[species].type1;
    battlers[target].type1 = basestats[species].type2;


}

void attack_init_trigger_abilities(){
    BATTLE_STATE2->status_custom[defending_battler] &= (u32)(~CUSTOM_STATUS_FLOATING_ROCKS);
    if (fmem.battle_handicaps & int_bitmasks[BATTLE_HANDICAP_FLOATING_ROCKS] && 
        (battlers[defending_battler].type1 == TYPE_GESTEIN || battlers[defending_battler].type2 == TYPE_GESTEIN)
        && battler_is_opponent(attacking_battler) != battler_is_opponent(defending_battler) && attacks[active_attack].base_power != 0) {
            battle_animation_user = defending_battler;
            battle_animation_target = defending_battler;
            battle_scripting.battler_idx = defending_battler;
            battlescript_callstack_push_next_command();
            BATTLE_STATE2->status_custom[defending_battler] |= CUSTOM_STATUS_FLOATING_ROCKS;
            bsc_offset = battlescript_handicap_floating_rocks_apply;
    }
    battler *attacker = &battlers[attacking_battler];
    switch(attacker->ability){
        case WANDLUNGSK:{
            // dprintf("Lauched ability 'Wandlungsk.'");
            u8 attack_type = attacks[active_attack].type;
            if(attacker->type1 != attack_type || attacker->type2 != attack_type){
                attacker->type1 = attack_type;
                attacker->type2 = attack_type;
                BSC_BUFFER_TYPE(bsc_string_buffer0, attack_type);
                battlescript_callstack_push_next_command();
                bsc_offset = bsc_wandlungskunst;
            }
                
            break;
        }
        case TAKTIKWECHS:{
            if(attacker->species == POKEMON_DURENGARD && 
                    (attacks[active_attack].category == CATEGORY_PHYSICAL || 
                    (attacks[active_attack].category == CATEGORY_SPECIAL))){
                stance_change_change_species(attacking_battler,
                        POKEMON_DURENGARDA);
                battlescript_callstack_push_next_command();
                battle_animation_user = attacking_battler;
                battle_animation_target = attacking_battler;
                battle_scripting.battler_idx = attacking_battler;
                // dprintf("User index %d, target index %d\n", attacking_battler, attacking_battler);
                bsc_offset = bsc_stance_change_to_attack;
                
            } else if(attacker->species == POKEMON_DURENGARDA &&
                    active_attack == ATTACK_KOENIGSSCHILD){
                stance_change_change_species(attacking_battler,
                        POKEMON_DURENGARD);
                battlescript_callstack_push_next_command();
                battle_animation_user = attacking_battler;
                battle_animation_target = attacking_battler;
                battle_scripting.battler_idx = attacking_battler;
                dprintf("User index %d, target index %d\n", attacking_battler, 
                        attacking_battler);
                bsc_offset = bsc_stance_change_to_defense;
            }
            break;
            
        }
        case AP_SPARER:{
            if(rnd16() & 3){
                attacker->custom_status |= CUSTOM_STATUS_AP_SPARER;
                battlescript_callstack_push_next_command();
                bsc_offset = bsc_ap_sparer;
                // dprintf("AP sparer triggered for attacker %d\n", 
                //        attacking_battler);
                // bsc_string_buffer0[0] = 0xFD;
                // bsc_string_buffer0[1] = 3;
                // bsc_string_buffer0[3] = 0xFF;
            }
            break;
        }
    }
}