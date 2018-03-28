.include "std.s"

@// Wild data map_3_19_wild_grass
.global map_3_19_wild_grass
.align 4
map_3_19_wild_grass:
.byte 0x27 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_19_wild_grass_entries

.align 4
map_3_19_wild_grass_entries:
.byte 3, 3 @//Level range
.hword POKEMON_FIFFYEN @// 20 percent percent
.byte 3, 3 @//Level range
.hword POKEMON_DARTIRI @// 20 percent percent
.byte 3, 3 @//Level range
.hword POKEMON_FIFFYEN @// 10 percent percent
.byte 3, 3 @//Level range
.hword POKEMON_ZIGZACHS @// 10 percent percent
.byte 2, 2 @//Level range
.hword POKEMON_STARALILI @// 10 percent percent
.byte 2, 2 @//Level range
.hword POKEMON_STARALILI @// 10 percent percent
.byte 3, 3 @//Level range
.hword POKEMON_STARALILI @// 5 percent percent
.byte 3, 3 @//Level range
.hword POKEMON_FIFFYEN @// 5 percent percent
.byte 3, 3 @//Level range
.hword POKEMON_STARALILI @// 4 percent percent
.byte 4, 4 @//Level range
.hword POKEMON_STARALILI @// 4 percent percent
.byte 5, 5 @//Level range
.hword POKEMON_STARALILI @// 1 percent percent
.byte 4, 4 @//Level range
.hword POKEMON_STARALILI @// 1 percent percent

@// Wild data map_3_19_wild_other
.global map_3_19_wild_other
.align 4
map_3_19_wild_other:
.byte 0x0 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_19_wild_other_entries

.align 4
map_3_19_wild_other_entries:
.byte 8, 10 @//Level range
.hword POKEMON_FUKANO @// 60 percent percent
.byte 7, 11 @//Level range
.hword POKEMON_NIDORANW @// 30 percent percent
.byte 8, 11 @//Level range
.hword POKEMON_NIDORANM @// 5 percent percent
.byte 7, 11 @//Level range
.hword POKEMON_SNUBBULL @// 4 percent percent
.byte 8, 12 @//Level range
.hword POKEMON_SNUBBULL @// 1 percent percent

