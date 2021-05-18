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

static worldmap_position_bank worldmap_positions_bank_0  = {
	[7] = {.x = 20, .y = 5, .width = 1, .height = 1},
	[12] = {.x = 0, .y = 0, .width = 1, .height = 1},
	[5] = {.x = 19, .y = 5, .width = 1, .height = 1},
	[6] = {.x = 19, .y = 5, .width = 1, .height = 1},
	[13] = {.x = 0, .y = 0, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_1  = {
	[0] = {.x = 18, .y = 4, .width = 1, .height = 1},
	[81] = {.x = 0, .y = 0, .width = 1, .height = 1},
	[82] = {.x = 0, .y = 0, .width = 1, .height = 1},
	[126] = {.x = 0, .y = 0, .width = 1, .height = 1},
	[59] = {.x = 21, .y = 4, .width = 1, .height = 1},
	[125] = {.x = 13, .y = 5, .width = 1, .height = 1},
	[30] = {.x = 13, .y = 5, .width = 1, .height = 1},
	[31] = {.x = 13, .y = 5, .width = 1, .height = 1},
	[1] = {.x = 18, .y = 4, .width = 1, .height = 1},
	[2] = {.x = 18, .y = 4, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_3  = {
	[0] = {.x = 21, .y = 11, .width = 1, .height = 1},
	[1] = {.x = 21, .y = 8, .width = 1, .height = 1},
	[2] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[67] = {.x = 20, .y = 5, .width = 1, .height = 1},
	[4] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[5] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[6] = {.x = 11, .y = 6, .width = 1, .height = 1},
	[72] = {.x = 20, .y = 10, .width = 1, .height = 1},
	[73] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[74] = {.x = 19, .y = 5, .width = 1, .height = 1},
	[75] = {.x = 17, .y = 6, .width = 1, .height = 1},
	[76] = {.x = 21, .y = 9, .width = 1, .height = 2},
	[66] = {.x = 17, .y = 6, .width = 1, .height = 1},
	[3] = {.x = 18, .y = 5, .width = 1, .height = 1},
	[21] = {.x = 20, .y = 5, .width = 1, .height = 1},
	[22] = {.x = 21, .y = 6, .width = 1, .height = 2},
	[23] = {.x = 16, .y = 6, .width = 1, .height = 1},
	[24] = {.x = 14, .y = 6, .width = 1, .height = 1},
	[70] = {.x = 17, .y = 6, .width = 1, .height = 1},
	[41] = {.x = 17, .y = 6, .width = 1, .height = 2},
	[19] = {.x = 21, .y = 9, .width = 1, .height = 2},
	[57] = {.x = 20, .y = 10, .width = 1, .height = 1},
	[7] = {.x = 17, .y = 6, .width = 1, .height = 1},
	[8] = {.x = 18, .y = 3, .width = 1, .height = 1},
	[9] = {.x = 18, .y = 2, .width = 1, .height = 1},
	[10] = {.x = 18, .y = 0, .width = 1, .height = 2},
	[11] = {.x = 21, .y = 1, .width = 1, .height = 3},
	[12] = {.x = 17, .y = 9, .width = 1, .height = 2},
	[13] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[14] = {.x = 18, .y = 11, .width = 1, .height = 1},
	[15] = {.x = 16, .y = 11, .width = 1, .height = 1},
	[16] = {.x = 14, .y = 11, .width = 2, .height = 1},
	[17] = {.x = 13, .y = 11, .width = 1, .height = 1},
	[18] = {.x = 13, .y = 9, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_4  = {
	[0] = {.x = 21, .y = 11, .width = 1, .height = 1},
	[1] = {.x = 21, .y = 11, .width = 1, .height = 1},
	[2] = {.x = 21, .y = 11, .width = 1, .height = 1},
	[4] = {.x = 21, .y = 11, .width = 1, .height = 1},
	[3] = {.x = 21, .y = 11, .width = 1, .height = 1},
	[5] = {.x = 21, .y = 11, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_5  = {
	[0] = {.x = 21, .y = 8, .width = 1, .height = 1},
	[2] = {.x = 21, .y = 8, .width = 1, .height = 1},
	[4] = {.x = 21, .y = 8, .width = 1, .height = 1},
	[11] = {.x = 21, .y = 8, .width = 1, .height = 1},
	[12] = {.x = 21, .y = 8, .width = 1, .height = 1},
	[13] = {.x = 21, .y = 8, .width = 1, .height = 1},
	[1] = {.x = 21, .y = 8, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_6  = {
	[0] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[1] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[2] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[3] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[5] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[9] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[13] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[14] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[15] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[4] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[6] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[7] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[8] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[10] = {.x = 21, .y = 0, .width = 1, .height = 1},
	[11] = {.x = 21, .y = 0, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_7  = {
	[1] = {.x = 18, .y = 5, .width = 1, .height = 1},
	[2] = {.x = 18, .y = 5, .width = 1, .height = 1},
	[3] = {.x = 18, .y = 5, .width = 1, .height = 1},
	[5] = {.x = 18, .y = 5, .width = 1, .height = 1},
	[8] = {.x = 18, .y = 5, .width = 1, .height = 1},
	[10] = {.x = 18, .y = 5, .width = 1, .height = 1},
	[0] = {.x = 18, .y = 5, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_8  = {
	[0] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[1] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[2] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[3] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[4] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[5] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[6] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[7] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[8] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[9] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[10] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[11] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[12] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[13] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[14] = {.x = 21, .y = 4, .width = 1, .height = 2},
};

static worldmap_position_bank worldmap_positions_bank_9  = {
	[1] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[3] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[4] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[9] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[10] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[11] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[12] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[13] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[14] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[15] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[16] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[17] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[18] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[19] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[0] = {.x = 15, .y = 6, .width = 1, .height = 1},
	[2] = {.x = 15, .y = 6, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_10  = {
	[16] = {.x = 11, .y = 6, .width = 1, .height = 1},
	[12] = {.x = 11, .y = 6, .width = 1, .height = 1},
	[20] = {.x = 11, .y = 6, .width = 1, .height = 1},
	[22] = {.x = 11, .y = 6, .width = 1, .height = 1},
	[0] = {.x = 11, .y = 6, .width = 1, .height = 1},
	[1] = {.x = 11, .y = 6, .width = 1, .height = 1},
	[2] = {.x = 11, .y = 6, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_15  = {
	[0] = {.x = 17, .y = 5, .width = 1, .height = 1},
	[1] = {.x = 17, .y = 5, .width = 1, .height = 1},
	[4] = {.x = 17, .y = 5, .width = 1, .height = 1},
	[5] = {.x = 17, .y = 5, .width = 1, .height = 1},
	[2] = {.x = 17, .y = 5, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_16  = {
	[3] = {.x = 21, .y = 7, .width = 1, .height = 1},
	[4] = {.x = 21, .y = 6, .width = 1, .height = 1},
	[0] = {.x = 21, .y = 6, .width = 1, .height = 2},
};

static worldmap_position_bank worldmap_positions_bank_17  = {
	[2] = {.x = 16, .y = 6, .width = 1, .height = 1},
	[3] = {.x = 16, .y = 6, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_18  = {
	[2] = {.x = 14, .y = 6, .width = 1, .height = 1},
	[3] = {.x = 12, .y = 6, .width = 2, .height = 1},
	[0] = {.x = 12, .y = 6, .width = 3, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_2  = {
	[33] = {.x = 0, .y = 0, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_11  = {
	[0] = {.x = 20, .y = 6, .width = 1, .height = 1},
	[1] = {.x = 20, .y = 8, .width = 1, .height = 1},
	[2] = {.x = 18, .y = 8, .width = 1, .height = 1},
	[3] = {.x = 17, .y = 6, .width = 1, .height = 1},
	[4] = {.x = 17, .y = 6, .width = 1, .height = 1},
	[5] = {.x = 17, .y = 8, .width = 1, .height = 1},
	[6] = {.x = 18, .y = 8, .width = 2, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_12  = {
	[0] = {.x = 18, .y = 2, .width = 1, .height = 1},
	[1] = {.x = 18, .y = 2, .width = 1, .height = 1},
	[2] = {.x = 18, .y = 2, .width = 1, .height = 1},
	[3] = {.x = 18, .y = 2, .width = 1, .height = 1},
	[4] = {.x = 18, .y = 2, .width = 1, .height = 1},
	[5] = {.x = 18, .y = 2, .width = 1, .height = 1},
	[6] = {.x = 18, .y = 2, .width = 1, .height = 1},
	[7] = {.x = 18, .y = 2, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_13  = {
	[0] = {.x = 19, .y = 0, .width = 2, .height = 1},
	[1] = {.x = 20, .y = 0, .width = 1, .height = 1},
	[2] = {.x = 19, .y = 0, .width = 1, .height = 1},
	[3] = {.x = 19, .y = 0, .width = 1, .height = 1},
	[4] = {.x = 18, .y = 0, .width = 1, .height = 2},
	[5] = {.x = 19, .y = 0, .width = 2, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_14  = {
	[0] = {.x = 21, .y = 1, .width = 1, .height = 3},
};

static worldmap_position_bank worldmap_positions_bank_19  = {
	[0] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[1] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[2] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[3] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[4] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[5] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[6] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[7] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[8] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[9] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[10] = {.x = 17, .y = 11, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_20  = {
	[0] = {.x = 18, .y = 11, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_21  = {
	[0] = {.x = 0, .y = 0, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_22  = {
	[0] = {.x = 20, .y = 5, .width = 1, .height = 1},
	[1] = {.x = 19, .y = 5, .width = 1, .height = 1},
	[2] = {.x = 20, .y = 5, .width = 1, .height = 1},
	[3] = {.x = 20, .y = 5, .width = 1, .height = 1},
	[4] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[5] = {.x = 21, .y = 5, .width = 1, .height = 1},
	[6] = {.x = 21, .y = 5, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_23  = {
	[0] = {.x = 18, .y = 3, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_24  = {
	[0] = {.x = 21, .y = 4, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_25  = {
	[0] = {.x = 17, .y = 9, .width = 1, .height = 3},
};

static worldmap_position_bank worldmap_positions_bank_26  = {
	[0] = {.x = 16, .y = 11, .width = 1, .height = 1},
	[1] = {.x = 14, .y = 11, .width = 2, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_27  = {
	[0] = {.x = 13, .y = 11, .width = 1, .height = 1},
	[1] = {.x = 13, .y = 11, .width = 1, .height = 1},
	[2] = {.x = 13, .y = 11, .width = 1, .height = 1},
	[3] = {.x = 13, .y = 11, .width = 1, .height = 1},
	[4] = {.x = 13, .y = 11, .width = 1, .height = 1},
	[5] = {.x = 13, .y = 11, .width = 1, .height = 1},
	[6] = {.x = 13, .y = 11, .width = 1, .height = 1},
	[7] = {.x = 13, .y = 11, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_28  = {
	[0] = {.x = 0x14, .y = 5, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_29  = {
	[0] = {.x = 13, .y = 11, .width = 1, .height = 1},
	[1] = {.x = 13, .y = 10, .width = 1, .height = 1},
	[2] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[3] = {.x = 13, .y = 7, .width = 1, .height = 1},
	[4] = {.x = 13, .y = 7, .width = 1, .height = 1},
	[5] = {.x = 13, .y = 11, .width = 1, .height = 1},
	[6] = {.x = 13, .y = 8, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_31  = {
	[0] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[1] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[2] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[3] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[4] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[5] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[6] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[7] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[8] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[9] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[10] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[11] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[12] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[13] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[14] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[15] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[16] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[17] = {.x = 13, .y = 8, .width = 1, .height = 1},
	[18] = {.x = 13, .y = 8, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_32  = {
	[0] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[1] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[2] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[3] = {.x = 17, .y = 11, .width = 1, .height = 1},
	[4] = {.x = 17, .y = 11, .width = 1, .height = 1},
};

static worldmap_position_bank worldmap_positions_bank_33  = {
	// TODO: Where actually is BB's ship?
};

worldmap_position_t *worldmap_positions[256] = {
	[0] = worldmap_positions_bank_0,
	[1] = worldmap_positions_bank_1,
	[3] = worldmap_positions_bank_3,
	[4] = worldmap_positions_bank_4,
	[5] = worldmap_positions_bank_5,
	[6] = worldmap_positions_bank_6,
	[7] = worldmap_positions_bank_7,
	[8] = worldmap_positions_bank_8,
	[9] = worldmap_positions_bank_9,
	[10] = worldmap_positions_bank_10,
	[15] = worldmap_positions_bank_15,
	[16] = worldmap_positions_bank_16,
	[17] = worldmap_positions_bank_17,
	[18] = worldmap_positions_bank_18,
	[2] = worldmap_positions_bank_2,
	[11] = worldmap_positions_bank_11,
	[12] = worldmap_positions_bank_12,
	[13] = worldmap_positions_bank_13,
	[14] = worldmap_positions_bank_14,
	[19] = worldmap_positions_bank_19,
	[20] = worldmap_positions_bank_20,
	[21] = worldmap_positions_bank_21,
	[22] = worldmap_positions_bank_22,
	[23] = worldmap_positions_bank_23,
	[24] = worldmap_positions_bank_24,
	[25] = worldmap_positions_bank_25,
	[26] = worldmap_positions_bank_26,
	[27] = worldmap_positions_bank_27,
	[28] = worldmap_positions_bank_28,
	[29] = worldmap_positions_bank_29,
	[31] = worldmap_positions_bank_31,
	[32] = worldmap_positions_bank_32,
	[33] = worldmap_positions_bank_33,
};

