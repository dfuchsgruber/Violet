.include "std.s"

@// Wild data map_3_4_wild_water
.global map_3_4_wild_water
.align 4
map_3_4_wild_water:
.byte 0xd @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_4_wild_water_entries

.align 4
map_3_4_wild_water_entries:
.byte 30, 30 @//Level range
.hword POKEMON_MARILL @// 60 percent percent
.byte 30, 30 @//Level range
.hword POKEMON_KANIVANHA @// 30 percent percent
.byte 30, 30 @//Level range
.hword POKEMON_TENTACHA @// 5 percent percent
.byte 35, 35 @//Level range
.hword POKEMON_TENTACHA @// 4 percent percent
.byte 35, 40 @//Level range
.hword POKEMON_TENTACHA @// 1 percent percent

