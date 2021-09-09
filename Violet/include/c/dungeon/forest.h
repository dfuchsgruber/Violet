/*
 * forest.h
 *
 *  Created on: Jun 25, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_DUNGEON_FOREST_H_
#define INCLUDE_C_DUNGEON_FOREST_H_

#include "types.h"
#include "map/header.h"
#include "constants/dungeon/dungeon_forest_types.h"

#define DG2_DUSK_FOREST_CABIN_MAP 0
#define DG2_DUSK_FOREST_TENT_MAP 1

#define DTYPE_FOREST_WILD_POKEMON_FREQUENCY 0x20

    #define DG2_FOREST_WIDTH 56
    #define DG2_FOREST_HEIGHT 56
    #define DG2_FOREST_PATH_RANDOMNESS 45875 //0.7
    #define DG2_FOREST_INIT_RANDOMNESS 26214 //0.4
    #define DG2_FOREST_NODES 12
    #define DG2_FOREST_MARGIN 6
    #define DG2_FOREST_NODE_METRIC_LAMBDA_MIN 7
    #define DG2_FOREST_NODE_METRIC_LAMBDA_MEAN 5
    #define DG2_FOREST_NODE_SAMPLES 64

    enum {
        NB_GRASS = 0,
        NB_1x1_TREE,
        NB_2x2_TREE,
        NB_2x2_TREE_ALT,
        NUM_NBS,
    };

    #define DUNGEON_FOREST_NUM_ITEMS_COMMON 8
    #define DUNGEON_FOREST_NUM_ITEMS_RARE 4
    #define DUNGEON_FOREST_NUM_POKEMON_COMMON 8
    #define DUNGEON_FOREST_NUM_POKEMON_RARE 4
    #define DUNGEON_FOREST_NUM_POKEMON_STATIC 4

    typedef struct {
        map_footer_t *footer; // A special pattern that only occurs in this dungeon
        void (*event_init)(dungeon_generator2 *);
        u8 min_num_patterns;
        u8 max_num_patterns; // How often this pattern can occur
        u16 deco_rate; // in 1/256
        u16 alternative_tree_rate; // in 1/256
        u8 has_alternative_trees;
        u8 x_consistent_decoration; // If true, the decoration idx is always the same across two columns, this allows for larger patterns
        u8 y_consistent_decoration; // If true, the decoratino idx is always the same across two rows, this allows for larger patterns
        u8 map_weather;
        void (*fill_pattern_in_map)(u8 *map, int x, int y, int w, int h, dungeon_generator2 *dg2);
        u16 items_common[DUNGEON_FOREST_NUM_ITEMS_COMMON];
        u16 items_rare[DUNGEON_FOREST_NUM_ITEMS_RARE];
        u16 species_common[DUNGEON_FOREST_NUM_POKEMON_COMMON];
        u16 species_rare[DUNGEON_FOREST_NUM_POKEMON_RARE];
        u16 species_static_encounter[DUNGEON_FOREST_NUM_POKEMON_STATIC];
    } dungeon_forest_t;

    dungeon_forest_t dungeon_forest_types[NUM_DUNGEON_FOREST_TYPES];

    enum {
        BLOCK_NORMAL,
        BLOCK_WITH_DECO,
    };

    /**
     * Copies the blocks for the forest dungeon from the savefile to the map layout
     */
    void dungeon2_copy_blocks_forest();

    /**
     * Initializes a dungeon_generator2 instance for the forest dungeon
     * @param dg2 the instance to initalize
     */
    void dungeon2_forest_initialize_state(dungeon_generator2 *dg2);

    /**
     * Computes the header, footer, events and wild pokemon structures for the forest dungeon type
     */
    void dungeon2_initialize_forest();

    map_header_t *dungeon2_init_header_forest(dungeon_generator2 *dg2);

    map_event_header_t *dungeon2_init_events_forest(dungeon_generator2 *dgen);

    map_footer_t *dungeon2_init_footer_forest(dungeon_generator2 *dg2);

    /**
     * Returns an item obtainable in the forest dungeon
     * @param dg2 generator instance
     * @return item to obtain
     */
    u16 dungeon_forest_pick_item(dungeon_generator2 *dg2);

    /**
     * Gets the level distribution (normal) for the forest based on the badges collected
     * @param mean pointer to the mean level
     * @param std_deviation pointer to the standard deviation
     */
    void dungeon2_forest_wild_pokemon_level_distribution(u8 *mean, u8 *std_deviation);

    /**
     * Initializes the wild pokemon for the forest dungeon
     */
    void dungeon2_init_wild_pokemon_forest(dungeon_generator2 *dg2);

    /**
     * Sets the overworld encounter for the forest dungeon
     */
    void dungeon2_set_encounter_forest();

#endif /* INCLUDE_C_DUNGEON_FOREST_H_ */
