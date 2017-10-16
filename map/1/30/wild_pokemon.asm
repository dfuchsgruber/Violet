.include "std.s"

@// Wild data map_1_30_wild_grass
.global map_1_30_wild_grass
.align 4
map_1_30_wild_grass:
.byte 0x9 @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_30_wild_grass_entries

.align 4
map_1_30_wild_grass_entries:
.byte 27, 30 @//Level range
.hword POKEMON_DARTIGNIS @// 20 percent percent
.byte 27, 30 @//Level range
.hword POKEMON_KLEINSTEIN @// 20 percent percent
.byte 27, 30 @//Level range
.hword POKEMON_SCHNECKMAG @// 10 percent percent
.byte 27, 30 @//Level range
.hword POKEMON_DARTIGNIS @// 10 percent percent
.byte 27, 30 @//Level range
.hword POKEMON_KLEINSTEIN @// 10 percent percent
.byte 27, 30 @//Level range
.hword POKEMON_SCHNECKMAG @// 10 percent percent
.byte 28, 31 @//Level range
.hword POKEMON_DARTIGNIS @// 5 percent percent
.byte 28, 31 @//Level range
.hword POKEMON_GEOROK @// 5 percent percent
.byte 29, 32 @//Level range
.hword POKEMON_SCHNECKMAG @// 4 percent percent
.byte 30, 32 @//Level range
.hword POKEMON_DARTIGNIS @// 4 percent percent
.byte 30, 33 @//Level range
.hword POKEMON_GEOROK @// 1 percent percent
.byte 33, 35 @//Level range
.hword POKEMON_MAGCARGO @// 1 percent percent

@// Wild data map_1_30_wild_other
.global map_1_30_wild_other
.align 4
map_1_30_wild_other:
.byte 0x91 @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_30_wild_other_entries

.align 4
map_1_30_wild_other_entries:
.byte 29, 32 @//Level range
.hword POKEMON_VULPIX @// 60 percent percent
.byte 29, 32 @//Level range
.hword POKEMON_DARTIGNIS @// 30 percent percent
.byte 29, 33 @//Level range
.hword POKEMON_CAMAUB @// 5 percent percent
.byte 30, 34 @//Level range
.hword POKEMON_VULPIX @// 4 percent percent
.byte 32, 37 @//Level range
.hword POKEMON_MAGMAR @// 1 percent percent

