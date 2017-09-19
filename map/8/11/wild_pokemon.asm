.include "std.s"

@// Wild data map_8_11_wild_water
.global map_8_11_wild_water
map_8_11_wild_water:
.byte 0xd @// Frequency in 1/256
.byte 0, 0, 0
.word map_8_11_wild_water_entries

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
map_8_11_wild_rod:
.byte 0xd @// Frequency in 1/256
.byte 0, 0, 0
.word map_8_11_wild_rod_entries

map_8_11_wild_rod_entries:
.byte 26, 32 @//Level range
.hword POKEMON_QUABBEL @// 70 percent, rod percent
.byte 26, 30 @//Level range
.hword POKEMON_TENTACHA @// 30 percent, rod percent
.byte 26, 29 @//Level range
.hword POKEMON_KRABBY @// 60 percent, profi rod percent
.byte 27, 33 @//Level range
.hword POKEMON_KRABBY @// 20 percent, profi rod percent
.byte 30, 34 @//Level range
.hword POKEMON_KRABBY @// 20 percent, profi rod percent
.byte 13, 0 @//Level range
.hword POKEMON_POKEMON_0 @// 40 percent, super rod percent
.byte 92, 181 @//Level range
.hword 0x871 @// 40 percent, super rod percent
.byte 255, 255 @//Level range
.hword 0xffff @// 15 percent, super rod percent
.byte 255, 255 @//Level range
.hword 0xffff @// 4 percent, super rod percent
.byte 255, 255 @//Level range
.hword 0xffff @// 1 percent, super rod percent

