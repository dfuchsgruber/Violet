#include "types.h"
#include "item/item.h"
#include "pokemon/virtual.h"
#include "language.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "debug.h"
#include "item/bag.h"
#include "item/pokeball.h"
#include "color.h"

extern u8 str_pokeball_unusable_because_no_space[];

u8 str_pokeball_unusable_cant_aim_at_two[] = LANGDEP(
    PSTRING("Du kannst nicht auf zwei Pokémon\ngleichzeitig zielen!PAUSE_UNTIL_PRESS"),
    PSTRING("You can't aim at two Pokémon at\nthe same time!PAUSE_UNTIL_PRESS")
);

u8 str_pokeball_unusable_because_of_other_action[] = LANGDEP(
    PSTRING("Du kannst keinen Ball werfen, wenn du\nbereits eine andere Aktion ausführst.PAUSE_UNTIL_PRESS"),
    PSTRING("You can't throw a ball while\nperforming another action.PAUSE_UNTIL_PRESS")
);

void item_pokeball_battle(u8 self) {
    if (BATTLE_IS_WILD_DOUBLE && battler_get_position(battler_in_party_menu) == BATTLE_POSITION_PLAYER_RIGHT) {
        bag_print_string(self, 2, str_pokeball_unusable_because_of_other_action, bag_return_from_context_menu);
    } else if ((battle_flags & BATTLE_DOUBLE) && battlers[BATTLE_POSITION_OPPONENT_LEFT].current_hp > 0 && battlers[BATTLE_POSITION_OPPONENT_RIGHT].current_hp > 0) {
        bag_print_string(self, 2, str_pokeball_unusable_cant_aim_at_two, bag_return_from_context_menu);
    } else if (player_party_and_boxes_full()) {
        bag_print_string(self, 2, str_pokeball_unusable_because_no_space, bag_return_from_context_menu);
    } else {
        item_remove(item_activated, 1);
        bag_initialize_close_animation();
        item_menu_fade_and_continue(self);
    }
}

u8 item_idx_to_pokeball_idx(u16 item_idx) {
    switch (item_idx) {
        case ITEM_MEISTERBALL:
            return BALL_MASTER;
        case ITEM_HYPERBALL:
            return BALL_ULTRA;
        case ITEM_SUPERBALL:
            return BALL_GREAT;
        case ITEM_SAFARIBALL:
            return BALL_SAFARI;
        case ITEM_NETZBALL:
            return BALL_NET;
        case ITEM_WOLKENBALL:
            return BALL_DIVE;
        case ITEM_NESTBALL:
            return BALL_NEST;
        case ITEM_WIEDERBALL:
            return BALL_REPEAT;
        case ITEM_TIMERBALL:
            return BALL_TIMER;
        case ITEM_LUXUSBALL:
            return BALL_LUXURY;
        case ITEM_PREMIERBALL:
            return BALL_PREMIER;
        case ITEM_LOTUS_BALL:
            return BALL_LOTUS;
        case ITEM_POKEBALL:
        default:
            return BALL_POKE;
    }
}

graphic pokeball_gfxs[NUM_POKEBALLS] = {
    [BALL_POKE] = {.sprite = gfx_pokeball_pokeTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_POKE},
    [BALL_GREAT] = {.sprite = gfx_pokeball_greatTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_GREAT},
    [BALL_SAFARI] = {.sprite = gfx_pokeball_safariTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_SAFARI},
    [BALL_ULTRA] = {.sprite = gfx_pokeball_ultraTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_ULTRA},
    [BALL_MASTER] = {.sprite = gfx_pokeball_masterTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_MASTER},
    [BALL_NET] = {.sprite = gfx_pokeball_netTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_NET},
    [BALL_DIVE] = {.sprite = gfx_pokeball_diveTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_DIVE},
    [BALL_NEST] = {.sprite = gfx_pokeball_nestTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_NEST},
    [BALL_REPEAT] = {.sprite = gfx_pokeball_repeatTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_REPEAT},
    [BALL_TIMER] = {.sprite = gfx_pokeball_timerTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_TIMER},
    [BALL_LUXURY] = {.sprite = gfx_pokeball_luxuryTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_LUXURY},
    [BALL_PREMIER] = {.sprite = gfx_pokeball_premierTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_PREMIER},
    [BALL_LOTUS] = {.sprite = gfx_pokeball_lotusTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_LOTUS},
    [BALL_QUICK] = {.sprite = gfx_pokeball_quickTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_QUICK},
    [BALL_DUSK] = {.sprite = gfx_pokeball_duskTiles, .size = GRAPHIC_SIZE_4BPP(16, 48), .tag = OAM_TAG_POKEBALL_BASE + BALL_DUSK},
};

palette pokeball_palettes[NUM_POKEBALLS] = {
    [BALL_POKE] = {.pal = gfx_pokeball_pokePal, .tag = OAM_TAG_POKEBALL_BASE + BALL_POKE},
    [BALL_GREAT] = {.pal = gfx_pokeball_greatPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_GREAT},
    [BALL_SAFARI] = {.pal = gfx_pokeball_safariPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_SAFARI},
    [BALL_ULTRA] = {.pal = gfx_pokeball_ultraPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_ULTRA},
    [BALL_MASTER] = {.pal = gfx_pokeball_masterPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_MASTER},
    [BALL_NET] = {.pal = gfx_pokeball_netPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_NET},
    [BALL_DIVE] = {.pal = gfx_pokeball_divePal, .tag = OAM_TAG_POKEBALL_BASE + BALL_DIVE},
    [BALL_NEST] = {.pal = gfx_pokeball_nestPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_NEST},
    [BALL_REPEAT] = {.pal = gfx_pokeball_repeatPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_REPEAT},
    [BALL_TIMER] = {.pal = gfx_pokeball_timerPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_TIMER},
    [BALL_LUXURY] = {.pal = gfx_pokeball_luxuryPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_LUXURY},
    [BALL_PREMIER] = {.pal = gfx_pokeball_premierPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_PREMIER},
    [BALL_LOTUS] = {.pal = gfx_pokeball_lotusPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_LOTUS},
    [BALL_QUICK] = {.pal = gfx_pokeball_quickPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_QUICK},
    [BALL_DUSK] = {.pal = gfx_pokeball_duskPal, .tag = OAM_TAG_POKEBALL_BASE + BALL_DUSK},
};

oam_template pokeball_oam_templates[NUM_POKEBALLS] = {
    [BALL_POKE] = POKEBALL_TEMPLATE_STANDARD(BALL_POKE),
    [BALL_GREAT] = POKEBALL_TEMPLATE_STANDARD(BALL_GREAT),
    [BALL_SAFARI] = POKEBALL_TEMPLATE_STANDARD(BALL_SAFARI),
    [BALL_ULTRA] = POKEBALL_TEMPLATE_STANDARD(BALL_ULTRA),
    [BALL_MASTER] = POKEBALL_TEMPLATE_STANDARD(BALL_MASTER),
    [BALL_NET] = POKEBALL_TEMPLATE_STANDARD(BALL_NET),
    [BALL_DIVE] = POKEBALL_TEMPLATE_STANDARD(BALL_DIVE),
    [BALL_NEST] = POKEBALL_TEMPLATE_STANDARD(BALL_NEST),
    [BALL_REPEAT] = POKEBALL_TEMPLATE_STANDARD(BALL_REPEAT),
    [BALL_TIMER] = POKEBALL_TEMPLATE_STANDARD(BALL_TIMER),
    [BALL_LUXURY] = POKEBALL_TEMPLATE_STANDARD(BALL_LUXURY),
    [BALL_PREMIER] = POKEBALL_TEMPLATE_STANDARD(BALL_PREMIER),
    [BALL_LOTUS] = POKEBALL_TEMPLATE_STANDARD(BALL_LOTUS),
    [BALL_QUICK] = POKEBALL_TEMPLATE_STANDARD(BALL_QUICK),
    [BALL_DUSK] = POKEBALL_TEMPLATE_STANDARD(BALL_DUSK),
};

static sprite pokeball_partices_sprite = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_8_8, .attr2 = ATTR2_PRIO(2),};

graphic pokeball_particle_gfxs[NUM_POKEBALLS] = {
    [BALL_POKE] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_POKE},
    [BALL_GREAT] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_GREAT},
    [BALL_SAFARI] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_SAFARI},
    [BALL_ULTRA] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_ULTRA},
    [BALL_MASTER] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_MASTER},
    [BALL_NET] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_NET},
    [BALL_DIVE] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_DIVE},
    [BALL_NEST] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_NEST},
    [BALL_REPEAT] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_REPEAT},
    [BALL_TIMER] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_TIMER},
    [BALL_LUXURY] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_LUXURY},
    [BALL_PREMIER] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_PREMIER},
    [BALL_LOTUS] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_LOTUS},
    [BALL_QUICK] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_QUICK},
    [BALL_DUSK] = {.sprite = gfx_pokeball_particlesTiles, .size = GRAPHIC_SIZE_4BPP(8, 8) * 8, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_DUSK},
};

palette pokeball_particle_palettes[NUM_POKEBALLS] = {
    [BALL_POKE] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_POKE},
    [BALL_GREAT] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_GREAT},
    [BALL_SAFARI] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_SAFARI},
    [BALL_ULTRA] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_ULTRA},
    [BALL_MASTER] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_MASTER},
    [BALL_NET] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_NET},
    [BALL_DIVE] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_DIVE},
    [BALL_NEST] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_NEST},
    [BALL_REPEAT] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_REPEAT},
    [BALL_TIMER] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_TIMER},
    [BALL_LUXURY] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_LUXURY},
    [BALL_PREMIER] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_PREMIER},
    [BALL_LOTUS] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_LOTUS},
    [BALL_QUICK] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_QUICK},
    [BALL_DUSK] = {.pal = gfx_pokeball_particlesPal, .tag = OAM_TAG_POKEBALL_PARTICLES_BASE + BALL_DUSK},
};

u8 pokeball_particle_animation_idxs[NUM_POKEBALLS] = {
    [BALL_POKE]    = 0,
    [BALL_GREAT]   = 0,
    [BALL_SAFARI]  = 0,
    [BALL_ULTRA]   = 5,
    [BALL_MASTER]  = 1,
    [BALL_NET]     = 2,
    [BALL_DIVE]    = 2,
    [BALL_NEST]    = 3,
    [BALL_REPEAT]  = 5,
    [BALL_TIMER]   = 5,
    [BALL_LUXURY]  = 4,
    [BALL_PREMIER] = 4,
    [BALL_LOTUS] = 1,
    [BALL_QUICK] = BALL_PARTICLE_SMALL_GREEN_CROSSES,
    [BALL_DUSK] = BALL_PARTICLE_SMALL_GREEN_CROSSES,
};

void (*pokeball_particles_initializers[NUM_POKEBALLS])(u8) = {
    [BALL_POKE] = pokeball_particles_initialize_poke_ball,
    [BALL_GREAT] = pokeball_particles_initialize_great_ball,
    [BALL_SAFARI] = pokeball_particles_initialize_safari_ball,
    [BALL_ULTRA] = pokeball_particles_initialize_ultra_ball,
    [BALL_MASTER] = pokeball_particles_initialize_master_ball,
    [BALL_NET] = pokeball_particles_initialize_net_ball,
    [BALL_DIVE] = pokeball_particles_initialize_dive_ball,
    [BALL_NEST] = pokeball_particles_initialize_nest_ball,
    [BALL_REPEAT] = pokeball_particles_initialize_repeat_ball,
    [BALL_TIMER] = pokeball_particles_initialize_timer_ball,
    [BALL_LUXURY] = pokeball_particles_initialize_luxury_ball,
    [BALL_PREMIER] = pokeball_particles_initialize_premier_ball,
    [BALL_LOTUS] = pokeball_particles_initialize_master_ball,
    [BALL_QUICK] = pokeball_particles_initialize_nest_ball,
    [BALL_DUSK] = pokeball_particles_initialize_nest_ball,
};

oam_template pokeball_particles_oam_templates[NUM_POKEBALLS] = {
    [BALL_POKE] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_POKE),
    [BALL_GREAT] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_GREAT),
    [BALL_SAFARI] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_SAFARI),
    [BALL_ULTRA] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_ULTRA),
    [BALL_MASTER] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_MASTER),
    [BALL_NET] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_NET),
    [BALL_DIVE] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_DIVE),
    [BALL_NEST] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_NEST),
    [BALL_REPEAT] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_REPEAT),
    [BALL_TIMER] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_TIMER),
    [BALL_LUXURY] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_LUXURY),
    [BALL_PREMIER] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_PREMIER),
    [BALL_LOTUS] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_LOTUS),
    [BALL_QUICK] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_QUICK),
    [BALL_DUSK] = POKEBALL_PARTICLE_TEMPLATE_STANDARD(BALL_DUSK),
};

// Battlers are faded to this palette when sent out in this ball
color_t pokeball_open_fade_colors[] = {
    [BALL_POKE]    =  {.rgb = {.red = 31, .green = 22, .blue = 30}},
    [BALL_GREAT]    =  {.rgb = {.red = 16, .green = 23, .blue = 30}},
    [BALL_SAFARI]    =  {.rgb = {.red = 23, .green = 30, .blue = 20}},
    [BALL_ULTRA]    =  {.rgb = {.red = 31, .green = 31, .blue = 15}},
    [BALL_MASTER]    =  {.rgb = {.red = 23, .green = 20, .blue = 28}},
    [BALL_NET]    =  {.rgb = {.red = 21, .green = 31, .blue = 25}},
    [BALL_DIVE]    =  {.rgb = {.red = 12, .green = 25, .blue = 30}},
    [BALL_NEST]    =  {.rgb = {.red = 30, .green = 27, .blue = 10}},
    [BALL_REPEAT]    =  {.rgb = {.red = 31, .green = 24, .blue = 16}},
    [BALL_TIMER]    =  {.rgb = {.red = 29, .green = 30, .blue = 30}},
    [BALL_LUXURY]    =  {.rgb = {.red = 31, .green = 17, .blue = 10}},
    [BALL_PREMIER]    =  {.rgb = {.red = 31, .green = 9, .blue = 10}},
    [BALL_LOTUS]    =  {.rgb = {.red = 31, .green = 31, .blue = 10}},
    [BALL_QUICK]    =  {.rgb = {.red = 26, .green = 20, .blue = 4}},
    [BALL_DUSK]    =  {.rgb = {.red = 11, .green = 11, .blue = 1}},
};

void pokeball_load_gfx(u8 ball_idx) {
    if (oam_vram_get_tile(pokeball_oam_templates[ball_idx].tiles_tag) == 0xFFFF) {
        oam_load_graphic_using_heap(pokeball_gfxs + ball_idx);
        oam_load_palette_using_heap(pokeball_palettes + ball_idx);
    }
}