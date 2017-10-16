.include "std.s"

@// Wild data map_3_23_wild_grass
.global map_3_23_wild_grass
.align 4
map_3_23_wild_grass:
.byte 0x15 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_23_wild_grass_entries

.align 4
map_3_23_wild_grass_entries:
.byte 23, 26 @//Level range
.hword POKEMON_MINUN @// 20 percent percent
.byte 23, 26 @//Level range
.hword POKEMON_PLUSLE @// 20 percent percent
.byte 23, 26 @//Level range
.hword POKEMON_MEDITIE @// 10 percent percent
.byte 23, 26 @//Level range
.hword POKEMON_WABLU @// 10 percent percent
.byte 23, 26 @//Level range
.hword POKEMON_MINUN @// 10 percent percent
.byte 23, 26 @//Level range
.hword POKEMON_PLUSLE @// 10 percent percent
.byte 24, 26 @//Level range
.hword POKEMON_MEDITIE @// 5 percent percent
.byte 24, 27 @//Level range
.hword POKEMON_WABLU @// 5 percent percent
.byte 24, 27 @//Level range
.hword POKEMON_MEDITIE @// 4 percent percent
.byte 25, 28 @//Level range
.hword POKEMON_MEDITIE @// 4 percent percent
.byte 26, 30 @//Level range
.hword POKEMON_MEDITIE @// 1 percent percent
.byte 28, 32 @//Level range
.hword POKEMON_MEDITIE @// 1 percent percent

@// Wild data map_3_23_wild_other
.global map_3_23_wild_other
.align 4
map_3_23_wild_other:
.byte 0xa1 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_23_wild_other_entries

.align 4
map_3_23_wild_other_entries:
.byte 25, 28 @//Level range
.hword POKEMON_SNUBBULL @// 60 percent percent
.byte 26, 28 @//Level range
.hword POKEMON_SPOINK @// 30 percent percent
.byte 28, 32 @//Level range
.hword POKEMON_WABLU @// 5 percent percent
.byte 29, 32 @//Level range
.hword POKEMON_SPOINK @// 4 percent percent
.byte 32, 34 @//Level range
.hword POKEMON_SPOINK @// 1 percent percent

