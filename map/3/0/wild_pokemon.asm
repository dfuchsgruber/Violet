.include "species.s"

@// Wild data map_3_0_wild_water
.global map_3_0_wild_water
.align 4
map_3_0_wild_water:
.byte 0x9 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_0_wild_water_entries

.align 4
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
.align 4
map_3_0_wild_rod:
.byte 0x42 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_0_wild_rod_entries

.align 4
map_3_0_wild_rod_entries:
.byte 11, 11 @//Level range
.hword POKEMON_KARPADOR @// 70 percent, rod percent
.byte 11, 1 @//Level range
.hword POKEMON_KARPADOR @// 30 percent, rod percent
.byte 22, 25 @//Level range
.hword POKEMON_FLEGMON @// 60 percent, profi rod percent
.byte 22, 25 @//Level range
.hword POKEMON_KARPADOR @// 20 percent, profi rod percent
.byte 22, 25 @//Level range
.hword POKEMON_KARPADOR @// 20 percent, profi rod percent
.byte 35, 38 @//Level range
.hword POKEMON_FLEGMON @// 40 percent, super rod percent
.byte 35, 38 @//Level range
.hword POKEMON_KARPADOR @// 40 percent, super rod percent
.byte 35, 38 @//Level range
.hword POKEMON_KARPADOR @// 15 percent, super rod percent
.byte 35, 38 @//Level range
.hword POKEMON_GARADOS @// 4 percent, super rod percent
.byte 35, 38 @//Level range
.hword POKEMON_FLEGMON @// 1 percent, super rod percent

