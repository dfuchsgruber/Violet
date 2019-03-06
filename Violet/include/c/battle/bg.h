/*
 * bg.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_BG_H_
#define INCLUDE_C_BATTLE_BG_H_


typedef struct battle_bg {
    const void *tileset;
    const void *tilemap;
    const void *anim_tileset;
    const void *anim_tilemap;
    const void *pal;
} battle_bg;

typedef struct  {
    const void *tileset;
    const void *pal;
    const void *map;
} battle_anim_bg;

battle_bg battle_bgs[29];

u8 battle_bg_get_id();

// Battle bg
extern const unsigned short gfx_battle_bg_capturedTiles[];
extern const unsigned short gfx_battle_bg_caveTiles[];
extern const unsigned short gfx_battle_bg_cloudsTiles[];
extern const unsigned short gfx_battle_bg_desertTiles[];
extern const unsigned short gfx_battle_bg_evolutionTiles[];
extern const unsigned short gfx_battle_bg_fireTiles[];
extern const unsigned short gfx_battle_bg_grassTiles[];
extern const unsigned short gfx_battle_bg_gymTiles[];
extern const unsigned short gfx_battle_bg_millTiles[];
extern const unsigned short gfx_battle_bg_mountainTiles[];
extern const unsigned short gfx_battle_bg_museumTiles[];
extern const unsigned short gfx_battle_bg_oceanTiles[];
extern const unsigned short gfx_battle_bg_pondTiles[];
extern const unsigned short gfx_battle_bg_shoreTiles[];
extern const unsigned short gfx_battle_bg_streetTiles[];
extern const unsigned short gfx_battle_bg_watercaveTiles[];

extern const unsigned short gfx_battle_bg_capturedPal[];
extern const unsigned short gfx_battle_bg_cavePal[];
extern const unsigned short gfx_battle_bg_cloudsPal[];
extern const unsigned short gfx_battle_bg_desertPal[];
extern const unsigned short gfx_battle_bg_evolutionPal[];
extern const unsigned short gfx_battle_bg_firePal[];
extern const unsigned short gfx_battle_bg_grassPal[];
extern const unsigned short gfx_battle_bg_gymPal[];
extern const unsigned short gfx_battle_bg_millPal[];
extern const unsigned short gfx_battle_bg_mountainPal[];
extern const unsigned short gfx_battle_bg_museumPal[];
extern const unsigned short gfx_battle_bg_oceanPal[];
extern const unsigned short gfx_battle_bg_pondPal[];
extern const unsigned short gfx_battle_bg_shorePal[];
extern const unsigned short gfx_battle_bg_streetPal[];
extern const unsigned short gfx_battle_bg_watercavePal[];

extern const unsigned short gfx_battle_bg_capturedMap[];
extern const unsigned short gfx_battle_bg_caveMap[];
extern const unsigned short gfx_battle_bg_cloudsMap[];
extern const unsigned short gfx_battle_bg_desertMap[];
extern const unsigned short gfx_battle_bg_evolutionMap[];
extern const unsigned short gfx_battle_bg_fireMap[];
extern const unsigned short gfx_battle_bg_grassMap[];
extern const unsigned short gfx_battle_bg_gymMap[];
extern const unsigned short gfx_battle_bg_millMap[];
extern const unsigned short gfx_battle_bg_mountainMap[];
extern const unsigned short gfx_battle_bg_museumMap[];
extern const unsigned short gfx_battle_bg_oceanMap[];
extern const unsigned short gfx_battle_bg_pondMap[];
extern const unsigned short gfx_battle_bg_shoreMap[];
extern const unsigned short gfx_battle_bg_streetMap[];
extern const unsigned short gfx_battle_bg_watercaveMap[];

// Battle anim bg
extern const unsigned short gfx_stance_changeTiles[];
extern const unsigned short gfx_stance_changePal[];
extern const unsigned short gfx_stance_changeMap[];


#endif /* INCLUDE_C_BATTLE_BG_H_ */
