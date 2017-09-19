.include "std.s"

@// Wild data map_3_4_wild_water
.global map_3_4_wild_water
map_3_4_wild_water:
.byte 0xd @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_4_wild_water_entries

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

@// Wild data map_3_4_wild_rod
.global map_3_4_wild_rod
map_3_4_wild_rod:
.byte 0xd @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_4_wild_rod_entries

map_3_4_wild_rod_entries:
.byte 30, 30 @//Level range
.hword POKEMON_MARILL @// 70 percent, rod percent
.byte 30, 30 @//Level range
.hword POKEMON_KANIVANHA @// 30 percent, rod percent
.byte 30, 30 @//Level range
.hword POKEMON_TENTACHA @// 60 percent, profi rod percent
.byte 35, 35 @//Level range
.hword POKEMON_TENTACHA @// 20 percent, profi rod percent
.byte 35, 40 @//Level range
.hword POKEMON_TENTACHA @// 20 percent, profi rod percent
.byte 13, 0 @//Level range
.hword POKEMON_POKEMON_0 @// 40 percent, super rod percent
.byte 232, 150 @//Level range
.hword 0x871 @// 40 percent, super rod percent
.byte 0, 255 @//Level range
.hword 0xffff @// 15 percent, super rod percent
.byte 204, 204 @//Level range
.hword 0xcccc @// 4 percent, super rod percent
.byte 172, 202 @//Level range
.hword 0xcccc @// 1 percent, super rod percent

