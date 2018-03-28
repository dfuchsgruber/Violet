#include "types.h"
#include "map.h"

stru_healing_place healing_places[NUM_HEALING_PLACES] = {
    {4, 0},
    {5, 4},
    {6, 5},
    {7, 3},
    {8, 0},
    {9, 1},
    {10, 12},
    {11, 5},
    {12, 5},
    {13, 0},
    {14, 6},
    {16, 0},
    {21, 0},
    {32, 0},
    {33, 2},
    {34, 1},
    {35, 1},
    {36, 0},
    {31, 3},
    {37, 0},
    {0xFFFF, 0xFFFF}
};

u8 healing_place_target_persons[NUM_HEALING_PLACES] = {
    {1, 1, 3, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0xFF}
};
