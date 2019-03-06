.include "species.s"

@// Wild data map_3_76_wild_grass
.global map_3_76_wild_grass
.align 4
map_3_76_wild_grass:
.byte 0x3 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_76_wild_grass_entries

.align 4
map_3_76_wild_grass_entries:
.byte 24, 27 @//Level range
.hword POKEMON_WABLU @// 20 percent percent
.byte 23, 28 @//Level range
.hword POKEMON_SCHWALBINI @// 20 percent percent
.byte 24, 28 @//Level range
.hword POKEMON_KRAMURX @// 10 percent percent
.byte 24, 29 @//Level range
.hword POKEMON_WABLU @// 10 percent percent
.byte 24, 27 @//Level range
.hword POKEMON_SCHWALBINI @// 10 percent percent
.byte 26, 28 @//Level range
.hword POKEMON_KRAMURX @// 10 percent percent
.byte 26, 28 @//Level range
.hword POKEMON_WABLU @// 5 percent percent
.byte 27, 29 @//Level range
.hword POKEMON_SCHWALBINI @// 5 percent percent
.byte 27, 29 @//Level range
.hword POKEMON_SCHWALBINI @// 4 percent percent
.byte 28, 30 @//Level range
.hword POKEMON_KRAMURX @// 4 percent percent
.byte 28, 30 @//Level range
.hword POKEMON_WABLU @// 1 percent percent
.byte 32, 32 @//Level range
.hword POKEMON_KRAMURX @// 1 percent percent

