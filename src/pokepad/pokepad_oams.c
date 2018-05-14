#include "types.h"
#include "stdbool.h"
#include "oam.h"
#include "pokepad/gui.h"

//static resources
extern const unsigned short gfx_wondertrade_badgesTiles[];
extern const unsigned short gfx_pokepad_arrowTiles[];
extern const unsigned short gfx_pokepad_lTiles[];
extern const unsigned short gfx_pokepad_rTiles[];



graphic graphic_pokepad_arrow = {
    (void*) gfx_pokepad_arrowTiles,
    0x80,
    0xA001
};

graphic graphic_pokepad_l = {
    (void*) gfx_pokepad_lTiles,
    0x40,
    0xA002
};

graphic graphic_pokepad_r = {
    (void*) gfx_pokepad_rTiles,
    0x40,
    0xA003
};


sprite sprite_pokepad_lr = {
    0x4000, 0, 0, 0
};

sprite sprite_pokepad_arrow = {
    0, 0x4000, 0, 0
};


oam_template oam_template_pokepad_arrow = {
    0xA001, 0xA001,
    &sprite_pokepad_arrow,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    OAM_ROTSCALE_ANIM_TABLE_NULL,
    pokepad_oam_arrow_anim
};

oam_template oam_template_pokepad_l = {
    0xA002, 0xA002,
    &sprite_pokepad_lr,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    OAM_ROTSCALE_ANIM_TABLE_NULL,
    oam_null_callback
};

oam_template oam_template_pokepad_r = {
    0xA003, 0xA002,
    &sprite_pokepad_lr,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    OAM_ROTSCALE_ANIM_TABLE_NULL,
    oam_null_callback
};

void pokepad_oam_arrow_anim(oam_object *self) {
    if (++self->private[2] != 4)
        return;
    self->private[2] = 0;
    if (!self->private[0]) {
        //count up to 4
        self->private[1]++;
        self->x2++;
        if (self->private[1] == 2)
            self->private[0] = 1;
    } else {
        //count down to -4
        self->private[1]--;
        self->x2--;
        if (self->private[1] == 0xFFFE)
            self->private[0] = 0;
    }
}
