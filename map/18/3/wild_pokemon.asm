.include "std.s"

@// Wild data map_18_3_wild_grass
.global map_18_3_wild_grass
map_18_3_wild_grass:
.byte 0x18 @// Frequency in 1/256
.byte 0, 0, 0
.word map_18_3_wild_grass_entries

map_18_3_wild_grass_entries:
.byte 24, 27 @//Level range
.hword POKEMON_VULPIX @// 20 percent percent
.byte 24, 27 @//Level range
.hword POKEMON_SCHNECKMAG @// 20 percent percent
.byte 24, 27 @//Level range
.hword POKEMON_MAGBY @// 10 percent percent
.byte 24, 27 @//Level range
.hword POKEMON_CAMAUB @// 10 percent percent
.byte 25, 29 @//Level range
.hword POKEMON_VULPIX @// 10 percent percent
.byte 25, 29 @//Level range
.hword POKEMON_SCHNECKMAG @// 10 percent percent
.byte 25, 29 @//Level range
.hword POKEMON_CAMAUB @// 5 percent percent
.byte 25, 29 @//Level range
.hword POKEMON_MAGBY @// 5 percent percent
.byte 26, 30 @//Level range
.hword POKEMON_VULPIX @// 4 percent percent
.byte 26, 30 @//Level range
.hword POKEMON_SCHNECKMAG @// 4 percent percent
.byte 27, 32 @//Level range
.hword POKEMON_CAMAUB @// 1 percent percent
.byte 29, 34 @//Level range
.hword POKEMON_MAGMAR @// 1 percent percent

@// Wild data map_18_3_wild_other
.global map_18_3_wild_other
map_18_3_wild_other:
.byte 0x4f @// Frequency in 1/256
.byte 0, 0, 0
.word map_18_3_wild_other_entries

map_18_3_wild_other_entries:
.byte 26, 30 @//Level range
.hword POKEMON_FUKANO @// 60 percent percent
.byte 27, 31 @//Level range
.hword POKEMON_HUNDUSTER @// 30 percent percent
.byte 26, 30 @//Level range
.hword POKEMON_FUKANO @// 5 percent percent
.byte 27, 32 @//Level range
.hword POKEMON_HUNDUSTER @// 4 percent percent
.byte 36, 36 @//Level range
.hword POKEMON_PANZAERON @// 1 percent percent

