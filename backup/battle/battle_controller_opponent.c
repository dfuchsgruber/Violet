#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "pokemon/basestat.h"
#include "battle/attack.h"
#include "math.h"
#include "attack.h"
#include "constants/abilities.h"
#include "constants/pokemon_types.h"
#include "prng.h"
#include "debug.h"
#include "battle/controller.h"
#include "trainer/virtual.h"
#include "trainer/trainer.h"
#include "save.h"
#include "oam.h"
#include "pokemon/sprites.h"
#include "music.h"

static void attack_apply_effectiveness_multiplier_with_abilities(u8 attack_type, u8 defender_ability, u8 defender_type1, u8 defender_type2, 
    u8 *multiplier) {
    u8 old_multiplier = *multiplier;
    attack_apply_effectiveness_multiplier(attack_type, defender_type1, defender_type2, multiplier);
    if (attack_type == TYPE_BODEN && defender_ability == SCHWEBE) *multiplier = 0;
    if (defender_ability == WUNDERWACHE && *multiplier <= old_multiplier) *multiplier = 0;
}

// How well does a mon resist the opponents battlers
static int battle_ai_score_resists_foes(pokemon *p, u8 foe, u8 foe_partner) {
    if (POKEMON_IS_VIABLE(p)) {
        u8 multiplier1 = 8, multiplier2 = 8;
        u16 species = (u16) pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
        u8 ability = pokemon_get_ability(p);
        u8 type1 = basestats[species].type1;
        u8 type2 = basestats[species].type2;
        if (!(battlers_absent & int_bitmasks[foe])) {
            attack_apply_effectiveness_multiplier_with_abilities(battlers[foe].type1, ability, type1, type2, &multiplier1);
            attack_apply_effectiveness_multiplier_with_abilities(battlers[foe].type2, ability, type1, type2, &multiplier1);
        }
        if (!(battlers_absent & int_bitmasks[foe_partner]) && foe_partner != foe) {
            attack_apply_effectiveness_multiplier_with_abilities(battlers[foe_partner].type1, ability, type1, type2, &multiplier2);
            attack_apply_effectiveness_multiplier_with_abilities(battlers[foe_partner].type2, ability, type1, type2, &multiplier2);
        }
        int score1 = 3 - msb_index(multiplier1); // Score in [-4, 4]
        int score2 = 3 - msb_index(multiplier2); // Score in [-4, 4]
        return (score1 + score2) * 32; // Final score in [-256, 256]
    }
    return 0;
}

// Checks how well a pokemon attacks opponent battlers. Considers only it's best move.
static int battle_ai_score_attacks_foes(pokemon *p, u8 foe, u8 foe_partner) {
    if (POKEMON_IS_VIABLE(p)) {
        int best_score = 4;
        // Check all moves
        for (int i = 0; i < 4; i++) {
            u8 multiplier1 = 4, multiplier2 = 4;
            int attack = pokemon_get_attribute(p, (u8)(ATTRIBUTE_ATTACK1 + i), 0);
            if (attack != 0 && pokemon_get_attribute(p, (u8)(ATTRIBUTE_PP1 + i), 0) > 0 && attacks[attack].base_power) {
                if (!(battlers_absent & int_bitmasks[foe])) {
                    attack_apply_effectiveness_multiplier_with_abilities(attacks[attack].type, battlers[foe].type1, battlers[foe].type2, 
                        battlers[foe].ability, &multiplier1);
                }
                if (!(battlers_absent & int_bitmasks[foe_partner]) && foe_partner != foe) {
                    attack_apply_effectiveness_multiplier_with_abilities(attacks[attack].type, battlers[foe_partner].type1, 
                        battlers[foe_partner].type2, battlers[foe_partner].ability, &multiplier2);
                }
                int score1 = msb_index(multiplier1) - 2; // Score in [-2, 2]
                int score2 = msb_index(multiplier2) - 2; // Score in [-2, 2]
                best_score = MAX(score1 + score2, best_score);
            }

        }
        return 64 * best_score; // Final score in range [-256, 256]
    }
    return 0;
}

u8 battle_ai_get_pokemon_to_switch_into() {
    if (battle_state->battler_to_switch_into[active_battler] != 6) {
        // A pokemon to switch into was already selected
        return battle_state->battler_to_switch_into[active_battler];
    }
    u8 first = 0, last = 0, partner = 0, foe = 0, foe_partner = 0;
    battler_get_partner_and_foes(active_battler, &partner, &foe, &foe_partner);
    pokemon *party = battler_load_party_range(active_battler, &first, &last);
    int scores[6] = {0};
    for (u8 i = first; i < last; i++) {
        if (POKEMON_IS_VIABLE(party + i) && battler_party_idxs[active_battler] != i && battler_party_idxs[partner] != i) {
            scores[i] += battle_ai_score_resists_foes(party + i, foe, foe_partner);
            scores[i] += battle_ai_score_attacks_foes(party + i, foe, foe_partner);
            dprintf("Switching target %d for battler %d has a score of %d\n", i, active_battler, scores[i]);
        }
    }
    int best_score = INT_MIN;
    u8 target = 6;
    for (u8 i = first; i < last; i++) {
        dprintf("Checking score for %d %d\n", i, POKEMON_IS_VIABLE(party + i));
        if (POKEMON_IS_VIABLE(party + i) && battler_party_idxs[active_battler] != i && battler_party_idxs[partner] != i) {
            if ((scores[i] > best_score) || (scores[i] == best_score && (rnd16() & 1) > 0)) {
                best_score = scores[i];
                target = i;
            }
        }
    }
    dprintf("Ai switches into target %d from battler %d, partner %d\n", target, active_battler, partner);
    return target;
}


void battle_controller_opponent_handle_choose_pokemon() {
    u8 target_idx;
    if (battle_state->battler_to_switch_into[battler_get_position(active_battler) >> 1] == 6) {
        target_idx = battle_ai_get_pokemon_to_switch_into();
        if (target_idx == 6)
            dprintf("No pokemon to switch into for battler %d\n", active_battler);
    } else {
        target_idx = battle_state->battler_to_switch_into[battler_get_position(active_battler) >> 1];
        battle_state->battler_to_switch_into[battler_get_position(active_battler) >> 1] = 6;
    }
    battle_state->battler_to_switch_into[active_battler] = target_idx;
    battle_controller_opponent_emit_chosen_pokemon(1, target_idx, NULL);
    battle_controller_opponent_execution_finished();
}

u8 battle_controller_opponent_get_trainer_pic() {
    // Cut secret base, e-reader, trainer tower, duel tower trainers...
    u16 trainer_idx;
    if (battle_flags & BATTLE_TWO_TRAINERS)
        trainer_idx = active_battler == 1 ? trainer_vars.trainer_id : fmem.trainer_varsB.trainer_id;
    else
        trainer_idx = trainer_vars.trainer_id;
    dprintf("Get trainer idx for battler %d: %d\n", active_battler, trainer_idx);
    return trainers[trainer_idx].sprite;
}

u8 battle_controller_opponent_create_trainer_pic_oam(u8 relative_prio, s16 y) {
    s16 x;
    if (battle_has_two_opponents())
        x = battler_get_position(active_battler) & 2 ? 152 : 200;
    else 
        x = 176;
    dprintf("y is %d\n", y);
    return oam_new_forward_search(&gp_oam_template, x, y, relative_prio);
}

/**
void battle_controller_opponent_handle_draw_trainer_picture() {
    u8 sprite = battle_controller_opponent_get_trainer_pic();
    s16 x;
    if (battle_has_two_opponents())
        x = battler_get_position(active_battler) & 2 ? 152 : 200;
    else
        x = 176;
    trainer_gfx_load(sprite, active_battler);
    trainer_gfx_initialize_gp_oam_template(sprite, battler_get_position(active_battler));
    s16 y = (s16)((8 - trainer_sprite_coordinates[sprite].y_offset) * 4 + 40);
    u8 oam_idx = oam_new_forward_search(&gp_oam_template, x, y, battler_oam_get_relative_priority(active_battler));
    battler_oams[active_battler] = oam_idx;
    oams[oam_idx].x2 = -240;
    oams[oam_idx].private[0] = 2;
    oams[oam_idx].final_oam.attr

}
**/


void sub_08035b30() {
    // I have no clue what this function does, it is changed in pokeemerald drastically, so we do these changes as well...
    bool healthboxes_done = false, wait_for_both_healthboxes;
    if (!battle_is_double() || (battle_is_double() && (battle_flags & BATTLE_MULTI)) || (battle_flags & BATTLE_TWO_TRAINERS)) {
        if (oams[battle_healthbox_oams[active_battler]].callback == oam_null_callback) healthboxes_done = true;
        wait_for_both_healthboxes = false;
    } else {
        if (oams[battle_healthbox_oams[active_battler]].callback == oam_null_callback &&
        oams[battle_healthbox_oams[PARTNER(active_battler)]].callback == oam_null_callback) healthboxes_done = true;
        wait_for_both_healthboxes = true;
    }
    /** There is no pendant for this in firered ??
    gUnknown_020244D8 = &gBattleSpritesDataPtr->healthBoxesData[gActiveBattler];
    gUnknown_020244DC = &gBattleSpritesDataPtr->healthBoxesData[gActiveBattler ^ BIT_FLANK]; **/
    if (healthboxes_done) {
        if (wait_for_both_healthboxes) {
            if (wait_for_both_healthboxes && battle_sprite_data->healthbox_info[active_battler].field_1_x1 && 
                battle_sprite_data->healthbox_info[PARTNER(active_battler)].field_1_x1) { // Wait for field_1_x1 of both boxes
                battle_sprite_data->healthbox_info[active_battler].flag_x80 = 0;
                battle_sprite_data->healthbox_info[active_battler].field_1_x1 = 0;
                battle_sprite_data->healthbox_info[PARTNER(active_battler)].flag_x80 = 0;
                battle_sprite_data->healthbox_info[PARTNER(active_battler)].field_1_x1 = 0;
                oam_free_vram_by_tag(0x27F9);
                oam_palette_free(0x27F9);
            } else {
                return;
            }
        } else if (battle_sprite_data->healthbox_info[active_battler].field_1_x1) { // Wait for field_1_x1 of one box
            // If for one box is waited and the current battler is the RIGHT side of the opponent, we free only if the other
            // opponent box has finished?
            if (battler_get_position(active_battler) == BATTLE_POSITION_OPPONENT_RIGHT) {
                if (battle_sprite_data->healthbox_info[PARTNER(active_battler)].flag_x80 == 0 &&
                        battle_sprite_data->healthbox_info[PARTNER(active_battler)].field_1_x1 == 0) {
                    oam_free_vram_by_tag(0x27F9);
                    oam_palette_free(0x27F9);
                    volume_set(mplay_info_background_music, 0xFFFF, 256);
                } else {
                    return;
                }
            }
            battle_sprite_data->healthbox_info[active_battler].flag_x80 = 0;
            battle_sprite_data->healthbox_info[active_battler].field_1_x1 = 0;
        } else { // Wait for one box, but field_1_x1 is not finished ?
            return;
        }
        battle_sprite_data->healthbox_info[active_battler].field_9 = 3; // Delay for battle controller execution, why 3 frames tho?
        battle_controllers[active_battler] = sub_08035ae8; // Delays until field9 of the healthbox has reached zero
    }
}