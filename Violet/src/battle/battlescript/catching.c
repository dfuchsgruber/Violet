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

u8 bsc_cmd_xEF_determine_target_to_catch() {
    u8 target = battler_get_by_position(BATTLE_POSITION_OPPONENT_LEFT);
    if (battle_flags & BATTLE_DOUBLE) {
        if (battlers[battler_get_by_position(BATTLE_POSITION_OPPONENT_RIGHT)].current_hp > 0) {
            target = battler_get_by_position(BATTLE_POSITION_OPPONENT_RIGHT);
        }
    }
    dprintf("Target to catch is battler %d\n", target);
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
    //dprintf("Bsc before caught %x\n", bsc_offset);
    u16 species = (u16)pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
    dprintf("Bsc pokemon caught with battler %d, species %d\n", bsc_cmd_xEF_determine_target_to_catch(), species);
    u16 dex_id = pokedex_get_id(species);
    pid_t pid = {.value = (u32)pokemon_get_attribute(p, ATTRIBUTE_PID, 0)};
    bool caught = pokedex_operator(species,POKEDEX_GET | POKEDEX_CAUGHT, true);
    if(caught){
      u8 *bsc_off_loc = &((bsc_offset)[1]);
      int target = UNALIGNED_32_GET(bsc_off_loc);
      bsc_offset = (u8*)target;
    }else{
        //catch pokemon
        pokedex_set_caught_and_load_pid(dex_id, 0b11, pid);
        if(checkflag(CAUGHT_POKEDEX_DISABLE)){
            u8 *bsc_off_loc = &((bsc_offset)[1]);
            int target = UNALIGNED_32_GET(bsc_off_loc);
            bsc_offset = (u8*)target;
        }else{
            bsc_offset = (u8*)((int)(bsc_offset) + 5);   
        }
    }
    //dprintf("Bsc after caught %x\n", bsc_offset);
}
