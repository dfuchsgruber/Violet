#include "types.h"
#include "worldmap.h"

// Make the arrays fixed size to validate for tools/index/worldmap.py during debugging.
// For space efficiency this can be omitted later, I guess...
#define VALIDATION true

#if VALIDATION
typedef worldmap_position_t worldmap_position_bank[256];
#else
typedef worldmap_position_t worldmap_position_bank[];
#endif

#define WORLDMAP_POSITION_NO_POSITION {.width = 0, .height = 0, .filler = 0xFFFF}
#define WORLDMAP_POSITION_ANEMONIA {.x = 20, .y = 12, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_ANEMONIA_CLOUDS {.x = 20, .y = 12, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}
#define WORLDMAP_POSITION_TRAINER_SCHOOL {.x = 19, .y = 11, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_BLUETENBACH {.x = 20, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_BLUETENBACH_CLOUDS {.x = 20, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}
#define WORLDMAP_POSITION_SONNAUFELD {.x = 16, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_SONNAUFELD_CLOUDS {.x = 16, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}
#define WORLDMAP_POSITION_KRANZWALD {.x = 13, .y = 4, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_KRANZDORF {.x = 13, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_KRANZDORF_CLOUDS {.x = 13, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}
#define WORLDMAP_POSITION_BASIS_TROCKENTAG {.x = 16, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_TAFELBERG_WEST {.x = 19, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_TAFELBERG_WEST_CLOUDS {.x = 19, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}
#define WORLDMAP_POSITION_KASKADA {.x = 20, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_KASKADA_CLOUDS {.x = 20, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}
#define WORLDMAP_POSITION_TAFELBERG_NORTH {.x = 20, .y = 4, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_TAFELBERG_NORTH_CLOUDS {.x = 20, .y = 4, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}
#define WORLDMAP_POSITION_BRUCHFELS {.x = 20, .y = 0, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_BRUCHFELS_CLOUDS {.x = 20, .y = 0, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}
#define WORLDMAP_POSITION_LAUBDORF {.x = 13, .y = 1, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_HOCHPOLIS_CITY {.x = 10, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_HOCHPOLIS_CITY_CLOUDS {.x = 10, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}
#define WORLDMAP_POSITION_KRAFTWERTK {.x = 10, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_INFERIOR {.x = 6, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_INFERIOR_CLOUDS {.x = 6, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}
#define WORLDMAP_POSITION_VOLCANO {.x = 6, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_ARDEAL {.x = 10, .y = 8, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_HAWEILAND {.x = 9, .y = 12, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_CEOMETRIA {.x = 14, .y = 12, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_CEOMETRIA_CLOUDS {.x = 14, .y = 12, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}
#define WORLDMAP_POSITION_DUNKLER_TURM WORLDMAP_POSITION_CEOMETRIA_CLOUDS
#define WORLDMAP_POSITION_WALDFRIEDHOF {.x = 15, .y = 12, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}
#define WORLDMAP_POSITION_SCHATTENFLUT {.x = 7, .y = 11, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}

static const worldmap_position_bank worldmap_positions_bank_3  = {
	[0] = WORLDMAP_POSITION_ANEMONIA, // Anemonia
    [19] = {.x = 20, .y = 10, .width = 1, .height = 2, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 1
    [57] = WORLDMAP_POSITION_TRAINER_SCHOOL, // Trainer School
    [72] =  WORLDMAP_POSITION_TRAINER_SCHOOL, // Trainer School Inside
    [1] = WORLDMAP_POSITION_BLUETENBACH, // Bluetenbach
    [7] = {.x = 17, .y = 9, .width = 2, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 2 East
    [70] = {.x = 19, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 2 Cave
    [25] = WORLDMAP_POSITION_SONNAUFELD,
    [66] = WORLDMAP_POSITION_SONNAUFELD, // Tann's lab
    [41] = {.x = 14, .y = 7, .width = 2, .height = 3, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 3
    [75] = {.x = 15, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Version-Transfer-Cave
    [3] = WORLDMAP_POSITION_KRANZDORF,
    [74] = {.x = 14, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Felsige Oednis Route
    [26] = WORLDMAP_POSITION_BASIS_TROCKENTAG,
    [21] = {.x = 17, .y = 5, .width = 2, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Kaktuslabyrinth
    [67] = WORLDMAP_POSITION_TAFELBERG_WEST, // Tafelberg ascent east
    [4] = WORLDMAP_POSITION_KASKADA,
    [22] = {.x = 20, .y = 6, .width = 1, .height = 3, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 5
    [11] = {.x = 20, .y = 1, .width = 1, .height = 3, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 10
    [2] = WORLDMAP_POSITION_BRUCHFELS,
    [73] = WORLDMAP_POSITION_BRUCHFELS, // Bruchfels' past
    [10] = {.x = 13, .y = 0, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Horizontal stretch of Route 9
    [9] = WORLDMAP_POSITION_LAUBDORF,
    [8] = {.x = 13, .y = 2, .width = 1, .height = 2, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Laubpfad
    [23] = {.x = 11, .y = 6, .width = 2, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 6
    [5] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [20] = WORLDMAP_POSITION_KRAFTWERTK,
    [24] = {.x = 9, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 7 cave east entrance
    [6] = WORLDMAP_POSITION_INFERIOR,
    [18] = {.x = 9, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 8 center piece south of castle
    [17] = WORLDMAP_POSITION_HAWEILAND,
    [16] = {.x = 10, .y = 12, .width = 2, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 12 west
    [15] = {.x = 12, .y = 12, .width = 2, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 12 east
    [13] = WORLDMAP_POSITION_CEOMETRIA,
    [14] = WORLDMAP_POSITION_WALDFRIEDHOF,
    [12] = {.x = 14, .y = 10, .width = 1, .height = 2, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 11
    [76] = {.x = 20, .y = 10, .width = 1, .height = 2, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 1 Clouds
};  

static const worldmap_position_bank worldmap_positions_bank_4_anemonia  = {
	[0] = WORLDMAP_POSITION_ANEMONIA,
	[1] = WORLDMAP_POSITION_ANEMONIA,
	[2] = WORLDMAP_POSITION_ANEMONIA,
	[4] = WORLDMAP_POSITION_ANEMONIA,
	[3] = WORLDMAP_POSITION_ANEMONIA,
	[5] = WORLDMAP_POSITION_ANEMONIA_CLOUDS,
    [6] = WORLDMAP_POSITION_ANEMONIA_CLOUDS,
};

static const worldmap_position_bank worldmap_positions_bank_5_bluetenbach = {
    [0] = WORLDMAP_POSITION_BLUETENBACH,
    [1] = WORLDMAP_POSITION_BLUETENBACH_CLOUDS,
    [2] = WORLDMAP_POSITION_BLUETENBACH,
    [3] = WORLDMAP_POSITION_BLUETENBACH,
    [4] = WORLDMAP_POSITION_BLUETENBACH,
    [5] = WORLDMAP_POSITION_BLUETENBACH,
    [6] = WORLDMAP_POSITION_BLUETENBACH,
    [7] = WORLDMAP_POSITION_BLUETENBACH,
    [11] = WORLDMAP_POSITION_BLUETENBACH,
    [12] = WORLDMAP_POSITION_BLUETENBACH,
    [13] = WORLDMAP_POSITION_BLUETENBACH,
};


static const worldmap_position_bank worldmap_positions_bank_11_route_2 = {
    [0] = {.x = 19, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 2 Cave
    [1] = {.x = 19, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Route 2 Cave
    [5] = {.x = 16, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Cave 2
    [6] = {.x = 16, .y = 9, .width = 2, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Cave 2 - connnection
    [2] = {.x = 17, .y = 9, .width = 3, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 2 East Clouds
    [7] = {.x = 17, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 2 East Clouds Cave
    [8] = {.x = 17, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 2 East Clouds Cave
    [9] = {.x = 17, .y = 9, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 2 East Clouds Cave
    [3] =  {.x = 14, .y = 7, .width = 2, .height = 3, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 3 Clouds
    [4] =  {.x = 14, .y = 7, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 3 Clouds Ruins
    // TODO: cloud maps for route 3: 3, 4
};

static const worldmap_position_bank worldmap_position_bank_35_sonnaufeld = {
    [0] = WORLDMAP_POSITION_SONNAUFELD,
    [1] = WORLDMAP_POSITION_SONNAUFELD,
    [3] = WORLDMAP_POSITION_SONNAUFELD_CLOUDS,
    [2] = WORLDMAP_POSITION_SONNAUFELD,
    [4] = WORLDMAP_POSITION_SONNAUFELD,
    [5] = WORLDMAP_POSITION_SONNAUFELD,
};

static const worldmap_position_bank worldmap_position_bank_36_route_3 = {
    [0] = {.x = 14, .y = 8, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,},
};

static const worldmap_position_bank worldmap_position_bank_15_route_4 = {
    [0] = {.x = 13, .y = 6, .width = 1, .height = 2, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Outdoor map
    [1] = {.x = 13, .y = 7, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Indoor map, bird breeders
    [3] = {.x = 13, .y = 7, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Clouds map
    [4] = {.x = 13, .y = 6, .width = 1, .height = 2, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Outdoor map
    [5] = {.x = 13, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Mill
    [6] = {.x = 13, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Mill
    [2] = {.x = 13, .y = 6, .width = 1, .height = 2, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Outdoor map
};

static const worldmap_position_bank worldmap_position_bank_1_kranwald = {
    [0] = WORLDMAP_POSITION_KRANZWALD,
    [1] = WORLDMAP_POSITION_KRANZWALD,
    [59] = WORLDMAP_POSITION_TAFELBERG_NORTH,
    // Aschhain
    [30] = {.x = 8, .y = 4, .height = 2, .width = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,},
    [31] = {.x = 8, .y = 5, .height = 1, .width = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,},
    [125] = {.x = 8, .y = 4, .height = 1, .width = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,},
    // Volcano
    [81] = WORLDMAP_POSITION_VOLCANO,
    [82] = WORLDMAP_POSITION_VOLCANO,
    [126] = WORLDMAP_POSITION_VOLCANO,
    // TODO: cloud maps 2
};

static const worldmap_position_bank worldmap_position_bank_7_kranzdorf = {
    [1] = WORLDMAP_POSITION_KRANZDORF,
    [2] = WORLDMAP_POSITION_KRANZDORF,
    [3] = WORLDMAP_POSITION_KRANZDORF,
    [4] = WORLDMAP_POSITION_KRANZDORF,
    [5] = WORLDMAP_POSITION_KRANZDORF,
    [8] = WORLDMAP_POSITION_KRANZDORF,
    [10] = WORLDMAP_POSITION_KRANZDORF,
    [0] = WORLDMAP_POSITION_KRANZDORF_CLOUDS,
};

static const worldmap_position_bank worldmap_position_bank_0_felsige_oednis = {
    [5] = {.x = 15, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Felsige Oednis Cave
    [6] = {.x = 15, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Felsige Oednis Cave
    [7] = WORLDMAP_POSITION_TAFELBERG_WEST, // Lapis cave
    // Volcano
    [12] = WORLDMAP_POSITION_VOLCANO,
    [13] = WORLDMAP_POSITION_VOLCANO,
};

static const worldmap_position_bank worldmap_position_bank_22_basis_trockentag = {
    [2] = {.x = 15, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Felsige Oednis Cave
    [6] = WORLDMAP_POSITION_BASIS_TROCKENTAG,
    [7] = WORLDMAP_POSITION_BASIS_TROCKENTAG,
    [8] = WORLDMAP_POSITION_BASIS_TROCKENTAG,
    [3] = {.x = 17, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Kaktuslabyrinth Gible cave
    [4] = WORLDMAP_POSITION_TAFELBERG_WEST, // Tafelberg outside ascent, east
    [5] = WORLDMAP_POSITION_TAFELBERG_WEST, // Tafelberg outside ascent, east  
    [0] = WORLDMAP_POSITION_TAFELBERG_WEST_CLOUDS,
    [1] = WORLDMAP_POSITION_TAFELBERG_WEST_CLOUDS,

};

static const worldmap_position_bank worldmap_postition_bank_37_basis_trockentag = {
    [0] = WORLDMAP_POSITION_BASIS_TROCKENTAG,
    [1] = WORLDMAP_POSITION_BASIS_TROCKENTAG,
    [2] = WORLDMAP_POSITION_BASIS_TROCKENTAG,
};

static const worldmap_position_bank worldmap_position_bank_8_kaskada = {
    [0] = WORLDMAP_POSITION_KASKADA,
    [1] = WORLDMAP_POSITION_KASKADA_CLOUDS,
    [2] = WORLDMAP_POSITION_KASKADA_CLOUDS,
    [3] = WORLDMAP_POSITION_KASKADA,
    [4] = WORLDMAP_POSITION_KASKADA,
    [5] = WORLDMAP_POSITION_KASKADA,
    [6] = WORLDMAP_POSITION_KASKADA,
    [7] = WORLDMAP_POSITION_KASKADA,
    [8] = WORLDMAP_POSITION_KASKADA,
    [9] = WORLDMAP_POSITION_KASKADA,
    [10] = WORLDMAP_POSITION_KASKADA,
    [11] = WORLDMAP_POSITION_KASKADA,
    [12] = WORLDMAP_POSITION_KASKADA,
    [13] = WORLDMAP_POSITION_KASKADA,
    [14] = WORLDMAP_POSITION_KASKADA,
    [15] = WORLDMAP_POSITION_KASKADA,
};

static const worldmap_position_bank worldmap_position_bank_24 = {
    [0] = WORLDMAP_POSITION_TAFELBERG_NORTH_CLOUDS,
};

static const worldmap_position_bank worldmap_position_bank_16_route_5 = {
    [1] = {.x = 20, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,},
    [4] = {.x = 20, .y = 7, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Fly house
    [2] = {.x = 20, .y = 8, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // South cave
    [0] = {.x = 20, .y = 6, .width = 1, .height = 3, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 5 clouds
    [5] = {.x = 20, .y = 6, .width = 1, .height = 2, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 5 clouds cave
};

static const worldmap_position_bank worldmap_position_bank_14_route_10 = {
    [0] =  {.x = 20, .y = 1, .width = 1, .height = 3, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 10
};

static const worldmap_position_bank worldmap_position_bank_6_bruchfels = {
    [0] = WORLDMAP_POSITION_BRUCHFELS,
    [1] = WORLDMAP_POSITION_BRUCHFELS,
    [2] = WORLDMAP_POSITION_BRUCHFELS,
    [3] = WORLDMAP_POSITION_BRUCHFELS,
    [4] = WORLDMAP_POSITION_BRUCHFELS,
    [5] = WORLDMAP_POSITION_BRUCHFELS,
    [6] = WORLDMAP_POSITION_BRUCHFELS_CLOUDS,
    [7] = WORLDMAP_POSITION_BRUCHFELS_CLOUDS,
    [8] = WORLDMAP_POSITION_BRUCHFELS,
    [9] = WORLDMAP_POSITION_BRUCHFELS,
    [10] = WORLDMAP_POSITION_BRUCHFELS,
    [11] = WORLDMAP_POSITION_BRUCHFELS,
    [12] = WORLDMAP_POSITION_BRUCHFELS,
    [13] = WORLDMAP_POSITION_BRUCHFELS,
    [14] = WORLDMAP_POSITION_BRUCHFELS,
    [15] = WORLDMAP_POSITION_BRUCHFELS,
};

static const worldmap_position_bank worldmap_position_bank_13_route_9 = {
    [0] = {.x = 14, .y = 0, .width = 6, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // This is too wide, add some content here...
    [1] = {.x = 19, .y = 0, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // House on route 9
    [2] = {.x = 14, .y = 0, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Cave on route 9
    [3] = {.x = 14, .y = 0, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Cave on route 9
    // TODO: Cloud maps 4, 5
};

static const worldmap_position_bank worldmap_position_bank_17_route_6 = {
    [2] = {.x = 11, .y = 6, .width = 2, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 6 Clouds
    [0] = {.x = 11, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 6 Clouds Cave
    [1] = {.x = 11, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 6 Clouds Cave
    [3] = {.x = 11, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 6 Clouds Cave
    [4] = {.x = 11, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 6 Clouds Cave
    [5] = {.x = 11, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 6 Clouds Cave
    [6] = {.x = 11, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 6 Clouds Cave
    [7] = {.x = 11, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 6 Clouds Cave
    [8] = {.x = 11, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 6 Clouds Cave
};

static const worldmap_position_bank worldmap_position_bank_12_laubdorf = {
    [0] = WORLDMAP_POSITION_LAUBDORF,
    [1] = WORLDMAP_POSITION_LAUBDORF,
    [2] = WORLDMAP_POSITION_LAUBDORF,
    [3] = WORLDMAP_POSITION_LAUBDORF,
    [4] = WORLDMAP_POSITION_LAUBDORF,
    [5] = WORLDMAP_POSITION_LAUBDORF,
    [6] = WORLDMAP_POSITION_LAUBDORF,
    [7] = WORLDMAP_POSITION_LAUBDORF,
    [8] = WORLDMAP_POSITION_LAUBDORF,
};

static const worldmap_position_bank worldmap_position_bank_9_hochpolis_city = {
    [0] = WORLDMAP_POSITION_HOCHPOLIS_CITY_CLOUDS,
    [1] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [2] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [3] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [4] = WORLDMAP_POSITION_HOCHPOLIS_CITY_CLOUDS,
    [5] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [6] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [9] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [10] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [11] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [12] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [13] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [14] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [15] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [16] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [17] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [18] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
    [19] = WORLDMAP_POSITION_HOCHPOLIS_CITY,
};

const worldmap_position_bank worldmap_position_bank_34_kraftwerk = {
    [0] = WORLDMAP_POSITION_KRAFTWERTK,
};

static const worldmap_position_bank worldmap_position_bank_18_route_7 = {
    [2] = {.x = 9, .y = 6, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // cave
    [3] = {.x = 7, .y = 6, .width = 2, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // west
    [0] = {.x = 7, .y = 6, .width = 3, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,} // Clouds
};

static const worldmap_position_bank worldmap_position_bank_10_inferior = {
    [0] = WORLDMAP_POSITION_INFERIOR,
    [1] = WORLDMAP_POSITION_INFERIOR,
    [2] = WORLDMAP_POSITION_INFERIOR_CLOUDS,
    [12] = WORLDMAP_POSITION_INFERIOR,
    [16] = WORLDMAP_POSITION_INFERIOR,
    [20] = WORLDMAP_POSITION_INFERIOR,
    [22] = WORLDMAP_POSITION_INFERIOR,
};

static const worldmap_position_bank worldmap_position_bank_21_volcano = {
    [0] = WORLDMAP_POSITION_VOLCANO,
};

static const worldmap_position_bank worldmap_position_bank_29_route_8 = {
    [3] = {.x = 8, .y = 7, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // north
    [2] = {.x = 8, .y = 8, .width = 2, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // castle
    [1] = {.x = 9, .y = 10, .width = 1, .height = 2, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // south 
    [4] = {.x = 8, .y = 7, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // house on northmost part
    [5] = {.x = 9, .y = 11, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // fisherman house
    [0] = WORLDMAP_POSITION_HAWEILAND,
};

static const worldmap_position_bank worldmap_position_bank_31_ardeal = {
    [0] = WORLDMAP_POSITION_ARDEAL,
    [1] = WORLDMAP_POSITION_ARDEAL,
    [2] = WORLDMAP_POSITION_ARDEAL,
    [3] = WORLDMAP_POSITION_ARDEAL,
    [4] = WORLDMAP_POSITION_ARDEAL,
    [5] = WORLDMAP_POSITION_ARDEAL,
    [6] = WORLDMAP_POSITION_ARDEAL,
    [7] = WORLDMAP_POSITION_ARDEAL,
    [8] = WORLDMAP_POSITION_ARDEAL,
    [9] = WORLDMAP_POSITION_ARDEAL,
    [10] = WORLDMAP_POSITION_ARDEAL,
    [11] = WORLDMAP_POSITION_ARDEAL,
    [12] = WORLDMAP_POSITION_ARDEAL,
    [13] = WORLDMAP_POSITION_ARDEAL,
    [14] = WORLDMAP_POSITION_ARDEAL,
    [15] = WORLDMAP_POSITION_ARDEAL,
    [16] = WORLDMAP_POSITION_ARDEAL,
    [17] = WORLDMAP_POSITION_ARDEAL,
};

static const worldmap_position_bank worldmap_position_bank_28_antike_ruine = {
    [0] = {.x = 17, .y = 5, .width = 1, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_GROUND,}, // Regirock's ruins
};

static const worldmap_position_bank worldmap_position_bank_27_haweiland = {
    [0] = WORLDMAP_POSITION_HAWEILAND,
    [1] = WORLDMAP_POSITION_HAWEILAND,
    [2] = WORLDMAP_POSITION_HAWEILAND,
    [3] = WORLDMAP_POSITION_HAWEILAND,
    [4] = WORLDMAP_POSITION_HAWEILAND,
    [5] = WORLDMAP_POSITION_HAWEILAND,
    [6] = WORLDMAP_POSITION_HAWEILAND,
    [7] = WORLDMAP_POSITION_HAWEILAND,
};

static const worldmap_position_bank worldmap_position_bank_26_route_12 = {
    [1] = {.x = 10, .y = 12, .width = 2, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 12 west clouds
    [2] = {.x = 12, .y = 12, .width = 2, .height = 1, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 12 east clouds
};

static const worldmap_position_bank worldmap_position_bank_19_ceometria = {
    [0] = WORLDMAP_POSITION_CEOMETRIA,
    [1] = WORLDMAP_POSITION_CEOMETRIA,
    [2] = WORLDMAP_POSITION_CEOMETRIA,
    [3] = WORLDMAP_POSITION_CEOMETRIA,
    [4] = WORLDMAP_POSITION_CEOMETRIA,
    [5] = WORLDMAP_POSITION_CEOMETRIA,
    [6] = WORLDMAP_POSITION_CEOMETRIA,
    [7] = WORLDMAP_POSITION_CEOMETRIA,
    [8] = WORLDMAP_POSITION_CEOMETRIA,
    [9] = WORLDMAP_POSITION_CEOMETRIA_CLOUDS,
    [10] = WORLDMAP_POSITION_CEOMETRIA,
};

static const worldmap_position_bank worldmap_position_bank_32_dunkler_turm = {
    [0] = WORLDMAP_POSITION_DUNKLER_TURM,
    [1] = WORLDMAP_POSITION_DUNKLER_TURM,
    [2] = WORLDMAP_POSITION_DUNKLER_TURM,
    [3] = WORLDMAP_POSITION_DUNKLER_TURM,
    [4] = WORLDMAP_POSITION_DUNKLER_TURM,
};

static const worldmap_position_bank worldmap_position_bank_20_waldfriedhof = {
    [0] = WORLDMAP_POSITION_WALDFRIEDHOF,
};

static const worldmap_position_bank worldmap_position_bank_25_route_11 = {
    [0] = {.x = 14, .y = 10, .width = 1, .height = 2, .worldmap_idx = WORLDMAP_THETO, .layer = WORLDMAP_LAYER_CLOUDS,}, // Route 11 Clouds
};

static const worldmap_position_bank worldmap_position_bank_33_schattenflut = {
    [0] = WORLDMAP_POSITION_SCHATTENFLUT,
    [1] = WORLDMAP_POSITION_SCHATTENFLUT,
    [2] = WORLDMAP_POSITION_SCHATTENFLUT,
    [3] = WORLDMAP_POSITION_SCHATTENFLUT,
    [4] = WORLDMAP_POSITION_SCHATTENFLUT,
    [5] = WORLDMAP_POSITION_SCHATTENFLUT,
    [6] = WORLDMAP_POSITION_SCHATTENFLUT,
    [7] = WORLDMAP_POSITION_SCHATTENFLUT,
    [8] = WORLDMAP_POSITION_SCHATTENFLUT,
};

static const worldmap_position_bank worldmap_positions_bank_2 = {
    [33] = WORLDMAP_POSITION_NO_POSITION
};

static const worldmap_position_bank worldmap_positions_bank_126 = {
    [0] = WORLDMAP_POSITION_NO_POSITION,
    [1] = WORLDMAP_POSITION_NO_POSITION,
    [2] = WORLDMAP_POSITION_NO_POSITION,
};

const worldmap_position_t *const worldmap_positions[256] = {
    [3] = worldmap_positions_bank_3,
    [4] = worldmap_positions_bank_4_anemonia,
    [5] = worldmap_positions_bank_5_bluetenbach,
    [11] = worldmap_positions_bank_11_route_2,
    [35] = worldmap_position_bank_35_sonnaufeld,
    [36] = worldmap_position_bank_36_route_3,
    [15] = worldmap_position_bank_15_route_4,
    [1] = worldmap_position_bank_1_kranwald,
    [7] = worldmap_position_bank_7_kranzdorf,
    [0] = worldmap_position_bank_0_felsige_oednis,
    [22] = worldmap_position_bank_22_basis_trockentag,
    [37] = worldmap_postition_bank_37_basis_trockentag,
    [8] = worldmap_position_bank_8_kaskada,
    [24] = worldmap_position_bank_24,
    [16] = worldmap_position_bank_16_route_5,
    [14] = worldmap_position_bank_14_route_10,
    [6] = worldmap_position_bank_6_bruchfels,
    [13] = worldmap_position_bank_13_route_9,
    [12] = worldmap_position_bank_12_laubdorf,
    [17] = worldmap_position_bank_17_route_6,
    [9] = worldmap_position_bank_9_hochpolis_city,
    [34] = worldmap_position_bank_34_kraftwerk,
    [18] = worldmap_position_bank_18_route_7,
    [10] = worldmap_position_bank_10_inferior,
    [21] = worldmap_position_bank_21_volcano,
    [29] = worldmap_position_bank_29_route_8,
    [31] = worldmap_position_bank_31_ardeal,
    [28] = worldmap_position_bank_28_antike_ruine,
    [26] = worldmap_position_bank_26_route_12,
    [27] = worldmap_position_bank_27_haweiland,
    [19] = worldmap_position_bank_19_ceometria,
    [32] = worldmap_position_bank_32_dunkler_turm,
    [20] = worldmap_position_bank_20_waldfriedhof,
    [25] = worldmap_position_bank_25_route_11,
    [33] = worldmap_position_bank_33_schattenflut,
    [2] = worldmap_positions_bank_2,
    [126] = worldmap_positions_bank_126,
};