.include "std.s"

@// Wild data map_0_6_wild_grass
.global map_0_6_wild_grass
.align 4
map_0_6_wild_grass:
.byte 0x4 @// Frequency in 1/256
.byte 0, 0, 0
.word map_0_6_wild_grass_entries

.align 4
map_0_6_wild_grass_entries:
.byte 16, 19 @//Level range
.hword POKEMON_ZUBAT @// 20 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_NASGNET @// 20 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_KLEINSTEIN @// 10 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_SANDAN @// 10 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_ZUBAT @// 10 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_NASGNET @// 10 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_KLEINSTEIN @// 5 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_SANDAN @// 5 percent percent
.byte 17, 20 @//Level range
.hword POKEMON_ZUBAT @// 4 percent percent
.byte 17, 20 @//Level range
.hword POKEMON_NASGNET @// 4 percent percent
.byte 17, 20 @//Level range
.hword POKEMON_KLEINSTEIN @// 1 percent percent
.byte 18, 21 @//Level range
.hword POKEMON_STOLLUNIOR @// 1 percent percent

