#include "types.h"
#include "item.h"
#include "romfuncs.h"
#include "pstring.h"

item items[] = {
	{
		//ITEM_NONE
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x0_item_none,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MEISTERBALL
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_i, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_a, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0})),
		0x1, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x1_item_meisterball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		0, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HYPERBALL
		PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_y, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_U, PCHAR_l, PCHAR_t, PCHAR_r, PCHAR_a, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0})),
		0x2, //index
		1200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x2_item_hyperball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SUPERBALL
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_u, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_G, PCHAR_r, PCHAR_e, PCHAR_a, PCHAR_t, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0})),
		0x3, //index
		600, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x3_item_superball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		2, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_POKEBALL
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_k, PCHAR_POKE_E, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_o, PCHAR_k, PCHAR_POKE_E, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x4, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x4_item_pokeball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		3, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SAFARIBALL
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_a, PCHAR_f, PCHAR_a, PCHAR_r, PCHAR_i, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_a, PCHAR_f, PCHAR_a, PCHAR_r, PCHAR_i, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0})),
		0x5, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x5_item_safariball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		4, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_NETZBALL
		PSTRING(P99_PROCTECT({PCHAR_N, PCHAR_e, PCHAR_t, PCHAR_z, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_N, PCHAR_e, PCHAR_t, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0, 0})),
		0x6, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x6_item_netzball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		5, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TAUCHBALL
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_a, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_D, PCHAR_i, PCHAR_v, PCHAR_e, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x7, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x7_item_tauchball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		6, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_NESTBALL
		PSTRING(P99_PROCTECT({PCHAR_N, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_N, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x8, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x8_item_nestball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		7, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WIEDERBALL
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_e, PCHAR_d, PCHAR_e, PCHAR_r, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_e, PCHAR_p, PCHAR_e, PCHAR_a, PCHAR_t, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0})),
		0x9, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x9_item_wiederball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		8, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TIMERBALL
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_i, PCHAR_m, PCHAR_e, PCHAR_r, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_i, PCHAR_m, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0})),
		0xa, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xa_item_timerball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		9, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LUXUSBALL
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_u, PCHAR_x, PCHAR_u, PCHAR_s, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_u, PCHAR_x, PCHAR_u, PCHAR_r, PCHAR_y, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0})),
		0xb, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xb_item_luxusball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		10, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PREMIERBALL
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_r, PCHAR_e, PCHAR_m, PCHAR_i, PCHAR_e, PCHAR_r, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_r, PCHAR_e, PCHAR_m, PCHAR_i, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0})),
		0xc, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xc_item_premierball,
		0, //field_18
		POCKET_POKEBALLS, //pocket
		11, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f09, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TRANK
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_k, 0xff, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_o, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0, 0, 0, 0, 0, 0, 0})),
		0xd, //index
		300, //price
		0, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xd_item_trank,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GEGENGIFT
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_g, PCHAR_e, PCHAR_n, PCHAR_g, PCHAR_i, PCHAR_f, PCHAR_t, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_A, PCHAR_n, PCHAR_t, PCHAR_i, PCHAR_d, PCHAR_o, PCHAR_t, PCHAR_e, 0xff, 0, 0, 0, 0, 0})),
		0xe, //index
		250, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xe_item_gegengift,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FEUERHEILER
		PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_u, PCHAR_e, PCHAR_r, PCHAR_h, PCHAR_e, PCHAR_i, PCHAR_l, PCHAR_e, PCHAR_r, 0xff, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_u, PCHAR_r, PCHAR_n, PCHAR_SPACE, PCHAR_H, PCHAR_e, PCHAR_a, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0xf, //index
		250, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xf_item_feuerheiler,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EISHEILER
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, PCHAR_h, PCHAR_e, PCHAR_i, PCHAR_l, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_I, PCHAR_c, PCHAR_e, PCHAR_SPACE, PCHAR_H, PCHAR_e, PCHAR_a, PCHAR_l, 0xff, 0, 0, 0, 0, 0})),
		0x10, //index
		250, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x10_item_eisheiler,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AUFWECKER
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_u, PCHAR_f, PCHAR_w, PCHAR_e, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_A, PCHAR_w, PCHAR_a, PCHAR_k, PCHAR_e, PCHAR_n, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0, 0, 0, 0})),
		0x11, //index
		250, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x11_item_aufwecker,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PARA_HEILER
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_a, PCHAR_r, PCHAR_a, PCHAR_MINUS, PCHAR_H, PCHAR_e, PCHAR_i, PCHAR_l, PCHAR_e, PCHAR_r, 0xff, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_a, PCHAR_r, PCHAR_l, PCHAR_y, PCHAR_z, PCHAR_SPACE, PCHAR_H, PCHAR_e, PCHAR_a, PCHAR_l, 0xff, 0, 0})),
		0x12, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x12_item_para_heiler,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_GENESUNG
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_o, PCHAR_p, PCHAR_MINUS, PCHAR_G, PCHAR_e, PCHAR_n, PCHAR_e, PCHAR_s, PCHAR_u, PCHAR_n, PCHAR_g, 0xff, 0}), P99_PROTECT({PCHAR_F, PCHAR_u, PCHAR_l, PCHAR_l, PCHAR_SPACE, PCHAR_R, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_o, PCHAR_r, PCHAR_e, 0xff, 0})),
		0x13, //index
		3000, //price
		0, //holding_effect_id
		255, //holding_effect_param
		str_item_desc_x13_item_top_genesung,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_TRANK
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_o, PCHAR_p, PCHAR_MINUS, PCHAR_T, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_k, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_a, PCHAR_x, PCHAR_SPACE, PCHAR_P, PCHAR_o, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0, 0, 0})),
		0x14, //index
		2500, //price
		0, //holding_effect_id
		255, //holding_effect_param
		str_item_desc_x14_item_top_trank,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HYPERTRANK
		PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_y, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_t, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_k, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_y, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_P, PCHAR_o, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0})),
		0x15, //index
		1200, //price
		0, //holding_effect_id
		200, //holding_effect_param
		str_item_desc_x15_item_hypertrank,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SUPERTRANK
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_u, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_t, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_k, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_u, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_P, PCHAR_o, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0})),
		0x16, //index
		700, //price
		0, //holding_effect_id
		50, //holding_effect_param
		str_item_desc_x16_item_supertrank,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HYPERHEILER
		PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_y, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_h, PCHAR_e, PCHAR_i, PCHAR_l, PCHAR_e, PCHAR_r, 0xff, 0, 0}), P99_PROTECT({PCHAR_F, PCHAR_u, PCHAR_l, PCHAR_l, PCHAR_SPACE, PCHAR_H, PCHAR_e, PCHAR_a, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x17, //index
		600, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x17_item_hyperheiler,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BELEBER
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_e, PCHAR_l, PCHAR_e, PCHAR_b, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_e, PCHAR_v, PCHAR_i, PCHAR_v, PCHAR_e, 0xff, 0, 0, 0, 0, 0, 0, 0})),
		0x18, //index
		1500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x18_item_beleber,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_BELEBER
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_o, PCHAR_p, PCHAR_MINUS, PCHAR_B, PCHAR_e, PCHAR_l, PCHAR_e, PCHAR_b, PCHAR_e, PCHAR_r, 0xff, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_a, PCHAR_x, PCHAR_SPACE, PCHAR_R, PCHAR_e, PCHAR_v, PCHAR_i, PCHAR_v, PCHAR_e, 0xff, 0, 0, 0})),
		0x19, //index
		4000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x19_item_top_beleber,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TAFELWASSER
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_a, PCHAR_f, PCHAR_e, PCHAR_l, PCHAR_w, PCHAR_a, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_r, 0xff, 0, 0}), P99_PROTECT({PCHAR_F, PCHAR_r, PCHAR_e, PCHAR_s, PCHAR_h, PCHAR_SPACE, PCHAR_W, PCHAR_a, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0, 0})),
		0x1a, //index
		200, //price
		0, //holding_effect_id
		50, //holding_effect_param
		str_item_desc_x1a_item_tafelwasser,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPRUDEL
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_r, PCHAR_u, PCHAR_d, PCHAR_e, PCHAR_l, 0xff, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_o, PCHAR_d, PCHAR_a, PCHAR_SPACE, PCHAR_P, PCHAR_o, PCHAR_p, 0xff, 0, 0, 0, 0, 0})),
		0x1b, //index
		300, //price
		0, //holding_effect_id
		60, //holding_effect_param
		str_item_desc_x1b_item_sprudel,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LIMONADE
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_m, PCHAR_o, PCHAR_n, PCHAR_a, PCHAR_d, PCHAR_e, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_e, PCHAR_m, PCHAR_o, PCHAR_n, PCHAR_a, PCHAR_d, PCHAR_e, 0xff, 0, 0, 0, 0, 0})),
		0x1c, //index
		350, //price
		0, //holding_effect_id
		80, //holding_effect_param
		str_item_desc_x1c_item_limonade,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KUHMUH_MILCH
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_u, PCHAR_h, PCHAR_m, PCHAR_u, PCHAR_h, PCHAR_MINUS, PCHAR_M, PCHAR_i, PCHAR_l, PCHAR_c, PCHAR_h, 0xff, 0}), P99_PROTECT({PCHAR_M, PCHAR_o, PCHAR_o, PCHAR_m, PCHAR_o, PCHAR_o, PCHAR_SPACE, PCHAR_M, PCHAR_i, PCHAR_l, PCHAR_k, 0xff, 0, 0})),
		0x1d, //index
		500, //price
		0, //holding_effect_id
		100, //holding_effect_param
		str_item_desc_x1d_item_kuhmuh_milch,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ENERGIESTAUB
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_n, PCHAR_e, PCHAR_r, PCHAR_g, PCHAR_i, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_a, PCHAR_u, PCHAR_b, 0xff, 0}), P99_PROTECT({PCHAR_E, PCHAR_n, PCHAR_e, PCHAR_r, PCHAR_g, PCHAR_y, PCHAR_p, PCHAR_o, PCHAR_w, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0})),
		0x1e, //index
		500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x1e_item_energiestaub,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KRAFTWURZEL
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_a, PCHAR_f, PCHAR_t, PCHAR_w, PCHAR_u, PCHAR_r, PCHAR_z, PCHAR_e, PCHAR_l, 0xff, 0, 0}), P99_PROTECT({PCHAR_E, PCHAR_n, PCHAR_e, PCHAR_r, PCHAR_g, PCHAR_y, PCHAR_SPACE, PCHAR_R, PCHAR_o, PCHAR_o, PCHAR_t, 0xff, 0, 0})),
		0x1f, //index
		800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x1f_item_kraftwurzel,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HEILPUDER
		PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_e, PCHAR_i, PCHAR_l, PCHAR_p, PCHAR_u, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_e, PCHAR_a, PCHAR_l, PCHAR_SPACE, PCHAR_P, PCHAR_o, PCHAR_w, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0, 0})),
		0x20, //index
		450, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x20_item_heilpuder,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VITALKRAUT
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_i, PCHAR_t, PCHAR_a, PCHAR_l, PCHAR_k, PCHAR_r, PCHAR_a, PCHAR_u, PCHAR_t, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_e, PCHAR_v, PCHAR_i, PCHAR_v, PCHAR_a, PCHAR_l, PCHAR_SPACE, PCHAR_H, PCHAR_e, PCHAR_r, PCHAR_b, 0xff, 0})),
		0x21, //index
		2800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x21_item_vitalkraut,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AETHER
		PSTRING(P99_PROCTECT({PCHAR_AE, PCHAR_t, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_E, PCHAR_t, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x22, //index
		1200, //price
		0, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_x22_item_aether,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17e9, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20e1, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_AETHER
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_o, PCHAR_p, PCHAR_MINUS, PCHAR_ae, PCHAR_t, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_a, PCHAR_x, PCHAR_SPACE, PCHAR_E, PCHAR_t, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0})),
		0x23, //index
		2000, //price
		0, //holding_effect_id
		255, //holding_effect_param
		str_item_desc_x23_item_top_aether,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17e9, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20e1, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ELIXIER
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_l, PCHAR_i, PCHAR_x, PCHAR_i, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_E, PCHAR_l, PCHAR_i, PCHAR_x, PCHAR_i, PCHAR_r, 0xff, 0, 0, 0, 0, 0, 0, 0})),
		0x24, //index
		3000, //price
		0, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_x24_item_elixier,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17e9, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20e1, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_ELIXIER
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_o, PCHAR_p, PCHAR_MINUS, PCHAR_E, PCHAR_l, PCHAR_i, PCHAR_x, PCHAR_i, PCHAR_e, PCHAR_r, 0xff, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_a, PCHAR_x, PCHAR_SPACE, PCHAR_E, PCHAR_l, PCHAR_i, PCHAR_x, PCHAR_i, PCHAR_r, 0xff, 0, 0, 0})),
		0x25, //index
		4500, //price
		0, //holding_effect_id
		255, //holding_effect_param
		str_item_desc_x25_item_top_elixier,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17e9, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20e1, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LAVAKEKS
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_v, PCHAR_a, PCHAR_k, PCHAR_e, PCHAR_k, PCHAR_s, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_a, PCHAR_v, PCHAR_a, PCHAR_SPACE, PCHAR_C, PCHAR_o, PCHAR_o, PCHAR_k, PCHAR_i, PCHAR_e, 0xff, 0, 0})),
		0x26, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x26_item_lavakeks,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLAUE_FLOETE
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_a, PCHAR_u, PCHAR_e, PCHAR_SPACE, PCHAR_F, PCHAR_l, PCHAR_oe, PCHAR_t, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_l, PCHAR_u, PCHAR_e, PCHAR_SPACE, PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_t, PCHAR_e, 0xff, 0, 0, 0})),
		0x27, //index
		100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x27_item_blaue_floete,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GELBE_FLOETE
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_l, PCHAR_b, PCHAR_e, PCHAR_SPACE, PCHAR_F, PCHAR_l, PCHAR_oe, PCHAR_t, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_Y, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_o, PCHAR_w, PCHAR_SPACE, PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_t, PCHAR_e, 0xff, 0})),
		0x28, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x28_item_gelbe_floete,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ROTE_FLOETE
		PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_t, PCHAR_e, PCHAR_SPACE, PCHAR_F, PCHAR_l, PCHAR_oe, PCHAR_t, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_e, PCHAR_d, PCHAR_SPACE, PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_t, PCHAR_e, 0xff, 0, 0, 0, 0})),
		0x29, //index
		300, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x29_item_rote_floete,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHW_FLOETE
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_DOT, PCHAR_SPACE, PCHAR_F, PCHAR_l, PCHAR_oe, PCHAR_t, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_l, PCHAR_a, PCHAR_c, PCHAR_k, PCHAR_SPACE, PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_t, PCHAR_e, 0xff, 0, 0})),
		0x2a, //index
		400, //price
		0, //holding_effect_id
		50, //holding_effect_param
		str_item_desc_x2a_item_schw_floete,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1b81, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WEISSE_FLOETE
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_e, PCHAR_i, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_SPACE, PCHAR_F, PCHAR_l, PCHAR_oe, PCHAR_t, PCHAR_e, 0xff, 0}), P99_PROTECT({PCHAR_W, PCHAR_h, PCHAR_i, PCHAR_t, PCHAR_e, PCHAR_SPACE, PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_t, PCHAR_e, 0xff, 0, 0})),
		0x2b, //index
		500, //price
		0, //holding_effect_id
		150, //holding_effect_param
		str_item_desc_x2b_item_weisse_floete,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1b81, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BEERENSAFT
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, PCHAR_n, PCHAR_s, PCHAR_a, PCHAR_f, PCHAR_t, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, PCHAR_SPACE, PCHAR_J, PCHAR_u, PCHAR_i, PCHAR_c, PCHAR_e, 0xff, 0, 0})),
		0x2c, //index
		100, //price
		1, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_x2c_item_beerensaft,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ZAUBERASCHE
		PSTRING(P99_PROCTECT({PCHAR_Z, PCHAR_a, PCHAR_u, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_a, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_a, PCHAR_c, PCHAR_r, PCHAR_e, PCHAR_d, PCHAR_SPACE, PCHAR_A, PCHAR_s, PCHAR_h, 0xff, 0, 0, 0})),
		0x2d, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x2d_item_zauberasche,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1859, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KUESTENSALZ
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_ue, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_n, PCHAR_s, PCHAR_a, PCHAR_l, PCHAR_z, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_h, PCHAR_o, PCHAR_a, PCHAR_l, PCHAR_SPACE, PCHAR_S, PCHAR_a, PCHAR_l, PCHAR_t, 0xff, 0, 0, 0})),
		0x2e, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x2e_item_kuestensalz,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KUESTENSCHALE
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_ue, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_n, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_l, PCHAR_e, 0xff, 0}), P99_PROTECT({PCHAR_S, PCHAR_h, PCHAR_o, PCHAR_a, PCHAR_l, PCHAR_SPACE, PCHAR_S, PCHAR_h, PCHAR_e, PCHAR_l, PCHAR_l, 0xff, 0, 0})),
		0x2f, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x2f_item_kuestenschale,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PURPURSTUECK
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_u, PCHAR_r, PCHAR_p, PCHAR_u, PCHAR_r, PCHAR_s, PCHAR_t, PCHAR_ue, PCHAR_c, PCHAR_k, 0xff, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_e, PCHAR_d, PCHAR_SPACE, PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_d, 0xff, 0, 0, 0, 0})),
		0x30, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x30_item_purpurstueck,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_INDIGOSTUECK
		PSTRING(P99_PROCTECT({PCHAR_I, PCHAR_n, PCHAR_d, PCHAR_i, PCHAR_g, PCHAR_o, PCHAR_s, PCHAR_t, PCHAR_ue, PCHAR_c, PCHAR_k, 0xff, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_l, PCHAR_u, PCHAR_e, PCHAR_SPACE, PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_d, 0xff, 0, 0, 0})),
		0x31, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x31_item_indigostueck,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GELBSTUECK
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_l, PCHAR_b, PCHAR_s, PCHAR_t, PCHAR_ue, PCHAR_c, PCHAR_k, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_Y, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_o, PCHAR_w, PCHAR_SPACE, PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_d, 0xff, 0})),
		0x32, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x32_item_gelbstueck,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GRUENSTUECK
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_r, PCHAR_ue, PCHAR_n, PCHAR_s, PCHAR_t, PCHAR_ue, PCHAR_c, PCHAR_k, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_G, PCHAR_r, PCHAR_e, PCHAR_e, PCHAR_n, PCHAR_SPACE, PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_d, 0xff, 0, 0})),
		0x33, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x33_item_gruenstueck,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MAGMAISIERER
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_m, PCHAR_a, PCHAR_i, PCHAR_s, PCHAR_i, PCHAR_e, PCHAR_r, PCHAR_e, PCHAR_r, 0xff, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x34, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x34_item_magmaisierer,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_STROMISIERER
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_r, PCHAR_o, PCHAR_m, PCHAR_i, PCHAR_s, PCHAR_i, PCHAR_e, PCHAR_r, PCHAR_e, PCHAR_r, 0xff, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x35, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x35_item_stromisierer,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHOENSCHUPPE
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_oe, PCHAR_n, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_u, PCHAR_p, PCHAR_p, PCHAR_e, 0xff, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x36, //index
		500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x36_item_schoenschuppe,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DUBIOSDISK
		PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_u, PCHAR_b, PCHAR_i, PCHAR_o, PCHAR_s, PCHAR_d, PCHAR_i, PCHAR_s, PCHAR_k, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x37, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x37_item_dubiosdisk,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DUESTERUMHANG
		PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_ue, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_u, PCHAR_m, PCHAR_h, PCHAR_a, PCHAR_n, PCHAR_g, 0xff, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x38, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x38_item_duesterumhang,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHUETZER
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_ue, PCHAR_t, PCHAR_z, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x39, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x39_item_schuetzer,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LEBEN_ORB
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_e, PCHAR_b, PCHAR_e, PCHAR_n, PCHAR_MINUS, PCHAR_O, PCHAR_r, PCHAR_b, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x3a, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x3a_item_leben_orb,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EVOLITH
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_v, PCHAR_o, PCHAR_l, PCHAR_i, PCHAR_t, PCHAR_h, 0xff, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x3b, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x3b_item_evolith,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_SCHARFZAHN
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_f, PCHAR_z, PCHAR_a, PCHAR_h, PCHAR_n, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_a, PCHAR_z, PCHAR_o, PCHAR_r, 0, PCHAR_F, PCHAR_a, PCHAR_n, PCHAR_g, 0xff, 0, 0, 0})),
		0x0, //index
		0, //price
		30, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_x3c_item_scharfzahn,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_3D
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x3d_item_item_3d,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_3E
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x3e_item_item_3e,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KP_PLUS
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_p, PCHAR_MINUS, PCHAR_P, PCHAR_l, PCHAR_u, PCHAR_s, 0xff, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_p, PCHAR_SPACE, PCHAR_U, PCHAR_p, 0xff, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x3f, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x3f_item_kp_plus,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PROTEIN
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_r, PCHAR_o, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_r, PCHAR_o, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0, 0, 0, 0, 0})),
		0x40, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x40_item_protein,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EISEN
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, PCHAR_e, PCHAR_n, 0xff, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_I, PCHAR_r, PCHAR_o, PCHAR_n, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x41, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x41_item_eisen,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_CARBON
		PSTRING(P99_PROCTECT({PCHAR_C, PCHAR_a, PCHAR_r, PCHAR_b, PCHAR_o, PCHAR_n, 0xff, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_C, PCHAR_a, PCHAR_r, PCHAR_b, PCHAR_o, PCHAR_s, 0xff, 0, 0, 0, 0, 0, 0, 0})),
		0x42, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x42_item_carbon,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KALZIUM
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_a, PCHAR_l, PCHAR_z, PCHAR_i, PCHAR_u, PCHAR_m, 0xff, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_C, PCHAR_a, PCHAR_l, PCHAR_c, PCHAR_i, PCHAR_u, PCHAR_m, 0xff, 0, 0, 0, 0, 0, 0})),
		0x43, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x43_item_kalzium,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SONDERBONBON
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_o, PCHAR_n, PCHAR_d, PCHAR_e, PCHAR_r, PCHAR_b, PCHAR_o, PCHAR_n, PCHAR_b, PCHAR_o, PCHAR_n, 0xff, 0}), P99_PROTECT({PCHAR_R, PCHAR_a, PCHAR_r, PCHAR_e, PCHAR_SPACE, PCHAR_C, PCHAR_a, PCHAR_n, PCHAR_d, PCHAR_y, 0xff, 0, 0, 0})),
		0x44, //index
		4800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x44_item_sonderbonbon,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1821, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AP_PLUS
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_p, PCHAR_MINUS, PCHAR_P, PCHAR_l, PCHAR_u, PCHAR_s, 0xff, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_p, PCHAR_SPACE, PCHAR_U, PCHAR_p, 0xff, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x45, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x45_item_ap_plus,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1805, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ZINK
		PSTRING(P99_PROCTECT({PCHAR_Z, PCHAR_i, PCHAR_n, PCHAR_k, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_Z, PCHAR_i, PCHAR_n, PCHAR_c, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x46, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x46_item_zink,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AP_TOP
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_p, PCHAR_MINUS, PCHAR_T, PCHAR_o, PCHAR_p, 0xff, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_p, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_x, 0xff, 0, 0, 0, 0, 0, 0, 0})),
		0x47, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x47_item_ap_top,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1805, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_48
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x48_item_item_48,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MEGABLOCK
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_g, PCHAR_a, PCHAR_b, PCHAR_l, PCHAR_o, PCHAR_c, PCHAR_k, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_G, PCHAR_u, PCHAR_a, PCHAR_r, PCHAR_d, PCHAR_SPACE, PCHAR_S, PCHAR_p, PCHAR_e, PCHAR_c, PCHAR_DOT, 0xff, 0, 0})),
		0x49, //index
		700, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x49_item_megablock,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ANGRIFFPLUS
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_n, PCHAR_g, PCHAR_r, PCHAR_i, PCHAR_f, PCHAR_f, PCHAR_p, PCHAR_l, PCHAR_u, PCHAR_s, 0xff, 0, 0}), P99_PROTECT({PCHAR_D, PCHAR_i, PCHAR_r, PCHAR_e, PCHAR_SPACE, PCHAR_H, PCHAR_i, PCHAR_t, 0xff, 0, 0, 0, 0, 0})),
		0x4a, //index
		650, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x4a_item_angriffplus,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_X_ANGRIFF
		PSTRING(P99_PROCTECT({PCHAR_X, PCHAR_MINUS, PCHAR_A, PCHAR_n, PCHAR_g, PCHAR_r, PCHAR_i, PCHAR_f, PCHAR_f, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_X, PCHAR_SPACE, PCHAR_A, PCHAR_t, PCHAR_t, PCHAR_a, PCHAR_c, PCHAR_k, 0xff, 0, 0, 0, 0, 0})),
		0x4b, //index
		500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x4b_item_x_angriff,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_X_ABWEHR
		PSTRING(P99_PROCTECT({PCHAR_X, PCHAR_MINUS, PCHAR_A, PCHAR_b, PCHAR_w, PCHAR_e, PCHAR_h, PCHAR_r, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_X, PCHAR_SPACE, PCHAR_D, PCHAR_e, PCHAR_f, PCHAR_e, PCHAR_n, PCHAR_d, 0xff, 0, 0, 0, 0, 0})),
		0x4c, //index
		550, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x4c_item_x_abwehr,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_X_TEMPO
		PSTRING(P99_PROCTECT({PCHAR_X, PCHAR_MINUS, PCHAR_T, PCHAR_e, PCHAR_m, PCHAR_p, PCHAR_o, 0xff, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_X, PCHAR_SPACE, PCHAR_S, PCHAR_p, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0, 0, 0, 0, 0, 0})),
		0x4d, //index
		350, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x4d_item_x_tempo,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_X_TREFFER
		PSTRING(P99_PROCTECT({PCHAR_X, PCHAR_MINUS, PCHAR_T, PCHAR_r, PCHAR_e, PCHAR_f, PCHAR_f, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_X, PCHAR_SPACE, PCHAR_A, PCHAR_c, PCHAR_c, PCHAR_u, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_y, 0xff, 0, 0, 0})),
		0x4e, //index
		950, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x4e_item_x_treffer,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_X_SPEZIAL
		PSTRING(P99_PROCTECT({PCHAR_X, PCHAR_MINUS, PCHAR_S, PCHAR_p, PCHAR_e, PCHAR_z, PCHAR_i, PCHAR_a, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_X, PCHAR_SPACE, PCHAR_S, PCHAR_p, PCHAR_e, PCHAR_c, PCHAR_i, PCHAR_a, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x4f, //index
		350, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x4f_item_x_spezial,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_POKEPUPPE
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_k, PCHAR_POKE_E, PCHAR_p, PCHAR_u, PCHAR_p, PCHAR_p, PCHAR_e, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_o, PCHAR_k, PCHAR_POKE_E, PCHAR_SPACE, PCHAR_D, PCHAR_o, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x50, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x50_item_pokepuppe,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a20fd, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ENECO_RUTE
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_n, PCHAR_e, PCHAR_c, PCHAR_o, PCHAR_MINUS, PCHAR_R, PCHAR_u, PCHAR_t, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_f, PCHAR_f, PCHAR_y, PCHAR_SPACE, PCHAR_T, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0})),
		0x51, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x51_item_eneco_rute,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a20fd, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_52
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x52_item_item_52,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SUPERSCHUTZ
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_u, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_u, PCHAR_t, PCHAR_z, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_u, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_R, PCHAR_e, PCHAR_p, PCHAR_e, PCHAR_l, 0xff, 0, 0})),
		0x53, //index
		500, //price
		0, //holding_effect_id
		200, //holding_effect_param
		str_item_desc_x53_item_superschutz,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1a85, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_SCHUTZ
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_o, PCHAR_p, PCHAR_MINUS, PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_u, PCHAR_t, PCHAR_z, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_a, PCHAR_x, PCHAR_SPACE, PCHAR_R, PCHAR_e, PCHAR_p, PCHAR_e, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x54, //index
		700, //price
		0, //holding_effect_id
		250, //holding_effect_param
		str_item_desc_x54_item_top_schutz,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1a85, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FLUCHTSEIL
		PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_t, PCHAR_s, PCHAR_e, PCHAR_i, PCHAR_l, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_E, PCHAR_s, PCHAR_c, PCHAR_a, PCHAR_p, PCHAR_e, PCHAR_SPACE, PCHAR_R, PCHAR_o, PCHAR_p, PCHAR_e, 0xff, 0, 0})),
		0x55, //index
		550, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x55_item_fluchtseil,
		0, //field_18
		POCKET_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1c99, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHUTZ
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_u, PCHAR_t, PCHAR_z, 0xff, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_e, PCHAR_p, PCHAR_e, PCHAR_l, 0xff, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x56, //index
		350, //price
		0, //holding_effect_id
		100, //holding_effect_param
		str_item_desc_x56_item_schutz,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1a85, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_57
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x57_item_item_57,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_58
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x58_item_item_58,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_59
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x59_item_item_59,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_5A
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x5a_item_item_5a,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_5B
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x5b_item_item_5b,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_5C
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x5c_item_item_5c,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SONNENSTEIN
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_o, PCHAR_n, PCHAR_n, PCHAR_e, PCHAR_n, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_u, PCHAR_n, PCHAR_SPACE, PCHAR_S, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_e, 0xff, 0, 0, 0, 0})),
		0x5d, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x5d_item_sonnenstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MONDSTEIN
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_n, PCHAR_d, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_o, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_S, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_e, 0xff, 0, 0, 0})),
		0x5e, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x5e_item_mondstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FEUERSTEIN
		PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_u, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_F, PCHAR_i, PCHAR_r, PCHAR_e, PCHAR_SPACE, PCHAR_S, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_e, 0xff, 0, 0, 0})),
		0x5f, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x5f_item_feuerstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DONNERSTEIN
		PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_o, PCHAR_n, PCHAR_n, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_h, PCHAR_u, PCHAR_n, PCHAR_d, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_e, 0xff, 0})),
		0x60, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x60_item_donnerstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WASSERSTEIN
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0}), P99_PROTECT({PCHAR_W, PCHAR_a, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_S, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_e, 0xff, 0, 0})),
		0x61, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x61_item_wasserstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLATTSTEIN
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_a, PCHAR_t, PCHAR_t, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_e, PCHAR_a, PCHAR_f, PCHAR_SPACE, PCHAR_S, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_e, 0xff, 0, 0, 0})),
		0x62, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x62_item_blattstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LINKKABEL
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_n, PCHAR_k, PCHAR_k, PCHAR_a, PCHAR_b, PCHAR_e, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x63, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x63_item_linkkabel,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FINSTERSTEIN
		PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_n, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x64, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x64_item_finsterstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LEUCHTSTEIN
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_e, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_t, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x65, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x65_item_leuchtstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FUNKELSTEIN
		PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_u, PCHAR_n, PCHAR_k, PCHAR_e, PCHAR_l, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x66, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x66_item_funkelstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MINIPILZ
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_i, PCHAR_n, PCHAR_i, PCHAR_p, PCHAR_i, PCHAR_l, PCHAR_z, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_i, PCHAR_n, PCHAR_y, PCHAR_m, PCHAR_u, PCHAR_s, PCHAR_h, PCHAR_r, PCHAR_o, PCHAR_o, PCHAR_m, 0xff, 0})),
		0x67, //index
		500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x67_item_minipilz,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RIESENPILZ
		PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_i, PCHAR_e, PCHAR_s, PCHAR_e, PCHAR_n, PCHAR_p, PCHAR_i, PCHAR_l, PCHAR_z, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_i, PCHAR_g, PCHAR_SPACE, PCHAR_M, PCHAR_u, PCHAR_s, PCHAR_h, PCHAR_r, PCHAR_o, PCHAR_o, PCHAR_m, 0xff, 0})),
		0x68, //index
		5000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x68_item_riesenpilz,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPV_ORB_N
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_v, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, PCHAR_SPACE, PCHAR_PARANTHESIS_START, PCHAR_n, PCHAR_PARANTHESIS_END, 0xff, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x69, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x69_item_spv_orb_n,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		item_field_nature_stone, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PERLE
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_e, PCHAR_r, PCHAR_l, PCHAR_e, 0xff, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_e, PCHAR_a, PCHAR_r, PCHAR_l, 0xff, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x6a, //index
		1400, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x6a_item_perle,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RIESENPERLE
		PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_i, PCHAR_e, PCHAR_s, PCHAR_e, PCHAR_n, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_l, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_i, PCHAR_g, PCHAR_SPACE, PCHAR_P, PCHAR_e, PCHAR_a, PCHAR_r, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x6b, //index
		7500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x6b_item_riesenperle,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_STERNENSTAUB
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_n, PCHAR_e, PCHAR_n, PCHAR_s, PCHAR_t, PCHAR_a, PCHAR_u, PCHAR_b, 0xff, 0}), P99_PROTECT({PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_r, PCHAR_d, PCHAR_u, PCHAR_s, PCHAR_t, 0xff, 0, 0, 0, 0, 0})),
		0x6c, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x6c_item_sternenstaub,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_STERNENSTUECK
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_n, PCHAR_e, PCHAR_n, PCHAR_s, PCHAR_t, PCHAR_ue, PCHAR_c, PCHAR_k, 0xff, 0}), P99_PROTECT({PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_r, PCHAR_SPACE, PCHAR_P, PCHAR_i, PCHAR_e, PCHAR_c, PCHAR_e, 0xff, 0, 0, 0})),
		0x6d, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x6d_item_sternenstueck,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_NUGGET
		PSTRING(P99_PROCTECT({PCHAR_N, PCHAR_u, PCHAR_g, PCHAR_g, PCHAR_e, PCHAR_t, 0xff, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_N, PCHAR_u, PCHAR_g, PCHAR_g, PCHAR_e, PCHAR_t, 0xff, 0, 0, 0, 0, 0, 0, 0})),
		0x6e, //index
		10000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x6e_item_nugget,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HERZSCHUPPE
		PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_e, PCHAR_r, PCHAR_z, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_u, PCHAR_p, PCHAR_p, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_e, PCHAR_a, PCHAR_r, PCHAR_t, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_a, PCHAR_l, PCHAR_e, 0xff, 0, 0})),
		0x6f, //index
		100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x6f_item_herzschuppe,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ANGR_ORB_P
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_n, PCHAR_g, PCHAR_r, PCHAR_DOT, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, PCHAR_SPACE, PCHAR_PARANTHESIS_START, PCHAR_p, PCHAR_PARANTHESIS_END, 0xff}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x70, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x70_item_angr_orb_p,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		item_field_nature_stone, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ANGR_ORB_N
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_n, PCHAR_g, PCHAR_r, PCHAR_DOT, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, PCHAR_SPACE, PCHAR_PARANTHESIS_START, PCHAR_n, PCHAR_PARANTHESIS_END, 0xff}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x71, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x71_item_angr_orb_n,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		item_field_nature_stone, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VERT_ORB_P
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_e, PCHAR_r, PCHAR_t, PCHAR_DOT, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, PCHAR_SPACE, PCHAR_PARANTHESIS_START, PCHAR_p, PCHAR_PARANTHESIS_END, 0xff}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x72, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x72_item_vert_orb_p,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		item_field_nature_stone, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VERT_ORB_N
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_e, PCHAR_r, PCHAR_t, PCHAR_DOT, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, PCHAR_SPACE, PCHAR_PARANTHESIS_START, PCHAR_n, PCHAR_PARANTHESIS_END, 0xff}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x73, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x73_item_vert_orb_n,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		item_field_nature_stone, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_INIT_ORB_P
		PSTRING(P99_PROCTECT({PCHAR_I, PCHAR_n, PCHAR_i, PCHAR_t, PCHAR_DOT, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, PCHAR_SPACE, PCHAR_PARANTHESIS_START, PCHAR_p, PCHAR_PARANTHESIS_END, 0xff}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x74, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x74_item_init_orb_p,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		item_field_nature_stone, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_INIT_ORB_N
		PSTRING(P99_PROCTECT({PCHAR_I, PCHAR_n, PCHAR_i, PCHAR_t, PCHAR_DOT, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, PCHAR_SPACE, PCHAR_PARANTHESIS_START, PCHAR_n, PCHAR_PARANTHESIS_END, 0xff}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x75, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x75_item_init_orb_n,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		item_field_nature_stone, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPA_ORB_P
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_a, PCHAR_DOT, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, PCHAR_SPACE, PCHAR_PARANTHESIS_START, PCHAR_p, PCHAR_PARANTHESIS_END, 0xff, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x76, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x76_item_spa_orb_p,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		item_field_nature_stone, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPA_ORB_N
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_a, PCHAR_DOT, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, PCHAR_SPACE, PCHAR_PARANTHESIS_START, PCHAR_n, PCHAR_PARANTHESIS_END, 0xff, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x77, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x77_item_spa_orb_n,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		item_field_nature_stone, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPV_ORB_P
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_v, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, PCHAR_SPACE, PCHAR_PARANTHESIS_START, PCHAR_p, PCHAR_PARANTHESIS_END, 0xff, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x78, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x78_item_spv_orb_p,
		0, //field_18
		POCKET_ITEMS, //pocket
		1, //type
		item_field_nature_stone, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_79
		PSTRING(P99_PROCTECT({PCHAR_Z, PCHAR_i, PCHAR_g, PCHAR_z, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_s, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff}), P99_PROTECT({PCHAR_O, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_e, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0})),
		0x79, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x79_item_79,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HAFENBRIEF
		PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_a, PCHAR_f, PCHAR_e, PCHAR_n, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_a, PCHAR_r, PCHAR_b, PCHAR_o, PCHAR_r, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0})),
		0x7a, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x7a_item_hafenbrief,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GLITZERBRIEF
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_l, PCHAR_i, PCHAR_t, PCHAR_z, PCHAR_e, PCHAR_r, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0}), P99_PROTECT({PCHAR_G, PCHAR_l, PCHAR_i, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0})),
		0x7b, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x7b_item_glitzerbrief,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EILBRIEF
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_l, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_e, PCHAR_c, PCHAR_h, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x7c, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x7c_item_eilbrief,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WALDBRIEF
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_l, PCHAR_d, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_W, PCHAR_o, PCHAR_o, PCHAR_d, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x7d, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x7d_item_waldbrief,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WELLENBRIEF
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_e, PCHAR_n, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0, 0}), P99_PROTECT({PCHAR_W, PCHAR_a, PCHAR_v, PCHAR_e, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x7e, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x7e_item_wellenbrief,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PERLENBRIEF
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_e, PCHAR_r, PCHAR_l, PCHAR_e, PCHAR_n, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_e, PCHAR_a, PCHAR_d, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0, 0, 0})),
		0x7f, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x7f_item_perlenbrief,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DUNKELBRIEF
		PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_u, PCHAR_n, PCHAR_k, PCHAR_e, PCHAR_l, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_d, PCHAR_o, PCHAR_w, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0})),
		0x80, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x80_item_dunkelbrief,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TROPENBRIEF
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_o, PCHAR_p, PCHAR_e, PCHAR_n, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_r, PCHAR_o, PCHAR_p, PCHAR_i, PCHAR_c, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0})),
		0x81, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x81_item_tropenbrief,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TRAUMBRIEF
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_a, PCHAR_u, PCHAR_m, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_D, PCHAR_r, PCHAR_e, PCHAR_a, PCHAR_m, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0, 0})),
		0x82, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x82_item_traumbrief,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EDELBRIEF
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_d, PCHAR_e, PCHAR_l, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_F, PCHAR_a, PCHAR_b, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0, 0, 0, 0})),
		0x83, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x83_item_edelbrief,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RETROBRIEF
		PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_e, PCHAR_t, PCHAR_r, PCHAR_o, PCHAR_b, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_e, PCHAR_t, PCHAR_r, PCHAR_o, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0, 0, 0})),
		0x84, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x84_item_retrobrief,
		0, //field_18
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AMRENABEERE
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_m, PCHAR_r, PCHAR_e, PCHAR_n, PCHAR_a, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_C, PCHAR_h, PCHAR_e, PCHAR_r, PCHAR_i, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0x85, //index
		20, //price
		2, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x85_item_amrenabeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MARONBEERE
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_r, PCHAR_o, PCHAR_n, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_C, PCHAR_h, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_o, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0x86, //index
		20, //price
		3, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x86_item_maronbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PIRSIFBEERE
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_i, PCHAR_r, PCHAR_s, PCHAR_i, PCHAR_f, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_e, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0x87, //index
		20, //price
		4, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x87_item_pirsifbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FRAGIABEERE
		PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_i, PCHAR_a, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_a, PCHAR_w, PCHAR_s, PCHAR_t, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0x88, //index
		20, //price
		5, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x88_item_fragiabeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WILBIRBEERE
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_l, PCHAR_b, PCHAR_i, PCHAR_r, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_A, PCHAR_s, PCHAR_p, PCHAR_e, PCHAR_a, PCHAR_r, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0x89, //index
		20, //price
		6, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x89_item_wilbirbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_JONAGOBEERE
		PSTRING(P99_PROCTECT({PCHAR_J, PCHAR_o, PCHAR_n, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_e, PCHAR_p, PCHAR_p, PCHAR_a, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0x8a, //index
		20, //price
		7, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_x8a_item_jonagobeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))0x80a17e9, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20e1, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SINELBEERE
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_i, PCHAR_n, PCHAR_e, PCHAR_l, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_O, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0, 0})),
		0x8b, //index
		20, //price
		1, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_x8b_item_sinelbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PERSIMBEERE
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_i, PCHAR_m, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_i, PCHAR_m, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0x8c, //index
		20, //price
		8, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x8c_item_persimbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PRUNUSBEERE
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_r, PCHAR_u, PCHAR_n, PCHAR_u, PCHAR_s, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_u, PCHAR_m, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0, 0, 0})),
		0x8d, //index
		20, //price
		9, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x8d_item_prunusbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TSITRUBEERE
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_s, PCHAR_i, PCHAR_t, PCHAR_r, PCHAR_u, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_i, PCHAR_t, PCHAR_r, PCHAR_u, PCHAR_s, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0x8e, //index
		20, //price
		1, //holding_effect_id
		30, //holding_effect_param
		str_item_desc_x8e_item_tsitrubeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))0x80a17cd, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GIEFEBEERE
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_i, PCHAR_e, PCHAR_f, PCHAR_e, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_F, PCHAR_i, PCHAR_g, PCHAR_y, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0, 0})),
		0x8f, //index
		20, //price
		10, //holding_effect_id
		8, //holding_effect_param
		str_item_desc_x8f_item_giefebeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WIKIBEERE
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_k, PCHAR_i, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_W, PCHAR_i, PCHAR_k, PCHAR_i, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0, 0})),
		0x90, //index
		20, //price
		11, //holding_effect_id
		8, //holding_effect_param
		str_item_desc_x90_item_wikibeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MAGOBEERE
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0, 0})),
		0x91, //index
		20, //price
		12, //holding_effect_id
		8, //holding_effect_param
		str_item_desc_x91_item_magobeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GAUVEBEERE
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_a, PCHAR_u, PCHAR_v, PCHAR_e, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_A, PCHAR_g, PCHAR_u, PCHAR_a, PCHAR_v, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0x92, //index
		20, //price
		13, //holding_effect_id
		8, //holding_effect_param
		str_item_desc_x92_item_gauvebeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_YAPABEERE
		PSTRING(P99_PROCTECT({PCHAR_Y, PCHAR_a, PCHAR_p, PCHAR_a, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_I, PCHAR_a, PCHAR_p, PCHAR_a, PCHAR_p, PCHAR_a, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0x93, //index
		20, //price
		14, //holding_effect_id
		8, //holding_effect_param
		str_item_desc_x93_item_yapabeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HIMMIHBEERE
		PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_i, PCHAR_m, PCHAR_m, PCHAR_i, PCHAR_h, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_a, PCHAR_z, PCHAR_z, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0, 0})),
		0x94, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x94_item_himmihbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MORBBEERE
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_r, PCHAR_b, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_l, PCHAR_u, PCHAR_k, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0, 0})),
		0x95, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x95_item_morbbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_NANABBEERE
		PSTRING(P99_PROCTECT({PCHAR_N, PCHAR_a, PCHAR_n, PCHAR_a, PCHAR_b, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_N, PCHAR_a, PCHAR_n, PCHAR_a, PCHAR_b, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0x96, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x96_item_nanabbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_NIRBEBEERE
		PSTRING(P99_PROCTECT({PCHAR_N, PCHAR_i, PCHAR_r, PCHAR_b, PCHAR_e, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_W, PCHAR_e, PCHAR_p, PCHAR_e, PCHAR_a, PCHAR_r, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0x97, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x97_item_nirbebeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SANANABEERE
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_a, PCHAR_n, PCHAR_a, PCHAR_n, PCHAR_a, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_i, PCHAR_n, PCHAR_a, PCHAR_p, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0x98, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x98_item_sananabeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GRANABEERE
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_a, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_o, PCHAR_m, PCHAR_e, PCHAR_g, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0x99, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x99_item_granabeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SETANGBEERE
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_t, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_K, PCHAR_e, PCHAR_l, PCHAR_p, PCHAR_s, PCHAR_y, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0x9a, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x9a_item_setangbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_QUALOTBEERE
		PSTRING(P99_PROCTECT({PCHAR_Q, PCHAR_u, PCHAR_a, PCHAR_l, PCHAR_o, PCHAR_t, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_Q, PCHAR_u, PCHAR_a, PCHAR_l, PCHAR_o, PCHAR_t, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0x9b, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x9b_item_qualotbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HONMELBEERE
		PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_o, PCHAR_n, PCHAR_m, PCHAR_e, PCHAR_l, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_o, PCHAR_n, PCHAR_d, PCHAR_e, PCHAR_w, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0x9c, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x9c_item_honmelbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LABRUSBEERE
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_b, PCHAR_r, PCHAR_u, PCHAR_s, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_G, PCHAR_r, PCHAR_e, PCHAR_p, PCHAR_a, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0x9d, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x9d_item_labrusbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TAMOTBEERE
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_a, PCHAR_m, PCHAR_o, PCHAR_t, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_a, PCHAR_m, PCHAR_a, PCHAR_t, PCHAR_o, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0x9e, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x9e_item_tamotbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SAIMBEERE
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_a, PCHAR_i, PCHAR_m, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_C, PCHAR_o, PCHAR_r, PCHAR_n, PCHAR_n, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0x9f, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x9f_item_saimbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MAGOSTBEERE
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_s, PCHAR_t, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_s, PCHAR_t, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0xa0, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xa0_item_magostbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RABUTABEERE
		PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_a, PCHAR_b, PCHAR_u, PCHAR_t, PCHAR_a, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_a, PCHAR_b, PCHAR_u, PCHAR_t, PCHAR_a, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0xa1, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xa1_item_rabutabeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TRONZIBEERE
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_o, PCHAR_n, PCHAR_z, PCHAR_i, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_N, PCHAR_o, PCHAR_m, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0xa2, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xa2_item_tronzibeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KIWANBEERE
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_i, PCHAR_w, PCHAR_a, PCHAR_n, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0xa3, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xa3_item_kiwanbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PALLMBEERE
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_m, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_a, PCHAR_m, PCHAR_t, PCHAR_r, PCHAR_e, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0xa4, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xa4_item_pallmbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WASMELBEERE
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_s, PCHAR_m, PCHAR_e, PCHAR_l, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_W, PCHAR_a, PCHAR_t, PCHAR_m, PCHAR_e, PCHAR_l, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0xa5, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xa5_item_wasmelbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DURINBEERE
		PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_u, PCHAR_r, PCHAR_i, PCHAR_n, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_D, PCHAR_u, PCHAR_r, PCHAR_i, PCHAR_n, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0xa6, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xa6_item_durinbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MYRTILBEERE
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_y, PCHAR_r, PCHAR_t, PCHAR_i, PCHAR_l, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_e, PCHAR_l, PCHAR_u, PCHAR_e, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0xa7, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xa7_item_myrtilbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LYDZIBEERE
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_y, PCHAR_d, PCHAR_z, PCHAR_i, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_i, PCHAR_e, PCHAR_c, PCHAR_h, PCHAR_i, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0xa8, //index
		20, //price
		15, //holding_effect_id
		4, //holding_effect_param
		str_item_desc_xa8_item_lydzibeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LINGANBEERE
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_n, PCHAR_g, PCHAR_a, PCHAR_n, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_G, PCHAR_a, PCHAR_n, PCHAR_l, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0xa9, //index
		20, //price
		16, //holding_effect_id
		4, //holding_effect_param
		str_item_desc_xa9_item_linganbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SALKABEERE
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_a, PCHAR_l, PCHAR_k, PCHAR_a, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_a, PCHAR_l, PCHAR_a, PCHAR_c, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0xaa, //index
		20, //price
		17, //holding_effect_id
		4, //holding_effect_param
		str_item_desc_xaa_item_salkabeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TAHAYBEERE
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_a, PCHAR_h, PCHAR_a, PCHAR_y, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_e, PCHAR_t, PCHAR_a, PCHAR_y, PCHAR_a, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0xab, //index
		20, //price
		18, //holding_effect_id
		4, //holding_effect_param
		str_item_desc_xab_item_tahaybeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_APIKOBEERE
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_p, PCHAR_i, PCHAR_k, PCHAR_o, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_A, PCHAR_p, PCHAR_i, PCHAR_c, PCHAR_o, PCHAR_t, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0xac, //index
		20, //price
		19, //holding_effect_id
		4, //holding_effect_param
		str_item_desc_xac_item_apikobeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LANSATBEERE
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_n, PCHAR_s, PCHAR_a, PCHAR_t, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_a, PCHAR_n, PCHAR_s, PCHAR_a, PCHAR_t, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0xad, //index
		20, //price
		20, //holding_effect_id
		4, //holding_effect_param
		str_item_desc_xad_item_lansatbeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KRAMBOBEERE
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_a, PCHAR_m, PCHAR_b, PCHAR_o, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_r, PCHAR_f, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0, 0})),
		0xae, //index
		20, //price
		21, //holding_effect_id
		4, //holding_effect_param
		str_item_desc_xae_item_krambobeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ENIGMABEERE
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_n, PCHAR_i, PCHAR_g, PCHAR_m, PCHAR_a, PCHAR_b, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_E, PCHAR_n, PCHAR_i, PCHAR_g, PCHAR_m, PCHAR_a, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, 0xff, 0})),
		0xaf, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xaf_item_enigmabeere,
		0, //field_18
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2155, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a2281, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_B0
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xb0_item_item_b0,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WAHLGLAS
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_h, PCHAR_l, PCHAR_g, PCHAR_l, PCHAR_a, PCHAR_s, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xb1, //index
		100, //price
		29, //holding_effect_id
		2, //holding_effect_param
		str_item_desc_xb1_item_wahlglas,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WAHLSCHAL
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_h, PCHAR_l, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xb2, //index
		100, //price
		29, //holding_effect_id
		1, //holding_effect_param
		str_item_desc_xb2_item_wahlschal,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLENDPUDER
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_e, PCHAR_n, PCHAR_d, PCHAR_p, PCHAR_u, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_r, PCHAR_i, PCHAR_g, PCHAR_h, PCHAR_t, PCHAR_p, PCHAR_o, PCHAR_w, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0})),
		0xb3, //index
		10, //price
		22, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_xb3_item_blendpuder,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHLOHKRAUT
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_o, PCHAR_h, PCHAR_k, PCHAR_r, PCHAR_a, PCHAR_u, PCHAR_t, 0xff, 0, 0}), P99_PROTECT({PCHAR_W, PCHAR_h, PCHAR_i, PCHAR_t, PCHAR_e, PCHAR_SPACE, PCHAR_H, PCHAR_e, PCHAR_r, PCHAR_b, 0xff, 0, 0, 0})),
		0xb4, //index
		100, //price
		23, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xb4_item_schlohkraut,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MACHOBAND
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_o, PCHAR_b, PCHAR_a, PCHAR_n, PCHAR_d, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_o, PCHAR_SPACE, PCHAR_B, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_e, 0xff, 0, 0})),
		0xb5, //index
		3000, //price
		24, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xb5_item_machoband,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EP_TEILER
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_p, PCHAR_MINUS, PCHAR_T, PCHAR_e, PCHAR_i, PCHAR_l, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_E, PCHAR_x, PCHAR_p, PCHAR_DOT, PCHAR_SPACE, PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0})),
		0xb6, //index
		3000, //price
		25, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xb6_item_ep_teiler,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FLINKKLAUE
		PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_i, PCHAR_n, PCHAR_k, PCHAR_k, PCHAR_l, PCHAR_a, PCHAR_u, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_Q, PCHAR_u, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_SPACE, PCHAR_C, PCHAR_l, PCHAR_a, PCHAR_w, 0xff, 0, 0, 0})),
		0xb7, //index
		100, //price
		26, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xb7_item_flinkklaue,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SANFTGLOCKE
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_a, PCHAR_n, PCHAR_f, PCHAR_t, PCHAR_g, PCHAR_l, PCHAR_o, PCHAR_c, PCHAR_k, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_o, PCHAR_o, PCHAR_t, PCHAR_h, PCHAR_e, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_l, PCHAR_l, 0xff, 0, 0})),
		0xb8, //index
		100, //price
		27, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xb8_item_sanftglocke,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MENTALKRAUT
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_n, PCHAR_t, PCHAR_a, PCHAR_l, PCHAR_k, PCHAR_r, PCHAR_a, PCHAR_u, PCHAR_t, 0xff, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_e, PCHAR_n, PCHAR_t, PCHAR_a, PCHAR_l, PCHAR_SPACE, PCHAR_H, PCHAR_e, PCHAR_r, PCHAR_b, 0xff, 0, 0})),
		0xb9, //index
		100, //price
		28, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xb9_item_mentalkraut,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WAHLBAND
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_h, PCHAR_l, PCHAR_b, PCHAR_a, PCHAR_n, PCHAR_d, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_C, PCHAR_h, PCHAR_o, PCHAR_i, PCHAR_c, PCHAR_e, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_n, PCHAR_d, 0xff, 0, 0})),
		0xba, //index
		100, //price
		29, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xba_item_wahlband,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KING_STEIN
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_i, PCHAR_n, PCHAR_g, PCHAR_MINUS, PCHAR_S, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_K, PCHAR_i, PCHAR_n, PCHAR_g, 0xb4, PCHAR_s, PCHAR_SPACE, PCHAR_R, PCHAR_o, PCHAR_c, PCHAR_k, 0xff, 0, 0})),
		0xbb, //index
		100, //price
		30, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_xbb_item_king_stein,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SILBERSTAUB
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_i, PCHAR_l, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_t, PCHAR_a, PCHAR_u, PCHAR_b, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_i, PCHAR_l, PCHAR_v, PCHAR_e, PCHAR_r, PCHAR_p, PCHAR_o, PCHAR_w, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0})),
		0xbc, //index
		100, //price
		31, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_xbc_item_silberstaub,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MUENZAMULETT
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_ue, PCHAR_n, PCHAR_z, PCHAR_a, PCHAR_m, PCHAR_u, PCHAR_l, PCHAR_e, PCHAR_t, PCHAR_t, 0xff, 0, 0}), P99_PROTECT({PCHAR_A, PCHAR_m, PCHAR_u, PCHAR_l, PCHAR_e, PCHAR_t, PCHAR_SPACE, PCHAR_C, PCHAR_o, PCHAR_i, PCHAR_n, 0xff, 0, 0})),
		0xbd, //index
		100, //price
		32, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_xbd_item_muenzamulett,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHUTZBAND
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_u, PCHAR_t, PCHAR_z, PCHAR_b, PCHAR_a, PCHAR_n, PCHAR_d, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_C, PCHAR_l, PCHAR_e, PCHAR_a, PCHAR_n, PCHAR_s, PCHAR_e, PCHAR_SPACE, PCHAR_T, PCHAR_a, PCHAR_g, 0xff, 0, 0})),
		0xbe, //index
		200, //price
		33, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xbe_item_schutzband,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SEELENTAU
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_l, PCHAR_e, PCHAR_n, PCHAR_t, PCHAR_a, PCHAR_u, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_o, PCHAR_u, PCHAR_l, PCHAR_SPACE, PCHAR_D, PCHAR_e, PCHAR_w, 0xff, 0, 0, 0, 0, 0})),
		0xbf, //index
		200, //price
		34, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xbf_item_seelentau,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ABYSSZAHN
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_b, PCHAR_y, PCHAR_s, PCHAR_s, PCHAR_z, PCHAR_a, PCHAR_h, PCHAR_n, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_D, PCHAR_e, PCHAR_e, PCHAR_p, PCHAR_s, PCHAR_e, PCHAR_a, PCHAR_t, PCHAR_o, PCHAR_o, PCHAR_t, PCHAR_h, 0xff, 0})),
		0xc0, //index
		200, //price
		35, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xc0_item_abysszahn,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ABYSSPLATTE
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_b, PCHAR_y, PCHAR_s, PCHAR_s, PCHAR_p, PCHAR_l, PCHAR_a, PCHAR_t, PCHAR_t, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_D, PCHAR_e, PCHAR_e, PCHAR_p, PCHAR_s, PCHAR_e, PCHAR_a, PCHAR_s, PCHAR_c, PCHAR_a, PCHAR_l, PCHAR_e, 0xff, 0})),
		0xc1, //index
		200, //price
		36, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xc1_item_abyssplatte,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RAUCHBALL
		PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_a, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_m, PCHAR_o, PCHAR_k, PCHAR_e, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0})),
		0xc2, //index
		200, //price
		37, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xc2_item_rauchball,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EWIGSTEIN
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_w, PCHAR_i, PCHAR_g, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_E, PCHAR_v, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_e, 0xff, 0, 0, 0, 0})),
		0xc3, //index
		200, //price
		38, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xc3_item_ewigstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FOKUS_BAND
		PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_o, PCHAR_k, PCHAR_u, PCHAR_s, PCHAR_MINUS, PCHAR_B, PCHAR_a, PCHAR_n, PCHAR_d, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_F, PCHAR_o, PCHAR_c, PCHAR_u, PCHAR_s, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_n, PCHAR_d, 0xff, 0, 0, 0})),
		0xc4, //index
		200, //price
		39, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_xc4_item_fokus_band,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GLUECKS_EI
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_l, PCHAR_ue, PCHAR_c, PCHAR_k, PCHAR_s, PCHAR_MINUS, PCHAR_E, PCHAR_i, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_u, PCHAR_c, PCHAR_k, PCHAR_y, PCHAR_SPACE, PCHAR_E, PCHAR_g, PCHAR_g, 0xff, 0, 0, 0, 0})),
		0xc5, //index
		200, //price
		40, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xc5_item_gluecks_ei,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCOPE_LINSE
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_o, PCHAR_p, PCHAR_e, PCHAR_MINUS, PCHAR_L, PCHAR_i, PCHAR_n, PCHAR_s, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_c, PCHAR_o, PCHAR_p, PCHAR_e, PCHAR_SPACE, PCHAR_L, PCHAR_e, PCHAR_n, PCHAR_s, 0xff, 0, 0, 0})),
		0xc6, //index
		200, //price
		41, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xc6_item_scope_linse,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_METALLMANTEL
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_t, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_m, PCHAR_a, PCHAR_n, PCHAR_t, PCHAR_e, PCHAR_l, 0xff, 0}), P99_PROTECT({PCHAR_M, PCHAR_e, PCHAR_t, PCHAR_a, PCHAR_l, PCHAR_SPACE, PCHAR_C, PCHAR_o, PCHAR_a, PCHAR_t, 0xff, 0, 0, 0})),
		0xc7, //index
		100, //price
		42, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_xc7_item_metallmantel,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_UEBERRESTE
		PSTRING(P99_PROCTECT({PCHAR_UE, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_e, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_e, PCHAR_f, PCHAR_t, PCHAR_o, PCHAR_v, PCHAR_e, PCHAR_r, PCHAR_s, 0xff, 0, 0, 0, 0})),
		0xc8, //index
		200, //price
		43, //holding_effect_id
		10, //holding_effect_param
		str_item_desc_xc8_item_ueberreste,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DRACHENHAUT
		PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_n, PCHAR_h, PCHAR_a, PCHAR_u, PCHAR_t, 0xff, 0, 0}), P99_PROTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_a, PCHAR_l, PCHAR_e, 0xff, 0})),
		0xc9, //index
		2100, //price
		44, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xc9_item_drachenhaut,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KUGELBLITZ
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_u, PCHAR_g, PCHAR_e, PCHAR_l, PCHAR_b, PCHAR_l, PCHAR_i, PCHAR_t, PCHAR_z, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_i, PCHAR_g, PCHAR_h, PCHAR_t, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0})),
		0xca, //index
		100, //price
		45, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xca_item_kugelblitz,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PUDERSAND
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_u, PCHAR_d, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_a, PCHAR_n, PCHAR_d, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_o, PCHAR_f, PCHAR_t, PCHAR_SPACE, PCHAR_S, PCHAR_a, PCHAR_n, PCHAR_d, 0xff, 0, 0, 0, 0})),
		0xcb, //index
		100, //price
		46, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xcb_item_pudersand,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GRANITSTEIN
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_i, PCHAR_t, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_a, PCHAR_r, PCHAR_d, PCHAR_SPACE, PCHAR_S, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_e, 0xff, 0, 0, 0})),
		0xcc, //index
		100, //price
		47, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xcc_item_granitstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WUNDERSAAT
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_u, PCHAR_n, PCHAR_d, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_a, PCHAR_a, PCHAR_t, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_i, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_l, PCHAR_e, PCHAR_SPACE, PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0})),
		0xcd, //index
		100, //price
		48, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xcd_item_wundersaat,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHATTENGLAS
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_n, PCHAR_g, PCHAR_l, PCHAR_a, PCHAR_s, 0xff, 0}), P99_PROTECT({PCHAR_B, PCHAR_l, PCHAR_a, PCHAR_c, PCHAR_k, PCHAR_g, PCHAR_l, PCHAR_a, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_s, 0xff, 0})),
		0xce, //index
		100, //price
		49, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xce_item_schattenglas,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHWARZGURT
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_a, PCHAR_r, PCHAR_z, PCHAR_g, PCHAR_u, PCHAR_r, PCHAR_t, 0xff, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_l, PCHAR_a, PCHAR_c, PCHAR_k, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_l, PCHAR_t, 0xff, 0, 0, 0})),
		0xcf, //index
		100, //price
		50, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xcf_item_schwarzgurt,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MAGNET
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_n, PCHAR_e, PCHAR_t, 0xff, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_n, PCHAR_e, PCHAR_t, 0xff, 0, 0, 0, 0, 0, 0, 0})),
		0xd0, //index
		100, //price
		51, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xd0_item_magnet,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ZAUBERWASSER
		PSTRING(P99_PROCTECT({PCHAR_Z, PCHAR_a, PCHAR_u, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_w, PCHAR_a, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_r, 0xff, 0}), P99_PROTECT({PCHAR_M, PCHAR_y, PCHAR_s, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_SPACE, PCHAR_W, PCHAR_a, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0})),
		0xd1, //index
		100, //price
		52, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xd1_item_zauberwasser,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HACKATTACK
		PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_a, PCHAR_c, PCHAR_k, PCHAR_a, PCHAR_t, PCHAR_t, PCHAR_a, PCHAR_c, PCHAR_k, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_p, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_a, PCHAR_k, 0xff, 0, 0, 0})),
		0xd2, //index
		100, //price
		53, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xd2_item_hackattack,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GIFTSTICH
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_s, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_h, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_r, PCHAR_b, 0xff, 0, 0})),
		0xd3, //index
		100, //price
		54, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xd3_item_giftstich,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EWIGES_EIS
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_w, PCHAR_i, PCHAR_g, PCHAR_e, PCHAR_s, PCHAR_SPACE, PCHAR_E, PCHAR_i, PCHAR_s, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_N, PCHAR_e, PCHAR_v, PCHAR_e, PCHAR_r, PCHAR_m, PCHAR_e, PCHAR_l, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_e, 0xff, 0})),
		0xd4, //index
		100, //price
		55, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xd4_item_ewiges_eis,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BANNSTICKER
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_n, PCHAR_n, PCHAR_s, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_r, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_SPACE, PCHAR_T, PCHAR_a, PCHAR_g, 0xff, 0, 0, 0, 0})),
		0xd5, //index
		100, //price
		56, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xd5_item_bannsticker,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KRUEMMLOEFFEL
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_ue, PCHAR_m, PCHAR_m, PCHAR_l, PCHAR_oe, PCHAR_f, PCHAR_f, PCHAR_e, PCHAR_l, 0xff, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_w, PCHAR_i, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_d, PCHAR_s, PCHAR_p, PCHAR_o, PCHAR_o, PCHAR_n, 0xff, 0})),
		0xd6, //index
		100, //price
		57, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xd6_item_kruemmloeffel,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HOLZKOHLE
		PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_o, PCHAR_l, PCHAR_z, PCHAR_k, PCHAR_o, PCHAR_h, PCHAR_l, PCHAR_e, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_C, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_c, PCHAR_o, PCHAR_a, PCHAR_l, 0xff, 0, 0, 0, 0, 0})),
		0xd7, //index
		9800, //price
		58, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xd7_item_holzkohle,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DRACHENZAHN
		PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_n, PCHAR_z, PCHAR_a, PCHAR_h, PCHAR_n, 0xff, 0, 0}), P99_PROTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_F, PCHAR_a, PCHAR_n, PCHAR_g, 0xff, 0, 0})),
		0xd8, //index
		100, //price
		59, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xd8_item_drachenzahn,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SEIDENSCHAL
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_i, PCHAR_d, PCHAR_e, PCHAR_n, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_l, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_i, PCHAR_l, PCHAR_k, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_a, PCHAR_r, PCHAR_f, 0xff, 0, 0, 0})),
		0xd9, //index
		100, //price
		60, //holding_effect_id
		20, //holding_effect_param
		str_item_desc_xd9_item_seidenschal,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_UP_GRADE
		PSTRING(P99_PROCTECT({PCHAR_U, PCHAR_p, PCHAR_MINUS, PCHAR_G, PCHAR_r, PCHAR_a, PCHAR_d, PCHAR_e, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_U, PCHAR_p, PCHAR_MINUS, PCHAR_G, PCHAR_r, PCHAR_a, PCHAR_d, PCHAR_e, 0xff, 0, 0, 0, 0, 0})),
		0xda, //index
		2100, //price
		61, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xda_item_up_grade,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SEEGESANG
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_g, PCHAR_e, PCHAR_s, PCHAR_a, PCHAR_n, PCHAR_g, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_h, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_l, PCHAR_l, 0xff, 0, 0, 0})),
		0xdb, //index
		200, //price
		62, //holding_effect_id
		8, //holding_effect_param
		str_item_desc_xdb_item_seegesang,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SEERAUCH
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_a, PCHAR_u, PCHAR_c, PCHAR_h, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_e, PCHAR_a, PCHAR_SPACE, PCHAR_I, PCHAR_n, PCHAR_c, PCHAR_e, PCHAR_n, PCHAR_s, PCHAR_e, 0xff, 0, 0})),
		0xdc, //index
		9600, //price
		52, //holding_effect_id
		5, //holding_effect_param
		str_item_desc_xdc_item_seerauch,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LAXRAUCH
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_x, PCHAR_r, PCHAR_a, PCHAR_u, PCHAR_c, PCHAR_h, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_a, PCHAR_x, PCHAR_SPACE, PCHAR_I, PCHAR_n, PCHAR_c, PCHAR_e, PCHAR_n, PCHAR_s, PCHAR_e, 0xff, 0, 0})),
		0xdd, //index
		9600, //price
		22, //holding_effect_id
		5, //holding_effect_param
		str_item_desc_xdd_item_laxrauch,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LUCKY_PUNCH
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_u, PCHAR_c, PCHAR_k, PCHAR_y, PCHAR_SPACE, PCHAR_P, PCHAR_u, PCHAR_n, PCHAR_c, PCHAR_h, 0xff, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_u, PCHAR_c, PCHAR_k, PCHAR_y, PCHAR_SPACE, PCHAR_P, PCHAR_u, PCHAR_n, PCHAR_c, PCHAR_h, 0xff, 0, 0})),
		0xde, //index
		10, //price
		63, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xde_item_lucky_punch,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_METALLSTAUB
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_t, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_s, PCHAR_t, PCHAR_a, PCHAR_u, PCHAR_b, 0xff, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_e, PCHAR_t, PCHAR_a, PCHAR_l, PCHAR_SPACE, PCHAR_P, PCHAR_o, PCHAR_w, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0})),
		0xdf, //index
		10, //price
		64, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xdf_item_metallstaub,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KAMPFKNOCHEN
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_a, PCHAR_m, PCHAR_p, PCHAR_f, PCHAR_k, PCHAR_n, PCHAR_o, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_n, 0xff, 0}), P99_PROTECT({PCHAR_T, PCHAR_h, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_SPACE, PCHAR_C, PCHAR_l, PCHAR_u, PCHAR_b, 0xff, 0, 0, 0})),
		0xe0, //index
		500, //price
		65, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xe0_item_kampfknochen,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LAUCHSTANGE
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_s, PCHAR_t, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_k, 0xff, 0, 0, 0, 0, 0, 0, 0, 0})),
		0xe1, //index
		200, //price
		66, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xe1_item_lauchstange,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BISAFLORNIT
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_s, PCHAR_a, PCHAR_f, PCHAR_l, PCHAR_o, PCHAR_r, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xe2, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xe2_item_bisaflornit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GLURAKNIT
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_l, PCHAR_u, PCHAR_r, PCHAR_a, PCHAR_k, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xe3, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xe3_item_gluraknit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TURTOKNIT
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_u, PCHAR_r, PCHAR_t, PCHAR_o, PCHAR_k, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xe4, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xe4_item_turtoknit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TERRASORNIT
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_a, PCHAR_s, PCHAR_o, PCHAR_r, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xe5, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xe5_item_terrasornit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ZERBERNIT
		PSTRING(P99_PROCTECT({PCHAR_Z, PCHAR_e, PCHAR_r, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xe6, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xe6_item_zerbernit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SKULLYDRANIT
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_k, PCHAR_u, PCHAR_l, PCHAR_l, PCHAR_y, PCHAR_d, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xe7, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xe7_item_skullydranit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AQUANANIT
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_q, PCHAR_u, PCHAR_a, PCHAR_n, PCHAR_a, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xe8, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xe8_item_aquananit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FLAMARANIT
		PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_a, PCHAR_m, PCHAR_a, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xe9, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xe9_item_flamaranit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLITZANIT
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_i, PCHAR_t, PCHAR_z, PCHAR_a, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xea, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xea_item_blitzanit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AMPHAROSNIT
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_m, PCHAR_p, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_o, PCHAR_s, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xeb, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xeb_item_ampharosnit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GENGARNIT
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_n, PCHAR_g, PCHAR_a, PCHAR_r, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xec, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xec_item_gengarnit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BIBORNIT
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_b, PCHAR_o, PCHAR_r, PCHAR_n, PCHAR_i, PCHAR_t, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xed, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xed_item_bibornit,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_EE
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_m, PCHAR_a, PCHAR_h, PCHAR_e, PCHAR_r, PCHAR_z, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0xee, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xee_item_item_ee,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_EF
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xef_item_item_ef,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F0
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xf0_item_item_f0,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F1
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xf1_item_item_f1,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F2
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xf2_item_item_f2,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F3
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xf3_item_item_f3,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F4
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xf4_item_item_f4,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F5
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xf5_item_item_f5,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F6
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xf6_item_item_f6,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F7
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xf7_item_item_f7,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F8
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xf8_item_item_f8,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F9
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xf9_item_item_f9,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_FA
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xfa_item_item_fa,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_FB
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xfb_item_item_fb,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_FC
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xfc_item_item_fc,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_FD
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xfd_item_item_fd,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ROTER_SCHAL
		PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_l, 0xff, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_e, PCHAR_d, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_a, PCHAR_r, PCHAR_f, 0xff, 0, 0, 0, 0})),
		0xfe, //index
		100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xfe_item_roter_schal,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLAUER_SCHAL
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_a, PCHAR_u, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_l, 0xff, 0}), P99_PROTECT({PCHAR_B, PCHAR_l, PCHAR_u, PCHAR_e, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_a, PCHAR_r, PCHAR_f, 0xff, 0, 0, 0})),
		0xff, //index
		100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_xff_item_blauer_schal,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ROSA_SCHAL
		PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_s, PCHAR_a, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_l, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_i, PCHAR_n, PCHAR_k, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_a, PCHAR_r, PCHAR_f, 0xff, 0, 0, 0})),
		0x100, //index
		100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x100_item_rosa_schal,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GRUENER_SCHAL
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_r, PCHAR_ue, PCHAR_n, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_l, 0xff, 0}), P99_PROTECT({PCHAR_G, PCHAR_r, PCHAR_e, PCHAR_e, PCHAR_n, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_a, PCHAR_r, PCHAR_f, 0xff, 0, 0})),
		0x101, //index
		100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x101_item_gruener_schal,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GELBER_SCHAL
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_l, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_l, 0xff, 0}), P99_PROTECT({PCHAR_Y, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_o, PCHAR_w, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_a, PCHAR_r, PCHAR_f, 0xff, 0})),
		0x102, //index
		100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x102_item_gelber_schal,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EILRAD
		PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_l, PCHAR_r, PCHAR_a, PCHAR_d, 0xff, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_SPACE, PCHAR_B, PCHAR_i, PCHAR_k, PCHAR_e, 0xff, 0, 0, 0, 0})),
		0x103, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x103_item_eilrad,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1319, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MUENZKORB
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_ue, PCHAR_n, PCHAR_z, PCHAR_k, PCHAR_o, PCHAR_r, PCHAR_b, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_C, PCHAR_o, PCHAR_i, PCHAR_n, PCHAR_SPACE, PCHAR_C, PCHAR_a, PCHAR_s, PCHAR_e, 0xff, 0, 0, 0, 0})),
		0x104, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x104_item_muenzkorb,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a154d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DETEKTOR
		PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_e, PCHAR_t, PCHAR_e, PCHAR_k, PCHAR_t, PCHAR_o, PCHAR_r, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_I, PCHAR_t, PCHAR_e, PCHAR_m, PCHAR_f, PCHAR_i, PCHAR_n, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0})),
		0x105, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x105_item_detektor,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1525, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ANGEL
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_n, PCHAR_g, PCHAR_e, PCHAR_l, 0xff, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_O, PCHAR_l, PCHAR_d, PCHAR_SPACE, PCHAR_R, PCHAR_o, PCHAR_d, 0xff, 0, 0, 0, 0, 0, 0})),
		0x106, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x106_item_angel,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1425, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PROFIANGEL
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_r, PCHAR_o, PCHAR_f, PCHAR_i, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_e, PCHAR_l, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_G, PCHAR_o, PCHAR_o, PCHAR_d, PCHAR_SPACE, PCHAR_R, PCHAR_o, PCHAR_d, 0xff, 0, 0, 0, 0, 0})),
		0x107, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x107_item_profiangel,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1425, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SUPERANGEL
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_u, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_e, PCHAR_l, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_u, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_R, PCHAR_o, PCHAR_d, 0xff, 0, 0, 0, 0})),
		0x108, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x108_item_superangel,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1425, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BOOTSTICKET
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_o, PCHAR_o, PCHAR_t, PCHAR_s, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_t, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_DOT, PCHAR_s, PCHAR_DOT, PCHAR_SPACE, PCHAR_T, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_t, 0xff, 0, 0})),
		0x109, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x109_item_bootsticket,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WETTB_KARTE
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_e, PCHAR_t, PCHAR_t, PCHAR_b, PCHAR_DOT, PCHAR_MINUS, PCHAR_K, PCHAR_a, PCHAR_r, PCHAR_t, PCHAR_e, 0xff, 0}), P99_PROTECT({PCHAR_C, PCHAR_o, PCHAR_n, PCHAR_t, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_SPACE, PCHAR_P, PCHAR_a, PCHAR_s, PCHAR_s, 0xff, 0})),
		0x10a, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x10a_item_wettb_karte,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_10B
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_o, PCHAR_l, PCHAR_k, PCHAR_e, PCHAR_n, PCHAR_h, PCHAR_e, PCHAR_r, PCHAR_z, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x10b, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x10b_item_item_10b,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WAILMERKANNE
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_i, PCHAR_l, PCHAR_m, PCHAR_e, PCHAR_r, PCHAR_k, PCHAR_a, PCHAR_n, PCHAR_n, PCHAR_e, 0xff, 0}), P99_PROTECT({PCHAR_W, PCHAR_a, PCHAR_i, PCHAR_l, PCHAR_m, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_P, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0})),
		0x10c, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x10c_item_wailmerkanne,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DEVON_WAREN
		PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_e, PCHAR_v, PCHAR_o, PCHAR_n, PCHAR_MINUS, PCHAR_W, PCHAR_a, PCHAR_r, PCHAR_e, PCHAR_n, 0xff, 0, 0}), P99_PROTECT({PCHAR_D, PCHAR_e, PCHAR_v, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_G, PCHAR_o, PCHAR_o, PCHAR_d, PCHAR_s, 0xff, 0, 0})),
		0x10d, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x10d_item_devon_waren,
		2, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ASCHETASCHE
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_t, PCHAR_a, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_o, PCHAR_o, PCHAR_t, PCHAR_SPACE, PCHAR_S, PCHAR_a, PCHAR_c, PCHAR_k, 0xff, 0, 0, 0, 0})),
		0x10e, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x10e_item_aschetasche,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		item_ashbag_field, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KELLEROEFFNER
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_e, PCHAR_r, PCHAR_oe, PCHAR_f, PCHAR_f, PCHAR_n, PCHAR_e, PCHAR_r, 0xff, 0}), P99_PROTECT({PCHAR_B, PCHAR_a, PCHAR_s, PCHAR_e, PCHAR_m, PCHAR_e, PCHAR_n, PCHAR_t, PCHAR_SPACE, PCHAR_K, PCHAR_e, PCHAR_y, 0xff, 0})),
		0x10f, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x10f_item_kelleroeffner,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KUNSTRAD
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_u, PCHAR_n, PCHAR_s, PCHAR_t, PCHAR_r, PCHAR_a, PCHAR_d, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_A, PCHAR_c, PCHAR_r, PCHAR_o, PCHAR_SPACE, PCHAR_B, PCHAR_i, PCHAR_k, PCHAR_e, 0xff, 0, 0, 0, 0})),
		0x110, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x110_item_kunstrad,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1319, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BOX
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_o, PCHAR_x, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({0x55, 0x56, 0x57, 0x58, 0x59, PCHAR_SPACE, PCHAR_C, PCHAR_a, PCHAR_s, PCHAR_e, 0xff, 0, 0, 0})),
		0x111, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x111_item_box,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BRIEF
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_f, 0xff, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_e, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0, 0, 0, 0})),
		0x112, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x112_item_brief,
		2, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AEON_TICKET
		PSTRING(P99_PROCTECT({PCHAR_ae, PCHAR_o, PCHAR_n, PCHAR_MINUS, PCHAR_T, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_t, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_E, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_T, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_t, 0xff, 0, 0, 0})),
		0x113, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x113_item_aeon_ticket,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPIRITKERN
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_i, PCHAR_r, PCHAR_i, PCHAR_t, PCHAR_k, PCHAR_e, PCHAR_r, PCHAR_n, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_e, PCHAR_d, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, 0xff, 0, 0, 0, 0, 0, 0})),
		0x114, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x114_item_spiritkern,
		2, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLAUE_KUGEL
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_a, PCHAR_u, PCHAR_e, PCHAR_SPACE, PCHAR_K, PCHAR_u, PCHAR_g, PCHAR_e, PCHAR_l, 0xff, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_l, PCHAR_u, PCHAR_e, PCHAR_SPACE, PCHAR_O, PCHAR_r, PCHAR_b, 0xff, 0, 0, 0, 0, 0})),
		0x115, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x115_item_blaue_kugel,
		2, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCANNER
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_a, PCHAR_n, PCHAR_n, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_c, PCHAR_a, PCHAR_n, PCHAR_n, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0, 0, 0})),
		0x116, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x116_item_scanner,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WUESTENGLAS
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_ue, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_n, PCHAR_g, PCHAR_l, PCHAR_a, PCHAR_s, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_G, PCHAR_o, PCHAR_MINUS, PCHAR_G, PCHAR_o, PCHAR_g, PCHAR_g, PCHAR_l, PCHAR_e, PCHAR_s, 0xff, 0, 0, 0})),
		0x117, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x117_item_wuestenglas,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_METEORIT
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_t, PCHAR_e, PCHAR_o, PCHAR_r, PCHAR_i, PCHAR_t, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_M, PCHAR_e, PCHAR_t, PCHAR_e, PCHAR_o, PCHAR_r, PCHAR_i, PCHAR_t, PCHAR_e, 0xff, 0, 0, 0, 0})),
		0x118, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x118_item_meteorit,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_K1_SCHLUESSEL
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_1, PCHAR_MINUS, PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_ue, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_l, 0xff, 0}), P99_PROTECT({PCHAR_R, PCHAR_m, PCHAR_DOT, PCHAR_SPACE, PCHAR_1, PCHAR_SPACE, PCHAR_K, PCHAR_e, PCHAR_y, 0xff, 0, 0, 0, 0})),
		0x119, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x119_item_k1_schluessel,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_K2_SCHLUESSEL
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_2, PCHAR_MINUS, PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_ue, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_l, 0xff, 0}), P99_PROTECT({PCHAR_R, PCHAR_m, PCHAR_DOT, PCHAR_SPACE, PCHAR_2, PCHAR_SPACE, PCHAR_K, PCHAR_e, PCHAR_y, 0xff, 0, 0, 0, 0})),
		0x11a, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x11a_item_k2_schluessel,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_K4_SCHLUESSEL
		PSTRING(P99_PROCTECT({PCHAR_K, 0xa5, PCHAR_MINUS, PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_ue, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_l, 0xff, 0}), P99_PROTECT({PCHAR_R, PCHAR_m, PCHAR_DOT, PCHAR_SPACE, 0xa5, PCHAR_SPACE, PCHAR_K, PCHAR_e, PCHAR_y, 0xff, 0, 0, 0, 0})),
		0x11b, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x11b_item_k4_schluessel,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_K6_SCHLUESSEL
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_6, PCHAR_MINUS, PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_ue, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_l, 0xff, 0}), P99_PROTECT({PCHAR_R, PCHAR_m, PCHAR_DOT, PCHAR_SPACE, PCHAR_6, PCHAR_SPACE, PCHAR_K, PCHAR_e, PCHAR_y, 0xff, 0, 0, 0, 0})),
		0x11c, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x11c_item_k6_schluessel,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_L_SCHLUESSEL
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_DOT, PCHAR_MINUS, PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_ue, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_l, 0xff, 0}), P99_PROTECT({PCHAR_S, PCHAR_t, PCHAR_o, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_e, PCHAR_SPACE, PCHAR_K, PCHAR_e, PCHAR_y, 0xff, 0, 0})),
		0x11d, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x11d_item_l_schluessel,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WURZELFOSSIL
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_u, PCHAR_r, PCHAR_z, PCHAR_e, PCHAR_l, PCHAR_f, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, 0xff, 0}), P99_PROTECT({PCHAR_R, PCHAR_o, PCHAR_o, PCHAR_t, PCHAR_SPACE, PCHAR_F, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, 0xff, 0, 0})),
		0x11e, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x11e_item_wurzelfossil,
		0, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KLAUENFOSSIL
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_l, PCHAR_a, PCHAR_u, PCHAR_e, PCHAR_n, PCHAR_f, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, 0xff, 0}), P99_PROTECT({PCHAR_C, PCHAR_l, PCHAR_a, PCHAR_w, PCHAR_SPACE, PCHAR_F, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, 0xff, 0, 0})),
		0x11f, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x11f_item_klauenfossil,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DEVON_SCOPE
		PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_e, PCHAR_v, PCHAR_o, PCHAR_n, PCHAR_MINUS, PCHAR_S, PCHAR_c, PCHAR_o, PCHAR_p, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_D, PCHAR_e, PCHAR_v, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_o, PCHAR_p, PCHAR_e, 0xff, 0, 0})),
		0x120, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x120_item_devon_scope,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM01
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x121, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x121_item_tm01,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM02
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x122, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x122_item_tm02,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM03
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x123, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x123_item_tm03,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM04
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_0, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_0, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x124, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x124_item_tm04,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM05
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x125, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x125_item_tm05,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM06
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x126, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x126_item_tm06,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM07
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x127, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x127_item_tm07,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM08
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x128, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x128_item_tm08,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM09
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_9, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_0, PCHAR_9, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x129, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x129_item_tm09,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM10
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x12a, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x12a_item_tm10,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM11
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x12b, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x12b_item_tm11,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM12
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x12c, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x12c_item_tm12,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM13
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x12d, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x12d_item_tm13,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM14
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_1, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_1, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x12e, //index
		5500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x12e_item_tm14,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM15
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x12f, //index
		7500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x12f_item_tm15,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM16
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x130, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x130_item_tm16,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM17
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x131, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x131_item_tm17,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM18
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x132, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x132_item_tm18,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM19
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_9, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_1, PCHAR_9, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x133, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x133_item_tm19,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM20
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x134, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x134_item_tm20,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM21
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x135, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x135_item_tm21,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM22
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x136, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x136_item_tm22,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM23
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x137, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x137_item_tm23,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM24
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_2, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_2, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x138, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x138_item_tm24,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM25
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x139, //index
		5500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x139_item_tm25,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM26
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x13a, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x13a_item_tm26,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM27
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x13b, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x13b_item_tm27,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM28
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x13c, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x13c_item_tm28,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM29
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_9, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_2, PCHAR_9, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x13d, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x13d_item_tm29,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM30
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x13e, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x13e_item_tm30,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM31
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x13f, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x13f_item_tm31,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM32
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x140, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x140_item_tm32,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM33
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x141, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x141_item_tm33,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM34
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_3, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_3, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x142, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x142_item_tm34,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM35
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x143, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x143_item_tm35,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM36
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x144, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x144_item_tm36,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM37
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x145, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x145_item_tm37,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM38
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x146, //index
		5500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x146_item_tm38,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM39
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_9, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_3, PCHAR_9, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x147, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x147_item_tm39,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM40
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x148, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x148_item_tm40,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM41
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x149, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x149_item_tm41,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM42
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x14a, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x14a_item_tm42,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM43
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x14b, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x14b_item_tm43,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM44
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, 0xa5, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, 0xa5, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x14c, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x14c_item_tm44,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM45
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x14d, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x14d_item_tm45,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM46
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x14e, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x14e_item_tm46,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM47
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x14f, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x14f_item_tm47,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM48
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x150, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x150_item_tm48,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM49
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_9, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, 0xa5, PCHAR_9, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x151, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x151_item_tm49,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM50
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_m, PCHAR_5, PCHAR_0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_5, PCHAR_0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x152, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x152_item_tm50,
		0, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM01
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_m, PCHAR_0, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_m, PCHAR_0, PCHAR_1, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x153, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x153_item_vm01,
		1, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM02
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_m, PCHAR_0, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_m, PCHAR_0, PCHAR_2, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x154, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x154_item_vm02,
		1, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM03
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_m, PCHAR_0, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_m, PCHAR_0, PCHAR_3, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x155, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x155_item_vm03,
		1, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM04
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_m, PCHAR_0, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_m, PCHAR_0, 0xa5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x156, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x156_item_vm04,
		1, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM05
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_m, PCHAR_0, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_m, PCHAR_0, PCHAR_5, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x157, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x157_item_vm05,
		1, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM06
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_m, PCHAR_0, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_m, PCHAR_0, PCHAR_6, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x158, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x158_item_vm06,
		1, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM07
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_m, PCHAR_0, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_m, PCHAR_0, PCHAR_7, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x159, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x159_item_vm07,
		1, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM08
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_m, PCHAR_0, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_m, PCHAR_0, PCHAR_8, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x15a, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x15a_item_vm08,
		1, //field_18
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_15B
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x15b_item_item_15b,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_15C
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, PCHAR_QUESTION, 0xff, 0, 0, 0, 0, 0})),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x15c_item_item_15c,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EICHS_PAKET
		PSTRING(P99_PROCTECT({PCHAR_Z, PCHAR_u, PCHAR_g, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_s, PCHAR_k, PCHAR_a, PCHAR_r, PCHAR_t, PCHAR_e, 0xff, 0}), P99_PROTECT({PCHAR_O, PCHAR_a, PCHAR_k, 0xb4, PCHAR_s, PCHAR_SPACE, PCHAR_P, PCHAR_a, PCHAR_r, PCHAR_c, PCHAR_e, PCHAR_l, 0xff, 0})),
		0x15d, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x15d_item_eichs_paket,
		2, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_POKEFLOETE
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_k, 0xef, PCHAR_l, PCHAR_oe, PCHAR_t, PCHAR_e, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_P, PCHAR_o, PCHAR_k, PCHAR_POKE_E, PCHAR_SPACE, PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_t, PCHAR_e, 0xff, 0, 0, 0})),
		0x15e, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x15e_item_pokefloete,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1659, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f51, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM__OEFFNER
		PSTRING(P99_PROCTECT({PCHAR_QUESTION, PCHAR_MINUS, PCHAR_oe, PCHAR_f, PCHAR_f, PCHAR_n, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_e, PCHAR_c, PCHAR_r, PCHAR_e, PCHAR_t, PCHAR_SPACE, PCHAR_K, PCHAR_e, PCHAR_y, 0xff, 0, 0, 0})),
		0x15f, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x15f_item__oeffner,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RAD_COUPON
		PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_a, PCHAR_d, PCHAR_MINUS, PCHAR_C, PCHAR_o, PCHAR_u, PCHAR_p, PCHAR_o, PCHAR_n, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_i, PCHAR_k, PCHAR_e, PCHAR_SPACE, PCHAR_V, PCHAR_o, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0})),
		0x160, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x160_item_rad_coupon,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PKMCORDER
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_k, PCHAR_m, PCHAR_c, PCHAR_o, PCHAR_r, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_G, PCHAR_o, PCHAR_l, PCHAR_d, PCHAR_SPACE, PCHAR_T, PCHAR_e, PCHAR_e, PCHAR_t, PCHAR_h, 0xff, 0, 0, 0})),
		0x161, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x161_item_pkmcorder,
		2, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ALTBERNSTEIN
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_l, PCHAR_t, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_n, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0}), P99_PROTECT({PCHAR_O, PCHAR_l, PCHAR_d, PCHAR_SPACE, PCHAR_A, PCHAR_m, PCHAR_b, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0})),
		0x162, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x162_item_altbernstein,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TUEROEFFNER
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_ue, PCHAR_r, PCHAR_oe, PCHAR_f, PCHAR_f, PCHAR_n, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_C, PCHAR_a, PCHAR_r, PCHAR_d, PCHAR_SPACE, PCHAR_K, PCHAR_e, PCHAR_y, 0xff, 0, 0, 0, 0, 0})),
		0x163, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x163_item_tueroeffner,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LIFTOEFFNER
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_oe, PCHAR_f, PCHAR_f, PCHAR_n, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_L, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_SPACE, PCHAR_K, PCHAR_e, PCHAR_y, 0xff, 0, 0, 0, 0, 0})),
		0x164, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x164_item_liftoeffner,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HELIXFOSSIL
		PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_e, PCHAR_l, PCHAR_i, PCHAR_x, PCHAR_f, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, 0xff, 0, 0}), P99_PROTECT({PCHAR_H, PCHAR_e, PCHAR_l, PCHAR_i, PCHAR_x, PCHAR_SPACE, PCHAR_F, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, 0xff, 0})),
		0x165, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x165_item_helixfossil,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DOMFOSSIL
		PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_o, PCHAR_m, PCHAR_f, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_D, PCHAR_o, PCHAR_m, PCHAR_e, PCHAR_SPACE, PCHAR_F, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, 0xff, 0, 0})),
		0x166, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x166_item_domfossil,
		0, //field_18
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SILPH_SCOPE
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_i, PCHAR_l, PCHAR_p, PCHAR_h, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_o, PCHAR_p, PCHAR_e, 0xff, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_i, PCHAR_l, PCHAR_p, PCHAR_h, PCHAR_SPACE, PCHAR_S, PCHAR_c, PCHAR_o, PCHAR_p, PCHAR_e, 0xff, 0, 0})),
		0x167, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x167_item_silph_scope,
		1, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FAHRRAD
		PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_o, PCHAR_l, PCHAR_k, PCHAR_e, 0xff, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_i, PCHAR_c, PCHAR_y, PCHAR_c, PCHAR_l, PCHAR_e, 0xff, 0, 0, 0, 0, 0, 0})),
		0x1ff, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x168_item_fahrrad,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KARTE
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_a, PCHAR_r, PCHAR_t, PCHAR_e, 0xff, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_o, PCHAR_w, PCHAR_n, PCHAR_SPACE, PCHAR_M, PCHAR_a, PCHAR_p, 0xff, 0, 0, 0, 0, 0})),
		0x169, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x169_item_karte,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KAMPFFAHNDER
		PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_a, PCHAR_m, PCHAR_p, PCHAR_f, PCHAR_f, PCHAR_a, PCHAR_h, PCHAR_n, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0}), P99_PROTECT({PCHAR_V, PCHAR_s, PCHAR_SPACE, PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_k, PCHAR_e, PCHAR_r, 0xff, 0, 0, 0, 0})),
		0x16a, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x16a_item_kampffahnder,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1e89, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RUHMESDATEI
		PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_u, PCHAR_h, PCHAR_m, PCHAR_e, PCHAR_s, PCHAR_d, PCHAR_a, PCHAR_t, PCHAR_e, PCHAR_i, 0xff, 0, 0}), P99_PROTECT({PCHAR_F, PCHAR_a, PCHAR_m, PCHAR_e, PCHAR_SPACE, PCHAR_C, PCHAR_h, PCHAR_e, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_r, 0xff, 0})),
		0x16b, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x16b_item_ruhmesdatei,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1de5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VMTM_BOX
		PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_m, PCHAR_SLASH, PCHAR_t, PCHAR_m, PCHAR_MINUS, PCHAR_B, PCHAR_o, PCHAR_x, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_m, PCHAR_SPACE, PCHAR_C, PCHAR_a, PCHAR_s, PCHAR_e, 0xff, 0, 0, 0, 0, 0, 0})),
		0x16c, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x16c_item_vmtm_box,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1875, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BEERENTUETE
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_e, PCHAR_n, PCHAR_t, PCHAR_ue, PCHAR_t, PCHAR_e, 0xff, 0, 0, 0}), P99_PROTECT({PCHAR_B, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_y, PCHAR_SPACE, PCHAR_P, PCHAR_o, PCHAR_u, PCHAR_c, PCHAR_h, 0xff, 0, 0})),
		0x16d, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x16d_item_beerentuete,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a190d, //field_usage
		(void(*)(u8))0x3, //battle_usage1
		(void(*)(u8))0x80a19a5, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LEHRKANAL
		PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_e, PCHAR_h, PCHAR_r, PCHAR_k, PCHAR_a, PCHAR_n, PCHAR_a, PCHAR_l, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_e, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_y, PCHAR_SPACE, PCHAR_T, PCHAR_v, 0xff, 0, 0, 0, 0})),
		0x16e, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x16e_item_lehrkanal,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a19d9, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TRI_PASS
		PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_i, PCHAR_MINUS, PCHAR_P, PCHAR_a, PCHAR_s, PCHAR_s, 0xff, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_T, PCHAR_r, PCHAR_i, PCHAR_MINUS, PCHAR_P, PCHAR_a, PCHAR_s, PCHAR_s, 0xff, 0, 0, 0, 0, 0})),
		0x16f, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x16f_item_tri_pass,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BUNT_PASS
		PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_u, PCHAR_n, PCHAR_t, PCHAR_MINUS, PCHAR_P, PCHAR_a, PCHAR_s, PCHAR_s, 0xff, 0, 0, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_a, PCHAR_i, PCHAR_n, PCHAR_b, PCHAR_o, PCHAR_w, PCHAR_SPACE, PCHAR_P, PCHAR_a, PCHAR_s, PCHAR_s, 0xff, 0})),
		0x170, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x170_item_bunt_pass,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MEGA_AMULETT
		PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_g, PCHAR_a, PCHAR_MINUS, PCHAR_A, PCHAR_m, PCHAR_u, PCHAR_l, PCHAR_e, PCHAR_t, PCHAR_t, 0xff, 0}), P99_PROTECT({PCHAR_T, PCHAR_e, PCHAR_a, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x171, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x171_item_mega_amulett,
		513, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0xe, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GEHEIMTICKET
		PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_h, PCHAR_e, PCHAR_i, PCHAR_m, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_t, 0xff, 0}), P99_PROTECT({PCHAR_M, PCHAR_y, PCHAR_s, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_t, 0xff, 0})),
		0x172, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x172_item_geheimticket,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AURORATICKET
		PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_u, PCHAR_r, PCHAR_o, PCHAR_r, PCHAR_a, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_t, 0xff, 0}), P99_PROTECT({PCHAR_A, PCHAR_u, PCHAR_r, PCHAR_o, PCHAR_r, PCHAR_a, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_t, 0xff, 0})),
		0x173, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x173_item_auroraticket,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PUDERDOESCHEN
		PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_u, PCHAR_d, PCHAR_e, PCHAR_r, PCHAR_d, PCHAR_oe, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_n, 0xff, 0}), P99_PROTECT({PCHAR_P, PCHAR_o, PCHAR_w, PCHAR_d, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_J, PCHAR_a, PCHAR_r, 0xff, 0, 0, 0})),
		0x174, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x174_item_puderdoeschen,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a15d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RUBIN
		PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_u, PCHAR_b, PCHAR_i, PCHAR_n, 0xff, 0, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_R, PCHAR_u, PCHAR_b, PCHAR_y, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0})),
		0x175, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x175_item_rubin,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SAPHIR
		PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_a, PCHAR_p, PCHAR_h, PCHAR_i, PCHAR_r, 0xff, 0, 0, 0, 0, 0, 0, 0}), P99_PROTECT({PCHAR_S, PCHAR_a, PCHAR_p, PCHAR_p, PCHAR_h, PCHAR_i, PCHAR_r, PCHAR_e, 0xff, 0, 0, 0, 0, 0})),
		0x176, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_desc_x176_item_saphir,
		257, //field_18
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},
};
