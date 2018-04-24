.include "species.s"

@// Wild data map_0_12_wild_grass
.global map_0_12_wild_grass
.align 4
map_0_12_wild_grass:
.byte 0x1c @// Frequency in 1/256
.byte 0, 0, 0
.word map_0_12_wild_grass_entries

.align 4
map_0_12_wild_grass_entries:
.byte 26, 30 @//Level range
.hword POKEMON_CAMAUB @// 20 percent percent
.byte 26, 30 @//Level range
.hword POKEMON_SCHNECKMAG @// 20 percent percent
.byte 26, 30 @//Level range
.hword POKEMON_KLEINSTEIN @// 10 percent percent
.byte 27, 31 @//Level range
.hword POKEMON_CAMAUB @// 10 percent percent
.byte 27, 31 @//Level range
.hword POKEMON_SCHNECKMAG @// 10 percent percent
.byte 27, 31 @//Level range
.hword POKEMON_KLEINSTEIN @// 10 percent percent
.byte 27, 32 @//Level range
.hword POKEMON_CAMAUB @// 5 percent percent
.byte 28, 32 @//Level range
.hword POKEMON_SCHNECKMAG @// 5 percent percent
.byte 29, 33 @//Level range
.hword POKEMON_GEOROK @// 4 percent percent
.byte 29, 33 @//Level range
.hword POKEMON_CAMAUB @// 4 percent percent
.byte 30, 33 @//Level range
.hword POKEMON_SCHNECKMAG @// 1 percent percent
.byte 33, 34 @//Level range
.hword POKEMON_GEOROK @// 1 percent percent

