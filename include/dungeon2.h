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
#include "tile.h"

    // Linear congruency rnd parameters
    #define DG2_RND_MULTIPLIER 0x41C64E6D
    #define DG2_RND_INCREMENT 0x6073

#define DG2_STEPS 0x50E1
    
#define DG2_WALL 0
#define DG2_SPACE 1
    
    typedef struct{
        u32 initial_seed;
        u32 seed;
        int width, height;
        u16 randomness; // divided by 0x10000
        u8 nodes;
        u8 iterations;
        
        coordinate previous_position;
        u8 previous_bank, previous_map;
        
        
    } dungeon_generator2;
    
    
    void dungeon2_compute();
    
    /**
     * Computes map blocks by using set_block_id(...) and a bytemap
     * @param map
     * @param dg2
     */
    void dungeon2_compute_blocks(u8 *map, dungeon_generator2 *dg2);
    
    mapheader *dungeon2_init_header();
    
    map_events *dungeon2_init_events(dungeon_generator2 *dgen);
    
    mapfooter *dungeon2_init_footer(dungeon_generator2 *dg2);
    
    /**
     * Creates a dungeon bytemap by the dungeon2 algorithm
     * @param dg2
     * @return 
     */
    u8 *dungeon2_create(dungeon_generator2 *dg2);
  
    /**
     * Creates the next generation map by counting the adjacent walls to a tile
     * and if it at least suffices the rule or is zero it creates wall in the
     * next generation
     * @param map The old map (will be freed)
     * @param rule 
     * @param dg2
     * @return The new map
     */
    u8 *dungeon2_iterate(u8 *map, int rule, dungeon_generator2 *dg2);
    
    /**
     * Fills the borders of the map with DG2_WALL
     * @param map
     * @param width
     * @param height
     */
    void dungeon2_enclose(u8 *map, int width, int height);
    
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
    void dungeon2_next_node(int *result, dungeon_generator2 *dg2);

    /**
     * Intializes first an empty bytemap for the dungeon, selects random
     * points and connects them via semi-optimal BFS based on randomness.
     * In each traversal iteration step with a probabilty of dg2->randomness
     * a random adjacent tile is picked and else the optimal tile.
     * @param dg2
     * @return 
     */
    u8 *dungeon2_init(dungeon_generator2 *dg2);
    
    /**
     * Linear congruence RNG
     * @param dg2
     * @return 
     */
    u16 dungeon2_rnd(dungeon_generator2 *dg2);

#ifdef	__cplusplus
}
#endif

#endif	/* DUNGEON2_H */

