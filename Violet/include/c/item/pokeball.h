#ifndef H_ITEM_POKEBALL
#define H_ITEM_POKEBALL

#include "types.h"
#include "oam.h"

enum {
    BALL_POKE,
    BALL_GREAT,
    BALL_SAFARI,
    BALL_ULTRA,
    BALL_MASTER,
    BALL_NET,
    BALL_DIVE,
    BALL_NEST,
    BALL_REPEAT,
    BALL_TIMER,
    BALL_LUXURY,
    BALL_PREMIER,
    BALL_LOTUS,
    NUM_POKEBALLS,
};

#define OAM_TAG_POKEBALL_PARTICES_BASE 55020

extern gfx_frame *pokeball_particles_gfx_animations[6];

#define POKEBALL_PARTICLE_TEMPLATE_STANDARD(ball_idx) {\
        .tiles_tag = OAM_TAG_POKEBALL_PARTICES_BASE + ball_idx, \
        .pal_tag = OAM_TAG_POKEBALL_PARTICES_BASE + ball_idx,\
        .oam = &pokeball_partices_sprite, .animation = pokeball_particles_gfx_animations,\
        .graphics = NULL, .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,\
    }

void pokeball_particles_initialize_poke_ball (u8 self);
void pokeball_particles_initialize_great_ball (u8 self);
void pokeball_particles_initialize_safari_ball (u8 self);
void pokeball_particles_initialize_ultra_ball (u8 self);
void pokeball_particles_initialize_master_ball (u8 self);
void pokeball_particles_initialize_net_ball (u8 self);
void pokeball_particles_initialize_dive_ball (u8 self);
void pokeball_particles_initialize_nest_ball (u8 self);
void pokeball_particles_initialize_repeat_ball (u8 self);
void pokeball_particles_initialize_timer_ball (u8 self);
void pokeball_particles_initialize_luxury_ball (u8 self);
void pokeball_particles_initialize_premier_ball (u8 self);



#endif