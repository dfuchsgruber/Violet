/**
 * Alternative dungeon generator module for more natural dungeons. 
 *
 */

#include "types.h"
#include "map.h"
#include "save.h"
#include "tile.h"
#include "dungeon2.h"
#include "debug.h"
#include "utils.h"
#include "romfuncs.h"



u8 *dungeon2_iterate(u8 *map, int rule, dungeon_generator2 *dg2){
    dprintf("Iterating map with rule %d\n", rule);
    u8 *map2 = malloc((u32)(dg2->width * dg2->height));
    for(int x = 0; x < dg2->width; x++){
        for(int y = 0; y < dg2->height; y++){
            //Count wall neighbours of x, y
            int adjacent_walls = 0;
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(x + i >= 0 && x + i < dg2->width &&
                            y + j >= 0 && y + j < dg2->height){
                        if(map[(y + j) * dg2->height + x + i] == DG2_WALL)
                            adjacent_walls++;
                    }
                     
                }
            }
            if(adjacent_walls >= rule || adjacent_walls == 0)
                map2[y * dg2->height + x] = DG2_WALL;
            else
                map2[y * dg2->height + x] = DG2_SPACE;
        }
    }
    
    free(map);
    return map2;
}

void dungeon2_enclose(u8 *map, int width, int height){
    for(int i = 0; i < width; i++){
        map[i] = DG2_WALL;
        map[(height - 1) * width + i] = DG2_WALL;
    }
    for(int i = 0; i < height; i++){
        map[i * width] = DG2_WALL;
        map[(i * width) + width - 1] = DG2_WALL;
    }
}

int dg2_cross_neighbourhood[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dungeon2_next_node(int *result, dungeon_generator2 *dg2){
    int margin = dg2->iterations + 1; // The margin to the borders of the map
                                      // to prevent overflowing when iterating
    int xrange = dg2->width - 2 * margin;
    int yrange = dg2->height - 2 * margin;
    if(xrange <= 0 || yrange <= 0){
        derrf("Parameters for dungeon2 allow no node generation!\n");
    }
    int x = margin + (dungeon2_rnd(dg2) % xrange);
    int y = margin + (dungeon2_rnd(dg2) % yrange);
    result[0] = x;
    result[1] = y;
    
}

void dungeon2_connect_nodes(int *a, int *b, dungeon_generator2 *dg2, u8 *map){
    int x0 = a[0]; int y0 = a[1];
    int x1 = b[0]; int y1 = b[1];
    dprintf("Dungeon2: Connecting %d, %d to %d, %d\n", x0, y0, x1, y1);
    
    map[y0 * dg2->height + x0] = DG2_SPACE;
    while(x0 != x1 || y0 != y1){
        int i, j;
        if(dungeon2_rnd(dg2) < dg2->randomness){
            //Pick any adjacent tile
            int next = dungeon2_rnd(dg2) & 3;
            i = dg2_cross_neighbourhood[next][0];
            j = dg2_cross_neighbourhood[next][1];
        }else{
            //Pick the optimal adjacent tile
            int dx = x1 - x0; int dy = y1 - y0;
            if(abs(dx) > abs(dy)){
                i = signum(dx); j = 0;
            }else{
                i = 0; j = signum(dy);
            }
        }
        //dprintf("Picked delta %d, %d\n", i, j);
        //Check if i and j are valid
        if(x0 + i >= 0 && x0 + i < dg2->width && y0 + j >= 0 && y0 + j < dg2->height){
            x0 += i;
            y0 += j;
            map[y0 * dg2->height + x0] = DG2_SPACE;
        }
    }
}

u8 *dungeon2_init(dungeon_generator2 *dg2){
    u8 *map = cmalloc((u32)(dg2->width * dg2->height));
    
    int nodes[dg2->nodes + 1][2];
    dungeon2_next_node(nodes[0], dg2); //Initial node
    for(int i = 1; i <= dg2->nodes; i++){
        //Pick any node a
        int *a = nodes[dungeon2_rnd(dg2) % i];
        dungeon2_next_node(nodes[i], dg2);
        dungeon2_connect_nodes(a, nodes[i], dg2, map);
    }
    return map;
}

u8 *dungeon2_create(dungeon_generator2 *dg2){
    u8 *map = dungeon2_init(dg2);
    for(int i = 0; i < dg2->iterations; i++){
        map = dungeon2_iterate(map, 9 - dg2->iterations + i, dg2);
        dungeon2_enclose(map, dg2->width, dg2->height);
    }
    return map;
}


u16 dungeon2_rnd(dungeon_generator2 *dg2){
    dg2->seed = (u32) (
            dg2->seed * DG2_RND_MULTIPLIER + DG2_RND_INCREMENT);
    //dprintf("D2PRNG next seed 0x%x\n", dg2->seed);
    return (u16)(dg2->seed >> 16);
}