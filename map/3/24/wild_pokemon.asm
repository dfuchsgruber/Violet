.include "std.s"

@// Wild data map_3_24_wild_water
.global map_3_24_wild_water
map_3_24_wild_water:
.byte 0x2 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_24_wild_water_entries

map_3_24_wild_water_entries:
.byte 25, 32 @//Level range
.hword POKEMON_ENTON @// 60 percent percent
.byte 25, 32 @//Level range
.hword POKEMON_MARILL @// 30 percent percent
.byte 25, 30 @//Level range
.hword POKEMON_ENTON @// 5 percent percent
.byte 30, 35 @//Level range
.hword POKEMON_ENTON @// 4 percent percent
.byte 35, 40 @//Level range
.hword POKEMON_ENTON @// 1 percent percent

@// Wild data map_3_24_wild_rod
.global map_3_24_wild_rod
map_3_24_wild_rod:
.byte 0x2 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_24_wild_rod_entries

map_3_24_wild_rod_entries:
.byte 25, 32 @//Level range
.hword POKEMON_ENTON @// 70 percent, rod percent
.byte 25, 32 @//Level range
.hword POKEMON_MARILL @// 30 percent, rod percent
.byte 25, 30 @//Level range
.hword POKEMON_ENTON @// 60 percent, profi rod percent
.byte 30, 35 @//Level range
.hword POKEMON_ENTON @// 20 percent, profi rod percent
.byte 35, 40 @//Level range
.hword POKEMON_ENTON @// 20 percent, profi rod percent
.byte 2, 0 @//Level range
.hword POKEMON_POKEMON_0 @// 40 percent, super rod percent
.byte 72, 142 @//Level range
.hword 0x83c @// 40 percent, super rod percent
.byte 5, 5 @//Level range
.hword POKEMON_KARPADOR @// 15 percent, super rod percent
.byte 5, 5 @//Level range
.hword POKEMON_KARPADOR @// 4 percent, super rod percent
.byte 5, 15 @//Level range
.hword POKEMON_GRAMOKLES @// 1 percent, super rod percent

