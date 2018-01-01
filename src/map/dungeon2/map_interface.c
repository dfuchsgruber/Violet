
#include "types.h"
#include "map.h"
#include "save.h"
#include "tile.h"
#include "dungeon2.h"
#include "debug.h"
#include "utils.h"
#include "romfuncs.h"
#include "mapevents.h"

extern tileset maptileset0;
extern tileset maptileset15;

u16 dungeon2_borders[4] = {0x292, 0x291, 0x291, 0x291};

map_connections dungeon2_connections = {0, NULL};

levelscript_head dungeon2_lscr [] = {
    {0, {0, 0, 0, 0} }
};

#define DG2_WIDTH 50
#define DG2_HEIGHT 50
#define DG2_RANDOMNESS 45875
#define DG2_NODES 25
#define DG2_ITERATIONS 3

map_block dungeon2_map_empty[DG2_WIDTH * DG2_HEIGHT] = {0};

mapheader *dungeon2_init_header() {

    //(*save1)->flash_circle_size = 1;
    dprintf("D2 header init\n");
    dflags->header_initialized = 1;
    cmem->dhead.levelscripts = dungeon2_lscr;
    cmem->dhead.connections = &dungeon2_connections;
    cmem->dhead.music = 0x14b;
    cmem->dhead.map_index = 0x1c1; //test index
    cmem->dhead.flash = 0;
    cmem->dhead.weather = WEATHER_INSIDE;
    cmem->dhead.type = 0;
    cmem->dhead.show_name = 0;
    cmem->dhead.battle_style = 0;
    return &(cmem->dhead);
}

mapfooter *dungeon2_init_footer(dungeon_generator2 *dg2){
    dprintf("D2 footer init\n");
    cmem->footer.width = (u32)dg2->width;
    cmem->footer.height = (u32)dg2->height;
    cmem->footer.tileset1 = &maptileset0;
    cmem->footer.tileset2 = &maptileset15;
    cmem->footer.border_blocks = dungeon2_borders;
    cmem->footer.border_width = 2;
    cmem->footer.border_height = 2;
    cmem->footer.map = dungeon2_map_empty;
    return &(cmem->footer);
}

map_events *dungeon2_init_events(dungeon_generator2 *dgen){
    dprintf("D2 event init\n");
    (void)dgen;
    cmem->devents.person_cnt = 0;
    cmem->devents.warp_cnt = 0;
    cmem->devents.script_cnt = 0;
    cmem->devents.signpost_cnt = 0;
    return &(cmem->devents);
}

void dungeon2_compute_blocks(u8 *map, dungeon_generator2 *dg2){
    for(int x = 0; x < dg2->width; x++){
        for(int y = 0; y < dg2->height; y++){
            /*TODO*/
            u16 block = map[y * dg2->height + x] == DG2_WALL ? 0x291 : 0x281;
            //dprintf("DG2 block %x, %x -> %x\n", x, y, block);
            set_block_id((s16)(x + 7), (s16)(y + 7), block);
        }
    }
}

void dungeon2_compute(){
    dprintf("D2 compute...\n");
    dungeon_generator2 *dg2 = &(cmem->dg2);
    dg2->seed = dg2->initial_seed;
    dprintf("Seed is %x\n", dg2->seed);
    dflags->blocks_initialized = 1;
    
    u8 *map = dungeon2_create(dg2);
    dungeon2_compute_blocks(map, dg2);
    free(map);
    
    
    foot_ddata->footer = &(cmem->footer);
    //special_x8E_update_map_graphics();
    
}

void dungeon2_init_map_interface(){
    
    u32 seed = (u32)(random_change_seed() << 16 | random_change_seed());
    
    //Initialize generator instance
    dungeon_generator2 *dg2 = &(cmem->dg2);
    dg2->initial_seed = seed;
    dg2->seed = dg2->initial_seed;
    dg2->width = DG2_WIDTH;
    dg2->height = DG2_HEIGHT;
    dg2->randomness = DG2_RANDOMNESS;
    dg2->nodes = DG2_NODES;
    dg2->iterations = DG2_ITERATIONS;
    
    dungeon2_init_header();
    dungeon2_init_events(dg2);
    dungeon2_init_footer(dg2);
}
