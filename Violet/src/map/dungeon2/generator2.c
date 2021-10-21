/**
 * Alternative dungeon generator module for more natural dungeons. 
 *
 */

#include "agbmemory.h"
#include "bios.h"
#include "circle.h"
#include "debug.h"
#include "dungeon/dungeon2.h"
#include "map/header.h"
#include "math.h"
#include "prng.h"
#include "save.h"
#include "types.h"

void dungeon2_fill_rectangle(u8 *map, int x, int y, int w, int h, u8 fill, dungeon_generator2 *dg2) {
    dprintf("Fill rectangle at %d,%d with measures %d,%d with value %d\n", x, y, w, h, fill);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            map[dg2->width * (y + j) + x + i] = fill;
        }
    }
};

void dungeon2_iterate(u8 *map, u8 *map2, int near_lower_bound, int far_upper_bound, dungeon_generator2 *dg2) {
    dprintf("Iterating map with nlb %d and hub %d\n", near_lower_bound, far_upper_bound);
    for (int x = 1; x < dg2->width - 1; x++) {
        for (int y = 1; y < dg2->height - 1; y++) {
            //Count wall neighbours of x, y
            int nn = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (map[(y + j) * dg2->width + x + i] == DG2_WALL)
                        nn++;
                }
            }
            int fn = 0;
            for (int i = -2; i <= 2; i++) {
                for (int j = -2; j <= 2; j++) {
                    if (ABS(i) == 2 && ABS(j) == 2)
                        continue;
                    if (map[(y + j) * dg2->width + x + i] == DG2_WALL)
                        fn++;
                }
            }
            if (nn >= near_lower_bound || fn <= far_upper_bound)
                map2[y * dg2->width + x] = DG2_WALL;
            else
                map2[y * dg2->width + x] = DG2_SPACE;
        }
    }
}

void dungeon2_enclose(u8 *map, int width, int height) {
    for (int i = 0; i < width; i++) {
        map[i] = DG2_WALL;
        map[(height - 1) * width + i] = DG2_WALL;
    }
    for (int i = 0; i < height; i++) {
        map[i * width] = DG2_WALL;
        map[(i * width) + width - 1] = DG2_WALL;
    }
}

int dg2_cross_neighbourhood[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dungeon2_apply(u8 *src, u8 *dst, u8 type, dungeon_generator2 *dg2) {
    for (int x = 0; x < dg2->width; x++) {
        for (int y = 0; y < dg2->height; y++) {
            if (src[y * dg2->width + x] == type)
                dst[y * dg2->width + x] = type;
        }
    }
}

void dungeon2_enlarge(u8 *map, u8 *map2, dungeon_generator2 *dg2) {
    for (int x = 1; x < dg2->width - 1; x++) {
        for (int y = 1; y < dg2->height - 1; y++) {
            int adjacent_walls = 0;
            for (int k = 0; k < 4; k++) {
                int i = dg2_cross_neighbourhood[k][0];
                int j = dg2_cross_neighbourhood[k][1];
                if (map[(y + j) * dg2->width + x + i] == DG2_WALL)
                    adjacent_walls++;
            }
            if (adjacent_walls == 4 && map[y * dg2->width + x] == DG2_WALL)
                map2[y * dg2->width + x] = DG2_WALL;
            else
                map2[y * dg2->width + x] = DG2_SPACE;
        }
    }
}

void dungeon2_contract(u8 *map, u8 *map2, dungeon_generator2 *dg2) {
    for (int x = 1; x < dg2->width - 1; x++) {
        for (int y = 1; y < dg2->height - 1; y++) {
            int adjacent_walls = 0;
            for (int k = 0; k < 4; k++) {
                int i = dg2_cross_neighbourhood[k][0];
                int j = dg2_cross_neighbourhood[k][1];
                if (map[(y + j) * dg2->width + x + i] == DG2_WALL)
                    adjacent_walls++;
            }
            if (adjacent_walls > 0 || map[y * dg2->width + x] == DG2_WALL)
                map2[y * dg2->width + x] = DG2_WALL;
            else
                map2[y * dg2->width + x] = DG2_SPACE;
        }
    }
}

int dungeon2_flood_fill(u8 *map, u8 *map2, dungeon_generator2 *dg2) {
    int width = dg2->width;
    int height = dg2->height;

    //Initialize map2 with walls only
    int _dg2_wall = DG2_WALL | (DG2_WALL << 8);
    cpuset(&_dg2_wall, map2, CPUSET_FILL | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(width * height));

    //Find a root for flood fill (hope it is part of the biggest connected subgraph)
    s16 x, y;
    do {
        x = (s16)((int)dungeon2_rnd(dg2) % width);
        y = (s16)((int)dungeon2_rnd(dg2) % height);
    } while (map[y * height + x] == DG2_WALL);

    int filled_tiles = 0;
    coordinate_t *stack = malloc((size_t)((int)sizeof(coordinate_t) * width * height));
    stack[0].x = x;
    stack[0].y = y;
    int stack_size = 1;
    while (stack_size > 0) {
        stack_size--;
        x = stack[stack_size].x;
        y = stack[stack_size].y;
        s16 _x = x;
        while (_x > 0 && map[y * height + _x] == DG2_SPACE)
            _x--;
        _x++;
        bool span_above = false;
        bool span_below = false;
        while (_x < width && map[y * height + _x] == DG2_SPACE) {
            //Fill the span
            map[y * height + _x] = DG2_WALL;
            map2[y * height + _x] = DG2_SPACE;
            filled_tiles++;

            if (!span_above && y > 0 && map[(y - 1) * height + _x] == DG2_SPACE) {
                stack[stack_size].x = _x;
                stack[stack_size].y = (s16)(y - 1);
                stack_size++;
                span_above = true;
            } else if (span_above && y > 0 && map[(y - 1) * height + _x] == DG2_WALL) {
                span_above = false;
            } else if (!span_below && y < height - 1 && map[(y + 1) * height + _x] == DG2_SPACE) {
                stack[stack_size].x = _x;
                stack[stack_size].y = (s16)(y + 1);
                stack_size++;
                span_below = true;
            } else if (span_below && y < height - 1 && map[(y + 1) * height + _x] == DG2_WALL) {
                span_below = false;
            }
            _x++;
        }
    }
    free(stack);
    return filled_tiles;
}

void dungeon_init_unconnected_nodes(u8 *map, dungeon_generator2 *dg2, bool random_nodes, int excluded_nodes_mask) {
    int nodes[dg2->nodes][2];
    dungeon2_get_nodes(nodes, dg2->nodes, dg2, random_nodes);
    for (int i = 0; i < dg2->nodes; i++) {
        if (!(excluded_nodes_mask & (1 << i)))
            map[nodes[i][1] * dg2->width + nodes[i][0]] = DG2_SPACE;
    }
}

void dungeon_init_random(u8 *map, dungeon_generator2 *dg2) {
    for (int x = 0; x < dg2->width; x++) {
        for (int y = 0; y < dg2->height; y++) {
            if (x == 0 || y == 0 || x == dg2->width - 1 || y == dg2->height - 1) {
                // Borders must be walls
                map[y * dg2->width + x] = DG2_WALL;
            } else {
                // Randomize the type
                map[y * dg2->width + x] = (dungeon2_rnd_16(dg2) < dg2->init_randomness) ? DG2_WALL : DG2_SPACE;
            }
        }
    }
}

u8 *dungeon2_create_patch_layout(dungeon_generator2 *dg2, bool random_nodes, int excluded_nodes_mask) {

    u8 *map1 = malloc((u32)(dg2->width * dg2->height));
    int _dg2_space = DG2_WALL | (DG2_WALL << 8);
    cpuset(&_dg2_space, map1, CPUSET_HALFWORD | CPUSET_FILL | CPUSET_HALFWORD_SIZE(dg2->width * dg2->height));
    int nodes[dg2->nodes][2];
    dungeon2_get_nodes(nodes, dg2->nodes, dg2, random_nodes);
    for (int i = 0; i < dg2->nodes; i++) {
        if (excluded_nodes_mask & (1 << i))
            continue;
        int x_node = nodes[i][0];
        int y_node = nodes[i][1];
        for (int radius = 0; radius <= 4; radius++) {
            for (size_t j = 0; j < circle_coordinates_by_radius[radius].size; j++) {
                int x = x_node + circle_coordinates_by_radius[radius].coordinates[j].x;
                int y = y_node + circle_coordinates_by_radius[radius].coordinates[j].y;
                map1[y * dg2->width + x] = DG2_SPACE;
            }
        }
    }
    dungeon2_print_map(map1, dg2);
    return map1;
}

u16 dungeon2_rnd_16(dungeon_generator2 *dg2) {
    return (u16)dungeon2_rnd(dg2);
}

int dungeon2_rnd_int(dungeon_generator2 *dg2) {
    return (int)(dungeon2_rnd(dg2) & 0x7FFFFFFF);
}

u32 dungeon2_rnd(dungeon_generator2 *dg2) {
    return _prng_xorshift(&(dg2->seed));
}

FIXED dungeon2_rnd_normal(dungeon_generator2 *dg2) {
    return _prng_stdnormal(&(dg2->seed));
}
