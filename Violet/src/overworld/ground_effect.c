#include "types.h"
#include "overworld/ground_effect.h"
#include "overworld/npc.h"
#include "tile/block.h"
#include "constants/block_behaviour.h"
#include "debug.h"
#include "overworld/sprite.h"
#include "overworld/effect.h"

static void (*ground_effects[NUM_GROUND_EFFECTS])(npc *, oam_object *) = {
    [GROUND_EFFECT_FLAG_TALL_GRASS_ON_SPAWN] = ground_effect_tall_grass_on_spawn,
    [GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE] = ground_effect_tall_grass_on_move,
    [GROUND_EFFECT_FLAG_LONG_GRASS_ON_SPAWN] = ground_effect_long_grass_on_spawn,
    [GROUND_EFFECT_FLAG_LONG_GRASS_ON_MOVE] = ground_effect_long_grass_on_move,
    [GROUND_EFFECT_FLAG_ICE_REFLECTION] = ground_effect_ice_reflection,
    [GROUND_EFFECT_FLAG_REFLECTION] = ground_effect_reflection,
    [GROUND_EFFECT_FLAG_SHALLOW_FLOWING_WATER] = ground_effect_shallow_flowing_water,
    [GROUND_EFFECT_FLAG_SAND] = ground_effect_sand,
    [GROUND_EFFECT_FLAG_DEEP_SAND] = ground_effect_deep_sand,
    [GROUND_EFFECT_FLAG_RIPPLES] = ground_effect_ripples,
    [GROUND_EFFECT_FLAG_PUDDLE] = ground_effect_puddle,
    [GROUND_EFFECT_FLAG_SAND_PILE] = ground_effect_sand_pile,
    [GROUND_EFFECT_FLAG_LAND_IN_TALL_GRASS] = ground_effect_land_in_tall_grass,
    [GROUND_EFFECT_FLAG_LAND_IN_LONG_GRASS] = ground_effect_land_in_long_grass,
    [GROUND_EFFECT_FLAG_LAND_IN_SHALLOW_WATER] = ground_effect_land_in_shallow_water,
    [GROUND_EFFECT_FLAG_LAND_IN_DEEP_WATER] = ground_effect_land_in_deep_water,
    [GROUND_EFFECT_FLAG_LAND_ON_NORMAL_GROUND] = ground_effect_land_on_normal_ground,
    [GROUND_EFFECT_FLAG_SHORT_GRASS] = ground_effect_short_grass,
    [GROUND_EFFECT_FLAG_HOT_SPRINGS] = ground_effect_hot_springs,
    [GROUND_EFFECT_FLAG_SEAWEED] = ground_effect_seaweed,
    [GROUND_EFFECT_FLAG_SNOW] = ground_effect_snow,
};

void ground_effects_do_flagged(npc *n, oam_object *o, u32 flags) {
    if (n->overworld_id == OVERWORLD_IDX_VIEWPORT && n->flags.invisible)
        return;
    for (size_t i = 0; i < NUM_GROUND_EFFECTS; i++, flags >>= 1) {
        if (flags & 1) {
            ground_effects[i](n, o);
        }
    }
}

void ground_effect_get_tracks(npc *n, u32 *flags) {
    if (behaviour_is_sand(n->behavior_tile_previous)) {
        *flags |= 1 << GROUND_EFFECT_FLAG_SAND;
    }
    if (n->behavior_tile_previous == MB_SNOW) {
        DEBUG("Set Snow.\n");
        *flags |= 1 << GROUND_EFFECT_FLAG_SNOW;
    }
}

static void ground_effect_snow_tracks_none (npc *n, oam_object *o) {(void)n; (void)o; }

static void ground_effect_snow_tracks_normal(npc *n, oam_object *o) {
    (void)o;
    overworld_effect_state.x = n->from_x;
    overworld_effect_state.y = n->from_y;
    overworld_effect_state.height = 149;
    overworld_effect_state.bg_priority = 2;
    overworld_effect_state.target_ow_and_their_map = n->direction.facing;
    overworld_effect_new(OVERWORLD_EFFECT_SNOW_TRACKS);

}

static void ground_effect_snow_tracks_bike(npc *n, oam_object *o) {
    (void)n; (void)o; 
}

static void (*ground_effect_snow_tracks[])(npc *, oam_object *) = {
    [0] = ground_effect_snow_tracks_none,
    [1] = ground_effect_snow_tracks_normal,
    [2] = ground_effect_snow_tracks_bike,
};

void ground_effect_snow(npc *n, oam_object *o) {
    overworld_sprite *sprite = overworld_get_by_npc(n);
    ground_effect_snow_tracks[MIN(ARRAY_COUNT(ground_effect_snow_tracks), sprite->tracks)](n, o);
}