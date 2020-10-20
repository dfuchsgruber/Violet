#include "types.h"
#include "oam.h"
#include "battle/attack.h"

static void battle_animation_oam_callback_ancient_power_rock_arbitrary_position(oam_object *self) {
    oam_gfx_anim_start(self, (u8)battle_animation_arguments[4]);
    self->x = (s16)(battle_animation_arguments[0]);
    self->y = (s16)(battle_animation_arguments[1]);
    self->private[2] = (u16)(self->x); // No x translation
    self->private[4] = battle_animation_arguments[2];
    self->private[0] = battle_animation_arguments[3]; // Duration
    self->callback = battle_animation_oam_callback_initialize_linear_translation;
    battle_animation_set_continuation(self, battle_animation_oam_delete);
}

extern sprite battle_animation_sprite_ancient_power;
extern gfx_frame *battle_animation_gfx_animations_ancient_power[];

oam_template battle_animation_oam_template_ancient_power_rock_arbitrary_position = {
    .tiles_tag = 0x274A, .pal_tag = 0x274A, .oam = &battle_animation_sprite_ancient_power,
    .animation = battle_animation_gfx_animations_ancient_power, .graphics = NULL,
    .rotscale = oam_rotscale_anim_table_null, .callback = battle_animation_oam_callback_ancient_power_rock_arbitrary_position,
};

static void battle_animation_oam_callback_root_arbitrary_position(oam_object *self) {
    if (self->private[0] == 0) {
        self->x = (s16)(battle_animation_arguments[0]);
        self->y = (s16)(battle_animation_arguments[1]);
        self->priority_on_layer = (u8)((s16)battle_animation_arguments[2] + 30);
        oam_gfx_anim_start(self, (u8)battle_animation_arguments[3]);
        self->private[2] = battle_animation_arguments[4]; // Duration
    }
    self->callback = battle_animation_oam_callback_roots_flicker_out;
}

extern gfx_frame *battle_animation_gfx_animations_roots[];

oam_template battle_animation_oam_template_root_arbitrary_position = {
    .tiles_tag = 0x27EF, .pal_tag = 0x27EF, .oam = &battle_animation_sprite_ancient_power,
    .animation = battle_animation_gfx_animations_roots, .graphics = NULL,
    .rotscale = oam_rotscale_anim_table_null, .callback = battle_animation_oam_callback_root_arbitrary_position,
};
