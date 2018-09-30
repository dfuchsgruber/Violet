#include "types.h"
#include "pokepad/pokedex/count.h"
#include "pokepad/pokedex/data.h"
#include "language.h"


pokedex_data dex_data[POKEDEX_CNT + 1] = {
	{
		//Entry 0
		LANGDEP(PSTRING("Unbekannt"), PSTRING("Unknown")),
		0, 0,//Height & weight
		str_pokedex_data_0_page_0, str_pokedex_data_0_page_1,
		0,//unused
		256, 0,//Pokemon scale, displacement
		256, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 1
		LANGDEP(PSTRING("Samen"), PSTRING("Seed")),
		7, 69,//Height & weight
		str_pokedex_data_1_page_0, str_pokedex_data_1_page_1,
		0,//unused
		356, 16,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 2
		LANGDEP(PSTRING("Samen"), PSTRING("Seed")),
		10, 130,//Height & weight
		str_pokedex_data_2_page_0, str_pokedex_data_2_page_1,
		0,//unused
		332, 11,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 3
		LANGDEP(PSTRING("Samen"), PSTRING("Seed")),
		20, 1000,//Height & weight
		str_pokedex_data_3_page_0, str_pokedex_data_3_page_1,
		0,//unused
		256, 1,//Pokemon scale, displacement
		375, 6,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 4
		LANGDEP(PSTRING("Echse"), PSTRING("Lizard")),
		6, 85,//Height & weight
		str_pokedex_data_4_page_0, str_pokedex_data_4_page_1,
		0,//unused
		410, 16,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 5
		LANGDEP(PSTRING("Flamme"), PSTRING("Flame")),
		11, 190,//Height & weight
		str_pokedex_data_5_page_0, str_pokedex_data_5_page_1,
		0,//unused
		294, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 6
		LANGDEP(PSTRING("Flamme"), PSTRING("Flame")),
		17, 905,//Height & weight
		str_pokedex_data_6_page_0, str_pokedex_data_6_page_1,
		0,//unused
		271, 0,//Pokemon scale, displacement
		317, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 7
		LANGDEP(PSTRING("Minikröte"), PSTRING("Tiny turtle")),
		5, 90,//Height & weight
		str_pokedex_data_7_page_0, str_pokedex_data_7_page_1,
		0,//unused
		412, 16,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 8
		LANGDEP(PSTRING("Kröte"), PSTRING("Turtle")),
		10, 225,//Height & weight
		str_pokedex_data_8_page_0, str_pokedex_data_8_page_1,
		0,//unused
		334, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 9
		LANGDEP(PSTRING("Panzertier"), PSTRING("Shellfish")),
		16, 855,//Height & weight
		str_pokedex_data_9_page_0, str_pokedex_data_9_page_1,
		0,//unused
		256, 1,//Pokemon scale, displacement
		329, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 13
		LANGDEP(PSTRING("Raupe"), PSTRING("Hairy bug")),
		3, 32,//Height & weight
		str_pokedex_data_13_page_0, str_pokedex_data_13_page_1,
		0,//unused
		455, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 14
		LANGDEP(PSTRING("Kokon"), PSTRING("Cocoon")),
		6, 100,//Height & weight
		str_pokedex_data_14_page_0, str_pokedex_data_14_page_1,
		0,//unused
		424, 14,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 15
		LANGDEP(PSTRING("Giftbiene"), PSTRING("Poison bee")),
		10, 295,//Height & weight
		str_pokedex_data_15_page_0, str_pokedex_data_15_page_1,
		0,//unused
		366, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 25
		LANGDEP(PSTRING("Maus"), PSTRING("Mouse")),
		4, 60,//Height & weight
		str_pokedex_data_25_page_0, str_pokedex_data_25_page_1,
		0,//unused
		479, 16,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 26
		LANGDEP(PSTRING("Maus"), PSTRING("Mouse")),
		8, 300,//Height & weight
		str_pokedex_data_26_page_0, str_pokedex_data_26_page_1,
		0,//unused
		426, 10,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 27
		LANGDEP(PSTRING("Maus"), PSTRING("Mouse")),
		6, 120,//Height & weight
		str_pokedex_data_27_page_0, str_pokedex_data_27_page_1,
		0,//unused
		370, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 28
		LANGDEP(PSTRING("Maus"), PSTRING("Mouse")),
		10, 295,//Height & weight
		str_pokedex_data_28_page_0, str_pokedex_data_28_page_1,
		0,//unused
		341, 10,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 29
		LANGDEP(PSTRING("Giftdorn"), PSTRING("Poison pin")),
		4, 70,//Height & weight
		str_pokedex_data_29_page_0, str_pokedex_data_29_page_1,
		0,//unused
		488, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 30
		LANGDEP(PSTRING("Giftdorn"), PSTRING("Poison pin")),
		8, 200,//Height & weight
		str_pokedex_data_30_page_0, str_pokedex_data_30_page_1,
		0,//unused
		381, 13,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 31
		LANGDEP(PSTRING("Bohrer"), PSTRING("Drill")),
		13, 600,//Height & weight
		str_pokedex_data_31_page_0, str_pokedex_data_31_page_1,
		0,//unused
		283, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 32
		LANGDEP(PSTRING("Giftdorn"), PSTRING("Poison pin")),
		5, 90,//Height & weight
		str_pokedex_data_32_page_0, str_pokedex_data_32_page_1,
		0,//unused
		480, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 33
		LANGDEP(PSTRING("Giftdorn"), PSTRING("Poison pin")),
		9, 195,//Height & weight
		str_pokedex_data_33_page_0, str_pokedex_data_33_page_1,
		0,//unused
		408, 13,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 34
		LANGDEP(PSTRING("Bohrer"), PSTRING("Drill")),
		14, 620,//Height & weight
		str_pokedex_data_34_page_0, str_pokedex_data_34_page_1,
		0,//unused
		304, 3,//Pokemon scale, displacement
		323, 2,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 37
		LANGDEP(PSTRING("Fuchs"), PSTRING("Fox")),
		6, 99,//Height & weight
		str_pokedex_data_37_page_0, str_pokedex_data_37_page_1,
		0,//unused
		497, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 38
		LANGDEP(PSTRING("Fuchs"), PSTRING("Fox")),
		11, 199,//Height & weight
		str_pokedex_data_38_page_0, str_pokedex_data_38_page_1,
		0,//unused
		339, 6,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 213
		LANGDEP(PSTRING("Schimmel"), PSTRING("Mold")),
		6, 205,//Height & weight
		str_pokedex_data_213_page_0, str_pokedex_data_213_page_1,
		0,//unused
		485, 16,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 39
		LANGDEP(PSTRING("Ballon"), PSTRING("Balloon")),
		5, 55,//Height & weight
		str_pokedex_data_39_page_0, str_pokedex_data_39_page_1,
		0,//unused
		419, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 40
		LANGDEP(PSTRING("Ballon"), PSTRING("Balloon")),
		10, 120,//Height & weight
		str_pokedex_data_40_page_0, str_pokedex_data_40_page_1,
		0,//unused
		328, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 41
		LANGDEP(PSTRING("Fledermaus"), PSTRING("Bat")),
		8, 75,//Height & weight
		str_pokedex_data_41_page_0, str_pokedex_data_41_page_1,
		0,//unused
		355, 65532,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 42
		LANGDEP(PSTRING("Fledermaus"), PSTRING("Bat")),
		16, 550,//Height & weight
		str_pokedex_data_42_page_0, str_pokedex_data_42_page_1,
		0,//unused
		291, 0,//Pokemon scale, displacement
		296, 2,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 169
		LANGDEP(PSTRING("Fledermaus"), PSTRING("Bat")),
		18, 750,//Height & weight
		str_pokedex_data_169_page_0, str_pokedex_data_169_page_1,
		0,//unused
		279, 65535,//Pokemon scale, displacement
		313, 2,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 43
		LANGDEP(PSTRING("Unkraut"), PSTRING("Weed")),
		5, 54,//Height & weight
		str_pokedex_data_43_page_0, str_pokedex_data_43_page_1,
		0,//unused
		423, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 44
		LANGDEP(PSTRING("Unkraut"), PSTRING("Weed")),
		8, 86,//Height & weight
		str_pokedex_data_44_page_0, str_pokedex_data_44_page_1,
		0,//unused
		329, 10,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 45
		LANGDEP(PSTRING("Blume"), PSTRING("Flower")),
		12, 186,//Height & weight
		str_pokedex_data_45_page_0, str_pokedex_data_45_page_1,
		0,//unused
		256, 4,//Pokemon scale, displacement
		272, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 182
		LANGDEP(PSTRING("Blume"), PSTRING("Flower")),
		4, 58,//Height & weight
		str_pokedex_data_182_page_0, str_pokedex_data_182_page_1,
		0,//unused
		472, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 48
		LANGDEP(PSTRING("Kleben"), PSTRING("Insect")),
		10, 300,//Height & weight
		str_pokedex_data_48_page_0, str_pokedex_data_48_page_1,
		0,//unused
		360, 14,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 49
		LANGDEP(PSTRING("Donnerspinn"), PSTRING("Poison moth")),
		15, 125,//Height & weight
		str_pokedex_data_49_page_0, str_pokedex_data_49_page_1,
		0,//unused
		256, 3,//Pokemon scale, displacement
		293, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 50
		LANGDEP(PSTRING("Maulwurf"), PSTRING("Mole")),
		2, 8,//Height & weight
		str_pokedex_data_50_page_0, str_pokedex_data_50_page_1,
		0,//unused
		706, 22,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 51
		LANGDEP(PSTRING("Maulwurf"), PSTRING("Mole")),
		7, 333,//Height & weight
		str_pokedex_data_51_page_0, str_pokedex_data_51_page_1,
		0,//unused
		384, 14,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 54
		LANGDEP(PSTRING("Ente"), PSTRING("Duck")),
		8, 196,//Height & weight
		str_pokedex_data_54_page_0, str_pokedex_data_54_page_1,
		0,//unused
		347, 11,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 55
		LANGDEP(PSTRING("Ente"), PSTRING("Duck")),
		17, 766,//Height & weight
		str_pokedex_data_55_page_0, str_pokedex_data_55_page_1,
		0,//unused
		272, 4,//Pokemon scale, displacement
		287, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 56
		LANGDEP(PSTRING("Schw./ affe"), PSTRING("Pig monkey")),
		5, 280,//Height & weight
		str_pokedex_data_56_page_0, str_pokedex_data_56_page_1,
		0,//unused
		388, 16,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 57
		LANGDEP(PSTRING("Schw./ affe"), PSTRING("Pig monkey")),
		10, 320,//Height & weight
		str_pokedex_data_57_page_0, str_pokedex_data_57_page_1,
		0,//unused
		326, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 58
		LANGDEP(PSTRING("Hund"), PSTRING("Puppy")),
		7, 190,//Height & weight
		str_pokedex_data_58_page_0, str_pokedex_data_58_page_1,
		0,//unused
		346, 14,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 59
		LANGDEP(PSTRING("Legendär"), PSTRING("Legendary")),
		19, 1550,//Height & weight
		str_pokedex_data_59_page_0, str_pokedex_data_59_page_1,
		0,//unused
		256, 65535,//Pokemon scale, displacement
		312, 2,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 63
		LANGDEP(PSTRING("Psi"), PSTRING("Psi")),
		9, 195,//Height & weight
		str_pokedex_data_63_page_0, str_pokedex_data_63_page_1,
		0,//unused
		374, 14,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 64
		LANGDEP(PSTRING("Psi"), PSTRING("Psi")),
		13, 565,//Height & weight
		str_pokedex_data_64_page_0, str_pokedex_data_64_page_1,
		0,//unused
		272, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 65
		LANGDEP(PSTRING("Psi"), PSTRING("Psi")),
		15, 480,//Height & weight
		str_pokedex_data_65_page_0, str_pokedex_data_65_page_1,
		0,//unused
		272, 65535,//Pokemon scale, displacement
		271, 65535,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 66
		LANGDEP(PSTRING("Kraftprotz"), PSTRING("Superpower")),
		8, 195,//Height & weight
		str_pokedex_data_66_page_0, str_pokedex_data_66_page_1,
		0,//unused
		320, 12,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 67
		LANGDEP(PSTRING("Kraftprotz"), PSTRING("Superpower")),
		15, 705,//Height & weight
		str_pokedex_data_67_page_0, str_pokedex_data_67_page_1,
		0,//unused
		304, 6,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 68
		LANGDEP(PSTRING("Kraftprotz"), PSTRING("Superpower")),
		16, 1300,//Height & weight
		str_pokedex_data_68_page_0, str_pokedex_data_68_page_1,
		0,//unused
		278, 2,//Pokemon scale, displacement
		283, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 69
		LANGDEP(PSTRING("Blume"), PSTRING("Flower")),
		7, 40,//Height & weight
		str_pokedex_data_69_page_0, str_pokedex_data_69_page_1,
		0,//unused
		354, 16,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 70
		LANGDEP(PSTRING("Fliegentot"), PSTRING("Flycatcher")),
		10, 64,//Height & weight
		str_pokedex_data_70_page_0, str_pokedex_data_70_page_1,
		0,//unused
		256, 65535,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 71
		LANGDEP(PSTRING("Fliegentot"), PSTRING("Flycatcher")),
		17, 155,//Height & weight
		str_pokedex_data_71_page_0, str_pokedex_data_71_page_1,
		0,//unused
		256, 2,//Pokemon scale, displacement
		302, 2,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 72
		LANGDEP(PSTRING("Qualle"), PSTRING("Jellyfish")),
		9, 455,//Height & weight
		str_pokedex_data_72_page_0, str_pokedex_data_72_page_1,
		0,//unused
		256, 0,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 73
		LANGDEP(PSTRING("Qualle"), PSTRING("Jellyfish")),
		16, 550,//Height & weight
		str_pokedex_data_73_page_0, str_pokedex_data_73_page_1,
		0,//unused
		272, 65535,//Pokemon scale, displacement
		312, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 74
		LANGDEP(PSTRING("Gestein"), PSTRING("Rock")),
		4, 200,//Height & weight
		str_pokedex_data_74_page_0, str_pokedex_data_74_page_1,
		0,//unused
		330, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 75
		LANGDEP(PSTRING("Gestein"), PSTRING("Rock")),
		10, 1050,//Height & weight
		str_pokedex_data_75_page_0, str_pokedex_data_75_page_1,
		0,//unused
		272, 8,//Pokemon scale, displacement
		305, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 76
		LANGDEP(PSTRING("Urgestein"), PSTRING("Megaton")),
		14, 3000,//Height & weight
		str_pokedex_data_76_page_0, str_pokedex_data_76_page_1,
		0,//unused
		266, 3,//Pokemon scale, displacement
		298, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 77
		LANGDEP(PSTRING("Feuerpferd"), PSTRING("Fire horse")),
		10, 300,//Height & weight
		str_pokedex_data_77_page_0, str_pokedex_data_77_page_1,
		0,//unused
		288, 7,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 78
		LANGDEP(PSTRING("Feuerpferd"), PSTRING("Fire horse")),
		17, 950,//Height & weight
		str_pokedex_data_78_page_0, str_pokedex_data_78_page_1,
		0,//unused
		282, 65535,//Pokemon scale, displacement
		312, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 79
		LANGDEP(PSTRING("Schnarcher"), PSTRING("Dopey")),
		12, 360,//Height & weight
		str_pokedex_data_79_page_0, str_pokedex_data_79_page_1,
		0,//unused
		271, 10,//Pokemon scale, displacement
		272, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 80
		LANGDEP(PSTRING("Symbiose"), PSTRING("Hermit crab")),
		16, 785,//Height & weight
		str_pokedex_data_80_page_0, str_pokedex_data_80_page_1,
		0,//unused
		257, 65534,//Pokemon scale, displacement
		312, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 199
		LANGDEP(PSTRING("Monarch"), PSTRING("Royal")),
		20, 795,//Height & weight
		str_pokedex_data_199_page_0, str_pokedex_data_199_page_1,
		0,//unused
		265, 65535,//Pokemon scale, displacement
		330, 4,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 81
		LANGDEP(PSTRING("Magnet"), PSTRING("Magnet")),
		3, 60,//Height & weight
		str_pokedex_data_81_page_0, str_pokedex_data_81_page_1,
		0,//unused
		294, 65528,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 82
		LANGDEP(PSTRING("Magnet"), PSTRING("Magnet")),
		10, 600,//Height & weight
		str_pokedex_data_82_page_0, str_pokedex_data_82_page_1,
		0,//unused
		293, 65532,//Pokemon scale, displacement
		273, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 172
		LANGDEP(PSTRING("Magnetgebie"), PSTRING("Tiny mouse")),
		3, 20,//Height & weight
		str_pokedex_data_172_page_0, str_pokedex_data_172_page_1,
		0,//unused
		508, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 83
		LANGDEP(PSTRING("Wildente"), PSTRING("Wild duck")),
		8, 150,//Height & weight
		str_pokedex_data_83_page_0, str_pokedex_data_83_page_1,
		0,//unused
		317, 65534,//Pokemon scale, displacement
		256, 65533,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 84
		LANGDEP(PSTRING("Duovogel"), PSTRING("Twin bird")),
		14, 392,//Height & weight
		str_pokedex_data_84_page_0, str_pokedex_data_84_page_1,
		0,//unused
		256, 3,//Pokemon scale, displacement
		287, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 85
		LANGDEP(PSTRING("Trivogel"), PSTRING("Triple bird")),
		18, 852,//Height & weight
		str_pokedex_data_85_page_0, str_pokedex_data_85_page_1,
		0,//unused
		272, 65534,//Pokemon scale, displacement
		296, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 86
		LANGDEP(PSTRING("Seehund"), PSTRING("Sea lion")),
		11, 900,//Height & weight
		str_pokedex_data_86_page_0, str_pokedex_data_86_page_1,
		0,//unused
		298, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 87
		LANGDEP(PSTRING("Seehund"), PSTRING("Sea lion")),
		17, 1200,//Height & weight
		str_pokedex_data_87_page_0, str_pokedex_data_87_page_1,
		0,//unused
		288, 1,//Pokemon scale, displacement
		306, 65535,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 88
		LANGDEP(PSTRING("Schlamm"), PSTRING("Sludge")),
		9, 300,//Height & weight
		str_pokedex_data_88_page_0, str_pokedex_data_88_page_1,
		0,//unused
		258, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 89
		LANGDEP(PSTRING("Schlamm"), PSTRING("Sludge")),
		12, 300,//Height & weight
		str_pokedex_data_89_page_0, str_pokedex_data_89_page_1,
		0,//unused
		288, 7,//Pokemon scale, displacement
		288, 65535,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 90
		LANGDEP(PSTRING("Muschel"), PSTRING("Bivalve")),
		3, 40,//Height & weight
		str_pokedex_data_90_page_0, str_pokedex_data_90_page_1,
		0,//unused
		643, 21,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 91
		LANGDEP(PSTRING("Muschel"), PSTRING("Bivalve")),
		15, 1325,//Height & weight
		str_pokedex_data_91_page_0, str_pokedex_data_91_page_1,
		0,//unused
		264, 0,//Pokemon scale, displacement
		288, 65535,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 92
		LANGDEP(PSTRING("Gas"), PSTRING("Gas")),
		13, 1,//Height & weight
		str_pokedex_data_92_page_0, str_pokedex_data_92_page_1,
		0,//unused
		256, 0,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 93
		LANGDEP(PSTRING("Gas"), PSTRING("Gas")),
		16, 1,//Height & weight
		str_pokedex_data_93_page_0, str_pokedex_data_93_page_1,
		0,//unused
		269, 2,//Pokemon scale, displacement
		308, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 94
		LANGDEP(PSTRING("Schatten"), PSTRING("Shadow")),
		15, 405,//Height & weight
		str_pokedex_data_94_page_0, str_pokedex_data_94_page_1,
		0,//unused
		256, 4,//Pokemon scale, displacement
		317, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 95
		LANGDEP(PSTRING("Felsnatter"), PSTRING("Rock snake")),
		88, 2100,//Height & weight
		str_pokedex_data_95_page_0, str_pokedex_data_95_page_1,
		0,//unused
		257, 0,//Pokemon scale, displacement
		515, 12,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 208
		LANGDEP(PSTRING("Stahlboa"), PSTRING("Iron snake")),
		92, 4000,//Height & weight
		str_pokedex_data_208_page_0, str_pokedex_data_208_page_1,
		0,//unused
		278, 65535,//Pokemon scale, displacement
		557, 13,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 96
		LANGDEP(PSTRING("Hypnose"), PSTRING("Hypnosis")),
		10, 324,//Height & weight
		str_pokedex_data_96_page_0, str_pokedex_data_96_page_1,
		0,//unused
		274, 7,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 97
		LANGDEP(PSTRING("Hypnose"), PSTRING("Hypnosis")),
		16, 756,//Height & weight
		str_pokedex_data_97_page_0, str_pokedex_data_97_page_1,
		0,//unused
		298, 3,//Pokemon scale, displacement
		310, 2,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 98
		LANGDEP(PSTRING("Krabbe"), PSTRING("River crab")),
		4, 65,//Height & weight
		str_pokedex_data_98_page_0, str_pokedex_data_98_page_1,
		0,//unused
		469, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 99
		LANGDEP(PSTRING("Kneifer"), PSTRING("Pincer")),
		13, 600,//Height & weight
		str_pokedex_data_99_page_0, str_pokedex_data_99_page_1,
		0,//unused
		287, 3,//Pokemon scale, displacement
		308, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 100
		LANGDEP(PSTRING("Ball"), PSTRING("Ball")),
		5, 104,//Height & weight
		str_pokedex_data_100_page_0, str_pokedex_data_100_page_1,
		0,//unused
		364, 65528,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 101
		LANGDEP(PSTRING("Ball"), PSTRING("Ball")),
		12, 666,//Height & weight
		str_pokedex_data_101_page_0, str_pokedex_data_101_page_1,
		0,//unused
		256, 0,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 102
		LANGDEP(PSTRING("Ei"), PSTRING("Egg")),
		4, 25,//Height & weight
		str_pokedex_data_102_page_0, str_pokedex_data_102_page_1,
		0,//unused
		495, 65532,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 103
		LANGDEP(PSTRING("Palmfrucht"), PSTRING("Coconut")),
		20, 1200,//Height & weight
		str_pokedex_data_103_page_0, str_pokedex_data_103_page_1,
		0,//unused
		283, 0,//Pokemon scale, displacement
		376, 7,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 104
		LANGDEP(PSTRING("Einsam"), PSTRING("Lonely")),
		4, 65,//Height & weight
		str_pokedex_data_104_page_0, str_pokedex_data_104_page_1,
		0,//unused
		545, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 105
		LANGDEP(PSTRING("Knochenfan"), PSTRING("Bone keeper")),
		10, 450,//Height & weight
		str_pokedex_data_105_page_0, str_pokedex_data_105_page_1,
		0,//unused
		293, 12,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 236
		LANGDEP(PSTRING("Racker"), PSTRING("Scuffle")),
		7, 210,//Height & weight
		str_pokedex_data_236_page_0, str_pokedex_data_236_page_1,
		0,//unused
		292, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 106
		LANGDEP(PSTRING("Kicker"), PSTRING("Kicking")),
		15, 498,//Height & weight
		str_pokedex_data_106_page_0, str_pokedex_data_106_page_1,
		0,//unused
		256, 0,//Pokemon scale, displacement
		273, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 107
		LANGDEP(PSTRING("Puncher"), PSTRING("Punching")),
		14, 502,//Height & weight
		str_pokedex_data_107_page_0, str_pokedex_data_107_page_1,
		0,//unused
		256, 1,//Pokemon scale, displacement
		264, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 237
		LANGDEP(PSTRING("Kopfstand"), PSTRING("Handstand")),
		14, 480,//Height & weight
		str_pokedex_data_237_page_0, str_pokedex_data_237_page_1,
		0,//unused
		256, 2,//Pokemon scale, displacement
		257, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 108
		LANGDEP(PSTRING("Schlecker"), PSTRING("Licking")),
		12, 655,//Height & weight
		str_pokedex_data_108_page_0, str_pokedex_data_108_page_1,
		0,//unused
		272, 3,//Pokemon scale, displacement
		272, 65533,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 226
		LANGDEP(PSTRING("Flugrochen"), PSTRING("Kite")),
		21, 2200,//Height & weight
		str_pokedex_data_226_page_0, str_pokedex_data_226_page_1,
		0,//unused
		275, 0,//Pokemon scale, displacement
		360, 6,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 109
		LANGDEP(PSTRING("Giftwolke"), PSTRING("Poison gas")),
		6, 10,//Height & weight
		str_pokedex_data_109_page_0, str_pokedex_data_109_page_1,
		0,//unused
		369, 65535,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 110
		LANGDEP(PSTRING("Giftwolke"), PSTRING("Poison gas")),
		12, 95,//Height & weight
		str_pokedex_data_110_page_0, str_pokedex_data_110_page_1,
		0,//unused
		321, 65535,//Pokemon scale, displacement
		276, 65535,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 111
		LANGDEP(PSTRING("Stachler"), PSTRING("Spikes")),
		10, 1150,//Height & weight
		str_pokedex_data_111_page_0, str_pokedex_data_111_page_1,
		0,//unused
		291, 7,//Pokemon scale, displacement
		276, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 112
		LANGDEP(PSTRING("Bohrer"), PSTRING("Drill")),
		19, 1200,//Height & weight
		str_pokedex_data_112_page_0, str_pokedex_data_112_page_1,
		0,//unused
		272, 65535,//Pokemon scale, displacement
		344, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 370
		LANGDEP(PSTRING("Bohrer"), PSTRING("Drill")),
		24, 2828,//Height & weight
		str_pokedex_data_370_page_0, str_pokedex_data_370_page_1,
		0,//unused
		371, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 115
		LANGDEP(PSTRING("Muttertier"), PSTRING("Parent")),
		22, 800,//Height & weight
		str_pokedex_data_115_page_0, str_pokedex_data_115_page_1,
		0,//unused
		257, 65533,//Pokemon scale, displacement
		349, 5,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 116
		LANGDEP(PSTRING("Drache"), PSTRING("Dragon")),
		4, 80,//Height & weight
		str_pokedex_data_116_page_0, str_pokedex_data_116_page_1,
		0,//unused
		399, 65535,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 117
		LANGDEP(PSTRING("Drache"), PSTRING("Dragon")),
		12, 250,//Height & weight
		str_pokedex_data_117_page_0, str_pokedex_data_117_page_1,
		0,//unused
		296, 3,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 230
		LANGDEP(PSTRING("Drache"), PSTRING("Dragon")),
		18, 1520,//Height & weight
		str_pokedex_data_230_page_0, str_pokedex_data_230_page_1,
		0,//unused
		257, 1,//Pokemon scale, displacement
		293, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 313
		LANGDEP(PSTRING("Spielhaus"), PSTRING("Spielhaus")),
		6, 244,//Height & weight
		str_pokedex_data_313_page_0, str_pokedex_data_313_page_1,
		0,//unused
		442, 65532,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 113
		LANGDEP(PSTRING("Ei"), PSTRING("Egg")),
		11, 346,//Height & weight
		str_pokedex_data_113_page_0, str_pokedex_data_113_page_1,
		0,//unused
		257, 6,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 242
		LANGDEP(PSTRING("Freude"), PSTRING("Happiness")),
		15, 468,//Height & weight
		str_pokedex_data_242_page_0, str_pokedex_data_242_page_1,
		0,//unused
		256, 3,//Pokemon scale, displacement
		310, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 120
		LANGDEP(PSTRING("Sternform"), PSTRING("Star shape")),
		8, 345,//Height & weight
		str_pokedex_data_120_page_0, str_pokedex_data_120_page_1,
		0,//unused
		326, 1,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 121
		LANGDEP(PSTRING("Mysteriös"), PSTRING("Mysterious")),
		11, 800,//Height & weight
		str_pokedex_data_121_page_0, str_pokedex_data_121_page_1,
		0,//unused
		301, 3,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 239
		LANGDEP(PSTRING("Elektro"), PSTRING("Electric")),
		6, 235,//Height & weight
		str_pokedex_data_239_page_0, str_pokedex_data_239_page_1,
		0,//unused
		363, 13,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 125
		LANGDEP(PSTRING("Elektro"), PSTRING("Electric")),
		11, 300,//Height & weight
		str_pokedex_data_125_page_0, str_pokedex_data_125_page_1,
		0,//unused
		330, 7,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 206
		LANGDEP(PSTRING("Donnerkeil"), PSTRING("Land snake")),
		15, 140,//Height & weight
		str_pokedex_data_206_page_0, str_pokedex_data_206_page_1,
		0,//unused
		284, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 240
		LANGDEP(PSTRING("Glutherd"), PSTRING("Live coal")),
		7, 214,//Height & weight
		str_pokedex_data_240_page_0, str_pokedex_data_240_page_1,
		0,//unused
		284, 11,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 126
		LANGDEP(PSTRING("Brenner"), PSTRING("Spitfire")),
		13, 445,//Height & weight
		str_pokedex_data_126_page_0, str_pokedex_data_126_page_1,
		0,//unused
		293, 4,//Pokemon scale, displacement
		272, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 324
		LANGDEP(PSTRING("Detonation"), PSTRING("Coal")),
		5, 804,//Height & weight
		str_pokedex_data_324_page_0, str_pokedex_data_324_page_1,
		0,//unused
		392, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 123
		LANGDEP(PSTRING("Mantis"), PSTRING("Mantis")),
		15, 560,//Height & weight
		str_pokedex_data_123_page_0, str_pokedex_data_123_page_1,
		0,//unused
		272, 0,//Pokemon scale, displacement
		293, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 212
		LANGDEP(PSTRING("Kneifer"), PSTRING("Pincer")),
		18, 1180,//Height & weight
		str_pokedex_data_212_page_0, str_pokedex_data_212_page_1,
		0,//unused
		282, 0,//Pokemon scale, displacement
		282, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 127
		LANGDEP(PSTRING("Kneifkäfer"), PSTRING("Stag beetle")),
		15, 550,//Height & weight
		str_pokedex_data_127_page_0, str_pokedex_data_127_page_1,
		0,//unused
		256, 1,//Pokemon scale, displacement
		257, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 128
		LANGDEP(PSTRING("Wildbulle"), PSTRING("Wild bull")),
		14, 884,//Height & weight
		str_pokedex_data_128_page_0, str_pokedex_data_128_page_1,
		0,//unused
		256, 2,//Pokemon scale, displacement
		312, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 129
		LANGDEP(PSTRING("Fisch"), PSTRING("Fish")),
		9, 100,//Height & weight
		str_pokedex_data_129_page_0, str_pokedex_data_129_page_1,
		0,//unused
		317, 4,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 130
		LANGDEP(PSTRING("Grausam"), PSTRING("Atrocious")),
		65, 2350,//Height & weight
		str_pokedex_data_130_page_0, str_pokedex_data_130_page_1,
		0,//unused
		288, 65535,//Pokemon scale, displacement
		512, 11,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 131
		LANGDEP(PSTRING("Transport"), PSTRING("Transport")),
		25, 2200,//Height & weight
		str_pokedex_data_131_page_0, str_pokedex_data_131_page_1,
		0,//unused
		256, 0,//Pokemon scale, displacement
		425, 8,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 132
		LANGDEP(PSTRING("Transform"), PSTRING("Transform")),
		3, 40,//Height & weight
		str_pokedex_data_132_page_0, str_pokedex_data_132_page_1,
		0,//unused
		602, 21,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 133
		LANGDEP(PSTRING("Evolution"), PSTRING("Evolution")),
		3, 65,//Height & weight
		str_pokedex_data_133_page_0, str_pokedex_data_133_page_1,
		0,//unused
		476, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 134
		LANGDEP(PSTRING("Blubblase"), PSTRING("Bubble jet")),
		10, 290,//Height & weight
		str_pokedex_data_134_page_0, str_pokedex_data_134_page_1,
		0,//unused
		316, 7,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 135
		LANGDEP(PSTRING("Blitz"), PSTRING("Lightning")),
		8, 245,//Height & weight
		str_pokedex_data_135_page_0, str_pokedex_data_135_page_1,
		0,//unused
		283, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 136
		LANGDEP(PSTRING("Feuer"), PSTRING("Flame")),
		9, 250,//Height & weight
		str_pokedex_data_136_page_0, str_pokedex_data_136_page_1,
		0,//unused
		302, 11,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 163
		LANGDEP(PSTRING("Neuschnee"), PSTRING("Owl")),
		7, 212,//Height & weight
		str_pokedex_data_163_page_0, str_pokedex_data_163_page_1,
		0,//unused
		380, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 196
		LANGDEP(PSTRING("Sonne"), PSTRING("Sun")),
		9, 265,//Height & weight
		str_pokedex_data_196_page_0, str_pokedex_data_196_page_1,
		0,//unused
		363, 12,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 197
		LANGDEP(PSTRING("Mondschein"), PSTRING("Moonlight")),
		10, 270,//Height & weight
		str_pokedex_data_197_page_0, str_pokedex_data_197_page_1,
		0,//unused
		317, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 46
		LANGDEP(PSTRING("Unreif"), PSTRING("Mushroom")),
		3, 54,//Height & weight
		str_pokedex_data_46_page_0, str_pokedex_data_46_page_1,
		0,//unused
		546, 21,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 47
		LANGDEP(PSTRING("Bindung"), PSTRING("Mushroom")),
		10, 295,//Height & weight
		str_pokedex_data_47_page_0, str_pokedex_data_47_page_1,
		0,//unused
		307, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 137
		LANGDEP(PSTRING("Virtuell"), PSTRING("Virtual")),
		8, 365,//Height & weight
		str_pokedex_data_137_page_0, str_pokedex_data_137_page_1,
		0,//unused
		328, 7,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 233
		LANGDEP(PSTRING("Virtuell"), PSTRING("Virtual")),
		6, 325,//Height & weight
		str_pokedex_data_233_page_0, str_pokedex_data_233_page_1,
		0,//unused
		320, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 315
		LANGDEP(PSTRING("Virtuell"), PSTRING("Thorn")),
		9, 340,//Height & weight
		str_pokedex_data_315_page_0, str_pokedex_data_315_page_1,
		0,//unused
		677, 20,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 222
		LANGDEP(PSTRING("Nimmersatt"), PSTRING("Nimmersatt")),
		6, 1500,//Height & weight
		str_pokedex_data_222_page_0, str_pokedex_data_222_page_1,
		0,//unused
		410, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 143
		LANGDEP(PSTRING("Tagträumer"), PSTRING("Sleeping")),
		21, 4600,//Height & weight
		str_pokedex_data_143_page_0, str_pokedex_data_143_page_1,
		0,//unused
		275, 1,//Pokemon scale, displacement
		408, 7,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 138
		LANGDEP(PSTRING("Spirale"), PSTRING("Spiral")),
		4, 75,//Height & weight
		str_pokedex_data_138_page_0, str_pokedex_data_138_page_1,
		0,//unused
		521, 20,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 139
		LANGDEP(PSTRING("Spirale"), PSTRING("Spiral")),
		10, 350,//Height & weight
		str_pokedex_data_139_page_0, str_pokedex_data_139_page_1,
		0,//unused
		307, 5,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 140
		LANGDEP(PSTRING("Panzertier"), PSTRING("Shellfish")),
		5, 115,//Height & weight
		str_pokedex_data_140_page_0, str_pokedex_data_140_page_1,
		0,//unused
		438, 21,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 141
		LANGDEP(PSTRING("Panzertier"), PSTRING("Shellfish")),
		13, 405,//Height & weight
		str_pokedex_data_141_page_0, str_pokedex_data_141_page_1,
		0,//unused
		271, 1,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 142
		LANGDEP(PSTRING("Fossil"), PSTRING("Fossil")),
		18, 590,//Height & weight
		str_pokedex_data_142_page_0, str_pokedex_data_142_page_1,
		0,//unused
		275, 65535,//Pokemon scale, displacement
		317, 2,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 144
		LANGDEP(PSTRING("Eis"), PSTRING("Freeze")),
		17, 554,//Height & weight
		str_pokedex_data_144_page_0, str_pokedex_data_144_page_1,
		0,//unused
		278, 0,//Pokemon scale, displacement
		308, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 145
		LANGDEP(PSTRING("Elektro"), PSTRING("Electric")),
		16, 526,//Height & weight
		str_pokedex_data_145_page_0, str_pokedex_data_145_page_1,
		0,//unused
		275, 1,//Pokemon scale, displacement
		330, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 146
		LANGDEP(PSTRING("Flamme"), PSTRING("Flame")),
		20, 600,//Height & weight
		str_pokedex_data_146_page_0, str_pokedex_data_146_page_1,
		0,//unused
		270, 1,//Pokemon scale, displacement
		379, 6,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 147
		LANGDEP(PSTRING("Drache"), PSTRING("Dragon")),
		18, 33,//Height & weight
		str_pokedex_data_147_page_0, str_pokedex_data_147_page_1,
		0,//unused
		256, 8,//Pokemon scale, displacement
		386, 6,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 148
		LANGDEP(PSTRING("Drache"), PSTRING("Dragon")),
		40, 165,//Height & weight
		str_pokedex_data_148_page_0, str_pokedex_data_148_page_1,
		0,//unused
		274, 0,//Pokemon scale, displacement
		423, 6,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 149
		LANGDEP(PSTRING("Drache"), PSTRING("Dragon")),
		22, 2100,//Height & weight
		str_pokedex_data_149_page_0, str_pokedex_data_149_page_1,
		0,//unused
		283, 65535,//Pokemon scale, displacement
		342, 4,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 150
		LANGDEP(PSTRING("Genmutant"), PSTRING("Genetic")),
		20, 1220,//Height & weight
		str_pokedex_data_150_page_0, str_pokedex_data_150_page_1,
		0,//unused
		276, 65535,//Pokemon scale, displacement
		342, 5,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 151
		LANGDEP(PSTRING("Neue art"), PSTRING("New species")),
		4, 40,//Height & weight
		str_pokedex_data_151_page_0, str_pokedex_data_151_page_1,
		0,//unused
		460, 65534,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 152
		LANGDEP(PSTRING("Laub"), PSTRING("Leaf")),
		9, 64,//Height & weight
		str_pokedex_data_152_page_0, str_pokedex_data_152_page_1,
		0,//unused
		512, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 153
		LANGDEP(PSTRING("Laub"), PSTRING("Leaf")),
		12, 158,//Height & weight
		str_pokedex_data_153_page_0, str_pokedex_data_153_page_1,
		0,//unused
		296, 4,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 154
		LANGDEP(PSTRING("Kräuter"), PSTRING("Herb")),
		18, 1005,//Height & weight
		str_pokedex_data_154_page_0, str_pokedex_data_154_page_1,
		0,//unused
		286, 0,//Pokemon scale, displacement
		317, 2,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 155
		LANGDEP(PSTRING("Feuermaus"), PSTRING("Fire mouse")),
		5, 79,//Height & weight
		str_pokedex_data_155_page_0, str_pokedex_data_155_page_1,
		0,//unused
		539, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 156
		LANGDEP(PSTRING("Vulkan"), PSTRING("Volcano")),
		9, 190,//Height & weight
		str_pokedex_data_156_page_0, str_pokedex_data_156_page_1,
		0,//unused
		329, 10,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 157
		LANGDEP(PSTRING("Vulkan"), PSTRING("Volcano")),
		17, 795,//Height & weight
		str_pokedex_data_157_page_0, str_pokedex_data_157_page_1,
		0,//unused
		284, 65535,//Pokemon scale, displacement
		287, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 158
		LANGDEP(PSTRING("Grossmaul"), PSTRING("Big jaw")),
		6, 95,//Height & weight
		str_pokedex_data_158_page_0, str_pokedex_data_158_page_1,
		0,//unused
		487, 20,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 159
		LANGDEP(PSTRING("Grossmaul"), PSTRING("Big jaw")),
		11, 250,//Height & weight
		str_pokedex_data_159_page_0, str_pokedex_data_159_page_1,
		0,//unused
		378, 11,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 160
		LANGDEP(PSTRING("Grossmaul"), PSTRING("Big jaw")),
		23, 888,//Height & weight
		str_pokedex_data_160_page_0, str_pokedex_data_160_page_1,
		0,//unused
		282, 65535,//Pokemon scale, displacement
		375, 6,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 174
		LANGDEP(PSTRING("Einblütler"), PSTRING("Balloon")),
		3, 10,//Height & weight
		str_pokedex_data_174_page_0, str_pokedex_data_174_page_1,
		0,//unused
		457, 65535,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 35
		LANGDEP(PSTRING("Einblütler"), PSTRING("Fairy")),
		6, 75,//Height & weight
		str_pokedex_data_35_page_0, str_pokedex_data_35_page_1,
		0,//unused
		425, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 36
		LANGDEP(PSTRING("Garten"), PSTRING("Fairy")),
		13, 400,//Height & weight
		str_pokedex_data_36_page_0, str_pokedex_data_36_page_1,
		0,//unused
		256, 3,//Pokemon scale, displacement
		272, 65535,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 16
		LANGDEP(PSTRING("Star"), PSTRING("Tiny bird")),
		3, 18,//Height & weight
		str_pokedex_data_16_page_0, str_pokedex_data_16_page_1,
		0,//unused
		492, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 17
		LANGDEP(PSTRING("Star"), PSTRING("Bird")),
		11, 300,//Height & weight
		str_pokedex_data_17_page_0, str_pokedex_data_17_page_1,
		0,//unused
		334, 11,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 18
		LANGDEP(PSTRING("Star"), PSTRING("Bird")),
		15, 395,//Height & weight
		str_pokedex_data_18_page_0, str_pokedex_data_18_page_1,
		0,//unused
		269, 65534,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 10
		LANGDEP(PSTRING("Rotkehlchen"), PSTRING("Worm")),
		3, 29,//Height & weight
		str_pokedex_data_10_page_0, str_pokedex_data_10_page_1,
		0,//unused
		549, 20,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 11
		LANGDEP(PSTRING("Funkenregen"), PSTRING("Cocoon")),
		7, 160,//Height & weight
		str_pokedex_data_11_page_0, str_pokedex_data_11_page_1,
		0,//unused
		350, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 12
		LANGDEP(PSTRING("Stichflamme"), PSTRING("Butterfly")),
		12, 320,//Height & weight
		str_pokedex_data_12_page_0, str_pokedex_data_12_page_1,
		0,//unused
		312, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 165
		LANGDEP(PSTRING("Fünf-punkt"), PSTRING("Five star")),
		10, 108,//Height & weight
		str_pokedex_data_165_page_0, str_pokedex_data_165_page_1,
		0,//unused
		256, 4,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 166
		LANGDEP(PSTRING("Fünf-punkt"), PSTRING("Five star")),
		14, 356,//Height & weight
		str_pokedex_data_166_page_0, str_pokedex_data_166_page_1,
		0,//unused
		256, 1,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 167
		LANGDEP(PSTRING("Fadenwurf"), PSTRING("String spit")),
		5, 85,//Height & weight
		str_pokedex_data_167_page_0, str_pokedex_data_167_page_1,
		0,//unused
		414, 20,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 168
		LANGDEP(PSTRING("Langbein"), PSTRING("Long leg")),
		11, 335,//Height & weight
		str_pokedex_data_168_page_0, str_pokedex_data_168_page_1,
		0,//unused
		316, 7,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 175
		LANGDEP(PSTRING("Zackenball"), PSTRING("Spike ball")),
		3, 15,//Height & weight
		str_pokedex_data_175_page_0, str_pokedex_data_175_page_1,
		0,//unused
		507, 21,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 176
		LANGDEP(PSTRING("Freude"), PSTRING("Happiness")),
		6, 32,//Height & weight
		str_pokedex_data_176_page_0, str_pokedex_data_176_page_1,
		0,//unused
		424, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 173
		LANGDEP(PSTRING("Jubilierer"), PSTRING("Star shape")),
		3, 30,//Height & weight
		str_pokedex_data_173_page_0, str_pokedex_data_173_page_1,
		0,//unused
		462, 22,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 177
		LANGDEP(PSTRING("Kleinvogel"), PSTRING("Tiny bird")),
		2, 20,//Height & weight
		str_pokedex_data_177_page_0, str_pokedex_data_177_page_1,
		0,//unused
		610, 23,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 178
		LANGDEP(PSTRING("Mystik"), PSTRING("Mystic")),
		15, 150,//Height & weight
		str_pokedex_data_178_page_0, str_pokedex_data_178_page_1,
		0,//unused
		258, 4,//Pokemon scale, displacement
		317, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 179
		LANGDEP(PSTRING("Wolle"), PSTRING("Wool")),
		6, 78,//Height & weight
		str_pokedex_data_179_page_0, str_pokedex_data_179_page_1,
		0,//unused
		379, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 180
		LANGDEP(PSTRING("Wolle"), PSTRING("Wool")),
		8, 133,//Height & weight
		str_pokedex_data_180_page_0, str_pokedex_data_180_page_1,
		0,//unused
		372, 13,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 181
		LANGDEP(PSTRING("Leuchte"), PSTRING("Light")),
		14, 615,//Height & weight
		str_pokedex_data_181_page_0, str_pokedex_data_181_page_1,
		0,//unused
		275, 2,//Pokemon scale, displacement
		283, 65535,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 21
		LANGDEP(PSTRING("Ritt"), PSTRING("Tiny bird")),
		3, 20,//Height & weight
		str_pokedex_data_21_page_0, str_pokedex_data_21_page_1,
		0,//unused
		571, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 22
		LANGDEP(PSTRING("Ritt"), PSTRING("Beak")),
		12, 380,//Height & weight
		str_pokedex_data_22_page_0, str_pokedex_data_22_page_1,
		0,//unused
		282, 65535,//Pokemon scale, displacement
		272, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 60
		LANGDEP(PSTRING("Schwert"), PSTRING("Tadpole")),
		6, 124,//Height & weight
		str_pokedex_data_60_page_0, str_pokedex_data_60_page_1,
		0,//unused
		353, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 61
		LANGDEP(PSTRING("Schwerter"), PSTRING("Tadpole")),
		10, 200,//Height & weight
		str_pokedex_data_61_page_0, str_pokedex_data_61_page_1,
		0,//unused
		288, 10,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 62
		LANGDEP(PSTRING("Königstich"), PSTRING("Tadpole")),
		13, 540,//Height & weight
		str_pokedex_data_62_page_0, str_pokedex_data_62_page_1,
		0,//unused
		256, 5,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 186
		LANGDEP(PSTRING("Schlüssel"), PSTRING("Frog")),
		11, 339,//Height & weight
		str_pokedex_data_186_page_0, str_pokedex_data_186_page_1,
		0,//unused
		289, 5,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 187
		LANGDEP(PSTRING("Kerze"), PSTRING("Cottonweed")),
		4, 5,//Height & weight
		str_pokedex_data_187_page_0, str_pokedex_data_187_page_1,
		0,//unused
		562, 65529,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 188
		LANGDEP(PSTRING("Lampe"), PSTRING("Cottonweed")),
		6, 10,//Height & weight
		str_pokedex_data_188_page_0, str_pokedex_data_188_page_1,
		0,//unused
		387, 0,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 189
		LANGDEP(PSTRING("Geleit"), PSTRING("Cottonweed")),
		8, 30,//Height & weight
		str_pokedex_data_189_page_0, str_pokedex_data_189_page_1,
		0,//unused
		418, 65532,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 190
		LANGDEP(PSTRING("Langschweif"), PSTRING("Long tail")),
		8, 115,//Height & weight
		str_pokedex_data_190_page_0, str_pokedex_data_190_page_1,
		0,//unused
		363, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 193
		LANGDEP(PSTRING("Libelle"), PSTRING("Clear wing")),
		12, 380,//Height & weight
		str_pokedex_data_193_page_0, str_pokedex_data_193_page_1,
		0,//unused
		274, 65532,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 191
		LANGDEP(PSTRING("Frostbaum"), PSTRING("Seed")),
		3, 18,//Height & weight
		str_pokedex_data_191_page_0, str_pokedex_data_191_page_1,
		0,//unused
		541, 0,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 192
		LANGDEP(PSTRING("Frostbaum"), PSTRING("Sun")),
		8, 85,//Height & weight
		str_pokedex_data_192_page_0, str_pokedex_data_192_page_1,
		0,//unused
		374, 12,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 298
		LANGDEP(PSTRING("Gepunktet"), PSTRING("Polka dot")),
		2, 20,//Height & weight
		str_pokedex_data_298_page_0, str_pokedex_data_298_page_1,
		0,//unused
		603, 21,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 183
		LANGDEP(PSTRING("Aquamaus"), PSTRING("Aqua mouse")),
		4, 85,//Height & weight
		str_pokedex_data_183_page_0, str_pokedex_data_183_page_1,
		0,//unused
		476, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 184
		LANGDEP(PSTRING("Aquahase"), PSTRING("Aqua rabbit")),
		8, 285,//Height & weight
		str_pokedex_data_184_page_0, str_pokedex_data_184_page_1,
		0,//unused
		448, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 194
		LANGDEP(PSTRING("Fisch"), PSTRING("Water fish")),
		4, 85,//Height & weight
		str_pokedex_data_194_page_0, str_pokedex_data_194_page_1,
		0,//unused
		479, 20,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 195
		LANGDEP(PSTRING("Fisch"), PSTRING("Water fish")),
		14, 750,//Height & weight
		str_pokedex_data_195_page_0, str_pokedex_data_195_page_1,
		0,//unused
		273, 4,//Pokemon scale, displacement
		273, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 198
		LANGDEP(PSTRING("Finsternis"), PSTRING("Darkness")),
		5, 21,//Height & weight
		str_pokedex_data_198_page_0, str_pokedex_data_198_page_1,
		0,//unused
		401, 65528,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 200
		LANGDEP(PSTRING("Kreischer"), PSTRING("Screech")),
		7, 10,//Height & weight
		str_pokedex_data_200_page_0, str_pokedex_data_200_page_1,
		0,//unused
		407, 65528,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 201
		LANGDEP(PSTRING("Symbol"), PSTRING("Symbol")),
		5, 50,//Height & weight
		str_pokedex_data_201_page_0, str_pokedex_data_201_page_1,
		0,//unused
		411, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 314
		LANGDEP(PSTRING("Bonsai"), PSTRING("Bonsai")),
		5, 150,//Height & weight
		str_pokedex_data_314_page_0, str_pokedex_data_314_page_1,
		0,//unused
		572, 65532,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 185
		LANGDEP(PSTRING("Imitation"), PSTRING("Imitation")),
		12, 380,//Height & weight
		str_pokedex_data_185_page_0, str_pokedex_data_185_page_1,
		0,//unused
		305, 7,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 204
		LANGDEP(PSTRING("Beutelwurm"), PSTRING("Bagworm")),
		6, 72,//Height & weight
		str_pokedex_data_204_page_0, str_pokedex_data_204_page_1,
		0,//unused
		445, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 205
		LANGDEP(PSTRING("Beutelwurm"), PSTRING("Bagworm")),
		12, 1258,//Height & weight
		str_pokedex_data_205_page_0, str_pokedex_data_205_page_1,
		0,//unused
		293, 5,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 207
		LANGDEP(PSTRING("Flugskorpi"), PSTRING("Flyscorpion")),
		11, 648,//Height & weight
		str_pokedex_data_207_page_0, str_pokedex_data_207_page_1,
		0,//unused
		350, 65535,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 203
		LANGDEP(PSTRING("Langhals"), PSTRING("Long neck")),
		15, 415,//Height & weight
		str_pokedex_data_203_page_0, str_pokedex_data_203_page_1,
		0,//unused
		281, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 209
		LANGDEP(PSTRING("Fee"), PSTRING("Fairy")),
		6, 78,//Height & weight
		str_pokedex_data_209_page_0, str_pokedex_data_209_page_1,
		0,//unused
		465, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 210
		LANGDEP(PSTRING("Fee"), PSTRING("Fairy")),
		14, 487,//Height & weight
		str_pokedex_data_210_page_0, str_pokedex_data_210_page_1,
		0,//unused
		256, 3,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 214
		LANGDEP(PSTRING("Einzelhorn"), PSTRING("Single horn")),
		15, 540,//Height & weight
		str_pokedex_data_214_page_0, str_pokedex_data_214_page_1,
		0,//unused
		285, 0,//Pokemon scale, displacement
		283, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 216
		LANGDEP(PSTRING("Kleinbär"), PSTRING("Little bear")),
		6, 88,//Height & weight
		str_pokedex_data_216_page_0, str_pokedex_data_216_page_1,
		0,//unused
		455, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 217
		LANGDEP(PSTRING("Schläfer"), PSTRING("Hibernator")),
		18, 1258,//Height & weight
		str_pokedex_data_217_page_0, str_pokedex_data_217_page_1,
		0,//unused
		275, 0,//Pokemon scale, displacement
		280, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 218
		LANGDEP(PSTRING("Lava"), PSTRING("Lava")),
		7, 350,//Height & weight
		str_pokedex_data_218_page_0, str_pokedex_data_218_page_1,
		0,//unused
		329, 14,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 219
		LANGDEP(PSTRING("Lava"), PSTRING("Lava")),
		8, 550,//Height & weight
		str_pokedex_data_219_page_0, str_pokedex_data_219_page_1,
		0,//unused
		332, 14,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 220
		LANGDEP(PSTRING("Ferkel"), PSTRING("Pig")),
		4, 65,//Height & weight
		str_pokedex_data_220_page_0, str_pokedex_data_220_page_1,
		0,//unused
		324, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 221
		LANGDEP(PSTRING("Schwein"), PSTRING("Swine")),
		11, 558,//Height & weight
		str_pokedex_data_221_page_0, str_pokedex_data_221_page_1,
		0,//unused
		306, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 211
		LANGDEP(PSTRING("Doppelzahn"), PSTRING("Balloon")),
		18, 1004,//Height & weight
		str_pokedex_data_211_page_0, str_pokedex_data_211_page_1,
		0,//unused
		777, 0,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 223
		LANGDEP(PSTRING("Hochdruck"), PSTRING("Jet")),
		6, 120,//Height & weight
		str_pokedex_data_223_page_0, str_pokedex_data_223_page_1,
		0,//unused
		316, 4,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 224
		LANGDEP(PSTRING("Hochdruck"), PSTRING("Jet")),
		9, 285,//Height & weight
		str_pokedex_data_224_page_0, str_pokedex_data_224_page_1,
		0,//unused
		296, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 164
		LANGDEP(PSTRING("Wrestling"), PSTRING("Owl")),
		16, 408,//Height & weight
		str_pokedex_data_164_page_0, str_pokedex_data_164_page_1,
		0,//unused
		278, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 238
		LANGDEP(PSTRING("Gelassen"), PSTRING("Gelassen")),
		30, 1850,//Height & weight
		str_pokedex_data_238_page_0, str_pokedex_data_238_page_1,
		0,//unused
		440, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 215
		LANGDEP(PSTRING("Verboten"), PSTRING("Sharp claw")),
		9, 280,//Height & weight
		str_pokedex_data_215_page_0, str_pokedex_data_215_page_1,
		0,//unused
		413, 65533,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 225
		LANGDEP(PSTRING("Lieferant"), PSTRING("Delivery")),
		9, 160,//Height & weight
		str_pokedex_data_225_page_0, str_pokedex_data_225_page_1,
		0,//unused
		293, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 227
		LANGDEP(PSTRING("Flugstahl"), PSTRING("Armor bird")),
		17, 505,//Height & weight
		str_pokedex_data_227_page_0, str_pokedex_data_227_page_1,
		0,//unused
		285, 0,//Pokemon scale, displacement
		276, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 228
		LANGDEP(PSTRING("Hades"), PSTRING("Dark")),
		6, 108,//Height & weight
		str_pokedex_data_228_page_0, str_pokedex_data_228_page_1,
		0,//unused
		393, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 229
		LANGDEP(PSTRING("Hades"), PSTRING("Dark")),
		14, 350,//Height & weight
		str_pokedex_data_229_page_0, str_pokedex_data_229_page_1,
		0,//unused
		256, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 231
		LANGDEP(PSTRING("Langrüssel"), PSTRING("Long nose")),
		5, 335,//Height & weight
		str_pokedex_data_231_page_0, str_pokedex_data_231_page_1,
		0,//unused
		465, 20,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 232
		LANGDEP(PSTRING("Panzertier"), PSTRING("Armor")),
		11, 1200,//Height & weight
		str_pokedex_data_232_page_0, str_pokedex_data_232_page_1,
		0,//unused
		313, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 170
		LANGDEP(PSTRING("Angler"), PSTRING("Angler")),
		5, 120,//Height & weight
		str_pokedex_data_170_page_0, str_pokedex_data_170_page_1,
		0,//unused
		424, 65534,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 171
		LANGDEP(PSTRING("Leuchte"), PSTRING("Light")),
		12, 225,//Height & weight
		str_pokedex_data_171_page_0, str_pokedex_data_171_page_1,
		0,//unused
		269, 6,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 23
		LANGDEP(PSTRING("Baumstumpf"), PSTRING("Snake")),
		20, 69,//Height & weight
		str_pokedex_data_23_page_0, str_pokedex_data_23_page_1,
		0,//unused
		298, 13,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 24
		LANGDEP(PSTRING("Urgehölz"), PSTRING("Cobra")),
		35, 650,//Height & weight
		str_pokedex_data_24_page_0, str_pokedex_data_24_page_1,
		0,//unused
		256, 0,//Pokemon scale, displacement
		296, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 122
		LANGDEP(PSTRING("Kreischer"), PSTRING("Barrier")),
		7, 10,//Height & weight
		str_pokedex_data_122_page_0, str_pokedex_data_122_page_1,
		0,//unused
		407, 65528,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 235
		LANGDEP(PSTRING("Ritterlich"), PSTRING("Painter")),
		12, 580,//Height & weight
		str_pokedex_data_235_page_0, str_pokedex_data_235_page_1,
		0,//unused
		287, 5,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 118
		LANGDEP(PSTRING("Gleit"), PSTRING("Goldfish")),
		6, 150,//Height & weight
		str_pokedex_data_118_page_0, str_pokedex_data_118_page_1,
		0,//unused
		379, 4,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 119
		LANGDEP(PSTRING("Gleit"), PSTRING("Goldfish")),
		13, 390,//Height & weight
		str_pokedex_data_119_page_0, str_pokedex_data_119_page_1,
		0,//unused
		304, 1,//Pokemon scale, displacement
		288, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 241
		LANGDEP(PSTRING("Milchkuh"), PSTRING("Milk cow")),
		12, 755,//Height & weight
		str_pokedex_data_241_page_0, str_pokedex_data_241_page_1,
		0,//unused
		280, 3,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 293
		LANGDEP(PSTRING("Landhai"), PSTRING("Whisper")),
		6, 163,//Height & weight
		str_pokedex_data_293_page_0, str_pokedex_data_293_page_1,
		0,//unused
		373, 16,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 294
		LANGDEP(PSTRING("Höhle"), PSTRING("Big voice")),
		10, 405,//Height & weight
		str_pokedex_data_294_page_0, str_pokedex_data_294_page_1,
		0,//unused
		356, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 295
		LANGDEP(PSTRING("Rasanz"), PSTRING("Loud noise")),
		21, 840,//Height & weight
		str_pokedex_data_295_page_0, str_pokedex_data_295_page_1,
		0,//unused
		284, 1,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 161
		LANGDEP(PSTRING("Fackel"), PSTRING("Scout")),
		8, 60,//Height & weight
		str_pokedex_data_161_page_0, str_pokedex_data_161_page_1,
		0,//unused
		439, 12,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 162
		LANGDEP(PSTRING("Sonne"), PSTRING("Long body")),
		18, 325,//Height & weight
		str_pokedex_data_162_page_0, str_pokedex_data_162_page_1,
		0,//unused
		346, 10,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 243
		LANGDEP(PSTRING("Donner"), PSTRING("Thunder")),
		19, 1780,//Height & weight
		str_pokedex_data_243_page_0, str_pokedex_data_243_page_1,
		0,//unused
		283, 0,//Pokemon scale, displacement
		359, 6,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 244
		LANGDEP(PSTRING("Vulkan"), PSTRING("Volcano")),
		21, 1980,//Height & weight
		str_pokedex_data_244_page_0, str_pokedex_data_244_page_1,
		0,//unused
		283, 0,//Pokemon scale, displacement
		370, 7,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 245
		LANGDEP(PSTRING("Polarlicht"), PSTRING("Aurora")),
		20, 1870,//Height & weight
		str_pokedex_data_245_page_0, str_pokedex_data_245_page_1,
		0,//unused
		286, 0,//Pokemon scale, displacement
		371, 7,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 246
		LANGDEP(PSTRING("Felshaut"), PSTRING("Rock skin")),
		6, 720,//Height & weight
		str_pokedex_data_246_page_0, str_pokedex_data_246_page_1,
		0,//unused
		472, 16,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 247
		LANGDEP(PSTRING("Hartschale"), PSTRING("Hard shell")),
		12, 1520,//Height & weight
		str_pokedex_data_247_page_0, str_pokedex_data_247_page_1,
		0,//unused
		292, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 248
		LANGDEP(PSTRING("Panzertier"), PSTRING("Armor")),
		20, 2020,//Height & weight
		str_pokedex_data_248_page_0, str_pokedex_data_248_page_1,
		0,//unused
		285, 0,//Pokemon scale, displacement
		383, 7,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 249
		LANGDEP(PSTRING("Taucher"), PSTRING("Diving")),
		52, 2160,//Height & weight
		str_pokedex_data_249_page_0, str_pokedex_data_249_page_1,
		0,//unused
		283, 0,//Pokemon scale, displacement
		742, 18,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 250
		LANGDEP(PSTRING("Regenbogen"), PSTRING("Rainbow")),
		38, 1990,//Height & weight
		str_pokedex_data_250_page_0, str_pokedex_data_250_page_1,
		0,//unused
		283, 0,//Pokemon scale, displacement
		620, 16,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 251
		LANGDEP(PSTRING("Zeitreise"), PSTRING("Time travel")),
		6, 50,//Height & weight
		str_pokedex_data_251_page_0, str_pokedex_data_251_page_1,
		0,//unused
		393, 65526,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 252
		LANGDEP(PSTRING("Locke"), PSTRING("Wood gecko")),
		5, 50,//Height & weight
		str_pokedex_data_252_page_0, str_pokedex_data_252_page_1,
		0,//unused
		541, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 253
		LANGDEP(PSTRING("Schwert"), PSTRING("Wood gecko")),
		9, 216,//Height & weight
		str_pokedex_data_253_page_0, str_pokedex_data_253_page_1,
		0,//unused
		360, 5,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 254
		LANGDEP(PSTRING("Ritter"), PSTRING("Forest")),
		17, 522,//Height & weight
		str_pokedex_data_254_page_0, str_pokedex_data_254_page_1,
		0,//unused
		282, 65535,//Pokemon scale, displacement
		313, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 255
		LANGDEP(PSTRING("Welpe"), PSTRING("Chick")),
		4, 25,//Height & weight
		str_pokedex_data_255_page_0, str_pokedex_data_255_page_1,
		0,//unused
		566, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 256
		LANGDEP(PSTRING("Orthos"), PSTRING("Young fowl")),
		9, 195,//Height & weight
		str_pokedex_data_256_page_0, str_pokedex_data_256_page_1,
		0,//unused
		343, 5,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 257
		LANGDEP(PSTRING("Zerberus"), PSTRING("Blaze")),
		19, 520,//Height & weight
		str_pokedex_data_257_page_0, str_pokedex_data_257_page_1,
		0,//unused
		275, 65535,//Pokemon scale, displacement
		314, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 258
		LANGDEP(PSTRING("Wassermolch"), PSTRING("Mud fish")),
		4, 76,//Height & weight
		str_pokedex_data_258_page_0, str_pokedex_data_258_page_1,
		0,//unused
		535, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 259
		LANGDEP(PSTRING("Delphin"), PSTRING("Mud fish")),
		7, 280,//Height & weight
		str_pokedex_data_259_page_0, str_pokedex_data_259_page_1,
		0,//unused
		340, 7,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 260
		LANGDEP(PSTRING("Seeschlange"), PSTRING("Mud fish")),
		15, 819,//Height & weight
		str_pokedex_data_260_page_0, str_pokedex_data_260_page_1,
		0,//unused
		276, 65535,//Pokemon scale, displacement
		282, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 261
		LANGDEP(PSTRING("Biss"), PSTRING("Bite")),
		5, 136,//Height & weight
		str_pokedex_data_261_page_0, str_pokedex_data_261_page_1,
		0,//unused
		481, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 262
		LANGDEP(PSTRING("Biss"), PSTRING("Bite")),
		10, 370,//Height & weight
		str_pokedex_data_262_page_0, str_pokedex_data_262_page_1,
		0,//unused
		359, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 263
		LANGDEP(PSTRING("Kleindachs"), PSTRING("Tinyraccoon")),
		4, 175,//Height & weight
		str_pokedex_data_263_page_0, str_pokedex_data_263_page_1,
		0,//unused
		560, 21,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 264
		LANGDEP(PSTRING("Sprinter"), PSTRING("Rushing")),
		5, 325,//Height & weight
		str_pokedex_data_264_page_0, str_pokedex_data_264_page_1,
		0,//unused
		321, 5,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 265
		LANGDEP(PSTRING("Wurm"), PSTRING("Worm")),
		3, 36,//Height & weight
		str_pokedex_data_265_page_0, str_pokedex_data_265_page_1,
		0,//unused
		711, 22,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 266
		LANGDEP(PSTRING("Kokon"), PSTRING("Cocoon")),
		6, 100,//Height & weight
		str_pokedex_data_266_page_0, str_pokedex_data_266_page_1,
		0,//unused
		431, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 267
		LANGDEP(PSTRING("Falter"), PSTRING("Butterfly")),
		10, 284,//Height & weight
		str_pokedex_data_267_page_0, str_pokedex_data_267_page_1,
		0,//unused
		298, 65535,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 268
		LANGDEP(PSTRING("Kokon"), PSTRING("Cocoon")),
		7, 115,//Height & weight
		str_pokedex_data_268_page_0, str_pokedex_data_268_page_1,
		0,//unused
		391, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 269
		LANGDEP(PSTRING("Giftmotte"), PSTRING("Poison moth")),
		12, 316,//Height & weight
		str_pokedex_data_269_page_0, str_pokedex_data_269_page_1,
		0,//unused
		269, 1,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 270
		LANGDEP(PSTRING("Wasserlinse"), PSTRING("Water weed")),
		5, 26,//Height & weight
		str_pokedex_data_270_page_0, str_pokedex_data_270_page_1,
		0,//unused
		406, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 271
		LANGDEP(PSTRING("Frohmut"), PSTRING("Jolly")),
		12, 325,//Height & weight
		str_pokedex_data_271_page_0, str_pokedex_data_271_page_1,
		0,//unused
		277, 7,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 272
		LANGDEP(PSTRING("Sorglos"), PSTRING("Carefree")),
		15, 550,//Height & weight
		str_pokedex_data_272_page_0, str_pokedex_data_272_page_1,
		0,//unused
		283, 0,//Pokemon scale, displacement
		282, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 273
		LANGDEP(PSTRING("Eichelnuss"), PSTRING("Acorn")),
		5, 40,//Height & weight
		str_pokedex_data_273_page_0, str_pokedex_data_273_page_1,
		0,//unused
		472, 20,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 274
		LANGDEP(PSTRING("Hinterlist"), PSTRING("Wily")),
		10, 280,//Height & weight
		str_pokedex_data_274_page_0, str_pokedex_data_274_page_1,
		0,//unused
		299, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 275
		LANGDEP(PSTRING("Verschlagen"), PSTRING("Wicked")),
		13, 596,//Height & weight
		str_pokedex_data_275_page_0, str_pokedex_data_275_page_1,
		0,//unused
		290, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 290
		LANGDEP(PSTRING("Vorbereiter"), PSTRING("Trainee")),
		5, 55,//Height & weight
		str_pokedex_data_290_page_0, str_pokedex_data_290_page_1,
		0,//unused
		405, 20,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 291
		LANGDEP(PSTRING("Ninja"), PSTRING("Ninja")),
		8, 120,//Height & weight
		str_pokedex_data_291_page_0, str_pokedex_data_291_page_1,
		0,//unused
		383, 65527,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 292
		LANGDEP(PSTRING("Häutung"), PSTRING("Shed")),
		8, 12,//Height & weight
		str_pokedex_data_292_page_0, str_pokedex_data_292_page_1,
		0,//unused
		372, 65528,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 276
		LANGDEP(PSTRING("Schwälblein"), PSTRING("Tinyswallow")),
		3, 23,//Height & weight
		str_pokedex_data_276_page_0, str_pokedex_data_276_page_1,
		0,//unused
		465, 20,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 277
		LANGDEP(PSTRING("Schwalbe"), PSTRING("Swallow")),
		7, 198,//Height & weight
		str_pokedex_data_277_page_0, str_pokedex_data_277_page_1,
		0,//unused
		428, 13,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 285
		LANGDEP(PSTRING("Pilz"), PSTRING("Mushroom")),
		4, 45,//Height & weight
		str_pokedex_data_285_page_0, str_pokedex_data_285_page_1,
		0,//unused
		513, 20,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 286
		LANGDEP(PSTRING("Pilz"), PSTRING("Mushroom")),
		12, 392,//Height & weight
		str_pokedex_data_286_page_0, str_pokedex_data_286_page_1,
		0,//unused
		324, 6,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 327
		LANGDEP(PSTRING("Punkt-panda"), PSTRING("Spot panda")),
		11, 50,//Height & weight
		str_pokedex_data_327_page_0, str_pokedex_data_327_page_1,
		0,//unused
		321, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 278
		LANGDEP(PSTRING("Seemöwe"), PSTRING("Seagull")),
		6, 95,//Height & weight
		str_pokedex_data_278_page_0, str_pokedex_data_278_page_1,
		0,//unused
		295, 65534,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 279
		LANGDEP(PSTRING("Wasservogel"), PSTRING("Water bird")),
		12, 280,//Height & weight
		str_pokedex_data_279_page_0, str_pokedex_data_279_page_1,
		0,//unused
		288, 1,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 283
		LANGDEP(PSTRING("Wassergeher"), PSTRING("Pond skater")),
		5, 17,//Height & weight
		str_pokedex_data_283_page_0, str_pokedex_data_283_page_1,
		0,//unused
		375, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 284
		LANGDEP(PSTRING("Auge"), PSTRING("Eyeball")),
		8, 36,//Height & weight
		str_pokedex_data_284_page_0, str_pokedex_data_284_page_1,
		0,//unused
		378, 65535,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 320
		LANGDEP(PSTRING("Kugelwal"), PSTRING("Ball whale")),
		20, 1300,//Height & weight
		str_pokedex_data_320_page_0, str_pokedex_data_320_page_1,
		0,//unused
		256, 10,//Pokemon scale, displacement
		493, 10,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 321
		LANGDEP(PSTRING("Flutwal"), PSTRING("Float whale")),
		145, 3980,//Height & weight
		str_pokedex_data_321_page_0, str_pokedex_data_321_page_1,
		0,//unused
		276, 65535,//Pokemon scale, displacement
		1428, 20,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 300
		LANGDEP(PSTRING("Kätzchen"), PSTRING("Kitten")),
		6, 110,//Height & weight
		str_pokedex_data_300_page_0, str_pokedex_data_300_page_1,
		0,//unused
		492, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 301
		LANGDEP(PSTRING("Eingebildet"), PSTRING("Prim")),
		11, 326,//Height & weight
		str_pokedex_data_301_page_0, str_pokedex_data_301_page_1,
		0,//unused
		322, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 352
		LANGDEP(PSTRING("Farbenspiel"), PSTRING("Color swap")),
		10, 220,//Height & weight
		str_pokedex_data_352_page_0, str_pokedex_data_352_page_1,
		0,//unused
		316, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 343
		LANGDEP(PSTRING("Lehmpuppe"), PSTRING("Clay doll")),
		5, 215,//Height & weight
		str_pokedex_data_343_page_0, str_pokedex_data_343_page_1,
		0,//unused
		384, 18,//Pokemon scale, displacement
		256, 65533,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 344
		LANGDEP(PSTRING("Lehmpuppe"), PSTRING("Clay doll")),
		15, 1080,//Height & weight
		str_pokedex_data_344_page_0, str_pokedex_data_344_page_1,
		0,//unused
		256, 3,//Pokemon scale, displacement
		280, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 299
		LANGDEP(PSTRING("Kompass"), PSTRING("Compass")),
		10, 970,//Height & weight
		str_pokedex_data_299_page_0, str_pokedex_data_299_page_1,
		0,//unused
		256, 9,//Pokemon scale, displacement
		289, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 234
		LANGDEP(PSTRING("Kompass"), PSTRING("Big horn")),
		14, 712,//Height & weight
		str_pokedex_data_234_page_0, str_pokedex_data_234_page_1,
		0,//unused
		277, 65535,//Pokemon scale, displacement
		277, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 339
		LANGDEP(PSTRING("Barthaar"), PSTRING("Whiskers")),
		4, 19,//Height & weight
		str_pokedex_data_339_page_0, str_pokedex_data_339_page_1,
		0,//unused
		581, 65534,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 340
		LANGDEP(PSTRING("Barthaar"), PSTRING("Whiskers")),
		9, 236,//Height & weight
		str_pokedex_data_340_page_0, str_pokedex_data_340_page_1,
		0,//unused
		317, 1,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 341
		LANGDEP(PSTRING("Grobian"), PSTRING("Ruffian")),
		6, 115,//Height & weight
		str_pokedex_data_341_page_0, str_pokedex_data_341_page_1,
		0,//unused
		484, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 342
		LANGDEP(PSTRING("Schlingel"), PSTRING("Rogue")),
		11, 328,//Height & weight
		str_pokedex_data_342_page_0, str_pokedex_data_342_page_1,
		0,//unused
		365, 7,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 349
		LANGDEP(PSTRING("Fisch"), PSTRING("Fish")),
		6, 74,//Height & weight
		str_pokedex_data_349_page_0, str_pokedex_data_349_page_1,
		0,//unused
		423, 3,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 350
		LANGDEP(PSTRING("Zartheit"), PSTRING("Tender")),
		62, 1620,//Height & weight
		str_pokedex_data_350_page_0, str_pokedex_data_350_page_1,
		0,//unused
		282, 65535,//Pokemon scale, displacement
		382, 7,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 318
		LANGDEP(PSTRING("Gnadenlos"), PSTRING("Savage")),
		8, 208,//Height & weight
		str_pokedex_data_318_page_0, str_pokedex_data_318_page_1,
		0,//unused
		362, 0,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 319
		LANGDEP(PSTRING("Brutal"), PSTRING("Brutal")),
		18, 888,//Height & weight
		str_pokedex_data_319_page_0, str_pokedex_data_319_page_1,
		0,//unused
		265, 0,//Pokemon scale, displacement
		342, 4,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 328
		LANGDEP(PSTRING("Ameisenlöwe"), PSTRING("Ant pit")),
		7, 150,//Height & weight
		str_pokedex_data_328_page_0, str_pokedex_data_328_page_1,
		0,//unused
		298, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 329
		LANGDEP(PSTRING("Vibration"), PSTRING("Vibration")),
		11, 153,//Height & weight
		str_pokedex_data_329_page_0, str_pokedex_data_329_page_1,
		0,//unused
		370, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 330
		LANGDEP(PSTRING("Mystik"), PSTRING("Mystic")),
		20, 820,//Height & weight
		str_pokedex_data_330_page_0, str_pokedex_data_330_page_1,
		0,//unused
		280, 0,//Pokemon scale, displacement
		299, 2,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 296
		LANGDEP(PSTRING("Wellenspiel"), PSTRING("Guts")),
		10, 864,//Height & weight
		str_pokedex_data_296_page_0, str_pokedex_data_296_page_1,
		0,//unused
		256, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 297
		LANGDEP(PSTRING("Aura"), PSTRING("Arm thrust")),
		23, 2538,//Height & weight
		str_pokedex_data_297_page_0, str_pokedex_data_297_page_1,
		0,//unused
		268, 65535,//Pokemon scale, displacement
		375, 6,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 309
		LANGDEP(PSTRING("Gewitter"), PSTRING("Lightning")),
		6, 152,//Height & weight
		str_pokedex_data_309_page_0, str_pokedex_data_309_page_1,
		0,//unused
		290, 16,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 310
		LANGDEP(PSTRING("Entladung"), PSTRING("Discharge")),
		15, 402,//Height & weight
		str_pokedex_data_310_page_0, str_pokedex_data_310_page_1,
		0,//unused
		256, 1,//Pokemon scale, displacement
		257, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 322
		LANGDEP(PSTRING("Taubheit"), PSTRING("Numb")),
		7, 240,//Height & weight
		str_pokedex_data_322_page_0, str_pokedex_data_322_page_1,
		0,//unused
		310, 14,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 323
		LANGDEP(PSTRING("Ausbruch"), PSTRING("Eruption")),
		19, 2200,//Height & weight
		str_pokedex_data_323_page_0, str_pokedex_data_323_page_1,
		0,//unused
		256, 6,//Pokemon scale, displacement
		345, 4,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 363
		LANGDEP(PSTRING("Applaus"), PSTRING("Clap")),
		8, 395,//Height & weight
		str_pokedex_data_363_page_0, str_pokedex_data_363_page_1,
		0,//unused
		315, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 364
		LANGDEP(PSTRING("Spielball"), PSTRING("Ball roll")),
		11, 876,//Height & weight
		str_pokedex_data_364_page_0, str_pokedex_data_364_page_1,
		0,//unused
		338, 12,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 365
		LANGDEP(PSTRING("Eisbrecher"), PSTRING("Ice break")),
		14, 1506,//Height & weight
		str_pokedex_data_365_page_0, str_pokedex_data_365_page_1,
		0,//unused
		305, 2,//Pokemon scale, displacement
		277, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 331
		LANGDEP(PSTRING("Kaktus"), PSTRING("Cactus")),
		4, 513,//Height & weight
		str_pokedex_data_331_page_0, str_pokedex_data_331_page_1,
		0,//unused
		455, 19,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 332
		LANGDEP(PSTRING("Vogelschock"), PSTRING("Scarecrow")),
		13, 774,//Height & weight
		str_pokedex_data_332_page_0, str_pokedex_data_332_page_1,
		0,//unused
		327, 3,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 361
		LANGDEP(PSTRING("Schneehut"), PSTRING("Snow hat")),
		7, 168,//Height & weight
		str_pokedex_data_361_page_0, str_pokedex_data_361_page_1,
		0,//unused
		380, 14,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 362
		LANGDEP(PSTRING("Antlitz"), PSTRING("Face")),
		15, 2565,//Height & weight
		str_pokedex_data_362_page_0, str_pokedex_data_362_page_1,
		0,//unused
		256, 3,//Pokemon scale, displacement
		344, 2,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 202
		LANGDEP(PSTRING("Schneegebie"), PSTRING("Patient")),
		68, 285,//Height & weight
		str_pokedex_data_202_page_0, str_pokedex_data_202_page_1,
		0,//unused
		517, 4,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 337
		LANGDEP(PSTRING("Meteorit"), PSTRING("Meteorite")),
		10, 1680,//Height & weight
		str_pokedex_data_337_page_0, str_pokedex_data_337_page_1,
		0,//unused
		300, 1,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 338
		LANGDEP(PSTRING("Meteorit"), PSTRING("Meteorite")),
		12, 1540,//Height & weight
		str_pokedex_data_338_page_0, str_pokedex_data_338_page_1,
		0,//unused
		328, 65533,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 52
		LANGDEP(PSTRING("Dornfrucht"), PSTRING("Scratch cat")),
		4, 42,//Height & weight
		str_pokedex_data_52_page_0, str_pokedex_data_52_page_1,
		0,//unused
		480, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 53
		LANGDEP(PSTRING("Dornkugel"), PSTRING("Classy cat")),
		10, 320,//Height & weight
		str_pokedex_data_53_page_0, str_pokedex_data_53_page_1,
		0,//unused
		320, 10,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 325
		LANGDEP(PSTRING("Sprungfeder"), PSTRING("Bounce")),
		7, 306,//Height & weight
		str_pokedex_data_325_page_0, str_pokedex_data_325_page_1,
		0,//unused
		423, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 326
		LANGDEP(PSTRING("Manipulator"), PSTRING("Manipulate")),
		9, 715,//Height & weight
		str_pokedex_data_326_page_0, str_pokedex_data_326_page_1,
		0,//unused
		358, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 311
		LANGDEP(PSTRING("Jubel"), PSTRING("Cheering")),
		4, 42,//Height & weight
		str_pokedex_data_311_page_0, str_pokedex_data_311_page_1,
		0,//unused
		515, 65527,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 312
		LANGDEP(PSTRING("Jubel"), PSTRING("Cheering")),
		4, 42,//Height & weight
		str_pokedex_data_312_page_0, str_pokedex_data_312_page_1,
		0,//unused
		512, 65529,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 303
		LANGDEP(PSTRING("Schwindler"), PSTRING("Deceiver")),
		6, 115,//Height & weight
		str_pokedex_data_303_page_0, str_pokedex_data_303_page_1,
		0,//unused
		466, 15,//Pokemon scale, displacement
		256, 65533,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 307
		LANGDEP(PSTRING("Meditation"), PSTRING("Meditate")),
		6, 112,//Height & weight
		str_pokedex_data_307_page_0, str_pokedex_data_307_page_1,
		0,//unused
		465, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 308
		LANGDEP(PSTRING("Meditation"), PSTRING("Meditate")),
		13, 315,//Height & weight
		str_pokedex_data_308_page_0, str_pokedex_data_308_page_1,
		0,//unused
		298, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 333
		LANGDEP(PSTRING("Wollvogel"), PSTRING("Cotton bird")),
		4, 12,//Height & weight
		str_pokedex_data_333_page_0, str_pokedex_data_333_page_1,
		0,//unused
		422, 65528,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 334
		LANGDEP(PSTRING("Summsel"), PSTRING("Humming")),
		11, 206,//Height & weight
		str_pokedex_data_334_page_0, str_pokedex_data_334_page_1,
		0,//unused
		327, 0,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 355
		LANGDEP(PSTRING("Requiem"), PSTRING("Requiem")),
		8, 150,//Height & weight
		str_pokedex_data_355_page_0, str_pokedex_data_355_page_1,
		0,//unused
		376, 13,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 356
		LANGDEP(PSTRING("Wink"), PSTRING("Beckon")),
		16, 306,//Height & weight
		str_pokedex_data_356_page_0, str_pokedex_data_356_page_1,
		0,//unused
		256, 2,//Pokemon scale, displacement
		299, 2,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 302
		LANGDEP(PSTRING("Greifer"), PSTRING("Darkness")),
		5, 110,//Height & weight
		str_pokedex_data_302_page_0, str_pokedex_data_302_page_1,
		0,//unused
		451, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 287
		LANGDEP(PSTRING("Faulpelz"), PSTRING("Slacker")),
		8, 240,//Height & weight
		str_pokedex_data_287_page_0, str_pokedex_data_287_page_1,
		0,//unused
		291, 16,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 288
		LANGDEP(PSTRING("Wildaffe"), PSTRING("Wild monkey")),
		14, 465,//Height & weight
		str_pokedex_data_288_page_0, str_pokedex_data_288_page_1,
		0,//unused
		301, 1,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 289
		LANGDEP(PSTRING("Müssig"), PSTRING("Lazy")),
		20, 1305,//Height & weight
		str_pokedex_data_289_page_0, str_pokedex_data_289_page_1,
		0,//unused
		277, 5,//Pokemon scale, displacement
		326, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 316
		LANGDEP(PSTRING("Magen"), PSTRING("Stomach")),
		4, 103,//Height & weight
		str_pokedex_data_316_page_0, str_pokedex_data_316_page_1,
		0,//unused
		593, 22,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 317
		LANGDEP(PSTRING("Giftbeutel"), PSTRING("Poison bag")),
		17, 800,//Height & weight
		str_pokedex_data_317_page_0, str_pokedex_data_317_page_1,
		0,//unused
		256, 5,//Pokemon scale, displacement
		345, 4,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 357
		LANGDEP(PSTRING("Obst"), PSTRING("Fruit")),
		20, 1000,//Height & weight
		str_pokedex_data_357_page_0, str_pokedex_data_357_page_1,
		0,//unused
		283, 65535,//Pokemon scale, displacement
		371, 6,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 19
		LANGDEP(PSTRING("Bronze"), PSTRING("Mouse")),
		3, 35,//Height & weight
		str_pokedex_data_19_page_0, str_pokedex_data_19_page_1,
		0,//unused
		481, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 20
		LANGDEP(PSTRING("Bronzeglock"), PSTRING("Mouse")),
		7, 185,//Height & weight
		str_pokedex_data_20_page_0, str_pokedex_data_20_page_1,
		0,//unused
		401, 14,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 366
		LANGDEP(PSTRING("Muschel"), PSTRING("Bivalve")),
		4, 525,//Height & weight
		str_pokedex_data_366_page_0, str_pokedex_data_366_page_1,
		0,//unused
		691, 22,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 367
		LANGDEP(PSTRING("Tiefsee"), PSTRING("Deep sea")),
		17, 270,//Height & weight
		str_pokedex_data_367_page_0, str_pokedex_data_367_page_1,
		0,//unused
		307, 1,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 368
		LANGDEP(PSTRING("Südsee"), PSTRING("South sea")),
		18, 226,//Height & weight
		str_pokedex_data_368_page_0, str_pokedex_data_368_page_1,
		0,//unused
		278, 5,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 359
		LANGDEP(PSTRING("Desaster"), PSTRING("Disaster")),
		12, 470,//Height & weight
		str_pokedex_data_359_page_0, str_pokedex_data_359_page_1,
		0,//unused
		301, 1,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 353
		LANGDEP(PSTRING("Puppe"), PSTRING("Puppet")),
		6, 23,//Height & weight
		str_pokedex_data_353_page_0, str_pokedex_data_353_page_1,
		0,//unused
		440, 65533,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 354
		LANGDEP(PSTRING("Marionette"), PSTRING("Marionette")),
		11, 125,//Height & weight
		str_pokedex_data_354_page_0, str_pokedex_data_354_page_1,
		0,//unused
		262, 9,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 336
		LANGDEP(PSTRING("Reisszahn"), PSTRING("Fang snake")),
		27, 525,//Height & weight
		str_pokedex_data_336_page_0, str_pokedex_data_336_page_1,
		0,//unused
		275, 6,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 335
		LANGDEP(PSTRING("Frettkatz"), PSTRING("Cat ferret")),
		13, 403,//Height & weight
		str_pokedex_data_335_page_0, str_pokedex_data_335_page_1,
		0,//unused
		256, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 369
		LANGDEP(PSTRING("Bestand"), PSTRING("Longevity")),
		10, 234,//Height & weight
		str_pokedex_data_369_page_0, str_pokedex_data_369_page_1,
		0,//unused
		316, 5,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 114
		LANGDEP(PSTRING("Finsternis"), PSTRING("Vine")),
		5, 110,//Height & weight
		str_pokedex_data_114_page_0, str_pokedex_data_114_page_1,
		0,//unused
		451, 15,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 304
		LANGDEP(PSTRING("Eisenpanzer"), PSTRING("Iron armor")),
		4, 600,//Height & weight
		str_pokedex_data_304_page_0, str_pokedex_data_304_page_1,
		0,//unused
		419, 21,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 305
		LANGDEP(PSTRING("Eisenpanzer"), PSTRING("Iron armor")),
		9, 1200,//Height & weight
		str_pokedex_data_305_page_0, str_pokedex_data_305_page_1,
		0,//unused
		275, 11,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 306
		LANGDEP(PSTRING("Eisenpanzer"), PSTRING("Iron armor")),
		21, 3600,//Height & weight
		str_pokedex_data_306_page_0, str_pokedex_data_306_page_1,
		0,//unused
		274, 65535,//Pokemon scale, displacement
		374, 7,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 351
		LANGDEP(PSTRING("Wetter"), PSTRING("Weather")),
		3, 8,//Height & weight
		str_pokedex_data_351_page_0, str_pokedex_data_351_page_1,
		0,//unused
		435, 65531,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 360
		LANGDEP(PSTRING("Glöckchen"), PSTRING("Bell")),
		2, 6,//Height & weight
		str_pokedex_data_360_page_0, str_pokedex_data_360_page_1,
		0,//unused
		453, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 358
		LANGDEP(PSTRING("Windspiel"), PSTRING("Wind chime")),
		6, 10,//Height & weight
		str_pokedex_data_358_page_0, str_pokedex_data_358_page_1,
		0,//unused
		505, 65532,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 345
		LANGDEP(PSTRING("Seeanemone"), PSTRING("Sea lily")),
		10, 238,//Height & weight
		str_pokedex_data_345_page_0, str_pokedex_data_345_page_1,
		0,//unused
		305, 8,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 346
		LANGDEP(PSTRING("Rankfüsser"), PSTRING("Barnacle")),
		15, 604,//Height & weight
		str_pokedex_data_346_page_0, str_pokedex_data_346_page_1,
		0,//unused
		275, 65535,//Pokemon scale, displacement
		269, 65535,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 347
		LANGDEP(PSTRING("Krebssenior"), PSTRING("Old shrimp")),
		7, 125,//Height & weight
		str_pokedex_data_347_page_0, str_pokedex_data_347_page_1,
		0,//unused
		296, 4,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 348
		LANGDEP(PSTRING("Schild"), PSTRING("Plate")),
		15, 682,//Height & weight
		str_pokedex_data_348_page_0, str_pokedex_data_348_page_1,
		0,//unused
		312, 2,//Pokemon scale, displacement
		271, 65535,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 280
		LANGDEP(PSTRING("Gefühl"), PSTRING("Feeling")),
		4, 66,//Height & weight
		str_pokedex_data_280_page_0, str_pokedex_data_280_page_1,
		0,//unused
		457, 18,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 281
		LANGDEP(PSTRING("Emotion"), PSTRING("Emotion")),
		8, 202,//Height & weight
		str_pokedex_data_281_page_0, str_pokedex_data_281_page_1,
		0,//unused
		354, 10,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 282
		LANGDEP(PSTRING("Umarmung"), PSTRING("Embrace")),
		16, 484,//Height & weight
		str_pokedex_data_282_page_0, str_pokedex_data_282_page_1,
		0,//unused
		277, 0,//Pokemon scale, displacement
		276, 65535,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 124
		LANGDEP(PSTRING("Klinge"), PSTRING("Human shape")),
		14, 406,//Height & weight
		str_pokedex_data_124_page_0, str_pokedex_data_124_page_1,
		0,//unused
		256, 3,//Pokemon scale, displacement
		300, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 371
		LANGDEP(PSTRING("Steinhaupt"), PSTRING("Rock head")),
		6, 421,//Height & weight
		str_pokedex_data_371_page_0, str_pokedex_data_371_page_1,
		0,//unused
		448, 17,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 372
		LANGDEP(PSTRING("Durchsteher"), PSTRING("Endurance")),
		11, 1105,//Height & weight
		str_pokedex_data_372_page_0, str_pokedex_data_372_page_1,
		0,//unused
		311, 10,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 373
		LANGDEP(PSTRING("Drache"), PSTRING("Dragon")),
		15, 1026,//Height & weight
		str_pokedex_data_373_page_0, str_pokedex_data_373_page_1,
		0,//unused
		272, 2,//Pokemon scale, displacement
		307, 0,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 374
		LANGDEP(PSTRING("Eisenkugel"), PSTRING("Iron ball")),
		6, 952,//Height & weight
		str_pokedex_data_374_page_0, str_pokedex_data_374_page_1,
		0,//unused
		414, 65535,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 375
		LANGDEP(PSTRING("Eisenklaue"), PSTRING("Iron claw")),
		12, 2025,//Height & weight
		str_pokedex_data_375_page_0, str_pokedex_data_375_page_1,
		0,//unused
		256, 3,//Pokemon scale, displacement
		272, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 376
		LANGDEP(PSTRING("Eisenfuss"), PSTRING("Iron leg")),
		16, 5500,//Height & weight
		str_pokedex_data_376_page_0, str_pokedex_data_376_page_1,
		0,//unused
		272, 3,//Pokemon scale, displacement
		461, 4,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 377
		LANGDEP(PSTRING("Steingipfel"), PSTRING("Rock peak")),
		17, 2300,//Height & weight
		str_pokedex_data_377_page_0, str_pokedex_data_377_page_1,
		0,//unused
		256, 1,//Pokemon scale, displacement
		309, 1,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 378
		LANGDEP(PSTRING("Eisberg"), PSTRING("Iceberg")),
		18, 1750,//Height & weight
		str_pokedex_data_378_page_0, str_pokedex_data_378_page_1,
		0,//unused
		265, 0,//Pokemon scale, displacement
		317, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 379
		LANGDEP(PSTRING("Eisen"), PSTRING("Iron")),
		19, 2050,//Height & weight
		str_pokedex_data_379_page_0, str_pokedex_data_379_page_1,
		0,//unused
		256, 0,//Pokemon scale, displacement
		359, 6,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 382
		LANGDEP(PSTRING("Seegründler"), PSTRING("Sea basin")),
		45, 3520,//Height & weight
		str_pokedex_data_382_page_0, str_pokedex_data_382_page_1,
		0,//unused
		272, 1,//Pokemon scale, displacement
		639, 13,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 383
		LANGDEP(PSTRING("Kontinent"), PSTRING("Continent")),
		35, 9500,//Height & weight
		str_pokedex_data_383_page_0, str_pokedex_data_383_page_1,
		0,//unused
		276, 0,//Pokemon scale, displacement
		530, 12,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 384
		LANGDEP(PSTRING("Himmelhoch"), PSTRING("Sky high")),
		70, 2065,//Height & weight
		str_pokedex_data_384_page_0, str_pokedex_data_384_page_1,
		0,//unused
		286, 65535,//Pokemon scale, displacement
		483, 9,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 380
		LANGDEP(PSTRING("Äon"), PSTRING("Eon")),
		14, 400,//Height & weight
		str_pokedex_data_380_page_0, str_pokedex_data_380_page_1,
		0,//unused
		291, 2,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 381
		LANGDEP(PSTRING("Äon"), PSTRING("Eon")),
		20, 600,//Height & weight
		str_pokedex_data_381_page_0, str_pokedex_data_381_page_1,
		0,//unused
		273, 0,//Pokemon scale, displacement
		313, 3,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 385
		LANGDEP(PSTRING("Wünscher"), PSTRING("Wish")),
		3, 11,//Height & weight
		str_pokedex_data_385_page_0, str_pokedex_data_385_page_1,
		0,//unused
		608, 65528,//Pokemon scale, displacement
		256, 65534,//Trainer scale, displacement
		0,//unused
	},
	{
		//Entry 386
		LANGDEP(PSTRING("Dns"), PSTRING("Dna")),
		17, 608,//Height & weight
		str_pokedex_data_386_page_0, str_pokedex_data_386_page_1,
		0,//unused
		293, 0,//Pokemon scale, displacement
		337, 2,//Trainer scale, displacement
		0,//unused
	}
};
