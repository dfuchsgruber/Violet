#include "types.h"
#include "attack.h"
#include "debug.h"
#include "save.h"
#include "data_structures.h"
#include "battle/battler.h"
#include "battle/attack.h"
#include "battle/state.h"
#include "battle/battlescript.h"
#include "constants/items.h"
#include "constants/abilities.h"
#include "constants/attack_results.h"
#include "constants/attacks.h"
#include "constants/attack_flags.h"
#include "math.h"
#include "abilities.h"
#include "battle/battle_string.h"
#include "constants/battle/battle_handicaps.h"
#include "constants/pokemon_types.h"
#include "constants/pokemon_stat_names.h"
#include "item/item.h"
#include "constants/item_hold_effects.h"

extern u8 bsc_hagelalarm[];
extern u8 bsc_lernfaehig[];
extern u8 bsc_hochmut[];
extern u8 bsc_lebensraeuber[];
extern u8 bsc_curator[];
extern u8 bsc_extradorn[];
extern u8 bsc_fluffy[];
extern u8 bsc_tintenschuss[];

static u16 curator_relevant_attacks[] = {
    ATTACK_GENESUNG, ATTACK_TAGEDIEB, ATTACK_SYNTHESE, ATTACK_MONDSCHEIN, ATTACK_ERHOLUNG, ATTACK_WUNSCHTRAUM,
    ATTACK_WEICHEI, ATTACK_AROMAKUR, ATTACK_VITALGLOCKE, ATTACK_MILCHGETRAENK
};

bool battle_abilities_attack_done_attacker_new() {
    battler *attacker = battlers + attacking_battler;
    battler *defender = battlers + defending_battler;
    defending_battler_ability = attacker->ability;
    if (attacker->ability == LERNFAEHIG && attacker->current_hp &&
            (attack_result & ATTACK_MISSED) && attacker->stat_changes[6] < 12) {
        attacker->stat_changes[STAT_ACCURACY]++;
        battle_scripting.animation_arguments[0] = 0x18;
        battle_scripting.animation_arguments[1] = 0;
        battle_scripting.battler_idx = attacking_battler; 
        battle_scripting.animation_user = attacking_battler;
        battle_scripting.animation_targets = attacking_battler;
        effect_battler = attacking_battler;
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_lernfaehig;
        return true;
    } else if (attacker->ability == HOCHMUT && !(attack_result & ATTACK_NO_EFFECT_ANY) && 
            attacks[active_attack].base_power &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED
            && !defender->current_hp && attacker->stat_changes[1] < 12){
        attacker->stat_changes[STAT_ATTACK]++; // attack boost
        battle_scripting.animation_arguments[0] = 0xF;
        battle_scripting.animation_arguments[1] = 0;
        battle_scripting.battler_idx = attacking_battler;
        battle_scripting.animation_user = attacking_battler; 
        battle_scripting.animation_targets = attacking_battler;
        effect_battler = attacking_battler;
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_hochmut;
        return true;
    }else if (attacker->ability == LEBENSRAEUBER && !(attack_result & ATTACK_NO_EFFECT_ANY) && 
            attacks[active_attack].base_power && attacker->current_hp <
            attacker->max_hp &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED){
        battle_scripting.battler_idx = attacking_battler;
        battle_scripting.animation_user = attacking_battler;
        battle_scripting.animation_targets = attacking_battler;
        effect_battler = attacking_battler;
        int hp_to_heal = damage_caused >> 2;
        if(hp_to_heal <= 0) hp_to_heal = 1;
        damage_to_apply = -hp_to_heal;
        battlescript_callstack_push_next_command(); 
        bsc_offset = bsc_lebensraeuber;
        return true;
    }else if (attacker->ability == CURATOR && !(attack_result & ATTACK_NO_EFFECT_ANY) && 
            attacker->current_hp < attacker->max_hp && !battler_statuses[attacking_battler].hurt_in_confusion){
        for (size_t i = 0; i < ARRAY_COUNT(curator_relevant_attacks); i++) {
            if (active_attack == curator_relevant_attacks[i]) {
                int hp_to_heal = attacker->max_hp / 8;
                if (hp_to_heal <= 0) hp_to_heal = 1;
                damage_to_apply = -hp_to_heal;
    	        battle_scripting.battler_idx = attacking_battler;
                battle_scripting.animation_user = attacking_battler;
                battle_scripting.animation_targets = attacking_battler;
                effect_battler = attacking_battler;
                battlescript_callstack_push_next_command();
                bsc_offset = bsc_curator;
                return true;
            }
        }
    } else if (attacker->ability == EXTRADORN && !(attack_result & ATTACK_NO_EFFECT_ANY) &&
            defender->current_hp && 
            (attacks[active_attack].flags & MAKES_CONTACT) &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED){
        battle_scripting.battler_idx = defending_battler;
        battle_scripting.animation_user = defending_battler;
        battle_scripting.animation_targets = defending_battler;
        effect_battler = defending_battler;
        damage_to_apply = MAX(1, damage_caused / 5);
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_extradorn;
        return true;
    }
    return false;
}

bool battle_abilities_attack_done_defender_new() {
    battler *attacker = battlers + attacking_battler;
    battler *defender = battlers + defending_battler;
    DEBUG("Defender ability %d\n", defender->ability);
    defending_battler_ability = defender->ability;
    if(defender->ability == FLUFFIG && !(attack_result & ATTACK_NO_EFFECT_ANY) &&
            (attacks[active_attack].flags & MAKES_CONTACT) && !battler_statuses[attacking_battler].hurt_in_confusion && 
            DAMAGE_CAUSED) {
    	if (attacker->stat_changes[3] > 0) {
    		// Trigger fluffy
    		attacker->stat_changes[3] = (u8) MAX(0, attacker->stat_changes[3] - 2);
    	    battle_scripting.animation_arguments[0] = STAT_ANIM_MINUS2(STAT_SPEED);
    	    battle_scripting.animation_arguments[1] = 0;
    	    battle_scripting.battler_idx = attacking_battler;
            battle_scripting.animation_user = attacking_battler;
            battle_scripting.animation_targets = attacking_battler;
            battle_animation_user = attacking_battler;
            battle_animation_target = attacking_battler;
            effect_battler = attacking_battler;
            battlescript_callstack_push_next_command();
            bsc_offset = bsc_fluffy;
            return true;
    	}
    } else if (defender->ability == TINTENSCHUSS && !(attack_result & ATTACK_NO_EFFECT_ANY) &&
            (attacks[active_attack].flags & MAKES_CONTACT) && !battler_statuses[attacking_battler].hurt_in_confusion && 
            DAMAGE_CAUSED && attacker->stat_changes[STAT_ACCURACY] > 0) {
            attacker->stat_changes[STAT_ACCURACY] = (u8) MAX(0, attacker->stat_changes[STAT_ACCURACY] - 2);
            // battle_scripting.battler_idx = attacking_battler;
            // battle_scripting.animation_user = attacking_battler;
            // battle_scripting.animation_targets = defending_battler;
            // battle_animation_user = defending_battler;
            // battle_animation_target = attacking_battler;
            DEBUG("Attacking battler %d, defending battler %d\n", attacking_battler, defending_battler);
            battle_scripting.animation_arguments[0] = STAT_ANIM_MINUS2(STAT_ACCURACY);
            battle_scripting.animation_arguments[1] = 0;
            // effect_battler = attacking_battler;
            battlescript_callstack_push_next_command();
            bsc_offset = bsc_tintenschuss;
            return true;
    }
    return false;
}


