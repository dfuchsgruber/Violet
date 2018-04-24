.include "species.s"

@// Wild data map_18_2_wild_grass
.global map_18_2_wild_grass
.align 4
map_18_2_wild_grass:
.byte 0x4 @// Frequency in 1/256
.byte 0, 0, 0
.word map_18_2_wild_grass_entries

.align 4
map_18_2_wild_grass_entries:
.byte 24, 27 @//Level range
.hword POKEMON_ZUBAT @// 20 percent percent
.byte 24, 27 @//Level range
.hword POKEMON_CAMAUB @// 20 percent percent
.byte 24, 27 @//Level range
.hword POKEMON_MACHOLLO @// 10 percent percent
.byte 25, 28 @//Level range
.hword POKEMON_ZUBAT @// 10 percent percent
.byte 25, 27 @//Level range
.hword POKEMON_CAMAUB @// 10 percent percent
.byte 25, 27 @//Level range
.hword POKEMON_MACHOLLO @// 10 percent percent
.byte 26, 27 @//Level range
.hword POKEMON_ZUBAT @// 5 percent percent
.byte 26, 28 @//Level range
.hword POKEMON_CAMAUB @// 5 percent percent
.byte 27, 29 @//Level range
.hword POKEMON_GOLBAT @// 4 percent percent
.byte 28, 30 @//Level range
.hword POKEMON_MASCHOCK @// 4 percent percent
.byte 29, 32 @//Level range
.hword POKEMON_CAMAUB @// 1 percent percent
.byte 30, 33 @//Level range
.hword POKEMON_CAMAUB @// 1 percent percent

