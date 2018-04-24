/* 
 * File:   dungeon2.h
 * Author: Domi
 *
 * Created on 29. Dezember 2017, 11:35
 */

#ifndef DUNGEON2_H
#define	DUNGEON2_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "types.h"
#include "tile/coordinate.h"
#include "map/header.h"
#include "map/footer.h"
#include "map/event.h"

    // Linear congruency rnd parameters
    #define DG2_RND_MULTIPLIER 0x41C64E6D
    #define DG2_RND_INCREMENT 0x6073

#define DTYPE_FOREST 1
#define DTYPE_CAVE 2
    
#define DG2_WALL 0
#define DG2_SPACE 1
    
    typedef struct{
        u32 initial_seed;
        u32 seed;
        int width, height;
        u16 path_randomness; // divided by 0x10000
        u16 init_randomness; // divided by 0x10000
        u8 nodes;
        u8 margin;
        
        coordinate previous_position;
        u8 previous_bank, previous_map;
        
        
    } dungeon_generator2;
    
    void dungeon2_compute(int dungeon_type);
    
    void dungeon2_compute_forest();
    
    
    
    /**
     * Computes map blocks for a forest map by using set_block_id(...) and a bytemap
     * @param map The basic walk map
     * @param over The overlay map for grass patches
     * @param dg2
     */
    void dungeon2_compute_blocks_forest(u8 *map, u8 *over, dungeon_generator2 *dg2);
    
    mapheader *dungeon2_init_header_forest();
    
    map_events *dungeon2_init_events_forest(dungeon_generator2 *dgen);
    
    mapfooter *dungeon2_init_footer_forest(dungeon_generator2 *dg2);
    
    /**
     * Creates a connected dungeon bytemap by the dungeon2 algorithm
     * The dungeon will contain paths and culmation points ("rooms")
     * @param dg2
     * @return 
     */
    u8 *dungeon2_create_connected_layout(dungeon_generator2 *dg2);
  
    /**
     * Creates the next generation map by counting the adjacent walls to a tile
     * and if it at least suffices the rule or is zero it creates wall in the
     * next generation
     * @param map The old map
     * @param map2 Memory for new map (borders will not be filled)
     * @param near_lower_bound Tiles with 3x3 neighbours >= near_lower_bound will
     * become walls.
     * @param far_upper_bound Tiles with sqrt(5) neighbours <= far_upper_bound will
     * become walls.
     * @param dg2
     */
    void dungeon2_iterate(u8 *map, u8 *map2, int near_lower_bound, int far_upper_bound, dungeon_generator2 *dg2);
    
    /**
     * Fills the borders of the map with DG2_WALL
     * @param map
     * @param width
     * @param height
     */
    void dungeon2_enclose(u8 *map, int width, int height);
    
    /**
     * Enlarges the walkable map by counting neighbours in sqrt(3) neighbourhood
     * and if a wall tile has less than 4 wall neighbours it will become space
     * @param map 
     * @param map2 Memory for the new map
     * @param dg2
     */
    void dungeon2_enlarge(u8 *map, u8 *map2, dungeon_generator2 *dg2);
    
    /**
     * Contracts the walkable map by counting neighbours in sqrt(3) neighbourhood
     * and if a space tile has one adjacent wall it will turn into a wall. This
     * serves the purpose for each wall chunk being able to be resembled by
     * the cave tileset.
     * @param map
     * @param map2
     * @param dg2
     */
    void dungeon2_contract(u8 *map, u8 *map2, dungeon_generator2 *dg2);
    
    /**
     * Scan line flood fill for a random space position
     * @param map The current map (will be overwritten and filled)
     * @param map2 The new map
     * @param dg2 
     * @return The number of filled tiles
     */
    int dungeon2_flood_fill(u8 *map, u8 *map2, dungeon_generator2 *dg2);
    
    /**
     * Connects two points a and b as follows: Start at a and traverse tiles
     * unitl b is reached. For each iteration chose the next tile by application
     * of this rule: With a probabilty of randomness chose any adjacent tile.
     * Else chose the next tile of the optimal path.
     * @param a starting point
     * @param b end point
     * @param dg2
     * @param map
     */
    void dungeon2_connect_nodes(int *a, int *b, dungeon_generator2 *dg2, u8 *map);
    
    /**
     * Generates a random point between [margin, width-margin),
     * [margin, height-margin)
     * @param result int[2] to store coordinates of point
     * @param dg2
     */
    void dungeon2_next_node(int *result, int margin, dungeon_generator2 *dg2);

    /**
     * Intializes first an empty bytemap for the dungeon, selects random
     * points and connects them via semi-optimal BFS based on randomness.
     * In each traversal iteration step with a probabilty of dg2->randomness
     * a random adjacent tile is picked and else the optimal tile.
     * @param dg2
     * @return 
     */
    void dungeon2_init_by_paths(u8 *map, dungeon_generator2 *dg2);
    
    /**
     * Initializes first an empty bytemap for the dungeon, selects random
     * feasible points (w.r.t. the margin) and enable make those spaces
     * @param map
     * @param dg2
     */
    void dungeon_init_unconnected_nodes(u8 *map, dungeon_generator2 *dg2);
    
    /**
     * Initializes a bytemap for a dungeon by randomizing the walls. Each
     * feasible tile (w.r.t. the margin) will become a wall with probabilty
     * dg2->
     * @param map
     * @param dg2
     */
    void dungeon_init_random(u8 *map, dungeon_generator2 *dg2);
    

    /**
     * Creates a map layout full of patches (can be used for grass etc.)
     * using the dungeon2 algorithm
     * @param dg2
     * @return 
     */
    u8 *dungeon2_create_patch_layout(dungeon_generator2 *dg2);
    
    /**
     * Linear congruence RNG
     * @param dg2
     * @return 
     */
    u32 dungeon2_rnd(dungeon_generator2 *dg2);
    
    int dg2_cross_neighbourhood[4][2];

#ifdef	__cplusplus
}
#endif

#endif	/* DUNGEON2_H */

