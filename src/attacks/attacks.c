#include "types.h"
#include "attack.h"
#include "basestats.h"

attack attacks[ATTACK_CNT] = {
	// ATTACK_NONE
	{
		0x0, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		0, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_PFUND
	{
		0x0, //Effect-id (in table)
		40, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		40, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KARATESCHLAG
	{
		0x2b, //Effect-id (in table)
		50, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		25, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_DUPLEXHIEB
	{
		0x1d, //Effect-id (in table)
		15, //Base Power
		TYPE_NORMAL,
		85, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KOMETENHIEB
	{
		0x1d, //Effect-id (in table)
		18, //Base Power
		TYPE_NORMAL,
		85, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_MEGAHIEB
	{
		0x0, //Effect-id (in table)
		80, //Base Power
		TYPE_NORMAL,
		85, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ZAHLTAG
	{
		0x22, //Effect-id (in table)
		40, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FEUERSCHLAG
	{
		0x4, //Effect-id (in table)
		75, //Base Power
		TYPE_FIRE,
		100, //Accuracy
		15, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_EISHIEB
	{
		0x5, //Effect-id (in table)
		75, //Base Power
		TYPE_ICE,
		100, //Accuracy
		15, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_DONNERSCHLAG
	{
		0x6, //Effect-id (in table)
		75, //Base Power
		TYPE_ELECTRIC,
		100, //Accuracy
		15, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KRATZER
	{
		0x0, //Effect-id (in table)
		40, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		35, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KLAMMER
	{
		0x0, //Effect-id (in table)
		55, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_GUILLOTINE
	{
		0x26, //Effect-id (in table)
		1, //Base Power
		TYPE_NORMAL,
		30, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KLINGENSTURM
	{
		0x27, //Effect-id (in table)
		80, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SCHWERTTANZ
	{
		0x32, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_ZERSCHNEIDER
	{
		0x0, //Effect-id (in table)
		65, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_WINDSTOSS
	{
		0x95, //Effect-id (in table)
		40, //Base Power
		TYPE_FLYING,
		100, //Accuracy
		35, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_FLUEGELSCHLAG
	{
		0x0, //Effect-id (in table)
		60, //Base Power
		TYPE_FLYING,
		100, //Accuracy
		35, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_WIRBELWIND
	{
		0x1c, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		-6, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_FLIEGEN
	{
		0x9b, //Effect-id (in table)
		70, //Base Power
		TYPE_FLYING,
		95, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KLAMMERGRIFF
	{
		0x2a, //Effect-id (in table)
		15, //Base Power
		TYPE_NORMAL,
		75, //Accuracy
		20, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SLAM
	{
		0x0, //Effect-id (in table)
		80, //Base Power
		TYPE_NORMAL,
		75, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_RANKENHIEB
	{
		0x0, //Effect-id (in table)
		35, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_STAMPFER
	{
		0x96, //Effect-id (in table)
		65, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_DOPPELKICK
	{
		0x2c, //Effect-id (in table)
		30, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_MEGAKICK
	{
		0x0, //Effect-id (in table)
		120, //Base Power
		TYPE_NORMAL,
		75, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SPRUNGKICK
	{
		0x2d, //Effect-id (in table)
		70, //Base Power
		TYPE_FIGHTING,
		95, //Accuracy
		25, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FEGEKICK
	{
		0x1f, //Effect-id (in table)
		60, //Base Power
		TYPE_FIGHTING,
		85, //Accuracy
		15, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SANDWIRBEL
	{
		0x17, //Effect-id (in table)
		0, //Base Power
		TYPE_GROUND,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_KOPFNUSS
	{
		0x1f, //Effect-id (in table)
		70, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		15, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_HORNATTACKE
	{
		0x0, //Effect-id (in table)
		65, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		25, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FURIENSCHLAG
	{
		0x1d, //Effect-id (in table)
		15, //Base Power
		TYPE_NORMAL,
		85, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_HORNBOHRER
	{
		0x26, //Effect-id (in table)
		1, //Base Power
		TYPE_NORMAL,
		30, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_TACKLE
	{
		0x0, //Effect-id (in table)
		35, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		35, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_BODYSLAM
	{
		0x6, //Effect-id (in table)
		85, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		15, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_WICKEL
	{
		0x2a, //Effect-id (in table)
		15, //Base Power
		TYPE_NORMAL,
		85, //Accuracy
		20, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_BODYCHEK
	{
		0x30, //Effect-id (in table)
		90, //Base Power
		TYPE_NORMAL,
		85, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FUCHTLER
	{
		0x1b, //Effect-id (in table)
		90, //Base Power
		TYPE_NORMAL,
		120, //Accuracy
		20, //PP
		100, //Effect accuracy
		RANDOM_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_RISIKOTACKLE
	{
		0xc6, //Effect-id (in table)
		120, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_RUTENSCHLAG
	{
		0x13, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_GIFTSTACHEL
	{
		0x2, //Effect-id (in table)
		15, //Base Power
		TYPE_POISON,
		100, //Accuracy
		35, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_DUONADEL
	{
		0x4d, //Effect-id (in table)
		25, //Base Power
		TYPE_BUG,
		100, //Accuracy
		20, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_NADELRAKETE
	{
		0x1d, //Effect-id (in table)
		14, //Base Power
		TYPE_BUG,
		85, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SILBERBLICK
	{
		0x13, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_BISS
	{
		0x1f, //Effect-id (in table)
		60, //Base Power
		TYPE_DARK,
		100, //Accuracy
		25, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_HEULER
	{
		0x12, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		40, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_BRUELLER
	{
		0x1c, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		-6, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_GESANG
	{
		0x1, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		55, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SUPERSCHALL
	{
		0x31, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		55, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_ULTRASCHALL
	{
		0x82, //Effect-id (in table)
		1, //Base Power
		TYPE_NORMAL,
		90, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_AUSSETZER
	{
		0x56, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		55, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SAEURE
	{
		0x45, //Effect-id (in table)
		40, //Base Power
		TYPE_POISON,
		100, //Accuracy
		30, //PP
		10, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_GLUT
	{
		0x4, //Effect-id (in table)
		40, //Base Power
		TYPE_FIRE,
		100, //Accuracy
		25, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_FLAMMENWURF
	{
		0x4, //Effect-id (in table)
		95, //Base Power
		TYPE_FIRE,
		100, //Accuracy
		15, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_WEISSNEBEL
	{
		0x2e, //Effect-id (in table)
		0, //Base Power
		TYPE_ICE,
		0, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_AQUAKNARRE
	{
		0x0, //Effect-id (in table)
		40, //Base Power
		TYPE_WATER,
		100, //Accuracy
		25, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_HYDROPUMPE
	{
		0x0, //Effect-id (in table)
		120, //Base Power
		TYPE_WATER,
		80, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SURFER
	{
		0x0, //Effect-id (in table)
		95, //Base Power
		TYPE_WATER,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_EISSTRAHL
	{
		0x5, //Effect-id (in table)
		95, //Base Power
		TYPE_ICE,
		100, //Accuracy
		10, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_BLIZZARD
	{
		0x5, //Effect-id (in table)
		120, //Base Power
		TYPE_ICE,
		70, //Accuracy
		5, //PP
		10, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_PSYSTRAHL
	{
		0x4c, //Effect-id (in table)
		65, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		20, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_BLUBBSTRAHL
	{
		0x46, //Effect-id (in table)
		65, //Base Power
		TYPE_WATER,
		100, //Accuracy
		20, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_AURORASTRAHL
	{
		0x44, //Effect-id (in table)
		65, //Base Power
		TYPE_ICE,
		100, //Accuracy
		20, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_HYPERSTRAHL
	{
		0x50, //Effect-id (in table)
		150, //Base Power
		TYPE_NORMAL,
		90, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SCHNABEL
	{
		0x0, //Effect-id (in table)
		35, //Base Power
		TYPE_FLYING,
		100, //Accuracy
		35, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_BOHRSCHNABEL
	{
		0x0, //Effect-id (in table)
		80, //Base Power
		TYPE_FLYING,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_UEBERROLLER
	{
		0x30, //Effect-id (in table)
		80, //Base Power
		TYPE_FIGHTING,
		80, //Accuracy
		25, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FUSSKICK
	{
		0xc4, //Effect-id (in table)
		1, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FAUSTHIEB
	{
		0x0, //Effect-id (in table)
		75, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_GEOWURF
	{
		0x57, //Effect-id (in table)
		1, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_STAERKE
	{
		0x0, //Effect-id (in table)
		80, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ABSORBER
	{
		0x3, //Effect-id (in table)
		20, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_MEGASAUGER
	{
		0x3, //Effect-id (in table)
		40, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_EGELSAMEN
	{
		0x54, //Effect-id (in table)
		0, //Base Power
		TYPE_GRASS,
		90, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_WACHSTUM
	{
		0xd, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		40, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_RASIERBLATT
	{
		0x2b, //Effect-id (in table)
		55, //Base Power
		TYPE_GRASS,
		95, //Accuracy
		25, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SOLARSTRAHL
	{
		0x97, //Effect-id (in table)
		120, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_GIFTPUDER
	{
		0x42, //Effect-id (in table)
		0, //Base Power
		TYPE_POISON,
		75, //Accuracy
		35, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_STACHELSPORE
	{
		0x43, //Effect-id (in table)
		0, //Base Power
		TYPE_GRASS,
		75, //Accuracy
		30, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SCHLAFPUDER
	{
		0x1, //Effect-id (in table)
		0, //Base Power
		TYPE_GRASS,
		75, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_BLAETTERTANZ
	{
		0x1b, //Effect-id (in table)
		120, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		20, //PP
		100, //Effect accuracy
		RANDOM_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_FADENSCHUSS
	{
		0x14, //Effect-id (in table)
		0, //Base Power
		TYPE_BUG,
		95, //Accuracy
		40, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_DRACHENWUT
	{
		0x29, //Effect-id (in table)
		1, //Base Power
		TYPE_DRAGON,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_FEUERWIRBEL
	{
		0x2a, //Effect-id (in table)
		15, //Base Power
		TYPE_FIRE,
		70, //Accuracy
		15, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_DONNERSCHOCK
	{
		0x6, //Effect-id (in table)
		40, //Base Power
		TYPE_ELECTRIC,
		100, //Accuracy
		30, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_DONNERBLITZ
	{
		0x6, //Effect-id (in table)
		95, //Base Power
		TYPE_ELECTRIC,
		100, //Accuracy
		15, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_DONNERWELLE
	{
		0x43, //Effect-id (in table)
		0, //Base Power
		TYPE_ELECTRIC,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_DONNER
	{
		0x98, //Effect-id (in table)
		120, //Base Power
		TYPE_ELECTRIC,
		70, //Accuracy
		10, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_STEINWURF
	{
		0x0, //Effect-id (in table)
		50, //Base Power
		TYPE_ROCK,
		90, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_ERDBEBEN
	{
		0x93, //Effect-id (in table)
		100, //Base Power
		TYPE_GROUND,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES_AND_PARTNER,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_GEOFISSUR
	{
		0x26, //Effect-id (in table)
		1, //Base Power
		TYPE_GROUND,
		30, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SCHAUFLER
	{
		0x9b, //Effect-id (in table)
		60, //Base Power
		TYPE_GROUND,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_TOXIN
	{
		0x21, //Effect-id (in table)
		0, //Base Power
		TYPE_POISON,
		85, //Accuracy
		10, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_KONFUSION
	{
		0x4c, //Effect-id (in table)
		50, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		25, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_PSYCHOKINESE
	{
		0x48, //Effect-id (in table)
		90, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		10, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_HYPNOSE
	{
		0x1, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		60, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_MEDITATION
	{
		0xa, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		0, //Accuracy
		40, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_AGILITAET
	{
		0x34, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		0, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_RUCKZUCKHIEB
	{
		0x67, //Effect-id (in table)
		40, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		1, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_RASEREI
	{
		0x51, //Effect-id (in table)
		20, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_TELEPORT
	{
		0x99, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_NACHTNEBEL
	{
		0x57, //Effect-id (in table)
		1, //Base Power
		TYPE_GHOST,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_MIMIKRY
	{
		0x52, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_KREIDESCHREI
	{
		0x3b, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		85, //Accuracy
		40, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_DOPPELTEAM
	{
		0x10, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		15, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_GENESUNG
	{
		0x20, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_HAERTNER
	{
		0xb, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_KOMPRIMATOR
	{
		0x6c, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_RAUCHWOLKE
	{
		0x17, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_KONFUSTRAHL
	{
		0x31, //Effect-id (in table)
		0, //Base Power
		TYPE_GHOST,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_PANZERSCHUTZ
	{
		0xb, //Effect-id (in table)
		0, //Base Power
		TYPE_WATER,
		0, //Accuracy
		40, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_EINIGLER
	{
		0x9c, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		40, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_BARRIERE
	{
		0x33, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		0, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_LICHTSCHILD
	{
		0x23, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		0, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_DUNKELNEBEL
	{
		0x19, //Effect-id (in table)
		0, //Base Power
		TYPE_ICE,
		0, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_PROTECT,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_REFLEKTOR
	{
		0x41, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_ENERGIEFOKUS
	{
		0x2f, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_GEDULD
	{
		0x1a, //Effect-id (in table)
		1, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_METRONOM
	{
		0x53, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_DEPENDS_ON_ATTACK,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SPIEGELTRICK
	{
		0x9, //Effect-id (in table)
		0, //Base Power
		TYPE_FLYING,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_DEPENDS_ON_ATTACK,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_FINALE
	{
		0x7, //Effect-id (in table)
		200, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES_AND_PARTNER,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_EIERBOMBE
	{
		0x0, //Effect-id (in table)
		100, //Base Power
		TYPE_NORMAL,
		75, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SCHLECKER
	{
		0x6, //Effect-id (in table)
		20, //Base Power
		TYPE_GHOST,
		100, //Accuracy
		30, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SMOG
	{
		0x2, //Effect-id (in table)
		20, //Base Power
		TYPE_POISON,
		70, //Accuracy
		20, //PP
		40, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SCHLAMMBAD
	{
		0x2, //Effect-id (in table)
		65, //Base Power
		TYPE_POISON,
		100, //Accuracy
		20, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_KNOCHENKEULE
	{
		0x1f, //Effect-id (in table)
		65, //Base Power
		TYPE_GROUND,
		85, //Accuracy
		20, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FEUERSTURM
	{
		0x4, //Effect-id (in table)
		120, //Base Power
		TYPE_FIRE,
		85, //Accuracy
		5, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_KASKADE
	{
		0x1f, //Effect-id (in table)
		105, //Base Power
		TYPE_WATER,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SCHNAPPER
	{
		0x2a, //Effect-id (in table)
		35, //Base Power
		TYPE_WATER,
		75, //Accuracy
		10, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_STERNSCHAUER
	{
		0x11, //Effect-id (in table)
		60, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SCHAEDELWUMME
	{
		0x91, //Effect-id (in table)
		100, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_DORNKANONE
	{
		0x1d, //Effect-id (in table)
		20, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_UMKLAMMERUNG
	{
		0x46, //Effect-id (in table)
		10, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		35, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_AMNESIE
	{
		0x36, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_PSYKRAFT
	{
		0x17, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		80, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_WEICHEI
	{
		0x9d, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_TURMKICK
	{
		0x2d, //Effect-id (in table)
		85, //Base Power
		TYPE_FIGHTING,
		90, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_GIFTBLICK
	{
		0x43, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		75, //Accuracy
		30, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_TRAUMFRESSER
	{
		0x8, //Effect-id (in table)
		100, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_GIFTWOLKE
	{
		0x42, //Effect-id (in table)
		0, //Base Power
		TYPE_POISON,
		55, //Accuracy
		40, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_STAKKATO
	{
		0x1d, //Effect-id (in table)
		15, //Base Power
		TYPE_NORMAL,
		85, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_BLUTSAUGER
	{
		0x3, //Effect-id (in table)
		20, //Base Power
		TYPE_BUG,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_TODESKUSS
	{
		0x1, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		75, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_HIMMELSFEGER
	{
		0x4b, //Effect-id (in table)
		140, //Base Power
		TYPE_FLYING,
		90, //Accuracy
		5, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_WANDLER
	{
		0x39, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_BLUBBER
	{
		0x46, //Effect-id (in table)
		20, //Base Power
		TYPE_WATER,
		100, //Accuracy
		30, //PP
		10, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_IRRSCHLAG
	{
		0x4c, //Effect-id (in table)
		70, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_PILZSPORE
	{
		0x1, //Effect-id (in table)
		0, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_BLITZ
	{
		0x11, //Effect-id (in table)
		60, //Base Power
		TYPE_ELECTRIC,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_PSYWELLE
	{
		0x58, //Effect-id (in table)
		1, //Base Power
		TYPE_PSYCHIC,
		80, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_PLATSCHER
	{
		0x55, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		40, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SAEUREPANZER
	{
		0x33, //Effect-id (in table)
		0, //Base Power
		TYPE_POISON,
		0, //Accuracy
		40, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_KRABBHAMMER
	{
		0x2b, //Effect-id (in table)
		90, //Base Power
		TYPE_WATER,
		85, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_EXPLOSION
	{
		0x7, //Effect-id (in table)
		250, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES_AND_PARTNER,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KRATZFURIE
	{
		0x1d, //Effect-id (in table)
		18, //Base Power
		TYPE_NORMAL,
		80, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KNOCHMERANG
	{
		0x2c, //Effect-id (in table)
		50, //Base Power
		TYPE_GROUND,
		90, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ERHOLUNG
	{
		0x25, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_STEINHAGEL
	{
		0x1f, //Effect-id (in table)
		75, //Base Power
		TYPE_ROCK,
		90, //Accuracy
		10, //PP
		30, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_HYPERZAHN
	{
		0x1f, //Effect-id (in table)
		80, //Base Power
		TYPE_NORMAL,
		90, //Accuracy
		15, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SCHAERFER
	{
		0xa, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_UMWANDLUNG
	{
		0x1e, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_TRIPLETTE
	{
		0x24, //Effect-id (in table)
		80, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SUPERZAHN
	{
		0x28, //Effect-id (in table)
		1, //Base Power
		TYPE_NORMAL,
		90, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SCHLITZER
	{
		0x2b, //Effect-id (in table)
		70, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_DELEGATOR
	{
		0x4f, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_VERZWEIFLER
	{
		0x30, //Effect-id (in table)
		50, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		1, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_NACHAHMER
	{
		0x5f, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		1, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_DREIFACHKICK
	{
		0x68, //Effect-id (in table)
		10, //Base Power
		TYPE_FIGHTING,
		90, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_RAUB
	{
		0x69, //Effect-id (in table)
		40, //Base Power
		TYPE_DARK,
		100, //Accuracy
		10, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SPINNENNETZ
	{
		0x6a, //Effect-id (in table)
		0, //Base Power
		TYPE_BUG,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_WILLENSLESER
	{
		0x5e, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_NACHTMAHR
	{
		0x6b, //Effect-id (in table)
		0, //Base Power
		TYPE_GHOST,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_FLAMMENRAD
	{
		0x7d, //Effect-id (in table)
		60, //Base Power
		TYPE_FIRE,
		100, //Accuracy
		25, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SCHNARCHER
	{
		0x5c, //Effect-id (in table)
		40, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		15, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_FLUCH
	{
		0x6d, //Effect-id (in table)
		0, //Base Power
		TYPE_GHOST,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_DRESCHFLEGEL
	{
		0x63, //Effect-id (in table)
		1, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_UNWANDLUNG2
	{
		0x5d, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_LUFTSTOSS
	{
		0x2b, //Effect-id (in table)
		100, //Base Power
		TYPE_FLYING,
		95, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_BAUMWOLLSAAT
	{
		0x3c, //Effect-id (in table)
		0, //Base Power
		TYPE_GRASS,
		85, //Accuracy
		40, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_GEGENSCHLAG
	{
		0x63, //Effect-id (in table)
		1, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_GROLL
	{
		0x64, //Effect-id (in table)
		0, //Base Power
		TYPE_GHOST,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_PULVERSCHNEE
	{
		0x5, //Effect-id (in table)
		40, //Base Power
		TYPE_ICE,
		100, //Accuracy
		25, //PP
		10, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SCHUTZSCHILD
	{
		0x6f, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		3, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_TEMPOHIEB
	{
		0x67, //Effect-id (in table)
		40, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		1, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_GRIMASSE
	{
		0x3c, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		90, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_FINTE
	{
		0x11, //Effect-id (in table)
		60, //Base Power
		TYPE_DARK,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_BITTERKUSS
	{
		0x31, //Effect-id (in table)
		0, //Base Power
		TYPE_FAIRY,
		75, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_BAUCHTROMMEL
	{
		0x8e, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_MATSCHBOMBE
	{
		0x2, //Effect-id (in table)
		90, //Base Power
		TYPE_POISON,
		100, //Accuracy
		10, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_LEHMSCHELLE
	{
		0x49, //Effect-id (in table)
		20, //Base Power
		TYPE_GROUND,
		100, //Accuracy
		10, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_OCTAZOOKA
	{
		0x49, //Effect-id (in table)
		65, //Base Power
		TYPE_WATER,
		85, //Accuracy
		10, //PP
		50, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_STACHLER
	{
		0x70, //Effect-id (in table)
		0, //Base Power
		TYPE_GROUND,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_OPPONENT_FIELD,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_BLITZKANONE
	{
		0x6, //Effect-id (in table)
		100, //Base Power
		TYPE_ELECTRIC,
		50, //Accuracy
		5, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_GESICHTE
	{
		0x71, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		40, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_ABGANGSBUND
	{
		0x62, //Effect-id (in table)
		0, //Base Power
		TYPE_GHOST,
		0, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_ABGESANG
	{
		0x72, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_EISSTURM
	{
		0x46, //Effect-id (in table)
		55, //Base Power
		TYPE_ICE,
		95, //Accuracy
		15, //PP
		100, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SCANNER
	{
		0x6f, //Effect-id (in table)
		0, //Base Power
		TYPE_FIGHTING,
		0, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_USER,
		3, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_KNOCHENHATZ
	{
		0x1d, //Effect-id (in table)
		25, //Base Power
		TYPE_GROUND,
		80, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ZIELSCHUSS
	{
		0x5e, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_WUTANFALL
	{
		0x1b, //Effect-id (in table)
		120, //Base Power
		TYPE_DRAGON,
		100, //Accuracy
		15, //PP
		100, //Effect accuracy
		RANDOM_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SANDSTURM
	{
		0x73, //Effect-id (in table)
		0, //Base Power
		TYPE_ROCK,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_GIGASAUGER
	{
		0x3, //Effect-id (in table)
		60, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_AUSDAUER
	{
		0x74, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		3, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_CHARME
	{
		0x3a, //Effect-id (in table)
		0, //Base Power
		TYPE_FAIRY,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_WALZER
	{
		0x75, //Effect-id (in table)
		30, //Base Power
		TYPE_ROCK,
		90, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_TRUGSCHLAG
	{
		0x65, //Effect-id (in table)
		40, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		40, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ANGEBEREI
	{
		0x76, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		90, //Accuracy
		15, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_MILCHGETRAENK
	{
		0x9d, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_FUNKENSPRUNG
	{
		0x6, //Effect-id (in table)
		65, //Base Power
		TYPE_ELECTRIC,
		100, //Accuracy
		20, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ZORNKLINGE
	{
		0x2b, //Effect-id (in table)
		85, //Base Power
		TYPE_BUG,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_STAHLFLUEGEL
	{
		0x8a, //Effect-id (in table)
		70, //Base Power
		TYPE_STEEL,
		90, //Accuracy
		25, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_HORRORBLICK
	{
		0x6a, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_ANZIEHUNG
	{
		0x78, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SCHLAFREDE
	{
		0x61, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_DEPENDS_ON_ATTACK,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_VITALGLOCKE
	{
		0x66, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_RUECKKEHR
	{
		0x79, //Effect-id (in table)
		1, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_GESCHENK
	{
		0x7a, //Effect-id (in table)
		1, //Base Power
		TYPE_NORMAL,
		90, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_FRUSTRATION
	{
		0x7b, //Effect-id (in table)
		1, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_BODYGUARD
	{
		0x7c, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		25, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_LEIDTEILER
	{
		0x5b, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_LAEUTERFEUER
	{
		0x7d, //Effect-id (in table)
		100, //Base Power
		TYPE_FIRE,
		95, //Accuracy
		5, //PP
		50, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_INTENSITAET
	{
		0x7e, //Effect-id (in table)
		1, //Base Power
		TYPE_GROUND,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES_AND_PARTNER,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_WUCHTSCHLAG
	{
		0xb6, //Effect-id (in table)
		120, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		5, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_VIELENDER
	{
		0x0, //Effect-id (in table)
		120, //Base Power
		TYPE_BUG,
		85, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FEUERODEM
	{
		0x6, //Effect-id (in table)
		60, //Base Power
		TYPE_DRAGON,
		100, //Accuracy
		20, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_STAFFETTE
	{
		0x7f, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		40, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_ZUGABE
	{
		0x5a, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_VERFOLGUNG
	{
		0x80, //Effect-id (in table)
		40, //Base Power
		TYPE_DARK,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_TURBODREHER
	{
		0x81, //Effect-id (in table)
		20, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		40, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_LOCKDUFT
	{
		0x18, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_EISENSCHWEIF
	{
		0x45, //Effect-id (in table)
		100, //Base Power
		TYPE_STEEL,
		75, //Accuracy
		15, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_METALLKLAUE
	{
		0x8b, //Effect-id (in table)
		50, //Base Power
		TYPE_STEEL,
		95, //Accuracy
		35, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_UEBERWURF
	{
		0x4e, //Effect-id (in table)
		70, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		-1, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_MORGENGRAUEN
	{
		0x84, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SYNTHESE
	{
		0x85, //Effect-id (in table)
		0, //Base Power
		TYPE_GRASS,
		0, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_MONDSCHEIN
	{
		0x86, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_INNERE_KRAFT
	{
		0x1d, //Effect-id (in table)
		15, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_KREUZHIEB
	{
		0x2b, //Effect-id (in table)
		100, //Base Power
		TYPE_FIGHTING,
		80, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_WINDHOSE
	{
		0x92, //Effect-id (in table)
		40, //Base Power
		TYPE_DRAGON,
		100, //Accuracy
		20, //PP
		20, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_REGENTANZ
	{
		0x88, //Effect-id (in table)
		0, //Base Power
		TYPE_WATER,
		0, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SONNENTAG
	{
		0x89, //Effect-id (in table)
		0, //Base Power
		TYPE_FIRE,
		0, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_KNIRSCHER
	{
		0x48, //Effect-id (in table)
		80, //Base Power
		TYPE_DARK,
		100, //Accuracy
		15, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FOKUSWELLE
	{
		0x0, //Effect-id (in table)
		75, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_PSYCHO_PLUS
	{
		0x8f, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_TURBOTEMPO
	{
		0x67, //Effect-id (in table)
		80, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		1, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ANTIK_KRAFT
	{
		0x8c, //Effect-id (in table)
		60, //Base Power
		TYPE_ROCK,
		100, //Accuracy
		5, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SPUKBALL
	{
		0x48, //Effect-id (in table)
		80, //Base Power
		TYPE_GHOST,
		100, //Accuracy
		15, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SEHER
	{
		0x94, //Effect-id (in table)
		80, //Base Power
		TYPE_PSYCHIC,
		90, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_ZERTRUEMMERER
	{
		0x2b, //Effect-id (in table)
		85, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		15, //PP
		50, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_WHIRLPOOL
	{
		0x2a, //Effect-id (in table)
		15, //Base Power
		TYPE_WATER,
		70, //Accuracy
		15, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_PRUEGLER
	{
		0x9a, //Effect-id (in table)
		10, //Base Power
		TYPE_DARK,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_MOGELHIEB
	{
		0x9e, //Effect-id (in table)
		40, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		1, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_AUFRUHR
	{
		0x9f, //Effect-id (in table)
		50, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		100, //Effect accuracy
		RANDOM_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_HORTER
	{
		0xa0, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_ENTFESSLER
	{
		0xa1, //Effect-id (in table)
		100, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_VERZEHRER
	{
		0xa2, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_HITZEWELLE
	{
		0x4, //Effect-id (in table)
		100, //Base Power
		TYPE_FIRE,
		90, //Accuracy
		10, //PP
		10, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_HAGELSTURM
	{
		0xa4, //Effect-id (in table)
		0, //Base Power
		TYPE_ICE,
		0, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_PROTECT,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_FOLTERKNECHT
	{
		0xa5, //Effect-id (in table)
		0, //Base Power
		TYPE_DARK,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SCHMEICHLER
	{
		0xa6, //Effect-id (in table)
		0, //Base Power
		TYPE_DARK,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_IRRLICHT
	{
		0xa7, //Effect-id (in table)
		0, //Base Power
		TYPE_FIRE,
		75, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_MEMENTO_MORI
	{
		0xa8, //Effect-id (in table)
		0, //Base Power
		TYPE_DARK,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_FASSADE
	{
		0x4c, //Effect-id (in table)
		90, //Base Power
		TYPE_NORMAL,
		85, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_POWER_PUNCH
	{
		0xaa, //Effect-id (in table)
		150, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		-3, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_RIECHSALZ
	{
		0xab, //Effect-id (in table)
		60, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SPOTLIGHT
	{
		0xac, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		3, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_NATUR_KRAFT
	{
		0xad, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_DEPENDS_ON_ATTACK,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_LADEVORGANG
	{
		0xae, //Effect-id (in table)
		0, //Base Power
		TYPE_ELECTRIC,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_VERHOEHNER
	{
		0xaf, //Effect-id (in table)
		0, //Base Power
		TYPE_DARK,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_RECHTE_HAND
	{
		0xb0, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		5, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_TRICKBETRUG
	{
		0xb1, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_ROLLENTAUSCH
	{
		0xb2, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_WUNSCHTRAUM
	{
		0xb3, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_PROTECT,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_ZUSCHUSS
	{
		0xb4, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_DEPENDS_ON_ATTACK,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_VERWURZLER
	{
		0xb5, //Effect-id (in table)
		0, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_KRAFTKOLOSS
	{
		0xb6, //Effect-id (in table)
		120, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_MAGIEMANTEL
	{
		0xb7, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		TARGET_DEPENDS_ON_ATTACK,
		4, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_AUFBEREITUNG
	{
		0xb8, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_VERGELTUNG
	{
		0xb9, //Effect-id (in table)
		60, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		-4, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_DURCHBRUCH
	{
		0xba, //Effect-id (in table)
		75, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_GAEHNER
	{
		0xbb, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_ABSCHLAG
	{
		0xbc, //Effect-id (in table)
		20, //Base Power
		TYPE_DARK,
		100, //Accuracy
		20, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_NOTSITUATION
	{
		0xbd, //Effect-id (in table)
		1, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ERUPTION
	{
		0xbe, //Effect-id (in table)
		150, //Base Power
		TYPE_FIRE,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_WERTWECHSEL
	{
		0xbf, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_BEGRENZER
	{
		0xc0, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_PROTECT,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_HEILUNG
	{
		0xc1, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_NACHSPIEL
	{
		0xc2, //Effect-id (in table)
		0, //Base Power
		TYPE_GHOST,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_UEBERNAHME
	{
		0xc3, //Effect-id (in table)
		0, //Base Power
		TYPE_DARK,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_DEPENDS_ON_ATTACK,
		4, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_GEHEIMPOWER
	{
		0xc5, //Effect-id (in table)
		70, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_TAUCHER
	{
		0x0, //Effect-id (in table)
		95, //Base Power
		TYPE_WATER,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ARMSTOSS
	{
		0x1d, //Effect-id (in table)
		15, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_TARNUNG
	{
		0xd5, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SCHWEIFGLANZ
	{
		0x35, //Effect-id (in table)
		0, //Base Power
		TYPE_BUG,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SCHEINWERFER
	{
		0x48, //Effect-id (in table)
		70, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		5, //PP
		50, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_NEBELBALL
	{
		0x47, //Effect-id (in table)
		70, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		5, //PP
		50, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_DAUNENREIGEN
	{
		0x3a, //Effect-id (in table)
		0, //Base Power
		TYPE_FLYING,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_TAUMELTANZ
	{
		0xc7, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES_AND_PARTNER,
		0, //Priority
		AFFECTED_BY_PROTECT,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_FEUERFEGER
	{
		0xc8, //Effect-id (in table)
		85, //Base Power
		TYPE_FIRE,
		90, //Accuracy
		10, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_LEHMSUHLER
	{
		0xc9, //Effect-id (in table)
		0, //Base Power
		TYPE_GROUND,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_FROSTBEULE
	{
		0x75, //Effect-id (in table)
		30, //Base Power
		TYPE_ICE,
		90, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_NIETENRANKE
	{
		0x96, //Effect-id (in table)
		60, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		15, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_TAGEDIEB
	{
		0x20, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SCHALLWELLE
	{
		0x0, //Effect-id (in table)
		90, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_GIFTZAHN
	{
		0xca, //Effect-id (in table)
		50, //Base Power
		TYPE_POISON,
		100, //Accuracy
		15, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ZERMALMKLAUE
	{
		0x45, //Effect-id (in table)
		75, //Base Power
		TYPE_NORMAL,
		95, //Accuracy
		10, //PP
		50, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_LOHEKANONADE
	{
		0x50, //Effect-id (in table)
		150, //Base Power
		TYPE_FIRE,
		90, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_AQUAHAUBITZE
	{
		0x50, //Effect-id (in table)
		150, //Base Power
		TYPE_WATER,
		90, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_STERNHIEB
	{
		0x8b, //Effect-id (in table)
		100, //Base Power
		TYPE_STEEL,
		85, //Accuracy
		10, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ERSTAUNER
	{
		0x96, //Effect-id (in table)
		30, //Base Power
		TYPE_GHOST,
		100, //Accuracy
		15, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_METEOROLOGE
	{
		0xcb, //Effect-id (in table)
		50, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_AROMAKUR
	{
		0x66, //Effect-id (in table)
		0, //Base Power
		TYPE_GRASS,
		0, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_TRUGTRAENE
	{
		0x3e, //Effect-id (in table)
		0, //Base Power
		TYPE_DARK,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_WINDSCHNITT
	{
		0x2b, //Effect-id (in table)
		55, //Base Power
		TYPE_FLYING,
		95, //Accuracy
		25, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_HITZEKOLLER
	{
		0xcc, //Effect-id (in table)
		140, //Base Power
		TYPE_FIRE,
		90, //Accuracy
		5, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SCHNUEFFLER
	{
		0x71, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		40, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_FELSGRAB
	{
		0x46, //Effect-id (in table)
		50, //Base Power
		TYPE_ROCK,
		80, //Accuracy
		10, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SILBERHAUCH
	{
		0x8c, //Effect-id (in table)
		60, //Base Power
		TYPE_BUG,
		100, //Accuracy
		5, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_METALLSOUND
	{
		0x3e, //Effect-id (in table)
		0, //Base Power
		TYPE_STEEL,
		85, //Accuracy
		40, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_GRASFLOETE
	{
		0x1, //Effect-id (in table)
		0, //Base Power
		TYPE_GRASS,
		55, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SPASSKANONE
	{
		0xcd, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_KOSMIK_KRAFT
	{
		0xce, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_FONTRAENEN
	{
		0xbe, //Effect-id (in table)
		150, //Base Power
		TYPE_WATER,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_AMPELLEUCHTE
	{
		0x4c, //Effect-id (in table)
		75, //Base Power
		TYPE_BUG,
		100, //Accuracy
		15, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_FINSTERFAUST
	{
		0x11, //Effect-id (in table)
		60, //Base Power
		TYPE_GHOST,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SONDERSENSOR
	{
		0x96, //Effect-id (in table)
		80, //Base Power
		TYPE_PSYCHIC,
		100, //Accuracy
		30, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_HIMMELHIEB
	{
		0xcf, //Effect-id (in table)
		85, //Base Power
		TYPE_FIGHTING,
		90, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SANDGRAB
	{
		0x2a, //Effect-id (in table)
		15, //Base Power
		TYPE_GROUND,
		70, //Accuracy
		15, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_EISESKAELTE
	{
		0x26, //Effect-id (in table)
		1, //Base Power
		TYPE_ICE,
		30, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_LEHMBRUEHE
	{
		0x49, //Effect-id (in table)
		95, //Base Power
		TYPE_WATER,
		85, //Accuracy
		10, //PP
		30, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_KUGELSAAT
	{
		0x1d, //Effect-id (in table)
		15, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_AERO_ASS
	{
		0x11, //Effect-id (in table)
		60, //Base Power
		TYPE_FLYING,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_EISSPEER
	{
		0x1d, //Effect-id (in table)
		10, //Base Power
		TYPE_ICE,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_EISENABWEHR
	{
		0x33, //Effect-id (in table)
		0, //Base Power
		TYPE_STEEL,
		0, //Accuracy
		15, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_RUECKENTZUG
	{
		0x6a, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_JAULER
	{
		0xa, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		40, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_DRACHENKLAUE
	{
		0x0, //Effect-id (in table)
		80, //Base Power
		TYPE_DRAGON,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FAUNA_STATUE
	{
		0x50, //Effect-id (in table)
		150, //Base Power
		TYPE_GRASS,
		90, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_PROTZER
	{
		0xd0, //Effect-id (in table)
		0, //Base Power
		TYPE_FIGHTING,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_SPRUNGFEDER
	{
		0x9b, //Effect-id (in table)
		85, //Base Power
		TYPE_FLYING,
		85, //Accuracy
		5, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_LEHMSCHUSS
	{
		0x46, //Effect-id (in table)
		55, //Base Power
		TYPE_GROUND,
		95, //Accuracy
		15, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_GIFTSCHWEIF
	{
		0xd1, //Effect-id (in table)
		50, //Base Power
		TYPE_POISON,
		100, //Accuracy
		25, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_BEZIRZER
	{
		0x69, //Effect-id (in table)
		40, //Base Power
		TYPE_NORMAL,
		100, //Accuracy
		40, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_VOLTTACKLE
	{
		0xc6, //Effect-id (in table)
		120, //Base Power
		TYPE_ELECTRIC,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ZAUBERBLATT
	{
		0x11, //Effect-id (in table)
		60, //Base Power
		TYPE_GRASS,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_NASSMACHER
	{
		0xd2, //Effect-id (in table)
		0, //Base Power
		TYPE_WATER,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_GEDANKENGUT
	{
		0xd3, //Effect-id (in table)
		0, //Base Power
		TYPE_PSYCHIC,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_LAUBKLINGE
	{
		0x2b, //Effect-id (in table)
		70, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_DRACHENTANZ
	{
		0xd4, //Effect-id (in table)
		0, //Base Power
		TYPE_DRAGON,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_FELSWURF
	{
		0x1d, //Effect-id (in table)
		25, //Base Power
		TYPE_ROCK,
		80, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SCHOCKWELLE
	{
		0x11, //Effect-id (in table)
		60, //Base Power
		TYPE_ELECTRIC,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_AQUAWELLE
	{
		0x4c, //Effect-id (in table)
		60, //Base Power
		TYPE_WATER,
		100, //Accuracy
		20, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_KISMETWUNSCH
	{
		0x94, //Effect-id (in table)
		120, //Base Power
		TYPE_STEEL,
		85, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_PSYSCHUB
	{
		0xcc, //Effect-id (in table)
		140, //Base Power
		TYPE_PSYCHIC,
		90, //Accuracy
		5, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_FILLER
	{
		0x0, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		0, //Accuracy
		0, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		0,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_HAMMERARM
	{
		0xdd, //Effect-id (in table)
		100, //Base Power
		TYPE_FIGHTING,
		90, //Accuracy
		10, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_AURASPHAERE
	{
		0x11, //Effect-id (in table)
		90, //Base Power
		TYPE_FIGHTING,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_GIFTHIEB
	{
		0x2, //Effect-id (in table)
		80, //Base Power
		TYPE_POISON,
		100, //Accuracy
		20, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FOKUSSTOSS
	{
		0x16, //Effect-id (in table)
		120, //Base Power
		TYPE_FIGHTING,
		70, //Accuracy
		5, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_PATRONENHIEB
	{
		0x67, //Effect-id (in table)
		40, //Base Power
		TYPE_STEEL,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		1, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FINSTERAURA
	{
		0x1f, //Effect-id (in table)
		80, //Base Power
		TYPE_DARK,
		100, //Accuracy
		15, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_FLAMMENBLITZ
	{
		0xd9, //Effect-id (in table)
		120, //Base Power
		TYPE_FIRE,
		100, //Accuracy
		15, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_EISZAHN
	{
		0xda, //Effect-id (in table)
		65, //Base Power
		TYPE_ICE,
		95, //Accuracy
		15, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_DONNERZAHN
	{
		0xdb, //Effect-id (in table)
		65, //Base Power
		TYPE_ELECTRIC,
		95, //Accuracy
		15, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_DUNKELKLAUE
	{
		0x2b, //Effect-id (in table)
		70, //Base Power
		TYPE_DARK,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KREUZSCHERE
	{
		0x0, //Effect-id (in table)
		80, //Base Power
		TYPE_BUG,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_STEINKANTE
	{
		0x2b, //Effect-id (in table)
		100, //Base Power
		TYPE_ROCK,
		80, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_STURZFLUG
	{
		0xc6, //Effect-id (in table)
		120, //Base Power
		TYPE_FLYING,
		100, //Accuracy
		15, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_STEINPOLITUR
	{
		0x34, //Effect-id (in table)
		0, //Base Power
		TYPE_ROCK,
		0, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_SNATCH,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_KRAXLER
	{
		0x1f, //Effect-id (in table)
		90, //Base Power
		TYPE_ROCK,
		85, //Accuracy
		20, //PP
		33, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_BLAETTERSTURM
	{
		0xcc, //Effect-id (in table)
		140, //Base Power
		TYPE_GRASS,
		90, //Accuracy
		5, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_NAHKAMPF
	{
		0xde, //Effect-id (in table)
		120, //Base Power
		TYPE_FIGHTING,
		100, //Accuracy
		5, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_LICHTKANONE
	{
		0x16, //Effect-id (in table)
		80, //Base Power
		TYPE_STEEL,
		100, //Accuracy
		10, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		-6, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_DRACO_METEOR
	{
		0xcc, //Effect-id (in table)
		140, //Base Power
		TYPE_DRAGON,
		90, //Accuracy
		5, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_NASSCHWEIF
	{
		0x0, //Effect-id (in table)
		90, //Base Power
		TYPE_WATER,
		90, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ZEN_KOPFSTOSS
	{
		0x1f, //Effect-id (in table)
		80, //Base Power
		TYPE_PSYCHIC,
		90, //Accuracy
		15, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ENERGIEBALL
	{
		0x16, //Effect-id (in table)
		80, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		10, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SCHATTENSTOSS
	{
		0x67, //Effect-id (in table)
		40, //Base Power
		TYPE_GHOST,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		1, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_DOPPELSCHLAG
	{
		0x2c, //Effect-id (in table)
		35, //Base Power
		TYPE_NORMAL,
		90, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_TIEFSCHLAG
	{
		0x67, //Effect-id (in table)
		80, //Base Power
		TYPE_DARK,
		100, //Accuracy
		5, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		1, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_NACHTHIEB
	{
		0x2b, //Effect-id (in table)
		70, //Base Power
		TYPE_DARK,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SAMENBOMBE
	{
		0x0, //Effect-id (in table)
		80, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ERDKRAEFTE
	{
		0x16, //Effect-id (in table)
		90, //Base Power
		TYPE_GROUND,
		100, //Accuracy
		10, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_DRACHENPULS
	{
		0x0, //Effect-id (in table)
		90, //Base Power
		TYPE_DRAGON,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_EISSPLITTER
	{
		0x67, //Effect-id (in table)
		40, //Base Power
		TYPE_ICE,
		100, //Accuracy
		30, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		1, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FEUERZAHN
	{
		0xdc, //Effect-id (in table)
		65, //Base Power
		TYPE_FIRE,
		95, //Accuracy
		15, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_WASSERDUESE
	{
		0x67, //Effect-id (in table)
		40, //Base Power
		TYPE_WATER,
		100, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		1, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_ZORNFEUER
	{
		104, //Effect-id (in table)
		35, //Base Power
		TYPE_FIRE,
		90, //Accuracy
		20, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_TSUNAMI
	{
		0x2b, //Effect-id (in table)
		115, //Base Power
		TYPE_WATER,
		80, //Accuracy
		15, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_STAHLSTREICH
	{
		0xe0, //Effect-id (in table)
		85, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		20, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KINESISWELLE
	{
		0x50, //Effect-id (in table)
		250, //Base Power
		TYPE_PSYCHIC,
		85, //Accuracy
		20, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SUPERNOVA
	{
		4, //Effect-id (in table)
		70, //Base Power
		TYPE_FIRE,
		90, //Accuracy
		15, //PP
		100, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_WASSERSPALT
	{
		76, //Effect-id (in table)
		115, //Base Power
		TYPE_WATER,
		100, //Accuracy
		5, //PP
		25, //Effect accuracy
		RANDOM_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SCHALLSTICH
	{
		0x67, //Effect-id (in table)
		75, //Base Power
		TYPE_STEEL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		1, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_DIEBESKUSS
	{
		0x3, //Effect-id (in table)
		50, //Base Power
		TYPE_FAIRY,
		100, //Accuracy
		35, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KNUDDLER
	{
		0x0, //Effect-id (in table)
		90, //Base Power
		TYPE_FAIRY,
		90, //Accuracy
		10, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_MONDGEWALT
	{
		0x0, //Effect-id (in table)
		95, //Base Power
		TYPE_FAIRY,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_ZAUBERSCHEIN
	{
		0x0, //Effect-id (in table)
		80, //Base Power
		TYPE_FAIRY,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_SAEUSELSTIMME
	{
		0x0, //Effect-id (in table)
		40, //Base Power
		TYPE_FAIRY,
		100, //Accuracy
		15, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_BIENENSTICH
	{
		0x2, //Effect-id (in table)
		75, //Base Power
		TYPE_BUG,
		100, //Accuracy
		40, //PP
		50, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_SCHWARMSTICH
	{
		0x1d, //Effect-id (in table)
		20, //Base Power
		TYPE_POISON,
		100, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_GESANG_2
	{
		0x1, //Effect-id (in table)
		0, //Base Power
		TYPE_NORMAL,
		55, //Accuracy
		15, //PP
		0, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_HEISSSTEIN
	{
		0x4, //Effect-id (in table)
		95, //Base Power
		TYPE_FIRE,
		85, //Accuracy
		20, //PP
		40, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_MAGIC_COAT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_GEWITTER
	{
		0x6, //Effect-id (in table)
		100, //Base Power
		TYPE_ELECTRIC,
		100, //Accuracy
		10, //PP
		20, //Effect accuracy
		TARGET_BOTH_FOES_AND_PARTNER,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_EISENSLAM
	{
		0x1f, //Effect-id (in table)
		85, //Base Power
		TYPE_STEEL,
		95, //Accuracy
		15, //PP
		20, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_HOLZGEWEIH
	{
		0x3, //Effect-id (in table)
		75, //Base Power
		TYPE_GRASS,
		100, //Accuracy
		30, //PP
		10, //Effect accuracy
		TARGET_BOTH_FOES,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_KAEFERBISS
	{
		0x4, //Effect-id (in table)
		60, //Base Power
		TYPE_FIRE,
		100, //Accuracy
		25, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		MAKES_CONTACT | AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_PHYSICAL,
		0x0 //Padding
	},
	// ATTACK_FALTERREIGEN
	{
		0xe1, //Effect-id (in table)
		95, //Base Power
		TYPE_BUG,
		100, //Accuracy
		15, //PP
		10, //Effect accuracy
		TARGET_USER,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	},
	// ATTACK_NITROLADUNG
	{
		0xe2, //Effect-id (in table)
		40, //Base Power
		TYPE_FIRE,
		100, //Accuracy
		20, //PP
		100, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | AFFECTED_BY_SNATCH | MIRRORABLE,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_KAEFERGEBRUMM
	{
		0x16, //Effect-id (in table)
		90, //Base Power
		TYPE_BUG,
		100, //Accuracy
		10, //PP
		10, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_TORNADO
	{
		0x4c, //Effect-id (in table)
		120, //Base Power
		TYPE_FLYING,
		70, //Accuracy
		10, //PP
		30, //Effect accuracy
		SELECTED_TARGET,
		0, //Priority
		AFFECTED_BY_PROTECT | MIRRORABLE | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_SPECIAL,
		0x0 //Padding
	},
	// ATTACK_KOENIGSSCHILD
	{
		0x6f, //Effect-id (in table)
		0, //Base Power
		TYPE_STEEL,
		100, //Accuracy
		10, //PP
		0, //Effect accuracy
		TARGET_USER,
		3, //Priority
		AFFECTED_BY_PROTECT | TRIGGERS_KINGS_ROCK,
		0x0, //Effect table
		CATEGORY_STATUS,
		0x0 //Padding
	}
    
};