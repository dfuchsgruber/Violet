#include "types.h"
#include "overworld/npc.h"
#include "overworld/script.h"
#include "save.h"
#include "debug.h"
#include "constants/map_types.h"
#include "music.h"
#include "constants/songs.h"
#include "callbacks.h"
#include "debug.h"
#include "overworld/sprite.h"
#include "oam.h"
#include "superstate.h"

void player_transition_water_to_land(u8 direction) {
    overworld_script_set_active();
    npc_stop_all_movements_but_players();
    save_set_player_non_surfing();
    // Adjust the player state depending if on a cloud map
    player_state.state &= (u8)(~PLAYER_STATE_SURFING);
    if (map_is_cloud()) {
        player_state.state |= PLAYER_STATE_BIKING;
        playsong1(MUS_CLOUDS, 8);
    } else {
        player_state.state |= PLAYER_STATE_WALKING;
        map_current_play_song_if_not_playing();
    }
    player_state.is_locked = 1;
    u8 callback_idx = big_callback_new(player_transition_water_to_land_callback, 255);
    big_callbacks[callback_idx].params[0] = direction;
    player_transition_water_to_land_callback(callback_idx);
}

void player_transition_water_to_land_callback_update_npc(u8 self) {
    npc *n = npcs + player_state.npc_idx;
    if (npc_animation_finished(n)) {
        u8 picture = OVERWORLD_PLAYER_PICTURE_CONTEXT_WALKING;
        if (map_is_cloud()) {
            npc_player_set_bike_state(2);
            picture = OVERWORLD_PLAYER_PICTURE_CONTEXT_BIKING;
        }
        npc_update_picture(n, picture);
        npc_do_facing_move(n, npc_get_facing_movement_by_direction((u8)(big_callbacks[self].params[0])));
        player_state.is_locked = false;
        overworld_script_set_inactive();
        npc_update_oam_delay_all();
        oam_clear_and_free_vram(oams + npcs[player_state.npc_idx].oam_surf);
        big_callback_delete(self);
        game_context_update();
    }
}

/** Validating the saveblock1 offsets
    dprintf("%d : money\n", (int)save1 - (int)(&(save1->money)));
    dprintf("%d : persons\n", (int)save1 - (int)(&(save1->persons[0])));
    dprintf("%d : mail_words\n", (int)save1 - (int)(save1->mail_words));
    dprintf("%d : daycare\n", (int)save1 - (int)(&(save1->daycare)));
    dprintf("%d : roamer\n", (int)save1 - (int)(&(save1->roamer)));
    dprintf("%d : enigma_effect\n", (int)save1 - (int)(&(save1->enigma_berry_item_effect)));
    dprintf("%d : mini_daycare\n", (int)save1 - (int)(&(save1->mini_daycare)));
    dprintf("%d : sizeof(item_effect_t)\n", sizeof(item_effect_t));
**/