#include "attack.h"
#include "battle/ai.h"
#include "battle/battler.h"
#include "battle/controller.h"
#include "battle/link.h"
#include "battle/state.h"
#include "constants/attack_affects_whom_flags.h"
#include "constants/battle/battle_actions.h"
#include "debug.h"
#include "mega.h"
#include "oam.h"
#include "overworld/pokemon_party_menu.h"
#include "pokemon/cry.h"
#include "pokemon/sprites.h"
#include "save.h"
#include "trainer/backsprite.h"
#include "trainer/trainer.h"
#include "types.h"

void battle_controller_player_handle_draw_trainer_picture() {
    s16 x;
    if (battle_is_multi_double() || battle_is_tag()) {
        if ((battler_get_position(active_battler) & 2) == 2) { // Left flank
            x = 90;
        } else {
            x = 32;
        }
    } else {
        x = 80;
    }

    u32 sprite_idx;
    if (battle_flags & BATTLE_LINK) {
        u16 version = link_players[multiplayer_get_idx()].version;
        if (version == 1 || version == 2 || version == 3) { // RSE sprites
            sprite_idx = (u32)(link_players[multiplayer_get_idx()].gender + 2);
        } else { // FRLG sprites
            sprite_idx = link_players[multiplayer_get_idx()].gender;
        }
    } else {
        sprite_idx = save2->player_is_female ? 1 : 0;
    }
    battle_trainer_load_backsprite_palette((u8)sprite_idx, active_battler);
    trainer_gfx_initialize_gp_oam_template((u8)sprite_idx, battler_get_position(active_battler));
    u8 oam_idx = oam_new_forward_search(&gp_oam_template, x,
                                        (s16)((8 - trainer_backsprite_coordinates[sprite_idx].y_offset) * 4 + 80),
                                        battler_oam_get_relative_priority(active_battler));
    battler_oams[active_battler] = oam_idx;
    oams[oam_idx].final_oam.attr2 = (u16)((oams[oam_idx].final_oam.attr2 & 0xFFF) | (active_battler << 12));
    oams[oam_idx].x2 = 240;
    oams[oam_idx].private[0] = 0xFFFE;
    oams[oam_idx].callback = oam_trainer_sprite_callback;
    battle_controllers[active_battler] = battle_controller_player_wait_for_oam;
}
