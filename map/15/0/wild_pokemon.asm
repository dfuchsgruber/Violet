.include "std.s"

@// Wild data map_15_0_wild_grass
.global map_15_0_wild_grass
map_15_0_wild_grass:
.byte 0x10 @// Frequency in 1/256
.byte 0, 0, 0
.word map_15_0_wild_grass_entries

map_15_0_wild_grass_entries:
.byte 9, 12 @//Level range
.hword POKEMON_VOLTILAMM @// 20 percent percent
.byte 8, 11 @//Level range
.hword POKEMON_KNOFENSA @// 20 percent percent
.byte 9, 13 @//Level range
.hword POKEMON_MYRAPLA @// 10 percent percent
.byte 9, 13 @//Level range
.hword POKEMON_MAEHIKEL @// 10 percent percent
.byte 7, 14 @//Level range
.hword POKEMON_VOLTILAMM @// 10 percent percent
.byte 9, 13 @//Level range
.hword POKEMON_KNOFENSA @// 10 percent percent
.byte 8, 11 @//Level range
.hword POKEMON_MYRAPLA @// 5 percent percent
.byte 8, 11 @//Level range
.hword POKEMON_MAEHIKEL @// 5 percent percent
.byte 8, 11 @//Level range
.hword POKEMON_VOLTILAMM @// 4 percent percent
.byte 8, 11 @//Level range
.hword POKEMON_VOLTILAMM @// 4 percent percent
.byte 8, 11 @//Level range
.hword POKEMON_KNOFENSA @// 1 percent percent
.byte 15, 15 @//Level range
.hword POKEMON_WAATY @// 1 percent percent

@// Wild data map_15_0_wild_water
.global map_15_0_wild_water
map_15_0_wild_water:
.byte 0xb @// Frequency in 1/256
.byte 0, 0, 0
.word map_15_0_wild_water_entries

map_15_0_wild_water_entries:
.byte 26, 30 @//Level range
.hword POKEMON_LOTURZEL @// 60 percent percent
.byte 28, 33 @//Level range
.hword POKEMON_LOMBRERO @// 30 percent percent
.byte 28, 30 @//Level range
.hword POKEMON_MARILL @// 5 percent percent
.byte 30, 35 @//Level range
.hword POKEMON_AZUMARILL @// 4 percent percent
.byte 30, 38 @//Level range
.hword POKEMON_AZUMARILL @// 1 percent percent

@// Wild data map_15_0_wild_other
.global map_15_0_wild_other
map_15_0_wild_other:
.byte 0x82 @// Frequency in 1/256
.byte 0, 0, 0
.word map_15_0_wild_other_entries

map_15_0_wild_other_entries:
.byte 10, 14 @//Level range
.hword POKEMON_MOGELBAUM @// 60 percent percent
.byte 10, 14 @//Level range
.hword POKEMON_CLAVION @// 30 percent percent
.byte 10, 14 @//Level range
.hword POKEMON_SCHLURP @// 5 percent percent
.byte 12, 14 @//Level range
.hword POKEMON_MOGELBAUM @// 4 percent percent
.byte 14, 16 @//Level range
.hword POKEMON_CLAVION @// 1 percent percent

@// Wild data map_15_0_wild_rod
.global map_15_0_wild_rod
map_15_0_wild_rod:
.byte 0xb @// Frequency in 1/256
.byte 0, 0, 0
.word map_15_0_wild_rod_entries

map_15_0_wild_rod_entries:
.byte 26, 30 @//Level range
.hword POKEMON_LOTURZEL @// 70 percent, rod percent
.byte 28, 33 @//Level range
.hword POKEMON_LOMBRERO @// 30 percent, rod percent
.byte 28, 30 @//Level range
.hword POKEMON_MARILL @// 60 percent, profi rod percent
.byte 30, 35 @//Level range
.hword POKEMON_AZUMARILL @// 20 percent, profi rod percent
.byte 30, 38 @//Level range
.hword POKEMON_AZUMARILL @// 20 percent, profi rod percent
.byte 11, 0 @//Level range
.hword POKEMON_POKEMON_0 @// 40 percent, super rod percent
.byte 0, 11 @//Level range
.hword 0x872 @// 40 percent, super rod percent
.byte 10, 14 @//Level range
.hword POKEMON_MOGELBAUM @// 15 percent, super rod percent
.byte 10, 14 @//Level range
.hword POKEMON_CLAVION @// 4 percent, super rod percent
.byte 10, 14 @//Level range
.hword POKEMON_SCHLURP @// 1 percent, super rod percent

