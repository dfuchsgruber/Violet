#ifndef H_BATTLE_GFX_EFFECTS
#define H_BATTLE_GFX_EFFECTS

#include "types.h"
#include "oam.h"

/**
 * Callback for an oam that applies the boucing effect to a healthbox when a battler is hit.
 * @param self self-reference
 **/
void battle_healthbox_bounce_oam_at_damage_callback (oam_object *self);

#endif