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



void dungeon2_iterate(u8 *map, u8 *map2, int near_lower_bound, int far_upper_bound, dungeon_generator2 *dg2){
    dprintf("Iterating map with nlb %d and hub %d\n", near_lower_bound, far_upper_bound);
    for(int x = 1; x < dg2->width - 1; x++){
        for(int y = 1; y < dg2->height - 1; y++){
            //Count wall neighbours of x, y
            int nn = 0;
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(map[(y + j) * dg2->height + x + i] == DG2_WALL)
                        nn++;
                }
            }
            int fn = 0;
            for(int i = -2; i <= 2; i++){
                for(int j = -2; j <= 2; j++){
                    if(abs(i) == 2 && abs(j) == 2) continue;
                    if(map[(y + j) * dg2->height + x + i] == DG2_WALL)
                        fn++;
                }
            }
            if(nn >= near_lower_bound || fn <= far_upper_bound)
                map2[y * dg2->height + x] = DG2_WALL;
            else
                map2[y * dg2->height + x] = DG2_SPACE;
        }
    }
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

void dungeon2_next_node(int *result, int margin, dungeon_generator2 *dg2){
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
        if(dungeon2_rnd(dg2) < dg2->path_randomness){
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
        if(x0 + i >= dg2->margin && x0 + i < dg2->width - dg2->margin && 
                y0 + j >= dg2->margin && y0 + j < dg2->height - dg2->margin){
            x0 += i;
            y0 += j;
            map[y0 * dg2->height + x0] = DG2_SPACE;
        }
    }
}


void dungeon2_init_by_paths(u8 *map, dungeon_generator2 *dg2){
    
    int nodes[dg2->nodes + 1][2];
    dungeon2_next_node(nodes[0], dg2->margin, dg2); //Initial node
    for(int i = 1; i <= dg2->nodes; i++){
        //Pick any node a
        int *a = nodes[dungeon2_rnd(dg2) % i];
        dungeon2_next_node(nodes[i], dg2->margin, dg2);
        dungeon2_connect_nodes(a, nodes[i], dg2, map);
    }
}

void dungeon2_enlarge(u8 *map, u8 *map2, dungeon_generator2 *dg2){
    for(int x = 1; x < dg2->width; x++){
        for(int y = 1; y < dg2->height; y++){
            int adjacent_walls = 0;
            for(int k = 0; k < 4; k++){
                int i = dg2_cross_neighbourhood[k][0];
                int j = dg2_cross_neighbourhood[k][1];
                if(map[(y + j) * dg2->height + x + i] == DG2_WALL)
                    adjacent_walls++;
            }
            if(adjacent_walls == 4 && map[y * dg2->height + x] == DG2_WALL)
                map2[y * dg2->height + x] = DG2_WALL;
            else
                map2[y * dg2->height + x] = DG2_SPACE;
        }
    }
}


void dungeon2_contract(u8 *map, u8 *map2, dungeon_generator2 *dg2){
    for(int x = 1; x < dg2->width; x++){
        for(int y = 1; y < dg2->height; y++){
            int adjacent_walls = 0;
            for(int k = 0; k < 4; k++){
                int i = dg2_cross_neighbourhood[k][0];
                int j = dg2_cross_neighbourhood[k][1];
                if(map[(y + j) * dg2->height + x + i] == DG2_WALL)
                    adjacent_walls++;
            }
            if(adjacent_walls > 0 || map[y * dg2->height + x] == DG2_WALL)
                map2[y * dg2->height + x] = DG2_WALL;
            else
                map2[y * dg2->height + x] = DG2_SPACE;
        }
    }
}

int dungeon2_flood_fill(u8 *map, u8 *map2, dungeon_generator2 *dg2){
    int width = dg2->width;
    int height = dg2->height;
    
    //Initialize map2 with walls only
    int _dg2_wall = DG2_WALL | (DG2_WALL << 8);
    cpuset(&_dg2_wall, map2, CPUSET_FILL | CPUSET_HALFWORD | (width * height / 2));
    
    //Find a root for flood fill (hope it is part of the biggest connected subgraph)
    s16 x, y;
    do{
        x = (s16)(dungeon2_rnd(dg2) % width);
        y = (s16)(dungeon2_rnd(dg2) % height);
    }while(map[y * height + x] == DG2_WALL);
    
    int filled_tiles = 0;
    coordinate *stack = malloc(sizeof(coordinate) * width * height);
    stack[0].x = x;
    stack[0].y = y;
    int stack_size = 1;
    while(stack_size > 0){
        stack_size--;
        x = stack[stack_size].x;
        y = stack[stack_size].y;
        s16 _x = x;
        while(_x > 0 && map[y * height + _x] == DG2_SPACE) _x--;
        _x++;
        bool span_above = false;
        bool span_below = false;
        while(_x < width && map[y * height + _x] == DG2_SPACE){
            //Fill the span
            map[y * height + _x] = DG2_WALL;
            map2[y * height + _x] = DG2_SPACE;
            filled_tiles++;
            
            if(!span_above && y > 0 && map[(y - 1) * height + _x] == DG2_SPACE){
                stack[stack_size].x = _x;
                stack[stack_size].y = (s16)(y - 1);
                stack_size++;
                span_above = true;
            }else if(span_above && y > 0 && map[(y - 1) * height + _x] == DG2_WALL){
                span_above = false;
            }else if(!span_below && y < height - 1 && map[(y + 1) * height + _x] == DG2_SPACE){
                stack[stack_size].x = _x;
                stack[stack_size].y = (s16)(y + 1);
                stack_size++;
                span_below= true;
            }else if(span_below && y < height - 1 && map[(y + 1) * height + _x] == DG2_WALL){
                span_below = false;
            }
            _x++;
        }
    }
    free(stack);
    return filled_tiles;
    
}

void dungeon_init_random(u8 *map, dungeon_generator2 *dg2){
    for(int x = dg2->margin; x < dg2->width - dg2->margin; x++){
        for(int y = dg2->margin; y < dg2->height - dg2->margin; y++){
            if(dungeon2_rnd(dg2) < dg2->init_randomness){
                map[y * dg2->height + x] = DG2_WALL;
            }else{
                map[y * dg2->height + x] = DG2_SPACE;
            }
        }
    }
}

void dungeon_init_unconnected_nodes(u8 *map, dungeon_generator2 *dg2){
    for(int i = 0; i < dg2->nodes; i++){
        int node[2];
        dungeon2_next_node(node, dg2->margin, dg2);
        map[node[1] * dg2->height + node[0]] = DG2_SPACE;
    }
}

u8 *dungeon2_create_patch_layout(dungeon_generator2 *dg2){
    
    u8 *map1 = malloc((u32)(dg2->width * dg2->height));
    u8 *map2 = malloc((u32)(dg2->width * dg2->height));
    int _dg2_space = DG2_WALL | (DG2_WALL << 8);
    cpuset(&_dg2_space, map1, CPUSET_HALFWORD | CPUSET_FILL | 
            ((dg2->width * dg2->height) / 2));
    cpuset(&_dg2_space, map2, CPUSET_HALFWORD | CPUSET_FILL | 
            ((dg2->width * dg2->height) / 2));
    dungeon_init_unconnected_nodes(map1, dg2);
    dungeon_init_unconnected_nodes(map1, dg2);
    dungeon2_enlarge(map1, map2, dg2);
    dungeon2_enlarge(map2, map1, dg2);
    dungeon2_iterate(map1, map2, 8, 1, dg2);
    free(map1);
    return map2;
}


u8 *dungeon2_create_connected_layout(dungeon_generator2 *dg2){
    u8 *map1 = malloc((u32)(dg2->width * dg2->height));
    u8 *map2 = malloc((u32)(dg2->width * dg2->height));
    
    while(1){
        int _dg2_space = DG2_WALL | (DG2_WALL << 8);
        cpuset(&_dg2_space, map1, CPUSET_HALFWORD | CPUSET_FILL | 
                ((dg2->width * dg2->height) / 2));
        cpuset(&_dg2_space, map2, CPUSET_HALFWORD | CPUSET_FILL | 
                ((dg2->width * dg2->height) / 2));
        dungeon2_init_by_paths(map1, dg2);
        for(int i = 0; i < 3; i++){
            dungeon2_iterate(map1, map2, 6, 2, dg2);
            //Swap map1 und map2 as map2 now holds the updated map
            u8 *tmp = map1;
            map1 = map2;
            map2 = tmp;
        }
        dungeon2_enlarge(map1, map2, dg2);
        dungeon2_contract(map2, map1, dg2);
        int filled_tiles = dungeon2_flood_fill(map1, map2, dg2);
        dprintf("Flood fill provided %d filled tiles of (%d)\n", filled_tiles, dg2->width * dg2->height);
        if(filled_tiles >= dg2->width * dg2->height / 10) break;
        
    }
    free(map1);
    return map2;
   
}


u32 dungeon2_rnd(dungeon_generator2 *dg2){
    return _prng_xorshift(&(dg2->seed));
}