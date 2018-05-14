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
    
    stru_flight_position flight_positions[NUM_FLIGHT_POSITONS];


    int *worldmap_tilemaps[4];
    u8 *namespace_worldmap_associations;
    extern const unsigned short gfx_worldmapTiles[];
    extern const unsigned short gfx_worldmapPal[];

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

#ifdef	__cplusplus
}
#endif

#endif	/* WORLDMAP_H */

