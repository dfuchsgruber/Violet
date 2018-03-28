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

    typedef struct{
        u8 bank;
        u8 map;
        s16 x;
        s16 y;
        u16 field_6;
    } stru_flight_position;
    
    stru_flight_position flight_positions[];


    int *worldmap_tilemaps[4];
    u8 *namespace_worldmap_associations;
    extern const unsigned short gfx_worldmapTiles[];
    extern const unsigned short gfx_worldmapPal[];


#ifdef	__cplusplus
}
#endif

#endif	/* WORLDMAP_H */

