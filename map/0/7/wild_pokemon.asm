.include "std.s"

@// Wild data map_0_7_wild_grass
.global map_0_7_wild_grass
.align 4
map_0_7_wild_grass:
.byte 0x1 @// Frequency in 1/256
.byte 0, 0, 0
.word map_0_7_wild_grass_entries

.align 4
map_0_7_wild_grass_entries:
.byte 20, 22 @//Level range
.hword POKEMON_MARILL @// 20 percent percent
.byte 18, 22 @//Level range
.hword POKEMON_KRABBY @// 20 percent percent
.byte 18, 22 @//Level range
.hword POKEMON_ZUBAT @// 10 percent percent
.byte 18, 22 @//Level range
.hword POKEMON_MARILL @// 10 percent percent
.byte 18, 22 @//Level range
.hword POKEMON_KRABBY @// 10 percent percent
.byte 18, 18 @//Level range
.hword POKEMON_ZUBAT @// 10 percent percent
.byte 22, 22 @//Level range
.hword POKEMON_MARILL @// 5 percent percent
.byte 22, 17 @//Level range
.hword POKEMON_KRABBY @// 5 percent percent
.byte 17, 17 @//Level range
.hword POKEMON_ZUBAT @// 4 percent percent
.byte 18, 18 @//Level range
.hword POKEMON_MARILL @// 4 percent percent
.byte 19, 21 @//Level range
.hword POKEMON_KRABBY @// 1 percent percent
.byte 26, 26 @//Level range
.hword POKEMON_AZUMARILL @// 1 percent percent

@// Wild data map_0_7_wild_water
.global map_0_7_wild_water
.align 4
map_0_7_wild_water:
.byte 0xa @// Frequency in 1/256
.byte 0, 0, 0
.word map_0_7_wild_water_entries

.align 4
map_0_7_wild_water_entries:
.byte 25, 32 @//Level range
.hword POKEMON_KRABBY @// 60 percent percent
.byte 25, 32 @//Level range
.hword POKEMON_KREBSCORPS @// 30 percent percent
.byte 27, 33 @//Level range
.hword POKEMON_KRABBY @// 5 percent percent
.byte 25, 34 @//Level range
.hword POKEMON_KINGLER @// 4 percent percent
.byte 30, 35 @//Level range
.hword POKEMON_KINGLER @// 1 percent percent

@// Wild data map_0_7_wild_rod
.global map_0_7_wild_rod
.align 4
map_0_7_wild_rod:
.byte 0xa @// Frequency in 1/256
.byte 0, 0, 0
.word map_0_7_wild_rod_entries

.align 4
map_0_7_wild_rod_entries:
.byte 25, 32 @//Level range
.hword POKEMON_KRABBY @// 70 percent, rod percent
.byte 25, 32 @//Level range
.hword POKEMON_KREBSCORPS @// 30 percent, rod percent
.byte 27, 33 @//Level range
.hword POKEMON_KRABBY @// 60 percent, profi rod percent
.byte 25, 34 @//Level range
.hword POKEMON_KINGLER @// 20 percent, profi rod percent
.byte 30, 35 @//Level range
.hword POKEMON_KINGLER @// 20 percent, profi rod percent
.byte 10, 0 @//Level range
.hword POKEMON_POKEMON_0 @// 40 percent, super rod percent
.byte 64, 40 @//Level range
.hword 0x872 @// 40 percent, super rod percent
.byte 20, 22 @//Level range
.hword POKEMON_KARPADOR @// 15 percent, super rod percent
.byte 20, 22 @//Level range
.hword POKEMON_KARPADOR @// 4 percent, super rod percent
.byte 20, 22 @//Level range
.hword POKEMON_KARPADOR @// 1 percent, super rod percent

