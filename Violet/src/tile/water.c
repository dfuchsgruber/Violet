#include "types.h"
#include "flags.h"
#include "tile/block.h"
#include "tile/coordinate.h"
#include "constants/flags.h"
#include "pokemon/virtual.h"
#include "constants/attacks.h"

extern u8 ow_script_surf_not_usable_stream_too_strong[];
extern u8 ow_script_prompt_surf[];
extern u8 ow_script_waterfall_not_available[];
extern u8 ow_script_prompt_waterfall[];

u8 *tile_trigger_water_scripts(position_t *tile_position, u8 behaviour, u8 player_facing) {
  (void)tile_position;
  (void)player_facing;
  if (behaviour_is_surf_strong_stream(behaviour) && player_pokemon_has_surf())
    return ow_script_surf_not_usable_stream_too_strong;
  if (checkflag(FRBADGE_4) && player_pokemon_has_surf() && player_can_use_surf_on_tile_faced())
    return ow_script_prompt_surf;
  if (behaviour_is_waterfall(behaviour)) {
    if (checkflag(FRBADGE_7) && player_can_use_waterfall_on_tile_faced())
      return ow_script_prompt_waterfall;
    else
      return ow_script_waterfall_not_available;
  }
  return NULL;
}

bool player_pokemon_has_waterfall() {
  for (int i = 0; i < player_pokemon_cnt; i++) {
    if (pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_SPECIES, 0)) {
      for (int j = 0; j < 4; j++) {
        if (pokemon_get_attribute(player_pokemon + i, (u16)(ATTRIBUTE_ATTACK1 + j), 0) == ATTACK_KASKADE)
          return true;
      }
    }
  }
  return false;
}