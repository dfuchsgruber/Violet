.include "std.s"

@// Wild data map_3_21_wild_grass
.global map_3_21_wild_grass
map_3_21_wild_grass:
.byte 0x11 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_21_wild_grass_entries

map_3_21_wild_grass_entries:
.byte 17, 19 @//Level range
.hword POKEMON_KNACKLION @// 20 percent percent
.byte 17, 19 @//Level range
.hword POKEMON_PUPPANCE @// 20 percent percent
.byte 17, 19 @//Level range
.hword POKEMON_SANDAN @// 10 percent percent
.byte 17, 19 @//Level range
.hword POKEMON_DIGDA @// 10 percent percent
.byte 17, 19 @//Level range
.hword POKEMON_KNACKLION @// 10 percent percent
.byte 17, 19 @//Level range
.hword POKEMON_DIGDA @// 10 percent percent
.byte 17, 19 @//Level range
.hword POKEMON_SANDAN @// 5 percent percent
.byte 17, 19 @//Level range
.hword POKEMON_PUPPANCE @// 5 percent percent
.byte 17, 19 @//Level range
.hword POKEMON_DIGDA @// 4 percent percent
.byte 17, 19 @//Level range
.hword POKEMON_DIGDA @// 4 percent percent
.byte 17, 19 @//Level range
.hword POKEMON_SANDAN @// 1 percent percent
.byte 19, 22 @//Level range
.hword POKEMON_SANDAN @// 1 percent percent

@// Wild data map_3_21_wild_other
.global map_3_21_wild_other
map_3_21_wild_other:
.byte 0x9a @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_21_wild_other_entries

map_3_21_wild_other_entries:
.byte 16, 19 @//Level range
.hword POKEMON_TUSKA @// 60 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_TUSKA @// 30 percent percent
.byte 16, 21 @//Level range
.hword POKEMON_TUSKA @// 5 percent percent
.byte 18, 22 @//Level range
.hword POKEMON_SANDAMER @// 4 percent percent
.byte 25, 25 @//Level range
.hword POKEMON_SANDAMER @// 1 percent percent

