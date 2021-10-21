#ifndef H_CIRCLE
#define H_CIRCLE

#include "tile/coordinate.h"
#include "types.h"

// Sets of coordinates that are within a circle of a given radius centered at 0,0

coordinate_t circle_coordinates_radius_0[1];
coordinate_t circle_coordinates_radius_1[4];
coordinate_t circle_coordinates_radius_2[8];
coordinate_t circle_coordinates_radius_3[16];
coordinate_t circle_coordinates_radius_4[20];
coordinate_t circle_coordinates_radius_5[32];
coordinate_t circle_coordinates_radius_6[32];

typedef struct {
    coordinate_t *coordinates;
    size_t size;
} circle_coordinates_t;

circle_coordinates_t circle_coordinates_by_radius[7];

#endif
