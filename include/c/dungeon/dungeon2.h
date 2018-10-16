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
#include "map/wild_pokemon.h"

    // Linear congruency rnd parameters
    #define DG2_RND_MULTIPLIER 0x41C64E6D
    #define DG2_RND_INCREMENT 0x6073

#define DG2_BANK 126
#define DG2_MAP 126

#define DTYPE_FOREST 1
#define DTYPE_CAVE 2
#define DTYPE_OCEAN 3

#define DG2_WALL 0
#define DG2_SPACE 1
#define DG2_ROCK 2
    
    typedef struct{
        // Initial seed of the dg2
        u32 initial_seed;
        // Current state
        u32 seed;
        // Size
        int width, height;
        // Probabilty of keeping strategy when connecting nodes
        FIXED path_randomness; // divided by 0x10000
        // Probability of generating walls when randomly initializing a map
        FIXED init_randomness; // divided by 0x10000

        // Number of samples to draw a node from
        size_t node_samples;
        // Weighting coefficient of the mean l2 distance of a node to all other nodes
        int node_metric_lambda_l2;
        // Weighting coefficient of the min distance of a node to all other nodes
        int node_metric_lambda_min;
        // Number of nodes to generate and connect when using node based initalization
        u8 nodes;

        // Size of margin in which nodes can not be placed in
        u8 margin;
        
        coordinate_t previous_position;
        u8 previous_bank, previous_map;
        
        
    } dungeon_generator2;

#define NUM_DUNGEON_LOCATIONS 32
    
    typedef struct{
      u8 bank;
      u8 map;
      s16 x;
      s16 y;
      u8 type;
    } dungeon_location;

    dungeon_location dungeon_locations[NUM_DUNGEON_LOCATIONS];

    /**
     * Gets the index of a dungeon location by a coordinate the player interacted with. If no
     * match could be found -1 is returned instead.
     * @param bank the map bank of the entrance
     * @param map the map id of the entrance
     * @param x the x coordinate of the entrance
     * @param y the y coordinate of the entrance
     * @return the dungeon idx to match the parameters or -1 if none matches
     */
    int dungeon_get_location_idx(u8 bank, u8 map, s16 x, s16 y);

    /**
     * Gets the index of the dungeon of which the player is currently facing the entrance
     * @return the idx of the dungeon entrance the player is facing or -1 if player is not
     * facing any dungeon entrance
     */
    int dungeon_get_location_idx_player_is_facing();

    /**
     * Returns the type of dungeon that is associated with the block the player is facing
     * @return the type of dungeon the player is facing
     */
    int dungeon_map_entrance_get_type();

    /**
     * Sets the flag of the dungeon of which the player is currently facing the entrance
     */
    void dungeon_map_entrance_set_flag();

    /**
     * Performs set_block on all map blocks that correspond to proper dungeon entries
     * Should be performed at execution time of levelscript type 1
     */
    void dungeon_map_set_tiles();

    void dungeon2_compute(int dungeon_type);
    
    /**
     * Computes the header structures for the current dungeon if not already computed
     */
    void dungeon2_init();
    
    /**
     * Creates a connected dungeon bytemap by the dungeon2 algorithm
     * The dungeon will contain paths and culmation points ("rooms")
     * @param dg2
     * @param random_nodes if the set of nodes is random or coninciedes with the standard nodes
     * of the given seed
     * @return 
     */
    u8 *dungeon2_create_connected_layout(dungeon_generator2 *dg2, bool random_nodes);

    /**
     * Creates a dungeon with isolated isles
     * @param dg2 generator instance
     * @param spread how wide spread isles are (std deviation of land blocks sampled next to
     * nodes)
     * @param denstiy how many blocks are sampled next to a node
     * @param random_nodes if the nodes are random or should match the seed-based nodes
     * @param exclude_node this node will not generate an isle (if all are disired set to num_nodes)
     * @return the dg2 map
     */
    u8 *dungeon2_create_isolated_layout(dungeon_generator2 *dg2, int spread, size_t density,
    		bool random_nodes, int exclude_node);
  
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
     * Applies src to dst, i.e. when src[x][y] == type, then dst[x][y] <- type
     * @param src the source map
     * @param dst the destination map
     * @param type the element to apply
     * @param dg2 generator instance
     */
    void dungeon2_apply(u8 *src, u8 *dst, u8 type, dungeon_generator2 *dg2);

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
     * Calculates one step connecting two nodes p and q using shortest path strategy
     * @param p first node (will be updated)
     * @param q second node
     */
    void dungeon2_connect_nodes_sp_next_step(int p[2], int q[2], dungeon_generator2 *dg2);

    /**
     * Calculates one step connecting two nodes p and q using random adjacent strategy
     * @param p first node (will be updated)
     * @param q second node
     */
    void dungeon2_connect_nodes_rnd_next_step(int p[2], int q[2], dungeon_generator2 *dg2);

    /**
     * Connects two nodes p and q starting at p. Each step is calculated by application of
     * one of these strategies:
     *  - shortest path: Uses the step that minimizes the l2 norm of the distance
     *  - random : Uses any valid step (adjacent and not in margin)
     *  Before each step the strategy will be kept with a probabilty pr. If the strategy is
     *  not changed pr will be multiplied with dg2->path_randomness. Otherwise it will be
     *  reinitialized with dg2->path_randomness
     * @param p starting point
     * @param q end point
     * @param dg2
     * @param map
     */
    void dungeon2_connect_nodes(int p[2], int q[2], dungeon_generator2 *dg2, u8 *map);
    

    /**
     * Valides that nodes[idx] does not coincide with nodes[:idx]
     * @param nodes a list of nodes
     * @param idx the index to validate
     * @param dg2 generator instance
     * @return idx + 1 if the node is valid, idx instead
     */
    int dungeon2_propose_node(int nodes[][2], int idx, dungeon_generator2 *dg2);

    /**
     * Calculates the distance metric of a nodes[idx] to all nodes[:idx]. The metric is given
     * by lambda1 * l2(distance) + lambda2 * min(distance) and provides a score high for nodes
     * that are not close to other nodes
     * @param nodes a list of nodes
     * @param idx the index to evaluate
     * @dg2 generator instance (unused)
     * @return the score of the node (rounded)
     */
    int dungeon2_node_distance(int nodes[][2], int idx, dungeon_generator2 *dg2);

    /**
     * Samples a node by generating dg2->node_samples nodes and picking the one with the highest
     * node distance.
     * @param nodes list of nodes
     * @param idx the index to sample
     * @param dg2 generator instance
     */
    void dungeon2_sample_node(int nodes[][2], int idx, dungeon_generator2 *dg2);

    /**
     * Generates nodes in the dungeon, i.e. a set of points between [margin, width-margin),
     * [margin, height-margin) and which do not coincide
     * @param nodes array of nodes with size num_nodes: nodes will be placed here
     * @param num_nodes size of thnodes array, i.e. number of nodes that will be generated
     * @param dg2 generator instance
     * @param random_nodes if the node set is random or dependent on the initial seed
     */
    void dungeon2_get_nodes(int nodes[][2], int num_nodes, dungeon_generator2 *dg2,
        bool random_nodes);

    /**
     * Intializes first an empty bytemap for the dungeon, selects random
     * points and connects them via semi-optimal BFS based on randomness.
     * In each traversal iteration step with a probabilty of dg2->randomness
     * a random adjacent tile is picked and else the optimal tile.
     * @param dg2
     * @param random_nodes if the set of nodes is random or coninciedes with the standard nodes
     * of the given seed
     */
    void dungeon2_init_by_paths(u8 *map, dungeon_generator2 *dg2, bool random_nodes);
    
    /**
     * Initializes first an empty bytemap for the dungeon, selects random
     * feasible points (w.r.t. the margin) and enable make those spaces
     * @param map
     * @param num_nodes number of nodes to generate
     * @param dg2
     * @param random_nodes if the set of nodes is random or coninciedes with the standard nodes
     * of the given seed
     */
    void dungeon_init_unconnected_nodes(u8 *map, dungeon_generator2 *dg2, bool random_nodes);
    
    /**
     * Initializes a bytemap for a dungeon by randomizing the walls. Each
     * feasible tile (w.r.t. the margin) will become a wall with probabilty
     * dg2->
     * @param map
     * @param dg2
     */
    void dungeon_init_random(u8 *map, dungeon_generator2 *dg2);
    
    /**
     * Debugging: Uses dprintf to print a dungeon, using # for walls and spaces for spaces and
     * x for nodes
     * @param map the map to print
     * @param nodes the nodes
     * @dg2 the dungeon generator
     */
    void dungeon2_print_map(u8 *map, dungeon_generator2 *dg2);

    /**
     * Creates a map layout full of patches (can be used for grass etc.)
     * using the dungeon2 algorithm
     * @param dg2
     * @param random_nodes if the set of nodes is random or coninciedes with the standard nodes
     * of the given seed
     * @return 
     */
    u8 *dungeon2_create_patch_layout(dungeon_generator2 *dg2, bool random_nodes);

    /**
     * Linear congruence RNG returning positive 16-bit integers
     * @param dg2
     * @return
     */
    u16 dungeon2_rnd_16(dungeon_generator2 *dg2);
    
    /**
     * Linear congruence RNG returning positive integers
     * @param dg2
     * @return
     */
    int dungeon2_rnd_int(dungeon_generator2 *dg2);

    /**
     * Linear congruence RNG
     * @param dg2
     * @return 
     */
    u32 dungeon2_rnd(dungeon_generator2 *dg2);
    
    /**
     * Returns a FIXED point number ~ N(0, 1)
     * @param dg2 generator instance
     * @return value x ~ N(0, 1)
     */
    FIXED dungeon2_rnd_normal(dungeon_generator2 *dg2);

    /**
     * Picks a number of distinct elements of src (terminated by 0xFFFF) and places them at dst
     */
    void dungeon2_pick_wild_pokemon(u16 *dst, int number, u16 *src, dungeon_generator2 *dg2);

    /**
     * Gets the boundaries for wild pokemon levels based on a mean and standard deviation
     * @param level_min pointer to the minimal level
     * @param level_max pointer to the maximum level
     * @param mean the expected level
     * @param std_deviation the standard deviation for the level
     */
    void dungeon2_wild_pokemon_sample_level_boundaries(u8 *level_min, u8 *level_max, u8 mean,
        u8 std_deviation, dungeon_generator2 *dg2);

    /**
     * Provides values in [0,127) based on the current dg2 instance
     * @return random value [0, 127) based on the dg2
     */
    u16 dungeon2_encounter_rnd_generator();

    /**
     * Copies the private field (item in context of dungeons) of the person which target index
     * is given in 0x8004 into the variable 0x8005
     */
    void dungeon_special_item_by_overworld_idx();

    int dg2_cross_neighbourhood[4][2];

    map_connection_header_t dungeon2_connections;

    levelscript_header_t dungeon2_lscr[1];

#ifdef	__cplusplus
}
#endif

#endif	/* DUNGEON2_H */

