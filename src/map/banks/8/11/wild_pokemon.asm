.include "species.s"

@// Wild data map_8_11_wild_water
.global map_8_11_wild_water
.align 4
map_8_11_wild_water:
.byte 0xd @// Frequency in 1/256
.byte 0, 0, 0
.word map_8_11_wild_water_entries

.align 4
map_8_11_wild_water_entries:
.byte 26, 32 @//Level range
.hword POKEMON_QUABBEL @// 60 percent percent
.byte 26, 30 @//Level range
.hword POKEMON_TENTACHA @// 30 percent percent
.byte 26, 29 @//Level range
.hword POKEMON_KRABBY @// 5 percent percent
.byte 27, 33 @//Level range
.hword POKEMON_KRABBY @// 4 percent percent
.byte 30, 34 @//Level range
.hword POKEMON_KRABBY @// 1 percent percent

@// Wild data map_8_11_wild_rod
.global map_8_11_wild_rod
.align 4
map_8_11_wild_rod:
.byte 0x0 @// Frequency in 1/256
.byte 0, 0, 0
.word map_8_11_wild_rod_entries

.align 4
map_8_11_wild_rod_entries:
.byte 21, 24 @//Level range
.hword POKEMON_KARPADOR @// 70 percent, rod percent
.byte 21, 24 @//Level range
.hword POKEMON_QUABBEL @// 30 percent, rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KRABBY @// 60 percent, profi rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KARPADOR @// 20 percent, profi rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KRABBY @// 20 percent, profi rod percent
.byte 0, 0 @//Level range
.hword POKEMON_QUABBEL @// 40 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KRABBY @// 40 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_QUABBEL @// 15 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_KINGLER @// 4 percent, super rod percent
.byte 0, 0 @//Level range
.hword POKEMON_GARADOS @// 1 percent, super rod percent

