.include "species.s"

@// Wild data map_1_82_wild_grass
.global map_1_82_wild_grass
.align 4
map_1_82_wild_grass:
.byte 0x3 @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_82_wild_grass_entries

.align 4
map_1_82_wild_grass_entries:
.byte 26, 30 @//Level range
.hword POKEMON_KLEINSTEIN @// 20 percent percent
.byte 26, 30 @//Level range
.hword POKEMON_SMOGON @// 20 percent percent
.byte 26, 30 @//Level range
.hword POKEMON_MAGBY @// 10 percent percent
.byte 27, 31 @//Level range
.hword POKEMON_CAMAUB @// 10 percent percent
.byte 27, 31 @//Level range
.hword POKEMON_KLEINSTEIN @// 10 percent percent
.byte 27, 31 @//Level range
.hword POKEMON_SMOGON @// 10 percent percent
.byte 27, 32 @//Level range
.hword POKEMON_MAGBY @// 5 percent percent
.byte 28, 32 @//Level range
.hword POKEMON_KLEINSTEIN @// 5 percent percent
.byte 28, 32 @//Level range
.hword POKEMON_SMOGON @// 4 percent percent
.byte 28, 33 @//Level range
.hword POKEMON_MAGBY @// 4 percent percent
.byte 29, 33 @//Level range
.hword POKEMON_KLEINSTEIN @// 1 percent percent
.byte 32, 34 @//Level range
.hword POKEMON_SMOGON @// 1 percent percent

@// Wild data map_1_82_wild_other
.global map_1_82_wild_other
.align 4
map_1_82_wild_other:
.byte 0x32 @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_82_wild_other_entries

.align 4
map_1_82_wild_other_entries:
.byte 5, 20 @//Level range
.hword POKEMON_KLEINSTEIN @// 60 percent percent
.byte 10, 20 @//Level range
.hword POKEMON_KLEINSTEIN @// 30 percent percent
.byte 15, 30 @//Level range
.hword POKEMON_KLEINSTEIN @// 5 percent percent
.byte 25, 40 @//Level range
.hword POKEMON_GEOROK @// 4 percent percent
.byte 30, 40 @//Level range
.hword POKEMON_GEOROK @// 1 percent percent

