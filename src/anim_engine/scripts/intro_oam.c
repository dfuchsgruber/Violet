#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "romfuncs.h"

extern u16 gfx_intro_meteorTiles[];
extern u16 gfx_intro_deoxys_headTiles[];
extern u16 gfx_intro_deoxys_bodyTiles[];
extern u16 gfx_intro_deoxys_bottomTiles[];
extern u16 gfx_intro_deoxys_armTiles[];
extern u16 gfx_intro_wavesTiles[];

graphic graphic_intro_meteor = {
    gfx_intro_meteorTiles,
    0x1000,
    0xADE3
};

sprite oam_sprite_intro_meteor = {
    ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE | ATTR0_DSIZE, 
    ATTR1_SIZE_64_64, 
    ATTR2_PRIO(0), 
    0
};

/**
 * Moves the oam of the meteor about 45 frames upwards
 * @param self
 */
void oam_intro_meteor_move(oam_object *self){
    if(++(self->private[0]) <= 70) self->y2--;
}

gfx_frame gfx_anim_intro_meteor[] = {
    {0, 8}, {64, 8}, {GFX_ANIM_JUMP, 0}
};

gfx_frame *gfx_anim_table_intro_meteor[] = {gfx_anim_intro_meteor};

rotscale_frame rotscal_anim_intro_meteor[] = {
    {0x200, 0x200, 0, 0, 0}, {-8, -8, 0, 63, 0}, {ROTSCAL_ANIM_END, 0, 0, 0, 0} 
};

rotscale_frame *rotscale_anim_table_intro_meteor[] = {rotscal_anim_intro_meteor};

oam_template oam_template_intro_meteor = {
    0xADE3, 0xADE3,
    &oam_sprite_intro_meteor,
    gfx_anim_table_intro_meteor,
    NULL,
    rotscale_anim_table_intro_meteor,
    oam_intro_meteor_move
};

void anim_intro_earthquake(u8 self){
    if(++(big_callbacks[self].params[0]) == 3){
        big_callbacks[self].params[0] = 0;
        if(++(big_callbacks[self].params[1]) == 8){
            set_io(0x14, 0);
            remove_big_callback(self);
        }
        else{
            big_callbacks[self].params[2] ^= 1;
            if(big_callbacks[self].params[2]){
                set_io(0x14, (u16)-2);
            }else{
                set_io(0x14, 2);
            }
        }
    }
}

graphic graphic_intro_deoxys_head = {
    gfx_intro_deoxys_headTiles, 0x400, 0xADE4
};

graphic graphic_intro_deoxys_body = {
    gfx_intro_deoxys_bodyTiles, 0x200, 0xADE5
};

graphic graphic_intro_deoxys_bottom = {
    gfx_intro_deoxys_bottomTiles, 0x800, 0xADE6
};

graphic graphic_intro_deoxys_arm = {
    gfx_intro_deoxys_armTiles, 0xC00, 0xADE7
};

sprite oam_sprite_intro_deoxys_head = {
    ATTR0_SHAPE_HORIZONTAL, ATTR1_SIZE_64_32, ATTR2_PRIO(1), 0
};

sprite oam_sprite_intro_deoxys_body = {
    ATTR0_SHAPE_SQUARE, ATTR1_SIZE_32_32, ATTR2_PRIO(1), 0
};

sprite oam_sprite_intro_deoxys_bottom = {
    ATTR0_SHAPE_SQUARE, ATTR1_SIZE_64_64, ATTR2_PRIO(1), 0
};

sprite oam_sprite_intro_deoxys_arm_right = {
    ATTR0_SHAPE_VERTICAL, ATTR1_SIZE_32_64, ATTR2_PRIO(1), 0
};

sprite oam_sprite_intro_deoxys_arm_left = {
    ATTR0_SHAPE_VERTICAL, ATTR1_SIZE_32_64 | ATTR1_VFLIP, ATTR2_PRIO(1), 0
};

gfx_frame gfx_anim_intro_deoxys_arm_right[] = {
    {0, 16}, {32, 16}, 
    {64, 16}, {32, 16}, {0xFFFE, 0}
};

gfx_frame gfx_anim_intro_deoxys_arm_left[] = {
    {0, 16 | GFX_ANIM_HFLIP}, {32, 16| GFX_ANIM_HFLIP}, 
    {64, 16 | GFX_ANIM_HFLIP}, {32, 16 | GFX_ANIM_HFLIP}, {GFX_ANIM_JUMP, 0}
};

gfx_frame *gfx_anim_table_intro_deoxys_arm_right[] = {
    gfx_anim_intro_deoxys_arm_right
};

gfx_frame *gfx_anim_table_intro_deoxys_arm_left[] = {
    gfx_anim_intro_deoxys_arm_left
};

void oam_intro_deoxys_leviate(oam_object *self){
    if(++(self->private[4]) == 8){
        self->private[4] = 0;
        //cycle the deoxys movement
        if(self->private[5]){
            //count down
            if(!--(self->private[6])){
                self->private[5] = 0; //switch to count up
            }
            self->y--;
        }else{
            //count up
            if(++(self->private[6]) == 4){
                self->private[5] = 1; //switch to count down
            }
            self->y++;
        }
    }
}



oam_template oam_template_intro_deoxys_head = {
    0xADE4, 0xADE4,
    &oam_sprite_intro_deoxys_head,
    GFX_ANIM_TABLE_NULL,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_intro_deoxys_leviate,
};

oam_template oam_template_intro_deoxys_body = {
    0xADE5, 0xADE4,
    &oam_sprite_intro_deoxys_body,
    GFX_ANIM_TABLE_NULL,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_intro_deoxys_leviate
};

oam_template oam_template_intro_deoxys_bottom = {
    0xADE6, 0xADE4,
    &oam_sprite_intro_deoxys_bottom,
    GFX_ANIM_TABLE_NULL,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_intro_deoxys_leviate
};

oam_template oam_template_intro_deoxys_arm_right = {
    0xADE7, 0xADE4,
    &oam_sprite_intro_deoxys_arm_right,
    gfx_anim_table_intro_deoxys_arm_right,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_intro_deoxys_leviate
};

oam_template oam_template_intro_deoxys_arm_left = {
    0xADE7, 0xADE4,
    &oam_sprite_intro_deoxys_arm_left,
    gfx_anim_table_intro_deoxys_arm_left,
    //GFX_ANIM_TABLE_NULL,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_intro_deoxys_leviate
};

graphic graphic_intro_waves = {
    gfx_intro_wavesTiles, 0x1000, 0xADE8
};

sprite oam_sprite_intro_waves_front = {
    ATTR0_SHAPE_SQUARE | ATTR0_DSIZE | ATTR0_ROTSCALE, 
    ATTR1_SIZE_64_64, 
    ATTR2_PRIO(0),
    0
};

/**
sprite oam_sprite_intro_waves_back = {
    ATTR0_SHAPE_SQUARE, 
    ATTR1_SIZE_64_64, 
    ATTR2_PRIO(1),
    0
};**/


gfx_frame gfx_anim_intro_waves[] = {
    {0, 24}, {64, 24}, {GFX_ANIM_JUMP, 0}
};

gfx_frame *gfx_anim_table_intro_waves[] = {gfx_anim_intro_waves};

rotscale_frame rotscal_anim_intro_waves[] = {
    {0x200, 0x200, 0, 0, 0}, {ROTSCAL_ANIM_END, 0, 0, 0, 0}
};

rotscale_frame *rotscale_anim_table_intro_waves[] = {rotscal_anim_intro_waves};

/**
void oam_intro_waves_back_move(oam_object *self){
    if(++(self->private[0]) == 2){
        self->private[0] = 0;
        self->x = (s16)(self->x + 2);
        if(self->x == 256 + 32) self->x = -32;
    }
}**/

void oam_intro_waves_front_move(oam_object *self){
    if(++(self->private[0]) == 3){
        self->private[0] = 0;
        self->x2 = (s16)(self->x2 + 4);
        if(self->x + self->x2 == 256 + 64) self->x2 = (s16)(-64 - self->x);
    }
}

oam_template oam_template_intro_waves_front = {
    0xADE8, 0xADE8,
    &oam_sprite_intro_waves_front,
    gfx_anim_table_intro_waves,
    NULL,
    rotscale_anim_table_intro_waves,
    oam_intro_waves_front_move
};

/**
oam_template oam_template_intro_waves_back = {
    0xADE8, 0xADE9,
    &oam_sprite_intro_waves_back,
    GFX_ANIM_TABLE_NULL,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
};**/

void anim_intro_waves_back_scroll(u8 self){
    set_io(0x18, big_callbacks[self].params[0]);
    set_io(0x1C, big_callbacks[self].params[0] >> 3);
    big_callbacks[self].params[0]--;
}
