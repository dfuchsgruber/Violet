.include "std.s"

@// Wild data map_3_5_wild_water
.global map_3_5_wild_water
.align 4
map_3_5_wild_water:
.byte 0x1 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_5_wild_water_entries

.align 4
map_3_5_wild_water_entries:
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

@// Wild data map_3_5_wild_rod
.global map_3_5_wild_rod
.align 4
map_3_5_wild_rod:
.byte 0xa @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_5_wild_rod_entries

.align 4
map_3_5_wild_rod_entries:
.byte 5, 5 @//Level range
.hword POKEMON_KARPADOR @// 70 percent, rod percent
.byte 5, 5 @//Level range
.hword POKEMON_KARPADOR @// 30 percent, rod percent
.byte 5, 15 @//Level range
.hword POKEMON_SEEPER @// 60 percent, profi rod percent
.byte 5, 15 @//Level range
.hword POKEMON_KARPADOR @// 20 percent, profi rod percent
.byte 5, 15 @//Level range
.hword POKEMON_KRABBY @// 20 percent, profi rod percent
.byte 15, 25 @//Level range
.hword POKEMON_SEEPER @// 40 percent, super rod percent
.byte 15, 25 @//Level range
.hword POKEMON_MUSCHAS @// 40 percent, super rod percent
.byte 15, 25 @//Level range
.hword POKEMON_GARADOS @// 15 percent, super rod percent
.byte 25, 35 @//Level range
.hword POKEMON_SEEPER @// 4 percent, super rod percent
.byte 25, 35 @//Level range
.hword POKEMON_ENTON @// 1 percent, super rod percent

