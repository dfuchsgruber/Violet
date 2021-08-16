#include "types.h"
#include "dungeon/dungeon2.h"
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
#include "flags.h"
#include "debug.h"
#include "hash.h"

bool dungeon2_find_empty_space(int *space_x, int *space_y, u8 *center_node, int nodes[][2], int width, int height, u8 *map, dungeon_generator2 *dg2) {
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

bool dungeon2_find_empty_space_for_pattern(int *space_x, int *space_y, u8 *center_node, int nodes[][2], map_footer_t *pattern, u8 *map, dungeon_generator2 *dg2) {
    return dungeon2_find_empty_space(space_x, space_y, center_node, nodes, (int)pattern->width, (int)pattern->height, map, dg2);
}

void dungeon2_place_pattern(int pattern_x, int pattern_y, map_footer_t *pattern) {
    dprintf("Place pattern with dimensions %d,%d at %d,%d\n", pattern->width, pattern->height, pattern_x, pattern_y);
    for (u8 i = 0; i < pattern->width; i++) {
        for (u8 j = 0; j < pattern->height; j++) {
            u16 *block = (u16*) pattern->map + (j * pattern->width + i);
            block_set_by_pos((s16)(pattern_x + i + 7 - (int)(pattern->width / 2)), (s16)(pattern_y + j + 7 - (int)(pattern->height / 2)), *block);
        }
    }
}

extern u8 ow_script_dungeon_encounter[];
extern u8 ow_script_dungeon_trainer_0[];
extern u8 ow_script_dungeon_trainer_1[];
extern u8 ow_script_dungeon_trainer_2[];
extern u8 ow_script_dungeon_trainer_3[];
extern u8 ow_script_dungeon_trainer_4[];
extern u8 ow_script_dungeon_trainer_5[];
extern u8 ow_script_dungeon_trainer_6[];
extern u8 ow_script_dungeon_trainer_7[];

static u8 *dungeon2_trainer_scripts[4][2] = {
    {ow_script_dungeon_trainer_0, ow_script_dungeon_trainer_4}, 
    {ow_script_dungeon_trainer_1, ow_script_dungeon_trainer_5}, 
    {ow_script_dungeon_trainer_2, ow_script_dungeon_trainer_6},
    {ow_script_dungeon_trainer_3, ow_script_dungeon_trainer_7},
};

void dungeon2_initialize_std_events(dungeon_generator2 *dg2, u16 (*item_picker)(dungeon_generator2*)) {

    // Clear all dynamic person events
    int zero = 0;
    cpuset(&zero, &(fmem.dpersons), CPUSET_FILL | CPUSET_HALFWORD |
        CPUSET_HALFWORD_SIZE(DMAP_PERSONS * sizeof(map_event_person)));

    fmem.dmapevents.warp_cnt = 0;
    fmem.dmapevents.script_cnt = 0;
    fmem.dmapevents.signpost_cnt = 0;
    fmem.dmapevents.persons = fmem.dpersons;

    int nodes[dg2->nodes][2];
    dungeon2_get_nodes(nodes, dg2->nodes, dg2, false);

    u8 num_persons = 0;

    // Initialize the static encounter
    fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_STATIC_ENCOUNTER][0]);
    fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_STATIC_ENCOUNTER][1]);
    u16 species = *var_access(DUNGEON_OVERWORLD_SPECIES);
    fmem.dpersons[num_persons].overworld_index = overworld_get_sprite_idx_by_species(species);
    fmem.dpersons[num_persons].value = species;
    fmem.dpersons[num_persons].behavior = BEHAVIOUR_WANDER_AROUND;
    fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
    fmem.dpersons[num_persons].script = ow_script_dungeon_encounter;
    fmem.dpersons[num_persons].flag = DG2_FLAG_STATIC_ENCOUNTER;
    num_persons++;

    // Initialize items / trainers
    int num_trainers_remaining = dungeon2_rnd_16(dg2) % (DG2_MAX_NUM_TRAINERS + 1);
    int num_trainers = 0;
    for (int i = 0; i < DG2_MAX_NUM_TRAINER_OR_ITEM_NODES && DG2_NODE_TRAINER_OR_ITEM + i < dg2->nodes; i++) {
        fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_TRAINER_OR_ITEM + i][0]);
        fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_TRAINER_OR_ITEM + i][1]);
        fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
        if (num_trainers_remaining > 0) { // Create a trainer
            fmem.dpersons[num_persons].overworld_index = (u8)(41 + (num_trainers & 1));
            fmem.dpersons[num_persons].trainer_type_and_strength_flag = 1;
            fmem.dpersons[num_persons].alert_radius = 4;
            fmem.dpersons[num_persons].script = dungeon2_trainer_scripts[num_trainers][dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon2_trainer_scripts[0])];
            fmem.dpersons[num_persons].behavior = BEHAVIOUR_LOOK_AROUND;
            num_trainers_remaining--;
            num_trainers++;
            num_persons++;
        } else if (dungeon2_rnd_16(dg2) % 2) { // Create an item
            fmem.dpersons[num_persons].overworld_index = 92;
            fmem.dpersons[num_persons].value = item_picker(dg2);
            fmem.dpersons[num_persons].script_std = PERSON_ITEM;
            fmem.dpersons[num_persons].flag = (u16)(DG2_FLAG_ITEM + i);
            num_persons++;
        }
    }
    fmem.dmapevents.person_cnt = num_persons;
}

static u32 dungeon_mushroom_rates[] = {
    [MUSHROOM_TYPE_TINY_MUSHROOM] = 2, [MUSHROOM_TYPE_LARGE_MUSHROOM] = 1,
};

u16 dungeon_mushroom_get_type(u16 mushroom_idx) {
    int idx = mushroom_idx - DUNGEON_MISC_IDX_START;
    if (checkflag((u16)(DG2_FLAG_PATTERN + idx)))
        return MUSHROOM_TYPE_PLUCKED;
    u32 seq[1] = {mushroom_idx};
    fmem.gp_rng = hash_sequence(seq, ARRAY_COUNT(seq), cmem.dg2.initial_seed);
    dprintf("GP rnd seeded with mushroom dungeon hash 0x%x\n", fmem.gp_rng);
    return (u8)choice(dungeon_mushroom_rates, ARRAY_COUNT(dungeon_mushroom_rates), gp_rnd16);
}

void dungeon_mushroom_set_flag(u16 mushroom_idx) {
    setflag((u16)(DG2_FLAG_PATTERN + mushroom_idx - DUNGEON_MISC_IDX_START));
}

void dungeon2_reset_flags() {
    for (u16 flag = FLAG_DUNGEON_GP; flag <= FLAG_LAST_DUNGEON_GP; flag++)
        clearflag(flag);
}