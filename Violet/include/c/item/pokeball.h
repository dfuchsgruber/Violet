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

#define OAM_TAG_POKEBALL_BASE 56020
#define OAM_TAG_POKEBALL_PARTICLES_BASE 55020

extern gfx_frame *pokeball_particles_gfx_animations[6];

#define POKEBALL_PARTICLE_TEMPLATE_STANDARD(ball_idx) {\
        .tiles_tag = OAM_TAG_POKEBALL_PARTICLES_BASE + ball_idx, \
        .pal_tag = OAM_TAG_POKEBALL_PARTICLES_BASE + ball_idx,\
        .oam = &pokeball_partices_sprite, .animation = pokeball_particles_gfx_animations,\
        .graphics = NULL, .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,\
    }

extern sprite pokeball_sprite;
extern gfx_frame *pokeball_gfx_animations[];
extern rotscale_frame *pokeball_rotscale_animations[];
void pokeball_throw_oam_callback(oam_object *self);

#define POKEBALL_TEMPLATE_STANDARD(ball_idx) {\
        .tiles_tag = OAM_TAG_POKEBALL_BASE + ball_idx, \
        .pal_tag = OAM_TAG_POKEBALL_BASE + ball_idx,\
        .oam = &pokeball_sprite, .animation = pokeball_gfx_animations,\
        .graphics = NULL, .rotscale = pokeball_rotscale_animations, .callback = pokeball_throw_oam_callback,\
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

/**
 * Converts an item idx into a pokeball idx
 * @param item_idx the item to convert
 * @return ball_idx the pokeball idx
 **/
u8 item_idx_to_pokeball_idx(u16 item_idx);

extern const u8 gfx_pokeball_pokeTiles[];
extern const u8 gfx_pokeball_pokePal[];
extern const u8 gfx_pokeball_greatTiles[];
extern const u8 gfx_pokeball_greatPal[];
extern const u8 gfx_pokeball_safariTiles[];
extern const u8 gfx_pokeball_safariPal[];
extern const u8 gfx_pokeball_ultraTiles[];
extern const u8 gfx_pokeball_ultraPal[];
extern const u8 gfx_pokeball_masterTiles[];
extern const u8 gfx_pokeball_masterPal[];
extern const u8 gfx_pokeball_netTiles[];
extern const u8 gfx_pokeball_netPal[];
extern const u8 gfx_pokeball_diveTiles[];
extern const u8 gfx_pokeball_divePal[];
extern const u8 gfx_pokeball_nestTiles[];
extern const u8 gfx_pokeball_nestPal[];
extern const u8 gfx_pokeball_repeatTiles[];
extern const u8 gfx_pokeball_repeatPal[];
extern const u8 gfx_pokeball_timerTiles[];
extern const u8 gfx_pokeball_timerPal[];
extern const u8 gfx_pokeball_luxuryTiles[];
extern const u8 gfx_pokeball_luxuryPal[];
extern const u8 gfx_pokeball_premierTiles[];
extern const u8 gfx_pokeball_premierPal[];
extern const u8 gfx_pokeball_lotusTiles[];
extern const u8 gfx_pokeball_lotusPal[];

extern const u8 gfx_pokeball_particlesTiles[];
extern const u8 gfx_pokeball_particlesPal[];


#endif