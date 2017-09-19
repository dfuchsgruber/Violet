.include "std.s"

@// Wild data map_3_3_wild_water
.global map_3_3_wild_water
map_3_3_wild_water:
.byte 0x11 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_3_wild_water_entries

map_3_3_wild_water_entries:
.byte 30, 30 @//Level range
.hword POKEMON_SEEPER @// 60 percent percent
.byte 30, 30 @//Level range
.hword POKEMON_SEEPER @// 30 percent percent
.byte 30, 30 @//Level range
.hword POKEMON_SEEPER @// 5 percent percent
.byte 30, 35 @//Level range
.hword POKEMON_SEEMON @// 4 percent percent
.byte 35, 38 @//Level range
.hword POKEMON_SEEDRAKING @// 1 percent percent

@// Wild data map_3_3_wild_rod
.global map_3_3_wild_rod
map_3_3_wild_rod:
.byte 0x11 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_3_wild_rod_entries

map_3_3_wild_rod_entries:
.byte 30, 30 @//Level range
.hword POKEMON_SEEPER @// 70 percent, rod percent
.byte 30, 30 @//Level range
.hword POKEMON_SEEPER @// 30 percent, rod percent
.byte 30, 30 @//Level range
.hword POKEMON_SEEPER @// 60 percent, profi rod percent
.byte 30, 35 @//Level range
.hword POKEMON_SEEMON @// 20 percent, profi rod percent
.byte 35, 38 @//Level range
.hword POKEMON_SEEDRAKING @// 20 percent, profi rod percent
.byte 17, 0 @//Level range
.hword POKEMON_POKEMON_0 @// 40 percent, super rod percent
.byte 172, 150 @//Level range
.hword 0x83c @// 40 percent, super rod percent
.byte 13, 16 @//Level range
.hword POKEMON_KARPADOR @// 15 percent, super rod percent
.byte 13, 16 @//Level range
.hword POKEMON_KARPADOR @// 4 percent, super rod percent
.byte 5, 15 @//Level range
.hword POKEMON_KARPADOR @// 1 percent, super rod percent

