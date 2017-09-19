.include "std.s"

@// Wild data map_17_2_wild_grass
.global map_17_2_wild_grass
map_17_2_wild_grass:
.byte 0x1 @// Frequency in 1/256
.byte 0, 0, 0
.word map_17_2_wild_grass_entries

map_17_2_wild_grass_entries:
.byte 24, 27 @//Level range
.hword POKEMON_WABLU @// 20 percent percent
.byte 23, 27 @//Level range
.hword POKEMON_SCHWALBINI @// 20 percent percent
.byte 23, 27 @//Level range
.hword POKEMON_DARTIGNIS @// 10 percent percent
.byte 23, 27 @//Level range
.hword POKEMON_WABLU @// 10 percent percent
.byte 23, 27 @//Level range
.hword POKEMON_SCHWALBINI @// 10 percent percent
.byte 23, 27 @//Level range
.hword POKEMON_WABLU @// 10 percent percent
.byte 24, 28 @//Level range
.hword POKEMON_DARTIGNIS @// 5 percent percent
.byte 25, 28 @//Level range
.hword POKEMON_SCHWALBINI @// 5 percent percent
.byte 26, 29 @//Level range
.hword POKEMON_DARTIGNIS @// 4 percent percent
.byte 26, 29 @//Level range
.hword POKEMON_WABLU @// 4 percent percent
.byte 27, 29 @//Level range
.hword POKEMON_WABLU @// 1 percent percent
.byte 28, 32 @//Level range
.hword POKEMON_SCHWALBOSS @// 1 percent percent

