#include "types.h"
#include "oam.h"
#include "mega.h"
#include "battle/attack.h"
#include "battle/state.h"
#include "save.h"
#include "mega.h"
#include "constants/species.h"
#include "debug.h"
#include "battle/battler.h"
#include "callbacks.h"
#include "pokemon/names.h"
#include "text.h"

extern const u8 gfx_mega_sparkleTiles[];
extern const u8 gfx_regent_groudon_sparkleTiles[];
extern const u8 gfx_regent_kyogre_sparkleTiles[];
extern const u8 gfx_regent_rayquaza_sparkleTiles[];
extern const u8 gfx_mega_sparklePal[];
extern const u8 gfx_regent_kyogre_sparklePal[]; // All regent sparkle gfxs use the same palette
extern const u8 gfx_mega_rayPal[];

#define MEGA_TAG 43210
#define REGENT_TAG 43211

static graphic graphic_mega_sparkle = {
    .sprite = gfx_mega_sparkleTiles, .tag = MEGA_TAG, .size = 32 * 32 / 2,
};
static graphic graphic_regent_groudon_sparkle = {
    .sprite = gfx_mega_sparkleTiles, .tag = REGENT_TAG, .size = 32 * 32 / 2,
};
static graphic graphic_regent_kyogre_sparkle = {
    .sprite = gfx_mega_sparkleTiles, .tag = REGENT_TAG, .size = 32 * 32 / 2,
};
static graphic graphic_regent_rayquaza_sparkle = {
    .sprite = gfx_mega_sparkleTiles, .tag = REGENT_TAG, .size = 32 * 32 / 2,
};
static palette palette_mega_sparkle = {
    .pal = gfx_mega_sparklePal, .tag = MEGA_TAG,
};
static palette palette_regent_sparkle = {
    .pal = gfx_regent_kyogre_sparklePal, .tag = REGENT_TAG,
};


static sprite sparkle_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE | ATTR0_MODE_SEMI_TRANSPARENT, .attr1 = ATTR1_SIZE_32_32, 
    .attr2 = ATTR2_PRIO(2),
};

oam_template battle_animation_mega_sparkle_template = {
    .tiles_tag = MEGA_TAG, .pal_tag = MEGA_TAG, .oam = &sparkle_sprite,
    .animation = oam_gfx_anim_table_null, .graphics = NULL, .rotscale = oam_rotscale_anim_table_null,
    .callback = battle_animation_oam_particle_emission_above_battler_callback,
};

oam_template battle_animation_regent_sparkle_template = {
    .tiles_tag = REGENT_TAG, .pal_tag = REGENT_TAG, .oam = &sparkle_sprite,
    .animation = oam_gfx_anim_table_null, .graphics = NULL, .rotscale = oam_rotscale_anim_table_null,
    .callback = battle_animation_oam_particle_emission_above_battler_callback,
};

void battle_animation_mega_callback_load_gfx(u8 self) {
    u8 battler_idx = battler_attacking_order[MEGA_STATE.mega_action_current_slot];
    mega_evolution_t *mega_evolution = mega_evolution_get_by_mega_species(battlers[battler_idx].species);
    graphic *g = NULL; palette *p = NULL;
    if (mega_evolution->type == MEGA_EVOLUTION){
        g = &graphic_mega_sparkle;
        p = &palette_mega_sparkle;
    } 
    else {
        p = &palette_regent_sparkle;
        switch (mega_evolution->species) {
            case POKEMON_GROUDON:
                g = &graphic_regent_groudon_sparkle;
                break;
            case POKEMON_KYOGRE:
                g = &graphic_regent_kyogre_sparkle;
                break;
            case POKEMON_RAYQUAZA:
                g = &graphic_regent_rayquaza_sparkle;
                break;
            default:
                derrf("Unknown species for regent evolution %d\n", mega_evolution->species);
                break;
        }
    }
    oam_load_graphic(g);
    battle_animation_load_oam_palette(p);
    battle_animation_register_gfx_tag((u16)(g->tag - 10000));
    // Delay one frame to wait for decompression of gfxs
    battle_animation_delay = 1;
    battle_animation_handler = battle_animation_handler_delay;
    battle_animation_big_callback_delete(self);
}

void battle_animation_mega_intialize_vars(u8 self) {
    u8 battler_idx = battler_attacking_order[MEGA_STATE.mega_action_current_slot];
    battle_animation_user = battler_idx;
    battle_animation_target = battler_idx;
    battle_animation_big_callback_delete(self);
}

void battle_animation_mega_modify_particle_pals(u8 self) {
    // This is somewhat hacky, but I am too lazy to build new particle structures, so we just modify the existing ones
    u8 pal_idx = oam_palette_get_index(0x27E3);
    if (pal_idx != 0xFF) {
        pal_decompress(gfx_mega_rayPal, (u16)(256 + 16 * pal_idx), 32);
    }
    pal_idx = oam_palette_get_index(0x27E4);
    if (pal_idx != 0xFF) {
        pal_decompress(gfx_mega_rayPal, (u16)(256 + 16 * pal_idx), 32);
    }
    battle_animation_big_callback_delete(self);
}

void battle_animation_alpha_blending_callback(u8 self);


static void battle_animation_update_battler_callback_step(u8 self) {
    u16 *state = big_callbacks[self].params + 10;
    u8 battler_idx = (u8)(big_callbacks[self].params[12]);
    u8 oam_idx = battler_oams[battler_idx];
    dprintf("Update state %d\n", *state);
    switch (*state) {
        case 0: {
            strcpy(buffer2, pokemon_names[battlers[battler_idx].species]);
            if (battle_sprite_data->sprite_info[battler_idx].behind_substitute)
                *state = 5; // Don't update the sprite when behind a substitute...
            else {
                big_callbacks[self].params[11] = (u16)(oams[oam_idx].x);
                oams[oam_idx].x = -64; // Off-screen
                (*state)++;
            }
            break;
        }
        case 1:
            battler_load_gfx(battler_idx, true, oam_idx);
            (*state)++;
            break;
        case 2: {
            oams[oam_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
            u8 cb_idx = big_callback_new(battle_animation_battler_gfx_to_oam, 5);
            big_callbacks[cb_idx].params[0] = 0;
            big_callbacks[cb_idx].params[2] = battler_idx;
            (*state)++;
            break;
        }
        case 3:
            if (!big_callback_is_active(battle_animation_battler_gfx_to_oam))
                (*state)++;
            break;
        case 4:
            oams[oam_idx].x = (s16)(big_callbacks[self].params[11]);
            FALL_THROUGH;
        default:
            battle_animation_big_callback_delete(self);
            break;
    }
}

void battle_animation_update_battler_callback (u8 self) {
    u8 battler_idx = 0xFF;
    switch (battle_animation_arguments[0]) {
        case 0: battler_idx = battle_animation_user; break;
        case 1: battler_idx = battle_animation_target; break;
        case 2: battler_idx = PARTNER(battle_animation_user); break;
        case 3: battler_idx = PARTNER(battle_animation_target); break;
    }
    if (battler_idx == 0xFF) {
        battle_animation_big_callback_delete(self);
    } else {
        big_callbacks[self].params[10] = 0;
        big_callbacks[self].params[12] = battler_idx;
        big_callbacks[self].function = battle_animation_update_battler_callback_step;
        battle_animation_update_battler_callback_step(self);
    }
}