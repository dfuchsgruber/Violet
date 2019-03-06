/* 
 * File:   worldmap.h
 * Author: Domi
 *
 * Created on 15. März 2017, 17:16
 */

#ifndef WORLDMAP_H
#define	WORLDMAP_H

#ifdef	__cplusplus
extern "C" {
#endif
#define ____ 0xC5

#define NUM_FLIGHT_POSITONS 21

    typedef struct{
        u8 bank;
        u8 map;
        s16 x;
        s16 y;
        u16 field_6;
    } stru_flight_position;
    
    typedef struct {
    	u16 cursor_x, cursor_y;
    	u8 unknown[0x10];
    	u16 player_namespace;
    	u8 unkown2[0xE];
    	u16 tiles[0x80]; // whatever those tiles may be...

    } worldmap_state_t;

    // A pattern consists of multiple shapes, each of which can have displacement from the
    // position anchor and its own rectangular dimension. To associate a map with a shape use
    // the respective field in the mapheader structure
    typedef struct {
    	u8 x, y, width, height;
    } worldmap_shape_t;

    typedef struct {
    	int num_shapes;
    	worldmap_shape_t *shapes;
    } worldmap_pattern_t;

    extern worldmap_state_t *worldmap_state;

    stru_flight_position flight_positions[NUM_FLIGHT_POSITONS];


    int *worldmap_tilemaps[4];
    u8 *namespace_worldmap_associations;
    extern const unsigned short gfx_worldmapTiles[];
    extern const unsigned short gfx_worldmapMap[];
    extern const unsigned short gfx_worldmapPal[];

    /**
     * Returns the flightposition idx that corresponds to a bank, map tuple
     * @param bank the mapbank
     * @param map the mapid in the bank
     * @return the corresponding flightposition idx + 1 or 0 if none matches
     */
    int map_get_flightposition(u8 bank, u8 map);

    /**
     * Returns the offset on a flight position by its index + 1
     * @param idx_plus_one the index of the flight position plus one
     * @return the flight pos offset
     */
    stru_flight_position *flightposition_by_id(int idx_plus_one);

    /**
     * Gets the namespace id associated with a position on the worldmap
     * @param worldmap_index which worldmap to use
     * @param layer the town or locality layer
     * @param x the x coordinate (in tiles)
     * @param y the y coordinate (in tiles)
     * @return the namespace id
     */
    u8 worldmap_get_namespace_by_pos(u8 worldmap_index, u8 layer, u16 x, u16 y);

    /**
     * Sets the state corresponding to a worldmapflag (needed as well to set the worldmapflag)
     * @param flag the flag to set
     */
    void worldmap_flag_state_set(u16 flag);

    /**
     * Sets a worldmap flag (the state needs to be set as well!)
     * @param flag the flag to set
     */
    void worldmap_flag_set(u16 flag);

    /**
     * Locates the player on the current worldmap (saves x, y to the worldmap state).
     */
    void worldmap_locate_player();

#ifdef	__cplusplus
}
#endif

#endif	/* WORLDMAP_H */

