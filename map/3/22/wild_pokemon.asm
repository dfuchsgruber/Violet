.include "std.s"

@// Wild data map_3_22_wild_grass
.global map_3_22_wild_grass
.align 4
map_3_22_wild_grass:
.byte 0x15 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_22_wild_grass_entries

.align 4
map_3_22_wild_grass_entries:
.byte 21, 25 @//Level range
.hword POKEMON_WINGULL @// 20 percent percent
.byte 21, 25 @//Level range
.hword POKEMON_MACHOLLO @// 20 percent percent
.byte 21, 25 @//Level range
.hword POKEMON_MEDITIE @// 10 percent percent
.byte 21, 25 @//Level range
.hword POKEMON_LOTURZEL @// 10 percent percent
.byte 21, 25 @//Level range
.hword POKEMON_WINGULL @// 10 percent percent
.byte 21, 25 @//Level range
.hword POKEMON_MACHOLLO @// 10 percent percent
.byte 21, 25 @//Level range
.hword POKEMON_MEDITIE @// 5 percent percent
.byte 22, 25 @//Level range
.hword POKEMON_MEDITIE @// 5 percent percent
.byte 22, 25 @//Level range
.hword POKEMON_LOMBRERO @// 4 percent percent
.byte 22, 26 @//Level range
.hword POKEMON_LOMBRERO @// 4 percent percent
.byte 25, 28 @//Level range
.hword POKEMON_MASCHOCK @// 1 percent percent
.byte 25, 28 @//Level range
.hword POKEMON_MASCHOCK @// 1 percent percent

@// Wild data map_3_22_wild_water
.global map_3_22_wild_water
.align 4
map_3_22_wild_water:
.byte 0x2 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_22_wild_water_entries

.align 4
map_3_22_wild_water_entries:
.byte 5, 10 @//Level range
.hword POKEMON_TENTACHA @// 60 percent percent
.byte 10, 20 @//Level range
.hword POKEMON_TENTACHA @// 30 percent percent
.byte 20, 30 @//Level range
.hword POKEMON_TENTACHA @// 5 percent percent
.byte 30, 35 @//Level range
.hword POKEMON_TENTACHA @// 4 percent percent
.byte 35, 40 @//Level range
.hword POKEMON_TENTACHA @// 1 percent percent

@// Wild data map_3_22_wild_other
.global map_3_22_wild_other
.align 4
map_3_22_wild_other:
.byte 0x9f @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_22_wild_other_entries

.align 4
map_3_22_wild_other_entries:
.byte 23, 26 @//Level range
.hword POKEMON_WINGULL @// 60 percent percent
.byte 21, 26 @//Level range
.hword POKEMON_FELINO @// 30 percent percent
.byte 23, 25 @//Level range
.hword POKEMON_PANDIR @// 5 percent percent
.byte 23, 25 @//Level range
.hword POKEMON_PANDIR @// 4 percent percent
.byte 28, 28 @//Level range
.hword POKEMON_PANDIR @// 1 percent percent

@// Wild data map_3_22_wild_rod
.global map_3_22_wild_rod
.align 4
map_3_22_wild_rod:
.byte 0x2 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_22_wild_rod_entries

.align 4
map_3_22_wild_rod_entries:
.byte 5, 10 @//Level range
.hword POKEMON_TENTACHA @// 70 percent, rod percent
.byte 10, 20 @//Level range
.hword POKEMON_TENTACHA @// 30 percent, rod percent
.byte 20, 30 @//Level range
.hword POKEMON_TENTACHA @// 60 percent, profi rod percent
.byte 30, 35 @//Level range
.hword POKEMON_TENTACHA @// 20 percent, profi rod percent
.byte 35, 40 @//Level range
.hword POKEMON_TENTACHA @// 20 percent, profi rod percent
.byte 2, 0 @//Level range
.hword POKEMON_POKEMON_0 @// 40 percent, super rod percent
.byte 140, 141 @//Level range
.hword 0x83c @// 40 percent, super rod percent
.byte 5, 5 @//Level range
.hword POKEMON_KARPADOR @// 15 percent, super rod percent
.byte 5, 5 @//Level range
.hword POKEMON_KARPADOR @// 4 percent, super rod percent
.byte 5, 15 @//Level range
.hword POKEMON_TENTACHA @// 1 percent, super rod percent

