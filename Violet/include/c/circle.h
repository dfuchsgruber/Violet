#ifndef H_CIRCLE
#define H_CIRCLE

#include "types.h"
#include "tile/coordinate.h"

// Sets of coordinates that are within a circle of a given radius centered at 0,0

extern const coordinate_t circle_coordinates_radius_0[1];
extern const coordinate_t circle_coordinates_radius_1[4];
extern const coordinate_t circle_coordinates_radius_2[8];
extern const coordinate_t circle_coordinates_radius_3[16];
extern const coordinate_t circle_coordinates_radius_4[20];
extern const coordinate_t circle_coordinates_radius_5[32];
extern const coordinate_t circle_coordinates_radius_6[32];

typedef struct {
    const coordinate_t *coordinates;
    size_t size;
} circle_coordinates_t;

extern const circle_coordinates_t circle_coordinates_by_radius[7];

#endif