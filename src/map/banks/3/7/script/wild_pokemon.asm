.include "species.s"

@// Wild data map_15_0_wild_grass
.global map_3_7_route2_east_wild_grass
.align 4
map_3_7_route2_east_wild_grass:
.byte 24 @// Frequency in 1/256
.byte 0, 0, 0
.word grass_entries

.align 4
grass_entries:
.byte 4, 7 @//Level range
.hword POKEMON_KNOFENSA @// 20 percent percent
.byte 4, 7 @//Level range
.hword POKEMON_NIDORANW @// 20 percent percent
.byte 4, 7 @//Level range
.hword POKEMON_FLABEBE @// 10 percent percent
.byte 4, 7 @//Level range
.hword POKEMON_NIDORANM @// 10 percent percent
.byte 4, 7 @//Level range
.hword POKEMON_ENECO @// 10 percent percent
.byte 4, 7 @//Level range
.hword POKEMON_NIDORANW @// 10 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_NIDORANM @// 5 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_NIDORANM @// 5 percent percent
.byte 6, 7 @//Level range
.hword POKEMON_ENECO @// 4 percent percent
.byte 6, 7 @//Level range
.hword POKEMON_KNOFENSA @// 4 percent percent
.byte 8, 8 @//Level range
.hword POKEMON_NIDORANW @// 1 percent percent
.byte 8, 8 @//Level range
.hword POKEMON_NIDORANM @// 1 percent percent


@// Wild data map_15_0_wild_other
.global map_3_7_route2_east_wild_other
.align 4
map_3_7_route2_east_wild_other:
.byte 0x82 @// Frequency in 1/256
.byte 0, 0, 0
.word other_entries

.align 4
other_entries:
.byte 7, 9 @//Level range
.hword POKEMON_TANNZA @// 60 percent percent
.byte 7, 9 @//Level range
.hword POKEMON_SAMURZEL @// 30 percent percent
.byte 7, 9 @//Level range
.hword POKEMON_BUMMELZ @// 5 percent percent
.byte 7, 9 @//Level range
.hword POKEMON_TANNZA @// 4 percent percent
.byte 10, 11 @//Level range
.hword POKEMON_SAMURZEL @// 1 percent percent
