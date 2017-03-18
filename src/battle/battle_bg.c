#include "types.h"
#include "romfuncs.h"
#include "battle.h"
#include "gfx.h"
#include "attack.h"


battle_bg battle_bgs[29] = {
    // Battle street
    {
        gfx_battle_bg_streetTiles,
        gfx_battle_bg_streetMap,
        NULL,
        NULL,
        gfx_battle_bg_streetPal
    },
    // Battle grass
    {
        gfx_battle_bg_grassTiles,
        gfx_battle_bg_grassMap,
        NULL,
        NULL,
        gfx_battle_bg_grassPal
    },
    // Battle mountain
    {
        gfx_battle_bg_mountainTiles,
        gfx_battle_bg_mountainMap,
        NULL,
        NULL,
        gfx_battle_bg_mountainPal
    },
    // Battle pond
    {
        gfx_battle_bg_pondTiles,
        gfx_battle_bg_pondMap,
        NULL,
        NULL,
        gfx_battle_bg_pondPal
    },
    // Battle cloud
    {
        gfx_battle_bg_cloudsTiles,
        gfx_battle_bg_cloudsMap,
        NULL,
        NULL,
        gfx_battle_bg_cloudsPal
    },
    // Battle shore
    {
        gfx_battle_bg_shoreTiles,
        gfx_battle_bg_shoreMap,
        NULL,
        NULL,
        gfx_battle_bg_shorePal
    },
    // Battle ocean
    {
        gfx_battle_bg_oceanTiles,
        gfx_battle_bg_oceanMap,
        NULL,
        NULL,
        gfx_battle_bg_oceanPal
    },
    // Battle cave
    {
        gfx_battle_bg_caveTiles,
        gfx_battle_bg_caveMap,
        NULL,
        NULL,
        gfx_battle_bg_cavePal
    },
    // Battle bg desert
    {
        gfx_battle_bg_desertTiles,
        gfx_battle_bg_desertMap,
        NULL,
        NULL,
        gfx_battle_bg_desertPal
    },
    // Battle bg gym
    {
        gfx_battle_bg_gymTiles,
        gfx_battle_bg_gymMap,
        NULL,
        NULL,
        gfx_battle_bg_gymPal
    },
    // Battle bg watercave
    {
        gfx_battle_bg_watercaveTiles,
        gfx_battle_bg_watercaveMap,
        NULL,
        NULL,
        gfx_battle_bg_watercavePal
    },
    // Battle bg 11
    {
        gfx_battle_bg_museumTiles,
        gfx_battle_bg_museumMap,
        NULL,
        NULL,
        gfx_battle_bg_museumPal
    },
    // Battle bg 12
    {
        gfx_battle_bg_fireTiles,
        gfx_battle_bg_fireMap,
        NULL,
        NULL,
        gfx_battle_bg_firePal
    },
    // Battle evol 13
    {
        gfx_battle_bg_evolutionTiles,
        gfx_battle_bg_evolutionMap,
        NULL,
        NULL,
        gfx_battle_bg_evolutionPal
    },
    // Battle bg captured 14
    {
        gfx_battle_bg_capturedTiles,
        gfx_battle_bg_capturedMap,
        NULL,
        NULL,
        gfx_battle_bg_capturedPal
    },
    // Battle bg wooden mill 15
    {
        gfx_battle_bg_millTiles,
        gfx_battle_bg_millMap,
        NULL,
        NULL,
        gfx_battle_bg_millPal
    },
    // Battle bg 28

};

void battle_bg_load(u8 id){
    lz77uncompvram(battle_bgs[id].tileset, (void*) 0x6008000);
    lz77uncompvram(battle_bgs[id].tilemap, (void*) 0x600d000);
    pal_load_comp(battle_bgs[id].pal, 0x20, 0x60);
}

void battle_bg_load_anim(u8 id){
    (void)id;
    return;
}

void battle_bg_get(u8 id, const void **set, const void **map, const void **pal){
    *set = battle_bgs[id].tileset;
    *map = battle_bgs[id].tilemap;
    *pal = battle_bgs[id].pal;
}

u8 battle_bg_get_id(){
    u8 *battle_bg_id = (u8*)0x2022B50;
    return *battle_bg_id;
}

u16 terrain_moves[] = {
    ATTACK_STERNSCHAUER,
    ATTACK_STACHELSPORE,
    ATTACK_STEINHAGEL,
    ATTACK_AQUAWELLE,
    
    ATTACK_WINDSCHNITT,
    ATTACK_SCHAUFLER,
    ATTACK_SURFER,
    ATTACK_SPUKBALL,
    
    ATTACK_ERDBEBEN,
    ATTACK_HYPERSTRAHL,
    ATTACK_NASSMACHER, //inside cave route4, kaskada
    ATTACK_ANTIK_KRAFT, //museum
    
    ATTACK_FLAMMENWURF, //fire route
    0, //evolution
    0, //captured
    ATTACK_SCHNABEL, //mill
};