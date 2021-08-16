#include "types.h"
#include "circle.h"

coordinate_t circle_coordinates_radius_0[1] = {
	{0, 0}
};

coordinate_t circle_coordinates_radius_1[4] = {
	{0, 1}, {-1, 0}, {0, -1}, {1, 0}
};

coordinate_t circle_coordinates_radius_2[8] = {
	{-1, 1}, {-2, 0}, {0, 2}, {2, 0}, {-1, -1}, {0, -2}, {1, -1}, {1, 1}
};

coordinate_t circle_coordinates_radius_3[16] = {
	{3, 0}, {2, 1}, {0, 3}, {1, -2}, {1, 2}, {-2, 1}, {-2, -2}, {-2, -1}, {-1, -2}, {2, 2}, {2, -2}, {2, -1}, {-2, 2}, {-1, 2}, {0, -3}, {-3, 0}
};

coordinate_t circle_coordinates_radius_4[20] = {
	{1, 3}, {-3, -2}, {-3, -1}, {-1, -3}, {-2, -3}, {4, 0}, {2, -3}, {-3, 2}, {1, -3}, {0, 4}, {0, -4}, {3, 2}, {-3, 1}, {2, 3}, {-4, 0}, {-2, 3}, {-1, 3}, {3, 1}, {3, -2}, {3, -1}
};

coordinate_t circle_coordinates_radius_5[32] = {
	{4, -3}, {2, -4}, {-4, 2}, {3, -3}, {-3, 3}, {0, -5}, {5, 0}, {-3, -4}, {-4, -3}, {1, 4}, {1, -4}, {4, 2}, {-4, 1}, {-2, 4}, {-1, 4}, {-3, 4}, {3, 4}, {2, 4}, {4, -2}, {4, -1}, {-3, -3}, {3, 3}, {-4, 3}, {3, -4}, {4, 1}, {-5, 0}, {0, 5}, {-4, -2}, {-4, -1}, {-2, -4}, {-1, -4}, {4, 3}
};

coordinate_t circle_coordinates_radius_6[32] = {
	{1, -5}, {2, 5}, {-5, 1}, {6, 0}, {0, -6}, {5, 1}, {1, 5}, {5, -2}, {5, -1}, {-3, -5}, {-2, -5}, {-1, -5}, {3, 5}, {-2, 5}, {-1, 5}, {-5, -2}, {-5, -1}, {5, -3}, {-5, 3}, {-5, -3}, {5, 3}, {4, -4}, {-4, 4}, {0, 6}, {-6, 0}, {-4, -4}, {4, 4}, {2, -5}, {3, -5}, {-3, 5}, {-5, 2}, {5, 2}
};

circle_coordinates_t circle_coordinates_by_radius[7] = {
    [0] = {.coordinates = circle_coordinates_radius_0, .size = ARRAY_COUNT(circle_coordinates_radius_0)},
    [1] = {.coordinates = circle_coordinates_radius_1, .size = ARRAY_COUNT(circle_coordinates_radius_1)},
    [2] = {.coordinates = circle_coordinates_radius_2, .size = ARRAY_COUNT(circle_coordinates_radius_2)},
    [3] = {.coordinates = circle_coordinates_radius_3, .size = ARRAY_COUNT(circle_coordinates_radius_3)},
    [4] = {.coordinates = circle_coordinates_radius_4, .size = ARRAY_COUNT(circle_coordinates_radius_4)},
    [5] = {.coordinates = circle_coordinates_radius_5, .size = ARRAY_COUNT(circle_coordinates_radius_5)},
    [6] = {.coordinates = circle_coordinates_radius_6, .size = ARRAY_COUNT(circle_coordinates_radius_6)},
};

