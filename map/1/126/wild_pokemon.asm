.include "std.s"

@// Wild data map_1_126_wild_grass
.global map_1_126_wild_grass
map_1_126_wild_grass:
.byte 0x2 @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_126_wild_grass_entries

map_1_126_wild_grass_entries:
.byte 26, 31 @//Level range
.hword POKEMON_KLEINSTEIN @// 20 percent percent
.byte 26, 31 @//Level range
.hword POKEMON_MAGBY @// 20 percent percent
.byte 26, 31 @//Level range
.hword POKEMON_SCHNECKMAG @// 10 percent percent
.byte 26, 31 @//Level range
.hword POKEMON_SMOGON @// 10 percent percent
.byte 27, 31 @//Level range
.hword POKEMON_KLEINSTEIN @// 10 percent percent
.byte 27, 31 @//Level range
.hword POKEMON_MAGBY @// 10 percent percent
.byte 27, 31 @//Level range
.hword POKEMON_SCHNECKMAG @// 5 percent percent
.byte 27, 32 @//Level range
.hword POKEMON_SMOGON @// 5 percent percent
.byte 28, 32 @//Level range
.hword POKEMON_KLEINSTEIN @// 4 percent percent
.byte 28, 33 @//Level range
.hword POKEMON_MAGBY @// 4 percent percent
.byte 29, 33 @//Level range
.hword POKEMON_SCHNECKMAG @// 1 percent percent
.byte 33, 35 @//Level range
.hword POKEMON_SMOGON @// 1 percent percent

