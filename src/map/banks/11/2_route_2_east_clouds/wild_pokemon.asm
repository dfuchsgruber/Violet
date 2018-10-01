.include "species.s"

@// Wild data map_17_2_wild_grass
.global map_11_2_route_2_east_clouds_wild_grass
.align 4
map_11_2_route_2_east_clouds_wild_grass:
.byte 3 @// Frequency in 1/256
.byte 0, 0, 0
.word grass_entries

.align 4
grass_entries:
.byte 24, 27 @//Level range
.hword POKEMON_KRAMURX @// 20 percent percent
.byte 23, 27 @//Level range
.hword POKEMON_SCHWALBINI @// 20 percent percent
.byte 23, 27 @//Level range
.hword POKEMON_DARTIGNIS @// 10 percent percent
.byte 23, 27 @//Level range
.hword POKEMON_KRAMURX @// 10 percent percent
.byte 23, 27 @//Level range
.hword POKEMON_SCHWALBINI @// 10 percent percent
.byte 23, 27 @//Level range
.hword POKEMON_KRAMURX @// 10 percent percent
.byte 24, 28 @//Level range
.hword POKEMON_DARTIGNIS @// 5 percent percent
.byte 25, 28 @//Level range
.hword POKEMON_SCHWALBINI @// 5 percent percent
.byte 26, 29 @//Level range
.hword POKEMON_DARTIGNIS @// 4 percent percent
.byte 26, 29 @//Level range
.hword POKEMON_KRAMURX @// 4 percent percent
.byte 27, 29 @//Level range
.hword POKEMON_KRAMURX @// 1 percent percent
.byte 28, 32 @//Level range
.hword POKEMON_STARAVIA @// 1 percent percent

