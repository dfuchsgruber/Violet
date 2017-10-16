.include "std.s"

@// Wild data map_3_2_wild_water
.global map_3_2_wild_water
.align 4
map_3_2_wild_water:
.byte 0x0 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_2_wild_water_entries

.align 4
map_3_2_wild_water_entries:
.byte 23, 29 @//Level range
.hword POKEMON_WINGULL @// 60 percent percent
.byte 24, 30 @//Level range
.hword POKEMON_TENTACHA @// 30 percent percent
.byte 25, 31 @//Level range
.hword POKEMON_WINGULL @// 5 percent percent
.byte 30, 33 @//Level range
.hword POKEMON_PELIPPER @// 4 percent percent
.byte 30, 33 @//Level range
.hword POKEMON_PELIPPER @// 1 percent percent

@// Wild data map_3_2_wild_rod
.global map_3_2_wild_rod
.align 4
map_3_2_wild_rod:
.byte 0x0 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_2_wild_rod_entries

.align 4
map_3_2_wild_rod_entries:
.byte 23, 29 @//Level range
.hword POKEMON_WINGULL @// 70 percent, rod percent
.byte 24, 30 @//Level range
.hword POKEMON_TENTACHA @// 30 percent, rod percent
.byte 25, 31 @//Level range
.hword POKEMON_WINGULL @// 60 percent, profi rod percent
.byte 30, 33 @//Level range
.hword POKEMON_PELIPPER @// 20 percent, profi rod percent
.byte 30, 33 @//Level range
.hword POKEMON_PELIPPER @// 20 percent, profi rod percent
.byte 0, 0 @//Level range
.hword POKEMON_POKEMON_0 @// 40 percent, super rod percent
.byte 52, 157 @//Level range
.hword 0x871 @// 40 percent, super rod percent
.byte 255, 255 @//Level range
.hword 0xffff @// 15 percent, super rod percent
.byte 255, 22 @//Level range
.hword 0x402f @// 4 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_BIBOR @// 1 percent, super rod percent

