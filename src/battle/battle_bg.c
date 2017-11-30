#include "types.h"
#include "romfuncs.h"
#include "battle.h"
#include "gfx.h"
#include "attack.h"
#include "tile.h"

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

u8 battle_bg_by_tile(){
    coordinate pos;
    get_current_tile_position(&pos.x, &pos.y);
    u8 bg_id = (u8)tile_get_field_by_pos(pos.x, pos.y, 3);
    u16 (*f)(s16, s16) = (u16(*)(s16, s16))0x08058E49;
    dprintf("battle_bg_by_tile x %d, y %d, bg %d, block %d, block data %d\n", pos.x, pos.y, bg_id, f(pos.x, pos.y), tile_get_field_by_pos(pos.x, pos.y, 8));
    return bg_id;
}

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
    //dprintf("Battle bg id is %d\n", *battle_bg_id);
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

battle_anim_bg battle_anim_bgs[] = {
        {(void*)0x8d1c9bc, (void*)0x8d1cfb4, (void*)0x8d1cfd4}, //0x0
	{(void*)0x8d1c9bc, (void*)0x8d1cfb4, (void*)0x8d1cfd4}, //0x1
	{(void*)0x8e7bf7c, (void*)0x8e7cc44, (void*)0x8e7cc60}, //0x2
	{(void*)0x8d1ea84, (void*)0x8d1ec54, (void*)0x8d1ec78}, //0x3
	{(void*)0x8d25db4, (void*)0x8d25d8c, (void*)0x8d26b20}, //0x4
	{(void*)0x8d25db4, (void*)0x8d25d8c, (void*)0x8d2701c}, //0x5
	{(void*)0x8d25db4, (void*)0x8d25d8c, (void*)0x8d274ec}, //0x6
	{(void*)0x8d28aec, (void*)0x8d28c94, (void*)0x8d28ce4}, //0x7
	{(void*)0x8d28aec, (void*)0x8d28c94, (void*)0x8d28e74}, //0x8
	{(void*)0x8d29f84, (void*)0x8d29f44, (void*)0x8d29c4c}, //0x9
	{(void*)0x8d29f84, (void*)0x8d29f44, (void*)0x8d2a504}, //0xa
	{(void*)0x8d2bfac, (void*)0x8d2c948, (void*)0x8d2c970}, //0xb
	{(void*)0x8d2b224, (void*)0x8d2bf8c, (void*)0x8d2a9d0}, //0xc
	{(void*)0x8d2b224, (void*)0x8d2bf8c, (void*)0x8d2ac98}, //0xd
	{(void*)0x8d2b224, (void*)0x8d2bf8c, (void*)0x8d2af94}, //0xe
	{(void*)0x8e79bec, (void*)0x8e7a55c, (void*)0x8e7a580}, //0xf
	{(void*)0x8e7ea30, (void*)0x8e7ea08, (void*)0x8e7ec90}, //0x10
	{(void*)0x8e7b31c, (void*)0x8e7b478, (void*)0x8e7b4a0}, //0x11
	{(void*)0x8d28aec, (void*)0x8d28cbc, (void*)0x8d28ce4}, //0x12
	{(void*)0x8d28aec, (void*)0x8d28cbc, (void*)0x8d28e74}, //0x13
	{(void*)0x8d29000, (void*)0x8d29a28, (void*)0x8d29a48}, //0x14
	{(void*)0x8e7ff64, (void*)0x8e80258, (void*)0x8e80274}, //0x15
	{(void*)0x8d29f84, (void*)0x8d29f64, (void*)0x8d29c4c}, //0x16
	{(void*)0x8d29f84, (void*)0x8d29f64, (void*)0x8d2a504}, //0x17
	{(void*)0x8d25db4, (void*)0x8e7cf7c, (void*)0x8d26b20}, //0x18
	{(void*)0x8d25db4, (void*)0x8e7cf7c, (void*)0x8d2701c}, //0x19
	{(void*)0x8d25db4, (void*)0x8e7cf7c, (void*)0x8d274ec}, //0x1a
	{(void*)0x80727cd, (void*)0x8072835, (void*)0x8072881}, //0x1b
	{(void*)0x8072975, (void*)0x80729f1, (void*)0x8072a31}, //0x1c
	{(void*)0x8072a65, (void*)0x8072a69, (void*)0x8072a6d}, //0x1d
	{(void*)0x8072b6d, (void*)0x8072b95, (void*)0x80731b1}, //0x1e
	{(void*)0x8073545, (void*)0x80735a5, (void*)0x80735c9}, //0x1f
	{(void*)0x80735fd, (void*)0x8073611, (void*)0x8073645}, //0x20
	{(void*)0x8073685, (void*)0x80736c9, (void*)0x8073705}, //0x21
	{(void*)0x80738dd, (void*)0x8073921, (void*)0x8073955}, //0x22
	{(void*)0x8073989, (void*)0x8073b2d, (void*)0x8073b65}, //0x23
	{(void*)0x8073b91, (void*)0x8073e35, (void*)0x8073f19}, //0x24
	{(void*)0x807357d, (void*)0x8073fd1, (void*)0x8074045}, //0x25
	{(void*)0x80740c9, (void*)0x8073301, (void*)0x80733e9}, //0x26
	{(void*)0x807411d, (void*)0x8073749, (void*)0x8073ce1}, //0x27
	{(void*)0x8073d75, (void*)0x807412d, (void*)0x8074179}, //0x28
	{(void*)0x80741a1, (void*)0x8074209, (void*)0x8074245}, //0x29
	{(void*)0x8074285, (void*)0x807432d, (void*)0x80743bd},//0x2a
        {gfx_stance_changeTiles, gfx_stance_changePal, gfx_stance_changeMap}//0x2b
};