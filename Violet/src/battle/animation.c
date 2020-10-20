#include "types.h"
#include "battle/attack.h"


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