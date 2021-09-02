/*
 * cave.h
 *
 *  Created on: Jun 26, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_DUNGEON_CAVE_H_
#define INCLUDE_C_DUNGEON_CAVE_H_

#define DG2_CAVE_TENT_MAP 1

#define DTYPE_CAVE_WILD_POKEMON_FREQUENCY 0x2

    #define DG2_CAVE_WIDTH 56
    #define DG2_CAVE_HEIGHT 56
    #define DG2_CAVE_PATH_RANDOMNESS 45875 //0.7
    #define DG2_CAVE_INIT_RANDOMNESS 0xA000 //0.4
    #define DG2_CAVE_NODES 12
    #define DG2_CAVE_MARGIN 6
    #define DG2_CAVE_NODE_METRIC_LAMBDA_MIN 7
    #define DG2_CAVE_NODE_METRIC_LAMBDA_MEAN 5
    #define DG2_CAVE_NODE_SAMPLES 50

    enum {
        DUNGEON_CAVE_TYPE_NORMAL = 0,
        DUNGEON_CAVE_TYPE_TENT,
        NUM_DUNGEON_CAVE_TYPES,
    };


    #define DUNGEON_CAVE_NUM_ITEMS_COMMON 8
    #define DUNGEON_CAVE_NUM_ITEMS_RARE 4
    #define DUNGEON_CAVE_NUM_POKEMON_COMMON 8
    #define DUNGEON_CAVE_NUM_POKEMON_RARE 4
    #define DUNGEON_CAVE_NUM_POKEMON_STATIC 4


    typedef struct {
        map_footer_t *footer; // A special pattern that only occurs in this dungeon
        void (*event_init)(dungeon_generator2 *);
        u8 min_num_patterns;
        u8 max_num_patterns; // How often this pattern can occur
        u16 deco_rate; // in 1/256
        u8 map_weather;
        void (*fill_pattern_in_map)(u8 *map, int x, int y, int w, int h, dungeon_generator2 *dg2);
        void (*fill_pattern_in_over)(u8 *map, int x, int y, int w, int h, dungeon_generator2 *dg2);
        u16 items_common[DUNGEON_CAVE_NUM_ITEMS_COMMON];
        u16 items_rare[DUNGEON_CAVE_NUM_ITEMS_RARE];
        u16 species_common[DUNGEON_CAVE_NUM_POKEMON_COMMON];
        u16 species_rare[DUNGEON_CAVE_NUM_POKEMON_RARE];
        u16 species_static_encounter[DUNGEON_CAVE_NUM_POKEMON_STATIC];
    } dungeon_cave_t;

    dungeon_cave_t dungeon_cave_types[NUM_DUNGEON_CAVE_TYPES];

    enum {
        ADJ_MASK_SE = (1 << 0),
        ADJ_MASK_E = (1 << 1),
        ADJ_MASK_NE = (1 << 2),
        ADJ_MASK_S = (1 << 3),
        ADJ_MASK_CENTER = (1 << 4),
        ADJ_MASK_N = (1 << 5),
        ADJ_MASK_SW = (1 << 6),
        ADJ_MASK_W = (1 << 7),
        ADJ_MASK_NW = (1 << 8),
        ADJ_ALL = ADJ_MASK_SE | ADJ_MASK_E | ADJ_MASK_NE | ADJ_MASK_S | ADJ_MASK_CENTER | ADJ_MASK_N | ADJ_MASK_SW | ADJ_MASK_W | ADJ_MASK_NW,
    };

    static inline int dungeon2_cave_count_adjacent_of_type(int x, int y, u8 type, u8 *map, dungeon_generator2 *dg2) {
        int adjacent = 0;
        for (int i = 0; i < 4; i++) {
            int x0 = x + dg2_cross_neighbourhood[i][0], y0 = y + dg2_cross_neighbourhood[i][1];
            u8 tile_at = map[y0 * dg2->width + x0];
            if (tile_at == type) 
                adjacent++;
        }
        return adjacent;
    }

    static inline int dungeon2_cave_get_adjacency_pattern(int x, int y, u8 *map, dungeon_generator2 *dg2) {
        int pattern = 0;
        for (int dx = -1; dx < 2; dx++) {
            for (int dy = -1; dy < 2; dy++) {
                int x0 = x + dx;
                int y0 = y + dy;
                pattern <<= 1;
                if (map[y0 * dg2->width + x0] == DG2_WALL) 
                    pattern |= 1;
            }
        }
        // Pattern bits look like this
        //    8         7        6       5        4       3        2       1       0
        // (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0), (1, 1)
        return pattern;
    }

	/**
	 * Checks if based on the adjacency pattern of a wall block it can be rendered with the
	 * standard rock tileset.
	 * @param map the map data
	 * @param x the x coordiante (0-based)
	 * @param y the y coordinate (0-based)
	 * @param dg2 the underlying dungeon generator instance
	 * @return if the block at x, y can be drawn as wall
	 */
	bool dungeon2_cave_wall_can_be_drawn(u8 *map, int x, int y, dungeon_generator2 *dg2);

    void dungeon2_set_blocks_cave(u8 *map, u8 *over, dungeon_generator2 *dg2);

    /**
     * Computes blocks for the cave dungeon
     */
    void dungeon2_compute_cave();

    /**
     * Initializes a dungeon_generator2 instance for the cave dungeon
     * @param dg2 the instance to initalize
     */
    void dungeon2_cave_initialize_state(dungeon_generator2 *dg2);

    /**
     * Computes the header structures for the cave dungeon type
     */
    void dungeon2_initialize_cave();

    map_header_t *dungeon2_init_header_cave(dungeon_generator2 *dg2);

    map_event_header_t *dungeon2_init_events_cave(dungeon_generator2 *dgen);

    map_footer_t *dungeon2_init_footer_cave(dungeon_generator2 *dg2);

    /**
     * Returns an item obtainable in the cave dungeon
     * @param dg2 generator instance
     * @return item to obtain
     */
    u16 dungeon_cave_pick_item(dungeon_generator2 *dg2);

    /**
     * Gets the level distribution (normal) for the cave based on the badges collected
     * @param mean pointer to the mean level
     * @param std_deviation pointer to the standard deviation
     */
    void dungeon2_cave_wild_pokemon_level_distribution(u8 *mean, u8 *std_deviation);

    /**
     * Initializes the wild pokemon for the cave dungeon
     */
    void dungeon2_init_wild_pokemon_cave(dungeon_generator2 *dg2);


    /**
     * Sets the overworld encounter for the cave dungeon
     */
    void dungeon2_set_encounter_cave();


#endif /* INCLUDE_C_DUNGEON_CAVE_H_ */
