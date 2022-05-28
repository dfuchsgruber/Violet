#ifndef H_OVERWORLD_GROUND_EFFECT
#define H_OVERWORLD_GROUND_EFFECT

#include "types.h"
#include "overworld/npc.h"
#include "oam.h"
#include "constants/overworld/ground_effects.h"

void ground_effect_tall_grass_on_spawn (npc *n, oam_object *o);
void ground_effect_tall_grass_on_move (npc *n, oam_object *o);
void ground_effect_long_grass_on_spawn (npc *n, oam_object *o);
void ground_effect_long_grass_on_move (npc *n, oam_object *o);
void ground_effect_ice_reflection (npc *n, oam_object *o);
void ground_effect_reflection (npc *n, oam_object *o);
void ground_effect_shallow_flowing_water (npc *n, oam_object *o);
void ground_effect_sand (npc *n, oam_object *o);
void ground_effect_deep_sand (npc *n, oam_object *o);
void ground_effect_ripples (npc *n, oam_object *o);
void ground_effect_puddle (npc *n, oam_object *o);
void ground_effect_sand_pile (npc *n, oam_object *o);
void ground_effect_land_in_tall_grass (npc *n, oam_object *o);
void ground_effect_land_in_long_grass (npc *n, oam_object *o);
void ground_effect_land_in_shallow_water (npc *n, oam_object *o);
void ground_effect_land_in_deep_water (npc *n, oam_object *o);
void ground_effect_land_on_normal_ground (npc *n, oam_object *o);
void ground_effect_short_grass (npc *n, oam_object *o);
void ground_effect_hot_springs (npc *n, oam_object *o);
void ground_effect_seaweed (npc *n, oam_object *o);
void ground_effect_snow (npc *n, oam_object *o);


#endif