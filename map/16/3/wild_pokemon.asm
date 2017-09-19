.include "std.s"

@// Wild data map_16_3_wild_grass
.global map_16_3_wild_grass
map_16_3_wild_grass:
.byte 0x4 @// Frequency in 1/256
.byte 0, 0, 0
.word map_16_3_wild_grass_entries

map_16_3_wild_grass_entries:
.byte 21, 24 @//Level range
.hword POKEMON_MACHOLLO @// 20 percent percent
.byte 21, 24 @//Level range
.hword POKEMON_KLEINSTEIN @// 20 percent percent
.byte 21, 24 @//Level range
.hword POKEMON_MENKI @// 10 percent percent
.byte 21, 24 @//Level range
.hword POKEMON_KRABBY @// 10 percent percent
.byte 21, 24 @//Level range
.hword POKEMON_MACHOLLO @// 10 percent percent
.byte 21, 24 @//Level range
.hword POKEMON_KLEINSTEIN @// 10 percent percent
.byte 23, 25 @//Level range
.hword POKEMON_GEOROK @// 5 percent percent
.byte 23, 25 @//Level range
.hword POKEMON_KRABBY @// 5 percent percent
.byte 23, 25 @//Level range
.hword POKEMON_MENKI @// 4 percent percent
.byte 25, 26 @//Level range
.hword POKEMON_MENKI @// 4 percent percent
.byte 27, 27 @//Level range
.hword POKEMON_MASCHOCK @// 1 percent percent
.byte 27, 27 @//Level range
.hword POKEMON_MASCHOCK @// 1 percent percent

