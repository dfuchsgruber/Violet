.include "species.s"

@// Wild data map_3_70_wild_grass
.global map_3_70_wild_grass
.align 4
map_3_70_wild_grass:
.byte 0x9 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_70_wild_grass_entries

.align 4
map_3_70_wild_grass_entries:
.byte 5, 7 @//Level range
.hword POKEMON_KLEINSTEIN @// 20 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_SANDAN @// 20 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_KLEINSTEIN @// 10 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_SANDAN @// 10 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_ONIX @// 10 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_ONIX @// 10 percent percent
.byte 5, 8 @//Level range
.hword POKEMON_KLEINSTEIN @// 5 percent percent
.byte 5, 8 @//Level range
.hword POKEMON_SANDAN @// 5 percent percent
.byte 5, 8 @//Level range
.hword POKEMON_KLEINSTEIN @// 4 percent percent
.byte 6, 8 @//Level range
.hword POKEMON_ONIX @// 4 percent percent
.byte 6, 8 @//Level range
.hword POKEMON_BRONZEL @// 1 percent percent
.byte 7, 8 @//Level range
.hword POKEMON_BRONZEL @// 1 percent percent

