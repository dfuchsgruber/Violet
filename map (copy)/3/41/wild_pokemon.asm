.include "std.s"

@// Wild data map_3_41_wild_grass
.global map_3_41_wild_grass
.align 4
map_3_41_wild_grass:
.byte 0x10 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_41_wild_grass_entries

.align 4
map_3_41_wild_grass_entries:
.byte 5, 7 @//Level range
.hword POKEMON_FRIZELBLIZ @// 20 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_TRASLA @// 20 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_WAUMPEL @// 10 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_TRASLA @// 10 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_KOKUNA @// 10 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_HORNLIU @// 10 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_MENKI @// 5 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_ABRA @// 5 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_MENKI @// 4 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_MENKI @// 4 percent percent
.byte 5, 7 @//Level range
.hword POKEMON_MENKI @// 1 percent percent
.byte 10, 10 @//Level range
.hword POKEMON_BIBOR @// 1 percent percent

@// Wild data map_3_41_wild_water
.global map_3_41_wild_water
.align 4
map_3_41_wild_water:
.byte 0x7 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_41_wild_water_entries

.align 4
map_3_41_wild_water_entries:
.byte 20, 25 @//Level range
.hword POKEMON_TENTACHA @// 60 percent percent
.byte 20, 25 @//Level range
.hword POKEMON_WINGULL @// 30 percent percent
.byte 25, 30 @//Level range
.hword POKEMON_MARILL @// 5 percent percent
.byte 30, 35 @//Level range
.hword POKEMON_MARILL @// 4 percent percent
.byte 35, 40 @//Level range
.hword POKEMON_AZUMARILL @// 1 percent percent

@// Wild data map_3_41_wild_other
.global map_3_41_wild_other
.align 4
map_3_41_wild_other:
.byte 0x97 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_41_wild_other_entries

.align 4
map_3_41_wild_other_entries:
.byte 9, 12 @//Level range
.hword POKEMON_VOLTOBAL @// 60 percent percent
.byte 9, 12 @//Level range
.hword POKEMON_ZIGZACHS @// 30 percent percent
.byte 10, 14 @//Level range
.hword POKEMON_SAMURZEL @// 5 percent percent
.byte 10, 14 @//Level range
.hword POKEMON_SAMURZEL @// 4 percent percent
.byte 10, 15 @//Level range
.hword POKEMON_SAMURZEL @// 1 percent percent

@// Wild data map_3_41_wild_rod
.global map_3_41_wild_rod
.align 4
map_3_41_wild_rod:
.byte 0x31 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_41_wild_rod_entries

.align 4
map_3_41_wild_rod_entries:
.byte 9, 11 @//Level range
.hword POKEMON_KARPADOR @// 70 percent, rod percent
.byte 9, 11 @//Level range
.hword POKEMON_TENTACHA @// 30 percent, rod percent
.byte 1, 1 @//Level range
.hword POKEMON_KARPADOR @// 60 percent, profi rod percent
.byte 1, 1 @//Level range
.hword POKEMON_TENTACHA @// 20 percent, profi rod percent
.byte 1, 1 @//Level range
.hword POKEMON_KARPADOR @// 20 percent, profi rod percent
.byte 1, 1 @//Level range
.hword POKEMON_KARPADOR @// 40 percent, super rod percent
.byte 1, 1 @//Level range
.hword POKEMON_TENTACHA @// 40 percent, super rod percent
.byte 1, 1 @//Level range
.hword POKEMON_KARPADOR @// 15 percent, super rod percent
.byte 1, 1 @//Level range
.hword POKEMON_TENTOXA @// 4 percent, super rod percent
.byte 1, 1 @//Level range
.hword POKEMON_GARADOS @// 1 percent, super rod percent

