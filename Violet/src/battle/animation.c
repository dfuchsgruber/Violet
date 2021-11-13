#include "types.h"
#include "battle/attack.h"
#include "battle/animation.h"
#include "oam.h"
#include "save.h"

void battle_animation_task_load_custom_gfx(u8 self) {
    graphic *g = (graphic*)UNALIGNED_32_GET(battle_animation_arguments);
    oam_load_graphic(g);
    palette *p = (palette*)UNALIGNED_32_GET(battle_animation_arguments + 2);
    battle_animation_load_oam_palette(p);
    battle_animation_register_gfx_tag((u16)(g->tag - 10000));
    // Delay one frame to wait for decompression of gfxs
    battle_animation_delay = 1;
    battle_animation_handler = battle_animation_handler_delay;
    battle_animation_big_callback_delete(self);
}


s16 battler_oam_clone_and_set_blend(u8 which_battler) {
    u8 oam_idx = battle_animation_battler_get_oam_idx(which_battler);
    if (oam_idx != 0xFF) {
        u8 cloned_idx = oam_allocate(OAM_ALLOCATE_AT_START);
        if (cloned_idx != NUM_OAMS) {
            oams[cloned_idx] = oams[oam_idx];
            oams[cloned_idx].final_oam.attr0 = (u16)((oams[cloned_idx].final_oam.attr0 & (u16)~(ATTR0_DSIZE | ATTR0_MODE_SEMI_TRANSPARENT)) | ATTR0_MODE_SEMI_TRANSPARENT);
            oams[cloned_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
            return cloned_idx;
        }
    }
    return -1;
}