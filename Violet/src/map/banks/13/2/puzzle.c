#include "types.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "vars.h"
#include "flags.h"
#include "map/route_9_puzzle.h"
#include "debug.h"

static const int route_9_cave_puzzle_connection_shifts[4] = {0, 4, 7, 9};

bool route_9_cave_puzzle_connection_check(int first, int second) {
    if (second < first) return route_9_cave_puzzle_connection_check(second, first);
    else if (second == first) return false;
    int bit_position = second - first - 1 + route_9_cave_puzzle_connection_shifts[first];
    return (*var_access(ROUTE_9_CAVE_STATE) & (1 << bit_position)) > 0;
}

void route_9_cave_puzzle_connection_set(int first, int second) {
    if (second < first) {
        route_9_cave_puzzle_connection_set(second, first);
    } else {
        int bit_position = second - first - 1 + route_9_cave_puzzle_connection_shifts[first];
        *var_access(ROUTE_9_CAVE_STATE) |= (u16)(1 << bit_position);
    }
}

s16 route_9_cave_puzzle_get_state() {
    s16 number_connections = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Check if only the lines of a pentagram are drawn
            bool is_drawn = route_9_cave_puzzle_connection_check(i, j);
            // DEBUG("Line from %d to %d drawn: %d\n", i, j, is_drawn);
            if ((i + 2) % 5 == j || (i + 3) % 5 == j) {
                if (is_drawn) number_connections++;
            } else {
                // Invalid line that is not part of the pentagram
                if (is_drawn) return -1;
            }
        }
    }
    return number_connections;
}

void route_9_cave_puzzle_set_last_rock() {
    u16 idx = *var_access(0x8000);
    int flags = *var_access(ROUTE_9_CAVE_STATE) & 0x3FF;
    *var_access(ROUTE_9_CAVE_STATE) = (u16)(((idx + 1) << 10) | flags);
}

s16 route_9_cave_puzzle_get_last_rock() {
    return (s16)((*var_access(ROUTE_9_CAVE_STATE) >> 10) - 1);
}

void route_9_cave_puzzle_rock() {
    int second = *var_access(0x8000);
    int first = route_9_cave_puzzle_get_last_rock();
    if (first != -1) {
        route_9_cave_puzzle_connection_set(first, second);
    }
    route_9_cave_puzzle_set_last_rock(second);
}

void route_9_cave_puzzle_reset() {
    *var_access(ROUTE_9_CAVE_STATE) = 0;
}

