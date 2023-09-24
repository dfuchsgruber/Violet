#include "types.h"
#include "battle/battlescript.h"
#include "pokemon/virtual.h"
#include "pokepad/pokedex/operator.h"
#include "constants/pokemon_attributes.h"
#include "constants/flags.h"
#include "flags.h"
#include "debug.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "battle/attack.h"
#include "battle/controller.h"
#include "battle/communication.h"
#include "item/pokeball.h"
#include "bios.h"
#include "constants/pokemon_types.h"
#include "pokemon/basestat.h"
#include "prng.h"
#include "constants/map_types.h"
#include "dns.h"

u8 bsc_cmd_xEF_determine_target_to_catch() {
    u8 target = battler_get_by_position(BATTLE_POSITION_OPPONENT_LEFT);
    if (battle_flags & BATTLE_DOUBLE) {
        if (battlers[battler_get_by_position(BATTLE_POSITION_OPPONENT_RIGHT)].current_hp > 0) {
            target = battler_get_by_position(BATTLE_POSITION_OPPONENT_RIGHT);
        }
    }
    return target;
}

pokemon *battle_get_catch_target_pokemon() {
    return opponent_pokemon + battler_idx_to_party_idx(bsc_cmd_xEF_determine_target_to_catch());
}

bool bsc_cmd_x23_should_play_victory_music() {
    if (battle_flags & BATTLE_TRAINER) 
        return false;
    if (battle_state->victory_song_idx != 0) 
        return false;
    int total_hp = 0;
    for (int i = 0; i < player_pokemon_recount_pokemon(); i++) {
        total_hp += pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_CURRENT_HP, 0);
    }
    if (total_hp == 0) return false; // Player has no viable mons and thus lost!
    // Check if there are any other non-trainer mons to battle
    total_hp = 0;
    for (int i = 0; i < 6; i++) {
        total_hp += pokemon_get_attribute(opponent_pokemon + i, ATTRIBUTE_CURRENT_HP, 0);
    }
    if (total_hp > 0) return false;
    return true;
}
 
void battle_handle_successful_ball_throw() {
    battle_sprite_data->animation_info->ball_throw_state = 4; // success
    battle_animation_active = true;
    battle_animation_special(active_battler, active_battler, bsc_cmd_xEF_determine_target_to_catch(), 3);
    battle_controllers[active_battler] = battle_controller_wait_for_animation;
}

void battle_handle_ball_throw() {
    battle_sprite_data->animation_info->ball_throw_state = battle_general_buffers0[active_battler][1];
    battle_animation_active = true;
    battle_animation_special(active_battler, active_battler, bsc_cmd_xEF_determine_target_to_catch(), 3);
    battle_controllers[active_battler] = battle_controller_wait_for_animation;
}


void bsc_pokemon_caught(){
    pokemon *p = opponent_pokemon + battler_idx_to_party_idx(bsc_cmd_xEF_determine_target_to_catch());
    //DEBUG("Bsc before caught %x\n", bsc_offset);
    u16 species = (u16)pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
    DEBUG("Bsc pokemon caught with battler %d, species %d\n", bsc_cmd_xEF_determine_target_to_catch(), species);
    u16 dex_id = pokedex_get_id(species);
    pid_t pid = {.value = (u32)pokemon_get_attribute(p, ATTRIBUTE_PID, 0)};
    bool caught = pokedex_operator(species,POKEDEX_GET | POKEDEX_CAUGHT, true);
    if(caught){
      const u8 *bsc_off_loc = &((bsc_offset)[1]);
      int target = UNALIGNED_32_GET(bsc_off_loc);
      bsc_offset = (const u8*)target;
    }else{
        //catch pokemon
        pokedex_set_caught_and_load_pid(dex_id, 0b11, pid);
        if(checkflag(FLAG_POKEDEX_DISABLE_AFTER_CATCHING) || (!checkflag(POKEDEX))){
            const u8 *bsc_off_loc = &((bsc_offset)[1]);
            int target = UNALIGNED_32_GET(bsc_off_loc);
            bsc_offset = (const u8*)target;
        }else{
            bsc_offset = (const u8*)((int)(bsc_offset) + 5);   
        }
    }
    //DEBUG("Bsc after caught %x\n", bsc_offset);
}


extern const u8 bsc_trainer_blocks_catch_attempt[];
extern const u8 bsc_ball_throw_success[];
extern const u8 bsc_ball_throw_no_success[];

static void bsc_ballthrow_success_set_pokemon_attribues(u8 battler_idx) {
    pokemon *p = opponent_pokemon + battler_idx_to_party_idx(battler_idx);
    u8 ball_idx = item_idx_to_pokeball_idx(bsc_last_used_item);
    pokemon_set_attribute(p, ATTRIBUTE_CATCH_INFO, &ball_idx);
    switch (ball_idx) {
        case BALL_LOTUS: {
                if (rnd16() % 1 == 0)
                    pokemon_set_hidden_ability(&p->box);
            break;
        }
        case BALL_HP:
            pokemon_set_potential_ev(p, STAT_HP, 48); break;
        case BALL_ATTACK:
            pokemon_set_potential_ev(p, STAT_ATTACK, 48); break;
        case BALL_DEFENSE:
            pokemon_set_potential_ev(p, STAT_DEFENSE, 48); break;
        case BALL_SPEED:
            pokemon_set_potential_ev(p, STAT_SPEED, 48); break;
        case BALL_SPECIAL_ATTACK:
            pokemon_set_potential_ev(p, STAT_SPECIAL_ATTACK, 48); break;
        case BALL_SPECIAL_DEFENSE:
            pokemon_set_potential_ev(p, STAT_SPECIAL_DEFENSE, 48); break;
    }
}

void bsc_command_xEF_handleballthrow(void) {
    u8 ball_multiplier = 0;

    if (!battler_marked_for_controller_execution) {
        active_battler = attacking_battler;
        defending_battler = OPPONENT(attacking_battler);
        // Omit Ghost doging, old man tutorial and pokedude
        if (battle_flags & BATTLE_TRAINER) {
            battle_controller_emit_ball_throw_animation(0, BALL_THROW_ANIMATION_TRAINER_BLOCK);
            battler_mark_for_controller_execution(active_battler);
            bsc_offset = bsc_trainer_blocks_catch_attempt;
        } else {
            u32 odds;
            int catch_rate;

            if (bsc_last_used_item == ITEM_SAFARIBALL)
                catch_rate = battle_state->safari_catch_factor * 1275 / 100;
            else
                catch_rate = basestats[battlers[defending_battler].species].catch_rate;
            u8 ball_idx = item_idx_to_pokeball_idx(bsc_last_used_item);
            switch (ball_idx) {
                default:
                    ball_multiplier = 10; 
                    break;
                case BALL_GREAT:
                    ball_multiplier = 15; 
                    break;
                case BALL_ULTRA:
                    ball_multiplier = 20; 
                    break;
                case BALL_SAFARI:
                    ball_multiplier = 15; 
                    break;
                case BALL_NET:
                    if (battlers[defending_battler].type1 == TYPE_WASSER || battlers[defending_battler].type2 == TYPE_WASSER ||
                        battlers[defending_battler].type1 == TYPE_KAEFER || battlers[defending_battler].type2 == TYPE_KAEFER)
                        ball_multiplier = 30;
                    else
                        ball_multiplier = 10;
                    break;
                case BALL_DIVE:
                    if (map_is_cloud())
                        ball_multiplier = 35;
                    else
                        ball_multiplier = 10;
                    break;
                case BALL_NEST:
                    if (battlers[defending_battler].level < 40)
                        ball_multiplier = (u8)MAX(10, 40 - battlers[defending_battler].level);
                    else
                        ball_multiplier = 10;
                    break;
                case BALL_REPEAT:
                    if (pokedex_operator(battlers[defending_battler].species, POKEDEX_GET | POKEDEX_CAUGHT, true))
                        ball_multiplier = 30;
                    else
                        ball_multiplier = 10;
                    break;
                case BALL_TIMER:
                    ball_multiplier = (u8)MIN(40, battle_results.turns_cnt + 10);
                    break;
                case BALL_QUICK:
                    if (battle_results.turns_cnt == 0)
                        ball_multiplier = 50;
                    else
                        ball_multiplier = 10;
                    break;
                case BALL_DUSK: {
                    if (mapheader_virtual.type == MAP_TYPE_BASEMENT || dns_get_daytime() == DAYTIME_NIGHT)
                        ball_multiplier = 30;
                    else
                        ball_multiplier = 10;
                }
            }
            DEBUG("Ball multiplier of item %d (=ball %d) is %d\n", bsc_last_used_item, ball_idx, ball_multiplier);
            odds = (u32)((catch_rate * ball_multiplier / 10) *
                    (battlers[defending_battler].max_hp * 3 - battlers[defending_battler].current_hp * 2)
                    / (3 * battlers[defending_battler].max_hp));
            if (battlers[defending_battler].status1 & (STATUS1_SLEEPING | STATUS1_FROZEN))
                odds *= 2;
            if (battlers[defending_battler].status1 & (STATUS1_POISONED_ANY | STATUS1_BURNED | STATUS1_PARALYZED))
                odds = (15 * odds) / 10;
            DEBUG("Odds are 0x%x\n", odds);
            if (ball_idx != BALL_SAFARI) {
                if (ball_idx == BALL_MASTER)
                    battle_results.master_ball_used = true;
                else if (battle_results.catch_attempts[0] < 0xFF) // We don't distinguish between balls anymore...
                    battle_results.catch_attempts[0]++;
            }
            u8 shakes;
            if (odds > 254)
                shakes = BALL_THROW_ANIMATION_SUCCESS;
            else {
                if (ball_idx == BALL_MASTER)
                    shakes = BALL_THROW_ANIMATION_SUCCESS;
                else {
                    odds = sqrt32(sqrt32(16711680 / odds));
                    odds = 1048560 / odds;
                    DEBUG("Probability for a single shake is 0x%x\n", odds);
                    for (shakes = 0; shakes < 4 && rnd16() < odds; ++shakes);
                }
            }
            DEBUG("%d shakes!\n", shakes);
            battle_controller_emit_ball_throw_animation(0, shakes);
            battler_mark_for_controller_execution(active_battler);
            if (shakes == BALL_THROW_ANIMATION_SUCCESS) {
                bsc_ballthrow_success_set_pokemon_attribues(defending_battler);
                if (player_pokemon_recount_pokemon() == 6)
                    battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 0;
                else
                    battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 1;
                bsc_offset = bsc_ball_throw_success;
            } else {
                battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = shakes;
                bsc_offset = bsc_ball_throw_no_success;
            }
        }
    }
}