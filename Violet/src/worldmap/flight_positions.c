#include "types.h"
#include "worldmap.h"

stru_flight_position flight_positions[NUM_FLIGHT_POSITONS] = {
    // bank, map, x, y, d
    {3, 0, 14, 26, 0},
    {3, 1, 72, 29, 0},
    {3, 2, 24, 21, 0},
    {3, 3, 20, 13, 0},
    {3, 4, 31, 51, 0},
    {3, 5, 31, 26, 0},
    {3, 6, 28, 17, 0},
    {3, 7, 47, 17, 0},
    {3, 8, 14, 12, 0},
    {3, 9, 11, 7, 0},
    {3, 10, 24, 39, 0},
    {15, 0, 47, 44, 0},
    {3, 28, 13, 21, 0},
    {3, 12, 14, 6, 0},
    {3, 13, 21, 8, 0},
    {3, 14, 14, 28, 0},
    {3, 15, 18, 21, 0},
    {3, 16, 18, 7, 0},
    {3, 17, 12, 4, 0},
    {3, 18, 11, 12, 0},
    {0xFF, 0xFF, 0, 0, 0}

};

int map_get_flightposition(u8 bank, u8 map){
    for(int i = 0; flight_positions[i].bank != 0xFF 
            || flight_positions[i].map != 0xFF; i++){
        if(flight_positions[i].bank == bank
                && flight_positions[i].map == map)
            return i + 1;
    }
    return 0;
}

stru_flight_position *flightposition_by_id(int id){
    if(!id) return 0;
    return &flight_positions[id - 1];
}
