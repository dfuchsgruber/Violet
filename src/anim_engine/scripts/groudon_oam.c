#include "types.h"
#include "oams.h"
#include "gfx.h"
#include "callbacks.h"
#include "romfuncs.h"
#include "save.h"
#include "debug.h"
#include "color.h"
#include "utils.h"



extern const unsigned short gfx_groudon_headTiles[];
extern const unsigned short gfx_groudon_arm_leftTiles[];
extern const unsigned short gfx_groudon_arm_rightTiles[];
extern const unsigned short gfx_groudon_leg_leftTiles[];
extern const unsigned short gfx_groudon_leg_rightTiles[];
extern const unsigned short gfx_groudon_diseraktTiles[];

graphic graphic_groudon_head = {
    gfx_groudon_headTiles,
    0x800,
    0xA0A0
};

graphic graphic_groudon_arm_left = {
    gfx_groudon_arm_leftTiles,
    0x400,
    0xA0A1
};

graphic graphic_groudon_arm_right = {
    gfx_groudon_arm_rightTiles,
    0x400,
    0xA0A2
};

graphic graphic_groudon_leg_left = {
    gfx_groudon_leg_leftTiles,
    0x400,
    0xA0A3
};

graphic graphic_groudon_leg_right = {
    gfx_groudon_leg_rightTiles,
    0x400,
    0xA0A4
};

graphic graphic_groudon_diserakt = {
    gfx_groudon_diseraktTiles,
    0x800,
    0xA0A5
};

sprite sprite_groudon_32_16_back = {
    ATTR0_SHAPE_VERTICAL, ATTR1_SIZE_32_64, ATTR2_PRIO(2), 0
};

sprite sprite_groudon_32_16_front = { 
    ATTR0_SHAPE_VERTICAL, ATTR1_SIZE_32_64, ATTR2_PRIO(1), 0
};

sprite sprite_groudon_head = {
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
        set_io(0x10, (u16)(get_io(0x10)-1));
        if(cnt == 0 || cnt == 8){
            set_io(0x18,(u16)(get_io(0x18)-1));
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
        
        
        oam_object *head = &oams[fmem->ae_mem->vars[0]];
        oam_object *arm_left = &oams[fmem->ae_mem->vars[1]];
        oam_object *arm_right = &oams[fmem->ae_mem->vars[2]];
        big_callbacks[self].params[1] ^= 1; //switch
        if( big_callbacks[self].params[1]){
            set_io(0x16, (u16)(get_io(0x16)+1));
            head->y--;
            arm_left->y--;
            arm_right->y--;
        }else{
            set_io(0x16, (u16)(get_io(0x16)-1));
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
        set_io(0x10, (u16)(get_io(0x10)-1));
        oam_object *d = &oams[fmem->ae_mem->vars[0]];
        d->x++;
        if(!(big_callbacks[self].params[0] & 127)){   
            set_io(0x14, (u16)(get_io(0x14)-1));
        }
    }
    big_callbacks[self].params[0]++;
}


void groudon_anim_step_cb(u8 self){
    
    
    
    if(big_callbacks[self].params[0]--){
        if(!(big_callbacks[self].params[0] & 1)) return;
        
        int i;
        for(i = 0; i < 5; i++){
            oams[fmem->ae_mem->vars[i]].x = (s16)(oams[fmem->ae_mem->vars[i]].x-1);
            if(big_callbacks[self].params[0] & 6)
                oams[fmem->ae_mem->vars[i]].y = (s16)(oams[fmem->ae_mem->vars[i]].y-1);
        }
        set_io(0x14, (u16)(get_io(0x14)+1));
        if(big_callbacks[self].params[0] & 6)
            set_io(0x16, (u16)(get_io(0x16)+1));
        
    }else{
        remove_big_callback(self);
    }
    
    
}


/**
 * 
 * formula for earthquake y(x):
 * intensity := i
 * speed := s, T := 4 * s
 * cushion := c
 * frame(running index) := x
 * y(x) = i * sin( x * T / (2 * pi) ) * (0.5 ^ (x * cushion / (T * T)))
 * 
 * @param self
 * 
 */
void groudon_anim_earthquake_cb(u8 self){
    //params [intensity] [speed] [duration] [cushion]
    
    int amplitude = big_callbacks[self].params[0];
    int period = big_callbacks[self].params[1] * 4;
    int duration = big_callbacks[self].params[2];
    int cushion = big_callbacks[self].params[3];
    int frame = big_callbacks[self].params[4];
    int y;
    
    u16 *slast = &(big_callbacks[self].params[5]);
    
    if(frame > duration){
        remove_big_callback(self);
    }else{
        //y(x) = A * sin(x * T / (2pi)) * hwt(x, T/2, 1)
        //T := 4 * speed
        y = frame * 0x10000 / period;
        y = sin_16(y) * amplitude / 0x10000; //sin_16 provides an ampl of 0x10000
        //if(frame)debug4(y, z, amplitude, w);
        int ht = hwt(frame/period, period/cushion, 0x10000);
        y *= ht;
        y /= 0x10000;
        int i;
            for(i = 0; i < 5; i++){
                oams[fmem->ae_mem->vars[i]].x2 = (s16)(y);
            }
            set_io(0x14, (u16)(get_io(0x14)-y+(*slast)));
            set_io(0x18, (u16)(get_io(0x18)-y+(*slast)));
            set_io(0x10, (u16)(get_io(0x10)-y+(*slast)));
            *slast = (u16)y;
        big_callbacks[self].params[4]++;
    }
}
    
    /**
    
    if(!__umod(big_callbacks[self].params[3], big_callbacks[self].params[1])){
        if(big_callbacks[self].params[3] >= big_callbacks[self].params[2]){
            remove_big_callback(self);
        }else{
            //period of oszilation is 4*speed, but sin_16 has period of 0x10000
            //so we multiply the counter by 0x10000 / (4*speed)
            int x = big_callbacks[self].params[3] * 0x10000 / (4 * big_callbacks[self].params[1]);
            int y = sin_16(x) * big_callbacks[self].params[0] / 0x10000;
            //we adjust the value by multiplicating e^ax to the sin
            //where a is defined as 2*ln(0.5)*T
            int a = 2 * (-69314718) / * 4 * (big_callbacks[self].params[1]) * 100000000;
            y = y * exp(a*x);
            
            
            int i;
            for(i = 0; i < 5; i++){
                oams[fmem->ae_mem->vars[i]].x2 = (s16)(oams[fmem->ae_mem->vars[i]].x2 + y);
            }
            set_io(0x14, (u16)(get_io(0x14)-y));
        }
    }
    big_callbacks[self].params[3]++;
}**/

void groudon_anim_diserakt_cb (u8 self){
    
    
    if(fmem->ae_mem->vars[1]){
        remove_big_callback(self);
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
    int dst_pal = get_obj_pal_by_tag(0xA0A1) + 16;
    int i;
    for(i = 0; i < 8; i++){
        color d = {dst_col};
        color n = alpha_blend(pal_restore[dst_pal*16+i], d, intensity);
        pals[dst_pal*16+i] = n;
    }
    
}

void groudon_cb_grey_fade(u8 self){
    big_callback *bself = &big_callbacks[self];
    if(bself->params[0] == 16){
        cpuset(pals, pal_restore, 512 | CPUSET_HALFWORD );
        remove_big_callback(self);
    }else{
        bself->params[0] = (u16)(bself->params[0]+1);
        int intensity = bself->params[0]*1;
        int i;
        for(i = 0; i < 512; i++){
            //for each color calculate middle
            u16 middle_int = (u16)((pal_restore[i].rgb.blue + pal_restore[i].rgb.red
                + pal_restore[i].rgb.green) / 3);
           
            color middle_col = {(u16)((middle_int << 5) | (middle_int << 10)| middle_int)};
            
            pals[i] = alpha_blend(pal_restore[i], middle_col, (u8)intensity);
        }
    }
}

oam_template oam_template_groudon_head = {
    0xA0A0,
    0xA0A0,
    &sprite_groudon_head,
    GFX_ANIM_TABLE_NULL,
    &graphic_groudon_head,
    ROTSCALE_TABLE_NULL,
    oam_callback_groudon_head
};

oam_template oam_template_groudon_arm_left = {
    0xA0A1,
    0xA0A0,
    &sprite_groudon_32_16_front,
    GFX_ANIM_TABLE_NULL,
    &graphic_groudon_arm_left,
    ROTSCALE_TABLE_NULL,
    oam_callback_groudon_arm
};

oam_template oam_template_groudon_arm_right = {
    0xA0A2,
    0xA0A0,
    &sprite_groudon_32_16_back,
    GFX_ANIM_TABLE_NULL,
    &graphic_groudon_arm_left,
    ROTSCALE_TABLE_NULL,
    oam_callback_groudon_arm
};

oam_template oam_template_groudon_leg_left = {
    0xA0A3,
    0xA0A0,
    &sprite_groudon_32_16_front,
    GFX_ANIM_TABLE_NULL,
    &graphic_groudon_leg_left,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
};

oam_template oam_template_groudon_leg_right = {
    0xA0A4,
    0xA0A0,
    &sprite_groudon_32_16_back,
    GFX_ANIM_TABLE_NULL,
    &graphic_groudon_leg_right,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
};

oam_template oam_template_groudon_diserakt = {
    0xA0A5,
    0xA0A1,
    &sprite_groudon_head,
    GFX_ANIM_TABLE_NULL,
    &graphic_groudon_diserakt,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
    
};