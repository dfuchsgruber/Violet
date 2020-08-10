#include "types.h"
#include "battle/state.h"
#include "battle/transition.h"
#include "trainer/virtual.h"
#include "trainer/trainer.h"
#include "save.h"
#include "battle/state.h"
#include "callbacks.h"
#include "dma.h"
#include "superstate.h"
#include "color.h"
#include "bios.h"
#include "debug.h"

static void battle_transition_phase_2_team_violet (u8 self);
static void battle_transition_phase_2_revolutionary (u8 self);

static u8 trainer_transitions_weak_opponent[] = {
    BATTLE_TRANSITION_SLIDING_POKEBALLS, BATTLE_TRANSITION_HORIZONTAL_CORRUGATE,
    BATTLE_TRANSITION_BLUR, BATTLE_TRANSITION_DISTORTED_WAVE,
};

static u8 trainer_transitions_strong_opponent[] = {
    BATTLE_TRANSITION_BLACK_DOODLES, BATTLE_TRANSITION_BIG_POKEBALL,
    BATTLE_TRANSITION_GRID_SQUARES, BATTLE_TRANSITION_FULLSCREEN_WAVE,
};

static bool battle_has_any_trainer_class(u8 trainerclass) {
    u8 trainerclass_first = trainers[trainer_vars.trainer_id].trainerclass;
    u8 trainerclass_second = trainerclass_first;
    if (fmem.trainers_cnt > 1) {
        trainerclass_second = trainers[fmem.trainer_varsB.trainer_id].trainerclass;
    }
    return trainerclass == trainerclass_first || trainerclass == trainerclass_second;
}

u8 battle_trainer_get_transition_type() {
    if (battle_has_any_trainer_class(TRAINERCLASS_TEAM_VIOLET))
        return BATTLE_TRANSITION_TEAM_VIOLET;
    if (battle_has_any_trainer_class(TRAINERCLASS_REVOLUTIONAER))
        return BATTLE_TRANSITION_REVOLUTIONARY;

    u8 transition_type = battle_transition_type_get_by_map();
    dprintf("Trainer transition type is %d\n", transition_type);
    int player_total_level;
    int opponent_total_level;
    if (fmem.trainers_cnt > 1) {
        player_total_level = player_pokemon_get_total_level(2);
        opponent_total_level = trainer_pokemon_get_total_level(trainer_vars.trainer_id, 1) +
            trainer_pokemon_get_total_level(fmem.trainer_varsB.trainer_id, 1);

    } else {
        if (trainers[trainer_vars.trainer_id].battle_state & BATTLE_DOUBLE) {
            player_total_level = player_pokemon_get_total_level(2);
            opponent_total_level = trainer_pokemon_get_total_level(trainer_vars.trainer_id, 2); 
        } else {
            player_total_level = player_pokemon_get_total_level(1);
            opponent_total_level = trainer_pokemon_get_total_level(trainer_vars.trainer_id, 1);
        }
    }
    if (opponent_total_level < player_total_level) {
        return trainer_transitions_weak_opponent[transition_type];
    } else {
        return trainer_transitions_strong_opponent[transition_type];
    }
}

static bool battle_transition_phase_2_initialize_pause32(big_callback *self) {
    self->params[9] = 32;
    ++self->params[0];
    return true;
};

static bool battle_transition_phase_2_pause(big_callback *self) {
    if (self->params[9] == 0) {
        ++self->params[0];
        return true;
    }
    --self->params[9];
    return false;
}

extern u16 gfx_battle_transition_team_violet_logoMap[20][32];
extern u8 gfx_battle_transition_team_violet_logoTiles[];
extern color_t gfx_battle_transition_team_violet_logoPal[16];

static bool battle_transition_team_violet_phase_2_initialize_gfx(big_callback *self) {
    u16 *tilemap = 0;
    void *tileset = 0;
    battle_transition_get_bg0_tilemap_and_tileset(&tilemap,&tileset);
    cpuset(gfx_battle_transition_team_violet_logoTiles, tileset, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(0x2000));
    pal_copy(gfx_battle_transition_team_violet_logoPal, 15 * 16, sizeof(gfx_battle_transition_team_violet_logoPal));
    ++self->params[0];
    return false;
}

static bool battle_transition_team_violet_phase_2_initialize_tilemap_and_wave (big_callback *self){
    s16 *theta = (s16*)(self->params + 4);
    s16 *amplitude = (s16*)(self->params + 5);
    u16 *tilemap = 0;
    void *tileset = 0;
    battle_transition_get_bg0_tilemap_and_tileset(&tilemap, &tileset);
    cpuset(gfx_battle_transition_team_violet_logoMap, tilemap, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(sizeof(gfx_battle_transition_team_violet_logoMap)));
    // for (int i = 0; i < 32 * 20; i++)
    //     tilemap[i] = ((u16*)gfx_battle_transition_team_violet_logoMap)[i];
    battle_transition_generate_wave(dma0_scanline_frames[0], 0, *theta, 132, *amplitude, 160);
    ++self->params[0];
    return false;
}

static bool battle_transition_team_violet_phase_2_circle_effect(big_callback *self) {
    s16 *radius = (s16*) (self->params + 1);
    s16 *delta_radius = (s16*) (self->params + 2);
    battle_transition_state->vblank_dma = false;
    if (*delta_radius < 2048) {
        *delta_radius = (s16)(*delta_radius + 256);
    }
    if (*radius) {
        *radius = (s16) MAX(0, *radius - (*delta_radius >> 8));
    }
    battle_transition_generate_circle(dma0_scanline_frames[0], 120, 80, *radius);
    if (*radius == 0) {
        *((u16*) 0x040000ba ) &= 0x45ff; // stops the dma0
        battle_transition_fade_pals_to_black();
        big_callback_delete(big_callback_get_id(battle_transition_phase_2_team_violet));
    }
    if (self->params[3] == 0) {
        self->params[3] = 1;
        vblank_handler_set(battle_transition_big_pokeball_vblank_handler_after_circle);
    }
    ++battle_transition_state->vblank_dma;
    return false;
}


static bool (*battle_transition_phase_2_team_violet_steps[])(big_callback *) = {
    battle_transition_big_pokeball_phase_2_initialize,
    battle_transition_team_violet_phase_2_initialize_gfx,
    battle_transition_team_violet_phase_2_initialize_tilemap_and_wave,
    battle_transition_big_pokeball_phase_2_wave_1_increment_eva,
    battle_transition_big_pokeball_phase_2_wave_2_increment_evb,
    battle_transition_big_pokeball_phase_2_wave_3,
    battle_transition_phase_2_initialize_pause32,
    battle_transition_phase_2_pause,
    battle_transition_team_violet_phase_2_circle_effect,
};

static void battle_transition_phase_2_team_violet (u8 self) {
    big_callback *big_cb = big_callbacks + self;
    while (battle_transition_phase_2_team_violet_steps[big_cb->params[0]](big_cb));
}


extern u16 gfx_battle_transition_revolutionary_logoMap[20][32];
extern u8 gfx_battle_transition_revolutionary_logoTiles[];
extern color_t gfx_battle_transition_revolutionary_logoPal[16];

static bool battle_transition_revolutionary_phase_2_initialize_gfx(big_callback *self) {
    u16 *tilemap = 0;
    void *tileset = 0;
    battle_transition_get_bg0_tilemap_and_tileset(&tilemap,&tileset);
    cpuset(gfx_battle_transition_revolutionary_logoTiles, tileset, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(0x2000));
    pal_copy(gfx_battle_transition_revolutionary_logoPal, 15 * 16, sizeof(gfx_battle_transition_revolutionary_logoPal));
    ++self->params[0];
    return false;
}

static bool battle_transition_revolutionary_phase_2_initialize_tilemap_and_wave (big_callback *self){
    s16 *theta = (s16*)(self->params + 4);
    s16 *amplitude = (s16*)(self->params + 5);
    u16 *tilemap = 0;
    void *tileset = 0;
    battle_transition_get_bg0_tilemap_and_tileset(&tilemap, &tileset);
    cpuset(gfx_battle_transition_revolutionary_logoMap, tilemap, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(sizeof(gfx_battle_transition_revolutionary_logoMap)));
    // for (int i = 0; i < 32 * 20; i++)
    //     tilemap[i] = ((u16*)gfx_battle_transition_revolutionary_logoMap)[i];
    battle_transition_generate_wave(dma0_scanline_frames[0], 0, *theta, 132, *amplitude, 160);
    ++self->params[0];
    return false;
}

static bool battle_transition_revolutionary_phase_2_circle_effect(big_callback *self) {
    s16 *radius = (s16*) (self->params + 1);
    s16 *delta_radius = (s16*) (self->params + 2);
    battle_transition_state->vblank_dma = false;
    if (*delta_radius < 2048) {
        *delta_radius = (s16)(*delta_radius + 256);
    }
    if (*radius) {
        *radius = (s16) MAX(0, *radius - (*delta_radius >> 8));
    }
    battle_transition_generate_circle(dma0_scanline_frames[0], 120, 80, *radius);
    if (*radius == 0) {
        *((u16*) 0x040000ba ) &= 0x45ff; // stops the dma0
        battle_transition_fade_pals_to_black();
        big_callback_delete(big_callback_get_id(battle_transition_phase_2_revolutionary));
    }
    if (self->params[3] == 0) {
        self->params[3] = 1;
        vblank_handler_set(battle_transition_big_pokeball_vblank_handler_after_circle);
    }
    ++battle_transition_state->vblank_dma;
    return false;
}


static bool (*battle_transition_phase_2_revolutionary_steps[])(big_callback *) = {
    battle_transition_big_pokeball_phase_2_initialize,
    battle_transition_revolutionary_phase_2_initialize_gfx,
    battle_transition_revolutionary_phase_2_initialize_tilemap_and_wave,
    battle_transition_big_pokeball_phase_2_wave_1_increment_eva,
    battle_transition_big_pokeball_phase_2_wave_2_increment_evb,
    battle_transition_big_pokeball_phase_2_wave_3,
    battle_transition_phase_2_initialize_pause32,
    battle_transition_phase_2_pause,
    battle_transition_revolutionary_phase_2_circle_effect,
};

static void battle_transition_phase_2_revolutionary (u8 self) {
    big_callback *big_cb = big_callbacks + self;
    while (battle_transition_phase_2_revolutionary_steps[big_cb->params[0]](big_cb));
}

void (*battle_transition_phase_1_callbacks[BATTLE_TRANSITION_COUNT])(u8) = {
    [0 ... BATTLE_TRANSITION_COUNT - 1] = battle_transition_phase_1_blink
};


void (*battle_transition_phase_2_callbacks[BATTLE_TRANSITION_COUNT])(u8) = {
    [BATTLE_TRANSITION_BLUR] = battle_transition_phase_2_blur,
    [BATTLE_TRANSITION_DISTORTED_WAVE] = battle_transition_phase_2_distorted_wave,
    [BATTLE_TRANSITION_HORIZONTAL_CORRUGATE] = battle_transition_phase_2_horizontal_corrugate,
    [BATTLE_TRANSITION_BIG_POKEBALL] = battle_transition_phase_2_big_pokeball,
    [BATTLE_TRANSITION_SLIDING_POKEBALLS] = battle_transition_phase_2_sliding_pokeballs,
    [BATTLE_TRANSITION_CLOCKWISE_BLACKFADE] = battle_transition_phase_2_clockwise_blackfade,
    [BATTLE_TRANSITION_FULLSCREEN_WAVE] = battle_transition_phase_2_fullscreen_wave,
    [BATTLE_TRANSITION_BLACK_WAVE_TO_RIGHT] = battle_transition_phase_2_black_wave_to_right,
    [BATTLE_TRANSITION_SLICED_SCREEN] = battle_transition_phase_2_sliced_screen,
    [BATTLE_TRANSITION_WHITEFADE_IN_STRIPES] = battle_transition_phase_2_whitefade_in_stripes,
    [BATTLE_TRANSITION_GRID_SQUARES] = battle_transition_phase_2_grid_squares,
    [BATTLE_TRANSITION_BLACK_DOODLES] = battle_transition_phase_2_black_doodles,
    [BATTLE_TRANSITION_LORELEI] = battle_transition_phase_2_lorelei,
    [BATTLE_TRANSITION_BRUNO] = battle_transition_phase_2_bruno,
    [BATTLE_TRANSITION_AGATHA] = battle_transition_phase_2_agatha,
    [BATTLE_TRANSITION_LANCE] = battle_transition_phase_2_lance,
    [BATTLE_TRANSITION_BLUE] = battle_transition_phase_2_blue,
    [BATTLE_TRANSITION_ANTI_CLOCKWISE_SPIRAL] = battle_transition_phase_2_anti_clockwise_spiral,
    [BATTLE_TRANSITION_TEAM_VIOLET] = battle_transition_phase_2_team_violet,
    [BATTLE_TRANSITION_REVOLUTIONARY] = battle_transition_phase_2_revolutionary,
};