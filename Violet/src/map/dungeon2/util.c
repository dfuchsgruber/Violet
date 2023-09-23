#include "types.h"
#include "dungeon/dungeon2.h"
#include "dungeon/callback.h"
#include "prng.h"
#include "map/header.h"
#include "save.h"
#include "agbmemory.h"
#include "bios.h"
#include "vars.h"
#include "constants/person_behaviours.h"
#include "constants/person_script_stds.h"
#include "constants/overworld/misc.h"
#include "overworld/sprite.h"
#include "overworld/script.h"
#include "flags.h"
#include "debug.h"
#include "hash.h"
#include "callbacks.h"

bool dungeon2_find_empty_space(int *space_x, int *space_y, u8 *center_node, int nodes[][2], int width, int height, 
    const u8 *map, dungeon_generator2 *dg2) {
    // For each node, see if we can expand the window arround it
    int valid_positions[dg2->nodes][2];
    u8 num_valid_positions = 0;
    for (u8 node_idx = 0; node_idx < dg2->nodes; node_idx++) {
        
        int x = nodes[node_idx][0] - (width - width / 2);
        int y = nodes[node_idx][1] - (height - height / 2);
        bool valid_node = true;
        for (int i = 0; i < width && valid_node; i++) {
            for (int j = 0; j < height && valid_node; j++) {
                if (map[(y + j) * dg2->width + x + i] != DG2_SPACE)
                    valid_node = false;
            }
        }
        if (valid_node) {
            valid_positions[num_valid_positions][0] = x;
            valid_positions[num_valid_positions][1] = y;
            num_valid_positions++;
        }
    }
    if (num_valid_positions) {
        *center_node = (u8)dungeon2_rnd_16(dg2) % num_valid_positions;
        *space_x = valid_positions[*center_node][0];
        *space_y = valid_positions[*center_node][1];
        return true;
    }
    return false;
}

bool dungeon2_find_empty_space_for_pattern(int *space_x, int *space_y, u8 *center_node, int nodes[][2], 
        const map_footer_t *pattern, const u8 *map, dungeon_generator2 *dg2) {
    return dungeon2_find_empty_space(space_x, space_y, center_node, nodes, (int)pattern->width, (int)pattern->height, map, dg2);
}

void dungeon2_place_pattern(int pattern_x, int pattern_y, const map_footer_t *pattern, dungeon_generator2 *dg2) {
    DEBUG("Place pattern with dimensions %d,%d at %d,%d\n", pattern->width, pattern->height, pattern_x, pattern_y);
    for (u8 i = 0; i < pattern->width; i++) {
        for (u8 j = 0; j < pattern->height; j++) {
            u16 *block = (u16*) pattern->map + (j * pattern->width + i);
            // block_set_by_pos((s16)(pattern_x + i + 7 - (int)(pattern->width / 2)), (s16)(pattern_y + j + 7 - (int)(pattern->height / 2)), *block);
            save1->dungeon_blocks[(pattern_y + j - (int)(pattern->height / 2)) * dg2->width + pattern_x + i - (int)(pattern->width / 2)] = *block;

        }
    }
}

extern const u8 ow_script_dungeon_encounter[];
extern const u8 ow_script_dungeon_trainer_0[];
extern const u8 ow_script_dungeon_trainer_1[];
extern const u8 ow_script_dungeon_trainer_2[];
extern const u8 ow_script_dungeon_trainer_3[];
extern const u8 ow_script_dungeon_trainer_4[];
extern const u8 ow_script_dungeon_trainer_5[];
extern const u8 ow_script_dungeon_trainer_6[];
extern const u8 ow_script_dungeon_trainer_7[];

static const u8 *const dungeon2_trainer_scripts[4][2] = {
    {ow_script_dungeon_trainer_0, ow_script_dungeon_trainer_4}, 
    {ow_script_dungeon_trainer_1, ow_script_dungeon_trainer_5}, 
    {ow_script_dungeon_trainer_2, ow_script_dungeon_trainer_6},
    {ow_script_dungeon_trainer_3, ow_script_dungeon_trainer_7},
};

u16 dungeon2_seeded_rnd16(dungeon_generator2 *dg2, u32 seed) {
    gp_rng = hash_sequence(&(dg2->initial_seed), 1, seed);
    u16 r =  gp_rnd16();
    return r;
}


u8 dungeon2_get_number_trainers(dungeon_generator2 *dg2) {
    u8 num_trainers = (u8)(dungeon2_seeded_rnd16(dg2, DG2_RANDOM_SEED_NUM_TRAINERS) % (DG2_MAX_NUM_TRAINERS + 1));
    // DEBUG("Dungeon has %d trainers\n", num_trainers);
    return num_trainers;
}

u8 dungeon2_get_number_items(dungeon_generator2 *dg2) {
    u8 num_trainers = dungeon2_get_number_trainers(dg2);
    int max_num_items = MAX(0, MIN(dg2->nodes - DG2_NODE_TRAINER_OR_ITEM - num_trainers, DG2_MAX_NUM_TRAINER_OR_ITEM_NODES - num_trainers));
    u8 num_items = (u8)(dungeon2_seeded_rnd16(dg2, DG2_RANDOM_SEED_NUM_ITEMS) % (max_num_items + 1));
    // DEBUG("Dungeon has %d (%d possible) items\n", num_items, max_num_items);
    return num_items;
}

int dungeon2_node_trainer_or_item_get_type(dungeon_generator2 *dg2, int node_idx) {
    if (node_idx < DG2_NODE_TRAINER_OR_ITEM || node_idx >= dg2->nodes || node_idx >= DG2_NODE_TRAINER_OR_ITEM + DG2_MAX_NUM_TRAINER_OR_ITEM_NODES)
        return DG2_NODE_TRAINER_OR_ITEM_TYPE_NOT_VALID;
    u8 num_trainers = dungeon2_get_number_trainers(dg2);
    u8 num_items = dungeon2_get_number_items(dg2);
    if (node_idx - DG2_NODE_TRAINER_OR_ITEM < num_trainers)
        return DG2_NODE_TRAINER_OR_ITEM_TYPE_TRAINER;
    else if (node_idx - DG2_NODE_TRAINER_OR_ITEM - num_trainers < num_items)
        return DG2_NODE_TRAINER_OR_ITEM_TYPE_ITEM;
    else
        return DG2_NODE_TRAINER_OR_ITEM_TYPE_NONE;
}

void dungeon2_initialize_std_events(dungeon_generator2 *dg2, u16 (*item_picker)(dungeon_generator2*)) {
    // Clear all dynamic person events
    int zero = 0;
    cpuset(&zero, &(dynamic_persons), CPUSET_FILL | CPUSET_HALFWORD |
        CPUSET_HALFWORD_SIZE(NUM_DYNAMIC_PERSONS * sizeof(map_event_person)));

    dynamic_map_event_header.script_cnt = 0;
    dynamic_map_event_header.signpost_cnt = 0;
    dynamic_map_event_header.persons = dynamic_persons;
    dynamic_map_event_header.warps = dynamic_warps;

    int (*nodes)[2] = save1->dungeon_nodes;

    u8 num_persons = 0;
    u8 num_trainers = 0;
    u8 num_warps = 0;

    // Initialize the first warp to the entrance, i.e. node 0
    dynamic_warps[num_warps].x = (s16)(nodes[DG2_NODE_PLAYER_WARP][0]);
    dynamic_warps[num_warps].y = (s16)(nodes[DG2_NODE_PLAYER_WARP][1]);
    num_warps++;

    // Initialize the static encounter
    dynamic_persons[num_persons].x = (s16)(nodes[DG2_NODE_STATIC_ENCOUNTER][0]);
    dynamic_persons[num_persons].y = (s16)(nodes[DG2_NODE_STATIC_ENCOUNTER][1]);
    u16 species = *var_access(DUNGEON_OVERWORLD_SPECIES);
    dynamic_persons[num_persons].overworld_index = overworld_get_sprite_idx_by_species(species);
    DEBUG("Static encounter has gotten overworld idx %d\n", dynamic_persons[num_persons].overworld_index);
    dynamic_persons[num_persons].value = species;
    dynamic_persons[num_persons].behavior = BEHAVIOUR_WANDER_AROUND;
    dynamic_persons[num_persons].target_index = (u8)(num_persons + 1);
    dynamic_persons[num_persons].script = ow_script_dungeon_encounter;
    dynamic_persons[num_persons].flag = DG2_FLAG_STATIC_ENCOUNTER;
    num_persons++;

    // Initialize items / trainers
    for (int i = 0; i < DG2_MAX_NUM_TRAINER_OR_ITEM_NODES && DG2_NODE_TRAINER_OR_ITEM + i < dg2->nodes; i++) {
        dynamic_persons[num_persons].x = (s16)(nodes[DG2_NODE_TRAINER_OR_ITEM + i][0]);
        dynamic_persons[num_persons].y = (s16)(nodes[DG2_NODE_TRAINER_OR_ITEM + i][1]);
        dynamic_persons[num_persons].target_index = (u8)(num_persons + 1);
        switch (dungeon2_node_trainer_or_item_get_type(dg2, DG2_NODE_TRAINER_OR_ITEM + i)) {
            case DG2_NODE_TRAINER_OR_ITEM_TYPE_ITEM: {
                dynamic_persons[num_persons].overworld_index = 92;
                dynamic_persons[num_persons].value = item_picker(dg2);
                dynamic_persons[num_persons].script_std = PERSON_ITEM;
                dynamic_persons[num_persons].flag = (u16)(DG2_FLAG_ITEM + i);
                num_persons++;
                break;
            }
            case DG2_NODE_TRAINER_OR_ITEM_TYPE_TRAINER: {
                dynamic_persons[num_persons].overworld_index = (u8)(41 + (num_trainers & 1));
                dynamic_persons[num_persons].trainer_type_and_strength_flag = 1;
                dynamic_persons[num_persons].alert_radius = 4;
                dynamic_persons[num_persons].script = dungeon2_trainer_scripts[num_trainers][dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon2_trainer_scripts[0])];
                dynamic_persons[num_persons].behavior = BEHAVIOUR_LOOK_AROUND;
                num_trainers++;
                num_persons++;
                break;
            }
        }
    }
    dynamic_map_event_header.person_cnt = num_persons;
    dynamic_map_event_header.warp_cnt = num_warps;
}

static const u32 dungeon_mushroom_rates[] = {
    [MUSHROOM_TYPE_TINY_MUSHROOM] = 2, [MUSHROOM_TYPE_LARGE_MUSHROOM] = 1,
};

u16 dungeon_mushroom_get_type(u16 mushroom_idx) {
    int idx = mushroom_idx - DUNGEON_MISC_IDX_START;
    if (checkflag((u16)(DG2_FLAG_PATTERN + idx)))
        return MUSHROOM_TYPE_PLUCKED;
    u32 seq[1] = {mushroom_idx};
    gp_rng = hash_sequence(seq, ARRAY_COUNT(seq), csave.dg2.initial_seed);
    DEBUG("GP rnd seeded with mushroom dungeon hash 0x%x\n", gp_rng);
    return (u8)choice(dungeon_mushroom_rates, ARRAY_COUNT(dungeon_mushroom_rates), gp_rnd16);
}

void dungeon_mushroom_set_flag(u16 mushroom_idx) {
    setflag((u16)(DG2_FLAG_PATTERN + mushroom_idx - DUNGEON_MISC_IDX_START));
}

void dungeon2_reset_flags() {
    for (u16 flag = FLAG_DUNGEON_GP; flag <= FLAG_LAST_DUNGEON_GP; flag++)
        clearflag(flag);
}