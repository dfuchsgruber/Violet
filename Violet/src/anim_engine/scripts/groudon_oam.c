#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "debug.h"
#include "color.h"
#include "math.h"
#include "io.h"
#include "bios.h"
#include "anim_engine.h"

extern const unsigned short gfx_groudon_headTiles[];
extern const unsigned short gfx_groudon_arm_leftTiles[];
extern const unsigned short gfx_groudon_arm_rightTiles[];
extern const unsigned short gfx_groudon_leg_leftTiles[];
extern const unsigned short gfx_groudon_leg_rightTiles[];
extern const unsigned short gfx_groudon_diseraktTiles[];

const graphic graphic_groudon_head = {
    gfx_groudon_headTiles,
    0x800,
    0xA0A0
};

const graphic graphic_groudon_arm_left = {
    gfx_groudon_arm_leftTiles,
    0x400,
    0xA0A1
};

const graphic graphic_groudon_arm_right = {
    gfx_groudon_arm_rightTiles,
    0x400,
    0xA0A2
};

const graphic graphic_groudon_leg_left = {
    gfx_groudon_leg_leftTiles,
    0x400,
    0xA0A3
};

const graphic graphic_groudon_leg_right = {
    gfx_groudon_leg_rightTiles,
    0x400,
    0xA0A4
};

const graphic graphic_groudon_diserakt = {
    gfx_groudon_diseraktTiles,
    0x800,
    0xA0A5
};

const sprite sprite_groudon_32_16_back = {
    ATTR0_SHAPE_VERTICAL, ATTR1_SIZE_32_64, ATTR2_PRIO(2), 0
};

const sprite sprite_groudon_32_16_front = { 
    ATTR0_SHAPE_VERTICAL, ATTR1_SIZE_32_64, ATTR2_PRIO(1), 0
};

const sprite sprite_groudon_head = {
    ATTR0_SHAPE_SQUARE, ATTR1_SIZE_64_64, ATTR2_PRIO(1), 0
};

void oam_callback_groudon_head(oam_object *self){
    if(!self->private[0]){
        //movement cycle
        self->private[1] ^= 1; //switch
        if(self->private[1]){
            self->y++;
        }else{
            self->y--;
        }
        self->private[0] = 30; //delay
    }else{
        self->private[0]--;
    }
}


void oam_callback_groudon_arm(oam_object *self){
    if(!self->private[0]){
        //movement cycle
        self->private[1] ^= 1; //switch
        if(self->private[1]){
            self->y--;
            self->x--;
        }else{
            self->y++;
            self->x++;
        }
        self->private[0] = 26; //delay
    }else{
        self->private[0]--;
    }
}

void groudon_bg_scroll_all(u8 self){
    int cnt = big_callbacks[self].params[0];
    if(cnt == 0 || cnt == 4 || cnt == 8 || cnt == 12){
        io_set(0x10, (u16)(io_get(0x10)-1));
        if(cnt == 0 || cnt == 8){
            io_set(0x18,(u16)(io_get(0x18)-1));
        }
    }
    if(!cnt){
        big_callbacks[self].params[0] = 16;
    }else{
        big_callbacks[self].params[0]--;
    }
}

void groudon_bg_scroll_cb(u8 self){
    
    
    
    if(!big_callbacks[self].params[0]){
        
        
        oam_object *head = &oams[animation_engine_state->vars[0]];
        oam_object *arm_left = &oams[animation_engine_state->vars[1]];
        oam_object *arm_right = &oams[animation_engine_state->vars[2]];
        big_callbacks[self].params[1] ^= 1; //switch
        if( big_callbacks[self].params[1]){
            io_set(0x16, (u16)(io_get(0x16)+1));
            head->y--;
            arm_left->y--;
            arm_right->y--;
        }else{
            io_set(0x16, (u16)(io_get(0x16)-1));
            head->y++;
            arm_left->y++;
            arm_right->y++;
        }
        big_callbacks[self].params[0] = 44;
    }else{
        big_callbacks[self].params[0]--;
    }
}

void groudon_bg_scroll_diserakt_cb(u8 self){
    
    if(!(big_callbacks[self].params[0] & 31)){
        io_set(0x10, (u16)(io_get(0x10)-1));
        oam_object *d = &oams[animation_engine_state->vars[0]];
        d->x++;
        if(!(big_callbacks[self].params[0] & 127)){   
            io_set(0x14, (u16)(io_get(0x14)-1));
        }
    }
    big_callbacks[self].params[0]++;
}


void groudon_anim_step_cb(u8 self){
    
    
    
    if(big_callbacks[self].params[0]--){
        if(!(big_callbacks[self].params[0] & 1)) return;
        
        int i;
        for(i = 0; i < 5; i++){
            oams[animation_engine_state->vars[i]].x = (s16)(oams[animation_engine_state->vars[i]].x-1);
            if(big_callbacks[self].params[0] & 6)
                oams[animation_engine_state->vars[i]].y = (s16)(oams[animation_engine_state->vars[i]].y-1);
        }
        io_set(0x14, (u16)(io_get(0x14)+1));
        if(big_callbacks[self].params[0] & 6)
            io_set(0x16, (u16)(io_get(0x16)+1));
        
    }else{
        big_callback_delete(self);
    }
    
    
}


/**
 * formula for earthquake y(x, i, s, T):
 * intensity := i
 * speed := s, T := 4 * s
 * cushion := c
 * frame(running index) := x
 * y(x) = i * sin( x * T / (2 * pi) ) * (0.5 ^ (x * cushion / (T * T)))
 */
int groudon_anim_earthquake_displacement(int frame, int period, int amplitude, int cushion) {
    FIXED sin_arg = FIXED_DIV(INT_TO_FIXED(frame), INT_TO_FIXED(period));
    FIXED trig_applied = FIXED_MUL(FIXED_SIN(sin_arg), INT_TO_FIXED(amplitude));
    // Apply decay function
    int decay = hwt(frame/period, period/cushion, 0x10000);
    return (FIXED_TO_INT(trig_applied) * decay) / 0x10000;
}

void groudon_anim_earthquake_cb(u8 self){
    //params [intensity] [speed] [duration] [cushion]
    int amplitude = big_callbacks[self].params[0];
    int period = big_callbacks[self].params[1] * 4;
    int duration = big_callbacks[self].params[2];
    int cushion = big_callbacks[self].params[3];
    int frame = big_callbacks[self].params[4]++;
    
    if(frame >= duration){
        big_callback_delete(self);
    }else {
        int dy = groudon_anim_earthquake_displacement(frame + 1, period, amplitude, cushion) - 
            groudon_anim_earthquake_displacement(frame, period, amplitude, cushion);
        for(int i = 0; i < 5; i++){
            oams[animation_engine_state->vars[i]].x = (s16)(dy + oams[animation_engine_state->vars[i]].x);
        }
        if (frame > 0) {
            // Use the dy from last frame to match the oam timingint 
            int dy_last = groudon_anim_earthquake_displacement(frame, period, amplitude, cushion) - 
            groudon_anim_earthquake_displacement(frame - 1, period, amplitude, cushion);
            io_set(0x14, (u16)(io_get(0x14) - dy_last));
            io_set(0x18, (u16)(io_get(0x18) - dy_last));
            io_set(0x10, (u16)(io_get(0x10) - dy_last));
        } 
    }
}

void groudon_anim_diserakt_cb (u8 self){
    
    
    if(animation_engine_state->vars[1]){
        big_callback_delete(self);
        return;
    }
    
    if(big_callbacks[self].params[3]++){
        big_callbacks[self].params[3] &= 7;
        return;
    }
    
    //this is simply a color fading
    u16 dst_col;
    switch(big_callbacks[self].params[0]){
        case 0: dst_col = 0x6564; break;
        case 1: dst_col = 0x0664; break;
        case 2: dst_col = 0x3FF; break;
        default: dst_col = 0x43C; break;
    }
    if(big_callbacks[self].params[1]){
        //descend
        if(!--big_callbacks[self].params[2]){
            //switch mode and dst_col rot
            big_callbacks[self].params[1] = 0;
            big_callbacks[self].params[0]++;
            big_callbacks[self].params[0] &= 3;
        }
    }else{
        //ascend
        if(++big_callbacks[self].params[2] == 8){
            big_callbacks[self].params[1] = 1;
        }
    }
    u8 intensity = (u8)big_callbacks[self].params[2];
    int dst_pal = oam_palette_get_index(0xA0A1) + 16;
    int i;
    for(i = 0; i < 8; i++){
        color_t d = {dst_col};
        color_t n = color_alpha_blend(pal_restore[dst_pal*16+i], d, intensity);
        pals[dst_pal*16+i] = n;
    }
    
}

void groudon_cb_grey_fade(u8 self){
    big_callback *bself = &big_callbacks[self];
    if(bself->params[0] == 16){
        cpuset(pals, pal_restore, 512 | CPUSET_HALFWORD );
        big_callback_delete(self);
    }else{
        bself->params[0] = (u16)(bself->params[0]+1);
        int intensity = bself->params[0]*1;
        int i;
        for(i = 0; i < 512; i++){
            //for each color calculate middle
            u16 middle_int = (u16)((pal_restore[i].rgb.blue + pal_restore[i].rgb.red
                + pal_restore[i].rgb.green) / 3);
           
            color_t middle_col = {(u16)((middle_int << 5) | (middle_int << 10)| middle_int)};
            
            pals[i] = color_alpha_blend(pal_restore[i], middle_col, (u8)intensity);
        }
    }
}

const oam_template oam_template_groudon_head = {
    0xA0A0,
    0xA0A0,
    &sprite_groudon_head,
    oam_gfx_anim_table_null,
    &graphic_groudon_head,
    oam_rotscale_anim_table_null,
    oam_callback_groudon_head
};

const oam_template oam_template_groudon_arm_left = {
    0xA0A1,
    0xA0A0,
    &sprite_groudon_32_16_front,
    oam_gfx_anim_table_null,
    &graphic_groudon_arm_left,
    oam_rotscale_anim_table_null,
    oam_callback_groudon_arm
};

const oam_template oam_template_groudon_arm_right = {
    0xA0A2,
    0xA0A0,
    &sprite_groudon_32_16_back,
    oam_gfx_anim_table_null,
    &graphic_groudon_arm_left,
    oam_rotscale_anim_table_null,
    oam_callback_groudon_arm
};

const oam_template oam_template_groudon_leg_left = {
    0xA0A3,
    0xA0A0,
    &sprite_groudon_32_16_front,
    oam_gfx_anim_table_null,
    &graphic_groudon_leg_left,
    oam_rotscale_anim_table_null,
    oam_null_callback
};

const oam_template oam_template_groudon_leg_right = {
    0xA0A4,
    0xA0A0,
    &sprite_groudon_32_16_back,
    oam_gfx_anim_table_null,
    &graphic_groudon_leg_right,
    oam_rotscale_anim_table_null,
    oam_null_callback
};

const oam_template oam_template_groudon_diserakt = {
    0xA0A5,
    0xA0A1,
    &sprite_groudon_head,
    oam_gfx_anim_table_null,
    &graphic_groudon_diserakt,
    oam_rotscale_anim_table_null,
    oam_null_callback
    
};
