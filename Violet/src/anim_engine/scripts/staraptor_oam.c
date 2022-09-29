#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "io.h"
#include "bios.h"
#include "math.h"
#include "overworld/sprite.h"

extern u16 gfx_anim_staraptor_frontTiles[];
extern u16 gfx_anim_staraptor_backTiles[];

graphic anim_staraptor_front_graphic = {
    gfx_anim_staraptor_frontTiles, 0x400, 0xCD72
};

graphic anim_staraptor_back_graphic = {
    gfx_anim_staraptor_backTiles, 0x400, 0xCD73
};

sprite anim_staraptor_sprite = {
    ATTR0_SHAPE_SQUARE, ATTR1_SIZE_32_32, ATTR2_PRIO(0), 0
};


sprite anim_staraptor_sprite_hiro = {
    ATTR0_SHAPE_VERTICAL, ATTR1_SIZE_16_32, ATTR2_PRIO(0), 0
};



gfx_frame anim_staraptor_wings[] = {
    {0, 16}, {16, 24}, {GFX_ANIM_JUMP, 0} 
};

gfx_frame anim_staraptor_wings_flipped[] = {
    {0, 16 | GFX_ANIM_HFLIP}, {16, 24 | GFX_ANIM_HFLIP}, {GFX_ANIM_JUMP, 0} 
}; 


gfx_frame *anim_staraptor[] = {
    anim_staraptor_wings,
    anim_staraptor_wings_flipped
};

void anim_staraptor_oam_callback(oam_object *self){
    FIXED period = INT_TO_FIXED(32);
    FIXED amplitude = INT_TO_FIXED(3);
    FIXED x = INT_TO_FIXED((self->private[0])++);
    x = FIXED_DIV(x, period);
    FIXED y = FIXED_COS(x);
    y = FIXED_MUL(y, amplitude);
    int y2 = FIXED_TO_INT(y);
    self->y2 = (s16)y2;
    
}

oam_template anim_staraptor_front_template = {
    0xCD72, 0xCD72,
    &anim_staraptor_sprite,
    anim_staraptor,
    NULL,
    oam_rotscale_anim_table_null,
    anim_staraptor_oam_callback
};


oam_template anim_staraptor_back_template = {
    0xCD73, 0xCD72,
    &anim_staraptor_sprite,
    anim_staraptor,
    NULL,
    oam_rotscale_anim_table_null,
    anim_staraptor_oam_callback
};

oam_template anim_staraptor_front_flipped_template = {
    0xCD72, 0xCD72,
    &anim_staraptor_sprite,
    &anim_staraptor[1],
    NULL,
    oam_rotscale_anim_table_null,
    anim_staraptor_oam_callback
};


oam_template anim_staraptor_back_flipped_template = {
    0xCD73, 0xCD72,
    &anim_staraptor_sprite,
    &anim_staraptor[1],
    NULL,
    oam_rotscale_anim_table_null,
    anim_staraptor_oam_callback
};


graphic anim_staraptor_hiro_graphics[] = {
    {gfx_ow_hiro_sit_2Tiles, 0x100, 0}
};

graphic anim_staraptor_hiroine_graphics[] = {
    {gfx_ow_hiroine_sit_2Tiles, 0x100, 0}
};

gfx_frame anim_staraptor_hiro_anim0[] = {
    {0, 0}, {GFX_ANIM_END, 0}  
};

gfx_frame anim_staraptor_hiro_anim1[] = {
    {0, 0 | GFX_ANIM_HFLIP}, {GFX_ANIM_END, 0}  
};

gfx_frame *anim_staraptor_hiro_anim_table[] = {
    anim_staraptor_hiro_anim0,
    anim_staraptor_hiro_anim1
};

oam_template anim_staraptor_hiroine_template_to = {
    0xFFFF, 0xCD73,
    &anim_staraptor_sprite_hiro,
    &anim_staraptor_hiro_anim_table[1],
    anim_staraptor_hiroine_graphics,
    oam_rotscale_anim_table_null,
    anim_staraptor_oam_callback
    
};


oam_template anim_staraptor_hiroine_template_from = {
    0xFFFF, 0xCD73,
    &anim_staraptor_sprite_hiro,
    anim_staraptor_hiro_anim_table,
    anim_staraptor_hiroine_graphics,
    oam_rotscale_anim_table_null,
    anim_staraptor_oam_callback
    
};


oam_template anim_staraptor_hiro_template_to = {
    0xFFFF, 0xCD73,
    &anim_staraptor_sprite_hiro,
    &anim_staraptor_hiro_anim_table[1],
    anim_staraptor_hiro_graphics,
    oam_rotscale_anim_table_null,
    anim_staraptor_oam_callback
    
};


oam_template anim_staraptor_hiro_template_from = {
    0xFFFF, 0xCD73,
    &anim_staraptor_sprite_hiro,
    anim_staraptor_hiro_anim_table,
    anim_staraptor_hiro_graphics,
    oam_rotscale_anim_table_null,
    anim_staraptor_oam_callback
    
};
