/*
 * ocean.h
 *
 *  Created on: Aug 20, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_DUNGEON_OCEAN_H_
#define INCLUDE_C_DUNGEON_OCEAN_H_

#define DUNGEON_TYPE_OCEAN_WILD_POKEMON_FREQUENCY_WATER 0x2
#define DUNGEON_TYPE_OCEAN_WILD_POKEMON_FREQUENCY_ROD 180

    #define DG2_OCEAN_WIDTH 50
    #define DG2_OCEAN_HEIGHT 50
    #define DG2_OCEAN_PATH_RANDOMNESS 45875 //0.7
    #define DG2_OCEAN_INIT_RANDOMNESS 0xA000 //0.4
    #define DG2_OCEAN_NODES 24
    #define DG2_OCEAN_MARGIN 4
    #define DG2_OCEAN_NODE_METRIC_LAMBDA_MIN 7
    #define DG2_OCEAN_NODE_METRIC_LAMBDA_MEAN 5
    #define DG2_OCEAN_NODE_SAMPLES 50

	#define DG2_OCEAN_IS_BORDER (1 << 0)
	#define DG2_OCEAN_IS_FIXED (1 << 1)

	/**
     * Computes blocks for the ocean dungeon
     */
    void dungeon2_compute_ocean();

    /**
     * Initializes a dungeon_generator2 instance for the ocean dungeon
     * @param dg2 the instance to initalize
     */
    void dungeon2_ocean_init_state(dungeon_generator2 *dg2);

    /**
     * Computes the header structures for the ocean dungeon type
     */
    void dungeon2_init_ocean();

    /**
     * Computes map blocks for a ocean map by using set_block_id(...) and a bytemap
     * @param map The basic walk map
     * @param over The overlay map for grass patches
     * @param dg2
     */
    void dungeon2_compute_blocks_ocean(u8 *map, u8 *over, dungeon_generator2 *dg2);

    map_header_t *dungeon2_init_header_ocean(dungeon_generator2 *dg2);

    map_event_header_t *dungeon2_init_events_ocean(dungeon_generator2 *dgen);

    map_footer_t *dungeon2_init_footer_ocean(dungeon_generator2 *dg2);

    /**
     * Returns an item obtainable in the ocean dungeon
     * @param dg2 generator instance
     * @return item to obtain
     */
    u16 dungeon_ocean_pick_item(dungeon_generator2 *dg2);

    /**
     * Gets the level distribution (normal) for the ocean based on the badges collected
     * @param mean pointer to the mean level
     * @param std_deviation pointer to the standard deviation
     */
    void dungeon2_ocean_wild_pokemon_level_distribution(u8 *mean, u8 *std_deviation);

    /**
     * Initializes the wild pokemon for the ocean dungeon
     */
    void dungeon2_init_wild_pokemon_ocean(dungeon_generator2 *dg2);


    /**
     * Sets the overworld encounter for the ocean dungeon
     */
    void dungeon2_set_encounter_ocean();



#endif /* INCLUDE_C_DUNGEON_OCEAN_H_ */
