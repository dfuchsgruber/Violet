#ifndef H_MAP_CLOUD
#define H_MAP_CLOUD

#include "types.h"

#define OAM_TAG_CLOUD_UPSTREAM 0x6561

enum {
    CLOUD_UPSTREAM_BOTTOM = 0,
    CLOUD_UPSTREAM_MID,
    CLOUD_UPSTREAM_TOP,
    CLOUD_UPSTREAM_TOP_2,
    CLOUD_UPSTREAM_NUM_OAMS,
};

enum {
    CLOUD_UPSTREAM_ANIM_BIG_RING,
    CLOUD_UPSTREAM_ANIM_NORMAL_RING,
    CLOUD_UPSTREAM_ANIM_SMALL_RING,
    CLOUD_UPSTREAM_ANIM_NO_RING,
    CLOUD_UPSTREAM_ANIM_BIG_RING_BG,
    CLOUD_UPSTREAM_ANIM_NORMAL_RING_BG,
    CLOUD_UPSTREAM_ANIM_SMALL_RING_BG,
    CLOUD_UPSTREAM_ANIM_STATIC,
    CLOUD_UPSTREAM_ANIM_STATIC_BG,
};


typedef struct {
    s16 x;
    s16 y;
    u8 bank;
    u8 map_idx;
    u8 oam_idx_controller;
    u8 oam_idxs[CLOUD_UPSTREAM_NUM_OAMS][2]; // bottom, mid, up
    u8 delay;
    u8 y_movement_delay;
    void (*contunation)();
} oam_cloud_upstream_state_t;

/**
 * Creates oams for all cloud upstreams on the current map
 **/
void map_cloud_upstream_new();

/**
 * Creates the cloud upstream whirlwind effect at a certain position.
 * @param x x coordinate (not 7 shifted)
 * @param y y coordinate (not 7 shifted)
 * @return the state of the cloud upstream, that is automatically freed if the upstream animation ends
 **/
oam_cloud_upstream_state_t *map_cloud_upstream_whirlwind_at(s16 x, s16 y);

#endif