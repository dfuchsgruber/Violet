.include "std.s"

@// Wild data map_0_5_wild_grass
.global map_0_5_wild_grass
map_0_5_wild_grass:
.byte 0x2 @// Frequency in 1/256
.byte 0, 0, 0
.word map_0_5_wild_grass_entries

map_0_5_wild_grass_entries:
.byte 15, 18 @//Level range
.hword POKEMON_KLEINSTEIN @// 20 percent percent
.byte 15, 18 @//Level range
.hword POKEMON_ZUBAT @// 20 percent percent
.byte 15, 18 @//Level range
.hword POKEMON_MACHOLLO @// 10 percent percent
.byte 15, 18 @//Level range
.hword POKEMON_SANDAN @// 10 percent percent
.byte 15, 18 @//Level range
.hword POKEMON_KLEINSTEIN @// 10 percent percent
.byte 15, 18 @//Level range
.hword POKEMON_MACHOLLO @// 10 percent percent
.byte 15, 18 @//Level range
.hword POKEMON_ZUBAT @// 5 percent percent
.byte 16, 19 @//Level range
.hword POKEMON_SANDAN @// 5 percent percent
.byte 16, 19 @//Level range
.hword POKEMON_KLEINSTEIN @// 4 percent percent
.byte 16, 19 @//Level range
.hword POKEMON_ZUBAT @// 4 percent percent
.byte 17, 20 @//Level range
.hword POKEMON_MACHOLLO @// 1 percent percent
.byte 22, 22 @//Level range
.hword POKEMON_SANDAN @// 1 percent percent

