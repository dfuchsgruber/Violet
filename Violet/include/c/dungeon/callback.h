#ifndef H_DUNGEON_CALLBACK
#define H_DUNGEON_CALLBACK

#include "types.h"
#include "dungeon/dungeon2.h"


    #define DG2_CREATE_CONNECTED_LAYOUT_NODE_CONNECTION_STEPS_PER_FRAME 1
    #define DG2_CREATE_CONNECTED_LAYOUT_FOLD_FUNCTION_LINES_PER_FRAME 1
    #define DG2_CREATE_PATCH_LAYOUT_NODES_PER_FRAME 4
    #define DG2_ENLARGE_LINES_PER_FRAME 4
    #define DG2_CONTRACT_LINES_PER_FRAME 4
    #define DG2_APPLY_LINES_PER_FRAME 8
    
    #define DG2_NODE_SAMPLES_PER_FRAME 8

    typedef struct {
        u8 state;
        u8 cb_idx_to_wait_for;
        bool random_nodes;
        dungeon_generator2 *dg2;
        u8 *map1;
        u8 *map2;
        u8 *map_paths;
        u8 *result;
        int (*nodes)[2];
        int excluded_nodes_mask;
    } create_connected_layout_state_t;

    /**
     * Creates a big callback that creates a connected layout
     * @param dg2 the dungeon generator state
     * @param nodes the nodes around which the layout is based
     * @param dst where to put the layout
     * @param excluded_nodes_mask bitfield that indicates which nodes are not connected
     * @return callback_idx of the process
     **/
    u8 dungeon2_create_connected_layout_with_callback(dungeon_generator2 *dg2, int (*nodes)[2], u8 *dst, int excluded_nodes_mask);

    /**
     * Checks if a connected layout has been created by a callback
     * @param callback_idx the callback that creates the layout
     * @return if the layout has been created
     **/
    bool dungeon2_create_connected_layout_with_callback_finished(u8 cb_idx);

    /**
     * Checks if the callback for sampling nodes is finished and deletes it if so
     * @param cb_idx the callback idx of the sampling process
     * @return if the sampling is finished
     **/
    bool dungeon2_get_nodes_with_callback_finished(u8 cb_idx);

    /**
     * Samples the nodes for a dungeon with a callback
     * @param nodes where to put the nodes
     * @param num_nodes how many nodes to sample
     * @param dg2 the generator state
     * @return callback idx of the sampling process
     **/
    u8 dungeon2_get_nodes_with_callback(int nodes[][2], u8 num_nodes, dungeon_generator2* dg2);

    /**
     * Checks if the callback for creating the patch layout has finished and if so, deletes it
     * @param cb_idx the callback_idx to wait for
     * @return if the creation has finished
     **/
    bool dungeon2_create_patch_layout_with_callback_finished(u8 cb_idx);

    /**
     * Creates a patch layout using a callback
     * @param dg2 the dungeon generator state
     * @param nodes the nodes at which to create patches
     * @param dst where to create the layout 
     * @param excluded_nodes_mask bitfield that indicates which nodes are excluded from the process
     * @return callback idx of the creation process
     **/
    u8 dungeon2_create_patch_layout_with_callback(dungeon_generator2 *dg2, int nodes[][2], u8 *dst, int excluded_nodes_mask);

    /**
     * Enlarges a map using a callback
     * @param src source map
     * @param dst where to put the new map
     * @param dg2 the dungeon generator state
     * @param u16 lines_per_frame how many lines are processed each frame 
     * @return callback idx of the process
     **/
    u8 dungeon2_enlarge_with_callback(u8 *src, u8 *dst, dungeon_generator2 *dg2, u16 lines_per_frame);

    /**
     * Checks if the callback for enlargening has finished and if so, deletes it
     * @param cb_idx the callback_idx to wait for
     * @return if the creation has finished
     **/
    bool dungeon2_enlarge_with_callback_finished(u8 cb_idx);

    /**
     * Contracts a map using a callback
     * @param src source map
     * @param dst where to put the new map
     * @param dg2 the dungeon generator state
     * @param u16 lines_per_frame how many lines are processed each frame 
     * @return callback idx of the process
     **/
    u8 dungeon2_contract_with_callback(u8 *src, u8 *dst, dungeon_generator2 *dg2, u16 lines_per_frame);

    /**
     * Checks if the callback for contracting has finished and if so, deletes it
     * @param cb_idx the callback_idx to wait for
     * @return if the creation has finished
     **/
    bool dungeon2_contract_with_callback_finished(u8 cb_idx);

    /**
     * Applies tiles from a src map to a dst map
     * @param src source map
     * @param dst where to put the new map
     * @param tile the tile to apply
     * @param dg2 the dungeon generator state
     * @param u16 lines_per_frame how many lines are processed each frame 
     * @return callback idx of the process
     **/
    u8 dungeon2_apply_with_callback(u8 *src, u8 *dst, u8 tile, dungeon_generator2 *dg2, u16 lines_per_frame);

    /**
     * Checks if the callback for applying tiles to a map has finished and if so, deletes it
     * @param cb_idx the callback_idx to wait for
     * @return if the creation has finished
     **/
    bool dungeon2_apply_with_callback_finished(u8 cb_idx);

#endif