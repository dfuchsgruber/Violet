#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "oam.h"
#include "save.h"
#include "mega.h"
#include "debug.h"
#include "math.h"
#include "battle/gfx_effects.h"
#include "constants/pokemon_attributes.h"

extern const u8 gfx_mega_indicatorTiles[];
extern const u8 gfx_mega_indicatorPal[];

static sprite indicator_sprite = {
    .attr0 = ATTR0_SHAPE_VERTICAL, .attr1 = ATTR1_SIZE_8_16, .attr2 = ATTR2_PRIO(0),
};

static graphic indicator_graphic = {.tag = MEGA_INDICATOR_TAG, .sprite = gfx_mega_indicatorTiles, .size = 8 * 32 / 2};

static gfx_frame indicator_gfx_animation[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 2, .duration = 0}, {.data = GFX_ANIM_END},
};

static gfx_frame *indicator_gfx_animations[] = {
    indicator_gfx_animation + 0, indicator_gfx_animation + 2,
};

static void indicator_callback (oam_object *self) {
    u8 battler_idx = (u8)(self->private[0]);
    // Find the healthbar the indicator is attached to
    oam_object *healthbox = oams + battle_healthbox_oams[battler_idx];
    mega_evolution_t * mega_evolution = mega_evolution_get_by_mega_species(battlers[battler_idx].species);
    if (mega_evolution && !(healthbox->flags & OAM_FLAG_INVISIBLE)) {
        u8 animation = 0xFF;
        if (mega_evolution->type == MEGA_EVOLUTION) {
            animation = 0;
        } else if (mega_evolution->type == REGENT_EVOLUTION) {
            animation = 1;
        } else {
            derrf("Unknown mega evolution type %d for creating an indicator.\n", mega_evolution->type);
        }
        if (self->anim_number != animation) {
            self->anim_number = animation;
            oam_gfx_anim_init(self, 0);
        }

        // Mirror priority of healthbox
        self->final_oam.attr2 &= (u16)(~ATTR2_PRIO(3));
        int healthbox_priority = (healthbox->final_oam.attr0 >> 10) & 3;
        self->final_oam.attr2 |= (u16)ATTR2_PRIO(healthbox_priority);

        // Anchor indicator next to the "Lv." string
        if (battler_is_opponent(battler_idx))
            self->x = (s16)(healthbox->x + 42);
        else
            self-> x = (s16)(healthbox->x + 50);
        self->y = (s16)(healthbox->y - 2);

        // Calculate the length of the level string
        pokemon *p = (battler_is_opponent(battler_idx) ? opponent_pokemon : player_pokemon) + battler_idx_to_party_idx(battler_idx);
        for (int level = pokemon_get_attribute(p, ATTRIBUTE_LEVEL, 0); level > 0; level /= 10)
            self->x = (s16)(self->x - 5);

        // Copy shaking from the move selection (bouncing healthbox or damage)
        if (battle_sprite_data->healthbox_info[battler_idx].healthbox_is_bouncing) {
            oam_object *bounce = oams + battle_sprite_data->healthbox_info[battler_idx].healthbox_bounce_sprite_idx;
            self->y2 = (s16)(bounce->private[2] + sine((s16)(bounce->private[0]), (s16)(bounce->private[2])));      
        } else {
            // Search for a damage effect on this battler
            int bounce_effect_oam_idx;
            for (bounce_effect_oam_idx = 0; bounce_effect_oam_idx < 64; bounce_effect_oam_idx++) {
                if (oams[bounce_effect_oam_idx].callback == battle_healthbox_bounce_oam_at_damage_callback &&
                    oams[bounce_effect_oam_idx].private[1] == battle_healthbox_oams[battler_idx]) break;
            }
            if (bounce_effect_oam_idx < 64) {
                self->y2 = (s16)(oams[bounce_effect_oam_idx].private[0]);   
            } else {
                // No bounce effects, neither from selection nor damage
                self->y2 = 0;
            }
        }
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
    } else {
        self->flags |= OAM_FLAG_INVISIBLE;
    }
}

static oam_template indicator_template = {
    .tiles_tag = MEGA_INDICATOR_TAG, .pal_tag = MEGA_INDICATOR_TAG,
    .oam = &indicator_sprite, .animation = indicator_gfx_animations,
    .graphics = NULL, .rotscale = oam_rotscale_anim_table_null, .callback = indicator_callback,
};

void battle_create_mega_indicator(u8 battler_idx) {
    // Setup gfx
    if (oam_vram_allocation_table_get_index(MEGA_INDICATOR_TAG) == 0xFF)
        oam_load_graphic(&indicator_graphic);
    if (oam_palette_get_index(MEGA_INDICATOR_TAG) == 0xFF) {
        u8 pal_idx = oam_allocate_palette(MEGA_INDICATOR_TAG);
        pal_decompress(gfx_mega_indicatorPal, (u16)(256 + 16 * pal_idx), 32);
    }
    u8 oam_idx = oam_new_backward_search(&indicator_template, -8, -8, 0);
    oams[oam_idx].private[0] = battler_idx;
}