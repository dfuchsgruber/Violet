#include "types.h"
#include "trainer.h"
#include "stdbool.h"
#include "basestats.h"
#include "item.h"
#include "attack.h"
#include "pstring.h"


trainer trainers [TRAINER_CNT] = {
{
	//Trainer 0x0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x0
},{
	//Trainer 0x1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_STREBER,
	{0x3, false},//Encounter and gender
	0x1d,//sprite
	{PCHAR_A, PCHAR_n, PCHAR_d, PCHAR_r, PCHAR_e, PCHAR_a, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1
},{
	//Trainer 0x2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x6, false},//Encounter and gender
	0x24,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_x, PCHAR_i, PCHAR_m, PCHAR_i, PCHAR_l, PCHAR_i, PCHAR_a, PCHAR_n, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2
},{
	//Trainer 0x3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHNOESEL,
	{0x6, false},//Encounter and gender
	0xd,//sprite
	{PCHAR_H, PCHAR_o, PCHAR_l, PCHAR_g, PCHAR_e, PCHAR_r, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x3
},{
	//Trainer 0x4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x3, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_H, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x4
},{
	//Trainer 0x5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER,
	{0xd, false},//Encounter and gender
	0x24,//sprite
	{PCHAR_P, PCHAR_e, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x5
},{
	//Trainer 0x6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x3, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_B, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x6
},{
	//Trainer 0x7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY,
	{0x2, true},//Encounter and gender
	0x3,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_r, PCHAR_l, PCHAR_e, PCHAR_e, PCHAR_n, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x7
},{
	//Trainer 0x8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_R, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x8
},{
	//Trainer 0x9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY,
	{0x5, false},//Encounter and gender
	0x3,//sprite
	{PCHAR_Y, PCHAR_s, PCHAR_a, PCHAR_b, PCHAR_e, PCHAR_l, PCHAR_l, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x9
},{
	//Trainer 0xa
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MECHANIKER,
	{0x5, false},//Encounter and gender
	0x5d,//sprite
	{PCHAR_X, PCHAR_a, PCHAR_v, PCHAR_e, PCHAR_r, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xa
},{
	//Trainer 0xb
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0x3, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_H, PCHAR_e, PCHAR_n, PCHAR_r, PCHAR_i, PCHAR_c, PCHAR_k, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xb
},{
	//Trainer 0xc
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER,
	{0x1, false},//Encounter and gender
	0x13,//sprite
	{PCHAR_T, PCHAR_r, PCHAR_i, PCHAR_s, PCHAR_t, PCHAR_a, PCHAR_y, PCHAR_n, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xc
},{
	//Trainer 0xd
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT,
	{0x1, false},//Encounter and gender
	0xc,//sprite
	{PCHAR_R, PCHAR_o, PCHAR_s, PCHAR_a, PCHAR_n, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xd
},{
	//Trainer 0xe
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT,
	{0xd, false},//Encounter and gender
	0x10,//sprite
	{PCHAR_R, PCHAR_i, PCHAR_c, PCHAR_k, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xe
},{
	//Trainer 0xf
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER,
	{0x3, false},//Encounter and gender
	0x3d,//sprite
	{PCHAR_J, PCHAR_a, PCHAR_n, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xf
},{
	//Trainer 0x10
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY,
	{0x1, false},//Encounter and gender
	0x3,//sprite
	{PCHAR_J, PCHAR_o, PCHAR_h, PCHAR_a, PCHAR_n, PCHAR_n, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x10
},{
	//Trainer 0x11
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT,
	{0x4, false},//Encounter and gender
	0x10,//sprite
	{PCHAR_L, PCHAR_u, PCHAR_c, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x11
},{
	//Trainer 0x12
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0x4, false},//Encounter and gender
	0x43,//sprite
	{PCHAR_W, PCHAR_i, PCHAR_l, PCHAR_l, PCHAR_a, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x12
},{
	//Trainer 0x13
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER,
	{0xb, false},//Encounter and gender
	0x42,//sprite
	{PCHAR_J, PCHAR_o, PCHAR_h, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x13
},{
	//Trainer 0x14
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_LADY,
	{0x0, false},//Encounter and gender
	0xb,//sprite
	{PCHAR_E, PCHAR_m, PCHAR_i, PCHAR_l, PCHAR_y, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x14
},{
	//Trainer 0x15
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE,
	{0x3, false},//Encounter and gender
	0x41,//sprite
	{PCHAR_S, PCHAR_a, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_n, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x15
},{
	//Trainer 0x16
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER,
	{0x4, false},//Encounter and gender
	0x2e,//sprite
	{PCHAR_A, PCHAR_l, PCHAR_e, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x16
},{
	//Trainer 0x17
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO,
	{0x4, false},//Encounter and gender
	0x16,//sprite
	{PCHAR_C, PCHAR_a, PCHAR_s, PCHAR_s, PCHAR_a, PCHAR_n, PCHAR_d, PCHAR_r, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x17
},{
	//Trainer 0x18
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER,
	{0xd, false},//Encounter and gender
	0x2e,//sprite
	{PCHAR_V, PCHAR_a, PCHAR_l, PCHAR_e, PCHAR_n, PCHAR_t, PCHAR_i, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x18
},{
	//Trainer 0x19
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_POLIZIST,
	{0xa, false},//Encounter and gender
	0x0,//sprite
	{PCHAR_H, PCHAR_a, PCHAR_r, PCHAR_r, PCHAR_e, PCHAR_n, PCHAR_f, PCHAR_e, PCHAR_l, PCHAR_d, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x19
},{
	//Trainer 0x1a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_POKEMANIAC,
	{0xa, false},//Encounter and gender
	0x20,//sprite
	{PCHAR_A, PCHAR_n, PCHAR_t, PCHAR_o, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1a
},{
	//Trainer 0x1b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY,
	{0x1, false},//Encounter and gender
	0x3,//sprite
	{PCHAR_F, PCHAR_e, PCHAR_l, PCHAR_i, PCHAR_z, PCHAR_i, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1b
},{
	//Trainer 0x1c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER,
	{0x0, false},//Encounter and gender
	0x26,//sprite
	{PCHAR_K, PCHAR_a, PCHAR_m, PCHAR_i, PCHAR_l, PCHAR_l, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1c
},{
	//Trainer 0x1d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER,
	{0x1, false},//Encounter and gender
	0x26,//sprite
	{PCHAR_B, PCHAR_e, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1d
},{
	//Trainer 0x1e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXPERTE,
	{0x0, true},//Encounter and gender
	0x23,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_r, PCHAR_t, PCHAR_h, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1e
},{
	//Trainer 0x1f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHULKIND,
	{0x0, false},//Encounter and gender
	0x1e,//sprite
	{PCHAR_C, PCHAR_h, PCHAR_a, PCHAR_n, PCHAR_t, PCHAR_a, PCHAR_l, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1f
},{
	//Trainer 0x20
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER,
	{0x9, false},//Encounter and gender
	0x26,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_r, PCHAR_i, PCHAR_u, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x20
},{
	//Trainer 0x21
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER,
	{0x9, false},//Encounter and gender
	0x26,//sprite
	{PCHAR_N, PCHAR_i, PCHAR_l, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x21
},{
	//Trainer 0x22
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_NINJAJUNGE,
	{0x9, false},//Encounter and gender
	0x2f,//sprite
	{PCHAR_K, PCHAR_e, PCHAR_v, PCHAR_i, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x22
},{
	//Trainer 0x23
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x4, false},//Encounter and gender
	0x9,//sprite
	{PCHAR_S, PCHAR_e, PCHAR_r, PCHAR_e, PCHAR_n, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x23
},{
	//Trainer 0x24
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TRIATHLET,
	{0x4, false},//Encounter and gender
	0x2a,//sprite
	{PCHAR_N, PCHAR_y, PCHAR_o, PCHAR_m, PCHAR_s, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x24
},{
	//Trainer 0x25
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER,
	{0x0, false},//Encounter and gender
	0x24,//sprite
	{PCHAR_T, PCHAR_i, PCHAR_n, PCHAR_o, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x25
},{
	//Trainer 0x26
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DIEB,
	{0x0, false},//Encounter and gender
	0x5c,//sprite
	{PCHAR_S, PCHAR_t, PCHAR_e, PCHAR_f, PCHAR_f, PCHAR_e, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x26
},{
	//Trainer 0x27
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER,
	{0xb, false},//Encounter and gender
	0x2e,//sprite
	{PCHAR_E, PCHAR_r, PCHAR_n, PCHAR_e, PCHAR_s, PCHAR_t, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x27
},{
	//Trainer 0x28
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_Y, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x28
},{
	//Trainer 0x29
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x0, true},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_k, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x29
},{
	//Trainer 0x2a
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x1, true},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_k, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2a
},{
	//Trainer 0x2b
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x1, true},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_k, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2b
},{
	//Trainer 0x2c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_POLIZIST,
	{0x1, false},//Encounter and gender
	0x0,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_r, PCHAR_q, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2c
},{
	//Trainer 0x2d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ROCKER,
	{0x1, false},//Encounter and gender
	0x11,//sprite
	{PCHAR_U, PCHAR_d, PCHAR_o, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2d
},{
	//Trainer 0x2e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY,
	{0x4, true},//Encounter and gender
	0x3,//sprite
	{PCHAR_A, PCHAR_n, PCHAR_n, PCHAR_i, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2e
},{
	//Trainer 0x2f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0x2, true},//Encounter and gender
	0x17,//sprite
	{PCHAR_J, PCHAR_o, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_i, PCHAR_m, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2f
},{
	//Trainer 0x30
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER,
	{0x2, false},//Encounter and gender
	0x33,//sprite
	{PCHAR_L, PCHAR_o, PCHAR_b, PCHAR_i, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x30
},{
	//Trainer 0x31
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEMPFERIN,
	{0x4, false},//Encounter and gender
	0x30,//sprite
	{PCHAR_R, PCHAR_a, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x31
},{
	//Trainer 0x32
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0x1, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_A, PCHAR_l, PCHAR_o, PCHAR_i, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x32
},{
	//Trainer 0x33
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TRIATHLET,
	{0x1, false},//Encounter and gender
	0x29,//sprite
	{PCHAR_S, PCHAR_e, PCHAR_y, PCHAR_m, PCHAR_o, PCHAR_u, PCHAR_r, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x33
},{
	//Trainer 0x34
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x1, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_N, PCHAR_e, PCHAR_d, PCHAR_d, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x34
},{
	//Trainer 0x35
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT,
	{0x1, false},//Encounter and gender
	0x62,//sprite
	{PCHAR_A, PCHAR_n, PCHAR_d, PCHAR_r, PCHAR_e, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x35
},{
	//Trainer 0x36
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY,
	{0x0, false},//Encounter and gender
	0x3,//sprite
	{PCHAR_J, PCHAR_e, PCHAR_y, PCHAR_n, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x36
},{
	//Trainer 0x37
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x24,//sprite
	{PCHAR_P, PCHAR_h, PCHAR_y, PCHAR_l, PCHAR_l, PCHAR_i, PCHAR_p, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x37
},{
	//Trainer 0x38
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_ZUECHTER,
	{0x0, true},//Encounter and gender
	0x3b,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_r, PCHAR_a, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x38
},{
	//Trainer 0x39
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER,
	{0x3, true},//Encounter and gender
	0x33,//sprite
	{PCHAR_E, PCHAR_l, PCHAR_i, PCHAR_o, PCHAR_t, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x39
},{
	//Trainer 0x3a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE2,
	{0x0, false},//Encounter and gender
	0x54,//sprite
	{PCHAR_C, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_l, PCHAR_i, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x3a
},{
	//Trainer 0x3b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x1, false},//Encounter and gender
	0x8,//sprite
	{PCHAR_L, PCHAR_e, PCHAR_o, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x3b
},{
	//Trainer 0x3c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TRIATHLET,
	{0x0, false},//Encounter and gender
	0x2a,//sprite
	{PCHAR_G, PCHAR_e, PCHAR_r, PCHAR_d, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x3c
},{
	//Trainer 0x3d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER,
	{0x0, false},//Encounter and gender
	0x33,//sprite
	{PCHAR_L, PCHAR_o, PCHAR_r, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x3d
},{
	//Trainer 0x3e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x1, false},//Encounter and gender
	0x24,//sprite
	{PCHAR_J, PCHAR_e, PCHAR_f, PCHAR_f, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x3e
},{
	//Trainer 0x3f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER3,
	{0x1, false},//Encounter and gender
	0x13,//sprite
	{PCHAR_M, PCHAR_i, PCHAR_g, PCHAR_u, PCHAR_e, PCHAR_l, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x3f
},{
	//Trainer 0x40
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_ZUECHTER,
	{0x1, true},//Encounter and gender
	0x3b,//sprite
	{PCHAR_I, PCHAR_s, PCHAR_m, PCHAR_e, PCHAR_r, PCHAR_a, PCHAR_l, PCHAR_d, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x40
},{
	//Trainer 0x41
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x24,//sprite
	{PCHAR_R, PCHAR_o, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_t, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x41
},{
	//Trainer 0x42
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER,
	{0x1, true},//Encounter and gender
	0x5e,//sprite
	{PCHAR_A, PCHAR_l, PCHAR_e, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x42
},{
	//Trainer 0x43
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER,
	{0x5, true},//Encounter and gender
	0x14,//sprite
	{PCHAR_M, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_i, PCHAR_k, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x43
},{
	//Trainer 0x44
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x5, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_N, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x44
},{
	//Trainer 0x45
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER,
	{0x7, true},//Encounter and gender
	0x3c,//sprite
	{PCHAR_R, PCHAR_e, PCHAR_m, PCHAR_u, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x45
},{
	//Trainer 0x46
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x7, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_M, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x46
},{
	//Trainer 0x47
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER,
	{0x7, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_E, PCHAR_r, PCHAR_n, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x47
},{
	//Trainer 0x48
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x1, false},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_I, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x48
},{
	//Trainer 0x49
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_P, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x49
},{
	//Trainer 0x4a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0xb, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_N, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x4a
},{
	//Trainer 0x4b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x2, false},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_D, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x4b
},{
	//Trainer 0x4c
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VIOLET_VORS,
	{0x4, true},//Encounter and gender
	0x1b,//sprite
	{PCHAR_R, PCHAR_i, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x4c
},{
	//Trainer 0x4d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0x8, false},//Encounter and gender
	0x43,//sprite
	{PCHAR_B, PCHAR_a, PCHAR_r, PCHAR_n, PCHAR_e, PCHAR_b, PCHAR_y, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x4d
},{
	//Trainer 0x4e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER,
	{0x6, false},//Encounter and gender
	0x24,//sprite
	{PCHAR_W, PCHAR_o, PCHAR_l, PCHAR_f, PCHAR_f, PCHAR_i, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x4e
},{
	//Trainer 0x4f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER,
	{0x6, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_K, PCHAR_o, PCHAR_r, PCHAR_i, PCHAR_n, PCHAR_n, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x4f
},{
	//Trainer 0x50
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0x7, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_K, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_e, PCHAR_h, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x50
},{
	//Trainer 0x51
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE,
	{0x7, false},//Encounter and gender
	0x54,//sprite
	{PCHAR_K, PCHAR_a, PCHAR_r, PCHAR_m, PCHAR_i, PCHAR_n, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x51
},{
	//Trainer 0x52
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0x0, false},//Encounter and gender
	0x43,//sprite
	{PCHAR_W, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_t, PCHAR_y, PCHAR_r, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x52
},{
	//Trainer 0x53
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHULKIND,
	{0x1, false},//Encounter and gender
	0x54,//sprite
	{PCHAR_S, PCHAR_o, PCHAR_p, PCHAR_h, PCHAR_i, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x53
},{
	//Trainer 0x54
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEMPFERIN,
	{0x0, false},//Encounter and gender
	0x30,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_y, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x54
},{
	//Trainer 0x55
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY,
	{0x1, true},//Encounter and gender
	0x3,//sprite
	{PCHAR_S, PCHAR_i, PCHAR_l, PCHAR_k, PCHAR_y, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x55
},{
	//Trainer 0x56
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_STREBER,
	{0x7a, false},//Encounter and gender
	0x59,//sprite
	{PCHAR_W, PCHAR_a, PCHAR_y, PCHAR_n, PCHAR_i, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x56
},{
	//Trainer 0x57
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXPERTE,
	{0xa, true},//Encounter and gender
	0x23,//sprite
	{PCHAR_F, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_z, PCHAR_i, PCHAR_s, PCHAR_k, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x57
},{
	//Trainer 0x58
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RUINENMANIAC,
	{0xa, false},//Encounter and gender
	0x4,//sprite
	{PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_o, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x58
},{
	//Trainer 0x59
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0x0, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_R, PCHAR_u, PCHAR_d, PCHAR_o, PCHAR_l, PCHAR_f, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x59
},{
	//Trainer 0x5a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DIEB,
	{0x0, false},//Encounter and gender
	0x5c,//sprite
	{PCHAR_M, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_e, PCHAR_c, PCHAR_k, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x5a
},{
	//Trainer 0x5b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_T, PCHAR_h, PCHAR_y, PCHAR_m, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x5b
},{
	//Trainer 0x5c
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x0, true},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_k, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERHEILER, ITEM_HYPERHEILER},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_PREFER_CERTAIN_MOVES,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x5c
},{
	//Trainer 0x5d
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x0, true},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_k, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERHEILER, ITEM_HYPERHEILER},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_PREFER_CERTAIN_MOVES,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x5d
},{
	//Trainer 0x5e
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x0, true},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_k, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERHEILER, ITEM_HYPERHEILER},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_PREFER_CERTAIN_MOVES,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x5e
},{
	//Trainer 0x5f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE,
	{0x0, true},//Encounter and gender
	0x54,//sprite
	{PCHAR_J, PCHAR_a, PCHAR_n, PCHAR_i, PCHAR_n, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x5f
},{
	//Trainer 0x60
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0x0, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_G, PCHAR_u, PCHAR_n, PCHAR_n, PCHAR_w, PCHAR_a, PCHAR_r, PCHAR_d, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x60
},{
	//Trainer 0x61
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_ZUECHTER,
	{0x28, true},//Encounter and gender
	0x3b,//sprite
	{PCHAR_H, PCHAR_e, PCHAR_n, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_t, PCHAR_t, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x61
},{
	//Trainer 0x62
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER3,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_S, PCHAR_o, PCHAR_n, PCHAR_n, PCHAR_w, PCHAR_a, PCHAR_l, PCHAR_d, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x62
},{
	//Trainer 0x63
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_POKEMANIAC,
	{0x0, false},//Encounter and gender
	0x36,//sprite
	{PCHAR_V, PCHAR_a, PCHAR_l, PCHAR_e, PCHAR_y, PCHAR_n, PCHAR_t, PCHAR_y, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x63
},{
	//Trainer 0x64
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_M, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x64
},{
	//Trainer 0x65
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER,
	{0x0, true},//Encounter and gender
	0x33,//sprite
	{PCHAR_J, PCHAR_a, PCHAR_n, PCHAR_i, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x65
},{
	//Trainer 0x66
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER,
	{0x0, false},//Encounter and gender
	0x3d,//sprite
	{PCHAR_I, PCHAR_s, PCHAR_m, PCHAR_e, PCHAR_r, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x66
},{
	//Trainer 0x67
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{PCHAR_E, PCHAR_u, PCHAR_s, PCHAR_j, PCHAR_e, PCHAR_a, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x67
},{
	//Trainer 0x68
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHNOESEL,
	{0x0, false},//Encounter and gender
	0xd,//sprite
	{PCHAR_R, PCHAR_u, PCHAR_d, PCHAR_d, PCHAR_e, PCHAR_r, PCHAR_i, PCHAR_c, PCHAR_h, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x68
},{
	//Trainer 0x69
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO,
	{0x0, false},//Encounter and gender
	0x16,//sprite
	{PCHAR_A, PCHAR_t, PCHAR_t, PCHAR_i, PCHAR_l, PCHAR_i, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x69
},{
	//Trainer 0x6a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0x0, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_G, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_o, PCHAR_l, PCHAR_f, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x6a
},{
	//Trainer 0x6b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER,
	{0x0, false},//Encounter and gender
	0x2e,//sprite
	{PCHAR_A, PCHAR_b, PCHAR_d, PCHAR_u, PCHAR_h, PCHAR_l, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x6b
},{
	//Trainer 0x6c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_REVOLUTIONAER,
	{0x0, false},//Encounter and gender
	0x1,//sprite
	{PCHAR_G, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_i, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x6c
},{
	//Trainer 0x6d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_REVOLUTIONAER,
	{0x0, true},//Encounter and gender
	0x2,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_r, PCHAR_j, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x6d
},{
	//Trainer 0x6e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_REVOLUTIONAER,
	{0x0, true},//Encounter and gender
	0x2,//sprite
	{PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x6e
},{
	//Trainer 0x6f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY,
	{0x0, true},//Encounter and gender
	0x3,//sprite
	{PCHAR_R, PCHAR_u, PCHAR_a, PCHAR_n, PCHAR_n, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x6f
},{
	//Trainer 0x70
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MECHANIKER,
	{0x0, false},//Encounter and gender
	0x5d,//sprite
	{PCHAR_T, PCHAR_o, PCHAR_m, PCHAR_m, PCHAR_a, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x70
},{
	//Trainer 0x71
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_S, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x71
},{
	//Trainer 0x72
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_REVOLUTIONAER,
	{0x0, false},//Encounter and gender
	0x2,//sprite
	{PCHAR_S, PCHAR_o, PCHAR_p, PCHAR_h, PCHAR_y, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x72
},{
	//Trainer 0x73
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_REVOLUTIONAER,
	{0x0, false},//Encounter and gender
	0x1,//sprite
	{PCHAR_R, PCHAR_e, PCHAR_l, PCHAR_l, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x73
},{
	//Trainer 0x74
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEMPFERIN,
	{0x0, true},//Encounter and gender
	0x30,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_g, PCHAR_y, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x74
},{
	//Trainer 0x75
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER,
	{0x1, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_K, PCHAR_r, PCHAR_i, PCHAR_s, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x75
},{
	//Trainer 0x76
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO,
	{0x1, false},//Encounter and gender
	0x64,//sprite
	{PCHAR_C, PCHAR_o, PCHAR_a, PCHAR_l, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x76
},{
	//Trainer 0x77
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0x1, false},//Encounter and gender
	0x7b,//sprite
	{PCHAR_F, PCHAR_r, PCHAR_a, PCHAR_u, PCHAR_n, PCHAR_k, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x77
},{
	//Trainer 0x78
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER,
	{0x1, false},//Encounter and gender
	0x5e,//sprite
	{PCHAR_S, PCHAR_h, PCHAR_e, PCHAR_l, PCHAR_d, PCHAR_o, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x78
},{
	//Trainer 0x79
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT,
	{0x1, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_R, PCHAR_a, PCHAR_s, PCHAR_h, PCHAR_i, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x79
},{
	//Trainer 0x7a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEMPFERIN,
	{0x1, true},//Encounter and gender
	0x30,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_y, PCHAR_a, PCHAR_m, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x7a
},{
	//Trainer 0x7b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER,
	{0x1, true},//Encounter and gender
	0x5e,//sprite
	{PCHAR_D, PCHAR_o, PCHAR_r, PCHAR_a, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x7b
},{
	//Trainer 0x7c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT,
	{0x1, true},//Encounter and gender
	0x69,//sprite
	{PCHAR_R, PCHAR_i, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_d, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x7c
},{
	//Trainer 0x7d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_REVOLUTIONAER,
	{0x1, true},//Encounter and gender
	0x2,//sprite
	{PCHAR_E, PCHAR_l, PCHAR_s, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x7d
},{
	//Trainer 0x7e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0x1, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_G, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_a, PCHAR_d, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x7e
},{
	//Trainer 0x7f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE2,
	{0x1, true},//Encounter and gender
	0x54,//sprite
	{PCHAR_L, PCHAR_i, PCHAR_v, PCHAR_i, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x7f
},{
	//Trainer 0x80
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEMPFERIN,
	{0x1, false},//Encounter and gender
	0x30,//sprite
	{PCHAR_L, PCHAR_o, PCHAR_r, PCHAR_e, PCHAR_t, PCHAR_t, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x80
},{
	//Trainer 0x81
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT,
	{0x1, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_T, PCHAR_o, PCHAR_b, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x81
},{
	//Trainer 0x82
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEMPFERIN,
	{0x1, true},//Encounter and gender
	0x30,//sprite
	{PCHAR_C, PCHAR_h, PCHAR_r, PCHAR_i, PCHAR_s, PCHAR_t, PCHAR_i, PCHAR_n, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x82
},{
	//Trainer 0x83
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT,
	{0x1, true},//Encounter and gender
	0x69,//sprite
	{PCHAR_G, PCHAR_e, PCHAR_r, PCHAR_d, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x83
},{
	//Trainer 0x84
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHERIN,
	{0x1, true},//Encounter and gender
	0x5,//sprite
	{PCHAR_E, PCHAR_l, PCHAR_i, PCHAR_s, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x84
},{
	//Trainer 0x85
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RUINENMANIAC,
	{0x1, true},//Encounter and gender
	0x4,//sprite
	{PCHAR_F, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_i, PCHAR_c, PCHAR_h, PCHAR_o, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x85
},{
	//Trainer 0x86
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0x0, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_N, PCHAR_i, PCHAR_k, PCHAR_o, PCHAR_l, PCHAR_a, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x86
},{
	//Trainer 0x87
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x0, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_L, PCHAR_o, PCHAR_r, PCHAR_e, PCHAR_n, PCHAR_z, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x87
},{
	//Trainer 0x88
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER,
	{0x0, false},//Encounter and gender
	0x42,//sprite
	{PCHAR_R, PCHAR_i, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_d, PCHAR_o, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x88
},{
	//Trainer 0x89
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WOLKENREITER,
	{0x0, true},//Encounter and gender
	0x47,//sprite
	{PCHAR_A, PCHAR_l, PCHAR_y, PCHAR_s, PCHAR_s, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x89
},{
	//Trainer 0x8a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WOLKENREITER,
	{0x0, false},//Encounter and gender
	0x48,//sprite
	{PCHAR_A, PCHAR_l, PCHAR_e, PCHAR_s, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x8a
},{
	//Trainer 0x8b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_STREBER,
	{0x0, false},//Encounter and gender
	0x59,//sprite
	{PCHAR_J, PCHAR_e, PCHAR_s, PCHAR_s, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x8b
},{
	//Trainer 0x8c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WOLKENREITER,
	{0x0, false},//Encounter and gender
	0x47,//sprite
	{PCHAR_E, PCHAR_l, PCHAR_y, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x8c
},{
	//Trainer 0x8d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_M, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x8d
},{
	//Trainer 0x8e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_J, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x8e
},{
	//Trainer 0x8f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, true},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_G, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x8f
},{
	//Trainer 0x90
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_S, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x90
},{
	//Trainer 0x91
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x49,//sprite
	{PCHAR_E, PCHAR_l, PCHAR_i, PCHAR_t, PCHAR_e, PCHAR_SPACE, PCHAR_V, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x91
},{
	//Trainer 0x92
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_HITZKOPF,
	{0x0, false},//Encounter and gender
	0x12,//sprite
	{PCHAR_R, PCHAR_a, PCHAR_p, PCHAR_h, PCHAR_a, PCHAR_e, PCHAR_l, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x92
},{
	//Trainer 0x93
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_T, PCHAR_a, PCHAR_s, PCHAR_s, PCHAR_o, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x93
},{
	//Trainer 0x94
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT,
	{0x0, false},//Encounter and gender
	0x62,//sprite
	{PCHAR_C, PCHAR_y, PCHAR_a, PCHAR_r, PCHAR_l, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x94
},{
	//Trainer 0x95
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER,
	{0x0, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_I, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, PCHAR_d, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x95
},{
	//Trainer 0x96
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0x2, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_G, PCHAR_e, PCHAR_w, PCHAR_e, PCHAR_r, PCHAR_t, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x96
},{
	//Trainer 0x97
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_STREBER,
	{0x2, true},//Encounter and gender
	0x59,//sprite
	{PCHAR_C, PCHAR_r, PCHAR_i, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, PCHAR_a, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x97
},{
	//Trainer 0x98
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER,
	{0x2, true},//Encounter and gender
	0x3e,//sprite
	{PCHAR_H, PCHAR_e, PCHAR_d, PCHAR_w, PCHAR_i, PCHAR_g, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x98
},{
	//Trainer 0x99
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE,
	{0x2, true},//Encounter and gender
	0x54,//sprite
	{PCHAR_R, PCHAR_u, PCHAR_t, PCHAR_h, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x99
},{
	//Trainer 0x9a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0x2, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_I, PCHAR_n, PCHAR_g, PCHAR_o, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x9a
},{
	//Trainer 0x9b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHULKIND,
	{0x2, true},//Encounter and gender
	0x1e,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_r, PCHAR_i, PCHAR_j, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x9b
},{
	//Trainer 0x9c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x2, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_J, PCHAR_a, PCHAR_n, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x9c
},{
	//Trainer 0x9d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_LADY2,
	{0x2, true},//Encounter and gender
	0x92,//sprite
	{PCHAR_N, PCHAR_a, PCHAR_t, PCHAR_h, PCHAR_a, PCHAR_l, PCHAR_i, PCHAR_e, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x9d
},{
	//Trainer 0x9e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DIEB,
	{0x0, true},//Encounter and gender
	0x5c,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_d, PCHAR_i, PCHAR_g, PCHAR_a, PCHAR_r, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x9e
},{
	//Trainer 0x9f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_ZUECHTER,
	{0x0, true},//Encounter and gender
	0x3b,//sprite
	{PCHAR_H, PCHAR_a, PCHAR_n, PCHAR_n, PCHAR_y, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x9f
},{
	//Trainer 0xa0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0x0, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_H, PCHAR_a, PCHAR_g, PCHAR_g, PCHAR_r, PCHAR_o, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xa0
},{
	//Trainer 0xa1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_J, PCHAR_o, PCHAR_s, PCHAR_e, PCHAR_p, PCHAR_p, PCHAR_o, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xa1
},{
	//Trainer 0xa2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_HITZKOPF,
	{0x0, false},//Encounter and gender
	0x12,//sprite
	{PCHAR_T, PCHAR_a, PCHAR_r, PCHAR_y, PCHAR_u, PCHAR_k, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xa2
},{
	//Trainer 0xa3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_M, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xa3
},{
	//Trainer 0xa4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_R, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xa4
},{
	//Trainer 0xa5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_L, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xa5
},{
	//Trainer 0xa6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_Y, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xa6
},{
	//Trainer 0xa7
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_D, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xa7
},{
	//Trainer 0xa8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_L, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xa8
},{
	//Trainer 0xa9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x0, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_C, PCHAR_u, PCHAR_r, PCHAR_r, PCHAR_i, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xa9
},{
	//Trainer 0xaa
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VIOLET_VORS,
	{0x3, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_M, PCHAR_i, PCHAR_s, PCHAR_t, PCHAR_r, PCHAR_a, PCHAR_l, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | 0x100,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xaa
},{
	//Trainer 0xab
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER,
	{0x3, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_D, PCHAR_a, PCHAR_r, PCHAR_i, PCHAR_o, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xab
},{
	//Trainer 0xac
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_HITZKOPF,
	{0x3, false},//Encounter and gender
	0x12,//sprite
	{PCHAR_G, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_i, PCHAR_t, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xac
},{
	//Trainer 0xad
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x3, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xad
},{
	//Trainer 0xae
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x49,//sprite
	{PCHAR_E, PCHAR_l, PCHAR_i, PCHAR_t, PCHAR_e, PCHAR_SPACE, PCHAR_H, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xae
},{
	//Trainer 0xaf
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x4a,//sprite
	{PCHAR_E, PCHAR_l, PCHAR_i, PCHAR_t, PCHAR_e, PCHAR_SPACE, PCHAR_M, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xaf
},{
	//Trainer 0xb0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_K, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xb0
},{
	//Trainer 0xb1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_ue, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_G, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xb1
},{
	//Trainer 0xb2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x3, true},//Encounter and gender
	0x49,//sprite
	{PCHAR_E, PCHAR_l, PCHAR_i, PCHAR_t, PCHAR_e, PCHAR_SPACE, PCHAR_N, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xb2
},{
	//Trainer 0xb3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER,
	{0x3, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_B, PCHAR_U, PCHAR_R, PCHAR_K, PCHAR_A, PCHAR_R, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xb3
},{
	//Trainer 0xb4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER,
	{0x3, false},//Encounter and gender
	0x5e,//sprite
	{PCHAR_R, PCHAR_O, PCHAR_N, PCHAR_N, PCHAR_Y, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xb4
},{
	//Trainer 0xb5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TRIATHLET,
	{0xb, false},//Encounter and gender
	0x29,//sprite
	{PCHAR_R, PCHAR_U, PCHAR_F, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xb5
},{
	//Trainer 0xb6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER,
	{0xb, false},//Encounter and gender
	0xf,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_S, PCHAR_P, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xb6
},{
	//Trainer 0xb7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PLANSCHER,
	{0xb, true},//Encounter and gender
	0x6,//sprite
	{PCHAR_M, PCHAR_I, PCHAR_N, PCHAR_O, PCHAR_R, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xb7
},{
	//Trainer 0xb8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER,
	{0xb, false},//Encounter and gender
	0xf,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_V, PCHAR_A, PCHAR_R, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xb8
},{
	//Trainer 0xb9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MATROSE,
	{0xb, false},//Encounter and gender
	0x55,//sprite
	{PCHAR_L, PCHAR_A, PCHAR_N, PCHAR_Z, PCHAR_E, PCHAR_L, PCHAR_O, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xb9
},{
	//Trainer 0xba
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN,
	{0xb, false},//Encounter and gender
	0x63,//sprite
	{PCHAR_G, PCHAR_I, PCHAR_S, PCHAR_E, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xba
},{
	//Trainer 0xbb
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0xb, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_L, PCHAR_U, PCHAR_Z, PCHAR_I, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xbb
},{
	//Trainer 0xbc
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER,
	{0xb, false},//Encounter and gender
	0x5e,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_I, PCHAR_M, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xbc
},{
	//Trainer 0xbd
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER,
	{0xb, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_S, PCHAR_I, PCHAR_E, PCHAR_G, PCHAR_F, PCHAR_R, PCHAR_I, PCHAR_E, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xbd
},{
	//Trainer 0xbe
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN,
	{0xb, false},//Encounter and gender
	0x2c,//sprite
	{PCHAR_S, PCHAR_A, PCHAR_B, PCHAR_R, PCHAR_I, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xbe
},{
	//Trainer 0xbf
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0xb, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_F, PCHAR_e, PCHAR_u, PCHAR_e, PCHAR_r, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xbf
},{
	//Trainer 0xc0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0xb, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_G, PCHAR_e, PCHAR_i, PCHAR_s, PCHAR_t, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xc0
},{
	//Trainer 0xc1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0xb, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_6, PCHAR_DOT, PCHAR_O, PCHAR_r, PCHAR_d, PCHAR_e, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xc1
},{
	//Trainer 0xc2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xc2
},{
	//Trainer 0xc3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xc3
},{
	//Trainer 0xc4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xc4
},{
	//Trainer 0xc5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xc5
},{
	//Trainer 0xc6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xc6
},{
	//Trainer 0xc7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xc7
},{
	//Trainer 0xc8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_STRATEGY_NONE,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xc8
},{
	//Trainer 0xc9
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x1b,//sprite
	{PCHAR_V, PCHAR_O, PCHAR_R, PCHAR_S, PCHAR_DOT, PCHAR_SPACE, PCHAR_R, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xc9
},{
	//Trainer 0xca
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xca
},{
	//Trainer 0xcb
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xcb
},{
	//Trainer 0xcc
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x3e,//sprite
	{PCHAR_E, PCHAR_L, PCHAR_I, PCHAR_T, PCHAR_E, PCHAR_SPACE, PCHAR_G, PCHAR_U, PCHAR_A, PCHAR_R, PCHAR_D, 0xff},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xcc
},{
	//Trainer 0xcd
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x3e,//sprite
	{PCHAR_E, PCHAR_L, PCHAR_I, PCHAR_T, PCHAR_E, PCHAR_SPACE, PCHAR_G, PCHAR_U, PCHAR_A, PCHAR_R, PCHAR_D, 0xff},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xcd
},{
	//Trainer 0xce
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x0, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xce
},{
	//Trainer 0xcf
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_D, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xcf
},{
	//Trainer 0xd0
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_B, PCHAR_L, PCHAR_A, PCHAR_S, PCHAR_I, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xd0
},{
	//Trainer 0xd1
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_G, PCHAR_E, PCHAR_R, PCHAR_A, PCHAR_L, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xd1
},{
	//Trainer 0xd2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0x3, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_7, PCHAR_DOT, PCHAR_O, PCHAR_r, PCHAR_d, PCHAR_e, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xd2
},{
	//Trainer 0xd3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0x3, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_8, PCHAR_DOT, PCHAR_O, PCHAR_r, PCHAR_d, PCHAR_e, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xd3
},{
	//Trainer 0xd4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0x3, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_L, PCHAR_I, PCHAR_G, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xd4
},{
	//Trainer 0xd5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DIEB,
	{0x3, false},//Encounter and gender
	0x5c,//sprite
	{PCHAR_R, PCHAR_A, PCHAR_L, PCHAR_F, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xd5
},{
	//Trainer 0xd6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DIEB,
	{0x3, false},//Encounter and gender
	0x5c,//sprite
	{PCHAR_B, PCHAR_O, PCHAR_R, PCHAR_I, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xd6
},{
	//Trainer 0xd7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DIEB,
	{0x3, false},//Encounter and gender
	0x5c,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_D, PCHAR_I, PCHAR_G, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xd7
},{
	//Trainer 0xd8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DIEB,
	{0x3, false},//Encounter and gender
	0x5c,//sprite
	{PCHAR_A, PCHAR_R, PCHAR_N, PCHAR_I, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xd8
},{
	//Trainer 0xd9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER,
	{0x3, false},//Encounter and gender
	0x8e,//sprite
	{PCHAR_S, PCHAR_I, PCHAR_R, PCHAR_I, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xd9
},{
	//Trainer 0xda
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_HEXE,
	{0x3, true},//Encounter and gender
	0xa,//sprite
	{PCHAR_S, PCHAR_I, PCHAR_M, PCHAR_O, PCHAR_N, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xda
},{
	//Trainer 0xdb
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_HEXE,
	{0x3, true},//Encounter and gender
	0xa,//sprite
	{PCHAR_L, PCHAR_U, PCHAR_D, PCHAR_W, PCHAR_I, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xdb
},{
	//Trainer 0xdc
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_HEXE,
	{0x0, true},//Encounter and gender
	0xa,//sprite
	{PCHAR_H, PCHAR_A, PCHAR_U, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xdc
},{
	//Trainer 0xdd
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO,
	{0x0, true},//Encounter and gender
	0x16,//sprite
	{PCHAR_D, PCHAR_E, PCHAR_N, PCHAR_I, PCHAR_S, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xdd
},{
	//Trainer 0xde
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT,
	{0x0, false},//Encounter and gender
	0x41,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_T, PCHAR_Y, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xde
},{
	//Trainer 0xdf
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0xb, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_B, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xdf
},{
	//Trainer 0xe0
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_TRAINER,
	{0xb, false},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_I, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xe0
},{
	//Trainer 0xe1
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_TRAINER,
	{0xb, true},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_I, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xe1
},{
	//Trainer 0xe2
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_TRAINER,
	{0xb, true},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_I, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xe2
},{
	//Trainer 0xe3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0xb, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_D, PCHAR_E, PCHAR_S, PCHAR_M, PCHAR_O, PCHAR_N, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xe3
},{
	//Trainer 0xe4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0xb, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_D, PCHAR_E, PCHAR_S, PCHAR_M, PCHAR_O, PCHAR_N, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xe4
},{
	//Trainer 0xe5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0xb, false},//Encounter and gender
	0x17,//sprite
	{PCHAR_D, PCHAR_E, PCHAR_S, PCHAR_M, PCHAR_O, PCHAR_N, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xe5
},{
	//Trainer 0xe6
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0xb, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xe6
},{
	//Trainer 0xe7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER3,
	{0xb, false},//Encounter and gender
	0x5e,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_A, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xe7
},{
	//Trainer 0xe8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER3,
	{0xb, false},//Encounter and gender
	0x5e,//sprite
	{PCHAR_A, PCHAR_M, PCHAR_A, PCHAR_D, PCHAR_E, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xe8
},{
	//Trainer 0xe9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER3,
	{0xb, false},//Encounter and gender
	0x5e,//sprite
	{PCHAR_A, PCHAR_N, PCHAR_S, PCHAR_G, PCHAR_A, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xe9
},{
	//Trainer 0xea
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_K, PCHAR_O, PCHAR_N, PCHAR_S, PCHAR_T, PCHAR_A, PCHAR_N, PCHAR_T, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xea
},{
	//Trainer 0xeb
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_E, PCHAR_N, PCHAR_N, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xeb
},{
	//Trainer 0xec
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_E, PCHAR_R, PCHAR_N, PCHAR_S, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xec
},{
	//Trainer 0xed
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_U, PCHAR_M, PCHAR_B, PCHAR_E, PCHAR_R, PCHAR_T, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xed
},{
	//Trainer 0xee
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_I, PCHAR_G, PCHAR_N, PCHAR_A, PCHAR_Z, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xee
},{
	//Trainer 0xef
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_W, PCHAR_I, PCHAR_N, PCHAR_F, PCHAR_R, PCHAR_I, PCHAR_E, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xef
},{
	//Trainer 0xf0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_K, PCHAR_E, PCHAR_V, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xf0
},{
	//Trainer 0xf1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_H, PCHAR_A, PCHAR_G, PCHAR_E, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xf1
},{
	//Trainer 0xf2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_B, PCHAR_A, PCHAR_S, PCHAR_I, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xf2
},{
	//Trainer 0xf3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_D, PCHAR_A, PCHAR_G, PCHAR_O, PCHAR_B, PCHAR_E, PCHAR_R, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xf3
},{
	//Trainer 0xf4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_N, PCHAR_U, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xf4
},{
	//Trainer 0xf5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_L, PCHAR_E, PCHAR_O, PCHAR_P, PCHAR_O, PCHAR_L, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xf5
},{
	//Trainer 0xf6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_P, PCHAR_E, PCHAR_D, PCHAR_R, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xf6
},{
	//Trainer 0xf7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_O, PCHAR_S, PCHAR_W, PCHAR_A, PCHAR_L, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xf7
},{
	//Trainer 0xf8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_T, PCHAR_H, PCHAR_O, PCHAR_M, PCHAR_A, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xf8
},{
	//Trainer 0xf9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_R, PCHAR_E, PCHAR_M, PCHAR_I, PCHAR_G, PCHAR_I, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xf9
},{
	//Trainer 0xfa
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_L, PCHAR_E, PCHAR_I, PCHAR_F, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xfa
},{
	//Trainer 0xfb
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_V, PCHAR_O, PCHAR_L, PCHAR_K, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xfb
},{
	//Trainer 0xfc
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_L, PCHAR_I, PCHAR_O, PCHAR_N, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xfc
},{
	//Trainer 0xfd
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_S, PCHAR_P, PCHAR_A, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xfd
},{
	//Trainer 0xfe
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_G, PCHAR_E, PCHAR_R, PCHAR_M, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xfe
},{
	//Trainer 0xff
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_G, PCHAR_OE, PCHAR_T, PCHAR_Z, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_xff
},{
	//Trainer 0x100
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_H, PCHAR_A, PCHAR_J, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x100
},{
	//Trainer 0x101
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_F, PCHAR_E, PCHAR_R, PCHAR_D, PCHAR_I, PCHAR_N, PCHAR_A, PCHAR_N, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x101
},{
	//Trainer 0x102
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER,
	{0x0, false},//Encounter and gender
	0x61,//sprite
	{PCHAR_J, PCHAR_A, PCHAR_N, PCHAR_N, PCHAR_E, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x102
},{
	//Trainer 0x103
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER,
	{0x0, false},//Encounter and gender
	0x61,//sprite
	{PCHAR_K, PCHAR_U, PCHAR_N, PCHAR_I, PCHAR_B, PCHAR_E, PCHAR_R, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x103
},{
	//Trainer 0x104
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER,
	{0x0, false},//Encounter and gender
	0x61,//sprite
	{PCHAR_D, PCHAR_I, PCHAR_R, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x104
},{
	//Trainer 0x105
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER,
	{0x0, false},//Encounter and gender
	0x61,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_C, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x105
},{
	//Trainer 0x106
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER,
	{0x0, false},//Encounter and gender
	0x61,//sprite
	{PCHAR_B, PCHAR_A, PCHAR_L, PCHAR_T, PCHAR_H, PCHAR_A, PCHAR_S, PCHAR_A, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x106
},{
	//Trainer 0x107
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER,
	{0x0, false},//Encounter and gender
	0x61,//sprite
	{0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x107
},{
	//Trainer 0x108
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER,
	{0x0, false},//Encounter and gender
	0x61,//sprite
	{PCHAR_R, PCHAR_I, PCHAR_C, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x108
},{
	//Trainer 0x109
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT2,
	{0x1, true},//Encounter and gender
	0x62,//sprite
	{PCHAR_S, PCHAR_A, PCHAR_L, PCHAR_M, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x109
},{
	//Trainer 0x10a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT2,
	{0x1, true},//Encounter and gender
	0x62,//sprite
	{PCHAR_R, PCHAR_O, PCHAR_B, PCHAR_E, PCHAR_R, PCHAR_T, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x10a
},{
	//Trainer 0x10b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT2,
	{0x1, true},//Encounter and gender
	0x62,//sprite
	{PCHAR_R, PCHAR_A, PCHAR_M, PCHAR_O, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x10b
},{
	//Trainer 0x10c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT2,
	{0x1, true},//Encounter and gender
	0x62,//sprite
	{PCHAR_L, PCHAR_O, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x10c
},{
	//Trainer 0x10d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT2,
	{0x1, true},//Encounter and gender
	0x62,//sprite
	{PCHAR_S, PCHAR_Y, PCHAR_L, PCHAR_V, PCHAR_I, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x10d
},{
	//Trainer 0x10e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_D, PCHAR_A, PCHAR_N, PCHAR_I, PCHAR_E, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x10e
},{
	//Trainer 0x10f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_S, PCHAR_S, PCHAR_A, PCHAR_N, PCHAR_D, PCHAR_R, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x10f
},{
	//Trainer 0x110
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_M, PCHAR_E, PCHAR_L, PCHAR_I, PCHAR_S, PCHAR_S, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x110
},{
	//Trainer 0x111
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT2,
	{0x1, true},//Encounter and gender
	0x62,//sprite
	{PCHAR_I, PCHAR_L, PCHAR_O, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x111
},{
	//Trainer 0x112
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT2,
	{0x1, true},//Encounter and gender
	0x62,//sprite
	{PCHAR_T, PCHAR_I, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x112
},{
	//Trainer 0x113
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_L, PCHAR_I, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x113
},{
	//Trainer 0x114
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_T, PCHAR_J, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x114
},{
	//Trainer 0x115
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_I, PCHAR_C, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x115
},{
	//Trainer 0x116
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_F, PCHAR_R, PCHAR_A, PCHAR_N, PCHAR_C, PCHAR_E, PCHAR_S, PCHAR_C, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x116
},{
	//Trainer 0x117
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_M, PCHAR_I, PCHAR_R, PCHAR_J, PCHAR_A, PCHAR_M, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x117
},{
	//Trainer 0x118
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO2,
	{0x4, false},//Encounter and gender
	0x64,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_E, PCHAR_X, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x118
},{
	//Trainer 0x119
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO2,
	{0x4, false},//Encounter and gender
	0x64,//sprite
	{PCHAR_B, PCHAR_E, PCHAR_R, PCHAR_T, PCHAR_O, PCHAR_L, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x119
},{
	//Trainer 0x11a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO2,
	{0x4, false},//Encounter and gender
	0x64,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_X, PCHAR_I, PCHAR_M, PCHAR_I, PCHAR_L, PCHAR_I, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x11a
},{
	//Trainer 0x11b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO2,
	{0x4, false},//Encounter and gender
	0x64,//sprite
	{PCHAR_U, PCHAR_R, PCHAR_B, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x11b
},{
	//Trainer 0x11c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ROCKER,
	{0x0, false},//Encounter and gender
	0x65,//sprite
	{PCHAR_H, PCHAR_U, PCHAR_B, PCHAR_E, PCHAR_R, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x11c
},{
	//Trainer 0x11d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ROCKER,
	{0x0, false},//Encounter and gender
	0x65,//sprite
	{PCHAR_X, PCHAR_A, PCHAR_V, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x11d
},{
	//Trainer 0x11e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JONGLEUR,
	{0xb, false},//Encounter and gender
	0x66,//sprite
	{PCHAR_B, PCHAR_O, PCHAR_B, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x11e
},{
	//Trainer 0x11f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JONGLEUR,
	{0xb, false},//Encounter and gender
	0x66,//sprite
	{PCHAR_N, PCHAR_I, PCHAR_N, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x11f
},{
	//Trainer 0x120
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JONGLEUR,
	{0xb, false},//Encounter and gender
	0x66,//sprite
	{PCHAR_C, PCHAR_H, PCHAR_U, PCHAR_C, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x120
},{
	//Trainer 0x121
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JONGLEUR,
	{0xb, false},//Encounter and gender
	0x66,//sprite
	{PCHAR_R, PCHAR_E, PCHAR_I, PCHAR_N, PCHAR_H, PCHAR_A, PCHAR_R, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x121
},{
	//Trainer 0x122
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JONGLEUR,
	{0xb, false},//Encounter and gender
	0x66,//sprite
	{PCHAR_J, PCHAR_O, PCHAR_H, PCHAR_A, PCHAR_N, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x122
},{
	//Trainer 0x123
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JONGLEUR,
	{0xb, false},//Encounter and gender
	0x66,//sprite
	{PCHAR_W, PCHAR_E, PCHAR_N, PCHAR_D, PCHAR_E, PCHAR_L, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x123
},{
	//Trainer 0x124
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JONGLEUR,
	{0xb, false},//Encounter and gender
	0x66,//sprite
	{PCHAR_M, PCHAR_I, PCHAR_L, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x124
},{
	//Trainer 0x125
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JONGLEUR,
	{0xb, false},//Encounter and gender
	0x66,//sprite
	{PCHAR_N, PCHAR_A, PCHAR_T, PCHAR_H, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x125
},{
	//Trainer 0x126
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DOMPTEUR,
	{0xb, false},//Encounter and gender
	0x67,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_N, PCHAR_R, PCHAR_Y, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x126
},{
	//Trainer 0x127
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DOMPTEUR,
	{0xb, false},//Encounter and gender
	0x67,//sprite
	{PCHAR_E, PCHAR_D, PCHAR_G, PCHAR_A, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x127
},{
	//Trainer 0x128
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DOMPTEUR,
	{0xb, false},//Encounter and gender
	0x67,//sprite
	{PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_G, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x128
},{
	//Trainer 0x129
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DOMPTEUR,
	{0xb, false},//Encounter and gender
	0x67,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_N, PCHAR_D, PCHAR_R, PCHAR_I, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x129
},{
	//Trainer 0x12a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DOMPTEUR,
	{0xb, false},//Encounter and gender
	0x67,//sprite
	{PCHAR_O, PCHAR_T, PCHAR_F, PCHAR_R, PCHAR_I, PCHAR_E, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x12a
},{
	//Trainer 0x12b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DOMPTEUR,
	{0xb, false},//Encounter and gender
	0x67,//sprite
	{PCHAR_U, PCHAR_R, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x12b
},{
	//Trainer 0x12c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_E, PCHAR_I, PCHAR_L, PCHAR_M, PCHAR_A, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x12c
},{
	//Trainer 0x12d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_J, PCHAR_O, PCHAR_S, PCHAR_C, PCHAR_H, PCHAR_K, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x12d
},{
	//Trainer 0x12e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_F, PCHAR_R, PCHAR_I, PCHAR_T, PCHAR_J, PCHAR_O, PCHAR_F, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x12e
},{
	//Trainer 0x12f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_T, PCHAR_I, PCHAR_L, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x12f
},{
	//Trainer 0x130
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_G, PCHAR_E, PCHAR_N, PCHAR_A, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x130
},{
	//Trainer 0x131
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_E, PCHAR_D, PCHAR_W, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x131
},{
	//Trainer 0x132
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_V, PCHAR_I, PCHAR_T, PCHAR_A, PCHAR_L, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x132
},{
	//Trainer 0x133
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_P, PCHAR_A, PCHAR_S, PCHAR_C, PCHAR_A, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x133
},{
	//Trainer 0x134
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_O, PCHAR_T, PCHAR_T, PCHAR_O, PCHAR_K, PCHAR_A, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x134
},{
	//Trainer 0x135
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_R, PCHAR_O, PCHAR_M, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x135
},{
	//Trainer 0x136
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_A, PCHAR_M, PCHAR_A, PCHAR_T, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x136
},{
	//Trainer 0x137
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_A, PCHAR_N, PCHAR_D, PCHAR_O, PCHAR_L, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x137
},{
	//Trainer 0x138
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_R, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x138
},{
	//Trainer 0x139
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_A, PCHAR_R, PCHAR_M, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x139
},{
	//Trainer 0x13a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_L, PCHAR_T, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x13a
},{
	//Trainer 0x13b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_V, PCHAR_I, PCHAR_N, PCHAR_C, PCHAR_E, PCHAR_N, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x13b
},{
	//Trainer 0x13c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_A, PCHAR_N, PCHAR_T, PCHAR_o, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x13c
},{
	//Trainer 0x13d
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_J, PCHAR_U, PCHAR_N, PCHAR_I, PCHAR_C, PCHAR_H, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x13d
},{
	//Trainer 0x13e
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_M, PCHAR_E, PCHAR_L, PCHAR_V, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x13e
},{
	//Trainer 0x13f
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_S, PCHAR_A, PCHAR_T, PCHAR_O, PCHAR_R, PCHAR_U, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x13f
},{
	//Trainer 0x140
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_E, PCHAR_D, PCHAR_M, PCHAR_U, PCHAR_N, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x140
},{
	//Trainer 0x141
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_S, PCHAR_H, PCHAR_I, PCHAR_G, PCHAR_E, PCHAR_R, PCHAR_U, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x141
},{
	//Trainer 0x142
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_H, PCHAR_I, PCHAR_R, PCHAR_O, PCHAR_S, PCHAR_H, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x142
},{
	//Trainer 0x143
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_Y, PCHAR_U, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x143
},{
	//Trainer 0x144
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_E, PCHAR_U, PCHAR_G, PCHAR_E, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x144
},{
	//Trainer 0x145
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_K, PCHAR_E, PCHAR_N, PCHAR_J, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x145
},{
	//Trainer 0x146
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE,
	{0x0, false},//Encounter and gender
	0x6a,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x146
},{
	//Trainer 0x147
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE,
	{0x0, false},//Encounter and gender
	0x6a,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x147
},{
	//Trainer 0x148
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE,
	{0x0, false},//Encounter and gender
	0x6a,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x148
},{
	//Trainer 0x149
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE,
	{0x0, false},//Encounter and gender
	0x6a,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERHEILER, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x149
},{
	//Trainer 0x14a
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE,
	{0x0, false},//Encounter and gender
	0x6a,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERHEILER, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x14a
},{
	//Trainer 0x14b
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE,
	{0x0, false},//Encounter and gender
	0x6a,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x14b
},{
	//Trainer 0x14c
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE,
	{0x0, false},//Encounter and gender
	0x6a,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x14c
},{
	//Trainer 0x14d
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE,
	{0x0, false},//Encounter and gender
	0x6a,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x14d
},{
	//Trainer 0x14e
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE,
	{0x0, false},//Encounter and gender
	0x6a,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x14e
},{
	//Trainer 0x14f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_R, PCHAR_a, PCHAR_m, PCHAR_o, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x14f
},{
	//Trainer 0x150
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_M, PCHAR_i, PCHAR_r, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x150
},{
	//Trainer 0x151
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_P, PCHAR_e, PCHAR_n, PCHAR_i, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x151
},{
	//Trainer 0x152
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_E, PCHAR_r, PCHAR_o, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x152
},{
	//Trainer 0x153
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_D, PCHAR_i, PCHAR_e, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x153
},{
	//Trainer 0x154
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_R, PCHAR_o, PCHAR_b, PCHAR_i, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x154
},{
	//Trainer 0x155
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_U, PCHAR_R, PCHAR_I, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x155
},{
	//Trainer 0x156
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_J, PCHAR_O, PCHAR_N, PCHAR_A, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x156
},{
	//Trainer 0x157
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_P, PCHAR_A, PCHAR_T, PCHAR_R, PCHAR_I, PCHAR_C, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x157
},{
	//Trainer 0x158
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_F, PCHAR_A, PCHAR_B, PCHAR_I, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x158
},{
	//Trainer 0x159
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_R, PCHAR_O, PCHAR_N, PCHAR_A, PCHAR_L, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x159
},{
	//Trainer 0x15a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_R, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x15a
},{
	//Trainer 0x15b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_A, PCHAR_N, PCHAR_G, PCHAR_E, PCHAR_L, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x15b
},{
	//Trainer 0x15c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BOSS,
	{0x6, false},//Encounter and gender
	0x6c,//sprite
	{PCHAR_G, PCHAR_I, PCHAR_O, PCHAR_V, PCHAR_A, PCHAR_N, PCHAR_N, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x15c
},{
	//Trainer 0x15d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BOSS,
	{0x6, false},//Encounter and gender
	0x6c,//sprite
	{PCHAR_G, PCHAR_I, PCHAR_O, PCHAR_V, PCHAR_A, PCHAR_N, PCHAR_N, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x15d
},{
	//Trainer 0x15e
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ARENALEITER,
	{0x6, false},//Encounter and gender
	0x6c,//sprite
	{PCHAR_G, PCHAR_I, PCHAR_O, PCHAR_V, PCHAR_A, PCHAR_N, PCHAR_N, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_HYPERTRANK, ITEM_HYPERHEILER, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x15e
},{
	//Trainer 0x15f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x15f
},{
	//Trainer 0x160
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x160
},{
	//Trainer 0x161
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x161
},{
	//Trainer 0x162
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x162
},{
	//Trainer 0x163
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x163
},{
	//Trainer 0x164
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x164
},{
	//Trainer 0x165
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x165
},{
	//Trainer 0x166
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x166
},{
	//Trainer 0x167
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x167
},{
	//Trainer 0x168
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x168
},{
	//Trainer 0x169
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x169
},{
	//Trainer 0x16a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x16a
},{
	//Trainer 0x16b
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x16b
},{
	//Trainer 0x16c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x16c
},{
	//Trainer 0x16d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x16d
},{
	//Trainer 0x16e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x16e
},{
	//Trainer 0x16f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, true},//Encounter and gender
	0x4e,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x16f
},{
	//Trainer 0x170
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x170
},{
	//Trainer 0x171
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x171
},{
	//Trainer 0x172
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x172
},{
	//Trainer 0x173
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x173
},{
	//Trainer 0x174
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x174
},{
	//Trainer 0x175
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x175
},{
	//Trainer 0x176
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, true},//Encounter and gender
	0x1b,//sprite
	{PCHAR_V, PCHAR_O, PCHAR_R, PCHAR_S, PCHAR_DOT, PCHAR_SPACE, PCHAR_R, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x176
},{
	//Trainer 0x177
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x177
},{
	//Trainer 0x178
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x178
},{
	//Trainer 0x179
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x179
},{
	//Trainer 0x17a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x17a
},{
	//Trainer 0x17b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x17b
},{
	//Trainer 0x17c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x17c
},{
	//Trainer 0x17d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x17d
},{
	//Trainer 0x17e
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x17e
},{
	//Trainer 0x17f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x17f
},{
	//Trainer 0x180
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x180
},{
	//Trainer 0x181
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x181
},{
	//Trainer 0x182
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x182
},{
	//Trainer 0x183
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x183
},{
	//Trainer 0x184
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x184
},{
	//Trainer 0x185
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x185
},{
	//Trainer 0x186
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x186
},{
	//Trainer 0x187
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x187
},{
	//Trainer 0x188
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_R, PCHAR_I, PCHAR_C, PCHAR_H, PCHAR_A, PCHAR_R, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_SUPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x188
},{
	//Trainer 0x189
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_N, PCHAR_I, PCHAR_L, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x189
},{
	//Trainer 0x18a
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_D, PCHAR_I, PCHAR_E, PCHAR_G, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x18a
},{
	//Trainer 0x18b
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_J, PCHAR_UE, PCHAR_R, PCHAR_G, PCHAR_E, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x18b
},{
	//Trainer 0x18c
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_N, PCHAR_E, PCHAR_P, PCHAR_O, PCHAR_M, PCHAR_U, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x18c
},{
	//Trainer 0x18d
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_E, PCHAR_R, PCHAR_I, PCHAR_C, PCHAR_H, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x18d
},{
	//Trainer 0x18e
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_R, PCHAR_A, PCHAR_I, PCHAR_M, PCHAR_U, PCHAR_N, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x18e
},{
	//Trainer 0x18f
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_C, PCHAR_H, PCHAR_R, PCHAR_I, PCHAR_S, PCHAR_T, PCHAR_I, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x18f
},{
	//Trainer 0x190
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_H, PCHAR_I, PCHAR_D, PCHAR_E, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x190
},{
	//Trainer 0x191
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_K, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x191
},{
	//Trainer 0x192
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_Y, PCHAR_V, PCHAR_O, PCHAR_N, PCHAR_N, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_SUPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x192
},{
	//Trainer 0x193
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_R, PCHAR_O, PCHAR_L, PCHAR_I, PCHAR_N, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x193
},{
	//Trainer 0x194
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_A, PCHAR_N, PCHAR_N, PCHAR_A, PCHAR_B, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x194
},{
	//Trainer 0x195
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_T, PCHAR_H, PCHAR_E, PCHAR_R, PCHAR_E, PCHAR_S, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x195
},{
	//Trainer 0x196
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_N, PCHAR_A, PCHAR_O, PCHAR_M, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x196
},{
	//Trainer 0x197
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_V, PCHAR_E, PCHAR_R, PCHAR_O, PCHAR_N, PCHAR_I, PCHAR_K, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x197
},{
	//Trainer 0x198
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_G, PCHAR_U, PCHAR_I, PCHAR_D, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x198
},{
	//Trainer 0x199
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_M, PCHAR_I, PCHAR_C, PCHAR_H, PCHAR_A, PCHAR_E, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x199
},{
	//Trainer 0x19a
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TOP_VIER2,
	{0xa, true},//Encounter and gender
	0x70,//sprite
	{PCHAR_L, PCHAR_O, PCHAR_R, PCHAR_E, PCHAR_L, PCHAR_E, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x19a
},{
	//Trainer 0x19b
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TOP_VIER2,
	{0xa, false},//Encounter and gender
	0x71,//sprite
	{PCHAR_B, PCHAR_R, PCHAR_U, PCHAR_N, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x19b
},{
	//Trainer 0x19c
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TOP_VIER2,
	{0xa, true},//Encounter and gender
	0x72,//sprite
	{PCHAR_A, PCHAR_G, PCHAR_A, PCHAR_T, PCHAR_H, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x19c
},{
	//Trainer 0x19d
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TOP_VIER2,
	{0xa, false},//Encounter and gender
	0x73,//sprite
	{PCHAR_S, PCHAR_I, PCHAR_E, PCHAR_G, PCHAR_F, PCHAR_R, PCHAR_I, PCHAR_E, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x19d
},{
	//Trainer 0x19e
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ARENALEITER,
	{0x0, false},//Encounter and gender
	0x74,//sprite
	{PCHAR_L, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x19e
},{
	//Trainer 0x19f
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ARENALEITER,
	{0x1, true},//Encounter and gender
	0x75,//sprite
	{PCHAR_M, PCHAR_i, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERTRANK, ITEM_HYPERHEILER},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x19f
},{
	//Trainer 0x1a0
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ARENALEITER,
	{0x0, false},//Encounter and gender
	0x76,//sprite
	{PCHAR_M, PCHAR_a, PCHAR_n, PCHAR_u, PCHAR_s, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_HYPERHEILER, ITEM_HYPERTRANK, ITEM_HYPERTRANK},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1a0
},{
	//Trainer 0x1a1
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ARENALEITER,
	{0x1, true},//Encounter and gender
	0x77,//sprite
	{PCHAR_T, PCHAR_E, PCHAR_N, PCHAR_E, PCHAR_B, PCHAR_R, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_HYPERHEILER, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1a1
},{
	//Trainer 0x1a2
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ARENALEITER,
	{0x0, false},//Encounter and gender
	0x78,//sprite
	{PCHAR_K, PCHAR_O, PCHAR_G, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_HYPERTRANK, ITEM_HYPERHEILER, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1a2
},{
	//Trainer 0x1a3
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ARENALEITER,
	{0x0, false},//Encounter and gender
	0x79,//sprite
	{PCHAR_I, PCHAR_G, PCHAR_V, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_HYPERTRANK, ITEM_HYPERHEILER, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1a3
},{
	//Trainer 0x1a4
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ARENALEITER,
	{0x1, true},//Encounter and gender
	0x7a,//sprite
	{PCHAR_S, PCHAR_A, PCHAR_B, PCHAR_R, PCHAR_I, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_HYPERTRANK, ITEM_HYPERHEILER, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1a4
},{
	//Trainer 0x1a5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN2,
	{0xd, false},//Encounter and gender
	0x7b,//sprite
	{PCHAR_N, PCHAR_I, PCHAR_K, PCHAR_O, PCHAR_L, PCHAR_A, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1a5
},{
	//Trainer 0x1a6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN2,
	{0xd, false},//Encounter and gender
	0x7b,//sprite
	{PCHAR_A, PCHAR_R, PCHAR_T, PCHAR_U, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1a6
},{
	//Trainer 0x1a7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN2,
	{0xd, false},//Encounter and gender
	0x7b,//sprite
	{PCHAR_C, PCHAR_L, PCHAR_A, PCHAR_U, PCHAR_D, PCHAR_I, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1a7
},{
	//Trainer 0x1a8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN2,
	{0xd, false},//Encounter and gender
	0x7b,//sprite
	{PCHAR_N, PCHAR_O, PCHAR_R, PCHAR_B, PCHAR_E, PCHAR_R, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1a8
},{
	//Trainer 0x1a9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN2,
	{0xd, false},//Encounter and gender
	0x7b,//sprite
	{PCHAR_A, PCHAR_B, PCHAR_R, PCHAR_A, PCHAR_H, PCHAR_A, PCHAR_M, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1a9
},{
	//Trainer 0x1aa
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1aa
},{
	//Trainer 0x1ab
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ab
},{
	//Trainer 0x1ac
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ac
},{
	//Trainer 0x1ad
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ad
},{
	//Trainer 0x1ae
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ae
},{
	//Trainer 0x1af
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1af
},{
	//Trainer 0x1b0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1b0
},{
	//Trainer 0x1b1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1b1
},{
	//Trainer 0x1b2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1b2
},{
	//Trainer 0x1b3
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1b3
},{
	//Trainer 0x1b4
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1b4
},{
	//Trainer 0x1b5
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE2,
	{0x0, false},//Encounter and gender
	0x7c,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1b5
},{
	//Trainer 0x1b6
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CHAMP2,
	{0x0, false},//Encounter and gender
	0x7d,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1b6
},{
	//Trainer 0x1b7
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CHAMP2,
	{0x0, false},//Encounter and gender
	0x7d,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1b7
},{
	//Trainer 0x1b8
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CHAMP2,
	{0x0, false},//Encounter and gender
	0x7d,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1b8
},{
	//Trainer 0x1b9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_W, PCHAR_A, PCHAR_L, PCHAR_B, PCHAR_U, PCHAR_R, PCHAR_G, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1b9
},{
	//Trainer 0x1ba
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_A, PCHAR_N, PCHAR_A, PCHAR_S, PCHAR_T, PCHAR_A, PCHAR_S, PCHAR_I, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ba
},{
	//Trainer 0x1bb
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_T, PCHAR_R, PCHAR_U, PCHAR_D, PCHAR_L, PCHAR_I, PCHAR_N, PCHAR_D, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1bb
},{
	//Trainer 0x1bc
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_P, PCHAR_A, PCHAR_U, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1bc
},{
	//Trainer 0x1bd
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_B, PCHAR_I, PCHAR_R, PCHAR_T, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1bd
},{
	//Trainer 0x1be
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_R, PCHAR_O, PCHAR_S, PCHAR_W, PCHAR_I, PCHAR_T, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1be
},{
	//Trainer 0x1bf
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_B, PCHAR_R, PCHAR_U, PCHAR_N, PCHAR_H, PCHAR_I, PCHAR_L, PCHAR_D, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1bf
},{
	//Trainer 0x1c0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_R, PCHAR_U, PCHAR_T, PCHAR_H, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1c0
},{
	//Trainer 0x1c1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_J, PCHAR_A, PCHAR_I, PCHAR_M, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1c1
},{
	//Trainer 0x1c2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_E, PCHAR_I, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1c2
},{
	//Trainer 0x1c3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_K, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1c3
},{
	//Trainer 0x1c4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_H, PCHAR_A, PCHAR_N, PCHAR_N, PCHAR_E, PCHAR_L, PCHAR_O, PCHAR_R, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1c4
},{
	//Trainer 0x1c5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_A, PCHAR_N, PCHAR_N, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1c5
},{
	//Trainer 0x1c6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN,
	{0x3, true},//Encounter and gender
	0x7b,//sprite
	{PCHAR_N, PCHAR_I, PCHAR_L, PCHAR_O, PCHAR_M, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1c6
},{
	//Trainer 0x1c7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_M, PCHAR_I, PCHAR_R, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1c7
},{
	//Trainer 0x1c8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1c8
},{
	//Trainer 0x1c9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1c9
},{
	//Trainer 0x1ca
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ca
},{
	//Trainer 0x1cb
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1cb
},{
	//Trainer 0x1cc
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1cc
},{
	//Trainer 0x1cd
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1cd
},{
	//Trainer 0x1ce
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_A, PCHAR_M, PCHAR_A, PCHAR_N, PCHAR_D, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ce
},{
	//Trainer 0x1cf
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_S, PCHAR_E, PCHAR_L, PCHAR_I, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1cf
},{
	//Trainer 0x1d0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_EXORZISTIN,
	{0x3, true},//Encounter and gender
	0x7e,//sprite
	{PCHAR_P, PCHAR_A, PCHAR_N, PCHAR_D, PCHAR_O, PCHAR_R, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1d0
},{
	//Trainer 0x1d1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0xb, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_J, PCHAR_E, PCHAR_N, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1d1
},{
	//Trainer 0x1d2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_K, PCHAR_I, PCHAR_R, PCHAR_S, PCHAR_T, PCHAR_E, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1d2
},{
	//Trainer 0x1d3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_J, PCHAR_A, PCHAR_N, PCHAR_K, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1d3
},{
	//Trainer 0x1d4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_T, PCHAR_A, PCHAR_B, PCHAR_I, PCHAR_T, PCHAR_H, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1d4
},{
	//Trainer 0x1d5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_H, PCHAR_I, PCHAR_L, PCHAR_D, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1d5
},{
	//Trainer 0x1d6
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_Z, PCHAR_O, PCHAR_L, PCHAR_T, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1d6
},{
	//Trainer 0x1d7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_I, PCHAR_N, PCHAR_Z, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1d7
},{
	//Trainer 0x1d8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_O, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1d8
},{
	//Trainer 0x1d9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_I, PCHAR_R, PCHAR_E, PCHAR_N, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1d9
},{
	//Trainer 0x1da
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_V, PCHAR_I, PCHAR_C, PCHAR_K, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1da
},{
	//Trainer 0x1db
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_A, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1db
},{
	//Trainer 0x1dc
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_K, PCHAR_E, PCHAR_R, PCHAR_S, PCHAR_T, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1dc
},{
	//Trainer 0x1dd
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_L, PCHAR_A, PCHAR_U, PCHAR_R, PCHAR_E, PCHAR_N, PCHAR_Z, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1dd
},{
	//Trainer 0x1de
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_R, PCHAR_O, PCHAR_X, PCHAR_A, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1de
},{
	//Trainer 0x1df
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_G, PCHAR_U, PCHAR_N, PCHAR_D, PCHAR_U, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1df
},{
	//Trainer 0x1e0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_I, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1e0
},{
	//Trainer 0x1e1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_J, PCHAR_E, PCHAR_N, PCHAR_N, PCHAR_Y, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1e1
},{
	//Trainer 0x1e2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN2,
	{0xd, false},//Encounter and gender
	0x7b,//sprite
	{PCHAR_T, PCHAR_A, PCHAR_N, PCHAR_K, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1e2
},{
	//Trainer 0x1e3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN2,
	{0xd, false},//Encounter and gender
	0x7b,//sprite
	{PCHAR_S, PCHAR_I, PCHAR_L, PCHAR_V, PCHAR_I, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1e3
},{
	//Trainer 0x1e4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ZWIL2,
	{0x9, false},//Encounter and gender
	0x7f,//sprite
	{PCHAR_N, PCHAR_O, PCHAR_R, PCHAR_A, 0x2d, PCHAR_J, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1e4
},{
	//Trainer 0x1e5
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PRIMAPAAR,
	{0x5, false},//Encounter and gender
	0x80,//sprite
	{PCHAR_T, PCHAR_Y, PCHAR_R, PCHAR_O, 0x2d, PCHAR_L, PCHAR_O, PCHAR_R, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1e5
},{
	//Trainer 0x1e6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JUNGES_GLUECK2,
	{0x2, false},//Encounter and gender
	0x81,//sprite
	{PCHAR_S, PCHAR_I, PCHAR_R, PCHAR_A, 0x2d, PCHAR_D, PCHAR_E, PCHAR_N, PCHAR_I, PCHAR_Z, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1e6
},{
	//Trainer 0x1e7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ZWIL2,
	{0x9, false},//Encounter and gender
	0x7f,//sprite
	{PCHAR_B, PCHAR_E, PCHAR_R, PCHAR_T, PCHAR_A, 0x2d, PCHAR_E, PCHAR_N, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1e7
},{
	//Trainer 0x1e8
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENSIPPE,
	{0x4, false},//Encounter and gender
	0x82,//sprite
	{PCHAR_S, PCHAR_E, PCHAR_R, PCHAR_G, PCHAR_I, PCHAR_O, 0x2d, PCHAR_E, PCHAR_V, PCHAR_A, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1e8
},{
	//Trainer 0x1e9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JUNGES_GLUECK2,
	{0x2, false},//Encounter and gender
	0x81,//sprite
	{PCHAR_L, PCHAR_E, PCHAR_N, PCHAR_A, 0x2d, PCHAR_U, PCHAR_W, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1e9
},{
	//Trainer 0x1ea
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GESCHWISTER2,
	{0x8, false},//Encounter and gender
	0x83,//sprite
	{PCHAR_N, PCHAR_O, PCHAR_R, PCHAR_A, 0x2d, PCHAR_T, PCHAR_O, PCHAR_M, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ea
},{
	//Trainer 0x1eb
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GESCHWISTER2,
	{0x8, false},//Encounter and gender
	0x83,//sprite
	{PCHAR_E, PCHAR_W, PCHAR_E, 0x2d, PCHAR_T, PCHAR_O, PCHAR_B, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1eb
},{
	//Trainer 0x1ec
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x0, true},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_I, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ec
},{
	//Trainer 0x1ed
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x0, false},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_I, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ed
},{
	//Trainer 0x1ee
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER,
	{0x0, false},//Encounter and gender
	0x39,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_I, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ee
},{
	//Trainer 0x1ef
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER2,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ef
},{
	//Trainer 0x1f0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER2,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1f0
},{
	//Trainer 0x1f1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER2,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1f1
},{
	//Trainer 0x1f2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_E, PCHAR_G, PCHAR_O, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1f2
},{
	//Trainer 0x1f3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_E, PCHAR_G, PCHAR_O, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1f3
},{
	//Trainer 0x1f4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_J, PCHAR_A, PCHAR_N, PCHAR_N, PCHAR_I, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1f4
},{
	//Trainer 0x1f5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE2,
	{0x1, true},//Encounter and gender
	0x54,//sprite
	{PCHAR_U, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1f5
},{
	//Trainer 0x1f6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE2,
	{0x1, true},//Encounter and gender
	0x54,//sprite
	{PCHAR_U, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1f6
},{
	//Trainer 0x1f7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_F, PCHAR_R, PCHAR_I, PCHAR_E, PCHAR_D, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1f7
},{
	//Trainer 0x1f8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_F, PCHAR_R, PCHAR_I, PCHAR_E, PCHAR_D, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1f8
},{
	//Trainer 0x1f9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_F, PCHAR_R, PCHAR_I, PCHAR_E, PCHAR_D, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1f9
},{
	//Trainer 0x1fa
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_J, PCHAR_A, PCHAR_N, PCHAR_N, PCHAR_I, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1fa
},{
	//Trainer 0x1fb
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE2,
	{0x1, true},//Encounter and gender
	0x54,//sprite
	{PCHAR_R, PCHAR_I, PCHAR_C, PCHAR_A, PCHAR_R, PCHAR_D, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1fb
},{
	//Trainer 0x1fc
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE2,
	{0x1, true},//Encounter and gender
	0x54,//sprite
	{PCHAR_R, PCHAR_I, PCHAR_C, PCHAR_A, PCHAR_R, PCHAR_D, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1fc
},{
	//Trainer 0x1fd
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_J, PCHAR_A, PCHAR_N, PCHAR_N, PCHAR_I, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1fd
},{
	//Trainer 0x1fe
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0xb, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_S, PCHAR_P, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1fe
},{
	//Trainer 0x1ff
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_PROF,
	{0x0, false},//Encounter and gender
	0x84,//sprite
	{PCHAR_P, PCHAR_R, PCHAR_O, PCHAR_F, PCHAR_DOT, PCHAR_SPACE, PCHAR_E, PCHAR_I, PCHAR_C, PCHAR_H, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x1ff
},{
	//Trainer 0x200
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER2,
	{0x0, false},//Encounter and gender
	0x85,//sprite
	{PCHAR_B, PCHAR_R, PCHAR_I, PCHAR_X, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x200
},{
	//Trainer 0x201
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER2,
	{0x1, false},//Encounter and gender
	0x86,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_I, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x201
},{
	//Trainer 0x202
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER2,
	{0x0, false},//Encounter and gender
	0x87,//sprite
	{PCHAR_R, PCHAR_O, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x202
},{
	//Trainer 0x203
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER2,
	{0x1, false},//Encounter and gender
	0x88,//sprite
	{PCHAR_B, PCHAR_L, PCHAR_A, PCHAR_T, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x203
},{
	//Trainer 0x204
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x89,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x204
},{
	//Trainer 0x205
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO2,
	{0x4, true},//Encounter and gender
	0x8a,//sprite
	{PCHAR_C, PCHAR_O, PCHAR_S, PCHAR_I, PCHAR_M, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x205
},{
	//Trainer 0x206
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENMAEDEL,
	{0x4, false},//Encounter and gender
	0x8b,//sprite
	{PCHAR_G, PCHAR_U, PCHAR_D, PCHAR_R, PCHAR_U, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x206
},{
	//Trainer 0x207
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PLANSCHER3,
	{0x2, false},//Encounter and gender
	0x8c,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x207
},{
	//Trainer 0x208
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_ZUECHTER2,
	{0x1, false},//Encounter and gender
	0x8d,//sprite
	{PCHAR_E, PCHAR_L, PCHAR_E, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x208
},{
	//Trainer 0x209
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER2,
	{0x5, false},//Encounter and gender
	0x8e,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_F, PCHAR_O, PCHAR_N, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x209
},{
	//Trainer 0x20a
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER2,
	{0x5, true},//Encounter and gender
	0x8f,//sprite
	{PCHAR_S, PCHAR_A, PCHAR_S, PCHAR_K, PCHAR_I, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x20a
},{
	//Trainer 0x20b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY2,
	{0x1, true},//Encounter and gender
	0x90,//sprite
	{PCHAR_A, PCHAR_S, PCHAR_T, PCHAR_R, PCHAR_I, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x20b
},{
	//Trainer 0x20c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RUINENMANIAC2,
	{0xb, false},//Encounter and gender
	0x91,//sprite
	{PCHAR_S, PCHAR_OE, PCHAR_R, PCHAR_E, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x20c
},{
	//Trainer 0x20d
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_LADY2,
	{0x1, false},//Encounter and gender
	0x92,//sprite
	{PCHAR_K, PCHAR_O, PCHAR_R, PCHAR_N, PCHAR_E, PCHAR_L, PCHAR_I, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x20d
},{
	//Trainer 0x20e
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MALERIN,
	{0x1, false},//Encounter and gender
	0x93,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_G, PCHAR_A, PCHAR_R, PCHAR_E, PCHAR_T, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x20e
},{
	//Trainer 0x20f
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_S, PCHAR_C, PCHAR_H, PCHAR_L, PCHAR_AE, PCHAR_G, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x20f
},{
	//Trainer 0x210
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_S, PCHAR_C, PCHAR_H, PCHAR_L, PCHAR_AE, PCHAR_G, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x210
},{
	//Trainer 0x211
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_S, PCHAR_C, PCHAR_H, PCHAR_L, PCHAR_AE, PCHAR_G, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x211
},{
	//Trainer 0x212
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x212
},{
	//Trainer 0x213
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER2,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{PCHAR_E, PCHAR_M, PCHAR_I, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x213
},{
	//Trainer 0x214
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER2,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{PCHAR_H, PCHAR_I, PCHAR_L, PCHAR_M, PCHAR_A, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x214
},{
	//Trainer 0x215
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ZWIL2,
	{0x9, false},//Encounter and gender
	0x7f,//sprite
	{PCHAR_N, PCHAR_O, PCHAR_R, PCHAR_A, 0x2d, PCHAR_J, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x215
},{
	//Trainer 0x216
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x216
},{
	//Trainer 0x217
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RIVALE,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_C, PCHAR_A, PCHAR_R, PCHAR_S, PCHAR_T, PCHAR_E, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x217
},{
	//Trainer 0x218
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_M, PCHAR_I, PCHAR_L, PCHAR_L, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x218
},{
	//Trainer 0x219
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x219
},{
	//Trainer 0x21a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x21a
},{
	//Trainer 0x21b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x21b
},{
	//Trainer 0x21c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x21c
},{
	//Trainer 0x21d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x21d
},{
	//Trainer 0x21e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x21e
},{
	//Trainer 0x21f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x1b,//sprite
	{PCHAR_V, PCHAR_O, PCHAR_R, PCHAR_S, PCHAR_DOT, PCHAR_SPACE, PCHAR_R, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x21f
},{
	//Trainer 0x220
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_V, PCHAR_O, PCHAR_R, PCHAR_S, PCHAR_DOT, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x220
},{
	//Trainer 0x221
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_FORSCHER,
	{0x3, false},//Encounter and gender
	0x6b,//sprite
	{PCHAR_I, PCHAR_N, PCHAR_G, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x221
},{
	//Trainer 0x222
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_U, PCHAR_L, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x222
},{
	//Trainer 0x223
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_J, PCHAR_U, PCHAR_T, PCHAR_T, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x223
},{
	//Trainer 0x224
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_I, PCHAR_R, PCHAR_M, PCHAR_G, PCHAR_A, PCHAR_R, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x224
},{
	//Trainer 0x225
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_I, PCHAR_S, PCHAR_A, PCHAR_A, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x225
},{
	//Trainer 0x226
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_M, PCHAR_I, PCHAR_C, PCHAR_H, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x226
},{
	//Trainer 0x227
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER3,
	{0xb, false},//Encounter and gender
	0x5e,//sprite
	{PCHAR_D, PCHAR_O, PCHAR_M, PCHAR_I, PCHAR_N, PCHAR_I, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x227
},{
	//Trainer 0x228
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENMAEDEL,
	{0x4, false},//Encounter and gender
	0x8b,//sprite
	{PCHAR_E, PCHAR_M, PCHAR_I, PCHAR_L, PCHAR_I, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x228
},{
	//Trainer 0x229
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_F, PCHAR_R, PCHAR_E, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x229
},{
	//Trainer 0x22a
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_E, PCHAR_N, PCHAR_R, PCHAR_I, PCHAR_C, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x22a
},{
	//Trainer 0x22b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_D, PCHAR_A, PCHAR_N, PCHAR_I, PCHAR_L, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x22b
},{
	//Trainer 0x22c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_K, PCHAR_L, PCHAR_A, PCHAR_R, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x22c
},{
	//Trainer 0x22d
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENSIPPE,
	{0x4, false},//Encounter and gender
	0x82,//sprite
	{PCHAR_D, PCHAR_I, PCHAR_R, PCHAR_K, 0x2d, PCHAR_H, PCHAR_E, PCHAR_I, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x22d
},{
	//Trainer 0x22e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY2,
	{0x1, true},//Encounter and gender
	0x90,//sprite
	{PCHAR_E, PCHAR_R, PCHAR_I, PCHAR_K, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x22e
},{
	//Trainer 0x22f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PLANSCHER3,
	{0x2, false},//Encounter and gender
	0x8c,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_E, PCHAR_X, PCHAR_I, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x22f
},{
	//Trainer 0x230
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ZWIL2,
	{0x9, false},//Encounter and gender
	0x7f,//sprite
	{PCHAR_U, PCHAR_T, PCHAR_E, 0x2d, PCHAR_I, PCHAR_D, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x230
},{
	//Trainer 0x231
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_I, PCHAR_M, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x231
},{
	//Trainer 0x232
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MALERIN,
	{0x1, false},//Encounter and gender
	0x93,//sprite
	{PCHAR_D, PCHAR_O, PCHAR_R, PCHAR_E, PCHAR_E, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x232
},{
	//Trainer 0x233
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MALERIN,
	{0x1, false},//Encounter and gender
	0x93,//sprite
	{PCHAR_D, PCHAR_O, PCHAR_R, PCHAR_O, PCHAR_T, PCHAR_H, PCHAR_E, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x233
},{
	//Trainer 0x234
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_LADY2,
	{0x1, false},//Encounter and gender
	0x92,//sprite
	{PCHAR_G, PCHAR_E, PCHAR_S, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x234
},{
	//Trainer 0x235
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_D, PCHAR_R, PCHAR_U, PCHAR_D, PCHAR_I, PCHAR_L, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x235
},{
	//Trainer 0x236
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_T, PCHAR_O, PCHAR_B, PCHAR_I, PCHAR_A, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x236
},{
	//Trainer 0x237
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x237
},{
	//Trainer 0x238
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x6d,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x238
},{
	//Trainer 0x239
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEAM_VIOLET,
	{0x6, false},//Encounter and gender
	0x89,//sprite
	{PCHAR_R, PCHAR_UE, PCHAR_P, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x239
},{
	//Trainer 0x23a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_D, PCHAR_O, PCHAR_N, PCHAR_A, PCHAR_T, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x23a
},{
	//Trainer 0x23b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_M, PCHAR_I, PCHAR_C, PCHAR_H, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x23b
},{
	//Trainer 0x23c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_H, PCHAR_A, PCHAR_R, PCHAR_A, PCHAR_L, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x23c
},{
	//Trainer 0x23d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER3,
	{0xb, false},//Encounter and gender
	0x5e,//sprite
	{PCHAR_U, PCHAR_L, PCHAR_A, PCHAR_N, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x23d
},{
	//Trainer 0x23e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_E, PCHAR_X, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x23e
},{
	//Trainer 0x23f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_N, PCHAR_I, PCHAR_C, PCHAR_O, PCHAR_L, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x23f
},{
	//Trainer 0x240
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GESCHWISTER2,
	{0x8, false},//Encounter and gender
	0x83,//sprite
	{PCHAR_T, PCHAR_I, PCHAR_N, PCHAR_O, 0x2d, PCHAR_T, PCHAR_I, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x240
},{
	//Trainer 0x241
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY2,
	{0x1, true},//Encounter and gender
	0x90,//sprite
	{PCHAR_R, PCHAR_O, PCHAR_S, PCHAR_E, PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x241
},{
	//Trainer 0x242
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_S, PCHAR_A, PCHAR_M, PCHAR_I, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x242
},{
	//Trainer 0x243
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_D, PCHAR_E, PCHAR_N, PCHAR_I, PCHAR_S, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x243
},{
	//Trainer 0x244
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ZWIL2,
	{0x9, false},//Encounter and gender
	0x7f,//sprite
	{PCHAR_L, PCHAR_E, PCHAR_A, 0x2d, PCHAR_M, PCHAR_I, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x244
},{
	//Trainer 0x245
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0xb, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_T, PCHAR_I, PCHAR_T, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x245
},{
	//Trainer 0x246
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RUINENMANIAC2,
	{0xb, false},//Encounter and gender
	0x91,//sprite
	{PCHAR_R, PCHAR_U, PCHAR_B, PCHAR_E, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x246
},{
	//Trainer 0x247
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RUINENMANIAC2,
	{0xb, false},//Encounter and gender
	0x91,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_R, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x247
},{
	//Trainer 0x248
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0xb, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_D, PCHAR_A, PCHAR_N, PCHAR_T, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x248
},{
	//Trainer 0x249
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_POKEMANIAC2,
	{0x3, false},//Encounter and gender
	0x58,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_K, PCHAR_T, PCHAR_O, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x249
},{
	//Trainer 0x24a
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO2,
	{0x4, false},//Encounter and gender
	0x64,//sprite
	{PCHAR_D, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x24a
},{
	//Trainer 0x24b
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO2,
	{0x4, true},//Encounter and gender
	0x8a,//sprite
	{PCHAR_R, PCHAR_A, PCHAR_O, PCHAR_U, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x24b
},{
	//Trainer 0x24c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_AROMALADY2,
	{0x1, true},//Encounter and gender
	0x90,//sprite
	{PCHAR_I, PCHAR_L, PCHAR_S, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x24c
},{
	//Trainer 0x24d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JUNGES_GLUECK2,
	{0x2, false},//Encounter and gender
	0x81,//sprite
	{PCHAR_T, PCHAR_I, PCHAR_Z, PCHAR_I, PCHAR_A, 0x2d, PCHAR_T, PCHAR_I, PCHAR_L, PCHAR_L, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x24d
},{
	//Trainer 0x24e
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JONGLEUR,
	{0xb, false},//Encounter and gender
	0x66,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_E, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x24e
},{
	//Trainer 0x24f
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENMAEDEL,
	{0x4, false},//Encounter and gender
	0x8b,//sprite
	{PCHAR_E, PCHAR_L, PCHAR_F, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x24f
},{
	//Trainer 0x250
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENMAEDEL,
	{0x4, false},//Encounter and gender
	0x8b,//sprite
	{PCHAR_N, PCHAR_O, PCHAR_U, PCHAR_R, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x250
},{
	//Trainer 0x251
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DOMPTEUR,
	{0xb, false},//Encounter and gender
	0x67,//sprite
	{PCHAR_T, PCHAR_o, PCHAR_n, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x251
},{
	//Trainer 0x252
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_POKEMANIAC2,
	{0x3, false},//Encounter and gender
	0x58,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x252
},{
	//Trainer 0x253
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER2,
	{0x5, false},//Encounter and gender
	0x8e,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x253
},{
	//Trainer 0x254
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER2,
	{0x5, false},//Encounter and gender
	0x8e,//sprite
	{PCHAR_E, PCHAR_C, PCHAR_K, PCHAR_B, PCHAR_E, PCHAR_R, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x254
},{
	//Trainer 0x255
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER2,
	{0x5, true},//Encounter and gender
	0x8f,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_M, PCHAR_U, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x255
},{
	//Trainer 0x256
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER2,
	{0x5, true},//Encounter and gender
	0x8f,//sprite
	{PCHAR_M, PCHAR_E, PCHAR_C, PCHAR_H, PCHAR_T, PCHAR_H, PCHAR_I, PCHAR_L, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x256
},{
	//Trainer 0x257
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_O, PCHAR_T, PCHAR_M, PCHAR_A, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x257
},{
	//Trainer 0x258
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_M, PCHAR_I, PCHAR_C, PCHAR_H, PCHAR_E, PCHAR_L, PCHAR_L, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x258
},{
	//Trainer 0x259
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PRIMAPAAR,
	{0x5, false},//Encounter and gender
	0x80,//sprite
	{PCHAR_O, PCHAR_L, PCHAR_E, 0x2d, PCHAR_G, PCHAR_R, PCHAR_I, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x259
},{
	//Trainer 0x25a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RUINENMANIAC2,
	{0xb, false},//Encounter and gender
	0x91,//sprite
	{PCHAR_B, PCHAR_R, PCHAR_U, PCHAR_N, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x25a
},{
	//Trainer 0x25b
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RUINENMANIAC2,
	{0xb, false},//Encounter and gender
	0x91,//sprite
	{PCHAR_E, PCHAR_G, PCHAR_I, PCHAR_D, PCHAR_I, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x25b
},{
	//Trainer 0x25c
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MALERIN,
	{0x1, false},//Encounter and gender
	0x93,//sprite
	{PCHAR_E, PCHAR_D, PCHAR_I, PCHAR_T, PCHAR_H, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x25c
},{
	//Trainer 0x25d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GENTLEMAN2,
	{0xd, false},//Encounter and gender
	0x7b,//sprite
	{PCHAR_T, PCHAR_O, PCHAR_M, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x25d
},{
	//Trainer 0x25e
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_LADY2,
	{0x1, false},//Encounter and gender
	0x92,//sprite
	{PCHAR_K, PCHAR_E, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x25e
},{
	//Trainer 0x25f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RUINENMANIAC2,
	{0xb, false},//Encounter and gender
	0x91,//sprite
	{PCHAR_W, PCHAR_O, PCHAR_L, PCHAR_F, PCHAR_G, PCHAR_A, PCHAR_N, PCHAR_G, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x25f
},{
	//Trainer 0x260
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO2,
	{0x4, true},//Encounter and gender
	0x8a,//sprite
	{PCHAR_L, PCHAR_A, PCHAR_U, PCHAR_R, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x260
},{
	//Trainer 0x261
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_ZUECHTER2,
	{0x1, false},//Encounter and gender
	0x8d,//sprite
	{PCHAR_E, PCHAR_V, PCHAR_E, PCHAR_L, PCHAR_Y, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x261
},{
	//Trainer 0x262
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_ZUECHTER2,
	{0x1, false},//Encounter and gender
	0x8d,//sprite
	{PCHAR_L, PCHAR_O, PCHAR_T, PCHAR_T, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x262
},{
	//Trainer 0x263
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER2,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x263
},{
	//Trainer 0x264
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER2,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{PCHAR_O, PCHAR_L, PCHAR_O, PCHAR_F, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x264
},{
	//Trainer 0x265
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER2,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{PCHAR_Y, PCHAR_O, PCHAR_R, PCHAR_I, PCHAR_C, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x265
},{
	//Trainer 0x266
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_I, PCHAR_W, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x266
},{
	//Trainer 0x267
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_Z, PCHAR_E, PCHAR_N, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x267
},{
	//Trainer 0x268
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE2,
	{0x1, true},//Encounter and gender
	0x54,//sprite
	{PCHAR_Y, PCHAR_V, PCHAR_E, PCHAR_T, PCHAR_T, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x268
},{
	//Trainer 0x269
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE2,
	{0x1, true},//Encounter and gender
	0x54,//sprite
	{PCHAR_Z, PCHAR_E, PCHAR_N, PCHAR_Z, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x269
},{
	//Trainer 0x26a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_C, PCHAR_L, PCHAR_I, PCHAR_F, PCHAR_F, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x26a
},{
	//Trainer 0x26b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_J, PCHAR_a, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x26b
},{
	//Trainer 0x26c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RUINENMANIAC2,
	{0xb, false},//Encounter and gender
	0x91,//sprite
	{PCHAR_S, PCHAR_E, PCHAR_B, PCHAR_A, PCHAR_S, PCHAR_T, PCHAR_I, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x26c
},{
	//Trainer 0x26d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_R, PCHAR_U, PCHAR_T, PCHAR_H, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x26d
},{
	//Trainer 0x26e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_R, PCHAR_U, PCHAR_T, PCHAR_H, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x26e
},{
	//Trainer 0x26f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_R, PCHAR_U, PCHAR_T, PCHAR_H, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x26f
},{
	//Trainer 0x270
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_G, PCHAR_UE, PCHAR_N, PCHAR_T, PCHAR_H, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x270
},{
	//Trainer 0x271
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_G, PCHAR_UE, PCHAR_N, PCHAR_T, PCHAR_H, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x271
},{
	//Trainer 0x272
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_G, PCHAR_UE, PCHAR_N, PCHAR_T, PCHAR_H, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x272
},{
	//Trainer 0x273
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_R, PCHAR_A, PCHAR_P, PCHAR_H, PCHAR_A, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x273
},{
	//Trainer 0x274
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_R, PCHAR_A, PCHAR_P, PCHAR_H, PCHAR_A, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x274
},{
	//Trainer 0x275
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_R, PCHAR_A, PCHAR_P, PCHAR_H, PCHAR_A, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x275
},{
	//Trainer 0x276
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_D, PCHAR_W, PCHAR_I, PCHAR_G, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x276
},{
	//Trainer 0x277
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_D, PCHAR_W, PCHAR_I, PCHAR_G, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x277
},{
	//Trainer 0x278
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_D, PCHAR_W, PCHAR_I, PCHAR_G, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x278
},{
	//Trainer 0x279
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_V, PCHAR_A, PCHAR_L, PCHAR_E, PCHAR_N, PCHAR_T, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x279
},{
	//Trainer 0x27a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_V, PCHAR_A, PCHAR_L, PCHAR_E, PCHAR_N, PCHAR_T, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x27a
},{
	//Trainer 0x27b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MECHANIKER,
	{0x0, false},//Encounter and gender
	0x5d,//sprite
	{PCHAR_H, PCHAR_A, PCHAR_S, PCHAR_S, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x27b
},{
	//Trainer 0x27c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER,
	{0x0, false},//Encounter and gender
	0x61,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_C, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x27c
},{
	//Trainer 0x27d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_C, PCHAR_H, PCHAR_R, PCHAR_I, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x27d
},{
	//Trainer 0x27e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_C, PCHAR_H, PCHAR_R, PCHAR_I, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x27e
},{
	//Trainer 0x27f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CAMPER2,
	{0x0, false},//Encounter and gender
	0x56,//sprite
	{PCHAR_C, PCHAR_H, PCHAR_R, PCHAR_I, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x27f
},{
	//Trainer 0x280
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_I, PCHAR_N, PCHAR_G, PCHAR_E, PCHAR_B, PCHAR_O, PCHAR_R, PCHAR_G, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x280
},{
	//Trainer 0x281
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_I, PCHAR_N, PCHAR_G, PCHAR_E, PCHAR_B, PCHAR_O, PCHAR_R, PCHAR_G, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x281
},{
	//Trainer 0x282
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_I, PCHAR_N, PCHAR_G, PCHAR_E, PCHAR_B, PCHAR_O, PCHAR_R, PCHAR_G, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x282
},{
	//Trainer 0x283
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0xb, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_J, PCHAR_E, PCHAR_N, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x283
},{
	//Trainer 0x284
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_POKEMANIAC2,
	{0x3, false},//Encounter and gender
	0x58,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x284
},{
	//Trainer 0x285
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_POKEMANIAC2,
	{0x3, false},//Encounter and gender
	0x58,//sprite
	{PCHAR_B, PCHAR_E, PCHAR_N, PCHAR_N, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x285
},{
	//Trainer 0x286
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_POKEMANIAC2,
	{0x3, false},//Encounter and gender
	0x58,//sprite
	{PCHAR_B, PCHAR_E, PCHAR_N, PCHAR_N, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x286
},{
	//Trainer 0x287
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0xb, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_I, PCHAR_M, PCHAR_K, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x287
},{
	//Trainer 0x288
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE2,
	{0x1, true},//Encounter and gender
	0x54,//sprite
	{PCHAR_L, PCHAR_E, PCHAR_I, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x288
},{
	//Trainer 0x289
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GOERE2,
	{0x1, true},//Encounter and gender
	0x54,//sprite
	{PCHAR_L, PCHAR_E, PCHAR_I, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x289
},{
	//Trainer 0x28a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_STREBER,
	{0x3, false},//Encounter and gender
	0x59,//sprite
	{PCHAR_G, PCHAR_E, PCHAR_R, PCHAR_R, PCHAR_I, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x28a
},{
	//Trainer 0x28b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SPIELER,
	{0x0, false},//Encounter and gender
	0x61,//sprite
	{PCHAR_R, PCHAR_I, PCHAR_C, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x28b
},{
	//Trainer 0x28c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_M, PCHAR_I, PCHAR_L, PCHAR_L, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x28c
},{
	//Trainer 0x28d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER3,
	{0xb, false},//Encounter and gender
	0x5e,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_O, PCHAR_I, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x28d
},{
	//Trainer 0x28e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ROCKER,
	{0x0, false},//Encounter and gender
	0x65,//sprite
	{PCHAR_X, PCHAR_A, PCHAR_V, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x28e
},{
	//Trainer 0x28f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT2,
	{0x1, true},//Encounter and gender
	0x62,//sprite
	{PCHAR_S, PCHAR_Y, PCHAR_L, PCHAR_V, PCHAR_I, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x28f
},{
	//Trainer 0x290
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_F, PCHAR_R, PCHAR_I, PCHAR_T, PCHAR_J, PCHAR_O, PCHAR_F, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x290
},{
	//Trainer 0x291
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_F, PCHAR_R, PCHAR_I, PCHAR_T, PCHAR_J, PCHAR_O, PCHAR_F, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x291
},{
	//Trainer 0x292
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_J, PCHAR_A, PCHAR_N, PCHAR_K, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x292
},{
	//Trainer 0x293
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_J, PCHAR_A, PCHAR_N, PCHAR_K, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x293
},{
	//Trainer 0x294
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_J, PCHAR_A, PCHAR_N, PCHAR_K, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x294
},{
	//Trainer 0x295
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_D, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x295
},{
	//Trainer 0x296
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_G, PCHAR_E, PCHAR_N, PCHAR_A, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x296
},{
	//Trainer 0x297
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_G, PCHAR_E, PCHAR_N, PCHAR_A, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x297
},{
	//Trainer 0x298
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_A, PCHAR_N, PCHAR_T, PCHAR_o, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x298
},{
	//Trainer 0x299
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_A, PCHAR_N, PCHAR_T, PCHAR_o, PCHAR_n, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x299
},{
	//Trainer 0x29a
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHOENHEIT2,
	{0x1, true},//Encounter and gender
	0x62,//sprite
	{PCHAR_I, PCHAR_L, PCHAR_O, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x29a
},{
	//Trainer 0x29b
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_V, PCHAR_I, PCHAR_T, PCHAR_A, PCHAR_L, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x29b
},{
	//Trainer 0x29c
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_V, PCHAR_I, PCHAR_T, PCHAR_A, PCHAR_L, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x29c
},{
	//Trainer 0x29d
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_I, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x29d
},{
	//Trainer 0x29e
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_I, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x29e
},{
	//Trainer 0x29f
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_I, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x29f
},{
	//Trainer 0x2a0
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENSIPPE,
	{0x4, false},//Encounter and gender
	0x82,//sprite
	{PCHAR_S, PCHAR_E, PCHAR_R, PCHAR_G, PCHAR_I, PCHAR_O, 0x2d, PCHAR_E, PCHAR_V, PCHAR_A, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2a0
},{
	//Trainer 0x2a1
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENSIPPE,
	{0x4, false},//Encounter and gender
	0x82,//sprite
	{PCHAR_S, PCHAR_E, PCHAR_R, PCHAR_G, PCHAR_I, PCHAR_O, 0x2d, PCHAR_E, PCHAR_V, PCHAR_A, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2a1
},{
	//Trainer 0x2a2
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENSIPPE,
	{0x4, false},//Encounter and gender
	0x82,//sprite
	{PCHAR_S, PCHAR_E, PCHAR_R, PCHAR_G, PCHAR_I, PCHAR_O, 0x2d, PCHAR_E, PCHAR_V, PCHAR_A, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2a2
},{
	//Trainer 0x2a3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_T, PCHAR_R, PCHAR_U, PCHAR_T, PCHAR_Z, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2a3
},{
	//Trainer 0x2a4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_V, PCHAR_O, PCHAR_L, PCHAR_K, PCHAR_E, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2a4
},{
	//Trainer 0x2a5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_BIKER,
	{0x0, false},//Encounter and gender
	0x5b,//sprite
	{PCHAR_K, PCHAR_O, PCHAR_N, PCHAR_R, PCHAR_A, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2a5
},{
	//Trainer 0x2a6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_S, PCHAR_P, PCHAR_A, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2a6
},{
	//Trainer 0x2a7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_H, PCHAR_A, PCHAR_J, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2a7
},{
	//Trainer 0x2a8
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_R, PCHAR_O, PCHAR_M, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2a8
},{
	//Trainer 0x2a9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_R, PCHAR_O, PCHAR_M, PCHAR_A, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2a9
},{
	//Trainer 0x2aa
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_I, PCHAR_C, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2aa
},{
	//Trainer 0x2ab
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_N, PCHAR_U, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2ab
},{
	//Trainer 0x2ac
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_O, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2ac
},{
	//Trainer 0x2ad
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PICKNICKER2,
	{0x2, true},//Encounter and gender
	0x57,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_O, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2ad
},{
	//Trainer 0x2ae
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ANGLER3,
	{0xb, false},//Encounter and gender
	0x5e,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_A, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2ae
},{
	//Trainer 0x2af
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_P, PCHAR_E, PCHAR_D, PCHAR_R, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2af
},{
	//Trainer 0x2b0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GESCHWISTER2,
	{0x8, false},//Encounter and gender
	0x83,//sprite
	{PCHAR_E, PCHAR_W, PCHAR_E, 0x2d, PCHAR_T, PCHAR_O, PCHAR_B, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2b0
},{
	//Trainer 0x2b1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GESCHWISTER2,
	{0x8, false},//Encounter and gender
	0x83,//sprite
	{PCHAR_E, PCHAR_W, PCHAR_E, 0x2d, PCHAR_T, PCHAR_O, PCHAR_B, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2b1
},{
	//Trainer 0x2b2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_I, PCHAR_S, PCHAR_A, PCHAR_A, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2b2
},{
	//Trainer 0x2b3
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENMAEDEL,
	{0x4, false},//Encounter and gender
	0x8b,//sprite
	{PCHAR_G, PCHAR_U, PCHAR_D, PCHAR_R, PCHAR_U, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2b3
},{
	//Trainer 0x2b4
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENMAEDEL,
	{0x4, false},//Encounter and gender
	0x8b,//sprite
	{PCHAR_G, PCHAR_U, PCHAR_D, PCHAR_R, PCHAR_U, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2b4
},{
	//Trainer 0x2b5
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENMAEDEL,
	{0x4, false},//Encounter and gender
	0x8b,//sprite
	{PCHAR_E, PCHAR_M, PCHAR_I, PCHAR_L, PCHAR_I, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2b5
},{
	//Trainer 0x2b6
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENMAEDEL,
	{0x4, false},//Encounter and gender
	0x8b,//sprite
	{PCHAR_E, PCHAR_M, PCHAR_I, PCHAR_L, PCHAR_I, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2b6
},{
	//Trainer 0x2b7
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_F, PCHAR_R, PCHAR_E, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2b7
},{
	//Trainer 0x2b8
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_F, PCHAR_R, PCHAR_E, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2b8
},{
	//Trainer 0x2b9
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_E, PCHAR_N, PCHAR_R, PCHAR_I, PCHAR_C, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2b9
},{
	//Trainer 0x2ba
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWARZGURT2,
	{0x4, false},//Encounter and gender
	0x69,//sprite
	{PCHAR_E, PCHAR_N, PCHAR_R, PCHAR_I, PCHAR_C, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2ba
},{
	//Trainer 0x2bb
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENSIPPE,
	{0x4, false},//Encounter and gender
	0x82,//sprite
	{PCHAR_D, PCHAR_I, PCHAR_R, PCHAR_K, 0x2d, PCHAR_H, PCHAR_E, PCHAR_I, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2bb
},{
	//Trainer 0x2bc
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENSIPPE,
	{0x4, false},//Encounter and gender
	0x82,//sprite
	{PCHAR_D, PCHAR_I, PCHAR_R, PCHAR_K, 0x2d, PCHAR_H, PCHAR_E, PCHAR_I, PCHAR_D, PCHAR_I, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2bc
},{
	//Trainer 0x2bd
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PLANSCHER3,
	{0x2, false},//Encounter and gender
	0x8c,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2bd
},{
	//Trainer 0x2be
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ZWIL2,
	{0x9, false},//Encounter and gender
	0x7f,//sprite
	{PCHAR_U, PCHAR_T, PCHAR_E, 0x2d, PCHAR_I, PCHAR_D, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2be
},{
	//Trainer 0x2bf
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MALERIN,
	{0x1, false},//Encounter and gender
	0x93,//sprite
	{PCHAR_D, PCHAR_O, PCHAR_R, PCHAR_O, PCHAR_T, PCHAR_H, PCHAR_E, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2bf
},{
	//Trainer 0x2c0
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TEENAGER2,
	{0x0, false},//Encounter and gender
	0x52,//sprite
	{PCHAR_D, PCHAR_R, PCHAR_U, PCHAR_D, PCHAR_I, PCHAR_L, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2c0
},{
	//Trainer 0x2c1
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_ZUECHTER2,
	{0x1, false},//Encounter and gender
	0x8d,//sprite
	{PCHAR_E, PCHAR_L, PCHAR_E, PCHAR_N, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2c1
},{
	//Trainer 0x2c2
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JUNGES_GLUECK2,
	{0x2, false},//Encounter and gender
	0x81,//sprite
	{PCHAR_S, PCHAR_I, PCHAR_R, PCHAR_A, 0x2d, PCHAR_D, PCHAR_E, PCHAR_N, PCHAR_I, PCHAR_Z, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2c2
},{
	//Trainer 0x2c3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JUNGES_GLUECK2,
	{0x2, false},//Encounter and gender
	0x81,//sprite
	{PCHAR_S, PCHAR_I, PCHAR_R, PCHAR_A, 0x2d, PCHAR_D, PCHAR_E, PCHAR_N, PCHAR_I, PCHAR_Z, 0xff, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2c3
},{
	//Trainer 0x2c4
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_D, PCHAR_O, PCHAR_N, PCHAR_A, PCHAR_T, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2c4
},{
	//Trainer 0x2c5
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_M, PCHAR_I, PCHAR_C, PCHAR_H, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2c5
},{
	//Trainer 0x2c6
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_VOGELFAENGER2,
	{0x5, false},//Encounter and gender
	0x68,//sprite
	{PCHAR_H, PCHAR_A, PCHAR_R, PCHAR_A, PCHAR_L, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2c6
},{
	//Trainer 0x2c7
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_N, PCHAR_I, PCHAR_C, PCHAR_O, PCHAR_L, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2c7
},{
	//Trainer 0x2c8
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO2,
	{0x4, true},//Encounter and gender
	0x8a,//sprite
	{PCHAR_C, PCHAR_O, PCHAR_S, PCHAR_I, PCHAR_M, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2c8
},{
	//Trainer 0x2c9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_S, PCHAR_A, PCHAR_M, PCHAR_I, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2c9
},{
	//Trainer 0x2ca
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_WANDERER,
	{0xb, false},//Encounter and gender
	0x5a,//sprite
	{PCHAR_T, PCHAR_I, PCHAR_T, PCHAR_U, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2ca
},{
	//Trainer 0x2cb
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_RUINENMANIAC2,
	{0xb, false},//Encounter and gender
	0x91,//sprite
	{PCHAR_K, PCHAR_A, PCHAR_R, PCHAR_E, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2cb
},{
	//Trainer 0x2cc
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_POKEMANIAC2,
	{0x3, false},//Encounter and gender
	0x58,//sprite
	{PCHAR_H, PCHAR_E, PCHAR_K, PCHAR_T, PCHAR_O, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2cc
},{
	//Trainer 0x2cd
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO2,
	{0x4, false},//Encounter and gender
	0x64,//sprite
	{PCHAR_D, PCHAR_A, PCHAR_R, PCHAR_I, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2cd
},{
	//Trainer 0x2ce
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PSYCHO2,
	{0x4, true},//Encounter and gender
	0x8a,//sprite
	{PCHAR_R, PCHAR_A, PCHAR_O, PCHAR_U, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2ce
},{
	//Trainer 0x2cf
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_JONGLEUR,
	{0xb, false},//Encounter and gender
	0x66,//sprite
	{PCHAR_M, PCHAR_A, PCHAR_R, PCHAR_E, PCHAR_K, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	4,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2cf
},{
	//Trainer 0x2d0
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER2,
	{0x5, false},//Encounter and gender
	0x8e,//sprite
	{PCHAR_A, PCHAR_L, PCHAR_F, PCHAR_O, PCHAR_N, PCHAR_S, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2d0
},{
	//Trainer 0x2d1
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER2,
	{0x5, true},//Encounter and gender
	0x8f,//sprite
	{PCHAR_S, PCHAR_A, PCHAR_S, PCHAR_K, PCHAR_I, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2d1
},{
	//Trainer 0x2d2
	false,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_MUEHLENMAEDEL,
	{0x4, false},//Encounter and gender
	0x8b,//sprite
	{PCHAR_E, PCHAR_L, PCHAR_F, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2d2
},{
	//Trainer 0x2d3
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_DOMPTEUR,
	{0xb, false},//Encounter and gender
	0x67,//sprite
	{PCHAR_T, PCHAR_o, PCHAR_n, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2d3
},{
	//Trainer 0x2d4
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER2,
	{0x5, false},//Encounter and gender
	0x8e,//sprite
	{PCHAR_E, PCHAR_C, PCHAR_K, PCHAR_B, PCHAR_E, PCHAR_R, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2d4
},{
	//Trainer 0x2d5
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PKMN_RANGER2,
	{0x5, true},//Encounter and gender
	0x8f,//sprite
	{PCHAR_M, PCHAR_E, PCHAR_C, PCHAR_H, PCHAR_T, PCHAR_H, PCHAR_I, PCHAR_L, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	1,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2d5
},{
	//Trainer 0x2d6
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, false},//Encounter and gender
	0x6e,//sprite
	{PCHAR_O, PCHAR_T, PCHAR_M, PCHAR_A, PCHAR_R, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2d6
},{
	//Trainer 0x2d7
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_ASS_TRAINER2,
	{0x5, true},//Encounter and gender
	0x6f,//sprite
	{PCHAR_M, PCHAR_I, PCHAR_C, PCHAR_H, PCHAR_E, PCHAR_L, PCHAR_L, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_HYPERTRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2d7
},{
	//Trainer 0x2d8
	true,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_PRIMAPAAR,
	{0x5, false},//Encounter and gender
	0x80,//sprite
	{PCHAR_O, PCHAR_L, PCHAR_E, 0x2d, PCHAR_G, PCHAR_R, PCHAR_I, PCHAR_T, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	true,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2d8
},{
	//Trainer 0x2d9
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER2,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{PCHAR_A, PCHAR_T, PCHAR_T, PCHAR_I, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2d9
},{
	//Trainer 0x2da
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER2,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{PCHAR_A, PCHAR_T, PCHAR_T, PCHAR_I, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2da
},{
	//Trainer 0x2db
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_KAEFERSAMMLER2,
	{0x0, false},//Encounter and gender
	0x53,//sprite
	{PCHAR_A, PCHAR_T, PCHAR_T, PCHAR_I, PCHAR_L, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	3,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2db
},{
	//Trainer 0x2dc
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_U, PCHAR_M, PCHAR_B, PCHAR_E, PCHAR_R, PCHAR_T, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2dc
},{
	//Trainer 0x2dd
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMER2,
	{0x8, false},//Encounter and gender
	0x5f,//sprite
	{PCHAR_K, PCHAR_E, PCHAR_V, PCHAR_I, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2dd
},{
	//Trainer 0x2de
	false,//Custom moves
	false,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_SCHWIMMERIN2,
	{0x1, true},//Encounter and gender
	0x63,//sprite
	{PCHAR_M, PCHAR_E, PCHAR_L, PCHAR_I, PCHAR_S, PCHAR_S, PCHAR_A, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2de
},{
	//Trainer 0x2df
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TOP_VIER2,
	{0xa, false},//Encounter and gender
	0x70,//sprite
	{PCHAR_L, PCHAR_O, PCHAR_R, PCHAR_E, PCHAR_L, PCHAR_E, PCHAR_I, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2df
},{
	//Trainer 0x2e0
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TOP_VIER2,
	{0xa, false},//Encounter and gender
	0x71,//sprite
	{PCHAR_B, PCHAR_R, PCHAR_U, PCHAR_N, PCHAR_O, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2e0
},{
	//Trainer 0x2e1
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TOP_VIER2,
	{0xa, false},//Encounter and gender
	0x72,//sprite
	{PCHAR_A, PCHAR_G, PCHAR_A, PCHAR_T, PCHAR_H, PCHAR_E, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2e1
},{
	//Trainer 0x2e2
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_TOP_VIER2,
	{0xa, false},//Encounter and gender
	0x73,//sprite
	{PCHAR_S, PCHAR_I, PCHAR_E, PCHAR_G, PCHAR_F, PCHAR_R, PCHAR_I, PCHAR_E, PCHAR_D, 0xff, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	5,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2e2
},{
	//Trainer 0x2e3
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CHAMP2,
	{0x0, false},//Encounter and gender
	0x7d,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2e3
},{
	//Trainer 0x2e4
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CHAMP2,
	{0x0, false},//Encounter and gender
	0x7d,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2e4
},{
	//Trainer 0x2e5
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_CHAMP2,
	{0x0, false},//Encounter and gender
	0x7d,//sprite
	{PCHAR_B, PCHAR_J, PCHAR_OE, PCHAR_R, PCHAR_N, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
	0x0,//field_1E
	6,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2e5
},{
	//Trainer 0x2e6
	true,//Custom moves
	true,//Custom items
	0x0,//field_0_filler
	TRAINERCLASS_GLATZKOPF,
	{0x0, false},//Encounter and gender
	0x60,//sprite
	{PCHAR_P, PCHAR_A, PCHAR_U, PCHAR_L, 0xff, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE, PCHAR_SPACE},
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	false,//Dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
	0x0,//field_1E
	2,//Pokemon Count
	0x0,//field_21
	0x0,//field_22
	0x0,//field_23
	(trainer_pokemon*) trainer_party_x2e6
}  
};
