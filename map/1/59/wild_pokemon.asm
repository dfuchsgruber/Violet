.include "species.s"

@// Wild data map_1_59_wild_grass
.global map_1_59_wild_grass
.align 4
map_1_59_wild_grass:
.byte 0x7 @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_59_wild_grass_entries

.align 4
map_1_59_wild_grass_entries:
.byte 22, 25 @//Level range
.hword POKEMON_SPOINK @// 20 percent percent
.byte 22, 25 @//Level range
.hword POKEMON_WINGULL @// 20 percent percent
.byte 22, 25 @//Level range
.hword POKEMON_SPOINK @// 10 percent percent
.byte 22, 25 @//Level range
.hword POKEMON_FLABEBE @// 10 percent percent
.byte 22, 25 @//Level range
.hword POKEMON_WINGULL @// 10 percent percent
.byte 22, 25 @//Level range
.hword POKEMON_SPOINK @// 10 percent percent
.byte 22, 25 @//Level range
.hword POKEMON_FLABEBE @// 5 percent percent
.byte 22, 25 @//Level range
.hword POKEMON_WINGULL @// 5 percent percent
.byte 23, 26 @//Level range
.hword POKEMON_SPOINK @// 4 percent percent
.byte 23, 26 @//Level range
.hword POKEMON_FLABEBE @// 4 percent percent
.byte 23, 26 @//Level range
.hword POKEMON_WINGULL @// 1 percent percent
.byte 28, 32 @//Level range
.hword POKEMON_PELIPPER @// 1 percent percent

@// Wild data map_1_59_wild_water
.global map_1_59_wild_water
.align 4
map_1_59_wild_water:
.byte 0x0 @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_59_wild_water_entries

.align 4
map_1_59_wild_water_entries:
.byte 1, 1 @//Level range
.hword POKEMON_POKEMON_0 @// 60 percent percent
.byte 1, 1 @//Level range
.hword POKEMON_POKEMON_0 @// 30 percent percent
.byte 1, 1 @//Level range
.hword POKEMON_POKEMON_0 @// 5 percent percent
.byte 1, 1 @//Level range
.hword POKEMON_POKEMON_0 @// 4 percent percent
.byte 1, 1 @//Level range
.hword POKEMON_POKEMON_0 @// 1 percent percent

@// Wild data map_1_59_wild_rod
.global map_1_59_wild_rod
.align 4
map_1_59_wild_rod:
.byte 0x19 @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_59_wild_rod_entries

.align 4
map_1_59_wild_rod_entries:
.byte 23, 25 @//Level range
.hword POKEMON_QUABBEL @// 70 percent, rod percent
.byte 23, 25 @//Level range
.hword POKEMON_QUABBEL @// 30 percent, rod percent
.byte 23, 25 @//Level range
.hword POKEMON_REMORAID @// 60 percent, profi rod percent
.byte 23, 25 @//Level range
.hword POKEMON_REMORAID @// 20 percent, profi rod percent
.byte 23, 25 @//Level range
.hword POKEMON_KARPADOR @// 20 percent, profi rod percent
.byte 23, 25 @//Level range
.hword POKEMON_KARPADOR @// 40 percent, super rod percent
.byte 1, 1 @//Level range
.hword POKEMON_POKEMON_0 @// 40 percent, super rod percent
.byte 1, 1 @//Level range
.hword POKEMON_POKEMON_0 @// 15 percent, super rod percent
.byte 1, 1 @//Level range
.hword POKEMON_POKEMON_0 @// 4 percent, super rod percent
.byte 1, 1 @//Level range
.hword POKEMON_POKEMON_0 @// 1 percent, super rod percent

