.include "species.s"

@// Wild data map_16_3_wild_grass
.global map_16_3_wild_grass
.align 4
map_16_3_wild_grass:
.byte 0x4 @// Frequency in 1/256
.byte 0, 0, 0
.word map_16_3_wild_grass_entries

.align 4
map_16_3_wild_grass_entries:
.byte 21, 24 @//Level range
.hword POKEMON_MACHOLLO @// 20 percent percent
.byte 21, 24 @//Level range
.hword POKEMON_KLEINSTEIN @// 20 percent percent
.byte 21, 24 @//Level range
.hword POKEMON_MENKI @// 10 percent percent
.byte 21, 24 @//Level range
.hword POKEMON_KRABBY @// 10 percent percent
.byte 21, 24 @//Level range
.hword POKEMON_MACHOLLO @// 10 percent percent
.byte 21, 24 @//Level range
.hword POKEMON_KLEINSTEIN @// 10 percent percent
.byte 23, 25 @//Level range
.hword POKEMON_GEOROK @// 5 percent percent
.byte 23, 25 @//Level range
.hword POKEMON_KRABBY @// 5 percent percent
.byte 23, 25 @//Level range
.hword POKEMON_MENKI @// 4 percent percent
.byte 25, 26 @//Level range
.hword POKEMON_MENKI @// 4 percent percent
.byte 27, 27 @//Level range
.hword POKEMON_MASCHOCK @// 1 percent percent
.byte 27, 27 @//Level range
.hword POKEMON_MASCHOCK @// 1 percent percent

@// Wild data map_16_3_wild_rod
.global map_16_3_wild_rod
.align 4
map_16_3_wild_rod:
.byte 0x54 @// Frequency in 1/256
.byte 0, 0, 0
.word map_16_3_wild_rod_entries

.align 4
map_16_3_wild_rod_entries:
.byte 16, 19 @//Level range
.hword POKEMON_KARPADOR @// 70 percent, rod percent
.byte 15, 20 @//Level range
.hword POKEMON_KRABBY @// 30 percent, rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KARPADOR @// 60 percent, profi rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KARPADOR @// 20 percent, profi rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KRABBY @// 20 percent, profi rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KRABBY @// 40 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KARPADOR @// 40 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KRABBY @// 15 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_GARADOS @// 4 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_GARADOS @// 1 percent, super rod percent

