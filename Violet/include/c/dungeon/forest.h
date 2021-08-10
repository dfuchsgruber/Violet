/*
 * forest.h
 *
 *  Created on: Jun 25, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_DUNGEON_FOREST_H_
#define INCLUDE_C_DUNGEON_FOREST_H_

#define DTYPE_FOREST_WILD_POKEMON_FREQUENCY 0x20

    #define DG2_FOREST_WIDTH 52
    #define DG2_FOREST_HEIGHT 52
    #define DG2_FOREST_PATH_RANDOMNESS 45875 //0.7
    #define DG2_FOREST_INIT_RANDOMNESS 26214 //0.4
    #define DG2_FOREST_NODES 12
    #define DG2_FOREST_MARGIN 4
    #define DG2_FOREST_NODE_METRIC_LAMBDA_MIN 7
    #define DG2_FOREST_NODE_METRIC_LAMBDA_MEAN 5
    #define DG2_FOREST_NODE_SAMPLES 100

    enum {
        DUNGEON_FOREST_TYPE_NORMAL = 0,
        DUNGEON_FOREST_TYPE_APPLE_FOREST = 1,
        NUM_DUNGEON_FOREST_TYPES
    };

    /**
     * Computes blocks for the forest dungeon
     */
    void dungeon2_compute_forest();

    /**
     * Initializes a dungeon_generator2 instance for the forest dungeon
     * @param dg2 the instance to initalize
     */
    void dungeon2_forest_init_state(dungeon_generator2 *dg2);

    /**
     * Computes the header structures for the forest dungeon type
     */
    void dungeon2_init_forest();

    /**
     * Computes map blocks for a forest map by using set_block_id(...) and a bytemap
     * @param map The basic walk map
     * @param over The overlay map for grass patches
     * @param dg2
     */
    void dungeon2_compute_blocks_forest(u8 *map, u8 *over, dungeon_generator2 *dg2);

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
