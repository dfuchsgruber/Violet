
#include "types.h"
#include "map/header.h"
#include "save.h"
#include "dungeon2.h"
#include "debug.h"
#include "romfuncs.h"
#include "constants/map_weathers.h"
#include "map/footer.h"

extern tileset maptileset0;
extern tileset maptileset15;

u16 dungeon2_forest_borders[4] = {0x5e, 0x5e, 0x5e, 0x5e};

map_connections dungeon2_connections = {0, NULL};

levelscript_head dungeon2_lscr [] = {
    {0, {0, 0, 0, 0} }
};

#define DG2_WIDTH 50
#define DG2_HEIGHT 50
#define DG2_PATH_RANDOMNESS 45875 //0.7
#define DG2_INIT_RANDOMNESS 26214 //0.4
#define DG2_NODES 25
#define DG2_MARGIN 3

map_block dungeon2_map_empty[DG2_WIDTH * DG2_HEIGHT] = {0};

mapheader *dungeon2_init_header_forest() {

    //(*save1)->flash_circle_size = 1;
    dprintf("D2 header init\n");
    fmem->dmap_header_initialized = 1;
    cmem->dmapheader.levelscripts = dungeon2_lscr;
    cmem->dmapheader.connections = &dungeon2_connections;
    cmem->dmapheader.music = 0x14b;
    cmem->dmapheader.map_index = 0x1c1; //test index
    cmem->dmapheader.flash = 0;
    cmem->dmapheader.weather = MAP_WEATHER_INSIDE;
    cmem->dmapheader.type = 0;
    cmem->dmapheader.show_name = 0;
    cmem->dmapheader.battle_style = 0;
    return &(cmem->dmapheader);
}

mapfooter *dungeon2_init_footer_forest(dungeon_generator2 *dg2){
    dprintf("D2 footer init\n");
    cmem->dmapfooter.width = (u32)dg2->width;
    cmem->dmapfooter.height = (u32)dg2->height;
    cmem->dmapfooter.tileset1 = &maptileset0;
    cmem->dmapfooter.tileset2 = &maptileset15;
    cmem->dmapfooter.border_blocks = dungeon2_forest_borders;
    cmem->dmapfooter.border_width = 2;
    cmem->dmapfooter.border_height = 2;
    cmem->dmapfooter.map = dungeon2_map_empty;
    return &(cmem->dmapfooter);
}

map_events *dungeon2_init_events_forest(dungeon_generator2 *dgen){
    dprintf("D2 event init\n");
    (void)dgen;
    cmem->devents.person_cnt = 0;
    cmem->devents.warp_cnt = 0;
    cmem->devents.script_cnt = 0;
    cmem->devents.signpost_cnt = 0;
    return &(cmem->devents);
}


u16 dungeon2_compute_block_forest(u8 *map, u8 *over, int x, int y, dungeon_generator2 *dg2){
    int height = dg2->height;
    if(map[y * height + x] == DG2_SPACE){
        if(over[y * height + x] == DG2_SPACE) return 0x10; //High grass
        else{
            //Count grass, wall neighbours
            int grass_neighbours = 0;
            int wall_neighbours = 0;
            for(int k = 0; k < 4; k++){
                int i = dg2_cross_neighbourhood[k][0];
                int j = dg2_cross_neighbourhood[k][1];
                if(x + i >= 0 && x + i < dg2->width &&
                        y + j >= 0 && y + j < dg2->height){
                    if(over[(y + j) * dg2->height + x + i] == DG2_SPACE &&
                        map[(y + j) * dg2->height + x + i] == DG2_SPACE)
                        grass_neighbours++;
                    else if(map[(y + j) * dg2->height + x + i] == DG2_WALL)
                        wall_neighbours++;
                }
            }
            if((int)dungeon2_rnd(dg2) < grass_neighbours * 0x3000){
                return 0x11; //Cut grass
            }
            if((int)dungeon2_rnd(dg2) < wall_neighbours * 0x1000){
                u16 decoratives[16] = {
                    0x18, 0x19, 0x20, 0x21, 0x28, 0x29, 0x8, 0x9,
                    0xA, 0xA, 0xA, 0xA, 0xB, 0xB, 0xB, 0xB
                };
                return decoratives[dungeon2_rnd(dg2) % 16];
            }
            if(dungeon2_rnd(dg2) < 0x400) return 0xC;
            return 0x1;
        }
    }
    bool wall_above = true;
    if(y > 0) wall_above = map[(y - 1) * height + x] == DG2_WALL;
    bool wall_below = true;
    if(y < height - 1) wall_below = map[(y + 1) * height + x] == DG2_WALL;
    if(wall_above && wall_below) return 0x5E;
    if(wall_above) return 0x67;
    if(wall_below){
        if(over[y * height + x] == DG2_SPACE) return 0x5C; 
        else return 0x5F;
    }
     
    return 0x12;

}

void dungeon2_compute_blocks_forest(u8 *map, u8 *over, dungeon_generator2 *dg2){
    for(int x = 0; x < dg2->width; x++){
        for(int y = 0; y < dg2->height; y++){
            /*TODO*/
            u16 block = dungeon2_compute_block_forest(map, over, x, y, dg2);
            //dprintf("DG2 block %x, %x -> %x\n", x, y, block);
            set_block_id((s16)(x + 7), (s16)(y + 7), block);
        }
    }
}

void dungeon2_compute_forest(){
    dprintf("D2 compute...\n");
    dungeon_generator2 *dg2 = &(cmem->dg2);
    dg2->seed = dg2->initial_seed;
    dprintf("Seed is %x\n", dg2->seed);
    fmem->dmap_blocks_initialized = 1;
    
    u8 *map = dungeon2_create_connected_layout(dg2);
    u8 *over = dungeon2_create_patch_layout(dg2);
    
    dungeon2_compute_blocks_forest(map, over, dg2);
    free(map);
    
    
    mapheader_virtual->footer = &(cmem->dmapfooter);
    //special_x8E_update_map_graphics();
    
}

void dungeon2_init_map_interface_forest(){
    
    u32 seed = (u32)(rnd16() << 16 | rnd16());
    
    //Initialize generator instance
    dungeon_generator2 *dg2 = &(cmem->dg2);
    dg2->initial_seed = seed;
    dg2->seed = dg2->initial_seed;
    dg2->width = DG2_WIDTH;
    dg2->height = DG2_HEIGHT;
    dg2->path_randomness = DG2_PATH_RANDOMNESS;
    dg2->init_randomness = DG2_INIT_RANDOMNESS;
    dg2->nodes = DG2_NODES;
    dg2->margin = DG2_MARGIN;
    
    dungeon2_init_header_forest();
    dungeon2_init_events_forest(dg2);
    dungeon2_init_footer_forest(dg2);
}

void dungeon2_compute(int dungeon_type){
    dprintf("Computing dungeon type %d\n", dungeon_type);
    switch(dungeon_type){
        case DTYPE_FOREST:
            dungeon2_compute_forest();
            break;
        case DTYPE_CAVE:
            derrf("Cave dungeon not implemented yet...\n");
            break;
    }
}
