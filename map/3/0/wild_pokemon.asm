.include "std.s"

@// Wild data map_3_0_wild_water
.global map_3_0_wild_water
map_3_0_wild_water:
.byte 0x9 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_0_wild_water_entries

map_3_0_wild_water_entries:
.byte 33, 35 @//Level range
.hword POKEMON_LOTURZEL @// 60 percent percent
.byte 33, 35 @//Level range
.hword POKEMON_MASKEREGEN @// 30 percent percent
.byte 33, 35 @//Level range
.hword POKEMON_LOTURZEL @// 5 percent percent
.byte 33, 35 @//Level range
.hword POKEMON_MASKEREGEN @// 4 percent percent
.byte 34, 35 @//Level range
.hword POKEMON_LOTURZEL @// 1 percent percent

@// Wild data map_3_0_wild_rod
.global map_3_0_wild_rod
map_3_0_wild_rod:
.byte 0x9 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_0_wild_rod_entries

map_3_0_wild_rod_entries:
.byte 33, 35 @//Level range
.hword POKEMON_LOTURZEL @// 70 percent, rod percent
.byte 33, 35 @//Level range
.hword POKEMON_MASKEREGEN @// 30 percent, rod percent
.byte 33, 35 @//Level range
.hword POKEMON_LOTURZEL @// 60 percent, profi rod percent
.byte 33, 35 @//Level range
.hword POKEMON_MASKEREGEN @// 20 percent, profi rod percent
.byte 34, 35 @//Level range
.hword POKEMON_LOTURZEL @// 20 percent, profi rod percent
.byte 11, 11 @//Level range
.hword POKEMON_KARPADOR @// 40 percent, super rod percent
.byte 11, 1 @//Level range
.hword POKEMON_KARPADOR @// 40 percent, super rod percent
.byte 22, 25 @//Level range
.hword POKEMON_FLEGMON @// 15 percent, super rod percent
.byte 22, 25 @//Level range
.hword POKEMON_KARPADOR @// 4 percent, super rod percent
.byte 22, 25 @//Level range
.hword POKEMON_KARPADOR @// 1 percent, super rod percent

