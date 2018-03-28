.include "std.s"

@// Wild data map_3_1_wild_water
.global map_3_1_wild_water
.align 4
map_3_1_wild_water:
.byte 0xf @// Frequency in 1/256
.byte 25, 67, 1
.word map_3_1_wild_water_entries

.align 4
map_3_1_wild_water_entries:
.byte 25, 30 @//Level range
.hword POKEMON_LOTURZEL @// 60 percent percent
.byte 25, 30 @//Level range
.hword POKEMON_ENTON @// 30 percent percent
.byte 25, 30 @//Level range
.hword POKEMON_LOTURZEL @// 5 percent percent
.byte 27, 30 @//Level range
.hword POKEMON_LOMBRERO @// 4 percent percent
.byte 27, 32 @//Level range
.hword POKEMON_LOMBRERO @// 1 percent percent

@// Wild data map_3_1_wild_rod
.global map_3_1_wild_rod
.align 4
map_3_1_wild_rod:
.byte 0x58 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_1_wild_rod_entries

.align 4
map_3_1_wild_rod_entries:
.byte 9, 12 @//Level range
.hword POKEMON_KARPADOR @// 70 percent, rod percent
.byte 9, 13 @//Level range
.hword POKEMON_KARPADOR @// 30 percent, rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KARPADOR @// 60 percent, profi rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KARPADOR @// 20 percent, profi rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KARPADOR @// 20 percent, profi rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KARPADOR @// 40 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KARPADOR @// 40 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KARPADOR @// 15 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_GARADOS @// 4 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_GARADOS @// 1 percent, super rod percent

