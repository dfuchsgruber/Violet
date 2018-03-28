.include "std.s"

@// Wild data map_15_4_wild_grass
.global map_15_4_wild_grass
.align 4
map_15_4_wild_grass:
.byte 0x6 @// Frequency in 1/256
.byte 0, 0, 0
.word map_15_4_wild_grass_entries

.align 4
map_15_4_wild_grass_entries:
.byte 10, 13 @//Level range
.hword POKEMON_SCHWALBINI @// 20 percent percent
.byte 10, 13 @//Level range
.hword POKEMON_WABLU @// 20 percent percent
.byte 10, 13 @//Level range
.hword POKEMON_SCHWALBINI @// 10 percent percent
.byte 10, 13 @//Level range
.hword POKEMON_STARAVIA @// 10 percent percent
.byte 10, 13 @//Level range
.hword POKEMON_SCHWALBINI @// 10 percent percent
.byte 10, 13 @//Level range
.hword POKEMON_SCHWALBINI @// 10 percent percent
.byte 10, 13 @//Level range
.hword POKEMON_DARTIRI @// 5 percent percent
.byte 10, 13 @//Level range
.hword POKEMON_STARALILI @// 5 percent percent
.byte 10, 13 @//Level range
.hword POKEMON_DARTIRI @// 4 percent percent
.byte 10, 13 @//Level range
.hword POKEMON_WABLU @// 4 percent percent
.byte 10, 13 @//Level range
.hword POKEMON_DARTIRI @// 1 percent percent
.byte 14, 17 @//Level range
.hword POKEMON_STARAVIA @// 1 percent percent

