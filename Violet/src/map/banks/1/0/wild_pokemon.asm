.include "species.s"

@// Wild data map_1_0_wild_grass
.global map_1_0_wild_grass
.align 4
map_1_0_wild_grass:
.byte 0x9 @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_0_wild_grass_entries

.align 4
map_1_0_wild_grass_entries:
.byte 16, 20 @//Level range
.hword POKEMON_SAMURZEL @// 20 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_KNILZ @// 20 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_WAUMPEL @// 10 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_MYRAPLA @// 10 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_SAMURZEL @// 10 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_KNILZ @// 10 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_SCHALOKO @// 5 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_KNILZ @// 5 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_PANEKON @// 4 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_PUDOX @// 4 percent percent
.byte 16, 20 @//Level range
.hword POKEMON_BLANAS @// 1 percent percent
.byte 20, 24 @//Level range
.hword POKEMON_TENGULIST @// 1 percent percent

@// Wild data map_1_0_wild_water
.global map_1_0_wild_water
.align 4
map_1_0_wild_water:
.byte 0xa @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_0_wild_water_entries

.align 4
map_1_0_wild_water_entries:
.byte 35, 35 @//Level range
.hword POKEMON_ENTON @// 60 percent percent
.byte 35, 35 @//Level range
.hword POKEMON_GEHWEIHER @// 30 percent percent
.byte 35, 37 @//Level range
.hword POKEMON_GEHWEIHER @// 5 percent percent
.byte 37, 37 @//Level range
.hword POKEMON_ENTORON @// 4 percent percent
.byte 40, 40 @//Level range
.hword POKEMON_ENTORON @// 1 percent percent

@// Wild data map_1_0_wild_other
.global map_1_0_wild_other
.align 4
map_1_0_wild_other:
.byte 0x8a @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_0_wild_other_entries

.align 4
map_1_0_wild_other_entries:
.byte 20, 25 @//Level range
.hword POKEMON_PARAGONI @// 60 percent percent
.byte 20, 25 @//Level range
.hword POKEMON_TANNZA @// 30 percent percent
.byte 20, 25 @//Level range
.hword POKEMON_KASTADUR @// 5 percent percent
.byte 20, 25 @//Level range
.hword POKEMON_PARAGONI @// 4 percent percent
.byte 20, 25 @//Level range
.hword POKEMON_KASTADUR @// 1 percent percent

@// Wild data map_1_0_wild_rod
.global map_1_0_wild_rod
.align 4
map_1_0_wild_rod:
.byte 0x26 @// Frequency in 1/256
.byte 0, 0, 0
.word map_1_0_wild_rod_entries

.align 4
map_1_0_wild_rod_entries:
.byte 14, 14 @//Level range
.hword POKEMON_SCHMERBE @// 70 percent, rod percent
.byte 14, 14 @//Level range
.hword POKEMON_KARPADOR @// 30 percent, rod percent
.byte 36, 36 @//Level range
.hword POKEMON_GARADOS @// 60 percent, profi rod percent
.byte 36, 36 @//Level range
.hword POKEMON_WELSAR @// 20 percent, profi rod percent
.byte 36, 36 @//Level range
.hword POKEMON_WELSAR @// 20 percent, profi rod percent
.byte 48, 48 @//Level range
.hword POKEMON_WELSAR @// 40 percent, super rod percent
.byte 48, 48 @//Level range
.hword POKEMON_WELSAR @// 40 percent, super rod percent
.byte 48, 48 @//Level range
.hword POKEMON_GARADOS @// 15 percent, super rod percent
.byte 55, 55 @//Level range
.hword POKEMON_WELSAR @// 4 percent, super rod percent
.byte 55, 55 @//Level range
.hword POKEMON_WELSAR @// 1 percent, super rod percent

