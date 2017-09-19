.include "std.s"

@// Wild data map_3_74_wild_grass
.global map_3_74_wild_grass
map_3_74_wild_grass:
.byte 0x17 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_74_wild_grass_entries

map_3_74_wild_grass_entries:
.byte 13, 16 @//Level range
.hword POKEMON_PONITA @// 20 percent percent
.byte 13, 16 @//Level range
.hword POKEMON_MAEHIKEL @// 20 percent percent
.byte 13, 16 @//Level range
.hword POKEMON_MYRAPLA @// 10 percent percent
.byte 13, 16 @//Level range
.hword POKEMON_RIHORN @// 10 percent percent
.byte 14, 16 @//Level range
.hword POKEMON_PONITA @// 10 percent percent
.byte 14, 16 @//Level range
.hword POKEMON_MAEHIKEL @// 10 percent percent
.byte 14, 16 @//Level range
.hword POKEMON_PONITA @// 5 percent percent
.byte 14, 16 @//Level range
.hword POKEMON_RIHORN @// 5 percent percent
.byte 15, 17 @//Level range
.hword POKEMON_MAEHIKEL @// 4 percent percent
.byte 15, 17 @//Level range
.hword POKEMON_TAUROS @// 4 percent percent
.byte 15, 17 @//Level range
.hword POKEMON_TAUROS @// 1 percent percent
.byte 18, 18 @//Level range
.hword POKEMON_TAUROS @// 1 percent percent

@// Wild data map_3_74_wild_other
.global map_3_74_wild_other
map_3_74_wild_other:
.byte 0x86 @// Frequency in 1/256
.byte 0, 0, 0
.word map_3_74_wild_other_entries

map_3_74_wild_other_entries:
.byte 13, 17 @//Level range
.hword POKEMON_PONITA @// 60 percent percent
.byte 13, 17 @//Level range
.hword POKEMON_KNACKLION @// 30 percent percent
.byte 13, 17 @//Level range
.hword POKEMON_SKORGLA @// 5 percent percent
.byte 14, 17 @//Level range
.hword POKEMON_SKORGLA @// 4 percent percent
.byte 16, 18 @//Level range
.hword POKEMON_SKORGLA @// 1 percent percent

