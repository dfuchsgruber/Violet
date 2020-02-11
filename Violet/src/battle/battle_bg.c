#include "types.h"
#include "battle/bg.h"
#include "battle/attack.h"
#include "constants/attacks.h"
#include "constants/vars.h"
#include "tile/coordinate.h"
#include "tile/block.h"
#include "color.h"
#include "bios.h"
#include "vars.h"
#include "battle/battler.h"
#include "battle/battlescript.h"
#include "battle/state.h"
#include "constants/battle_bgs.h"
#include "constants/pokemon_types.h"
#include "attack.h"
#include "save.h"
#include "map/tileset.h"
#include "debug.h" 
 
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
    // Battle bg graveyard 15
    [BATTLE_BG_GRAVEYARD] = {
        gfx_battle_bg_graveyardTiles,
        gfx_battle_bg_graveyardMap,
        NULL,
        NULL,
        gfx_battle_bg_graveyardPal
    },
    [BATTLE_BG_HAWEILAND] = {
        gfx_battle_bg_haweilandTiles,
        gfx_battle_bg_haweilandMap,
        NULL, NULL,
        gfx_battle_bg_haweilandPal
    },
    [BATTLE_BG_CLOUD_RUINS] = {
        gfx_battle_bg_cloud_ruinsTiles,
        gfx_battle_bg_cloud_ruinsMap,
        NULL, NULL,
        gfx_battle_bg_cloud_ruinsPal,
    },
    [BATTLE_BG_CARGO_HALL] = {
        gfx_battle_bg_cargo_hallTiles,
        gfx_battle_bg_cargo_hallMap,
        NULL, NULL,
        gfx_battle_bg_cargo_hallPal
    },
    [BATTLE_BG_ARDEAL_CLOUD] = {
        gfx_battle_bg_ardeal_cloudTiles,
        gfx_battle_bg_ardeal_cloudMap,
        NULL, NULL,
        gfx_battle_bg_ardeal_cloudPal,
    },
    [BATTLE_BG_ARDEAL] = {
        gfx_battle_bg_ardealTiles,
        gfx_battle_bg_ardealMap,
        NULL, NULL,
        gfx_battle_bg_ardealPal,
    },
    [BATTLE_BG_ARDEAL_DUNGEON] = {
        gfx_battle_bg_ardeal_dungeonTiles,
        gfx_battle_bg_ardeal_dungeonMap,
        NULL, NULL,
        gfx_battle_bg_ardeal_dungeonPal,
    },
};


void battle_bg_load_anim(u8 id){
    (void)id;
    id = battle_bg_get_id();
    lz77uncompvram(0, (void*)0x6004000);
    lz77uncompvram(0, (void*)0x600E000);
    return;
}

void battle_bg_get(u8 id, const void **set, const void **map, const void **pal){
    id = battle_bg_get_id();
    *set = battle_bgs[id].tileset;
    *map = battle_bgs[id].tilemap;
    *pal = battle_bgs[id].pal;
}

u8 battle_bg_get_id(){
    u16 *var_override = var_access(BATTLE_BG_OVERRIDE);
    //dprintf("Battle bg var override is %d\n", *var_override);
    if(*var_override)
        return (u8)(*var_override - 1);
    coordinate_t pos;
    player_get_coordinates(&pos.x, &pos.y);
    u8 bg_id = (u8)block_get_field_by_pos(pos.x, pos.y, 3);
    // In regions that use the Haweiland-Tileset, the shore background is replaced by the haweiland tileset
    // dprintf("bgid %d, ts2 %x, mtshaw %x\n", bg_id, &mapfooter_virtual.tileset2, &maptileset_haweiland);
    if (bg_id == BATTLE_BG_SHORE && mapheader_virtual.footer->tileset2 == &maptileset_haweiland) {
        bg_id = BATTLE_BG_HAWEILAND;
    }
    return bg_id;
}


void bsc_cmd_xEB_set_type_to_terrain() {
	bsc_offset++;
	u8 type;
	switch (battle_bg_get_id()) {
	case BATTLE_BG_GRASS:
		type = TYPE_PFLANZE;
		break;
	case BATTLE_BG_GYM:
		type = TYPE_KAMPF;
		break;
	case BATTLE_BG_CAVE:
	case BATTLE_BG_MOUNTAIN:
	case BATTLE_BG_MUSEUM:
    case BATTLE_BG_CLOUD_RUINS:
		type = TYPE_GESTEIN;
		break;
	case BATTLE_BG_MILL:
	case BATTLE_BG_CLOUD:
    case BATTLE_BG_ARDEAL_CLOUD:
		type = TYPE_FLUG;
		break;
	case BATTLE_BG_OCEAN:
	case BATTLE_BG_SHORE:
    case BATTLE_BG_HAWEILAND:
	case BATTLE_BG_POND:
	case BATTLE_BG_WATER_CAVE:
		type = TYPE_WASSER;
		break;
	case BATTLE_BG_DESERT:
		type = TYPE_BODEN;
		break;
	case BATTLE_BG_FIRE:
		type = TYPE_FEUER;
		break;
	default:
	case BATTLE_BG_EVOLUTION:
	case BATTLE_BG_CAPTURE:
	case BATTLE_BG_STREET:
    case BATTLE_BG_CARGO_HALL:
		type = TYPE_NORMAL;
		break;
    case BATTLE_BG_GRAVEYARD:
        type = TYPE_GEIST;
        break;
    case BATTLE_BG_ARDEAL:
        type = TYPE_PSYCHO;
        break;
    case BATTLE_BG_ARDEAL_DUNGEON:
        type = TYPE_UNLICHT;
        break;
	}
	if (type == battlers[attacking_battler].type1 ||
			type == battlers[attacking_battler].type2) {
		bsc_offset = (u8*)bsc_get_word();
	} else {
		bsc_offset += 4;
	}
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
    [BATTLE_BG_GRAVEYARD] = ATTACK_SPUKBALL,
    [BATTLE_BG_HAWEILAND] = ATTACK_EIERBOMBE,
    [BATTLE_BG_CLOUD_RUINS] = ATTACK_KRAFTRESERVE,
    [BATTLE_BG_CARGO_HALL] = ATTACK_TRICKBETRUG,
    [BATTLE_BG_ARDEAL_CLOUD] = ATTACK_WINDSCHNITT,
    [BATTLE_BG_ARDEAL] = ATTACK_PSYCHOKINESE,
    [BATTLE_BG_ARDEAL_DUNGEON] = ATTACK_FINSTERAURA,
};

void bsc_cmd_xCC_set_terrain_based_move(){
	battle_flags &= (u32)(~BATTLE_ROAMER);
    active_attack = terrain_moves[battle_bg_get_id()];
	defending_battler = attack_get_target_of_active_battler(active_attack, false);
	u8 *attack_script = attack_effects[attacks[active_attack].effect];
	battlescript_callstack_push(attack_script);
	bsc_offset++;
}
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


