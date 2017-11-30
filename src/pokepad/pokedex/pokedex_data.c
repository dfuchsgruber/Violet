#include "types.h"
#include "pokedex.h"
#include "pstring.h"

extern u8 str_pokedex_mamutel[];
extern u8 str_pokedex_none[];

pokedex_data dex_data[POKEDEX_CNT + 1] = {
    {
	//Entry 0
	PSTRING(P99_PROCTECT({PCHAR_U, PCHAR_n, PCHAR_b, PCHAR_e, PCHAR_k, PCHAR_a, PCHAR_n, PCHAR_n, PCHAR_t, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_U, PCHAR_n, PCHAR_k, PCHAR_n, PCHAR_o, PCHAR_w, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0})),
	0, 0,//Height & weight
	str_pokedex_data_0_page_0, str_pokedex_data_0_page_1,
	0,//unused
	256, 0,//Pokemon scale, displacement
	256, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 1
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_a, PCHAR_m, PCHAR_e, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	7, 69,//Height & weight
	str_pokedex_data_1_page_0, str_pokedex_data_1_page_1,
	0,//unused
	356, 16,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 2
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_a, PCHAR_m, PCHAR_e, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	10, 130,//Height & weight
	str_pokedex_data_2_page_0, str_pokedex_data_2_page_1,
	0,//unused
	332, 11,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 3
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_a, PCHAR_m, PCHAR_e, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	20, 1000,//Height & weight
	str_pokedex_data_3_page_0, str_pokedex_data_3_page_1,
	0,//unused
	256, 1,//Pokemon scale, displacement
	375, 6,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 4
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_c, PCHAR_h, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_z, PCHAR_a, PCHAR_r, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 85,//Height & weight
	str_pokedex_data_4_page_0, str_pokedex_data_4_page_1,
	0,//unused
	410, 16,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 5
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_a, PCHAR_m, PCHAR_m, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_a, PCHAR_m, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	11, 190,//Height & weight
	str_pokedex_data_5_page_0, str_pokedex_data_5_page_1,
	0,//unused
	294, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 6
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_a, PCHAR_m, PCHAR_m, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_a, PCHAR_m, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	17, 905,//Height & weight
	str_pokedex_data_6_page_0, str_pokedex_data_6_page_1,
	0,//unused
	271, 0,//Pokemon scale, displacement
	317, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 7
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_i, PCHAR_n, PCHAR_i, PCHAR_k, PCHAR_r, PCHAR_oe, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_i, PCHAR_n, PCHAR_y, PCHAR_SPACE, PCHAR_T, PCHAR_u, PCHAR_r, PCHAR_t, PCHAR_l, PCHAR_e, 0xff})),
	5, 90,//Height & weight
	str_pokedex_data_7_page_0, str_pokedex_data_7_page_1,
	0,//unused
	412, 16,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 8
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_oe, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_u, PCHAR_r, PCHAR_t, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	10, 225,//Height & weight
	str_pokedex_data_8_page_0, str_pokedex_data_8_page_1,
	0,//unused
	334, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 9
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_a, PCHAR_n, PCHAR_z, PCHAR_e, PCHAR_r, PCHAR_t, PCHAR_i, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_h, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_f, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0})),
	16, 855,//Height & weight
	str_pokedex_data_9_page_0, str_pokedex_data_9_page_1,
	0,//unused
	256, 1,//Pokemon scale, displacement
	329, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 10
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_t, PCHAR_k, PCHAR_e, PCHAR_h, PCHAR_l, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_n, 0xff}), P99_PROCTECT({PCHAR_W, PCHAR_o, PCHAR_r, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	3, 29,//Height & weight
	str_pokedex_data_10_page_0, str_pokedex_data_10_page_1,
	0,//unused
	549, 20,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 11
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_u, PCHAR_n, PCHAR_k, PCHAR_e, PCHAR_n, PCHAR_r, PCHAR_e, PCHAR_g, PCHAR_e, PCHAR_n, 0xff}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_c, PCHAR_o, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	7, 160,//Height & weight
	str_pokedex_data_11_page_0, str_pokedex_data_11_page_1,
	0,//unused
	350, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 12
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_h, PCHAR_f, PCHAR_l, PCHAR_a, PCHAR_m, PCHAR_m, PCHAR_e, 0xff}), P99_PROCTECT({PCHAR_B, PCHAR_u, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_f, PCHAR_l, PCHAR_y, 0xff, 0x0, 0x0})),
	12, 320,//Height & weight
	str_pokedex_data_12_page_0, str_pokedex_data_12_page_1,
	0,//unused
	312, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 13
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_a, PCHAR_u, PCHAR_p, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_a, PCHAR_i, PCHAR_r, PCHAR_y, PCHAR_SPACE, PCHAR_B, PCHAR_u, PCHAR_g, 0xff, 0x0, 0x0})),
	3, 32,//Height & weight
	str_pokedex_data_13_page_0, str_pokedex_data_13_page_1,
	0,//unused
	455, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 14
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_o, PCHAR_k, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_c, PCHAR_o, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 100,//Height & weight
	str_pokedex_data_14_page_0, str_pokedex_data_14_page_1,
	0,//unused
	424, 14,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 15
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_b, PCHAR_i, PCHAR_e, PCHAR_n, PCHAR_e, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_e, 0xff, 0x0})),
	10, 295,//Height & weight
	str_pokedex_data_15_page_0, str_pokedex_data_15_page_1,
	0,//unused
	366, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 16
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_i, PCHAR_n, PCHAR_y, PCHAR_SPACE, PCHAR_B, PCHAR_i, PCHAR_r, PCHAR_d, 0xff, 0x0, 0x0})),
	3, 18,//Height & weight
	str_pokedex_data_16_page_0, str_pokedex_data_16_page_1,
	0,//unused
	492, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 17
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_r, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	11, 300,//Height & weight
	str_pokedex_data_17_page_0, str_pokedex_data_17_page_1,
	0,//unused
	334, 11,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 18
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_r, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	15, 395,//Height & weight
	str_pokedex_data_18_page_0, str_pokedex_data_18_page_1,
	0,//unused
	269, 65534,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 19
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_r, PCHAR_o, PCHAR_n, PCHAR_z, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_u, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	3, 35,//Height & weight
	str_pokedex_data_19_page_0, str_pokedex_data_19_page_1,
	0,//unused
	481, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 20
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_r, PCHAR_o, PCHAR_n, PCHAR_z, PCHAR_e, PCHAR_g, PCHAR_l, PCHAR_o, PCHAR_c, PCHAR_k, 0xff}), P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_u, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	7, 185,//Height & weight
	str_pokedex_data_20_page_0, str_pokedex_data_20_page_1,
	0,//unused
	401, 14,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 21
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_i, PCHAR_t, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_i, PCHAR_n, PCHAR_y, PCHAR_SPACE, PCHAR_B, PCHAR_i, PCHAR_r, PCHAR_d, 0xff, 0x0, 0x0})),
	3, 20,//Height & weight
	str_pokedex_data_21_page_0, str_pokedex_data_21_page_1,
	0,//unused
	571, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 22
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_i, PCHAR_t, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_e, PCHAR_a, PCHAR_k, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	12, 380,//Height & weight
	str_pokedex_data_22_page_0, str_pokedex_data_22_page_1,
	0,//unused
	282, 65535,//Pokemon scale, displacement
	272, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 23
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_u, PCHAR_m, PCHAR_s, PCHAR_t, PCHAR_u, PCHAR_m, PCHAR_p, PCHAR_f, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_n, PCHAR_a, PCHAR_k, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	20, 69,//Height & weight
	str_pokedex_data_23_page_0, str_pokedex_data_23_page_1,
	0,//unused
	298, 13,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 24
	PSTRING(P99_PROCTECT({PCHAR_U, PCHAR_r, PCHAR_g, PCHAR_e, PCHAR_h, PCHAR_oe, PCHAR_l, PCHAR_z, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_b, PCHAR_r, PCHAR_a, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	35, 650,//Height & weight
	str_pokedex_data_24_page_0, str_pokedex_data_24_page_1,
	0,//unused
	256, 0,//Pokemon scale, displacement
	296, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 25
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_u, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_u, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	4, 60,//Height & weight
	str_pokedex_data_25_page_0, str_pokedex_data_25_page_1,
	0,//unused
	479, 16,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 26
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_u, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_u, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 300,//Height & weight
	str_pokedex_data_26_page_0, str_pokedex_data_26_page_1,
	0,//unused
	426, 10,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 27
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_u, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_u, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 120,//Height & weight
	str_pokedex_data_27_page_0, str_pokedex_data_27_page_1,
	0,//unused
	370, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 28
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_u, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_u, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	10, 295,//Height & weight
	str_pokedex_data_28_page_0, str_pokedex_data_28_page_1,
	0,//unused
	341, 10,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 29
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_d, PCHAR_o, PCHAR_r, PCHAR_n, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_P, PCHAR_i, PCHAR_n, 0xff, 0x0})),
	4, 70,//Height & weight
	str_pokedex_data_29_page_0, str_pokedex_data_29_page_1,
	0,//unused
	488, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 30
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_d, PCHAR_o, PCHAR_r, PCHAR_n, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_P, PCHAR_i, PCHAR_n, 0xff, 0x0})),
	8, 200,//Height & weight
	str_pokedex_data_30_page_0, str_pokedex_data_30_page_1,
	0,//unused
	381, 13,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 31
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_o, PCHAR_h, PCHAR_r, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_i, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	13, 600,//Height & weight
	str_pokedex_data_31_page_0, str_pokedex_data_31_page_1,
	0,//unused
	283, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 32
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_d, PCHAR_o, PCHAR_r, PCHAR_n, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_P, PCHAR_i, PCHAR_n, 0xff, 0x0})),
	5, 90,//Height & weight
	str_pokedex_data_32_page_0, str_pokedex_data_32_page_1,
	0,//unused
	480, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 33
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_d, PCHAR_o, PCHAR_r, PCHAR_n, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_P, PCHAR_i, PCHAR_n, 0xff, 0x0})),
	9, 195,//Height & weight
	str_pokedex_data_33_page_0, str_pokedex_data_33_page_1,
	0,//unused
	408, 13,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 34
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_o, PCHAR_h, PCHAR_r, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_i, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	14, 620,//Height & weight
	str_pokedex_data_34_page_0, str_pokedex_data_34_page_1,
	0,//unused
	304, 3,//Pokemon scale, displacement
	323, 2,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 35
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_n, PCHAR_b, PCHAR_l, PCHAR_ue, PCHAR_t, PCHAR_l, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_a, PCHAR_i, PCHAR_r, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 75,//Height & weight
	str_pokedex_data_35_page_0, str_pokedex_data_35_page_1,
	0,//unused
	425, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 36
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_a, PCHAR_r, PCHAR_t, PCHAR_e, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_a, PCHAR_i, PCHAR_r, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	13, 400,//Height & weight
	str_pokedex_data_36_page_0, str_pokedex_data_36_page_1,
	0,//unused
	256, 3,//Pokemon scale, displacement
	272, 65535,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 37
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_o, PCHAR_x, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 99,//Height & weight
	str_pokedex_data_37_page_0, str_pokedex_data_37_page_1,
	0,//unused
	497, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 38
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_o, PCHAR_x, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	11, 199,//Height & weight
	str_pokedex_data_38_page_0, str_pokedex_data_38_page_1,
	0,//unused
	339, 6,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 39
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_o, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0})),
	5, 55,//Height & weight
	str_pokedex_data_39_page_0, str_pokedex_data_39_page_1,
	0,//unused
	419, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 40
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_o, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0})),
	10, 120,//Height & weight
	str_pokedex_data_40_page_0, str_pokedex_data_40_page_1,
	0,//unused
	328, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 41
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_e, PCHAR_d, PCHAR_e, PCHAR_r, PCHAR_m, PCHAR_a, PCHAR_u, PCHAR_s, 0xff, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 75,//Height & weight
	str_pokedex_data_41_page_0, str_pokedex_data_41_page_1,
	0,//unused
	355, 65532,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 42
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_e, PCHAR_d, PCHAR_e, PCHAR_r, PCHAR_m, PCHAR_a, PCHAR_u, PCHAR_s, 0xff, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	16, 550,//Height & weight
	str_pokedex_data_42_page_0, str_pokedex_data_42_page_1,
	0,//unused
	291, 0,//Pokemon scale, displacement
	296, 2,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 43
	PSTRING(P99_PROCTECT({PCHAR_U, PCHAR_n, PCHAR_k, PCHAR_r, PCHAR_a, PCHAR_u, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	5, 54,//Height & weight
	str_pokedex_data_43_page_0, str_pokedex_data_43_page_1,
	0,//unused
	423, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 44
	PSTRING(P99_PROCTECT({PCHAR_U, PCHAR_n, PCHAR_k, PCHAR_r, PCHAR_a, PCHAR_u, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 86,//Height & weight
	str_pokedex_data_44_page_0, str_pokedex_data_44_page_1,
	0,//unused
	329, 10,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 45
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_u, PCHAR_m, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_o, PCHAR_w, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	12, 186,//Height & weight
	str_pokedex_data_45_page_0, str_pokedex_data_45_page_1,
	0,//unused
	256, 4,//Pokemon scale, displacement
	272, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 46
	PSTRING(P99_PROCTECT({PCHAR_U, PCHAR_n, PCHAR_r, PCHAR_e, PCHAR_i, PCHAR_f, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_u, PCHAR_s, PCHAR_h, PCHAR_r, PCHAR_o, PCHAR_o, PCHAR_m, 0xff, 0x0, 0x0, 0x0})),
	3, 54,//Height & weight
	str_pokedex_data_46_page_0, str_pokedex_data_46_page_1,
	0,//unused
	546, 21,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 47
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_n, PCHAR_d, PCHAR_u, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_u, PCHAR_s, PCHAR_h, PCHAR_r, PCHAR_o, PCHAR_o, PCHAR_m, 0xff, 0x0, 0x0, 0x0})),
	10, 295,//Height & weight
	str_pokedex_data_47_page_0, str_pokedex_data_47_page_1,
	0,//unused
	307, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 48
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_l, PCHAR_e, PCHAR_b, PCHAR_e, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_I, PCHAR_n, PCHAR_s, PCHAR_e, PCHAR_c, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	10, 300,//Height & weight
	str_pokedex_data_48_page_0, str_pokedex_data_48_page_1,
	0,//unused
	360, 14,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 49
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_o, PCHAR_n, PCHAR_n, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_p, PCHAR_i, PCHAR_n, PCHAR_n, 0xff}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_M, PCHAR_o, PCHAR_t, PCHAR_h, 0xff})),
	15, 125,//Height & weight
	str_pokedex_data_49_page_0, str_pokedex_data_49_page_1,
	0,//unused
	256, 3,//Pokemon scale, displacement
	293, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 50
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_u, PCHAR_l, PCHAR_w, PCHAR_u, PCHAR_r, PCHAR_f, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	2, 8,//Height & weight
	str_pokedex_data_50_page_0, str_pokedex_data_50_page_1,
	0,//unused
	706, 22,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 51
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_u, PCHAR_l, PCHAR_w, PCHAR_u, PCHAR_r, PCHAR_f, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	7, 333,//Height & weight
	str_pokedex_data_51_page_0, str_pokedex_data_51_page_1,
	0,//unused
	384, 14,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 52
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_o, PCHAR_r, PCHAR_n, PCHAR_f, PCHAR_r, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_t, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_r, PCHAR_a, PCHAR_t, PCHAR_c, PCHAR_h, PCHAR_SPACE, PCHAR_C, PCHAR_a, PCHAR_t, 0xff})),
	4, 42,//Height & weight
	str_pokedex_data_52_page_0, str_pokedex_data_52_page_1,
	0,//unused
	480, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 53
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_o, PCHAR_r, PCHAR_n, PCHAR_k, PCHAR_u, PCHAR_g, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_l, PCHAR_a, PCHAR_s, PCHAR_s, PCHAR_y, PCHAR_SPACE, PCHAR_C, PCHAR_a, PCHAR_t, 0xff, 0x0})),
	10, 320,//Height & weight
	str_pokedex_data_53_page_0, str_pokedex_data_53_page_1,
	0,//unused
	320, 10,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 54
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_n, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_u, PCHAR_c, PCHAR_k, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 196,//Height & weight
	str_pokedex_data_54_page_0, str_pokedex_data_54_page_1,
	0,//unused
	347, 11,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 55
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_n, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_u, PCHAR_c, PCHAR_k, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	17, 766,//Height & weight
	str_pokedex_data_55_page_0, str_pokedex_data_55_page_1,
	0,//unused
	272, 4,//Pokemon scale, displacement
	287, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 56
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_DOT, PCHAR_SLASH, PCHAR_SPACE, PCHAR_A, PCHAR_f, PCHAR_f, PCHAR_e, 0xff}), P99_PROCTECT({PCHAR_P, PCHAR_i, PCHAR_g, PCHAR_SPACE, PCHAR_M, PCHAR_o, PCHAR_n, PCHAR_k, PCHAR_e, PCHAR_y, 0xff, 0x0})),
	5, 280,//Height & weight
	str_pokedex_data_56_page_0, str_pokedex_data_56_page_1,
	0,//unused
	388, 16,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 57
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_DOT, PCHAR_SLASH, PCHAR_SPACE, PCHAR_A, PCHAR_f, PCHAR_f, PCHAR_e, 0xff}), P99_PROCTECT({PCHAR_P, PCHAR_i, PCHAR_g, PCHAR_SPACE, PCHAR_M, PCHAR_o, PCHAR_n, PCHAR_k, PCHAR_e, PCHAR_y, 0xff, 0x0})),
	10, 320,//Height & weight
	str_pokedex_data_57_page_0, str_pokedex_data_57_page_1,
	0,//unused
	326, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 58
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_u, PCHAR_n, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_u, PCHAR_p, PCHAR_p, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	7, 190,//Height & weight
	str_pokedex_data_58_page_0, str_pokedex_data_58_page_1,
	0,//unused
	346, 14,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 59
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_e, PCHAR_g, PCHAR_e, PCHAR_n, PCHAR_d, PCHAR_ae, PCHAR_r, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_e, PCHAR_g, PCHAR_e, PCHAR_n, PCHAR_d, PCHAR_a, PCHAR_r, PCHAR_y, 0xff, 0x0, 0x0})),
	19, 1550,//Height & weight
	str_pokedex_data_59_page_0, str_pokedex_data_59_page_1,
	0,//unused
	256, 65535,//Pokemon scale, displacement
	312, 2,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 60
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_e, PCHAR_r, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_a, PCHAR_d, PCHAR_p, PCHAR_o, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0})),
	6, 124,//Height & weight
	str_pokedex_data_60_page_0, str_pokedex_data_60_page_1,
	0,//unused
	353, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 61
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_e, PCHAR_r, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_a, PCHAR_d, PCHAR_p, PCHAR_o, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0})),
	10, 200,//Height & weight
	str_pokedex_data_61_page_0, str_pokedex_data_61_page_1,
	0,//unused
	288, 10,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 62
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_oe, PCHAR_n, PCHAR_i, PCHAR_g, PCHAR_s, PCHAR_t, PCHAR_i, PCHAR_c, PCHAR_h, 0xff, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_a, PCHAR_d, PCHAR_p, PCHAR_o, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0})),
	13, 540,//Height & weight
	str_pokedex_data_62_page_0, str_pokedex_data_62_page_1,
	0,//unused
	256, 5,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 63
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_s, PCHAR_i, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_s, PCHAR_i, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	9, 195,//Height & weight
	str_pokedex_data_63_page_0, str_pokedex_data_63_page_1,
	0,//unused
	374, 14,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 64
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_s, PCHAR_i, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_s, PCHAR_i, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	13, 565,//Height & weight
	str_pokedex_data_64_page_0, str_pokedex_data_64_page_1,
	0,//unused
	272, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 65
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_s, PCHAR_i, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_s, PCHAR_i, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	15, 480,//Height & weight
	str_pokedex_data_65_page_0, str_pokedex_data_65_page_1,
	0,//unused
	272, 65535,//Pokemon scale, displacement
	271, 65535,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 66
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_a, PCHAR_f, PCHAR_t, PCHAR_p, PCHAR_r, PCHAR_o, PCHAR_t, PCHAR_z, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_u, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_p, PCHAR_o, PCHAR_w, PCHAR_e, PCHAR_r, 0xff, 0x0})),
	8, 195,//Height & weight
	str_pokedex_data_66_page_0, str_pokedex_data_66_page_1,
	0,//unused
	320, 12,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 67
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_a, PCHAR_f, PCHAR_t, PCHAR_p, PCHAR_r, PCHAR_o, PCHAR_t, PCHAR_z, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_u, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_p, PCHAR_o, PCHAR_w, PCHAR_e, PCHAR_r, 0xff, 0x0})),
	15, 705,//Height & weight
	str_pokedex_data_67_page_0, str_pokedex_data_67_page_1,
	0,//unused
	304, 6,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 68
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_a, PCHAR_f, PCHAR_t, PCHAR_p, PCHAR_r, PCHAR_o, PCHAR_t, PCHAR_z, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_u, PCHAR_p, PCHAR_e, PCHAR_r, PCHAR_p, PCHAR_o, PCHAR_w, PCHAR_e, PCHAR_r, 0xff, 0x0})),
	16, 1300,//Height & weight
	str_pokedex_data_68_page_0, str_pokedex_data_68_page_1,
	0,//unused
	278, 2,//Pokemon scale, displacement
	283, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 69
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_u, PCHAR_m, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_o, PCHAR_w, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	7, 40,//Height & weight
	str_pokedex_data_69_page_0, str_pokedex_data_69_page_1,
	0,//unused
	354, 16,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 70
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_i, PCHAR_e, PCHAR_g, PCHAR_e, PCHAR_n, PCHAR_t, PCHAR_o, PCHAR_t, 0xff, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_y, PCHAR_c, PCHAR_a, PCHAR_t, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0x0})),
	10, 64,//Height & weight
	str_pokedex_data_70_page_0, str_pokedex_data_70_page_1,
	0,//unused
	256, 65535,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 71
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_i, PCHAR_e, PCHAR_g, PCHAR_e, PCHAR_n, PCHAR_t, PCHAR_o, PCHAR_t, 0xff, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_y, PCHAR_c, PCHAR_a, PCHAR_t, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0x0})),
	17, 155,//Height & weight
	str_pokedex_data_71_page_0, str_pokedex_data_71_page_1,
	0,//unused
	256, 2,//Pokemon scale, displacement
	302, 2,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 72
	PSTRING(P99_PROCTECT({PCHAR_Q, PCHAR_u, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_J, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_y, PCHAR_f, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0})),
	9, 455,//Height & weight
	str_pokedex_data_72_page_0, str_pokedex_data_72_page_1,
	0,//unused
	256, 0,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 73
	PSTRING(P99_PROCTECT({PCHAR_Q, PCHAR_u, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_J, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_y, PCHAR_f, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0})),
	16, 550,//Height & weight
	str_pokedex_data_73_page_0, str_pokedex_data_73_page_1,
	0,//unused
	272, 65535,//Pokemon scale, displacement
	312, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 74
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_c, PCHAR_k, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	4, 200,//Height & weight
	str_pokedex_data_74_page_0, str_pokedex_data_74_page_1,
	0,//unused
	330, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 75
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_c, PCHAR_k, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	10, 1050,//Height & weight
	str_pokedex_data_75_page_0, str_pokedex_data_75_page_1,
	0,//unused
	272, 8,//Pokemon scale, displacement
	305, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 76
	PSTRING(P99_PROCTECT({PCHAR_U, PCHAR_r, PCHAR_g, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_g, PCHAR_a, PCHAR_t, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0})),
	14, 3000,//Height & weight
	str_pokedex_data_76_page_0, str_pokedex_data_76_page_1,
	0,//unused
	266, 3,//Pokemon scale, displacement
	298, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 77
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_u, PCHAR_e, PCHAR_r, PCHAR_p, PCHAR_f, PCHAR_e, PCHAR_r, PCHAR_d, 0xff, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_r, PCHAR_e, PCHAR_SPACE, PCHAR_H, PCHAR_o, PCHAR_r, PCHAR_s, PCHAR_e, 0xff, 0x0})),
	10, 300,//Height & weight
	str_pokedex_data_77_page_0, str_pokedex_data_77_page_1,
	0,//unused
	288, 7,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 78
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_u, PCHAR_e, PCHAR_r, PCHAR_p, PCHAR_f, PCHAR_e, PCHAR_r, PCHAR_d, 0xff, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_r, PCHAR_e, PCHAR_SPACE, PCHAR_H, PCHAR_o, PCHAR_r, PCHAR_s, PCHAR_e, 0xff, 0x0})),
	17, 950,//Height & weight
	str_pokedex_data_78_page_0, str_pokedex_data_78_page_1,
	0,//unused
	282, 65535,//Pokemon scale, displacement
	312, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 79
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_n, PCHAR_a, PCHAR_r, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_o, PCHAR_p, PCHAR_e, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	12, 360,//Height & weight
	str_pokedex_data_79_page_0, str_pokedex_data_79_page_1,
	0,//unused
	271, 10,//Pokemon scale, displacement
	272, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 80
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_y, PCHAR_m, PCHAR_b, PCHAR_i, PCHAR_o, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_e, PCHAR_r, PCHAR_m, PCHAR_i, PCHAR_t, PCHAR_SPACE, PCHAR_C, PCHAR_r, PCHAR_a, PCHAR_b, 0xff})),
	16, 785,//Height & weight
	str_pokedex_data_80_page_0, str_pokedex_data_80_page_1,
	0,//unused
	257, 65534,//Pokemon scale, displacement
	312, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 81
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_n, PCHAR_e, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_n, PCHAR_e, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	3, 60,//Height & weight
	str_pokedex_data_81_page_0, str_pokedex_data_81_page_1,
	0,//unused
	294, 65528,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 82
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_n, PCHAR_e, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_n, PCHAR_e, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	10, 600,//Height & weight
	str_pokedex_data_82_page_0, str_pokedex_data_82_page_1,
	0,//unused
	293, 65532,//Pokemon scale, displacement
	273, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 83
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_l, PCHAR_d, PCHAR_e, PCHAR_n, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_l, PCHAR_d, PCHAR_SPACE, PCHAR_D, PCHAR_u, PCHAR_c, PCHAR_k, 0xff, 0x0, 0x0})),
	8, 150,//Height & weight
	str_pokedex_data_83_page_0, str_pokedex_data_83_page_1,
	0,//unused
	317, 65534,//Pokemon scale, displacement
	256, 65533,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 84
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_u, PCHAR_o, PCHAR_v, PCHAR_o, PCHAR_g, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_w, PCHAR_i, PCHAR_n, PCHAR_SPACE, PCHAR_B, PCHAR_i, PCHAR_r, PCHAR_d, 0xff, 0x0, 0x0})),
	14, 392,//Height & weight
	str_pokedex_data_84_page_0, str_pokedex_data_84_page_1,
	0,//unused
	256, 3,//Pokemon scale, displacement
	287, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 85
	PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_i, PCHAR_v, PCHAR_o, PCHAR_g, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_i, PCHAR_p, PCHAR_l, PCHAR_e, PCHAR_SPACE, PCHAR_B, PCHAR_i, PCHAR_r, PCHAR_d, 0xff})),
	18, 852,//Height & weight
	str_pokedex_data_85_page_0, str_pokedex_data_85_page_1,
	0,//unused
	272, 65534,//Pokemon scale, displacement
	296, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 86
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_h, PCHAR_u, PCHAR_n, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_a, PCHAR_SPACE, PCHAR_L, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0})),
	11, 900,//Height & weight
	str_pokedex_data_86_page_0, str_pokedex_data_86_page_1,
	0,//unused
	298, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 87
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_h, PCHAR_u, PCHAR_n, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_a, PCHAR_SPACE, PCHAR_L, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0})),
	17, 1200,//Height & weight
	str_pokedex_data_87_page_0, str_pokedex_data_87_page_1,
	0,//unused
	288, 1,//Pokemon scale, displacement
	306, 65535,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 88
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_a, PCHAR_m, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_l, PCHAR_u, PCHAR_d, PCHAR_g, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	9, 300,//Height & weight
	str_pokedex_data_88_page_0, str_pokedex_data_88_page_1,
	0,//unused
	258, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 89
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_a, PCHAR_m, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_l, PCHAR_u, PCHAR_d, PCHAR_g, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	12, 300,//Height & weight
	str_pokedex_data_89_page_0, str_pokedex_data_89_page_1,
	0,//unused
	288, 7,//Pokemon scale, displacement
	288, 65535,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 90
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_u, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_v, PCHAR_a, PCHAR_l, PCHAR_v, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0})),
	3, 40,//Height & weight
	str_pokedex_data_90_page_0, str_pokedex_data_90_page_1,
	0,//unused
	643, 21,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 91
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_u, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_v, PCHAR_a, PCHAR_l, PCHAR_v, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0})),
	15, 1325,//Height & weight
	str_pokedex_data_91_page_0, str_pokedex_data_91_page_1,
	0,//unused
	264, 0,//Pokemon scale, displacement
	288, 65535,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 92
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_a, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_G, PCHAR_a, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	13, 1,//Height & weight
	str_pokedex_data_92_page_0, str_pokedex_data_92_page_1,
	0,//unused
	256, 0,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 93
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_a, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_G, PCHAR_a, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	16, 1,//Height & weight
	str_pokedex_data_93_page_0, str_pokedex_data_93_page_1,
	0,//unused
	269, 2,//Pokemon scale, displacement
	308, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 94
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_n, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_d, PCHAR_o, PCHAR_w, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	15, 405,//Height & weight
	str_pokedex_data_94_page_0, str_pokedex_data_94_page_1,
	0,//unused
	256, 4,//Pokemon scale, displacement
	317, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 95
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_l, PCHAR_s, PCHAR_n, PCHAR_a, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_c, PCHAR_k, PCHAR_SPACE, PCHAR_S, PCHAR_n, PCHAR_a, PCHAR_k, PCHAR_e, 0xff, 0x0})),
	88, 2100,//Height & weight
	str_pokedex_data_95_page_0, str_pokedex_data_95_page_1,
	0,//unused
	257, 0,//Pokemon scale, displacement
	515, 12,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 96
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_y, PCHAR_p, PCHAR_n, PCHAR_o, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_y, PCHAR_p, PCHAR_n, PCHAR_o, PCHAR_s, PCHAR_i, PCHAR_s, 0xff, 0x0, 0x0, 0x0})),
	10, 324,//Height & weight
	str_pokedex_data_96_page_0, str_pokedex_data_96_page_1,
	0,//unused
	274, 7,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 97
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_y, PCHAR_p, PCHAR_n, PCHAR_o, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_y, PCHAR_p, PCHAR_n, PCHAR_o, PCHAR_s, PCHAR_i, PCHAR_s, 0xff, 0x0, 0x0, 0x0})),
	16, 756,//Height & weight
	str_pokedex_data_97_page_0, str_pokedex_data_97_page_1,
	0,//unused
	298, 3,//Pokemon scale, displacement
	310, 2,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 98
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_a, PCHAR_b, PCHAR_b, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_i, PCHAR_v, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_C, PCHAR_r, PCHAR_a, PCHAR_b, 0xff, 0x0})),
	4, 65,//Height & weight
	str_pokedex_data_98_page_0, str_pokedex_data_98_page_1,
	0,//unused
	469, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 99
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_n, PCHAR_e, PCHAR_i, PCHAR_f, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_i, PCHAR_n, PCHAR_c, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	13, 600,//Height & weight
	str_pokedex_data_99_page_0, str_pokedex_data_99_page_1,
	0,//unused
	287, 3,//Pokemon scale, displacement
	308, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 100
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	5, 104,//Height & weight
	str_pokedex_data_100_page_0, str_pokedex_data_100_page_1,
	0,//unused
	364, 65528,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 101
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	12, 666,//Height & weight
	str_pokedex_data_101_page_0, str_pokedex_data_101_page_1,
	0,//unused
	256, 0,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 102
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_g, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	4, 25,//Height & weight
	str_pokedex_data_102_page_0, str_pokedex_data_102_page_1,
	0,//unused
	495, 65532,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 103
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_a, PCHAR_l, PCHAR_m, PCHAR_f, PCHAR_r, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_t, 0xff, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_c, PCHAR_o, PCHAR_n, PCHAR_u, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0})),
	20, 1200,//Height & weight
	str_pokedex_data_103_page_0, str_pokedex_data_103_page_1,
	0,//unused
	283, 0,//Pokemon scale, displacement
	376, 7,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 104
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_n, PCHAR_s, PCHAR_a, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_o, PCHAR_n, PCHAR_e, PCHAR_l, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	4, 65,//Height & weight
	str_pokedex_data_104_page_0, str_pokedex_data_104_page_1,
	0,//unused
	545, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 105
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_n, PCHAR_o, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_n, PCHAR_f, PCHAR_a, PCHAR_n, 0xff, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_o, PCHAR_n, PCHAR_e, PCHAR_SPACE, PCHAR_K, PCHAR_e, PCHAR_e, PCHAR_p, PCHAR_e, PCHAR_r, 0xff})),
	10, 450,//Height & weight
	str_pokedex_data_105_page_0, str_pokedex_data_105_page_1,
	0,//unused
	293, 12,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 106
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_K, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0})),
	15, 498,//Height & weight
	str_pokedex_data_106_page_0, str_pokedex_data_106_page_1,
	0,//unused
	256, 0,//Pokemon scale, displacement
	273, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 107
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_u, PCHAR_n, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_u, PCHAR_n, PCHAR_c, PCHAR_h, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0})),
	14, 502,//Height & weight
	str_pokedex_data_107_page_0, str_pokedex_data_107_page_1,
	0,//unused
	256, 1,//Pokemon scale, displacement
	264, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 108
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_e, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0})),
	12, 655,//Height & weight
	str_pokedex_data_108_page_0, str_pokedex_data_108_page_1,
	0,//unused
	272, 3,//Pokemon scale, displacement
	272, 65533,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 109
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_w, PCHAR_o, PCHAR_l, PCHAR_k, PCHAR_e, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_G, PCHAR_a, PCHAR_s, 0xff, 0x0})),
	6, 10,//Height & weight
	str_pokedex_data_109_page_0, str_pokedex_data_109_page_1,
	0,//unused
	369, 65535,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 110
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_w, PCHAR_o, PCHAR_l, PCHAR_k, PCHAR_e, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_G, PCHAR_a, PCHAR_s, 0xff, 0x0})),
	12, 95,//Height & weight
	str_pokedex_data_110_page_0, str_pokedex_data_110_page_1,
	0,//unused
	321, 65535,//Pokemon scale, displacement
	276, 65535,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 111
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_i, PCHAR_k, PCHAR_e, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	10, 1150,//Height & weight
	str_pokedex_data_111_page_0, str_pokedex_data_111_page_1,
	0,//unused
	291, 7,//Pokemon scale, displacement
	276, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 112
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_o, PCHAR_h, PCHAR_r, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_i, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	19, 1200,//Height & weight
	str_pokedex_data_112_page_0, str_pokedex_data_112_page_1,
	0,//unused
	272, 65535,//Pokemon scale, displacement
	344, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 113
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_g, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	11, 346,//Height & weight
	str_pokedex_data_113_page_0, str_pokedex_data_113_page_1,
	0,//unused
	257, 6,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 114
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_n, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_n, PCHAR_i, PCHAR_s, 0xff, 0x0}), P99_PROCTECT({PCHAR_V, PCHAR_i, PCHAR_n, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	5, 110,//Height & weight
	str_pokedex_data_114_page_0, str_pokedex_data_114_page_1,
	0,//unused
	451, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 115
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_u, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_t, PCHAR_i, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_a, PCHAR_r, PCHAR_e, PCHAR_n, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	22, 800,//Height & weight
	str_pokedex_data_115_page_0, str_pokedex_data_115_page_1,
	0,//unused
	257, 65533,//Pokemon scale, displacement
	349, 5,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 116
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	4, 80,//Height & weight
	str_pokedex_data_116_page_0, str_pokedex_data_116_page_1,
	0,//unused
	399, 65535,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 117
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	12, 250,//Height & weight
	str_pokedex_data_117_page_0, str_pokedex_data_117_page_1,
	0,//unused
	296, 3,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 118
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_l, PCHAR_e, PCHAR_i, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_G, PCHAR_o, PCHAR_l, PCHAR_d, PCHAR_f, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0, 0x0})),
	6, 150,//Height & weight
	str_pokedex_data_118_page_0, str_pokedex_data_118_page_1,
	0,//unused
	379, 4,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 119
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_l, PCHAR_e, PCHAR_i, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_G, PCHAR_o, PCHAR_l, PCHAR_d, PCHAR_f, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0, 0x0})),
	13, 390,//Height & weight
	str_pokedex_data_119_page_0, str_pokedex_data_119_page_1,
	0,//unused
	304, 1,//Pokemon scale, displacement
	288, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 120
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_n, PCHAR_f, PCHAR_o, PCHAR_r, PCHAR_m, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_r, PCHAR_SPACE, PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_p, PCHAR_e, 0xff, 0x0})),
	8, 345,//Height & weight
	str_pokedex_data_120_page_0, str_pokedex_data_120_page_1,
	0,//unused
	326, 1,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 121
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_y, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_i, PCHAR_oe, PCHAR_s, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_y, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_i, PCHAR_o, PCHAR_u, PCHAR_s, 0xff, 0x0})),
	11, 800,//Height & weight
	str_pokedex_data_121_page_0, str_pokedex_data_121_page_1,
	0,//unused
	301, 3,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 122
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_e, PCHAR_i, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_r, PCHAR_r, PCHAR_i, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0})),
	7, 10,//Height & weight
	str_pokedex_data_122_page_0, str_pokedex_data_122_page_1,
	0,//unused
	407, 65528,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 123
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_n, PCHAR_t, PCHAR_i, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_n, PCHAR_t, PCHAR_i, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	15, 560,//Height & weight
	str_pokedex_data_123_page_0, str_pokedex_data_123_page_1,
	0,//unused
	272, 0,//Pokemon scale, displacement
	293, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 124
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_l, PCHAR_i, PCHAR_n, PCHAR_g, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_u, PCHAR_m, PCHAR_a, PCHAR_n, PCHAR_SPACE, PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_p, PCHAR_e, 0xff})),
	14, 406,//Height & weight
	str_pokedex_data_124_page_0, str_pokedex_data_124_page_1,
	0,//unused
	256, 3,//Pokemon scale, displacement
	300, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 125
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_l, PCHAR_e, PCHAR_k, PCHAR_t, PCHAR_r, PCHAR_o, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_l, PCHAR_e, PCHAR_c, PCHAR_t, PCHAR_r, PCHAR_i, PCHAR_c, 0xff, 0x0, 0x0, 0x0})),
	11, 300,//Height & weight
	str_pokedex_data_125_page_0, str_pokedex_data_125_page_1,
	0,//unused
	330, 7,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 126
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_r, PCHAR_e, PCHAR_n, PCHAR_n, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_i, PCHAR_t, PCHAR_f, PCHAR_i, PCHAR_r, PCHAR_e, 0xff, 0x0, 0x0, 0x0})),
	13, 445,//Height & weight
	str_pokedex_data_126_page_0, str_pokedex_data_126_page_1,
	0,//unused
	293, 4,//Pokemon scale, displacement
	272, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 127
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_n, PCHAR_e, PCHAR_i, PCHAR_f, PCHAR_k, PCHAR_ae, PCHAR_f, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_g, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_e, PCHAR_t, PCHAR_l, PCHAR_e, 0xff})),
	15, 550,//Height & weight
	str_pokedex_data_127_page_0, str_pokedex_data_127_page_1,
	0,//unused
	256, 1,//Pokemon scale, displacement
	257, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 128
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_l, PCHAR_d, PCHAR_b, PCHAR_u, PCHAR_l, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_l, PCHAR_d, PCHAR_SPACE, PCHAR_B, PCHAR_u, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0})),
	14, 884,//Height & weight
	str_pokedex_data_128_page_0, str_pokedex_data_128_page_1,
	0,//unused
	256, 2,//Pokemon scale, displacement
	312, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 129
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_s, PCHAR_c, PCHAR_h, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	9, 100,//Height & weight
	str_pokedex_data_129_page_0, str_pokedex_data_129_page_1,
	0,//unused
	317, 4,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 130
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_r, PCHAR_a, PCHAR_u, PCHAR_s, PCHAR_a, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_A, PCHAR_t, PCHAR_r, PCHAR_o, PCHAR_c, PCHAR_i, PCHAR_o, PCHAR_u, PCHAR_s, 0xff, 0x0, 0x0})),
	65, 2350,//Height & weight
	str_pokedex_data_130_page_0, str_pokedex_data_130_page_1,
	0,//unused
	288, 65535,//Pokemon scale, displacement
	512, 11,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 131
	PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_s, PCHAR_p, PCHAR_o, PCHAR_r, PCHAR_t, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_s, PCHAR_p, PCHAR_o, PCHAR_r, PCHAR_t, 0xff, 0x0, 0x0})),
	25, 2200,//Height & weight
	str_pokedex_data_131_page_0, str_pokedex_data_131_page_1,
	0,//unused
	256, 0,//Pokemon scale, displacement
	425, 8,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 132
	PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_s, PCHAR_f, PCHAR_o, PCHAR_r, PCHAR_m, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_s, PCHAR_f, PCHAR_o, PCHAR_r, PCHAR_m, 0xff, 0x0, 0x0})),
	3, 40,//Height & weight
	str_pokedex_data_132_page_0, str_pokedex_data_132_page_1,
	0,//unused
	602, 21,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 133
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_v, PCHAR_o, PCHAR_l, PCHAR_u, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_v, PCHAR_o, PCHAR_l, PCHAR_u, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0})),
	3, 65,//Height & weight
	str_pokedex_data_133_page_0, str_pokedex_data_133_page_1,
	0,//unused
	476, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 134
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_u, PCHAR_b, PCHAR_b, PCHAR_l, PCHAR_a, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_u, PCHAR_b, PCHAR_b, PCHAR_l, PCHAR_e, PCHAR_SPACE, PCHAR_J, PCHAR_e, PCHAR_t, 0xff, 0x0})),
	10, 290,//Height & weight
	str_pokedex_data_134_page_0, str_pokedex_data_134_page_1,
	0,//unused
	316, 7,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 135
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_i, PCHAR_t, PCHAR_z, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_g, PCHAR_h, PCHAR_t, PCHAR_n, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0})),
	8, 245,//Height & weight
	str_pokedex_data_135_page_0, str_pokedex_data_135_page_1,
	0,//unused
	283, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 136
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_u, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_a, PCHAR_m, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	9, 250,//Height & weight
	str_pokedex_data_136_page_0, str_pokedex_data_136_page_1,
	0,//unused
	302, 11,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 137
	PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_i, PCHAR_r, PCHAR_t, PCHAR_u, PCHAR_e, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_V, PCHAR_i, PCHAR_r, PCHAR_t, PCHAR_u, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0})),
	8, 365,//Height & weight
	str_pokedex_data_137_page_0, str_pokedex_data_137_page_1,
	0,//unused
	328, 7,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 138
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_i, PCHAR_r, PCHAR_a, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_i, PCHAR_r, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	4, 75,//Height & weight
	str_pokedex_data_138_page_0, str_pokedex_data_138_page_1,
	0,//unused
	521, 20,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 139
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_i, PCHAR_r, PCHAR_a, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_i, PCHAR_r, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	10, 350,//Height & weight
	str_pokedex_data_139_page_0, str_pokedex_data_139_page_1,
	0,//unused
	307, 5,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 140
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_a, PCHAR_n, PCHAR_z, PCHAR_e, PCHAR_r, PCHAR_t, PCHAR_i, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_h, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_f, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0})),
	5, 115,//Height & weight
	str_pokedex_data_140_page_0, str_pokedex_data_140_page_1,
	0,//unused
	438, 21,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 141
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_a, PCHAR_n, PCHAR_z, PCHAR_e, PCHAR_r, PCHAR_t, PCHAR_i, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_h, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_f, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0})),
	13, 405,//Height & weight
	str_pokedex_data_141_page_0, str_pokedex_data_141_page_1,
	0,//unused
	271, 1,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 142
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	18, 590,//Height & weight
	str_pokedex_data_142_page_0, str_pokedex_data_142_page_1,
	0,//unused
	275, 65535,//Pokemon scale, displacement
	317, 2,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 143
	PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_a, PCHAR_g, PCHAR_t, PCHAR_r, PCHAR_ae, PCHAR_u, PCHAR_m, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_l, PCHAR_e, PCHAR_e, PCHAR_p, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0})),
	21, 4600,//Height & weight
	str_pokedex_data_143_page_0, str_pokedex_data_143_page_1,
	0,//unused
	275, 1,//Pokemon scale, displacement
	408, 7,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 144
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_r, PCHAR_e, PCHAR_e, PCHAR_z, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	17, 554,//Height & weight
	str_pokedex_data_144_page_0, str_pokedex_data_144_page_1,
	0,//unused
	278, 0,//Pokemon scale, displacement
	308, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 145
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_l, PCHAR_e, PCHAR_k, PCHAR_t, PCHAR_r, PCHAR_o, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_l, PCHAR_e, PCHAR_c, PCHAR_t, PCHAR_r, PCHAR_i, PCHAR_c, 0xff, 0x0, 0x0, 0x0})),
	16, 526,//Height & weight
	str_pokedex_data_145_page_0, str_pokedex_data_145_page_1,
	0,//unused
	275, 1,//Pokemon scale, displacement
	330, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 146
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_a, PCHAR_m, PCHAR_m, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_a, PCHAR_m, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	20, 600,//Height & weight
	str_pokedex_data_146_page_0, str_pokedex_data_146_page_1,
	0,//unused
	270, 1,//Pokemon scale, displacement
	379, 6,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 147
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	18, 33,//Height & weight
	str_pokedex_data_147_page_0, str_pokedex_data_147_page_1,
	0,//unused
	256, 8,//Pokemon scale, displacement
	386, 6,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 148
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	40, 165,//Height & weight
	str_pokedex_data_148_page_0, str_pokedex_data_148_page_1,
	0,//unused
	274, 0,//Pokemon scale, displacement
	423, 6,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 149
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	22, 2100,//Height & weight
	str_pokedex_data_149_page_0, str_pokedex_data_149_page_1,
	0,//unused
	283, 65535,//Pokemon scale, displacement
	342, 4,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 150
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_n, PCHAR_m, PCHAR_u, PCHAR_t, PCHAR_a, PCHAR_n, PCHAR_t, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_n, PCHAR_e, PCHAR_t, PCHAR_i, PCHAR_c, 0xff, 0x0, 0x0, 0x0, 0x0})),
	20, 1220,//Height & weight
	str_pokedex_data_150_page_0, str_pokedex_data_150_page_1,
	0,//unused
	276, 65535,//Pokemon scale, displacement
	342, 5,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 151
	PSTRING(P99_PROCTECT({PCHAR_N, PCHAR_e, PCHAR_u, PCHAR_e, PCHAR_SPACE, PCHAR_A, PCHAR_r, PCHAR_t, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_N, PCHAR_e, PCHAR_w, PCHAR_SPACE, PCHAR_S, PCHAR_p, PCHAR_e, PCHAR_c, PCHAR_i, PCHAR_e, PCHAR_s, 0xff})),
	4, 40,//Height & weight
	str_pokedex_data_151_page_0, str_pokedex_data_151_page_1,
	0,//unused
	460, 65534,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 152
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_u, PCHAR_b, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_e, PCHAR_a, PCHAR_f, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	9, 64,//Height & weight
	str_pokedex_data_152_page_0, str_pokedex_data_152_page_1,
	0,//unused
	512, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 153
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_u, PCHAR_b, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_e, PCHAR_a, PCHAR_f, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	12, 158,//Height & weight
	str_pokedex_data_153_page_0, str_pokedex_data_153_page_1,
	0,//unused
	296, 4,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 154
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_ae, PCHAR_u, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_e, PCHAR_r, PCHAR_b, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	18, 1005,//Height & weight
	str_pokedex_data_154_page_0, str_pokedex_data_154_page_1,
	0,//unused
	286, 0,//Pokemon scale, displacement
	317, 2,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 155
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_u, PCHAR_e, PCHAR_r, PCHAR_m, PCHAR_a, PCHAR_u, PCHAR_s, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_r, PCHAR_e, PCHAR_SPACE, PCHAR_M, PCHAR_o, PCHAR_u, PCHAR_s, PCHAR_e, 0xff, 0x0})),
	5, 79,//Height & weight
	str_pokedex_data_155_page_0, str_pokedex_data_155_page_1,
	0,//unused
	539, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 156
	PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_u, PCHAR_l, PCHAR_k, PCHAR_a, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_V, PCHAR_o, PCHAR_l, PCHAR_c, PCHAR_a, PCHAR_n, PCHAR_o, 0xff, 0x0, 0x0, 0x0, 0x0})),
	9, 190,//Height & weight
	str_pokedex_data_156_page_0, str_pokedex_data_156_page_1,
	0,//unused
	329, 10,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 157
	PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_u, PCHAR_l, PCHAR_k, PCHAR_a, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_V, PCHAR_o, PCHAR_l, PCHAR_c, PCHAR_a, PCHAR_n, PCHAR_o, 0xff, 0x0, 0x0, 0x0, 0x0})),
	17, 795,//Height & weight
	str_pokedex_data_157_page_0, str_pokedex_data_157_page_1,
	0,//unused
	284, 65535,//Pokemon scale, displacement
	287, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 158
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_r, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_m, PCHAR_a, PCHAR_u, PCHAR_l, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_g, PCHAR_SPACE, PCHAR_J, PCHAR_a, PCHAR_w, 0xff, 0x0, 0x0, 0x0, 0x0})),
	6, 95,//Height & weight
	str_pokedex_data_158_page_0, str_pokedex_data_158_page_1,
	0,//unused
	487, 20,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 159
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_r, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_m, PCHAR_a, PCHAR_u, PCHAR_l, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_g, PCHAR_SPACE, PCHAR_J, PCHAR_a, PCHAR_w, 0xff, 0x0, 0x0, 0x0, 0x0})),
	11, 250,//Height & weight
	str_pokedex_data_159_page_0, str_pokedex_data_159_page_1,
	0,//unused
	378, 11,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 160
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_r, PCHAR_o, PCHAR_s, PCHAR_s, PCHAR_m, PCHAR_a, PCHAR_u, PCHAR_l, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_g, PCHAR_SPACE, PCHAR_J, PCHAR_a, PCHAR_w, 0xff, 0x0, 0x0, 0x0, 0x0})),
	23, 888,//Height & weight
	str_pokedex_data_160_page_0, str_pokedex_data_160_page_1,
	0,//unused
	282, 65535,//Pokemon scale, displacement
	375, 6,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 161
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_a, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_o, PCHAR_u, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 60,//Height & weight
	str_pokedex_data_161_page_0, str_pokedex_data_161_page_1,
	0,//unused
	439, 12,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 162
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_o, PCHAR_n, PCHAR_n, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_o, PCHAR_n, PCHAR_g, PCHAR_SPACE, PCHAR_B, PCHAR_o, PCHAR_d, PCHAR_y, 0xff, 0x0, 0x0})),
	18, 325,//Height & weight
	str_pokedex_data_162_page_0, str_pokedex_data_162_page_1,
	0,//unused
	346, 10,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 163
	PSTRING(P99_PROCTECT({PCHAR_N, PCHAR_e, PCHAR_u, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_n, PCHAR_e, PCHAR_e, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_O, PCHAR_w, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	7, 212,//Height & weight
	str_pokedex_data_163_page_0, str_pokedex_data_163_page_1,
	0,//unused
	380, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 164
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_r, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_l, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_O, PCHAR_w, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	16, 408,//Height & weight
	str_pokedex_data_164_page_0, str_pokedex_data_164_page_1,
	0,//unused
	278, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 165
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_ue, PCHAR_n, PCHAR_f, PCHAR_MINUS, PCHAR_P, PCHAR_u, PCHAR_n, PCHAR_k, PCHAR_t, 0xff, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_v, PCHAR_e, PCHAR_SPACE, PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_r, 0xff, 0x0, 0x0})),
	10, 108,//Height & weight
	str_pokedex_data_165_page_0, str_pokedex_data_165_page_1,
	0,//unused
	256, 4,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 166
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_ue, PCHAR_n, PCHAR_f, PCHAR_MINUS, PCHAR_P, PCHAR_u, PCHAR_n, PCHAR_k, PCHAR_t, 0xff, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_v, PCHAR_e, PCHAR_SPACE, PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_r, 0xff, 0x0, 0x0})),
	14, 356,//Height & weight
	str_pokedex_data_166_page_0, str_pokedex_data_166_page_1,
	0,//unused
	256, 1,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 167
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_a, PCHAR_d, PCHAR_e, PCHAR_n, PCHAR_w, PCHAR_u, PCHAR_r, PCHAR_f, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_r, PCHAR_i, PCHAR_n, PCHAR_g, PCHAR_SPACE, PCHAR_S, PCHAR_p, PCHAR_i, PCHAR_t, 0xff})),
	5, 85,//Height & weight
	str_pokedex_data_167_page_0, str_pokedex_data_167_page_1,
	0,//unused
	414, 20,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 168
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_b, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_o, PCHAR_n, PCHAR_g, PCHAR_SPACE, PCHAR_L, PCHAR_e, PCHAR_g, 0xff, 0x0, 0x0, 0x0})),
	11, 335,//Height & weight
	str_pokedex_data_168_page_0, str_pokedex_data_168_page_1,
	0,//unused
	316, 7,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 169
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_e, PCHAR_d, PCHAR_e, PCHAR_r, PCHAR_m, PCHAR_a, PCHAR_u, PCHAR_s, 0xff, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	18, 750,//Height & weight
	str_pokedex_data_169_page_0, str_pokedex_data_169_page_1,
	0,//unused
	279, 65535,//Pokemon scale, displacement
	313, 2,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 170
	PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_n, PCHAR_g, PCHAR_l, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_A, PCHAR_n, PCHAR_g, PCHAR_l, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	5, 120,//Height & weight
	str_pokedex_data_170_page_0, str_pokedex_data_170_page_1,
	0,//unused
	424, 65534,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 171
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_e, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_g, PCHAR_h, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	12, 225,//Height & weight
	str_pokedex_data_171_page_0, str_pokedex_data_171_page_1,
	0,//unused
	269, 6,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 172
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_n, PCHAR_e, PCHAR_t, PCHAR_g, PCHAR_e, PCHAR_b, PCHAR_i, PCHAR_e, 0xff}), P99_PROCTECT({PCHAR_T, PCHAR_i, PCHAR_n, PCHAR_y, PCHAR_SPACE, PCHAR_M, PCHAR_o, PCHAR_u, PCHAR_s, PCHAR_e, 0xff, 0x0})),
	3, 20,//Height & weight
	str_pokedex_data_172_page_0, str_pokedex_data_172_page_1,
	0,//unused
	508, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 173
	PSTRING(P99_PROCTECT({PCHAR_J, PCHAR_u, PCHAR_b, PCHAR_i, PCHAR_l, PCHAR_i, PCHAR_e, PCHAR_r, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_r, PCHAR_SPACE, PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_p, PCHAR_e, 0xff, 0x0})),
	3, 30,//Height & weight
	str_pokedex_data_173_page_0, str_pokedex_data_173_page_1,
	0,//unused
	462, 22,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 174
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_n, PCHAR_b, PCHAR_l, PCHAR_ue, PCHAR_t, PCHAR_l, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_o, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0})),
	3, 10,//Height & weight
	str_pokedex_data_174_page_0, str_pokedex_data_174_page_1,
	0,//unused
	457, 65535,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 175
	PSTRING(P99_PROCTECT({PCHAR_Z, PCHAR_a, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_n, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_i, PCHAR_k, PCHAR_e, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0x0})),
	3, 15,//Height & weight
	str_pokedex_data_175_page_0, str_pokedex_data_175_page_1,
	0,//unused
	507, 21,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 176
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_r, PCHAR_e, PCHAR_u, PCHAR_d, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_a, PCHAR_p, PCHAR_p, PCHAR_i, PCHAR_n, PCHAR_e, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0})),
	6, 32,//Height & weight
	str_pokedex_data_176_page_0, str_pokedex_data_176_page_1,
	0,//unused
	424, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 177
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_l, PCHAR_e, PCHAR_i, PCHAR_n, PCHAR_v, PCHAR_o, PCHAR_g, PCHAR_e, PCHAR_l, 0xff, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_i, PCHAR_n, PCHAR_y, PCHAR_SPACE, PCHAR_B, PCHAR_i, PCHAR_r, PCHAR_d, 0xff, 0x0, 0x0})),
	2, 20,//Height & weight
	str_pokedex_data_177_page_0, str_pokedex_data_177_page_1,
	0,//unused
	610, 23,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 178
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_y, PCHAR_s, PCHAR_t, PCHAR_i, PCHAR_k, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_y, PCHAR_s, PCHAR_t, PCHAR_i, PCHAR_c, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	15, 150,//Height & weight
	str_pokedex_data_178_page_0, str_pokedex_data_178_page_1,
	0,//unused
	258, 4,//Pokemon scale, displacement
	317, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 179
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_o, PCHAR_l, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_o, PCHAR_o, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 78,//Height & weight
	str_pokedex_data_179_page_0, str_pokedex_data_179_page_1,
	0,//unused
	379, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 180
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_o, PCHAR_l, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_o, PCHAR_o, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 133,//Height & weight
	str_pokedex_data_180_page_0, str_pokedex_data_180_page_1,
	0,//unused
	372, 13,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 181
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_e, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_g, PCHAR_h, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	14, 615,//Height & weight
	str_pokedex_data_181_page_0, str_pokedex_data_181_page_1,
	0,//unused
	275, 2,//Pokemon scale, displacement
	283, 65535,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 182
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_u, PCHAR_m, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_o, PCHAR_w, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	4, 58,//Height & weight
	str_pokedex_data_182_page_0, str_pokedex_data_182_page_1,
	0,//unused
	472, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 183
	PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_q, PCHAR_u, PCHAR_a, PCHAR_m, PCHAR_a, PCHAR_u, PCHAR_s, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_A, PCHAR_q, PCHAR_u, PCHAR_a, PCHAR_SPACE, PCHAR_M, PCHAR_o, PCHAR_u, PCHAR_s, PCHAR_e, 0xff, 0x0})),
	4, 85,//Height & weight
	str_pokedex_data_183_page_0, str_pokedex_data_183_page_1,
	0,//unused
	476, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 184
	PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_q, PCHAR_u, PCHAR_a, PCHAR_h, PCHAR_a, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_A, PCHAR_q, PCHAR_u, PCHAR_a, PCHAR_SPACE, PCHAR_R, PCHAR_a, PCHAR_b, PCHAR_b, PCHAR_i, PCHAR_t, 0xff})),
	8, 285,//Height & weight
	str_pokedex_data_184_page_0, str_pokedex_data_184_page_1,
	0,//unused
	448, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 185
	PSTRING(P99_PROCTECT({PCHAR_I, PCHAR_m, PCHAR_i, PCHAR_t, PCHAR_a, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_I, PCHAR_m, PCHAR_i, PCHAR_t, PCHAR_a, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0})),
	12, 380,//Height & weight
	str_pokedex_data_185_page_0, str_pokedex_data_185_page_1,
	0,//unused
	305, 7,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 186
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_ue, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_r, PCHAR_o, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	11, 339,//Height & weight
	str_pokedex_data_186_page_0, str_pokedex_data_186_page_1,
	0,//unused
	289, 5,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 187
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_e, PCHAR_r, PCHAR_z, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_t, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_w, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0x0})),
	4, 5,//Height & weight
	str_pokedex_data_187_page_0, str_pokedex_data_187_page_1,
	0,//unused
	562, 65529,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 188
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_m, PCHAR_p, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_t, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_w, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0x0})),
	6, 10,//Height & weight
	str_pokedex_data_188_page_0, str_pokedex_data_188_page_1,
	0,//unused
	387, 0,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 189
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_l, PCHAR_e, PCHAR_i, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_t, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_w, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0x0})),
	8, 30,//Height & weight
	str_pokedex_data_189_page_0, str_pokedex_data_189_page_1,
	0,//unused
	418, 65532,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 190
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_e, PCHAR_i, PCHAR_f, 0xff}), P99_PROCTECT({PCHAR_L, PCHAR_o, PCHAR_n, PCHAR_g, PCHAR_SPACE, PCHAR_T, PCHAR_a, PCHAR_i, PCHAR_l, 0xff, 0x0, 0x0})),
	8, 115,//Height & weight
	str_pokedex_data_190_page_0, str_pokedex_data_190_page_1,
	0,//unused
	363, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 191
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_r, PCHAR_o, PCHAR_s, PCHAR_t, PCHAR_b, PCHAR_a, PCHAR_u, PCHAR_m, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	3, 18,//Height & weight
	str_pokedex_data_191_page_0, str_pokedex_data_191_page_1,
	0,//unused
	541, 0,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 192
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_r, PCHAR_o, PCHAR_s, PCHAR_t, PCHAR_b, PCHAR_a, PCHAR_u, PCHAR_m, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_u, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 85,//Height & weight
	str_pokedex_data_192_page_0, str_pokedex_data_192_page_1,
	0,//unused
	374, 12,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 193
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_b, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_l, PCHAR_e, PCHAR_a, PCHAR_r, PCHAR_SPACE, PCHAR_W, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0})),
	12, 380,//Height & weight
	str_pokedex_data_193_page_0, str_pokedex_data_193_page_1,
	0,//unused
	274, 65532,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 194
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_s, PCHAR_c, PCHAR_h, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_F, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0})),
	4, 85,//Height & weight
	str_pokedex_data_194_page_0, str_pokedex_data_194_page_1,
	0,//unused
	479, 20,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 195
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_s, PCHAR_c, PCHAR_h, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_F, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0})),
	14, 750,//Height & weight
	str_pokedex_data_195_page_0, str_pokedex_data_195_page_1,
	0,//unused
	273, 4,//Pokemon scale, displacement
	273, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 196
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_o, PCHAR_n, PCHAR_n, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_u, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	9, 265,//Height & weight
	str_pokedex_data_196_page_0, str_pokedex_data_196_page_1,
	0,//unused
	363, 12,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 197
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_n, PCHAR_d, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_o, PCHAR_n, PCHAR_l, PCHAR_i, PCHAR_g, PCHAR_h, PCHAR_t, 0xff, 0x0, 0x0})),
	10, 270,//Height & weight
	str_pokedex_data_197_page_0, str_pokedex_data_197_page_1,
	0,//unused
	317, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 198
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_n, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_n, PCHAR_i, PCHAR_s, 0xff, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_a, PCHAR_r, PCHAR_k, PCHAR_n, PCHAR_e, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0, 0x0})),
	5, 21,//Height & weight
	str_pokedex_data_198_page_0, str_pokedex_data_198_page_1,
	0,//unused
	401, 65528,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 199
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_n, PCHAR_a, PCHAR_r, PCHAR_c, PCHAR_h, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_y, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	20, 795,//Height & weight
	str_pokedex_data_199_page_0, str_pokedex_data_199_page_1,
	0,//unused
	265, 65535,//Pokemon scale, displacement
	330, 4,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 200
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_e, PCHAR_i, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_r, PCHAR_e, PCHAR_e, PCHAR_c, PCHAR_h, 0xff, 0x0, 0x0, 0x0, 0x0})),
	7, 10,//Height & weight
	str_pokedex_data_200_page_0, str_pokedex_data_200_page_1,
	0,//unused
	407, 65528,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 201
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_y, PCHAR_m, PCHAR_b, PCHAR_o, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_y, PCHAR_m, PCHAR_b, PCHAR_o, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	5, 50,//Height & weight
	str_pokedex_data_201_page_0, str_pokedex_data_201_page_1,
	0,//unused
	411, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 202
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_n, PCHAR_e, PCHAR_e, PCHAR_g, PCHAR_e, PCHAR_b, PCHAR_i, PCHAR_e, 0xff}), P99_PROCTECT({PCHAR_P, PCHAR_a, PCHAR_t, PCHAR_i, PCHAR_e, PCHAR_n, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0})),
	68, 285,//Height & weight
	str_pokedex_data_202_page_0, str_pokedex_data_202_page_1,
	0,//unused
	517, 4,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 203
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_h, PCHAR_a, PCHAR_l, PCHAR_s, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_o, PCHAR_n, PCHAR_g, PCHAR_SPACE, PCHAR_N, PCHAR_e, PCHAR_c, PCHAR_k, 0xff, 0x0, 0x0})),
	15, 415,//Height & weight
	str_pokedex_data_203_page_0, str_pokedex_data_203_page_1,
	0,//unused
	281, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 204
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_e, PCHAR_u, PCHAR_t, PCHAR_e, PCHAR_l, PCHAR_w, PCHAR_u, PCHAR_r, PCHAR_m, 0xff, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_g, PCHAR_w, PCHAR_o, PCHAR_r, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0})),
	6, 72,//Height & weight
	str_pokedex_data_204_page_0, str_pokedex_data_204_page_1,
	0,//unused
	445, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 205
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_e, PCHAR_u, PCHAR_t, PCHAR_e, PCHAR_l, PCHAR_w, PCHAR_u, PCHAR_r, PCHAR_m, 0xff, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_g, PCHAR_w, PCHAR_o, PCHAR_r, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0})),
	12, 1258,//Height & weight
	str_pokedex_data_205_page_0, str_pokedex_data_205_page_1,
	0,//unused
	293, 5,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 206
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_o, PCHAR_n, PCHAR_n, PCHAR_e, PCHAR_r, PCHAR_k, PCHAR_e, PCHAR_i, PCHAR_l, 0xff, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_n, PCHAR_d, PCHAR_SPACE, PCHAR_S, PCHAR_n, PCHAR_a, PCHAR_k, PCHAR_e, 0xff, 0x0})),
	15, 140,//Height & weight
	str_pokedex_data_206_page_0, str_pokedex_data_206_page_1,
	0,//unused
	284, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 207
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_g, PCHAR_s, PCHAR_k, PCHAR_o, PCHAR_r, PCHAR_p, PCHAR_i, 0xff, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_y, PCHAR_s, PCHAR_c, PCHAR_o, PCHAR_r, PCHAR_p, PCHAR_i, PCHAR_o, PCHAR_n, 0xff})),
	11, 648,//Height & weight
	str_pokedex_data_207_page_0, str_pokedex_data_207_page_1,
	0,//unused
	350, 65535,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 208
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_a, PCHAR_h, PCHAR_l, PCHAR_b, PCHAR_o, PCHAR_a, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_I, PCHAR_r, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_S, PCHAR_n, PCHAR_a, PCHAR_k, PCHAR_e, 0xff, 0x0})),
	92, 4000,//Height & weight
	str_pokedex_data_208_page_0, str_pokedex_data_208_page_1,
	0,//unused
	278, 65535,//Pokemon scale, displacement
	557, 13,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 209
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_a, PCHAR_i, PCHAR_r, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 78,//Height & weight
	str_pokedex_data_209_page_0, str_pokedex_data_209_page_1,
	0,//unused
	465, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 210
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_a, PCHAR_i, PCHAR_r, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	14, 487,//Height & weight
	str_pokedex_data_210_page_0, str_pokedex_data_210_page_1,
	0,//unused
	256, 3,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 211
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_o, PCHAR_p, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_z, PCHAR_a, PCHAR_h, PCHAR_n, 0xff, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_o, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0})),
	18, 1004,//Height & weight
	str_pokedex_data_211_page_0, str_pokedex_data_211_page_1,
	0,//unused
	777, 0,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 212
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_n, PCHAR_e, PCHAR_i, PCHAR_f, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_i, PCHAR_n, PCHAR_c, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	18, 1180,//Height & weight
	str_pokedex_data_212_page_0, str_pokedex_data_212_page_1,
	0,//unused
	282, 0,//Pokemon scale, displacement
	282, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 213
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_i, PCHAR_m, PCHAR_m, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_o, PCHAR_l, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 205,//Height & weight
	str_pokedex_data_213_page_0, str_pokedex_data_213_page_1,
	0,//unused
	485, 16,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 214
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_n, PCHAR_z, PCHAR_e, PCHAR_l, PCHAR_h, PCHAR_o, PCHAR_r, PCHAR_n, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_i, PCHAR_n, PCHAR_g, PCHAR_l, PCHAR_e, PCHAR_SPACE, PCHAR_H, PCHAR_o, PCHAR_r, PCHAR_n, 0xff})),
	15, 540,//Height & weight
	str_pokedex_data_214_page_0, str_pokedex_data_214_page_1,
	0,//unused
	285, 0,//Pokemon scale, displacement
	283, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 215
	PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_e, PCHAR_r, PCHAR_b, PCHAR_o, PCHAR_t, PCHAR_e, PCHAR_n, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_p, PCHAR_SPACE, PCHAR_C, PCHAR_l, PCHAR_a, PCHAR_w, 0xff, 0x0})),
	9, 280,//Height & weight
	str_pokedex_data_215_page_0, str_pokedex_data_215_page_1,
	0,//unused
	413, 65533,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 216
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_l, PCHAR_e, PCHAR_i, PCHAR_n, PCHAR_b, PCHAR_ae, PCHAR_r, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_t, PCHAR_t, PCHAR_l, PCHAR_e, PCHAR_SPACE, PCHAR_B, PCHAR_e, PCHAR_a, PCHAR_r, 0xff})),
	6, 88,//Height & weight
	str_pokedex_data_216_page_0, str_pokedex_data_216_page_1,
	0,//unused
	455, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 217
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_ae, PCHAR_f, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_i, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_n, PCHAR_a, PCHAR_t, PCHAR_o, PCHAR_r, 0xff, 0x0})),
	18, 1258,//Height & weight
	str_pokedex_data_217_page_0, str_pokedex_data_217_page_1,
	0,//unused
	275, 0,//Pokemon scale, displacement
	280, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 218
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_v, PCHAR_a, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_v, PCHAR_a, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	7, 350,//Height & weight
	str_pokedex_data_218_page_0, str_pokedex_data_218_page_1,
	0,//unused
	329, 14,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 219
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_v, PCHAR_a, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_v, PCHAR_a, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 550,//Height & weight
	str_pokedex_data_219_page_0, str_pokedex_data_219_page_1,
	0,//unused
	332, 14,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 220
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_r, PCHAR_k, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_i, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	4, 65,//Height & weight
	str_pokedex_data_220_page_0, str_pokedex_data_220_page_1,
	0,//unused
	324, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 221
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_e, PCHAR_i, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_w, PCHAR_i, PCHAR_n, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	11, 558,//Height & weight
	str_pokedex_data_221_page_0, str_pokedex_data_221_page_1,
	0,//unused
	306, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 222
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_o, PCHAR_r, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_r, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 50,//Height & weight
	str_pokedex_data_222_page_0, str_pokedex_data_222_page_1,
	0,//unused
	410, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 223
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_o, PCHAR_c, PCHAR_h, PCHAR_d, PCHAR_r, PCHAR_u, PCHAR_c, PCHAR_k, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_J, PCHAR_e, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 120,//Height & weight
	str_pokedex_data_223_page_0, str_pokedex_data_223_page_1,
	0,//unused
	316, 4,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 224
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_o, PCHAR_c, PCHAR_h, PCHAR_d, PCHAR_r, PCHAR_u, PCHAR_c, PCHAR_k, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_J, PCHAR_e, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	9, 285,//Height & weight
	str_pokedex_data_224_page_0, str_pokedex_data_224_page_1,
	0,//unused
	296, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 225
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_e, PCHAR_f, PCHAR_e, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_t, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_e, PCHAR_l, PCHAR_i, PCHAR_v, PCHAR_e, PCHAR_r, PCHAR_y, 0xff, 0x0, 0x0, 0x0})),
	9, 160,//Height & weight
	str_pokedex_data_225_page_0, str_pokedex_data_225_page_1,
	0,//unused
	293, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 226
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_g, PCHAR_r, PCHAR_o, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_n, 0xff, 0x0}), P99_PROCTECT({PCHAR_K, PCHAR_i, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	21, 2200,//Height & weight
	str_pokedex_data_226_page_0, str_pokedex_data_226_page_1,
	0,//unused
	275, 0,//Pokemon scale, displacement
	360, 6,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 227
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_g, PCHAR_s, PCHAR_t, PCHAR_a, PCHAR_h, PCHAR_l, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_A, PCHAR_r, PCHAR_m, PCHAR_o, PCHAR_r, PCHAR_SPACE, PCHAR_B, PCHAR_i, PCHAR_r, PCHAR_d, 0xff, 0x0})),
	17, 505,//Height & weight
	str_pokedex_data_227_page_0, str_pokedex_data_227_page_1,
	0,//unused
	285, 0,//Pokemon scale, displacement
	276, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 228
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_a, PCHAR_d, PCHAR_e, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_a, PCHAR_r, PCHAR_k, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 108,//Height & weight
	str_pokedex_data_228_page_0, str_pokedex_data_228_page_1,
	0,//unused
	393, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 229
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_a, PCHAR_d, PCHAR_e, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_a, PCHAR_r, PCHAR_k, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	14, 350,//Height & weight
	str_pokedex_data_229_page_0, str_pokedex_data_229_page_1,
	0,//unused
	256, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 230
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	18, 1520,//Height & weight
	str_pokedex_data_230_page_0, str_pokedex_data_230_page_1,
	0,//unused
	257, 1,//Pokemon scale, displacement
	293, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 231
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_r, PCHAR_ue, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_l, 0xff, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_o, PCHAR_n, PCHAR_g, PCHAR_SPACE, PCHAR_N, PCHAR_o, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0})),
	5, 335,//Height & weight
	str_pokedex_data_231_page_0, str_pokedex_data_231_page_1,
	0,//unused
	465, 20,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 232
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_a, PCHAR_n, PCHAR_z, PCHAR_e, PCHAR_r, PCHAR_t, PCHAR_i, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_A, PCHAR_r, PCHAR_m, PCHAR_o, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	11, 1200,//Height & weight
	str_pokedex_data_232_page_0, str_pokedex_data_232_page_1,
	0,//unused
	313, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 233
	PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_i, PCHAR_r, PCHAR_t, PCHAR_u, PCHAR_e, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_V, PCHAR_i, PCHAR_r, PCHAR_t, PCHAR_u, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0})),
	6, 325,//Height & weight
	str_pokedex_data_233_page_0, str_pokedex_data_233_page_1,
	0,//unused
	320, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 234
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_o, PCHAR_m, PCHAR_p, PCHAR_a, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_g, PCHAR_SPACE, PCHAR_H, PCHAR_o, PCHAR_r, PCHAR_n, 0xff, 0x0, 0x0, 0x0})),
	14, 712,//Height & weight
	str_pokedex_data_234_page_0, str_pokedex_data_234_page_1,
	0,//unused
	277, 65535,//Pokemon scale, displacement
	277, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 235
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_i, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_l, PCHAR_i, PCHAR_c, PCHAR_h, 0xff, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_a, PCHAR_i, PCHAR_n, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0})),
	12, 580,//Height & weight
	str_pokedex_data_235_page_0, str_pokedex_data_235_page_1,
	0,//unused
	287, 5,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 236
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_a, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_u, PCHAR_f, PCHAR_f, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0})),
	7, 210,//Height & weight
	str_pokedex_data_236_page_0, str_pokedex_data_236_page_1,
	0,//unused
	292, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 237
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_o, PCHAR_p, PCHAR_f, PCHAR_s, PCHAR_t, PCHAR_a, PCHAR_n, PCHAR_d, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_a, PCHAR_n, PCHAR_d, PCHAR_s, PCHAR_t, PCHAR_a, PCHAR_n, PCHAR_d, 0xff, 0x0, 0x0})),
	14, 480,//Height & weight
	str_pokedex_data_237_page_0, str_pokedex_data_237_page_1,
	0,//unused
	256, 2,//Pokemon scale, displacement
	257, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 238
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_u, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_K, PCHAR_i, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	4, 60,//Height & weight
	str_pokedex_data_238_page_0, str_pokedex_data_238_page_1,
	0,//unused
	440, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 239
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_l, PCHAR_e, PCHAR_k, PCHAR_t, PCHAR_r, PCHAR_o, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_l, PCHAR_e, PCHAR_c, PCHAR_t, PCHAR_r, PCHAR_i, PCHAR_c, 0xff, 0x0, 0x0, 0x0})),
	6, 235,//Height & weight
	str_pokedex_data_239_page_0, str_pokedex_data_239_page_1,
	0,//unused
	363, 13,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 240
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_l, PCHAR_u, PCHAR_t, PCHAR_h, PCHAR_e, PCHAR_r, PCHAR_d, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_v, PCHAR_e, PCHAR_SPACE, PCHAR_C, PCHAR_o, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0})),
	7, 214,//Height & weight
	str_pokedex_data_240_page_0, str_pokedex_data_240_page_1,
	0,//unused
	284, 11,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 241
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_i, PCHAR_l, PCHAR_c, PCHAR_h, PCHAR_k, PCHAR_u, PCHAR_h, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_i, PCHAR_l, PCHAR_k, PCHAR_SPACE, PCHAR_C, PCHAR_o, PCHAR_w, 0xff, 0x0, 0x0, 0x0})),
	12, 755,//Height & weight
	str_pokedex_data_241_page_0, str_pokedex_data_241_page_1,
	0,//unused
	280, 3,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 242
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_r, PCHAR_e, PCHAR_u, PCHAR_d, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_a, PCHAR_p, PCHAR_p, PCHAR_i, PCHAR_n, PCHAR_e, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0})),
	15, 468,//Height & weight
	str_pokedex_data_242_page_0, str_pokedex_data_242_page_1,
	0,//unused
	256, 3,//Pokemon scale, displacement
	310, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 243
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_o, PCHAR_n, PCHAR_n, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_h, PCHAR_u, PCHAR_n, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0})),
	19, 1780,//Height & weight
	str_pokedex_data_243_page_0, str_pokedex_data_243_page_1,
	0,//unused
	283, 0,//Pokemon scale, displacement
	359, 6,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 244
	PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_u, PCHAR_l, PCHAR_k, PCHAR_a, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_V, PCHAR_o, PCHAR_l, PCHAR_c, PCHAR_a, PCHAR_n, PCHAR_o, 0xff, 0x0, 0x0, 0x0, 0x0})),
	21, 1980,//Height & weight
	str_pokedex_data_244_page_0, str_pokedex_data_244_page_1,
	0,//unused
	283, 0,//Pokemon scale, displacement
	370, 7,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 245
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_l, PCHAR_a, PCHAR_r, PCHAR_l, PCHAR_i, PCHAR_c, PCHAR_h, PCHAR_t, 0xff, 0x0}), P99_PROCTECT({PCHAR_A, PCHAR_u, PCHAR_r, PCHAR_o, PCHAR_r, PCHAR_a, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	20, 1870,//Height & weight
	str_pokedex_data_245_page_0, str_pokedex_data_245_page_1,
	0,//unused
	286, 0,//Pokemon scale, displacement
	371, 7,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 246
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_l, PCHAR_s, PCHAR_h, PCHAR_a, PCHAR_u, PCHAR_t, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_c, PCHAR_k, PCHAR_SPACE, PCHAR_S, PCHAR_k, PCHAR_i, PCHAR_n, 0xff, 0x0, 0x0})),
	6, 720,//Height & weight
	str_pokedex_data_246_page_0, str_pokedex_data_246_page_1,
	0,//unused
	472, 16,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 247
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_a, PCHAR_r, PCHAR_t, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_l, PCHAR_e, 0xff, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_a, PCHAR_r, PCHAR_d, PCHAR_SPACE, PCHAR_S, PCHAR_h, PCHAR_e, PCHAR_l, PCHAR_l, 0xff, 0x0})),
	12, 1520,//Height & weight
	str_pokedex_data_247_page_0, str_pokedex_data_247_page_1,
	0,//unused
	292, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 248
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_a, PCHAR_n, PCHAR_z, PCHAR_e, PCHAR_r, PCHAR_t, PCHAR_i, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_A, PCHAR_r, PCHAR_m, PCHAR_o, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	20, 2020,//Height & weight
	str_pokedex_data_248_page_0, str_pokedex_data_248_page_1,
	0,//unused
	285, 0,//Pokemon scale, displacement
	383, 7,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 249
	PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_a, PCHAR_u, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_i, PCHAR_v, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	52, 2160,//Height & weight
	str_pokedex_data_249_page_0, str_pokedex_data_249_page_1,
	0,//unused
	283, 0,//Pokemon scale, displacement
	742, 18,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 250
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_e, PCHAR_g, PCHAR_e, PCHAR_n, PCHAR_b, PCHAR_o, PCHAR_g, PCHAR_e, PCHAR_n, 0xff, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_a, PCHAR_i, PCHAR_n, PCHAR_b, PCHAR_o, PCHAR_w, 0xff, 0x0, 0x0, 0x0, 0x0})),
	38, 1990,//Height & weight
	str_pokedex_data_250_page_0, str_pokedex_data_250_page_1,
	0,//unused
	283, 0,//Pokemon scale, displacement
	620, 16,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 251
	PSTRING(P99_PROCTECT({PCHAR_Z, PCHAR_e, PCHAR_i, PCHAR_t, PCHAR_r, PCHAR_e, PCHAR_i, PCHAR_s, PCHAR_e, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_i, PCHAR_m, PCHAR_e, PCHAR_SPACE, PCHAR_T, PCHAR_r, PCHAR_a, PCHAR_v, PCHAR_e, PCHAR_l, 0xff})),
	6, 50,//Height & weight
	str_pokedex_data_251_page_0, str_pokedex_data_251_page_1,
	0,//unused
	393, 65526,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 252
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_o, PCHAR_c, PCHAR_k, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_o, PCHAR_o, PCHAR_d, PCHAR_SPACE, PCHAR_G, PCHAR_e, PCHAR_c, PCHAR_k, PCHAR_o, 0xff, 0x0})),
	5, 50,//Height & weight
	str_pokedex_data_252_page_0, str_pokedex_data_252_page_1,
	0,//unused
	541, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 253
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_e, PCHAR_r, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_o, PCHAR_o, PCHAR_d, PCHAR_SPACE, PCHAR_G, PCHAR_e, PCHAR_c, PCHAR_k, PCHAR_o, 0xff, 0x0})),
	9, 216,//Height & weight
	str_pokedex_data_253_page_0, str_pokedex_data_253_page_1,
	0,//unused
	360, 5,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 254
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_i, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_o, PCHAR_r, PCHAR_e, PCHAR_s, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	17, 522,//Height & weight
	str_pokedex_data_254_page_0, str_pokedex_data_254_page_1,
	0,//unused
	282, 65535,//Pokemon scale, displacement
	313, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 255
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_e, PCHAR_l, PCHAR_p, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_h, PCHAR_i, PCHAR_c, PCHAR_k, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	4, 25,//Height & weight
	str_pokedex_data_255_page_0, str_pokedex_data_255_page_1,
	0,//unused
	566, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 256
	PSTRING(P99_PROCTECT({PCHAR_O, PCHAR_r, PCHAR_t, PCHAR_h, PCHAR_o, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_Y, PCHAR_o, PCHAR_u, PCHAR_n, PCHAR_g, PCHAR_SPACE, PCHAR_F, PCHAR_o, PCHAR_w, PCHAR_l, 0xff, 0x0})),
	9, 195,//Height & weight
	str_pokedex_data_256_page_0, str_pokedex_data_256_page_1,
	0,//unused
	343, 5,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 257
	PSTRING(P99_PROCTECT({PCHAR_Z, PCHAR_e, PCHAR_r, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_u, PCHAR_s, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_l, PCHAR_a, PCHAR_z, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	19, 520,//Height & weight
	str_pokedex_data_257_page_0, str_pokedex_data_257_page_1,
	0,//unused
	275, 65535,//Pokemon scale, displacement
	314, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 258
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_r, PCHAR_m, PCHAR_o, PCHAR_l, PCHAR_c, PCHAR_h, 0xff}), P99_PROCTECT({PCHAR_M, PCHAR_u, PCHAR_d, PCHAR_SPACE, PCHAR_F, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0, 0x0})),
	4, 76,//Height & weight
	str_pokedex_data_258_page_0, str_pokedex_data_258_page_1,
	0,//unused
	535, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 259
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_e, PCHAR_l, PCHAR_p, PCHAR_h, PCHAR_i, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_u, PCHAR_d, PCHAR_SPACE, PCHAR_F, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0, 0x0})),
	7, 280,//Height & weight
	str_pokedex_data_259_page_0, str_pokedex_data_259_page_1,
	0,//unused
	340, 7,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 260
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_e, 0xff}), P99_PROCTECT({PCHAR_M, PCHAR_u, PCHAR_d, PCHAR_SPACE, PCHAR_F, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0, 0x0})),
	15, 819,//Height & weight
	str_pokedex_data_260_page_0, str_pokedex_data_260_page_1,
	0,//unused
	276, 65535,//Pokemon scale, displacement
	282, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 261
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	5, 136,//Height & weight
	str_pokedex_data_261_page_0, str_pokedex_data_261_page_1,
	0,//unused
	481, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 262
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	10, 370,//Height & weight
	str_pokedex_data_262_page_0, str_pokedex_data_262_page_1,
	0,//unused
	359, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 263
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_l, PCHAR_e, PCHAR_i, PCHAR_n, PCHAR_d, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_s, 0xff, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_i, PCHAR_n, PCHAR_y, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_c, PCHAR_o, PCHAR_o, PCHAR_n, 0xff})),
	4, 175,//Height & weight
	str_pokedex_data_263_page_0, str_pokedex_data_263_page_1,
	0,//unused
	560, 21,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 264
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_r, PCHAR_i, PCHAR_n, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_u, PCHAR_s, PCHAR_h, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0})),
	5, 325,//Height & weight
	str_pokedex_data_264_page_0, str_pokedex_data_264_page_1,
	0,//unused
	321, 5,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 265
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_u, PCHAR_r, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_o, PCHAR_r, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	3, 36,//Height & weight
	str_pokedex_data_265_page_0, str_pokedex_data_265_page_1,
	0,//unused
	711, 22,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 266
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_o, PCHAR_k, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_c, PCHAR_o, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 100,//Height & weight
	str_pokedex_data_266_page_0, str_pokedex_data_266_page_1,
	0,//unused
	431, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 267
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_a, PCHAR_l, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_u, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_f, PCHAR_l, PCHAR_y, 0xff, 0x0, 0x0})),
	10, 284,//Height & weight
	str_pokedex_data_267_page_0, str_pokedex_data_267_page_1,
	0,//unused
	298, 65535,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 268
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_o, PCHAR_k, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_c, PCHAR_o, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	7, 115,//Height & weight
	str_pokedex_data_268_page_0, str_pokedex_data_268_page_1,
	0,//unused
	391, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 269
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_m, PCHAR_o, PCHAR_t, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_M, PCHAR_o, PCHAR_t, PCHAR_h, 0xff})),
	12, 316,//Height & weight
	str_pokedex_data_269_page_0, str_pokedex_data_269_page_1,
	0,//unused
	269, 1,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 270
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_r, PCHAR_l, PCHAR_i, PCHAR_n, PCHAR_s, PCHAR_e, 0xff}), P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_W, PCHAR_e, PCHAR_e, PCHAR_d, 0xff, 0x0})),
	5, 26,//Height & weight
	str_pokedex_data_270_page_0, str_pokedex_data_270_page_1,
	0,//unused
	406, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 271
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_r, PCHAR_o, PCHAR_h, PCHAR_m, PCHAR_u, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_J, PCHAR_o, PCHAR_l, PCHAR_l, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	12, 325,//Height & weight
	str_pokedex_data_271_page_0, str_pokedex_data_271_page_1,
	0,//unused
	277, 7,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 272
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_o, PCHAR_r, PCHAR_g, PCHAR_l, PCHAR_o, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_a, PCHAR_r, PCHAR_e, PCHAR_f, PCHAR_r, PCHAR_e, PCHAR_e, 0xff, 0x0, 0x0, 0x0})),
	15, 550,//Height & weight
	str_pokedex_data_272_page_0, str_pokedex_data_272_page_1,
	0,//unused
	283, 0,//Pokemon scale, displacement
	282, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 273
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_l, PCHAR_n, PCHAR_u, PCHAR_s, PCHAR_s, 0xff, 0x0}), P99_PROCTECT({PCHAR_A, PCHAR_c, PCHAR_o, PCHAR_r, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	5, 40,//Height & weight
	str_pokedex_data_273_page_0, str_pokedex_data_273_page_1,
	0,//unused
	472, 20,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 274
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_i, PCHAR_n, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_l, PCHAR_i, PCHAR_s, PCHAR_t, 0xff, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_l, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	10, 280,//Height & weight
	str_pokedex_data_274_page_0, str_pokedex_data_274_page_1,
	0,//unused
	299, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 275
	PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_e, PCHAR_r, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_a, PCHAR_g, PCHAR_e, PCHAR_n, 0xff}), P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	13, 596,//Height & weight
	str_pokedex_data_275_page_0, str_pokedex_data_275_page_1,
	0,//unused
	290, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 276
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_ae, PCHAR_l, PCHAR_b, PCHAR_l, PCHAR_e, PCHAR_i, PCHAR_n, 0xff}), P99_PROCTECT({PCHAR_T, PCHAR_i, PCHAR_n, PCHAR_y, PCHAR_s, PCHAR_w, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_o, PCHAR_w, 0xff})),
	3, 23,//Height & weight
	str_pokedex_data_276_page_0, str_pokedex_data_276_page_1,
	0,//unused
	465, 20,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 277
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_a, PCHAR_l, PCHAR_b, PCHAR_e, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_w, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_o, PCHAR_w, 0xff, 0x0, 0x0, 0x0, 0x0})),
	7, 198,//Height & weight
	str_pokedex_data_277_page_0, str_pokedex_data_277_page_1,
	0,//unused
	428, 13,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 278
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_m, PCHAR_oe, PCHAR_w, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_a, PCHAR_g, PCHAR_u, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0})),
	6, 95,//Height & weight
	str_pokedex_data_278_page_0, str_pokedex_data_278_page_1,
	0,//unused
	295, 65534,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 279
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_r, PCHAR_v, PCHAR_o, PCHAR_g, PCHAR_e, PCHAR_l, 0xff}), P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_t, PCHAR_e, PCHAR_r, PCHAR_SPACE, PCHAR_B, PCHAR_i, PCHAR_r, PCHAR_d, 0xff, 0x0})),
	12, 280,//Height & weight
	str_pokedex_data_279_page_0, str_pokedex_data_279_page_1,
	0,//unused
	288, 1,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 280
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_f, PCHAR_ue, PCHAR_h, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_e, PCHAR_e, PCHAR_l, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0})),
	4, 66,//Height & weight
	str_pokedex_data_280_page_0, str_pokedex_data_280_page_1,
	0,//unused
	457, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 281
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_m, PCHAR_o, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_m, PCHAR_o, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0})),
	8, 202,//Height & weight
	str_pokedex_data_281_page_0, str_pokedex_data_281_page_1,
	0,//unused
	354, 10,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 282
	PSTRING(P99_PROCTECT({PCHAR_U, PCHAR_m, PCHAR_a, PCHAR_r, PCHAR_m, PCHAR_u, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_m, PCHAR_b, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0})),
	16, 484,//Height & weight
	str_pokedex_data_282_page_0, str_pokedex_data_282_page_1,
	0,//unused
	277, 0,//Pokemon scale, displacement
	276, 65535,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 283
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_a, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_r, PCHAR_g, PCHAR_e, PCHAR_h, PCHAR_e, PCHAR_r, 0xff}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_n, PCHAR_d, PCHAR_SPACE, PCHAR_S, PCHAR_k, PCHAR_a, PCHAR_t, PCHAR_e, PCHAR_r, 0xff})),
	5, 17,//Height & weight
	str_pokedex_data_283_page_0, str_pokedex_data_283_page_1,
	0,//unused
	375, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 284
	PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_u, PCHAR_g, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_y, PCHAR_e, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0})),
	8, 36,//Height & weight
	str_pokedex_data_284_page_0, str_pokedex_data_284_page_1,
	0,//unused
	378, 65535,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 285
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_i, PCHAR_l, PCHAR_z, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_u, PCHAR_s, PCHAR_h, PCHAR_r, PCHAR_o, PCHAR_o, PCHAR_m, 0xff, 0x0, 0x0, 0x0})),
	4, 45,//Height & weight
	str_pokedex_data_285_page_0, str_pokedex_data_285_page_1,
	0,//unused
	513, 20,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 286
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_i, PCHAR_l, PCHAR_z, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_u, PCHAR_s, PCHAR_h, PCHAR_r, PCHAR_o, PCHAR_o, PCHAR_m, 0xff, 0x0, 0x0, 0x0})),
	12, 392,//Height & weight
	str_pokedex_data_286_page_0, str_pokedex_data_286_page_1,
	0,//unused
	324, 6,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 287
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_a, PCHAR_u, PCHAR_l, PCHAR_p, PCHAR_e, PCHAR_l, PCHAR_z, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_l, PCHAR_a, PCHAR_c, PCHAR_k, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0})),
	8, 240,//Height & weight
	str_pokedex_data_287_page_0, str_pokedex_data_287_page_1,
	0,//unused
	291, 16,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 288
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_l, PCHAR_d, PCHAR_a, PCHAR_f, PCHAR_f, PCHAR_e, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_l, PCHAR_d, PCHAR_SPACE, PCHAR_M, PCHAR_o, PCHAR_n, PCHAR_k, PCHAR_e, PCHAR_y, 0xff})),
	14, 465,//Height & weight
	str_pokedex_data_288_page_0, str_pokedex_data_288_page_1,
	0,//unused
	301, 1,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 289
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_ue, PCHAR_s, PCHAR_s, PCHAR_i, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_z, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	20, 1305,//Height & weight
	str_pokedex_data_289_page_0, str_pokedex_data_289_page_1,
	0,//unused
	277, 5,//Pokemon scale, displacement
	326, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 290
	PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_o, PCHAR_r, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_e, PCHAR_i, PCHAR_t, PCHAR_e, PCHAR_r, 0xff}), P99_PROCTECT({PCHAR_T, PCHAR_r, PCHAR_a, PCHAR_i, PCHAR_n, PCHAR_e, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0})),
	5, 55,//Height & weight
	str_pokedex_data_290_page_0, str_pokedex_data_290_page_1,
	0,//unused
	405, 20,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 291
	PSTRING(P99_PROCTECT({PCHAR_N, PCHAR_i, PCHAR_n, PCHAR_j, PCHAR_a, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_N, PCHAR_i, PCHAR_n, PCHAR_j, PCHAR_a, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 120,//Height & weight
	str_pokedex_data_291_page_0, str_pokedex_data_291_page_1,
	0,//unused
	383, 65527,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 292
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_ae, PCHAR_u, PCHAR_t, PCHAR_u, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_h, PCHAR_e, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 12,//Height & weight
	str_pokedex_data_292_page_0, str_pokedex_data_292_page_1,
	0,//unused
	372, 65528,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 293
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_a, PCHAR_n, PCHAR_d, PCHAR_h, PCHAR_a, PCHAR_i, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_h, PCHAR_i, PCHAR_s, PCHAR_p, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0})),
	6, 163,//Height & weight
	str_pokedex_data_293_page_0, str_pokedex_data_293_page_1,
	0,//unused
	373, 16,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 294
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_oe, PCHAR_h, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_g, PCHAR_SPACE, PCHAR_V, PCHAR_o, PCHAR_i, PCHAR_c, PCHAR_e, 0xff, 0x0, 0x0})),
	10, 405,//Height & weight
	str_pokedex_data_294_page_0, str_pokedex_data_294_page_1,
	0,//unused
	356, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 295
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_a, PCHAR_s, PCHAR_a, PCHAR_n, PCHAR_z, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_o, PCHAR_u, PCHAR_d, PCHAR_SPACE, PCHAR_N, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_e, 0xff, 0x0})),
	21, 840,//Height & weight
	str_pokedex_data_295_page_0, str_pokedex_data_295_page_1,
	0,//unused
	284, 1,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 296
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_e, PCHAR_n, PCHAR_s, PCHAR_p, PCHAR_i, PCHAR_e, PCHAR_l, 0xff}), P99_PROCTECT({PCHAR_G, PCHAR_u, PCHAR_t, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	10, 864,//Height & weight
	str_pokedex_data_296_page_0, str_pokedex_data_296_page_1,
	0,//unused
	256, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 297
	PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_u, PCHAR_r, PCHAR_a, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_A, PCHAR_r, PCHAR_m, PCHAR_SPACE, PCHAR_T, PCHAR_h, PCHAR_r, PCHAR_u, PCHAR_s, PCHAR_t, 0xff, 0x0})),
	23, 2538,//Height & weight
	str_pokedex_data_297_page_0, str_pokedex_data_297_page_1,
	0,//unused
	268, 65535,//Pokemon scale, displacement
	375, 6,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 298
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_p, PCHAR_u, PCHAR_n, PCHAR_k, PCHAR_t, PCHAR_e, PCHAR_t, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_l, PCHAR_k, PCHAR_a, PCHAR_SPACE, PCHAR_D, PCHAR_o, PCHAR_t, 0xff, 0x0, 0x0})),
	2, 20,//Height & weight
	str_pokedex_data_298_page_0, str_pokedex_data_298_page_1,
	0,//unused
	603, 21,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 299
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_o, PCHAR_m, PCHAR_p, PCHAR_a, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_m, PCHAR_p, PCHAR_a, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0})),
	10, 970,//Height & weight
	str_pokedex_data_299_page_0, str_pokedex_data_299_page_1,
	0,//unused
	256, 9,//Pokemon scale, displacement
	289, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 300
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_ae, PCHAR_t, PCHAR_z, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_n, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_K, PCHAR_i, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 110,//Height & weight
	str_pokedex_data_300_page_0, str_pokedex_data_300_page_1,
	0,//unused
	492, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 301
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_n, PCHAR_g, PCHAR_e, PCHAR_b, PCHAR_i, PCHAR_l, PCHAR_d, PCHAR_e, PCHAR_t, 0xff}), P99_PROCTECT({PCHAR_P, PCHAR_r, PCHAR_i, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	11, 326,//Height & weight
	str_pokedex_data_301_page_0, str_pokedex_data_301_page_1,
	0,//unused
	322, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 302
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_r, PCHAR_e, PCHAR_i, PCHAR_f, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_a, PCHAR_r, PCHAR_k, PCHAR_n, PCHAR_e, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0, 0x0})),
	5, 110,//Height & weight
	str_pokedex_data_302_page_0, str_pokedex_data_302_page_1,
	0,//unused
	451, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 303
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_w, PCHAR_i, PCHAR_n, PCHAR_d, PCHAR_l, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_e, PCHAR_c, PCHAR_e, PCHAR_i, PCHAR_v, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0})),
	6, 115,//Height & weight
	str_pokedex_data_303_page_0, str_pokedex_data_303_page_1,
	0,//unused
	466, 15,//Pokemon scale, displacement
	256, 65533,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 304
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, PCHAR_e, PCHAR_n, PCHAR_p, PCHAR_a, PCHAR_n, PCHAR_z, PCHAR_e, PCHAR_r, 0xff}), P99_PROCTECT({PCHAR_I, PCHAR_r, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_A, PCHAR_r, PCHAR_m, PCHAR_o, PCHAR_r, 0xff, 0x0})),
	4, 600,//Height & weight
	str_pokedex_data_304_page_0, str_pokedex_data_304_page_1,
	0,//unused
	419, 21,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 305
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, PCHAR_e, PCHAR_n, PCHAR_p, PCHAR_a, PCHAR_n, PCHAR_z, PCHAR_e, PCHAR_r, 0xff}), P99_PROCTECT({PCHAR_I, PCHAR_r, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_A, PCHAR_r, PCHAR_m, PCHAR_o, PCHAR_r, 0xff, 0x0})),
	9, 1200,//Height & weight
	str_pokedex_data_305_page_0, str_pokedex_data_305_page_1,
	0,//unused
	275, 11,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 306
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, PCHAR_e, PCHAR_n, PCHAR_p, PCHAR_a, PCHAR_n, PCHAR_z, PCHAR_e, PCHAR_r, 0xff}), P99_PROCTECT({PCHAR_I, PCHAR_r, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_A, PCHAR_r, PCHAR_m, PCHAR_o, PCHAR_r, 0xff, 0x0})),
	21, 3600,//Height & weight
	str_pokedex_data_306_page_0, str_pokedex_data_306_page_1,
	0,//unused
	274, 65535,//Pokemon scale, displacement
	374, 7,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 307
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_d, PCHAR_i, PCHAR_t, PCHAR_a, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_d, PCHAR_i, PCHAR_t, PCHAR_a, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0})),
	6, 112,//Height & weight
	str_pokedex_data_307_page_0, str_pokedex_data_307_page_1,
	0,//unused
	465, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 308
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_d, PCHAR_i, PCHAR_t, PCHAR_a, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_d, PCHAR_i, PCHAR_t, PCHAR_a, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0})),
	13, 315,//Height & weight
	str_pokedex_data_308_page_0, str_pokedex_data_308_page_1,
	0,//unused
	298, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 309
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_e, PCHAR_w, PCHAR_i, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_g, PCHAR_h, PCHAR_t, PCHAR_n, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0})),
	6, 152,//Height & weight
	str_pokedex_data_309_page_0, str_pokedex_data_309_page_1,
	0,//unused
	290, 16,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 310
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_n, PCHAR_t, PCHAR_l, PCHAR_a, PCHAR_d, PCHAR_u, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_i, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_a, PCHAR_r, PCHAR_g, PCHAR_e, 0xff, 0x0, 0x0})),
	15, 402,//Height & weight
	str_pokedex_data_310_page_0, str_pokedex_data_310_page_1,
	0,//unused
	256, 1,//Pokemon scale, displacement
	257, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 311
	PSTRING(P99_PROCTECT({PCHAR_J, PCHAR_u, PCHAR_b, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_h, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0})),
	4, 42,//Height & weight
	str_pokedex_data_311_page_0, str_pokedex_data_311_page_1,
	0,//unused
	515, 65527,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 312
	PSTRING(P99_PROCTECT({PCHAR_J, PCHAR_u, PCHAR_b, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_h, PCHAR_e, PCHAR_e, PCHAR_r, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0})),
	4, 42,//Height & weight
	str_pokedex_data_312_page_0, str_pokedex_data_312_page_1,
	0,//unused
	512, 65529,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 313
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_b, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_r, PCHAR_e, PCHAR_f, PCHAR_l, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0})),
	7, 177,//Height & weight
	str_pokedex_data_313_page_0, str_pokedex_data_313_page_1,
	0,//unused
	442, 65532,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 314
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_i, PCHAR_b, PCHAR_e, PCHAR_l, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_r, PCHAR_e, PCHAR_f, PCHAR_l, PCHAR_y, 0xff, 0x0, 0x0, 0x0, 0x0})),
	6, 177,//Height & weight
	str_pokedex_data_314_page_0, str_pokedex_data_314_page_1,
	0,//unused
	572, 65532,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 315
	PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_i, PCHAR_r, PCHAR_t, PCHAR_u, PCHAR_e, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_V, PCHAR_i, PCHAR_r, PCHAR_t, PCHAR_u, PCHAR_a, PCHAR_l, 0xFF, 0x0, 0x0, 0x0, 0x0})),
	9, 340,//Height & weight
	str_pokedex_data_315_page_0, str_pokedex_data_315_page_1,
	0,//unused
	677, 20,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 316
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_g, PCHAR_e, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_o, PCHAR_m, PCHAR_a, PCHAR_c, PCHAR_h, 0xff, 0x0, 0x0, 0x0, 0x0})),
	4, 103,//Height & weight
	str_pokedex_data_316_page_0, str_pokedex_data_316_page_1,
	0,//unused
	593, 22,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 317
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_i, PCHAR_f, PCHAR_t, PCHAR_b, PCHAR_e, PCHAR_u, PCHAR_t, PCHAR_e, PCHAR_l, 0xff, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_o, PCHAR_i, PCHAR_s, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_g, 0xff, 0x0})),
	17, 800,//Height & weight
	str_pokedex_data_317_page_0, str_pokedex_data_317_page_1,
	0,//unused
	256, 5,//Pokemon scale, displacement
	345, 4,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 318
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_n, PCHAR_a, PCHAR_d, PCHAR_e, PCHAR_n, PCHAR_l, PCHAR_o, PCHAR_s, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_a, PCHAR_v, PCHAR_a, PCHAR_g, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 208,//Height & weight
	str_pokedex_data_318_page_0, str_pokedex_data_318_page_1,
	0,//unused
	362, 0,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 319
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_r, PCHAR_u, PCHAR_t, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_r, PCHAR_u, PCHAR_t, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	18, 888,//Height & weight
	str_pokedex_data_319_page_0, str_pokedex_data_319_page_1,
	0,//unused
	265, 0,//Pokemon scale, displacement
	342, 4,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 320
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_u, PCHAR_g, PCHAR_e, PCHAR_l, PCHAR_w, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_SPACE, PCHAR_W, PCHAR_h, PCHAR_a, PCHAR_l, PCHAR_e, 0xff, 0x0})),
	20, 1300,//Height & weight
	str_pokedex_data_320_page_0, str_pokedex_data_320_page_1,
	0,//unused
	256, 10,//Pokemon scale, displacement
	493, 10,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 321
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_u, PCHAR_t, PCHAR_w, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_l, PCHAR_o, PCHAR_a, PCHAR_t, PCHAR_SPACE, PCHAR_W, PCHAR_h, PCHAR_a, PCHAR_l, PCHAR_e, 0xff})),
	145, 3980,//Height & weight
	str_pokedex_data_321_page_0, str_pokedex_data_321_page_1,
	0,//unused
	276, 65535,//Pokemon scale, displacement
	1428, 20,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 322
	PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_a, PCHAR_u, PCHAR_b, PCHAR_h, PCHAR_e, PCHAR_i, PCHAR_t, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_N, PCHAR_u, PCHAR_m, PCHAR_b, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	7, 240,//Height & weight
	str_pokedex_data_322_page_0, str_pokedex_data_322_page_1,
	0,//unused
	310, 14,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 323
	PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_u, PCHAR_s, PCHAR_b, PCHAR_r, PCHAR_u, PCHAR_c, PCHAR_h, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_r, PCHAR_u, PCHAR_p, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0})),
	19, 2200,//Height & weight
	str_pokedex_data_323_page_0, str_pokedex_data_323_page_1,
	0,//unused
	256, 6,//Pokemon scale, displacement
	345, 4,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 324
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_e, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_a, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_a, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	5, 804,//Height & weight
	str_pokedex_data_324_page_0, str_pokedex_data_324_page_1,
	0,//unused
	392, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 325
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_r, PCHAR_u, PCHAR_n, PCHAR_g, PCHAR_f, PCHAR_e, PCHAR_d, PCHAR_e, PCHAR_r, 0xff}), P99_PROCTECT({PCHAR_B, PCHAR_o, PCHAR_u, PCHAR_n, PCHAR_c, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	7, 306,//Height & weight
	str_pokedex_data_325_page_0, str_pokedex_data_325_page_1,
	0,//unused
	423, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 326
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_n, PCHAR_i, PCHAR_p, PCHAR_u, PCHAR_l, PCHAR_a, PCHAR_t, PCHAR_o, PCHAR_r, 0xff}), P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_n, PCHAR_i, PCHAR_p, PCHAR_u, PCHAR_l, PCHAR_a, PCHAR_t, PCHAR_e, 0xff, 0x0})),
	9, 715,//Height & weight
	str_pokedex_data_326_page_0, str_pokedex_data_326_page_1,
	0,//unused
	358, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 327
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_u, PCHAR_n, PCHAR_k, PCHAR_t, PCHAR_MINUS, PCHAR_P, PCHAR_a, PCHAR_n, PCHAR_d, PCHAR_a, 0xff}), P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_o, PCHAR_t, PCHAR_SPACE, PCHAR_P, PCHAR_a, PCHAR_n, PCHAR_d, PCHAR_a, 0xff, 0x0})),
	11, 50,//Height & weight
	str_pokedex_data_327_page_0, str_pokedex_data_327_page_1,
	0,//unused
	321, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 328
	PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_m, PCHAR_e, PCHAR_i, PCHAR_s, PCHAR_e, PCHAR_n, PCHAR_l, PCHAR_oe, PCHAR_w, PCHAR_e, 0xff}), P99_PROCTECT({PCHAR_A, PCHAR_n, PCHAR_t, PCHAR_SPACE, PCHAR_P, PCHAR_i, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0})),
	7, 150,//Height & weight
	str_pokedex_data_328_page_0, str_pokedex_data_328_page_1,
	0,//unused
	298, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 329
	PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_i, PCHAR_b, PCHAR_r, PCHAR_a, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_V, PCHAR_i, PCHAR_b, PCHAR_r, PCHAR_a, PCHAR_t, PCHAR_i, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0})),
	11, 153,//Height & weight
	str_pokedex_data_329_page_0, str_pokedex_data_329_page_1,
	0,//unused
	370, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 330
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_y, PCHAR_s, PCHAR_t, PCHAR_i, PCHAR_k, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_y, PCHAR_s, PCHAR_t, PCHAR_i, PCHAR_c, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	20, 820,//Height & weight
	str_pokedex_data_330_page_0, str_pokedex_data_330_page_1,
	0,//unused
	280, 0,//Pokemon scale, displacement
	299, 2,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 331
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_a, PCHAR_k, PCHAR_t, PCHAR_u, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_a, PCHAR_c, PCHAR_t, PCHAR_u, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	4, 513,//Height & weight
	str_pokedex_data_331_page_0, str_pokedex_data_331_page_1,
	0,//unused
	455, 19,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 332
	PSTRING(P99_PROCTECT({PCHAR_V, PCHAR_o, PCHAR_g, PCHAR_e, PCHAR_l, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_o, PCHAR_c, PCHAR_k, 0xff}), P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_a, PCHAR_r, PCHAR_e, PCHAR_c, PCHAR_r, PCHAR_o, PCHAR_w, 0xff, 0x0, 0x0})),
	13, 774,//Height & weight
	str_pokedex_data_332_page_0, str_pokedex_data_332_page_1,
	0,//unused
	327, 3,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 333
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_o, PCHAR_l, PCHAR_l, PCHAR_v, PCHAR_o, PCHAR_g, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_t, PCHAR_t, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_B, PCHAR_i, PCHAR_r, PCHAR_d, 0xff})),
	4, 12,//Height & weight
	str_pokedex_data_333_page_0, str_pokedex_data_333_page_1,
	0,//unused
	422, 65528,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 334
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_u, PCHAR_m, PCHAR_m, PCHAR_s, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_H, PCHAR_u, PCHAR_m, PCHAR_m, PCHAR_i, PCHAR_n, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0})),
	11, 206,//Height & weight
	str_pokedex_data_334_page_0, str_pokedex_data_334_page_1,
	0,//unused
	327, 0,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 335
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_r, PCHAR_e, PCHAR_t, PCHAR_t, PCHAR_k, PCHAR_a, PCHAR_t, PCHAR_z, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_a, PCHAR_t, PCHAR_SPACE, PCHAR_F, PCHAR_e, PCHAR_r, PCHAR_r, PCHAR_e, PCHAR_t, 0xff, 0x0})),
	13, 403,//Height & weight
	str_pokedex_data_335_page_0, str_pokedex_data_335_page_1,
	0,//unused
	256, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 336
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_e, PCHAR_i, PCHAR_s, PCHAR_s, PCHAR_z, PCHAR_a, PCHAR_h, PCHAR_n, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_a, PCHAR_n, PCHAR_g, PCHAR_SPACE, PCHAR_S, PCHAR_n, PCHAR_a, PCHAR_k, PCHAR_e, 0xff, 0x0})),
	27, 525,//Height & weight
	str_pokedex_data_336_page_0, str_pokedex_data_336_page_1,
	0,//unused
	275, 6,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 337
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_t, PCHAR_e, PCHAR_o, PCHAR_r, PCHAR_i, PCHAR_t, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_t, PCHAR_e, PCHAR_o, PCHAR_r, PCHAR_i, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0})),
	10, 1680,//Height & weight
	str_pokedex_data_337_page_0, str_pokedex_data_337_page_1,
	0,//unused
	300, 1,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 338
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_t, PCHAR_e, PCHAR_o, PCHAR_r, PCHAR_i, PCHAR_t, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_e, PCHAR_t, PCHAR_e, PCHAR_o, PCHAR_r, PCHAR_i, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0})),
	12, 1540,//Height & weight
	str_pokedex_data_338_page_0, str_pokedex_data_338_page_1,
	0,//unused
	328, 65533,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 339
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_r, PCHAR_t, PCHAR_h, PCHAR_a, PCHAR_a, PCHAR_r, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_h, PCHAR_i, PCHAR_s, PCHAR_k, PCHAR_e, PCHAR_r, PCHAR_s, 0xff, 0x0, 0x0, 0x0})),
	4, 19,//Height & weight
	str_pokedex_data_339_page_0, str_pokedex_data_339_page_1,
	0,//unused
	581, 65534,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 340
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_r, PCHAR_t, PCHAR_h, PCHAR_a, PCHAR_a, PCHAR_r, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_h, PCHAR_i, PCHAR_s, PCHAR_k, PCHAR_e, PCHAR_r, PCHAR_s, 0xff, 0x0, 0x0, 0x0})),
	9, 236,//Height & weight
	str_pokedex_data_340_page_0, str_pokedex_data_340_page_1,
	0,//unused
	317, 1,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 341
	PSTRING(P99_PROCTECT({PCHAR_G, PCHAR_r, PCHAR_o, PCHAR_b, PCHAR_i, PCHAR_a, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_u, PCHAR_f, PCHAR_f, PCHAR_i, PCHAR_a, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0})),
	6, 115,//Height & weight
	str_pokedex_data_341_page_0, str_pokedex_data_341_page_1,
	0,//unused
	484, 18,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 342
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_l, PCHAR_i, PCHAR_n, PCHAR_g, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_g, PCHAR_u, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	11, 328,//Height & weight
	str_pokedex_data_342_page_0, str_pokedex_data_342_page_1,
	0,//unused
	365, 7,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 343
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_e, PCHAR_h, PCHAR_m, PCHAR_p, PCHAR_u, PCHAR_p, PCHAR_p, PCHAR_e, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_l, PCHAR_a, PCHAR_y, PCHAR_SPACE, PCHAR_D, PCHAR_o, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0})),
	5, 215,//Height & weight
	str_pokedex_data_343_page_0, str_pokedex_data_343_page_1,
	0,//unused
	384, 18,//Pokemon scale, displacement
	256, 65533,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 344
	PSTRING(P99_PROCTECT({PCHAR_L, PCHAR_e, PCHAR_h, PCHAR_m, PCHAR_p, PCHAR_u, PCHAR_p, PCHAR_p, PCHAR_e, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_l, PCHAR_a, PCHAR_y, PCHAR_SPACE, PCHAR_D, PCHAR_o, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0})),
	15, 1080,//Height & weight
	str_pokedex_data_344_page_0, str_pokedex_data_344_page_1,
	0,//unused
	256, 3,//Pokemon scale, displacement
	280, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 345
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_a, PCHAR_n, PCHAR_e, PCHAR_m, PCHAR_o, PCHAR_n, PCHAR_e, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_a, PCHAR_SPACE, PCHAR_L, PCHAR_i, PCHAR_l, PCHAR_y, 0xff, 0x0, 0x0, 0x0})),
	10, 238,//Height & weight
	str_pokedex_data_345_page_0, str_pokedex_data_345_page_1,
	0,//unused
	305, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 346
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_a, PCHAR_n, PCHAR_k, PCHAR_f, PCHAR_ue, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_r, PCHAR_n, PCHAR_a, PCHAR_c, PCHAR_l, PCHAR_e, 0xff, 0x0, 0x0, 0x0})),
	15, 604,//Height & weight
	str_pokedex_data_346_page_0, str_pokedex_data_346_page_1,
	0,//unused
	275, 65535,//Pokemon scale, displacement
	269, 65535,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 347
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_r, PCHAR_e, PCHAR_b, PCHAR_s, PCHAR_s, PCHAR_e, PCHAR_n, PCHAR_i, PCHAR_o, PCHAR_r, 0xff}), P99_PROCTECT({PCHAR_O, PCHAR_l, PCHAR_d, PCHAR_SPACE, PCHAR_S, PCHAR_h, PCHAR_r, PCHAR_i, PCHAR_m, PCHAR_p, 0xff, 0x0})),
	7, 125,//Height & weight
	str_pokedex_data_347_page_0, str_pokedex_data_347_page_1,
	0,//unused
	296, 4,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 348
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_i, PCHAR_l, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_l, PCHAR_a, PCHAR_t, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	15, 682,//Height & weight
	str_pokedex_data_348_page_0, str_pokedex_data_348_page_1,
	0,//unused
	312, 2,//Pokemon scale, displacement
	271, 65535,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 349
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_s, PCHAR_c, PCHAR_h, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 74,//Height & weight
	str_pokedex_data_349_page_0, str_pokedex_data_349_page_1,
	0,//unused
	423, 3,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 350
	PSTRING(P99_PROCTECT({PCHAR_Z, PCHAR_a, PCHAR_r, PCHAR_t, PCHAR_h, PCHAR_e, PCHAR_i, PCHAR_t, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_T, PCHAR_e, PCHAR_n, PCHAR_d, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	62, 1620,//Height & weight
	str_pokedex_data_350_page_0, str_pokedex_data_350_page_1,
	0,//unused
	282, 65535,//Pokemon scale, displacement
	382, 7,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 351
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_e, PCHAR_t, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_e, PCHAR_a, PCHAR_t, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0, 0x0})),
	3, 8,//Height & weight
	str_pokedex_data_351_page_0, str_pokedex_data_351_page_1,
	0,//unused
	435, 65531,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 352
	PSTRING(P99_PROCTECT({PCHAR_F, PCHAR_a, PCHAR_r, PCHAR_b, PCHAR_e, PCHAR_n, PCHAR_s, PCHAR_p, PCHAR_i, PCHAR_e, PCHAR_l, 0xff}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_l, PCHAR_o, PCHAR_r, PCHAR_SPACE, PCHAR_S, PCHAR_w, PCHAR_a, PCHAR_p, 0xff, 0x0})),
	10, 220,//Height & weight
	str_pokedex_data_352_page_0, str_pokedex_data_352_page_1,
	0,//unused
	316, 8,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 353
	PSTRING(P99_PROCTECT({PCHAR_P, PCHAR_u, PCHAR_p, PCHAR_p, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_P, PCHAR_u, PCHAR_p, PCHAR_p, PCHAR_e, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 23,//Height & weight
	str_pokedex_data_353_page_0, str_pokedex_data_353_page_1,
	0,//unused
	440, 65533,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 354
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_r, PCHAR_i, PCHAR_o, PCHAR_n, PCHAR_e, PCHAR_t, PCHAR_t, PCHAR_e, 0xff, 0x0}), P99_PROCTECT({PCHAR_M, PCHAR_a, PCHAR_r, PCHAR_i, PCHAR_o, PCHAR_n, PCHAR_e, PCHAR_t, PCHAR_t, PCHAR_e, 0xff, 0x0})),
	11, 125,//Height & weight
	str_pokedex_data_354_page_0, str_pokedex_data_354_page_1,
	0,//unused
	262, 9,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 355
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_e, PCHAR_q, PCHAR_u, PCHAR_i, PCHAR_e, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_e, PCHAR_q, PCHAR_u, PCHAR_i, PCHAR_e, PCHAR_m, 0xff, 0x0, 0x0, 0x0, 0x0})),
	8, 150,//Height & weight
	str_pokedex_data_355_page_0, str_pokedex_data_355_page_1,
	0,//unused
	376, 13,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 356
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_n, PCHAR_k, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_e, PCHAR_c, PCHAR_k, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	16, 306,//Height & weight
	str_pokedex_data_356_page_0, str_pokedex_data_356_page_1,
	0,//unused
	256, 2,//Pokemon scale, displacement
	299, 2,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 357
	PSTRING(P99_PROCTECT({PCHAR_O, PCHAR_b, PCHAR_s, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_r, PCHAR_u, PCHAR_i, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	20, 1000,//Height & weight
	str_pokedex_data_357_page_0, str_pokedex_data_357_page_1,
	0,//unused
	283, 65535,//Pokemon scale, displacement
	371, 6,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 358
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_n, PCHAR_d, PCHAR_s, PCHAR_p, PCHAR_i, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_n, PCHAR_d, PCHAR_SPACE, PCHAR_C, PCHAR_h, PCHAR_i, PCHAR_m, PCHAR_e, 0xff, 0x0})),
	6, 10,//Height & weight
	str_pokedex_data_358_page_0, str_pokedex_data_358_page_1,
	0,//unused
	505, 65532,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 359
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_e, PCHAR_s, PCHAR_a, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_i, PCHAR_s, PCHAR_a, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0})),
	12, 470,//Height & weight
	str_pokedex_data_359_page_0, str_pokedex_data_359_page_1,
	0,//unused
	301, 1,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 360
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_r, PCHAR_a, PCHAR_h, PCHAR_l, PCHAR_e, PCHAR_k, PCHAR_i, PCHAR_n, PCHAR_d, 0xff}), P99_PROCTECT({PCHAR_B, PCHAR_r, PCHAR_i, PCHAR_g, PCHAR_h, PCHAR_t, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	6, 140,//Height & weight
	str_pokedex_data_360_page_0, str_pokedex_data_360_page_1,
	0,//unused
	453, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 361
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_c, PCHAR_h, PCHAR_n, PCHAR_e, PCHAR_e, PCHAR_h, PCHAR_u, PCHAR_t, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_n, PCHAR_o, PCHAR_w, PCHAR_SPACE, PCHAR_H, PCHAR_a, PCHAR_t, 0xff, 0x0, 0x0, 0x0})),
	7, 168,//Height & weight
	str_pokedex_data_361_page_0, str_pokedex_data_361_page_1,
	0,//unused
	380, 14,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 362
	PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_n, PCHAR_t, PCHAR_l, PCHAR_i, PCHAR_t, PCHAR_z, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_F, PCHAR_a, PCHAR_c, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	15, 2565,//Height & weight
	str_pokedex_data_362_page_0, str_pokedex_data_362_page_1,
	0,//unused
	256, 3,//Pokemon scale, displacement
	344, 2,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 363
	PSTRING(P99_PROCTECT({PCHAR_A, PCHAR_p, PCHAR_p, PCHAR_l, PCHAR_a, PCHAR_u, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_l, PCHAR_a, PCHAR_p, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	8, 395,//Height & weight
	str_pokedex_data_363_page_0, str_pokedex_data_363_page_1,
	0,//unused
	315, 15,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 364
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_p, PCHAR_i, PCHAR_e, PCHAR_l, PCHAR_b, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, PCHAR_SPACE, PCHAR_R, PCHAR_o, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0})),
	11, 876,//Height & weight
	str_pokedex_data_364_page_0, str_pokedex_data_364_page_1,
	0,//unused
	338, 12,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 365
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, PCHAR_b, PCHAR_r, PCHAR_e, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0x0}), P99_PROCTECT({PCHAR_I, PCHAR_c, PCHAR_e, PCHAR_SPACE, PCHAR_B, PCHAR_r, PCHAR_e, PCHAR_a, PCHAR_k, 0xff, 0x0, 0x0})),
	14, 1506,//Height & weight
	str_pokedex_data_365_page_0, str_pokedex_data_365_page_1,
	0,//unused
	305, 2,//Pokemon scale, displacement
	277, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 366
	PSTRING(P99_PROCTECT({PCHAR_M, PCHAR_u, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_l, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_B, PCHAR_i, PCHAR_v, PCHAR_a, PCHAR_l, PCHAR_v, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0})),
	4, 525,//Height & weight
	str_pokedex_data_366_page_0, str_pokedex_data_366_page_1,
	0,//unused
	691, 22,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 367
	PSTRING(P99_PROCTECT({PCHAR_T, PCHAR_i, PCHAR_e, PCHAR_f, PCHAR_s, PCHAR_e, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_e, PCHAR_e, PCHAR_p, PCHAR_SPACE, PCHAR_S, PCHAR_e, PCHAR_a, 0xff, 0x0, 0x0, 0x0})),
	17, 270,//Height & weight
	str_pokedex_data_367_page_0, str_pokedex_data_367_page_1,
	0,//unused
	307, 1,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 368
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_ue, PCHAR_d, PCHAR_s, PCHAR_e, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_o, PCHAR_u, PCHAR_t, PCHAR_h, PCHAR_SPACE, PCHAR_S, PCHAR_e, PCHAR_a, 0xff, 0x0, 0x0})),
	18, 226,//Height & weight
	str_pokedex_data_368_page_0, str_pokedex_data_368_page_1,
	0,//unused
	278, 5,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 369
	PSTRING(P99_PROCTECT({PCHAR_B, PCHAR_e, PCHAR_s, PCHAR_t, PCHAR_a, PCHAR_n, PCHAR_d, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_L, PCHAR_o, PCHAR_n, PCHAR_g, PCHAR_e, PCHAR_v, PCHAR_i, PCHAR_t, PCHAR_y, 0xff, 0x0, 0x0})),
	10, 234,//Height & weight
	str_pokedex_data_369_page_0, str_pokedex_data_369_page_1,
	0,//unused
	316, 5,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 370
	PSTRING(P99_PROCTECT({PCHAR_R, PCHAR_e, PCHAR_n, PCHAR_d, PCHAR_e, PCHAR_z, PCHAR_v, PCHAR_o, PCHAR_u, PCHAR_s, 0xff, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_e, PCHAR_n, PCHAR_d, PCHAR_e, PCHAR_z, PCHAR_v, PCHAR_o, PCHAR_u, PCHAR_s, 0xff, 0x0})),
	6, 87,//Height & weight
	str_pokedex_data_370_page_0, str_pokedex_data_370_page_1,
	0,//unused
	371, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 371
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, PCHAR_h, PCHAR_a, PCHAR_u, PCHAR_p, PCHAR_t, 0xff, 0x0}), P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_c, PCHAR_k, PCHAR_SPACE, PCHAR_H, PCHAR_e, PCHAR_a, PCHAR_d, 0xff, 0x0, 0x0})),
	6, 421,//Height & weight
	str_pokedex_data_371_page_0, str_pokedex_data_371_page_1,
	0,//unused
	448, 17,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 372
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_u, PCHAR_r, PCHAR_c, PCHAR_h, PCHAR_s, PCHAR_t, PCHAR_e, PCHAR_h, PCHAR_e, PCHAR_r, 0xff}), P99_PROCTECT({PCHAR_E, PCHAR_n, PCHAR_d, PCHAR_u, PCHAR_r, PCHAR_a, PCHAR_n, PCHAR_c, PCHAR_e, 0xff, 0x0, 0x0})),
	11, 1105,//Height & weight
	str_pokedex_data_372_page_0, str_pokedex_data_372_page_1,
	0,//unused
	311, 10,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 373
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_c, PCHAR_h, PCHAR_e, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_r, PCHAR_a, PCHAR_g, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0})),
	15, 1026,//Height & weight
	str_pokedex_data_373_page_0, str_pokedex_data_373_page_1,
	0,//unused
	272, 2,//Pokemon scale, displacement
	307, 0,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 374
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, PCHAR_e, PCHAR_n, PCHAR_k, PCHAR_u, PCHAR_g, PCHAR_e, PCHAR_l, 0xff, 0x0}), P99_PROCTECT({PCHAR_I, PCHAR_r, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_l, PCHAR_l, 0xff, 0x0, 0x0})),
	6, 952,//Height & weight
	str_pokedex_data_374_page_0, str_pokedex_data_374_page_1,
	0,//unused
	414, 65535,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 375
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, PCHAR_e, PCHAR_n, PCHAR_k, PCHAR_l, PCHAR_a, PCHAR_u, PCHAR_e, 0xff, 0x0}), P99_PROCTECT({PCHAR_I, PCHAR_r, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_C, PCHAR_l, PCHAR_a, PCHAR_w, 0xff, 0x0, 0x0})),
	12, 2025,//Height & weight
	str_pokedex_data_375_page_0, str_pokedex_data_375_page_1,
	0,//unused
	256, 3,//Pokemon scale, displacement
	272, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 376
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, PCHAR_e, PCHAR_n, PCHAR_f, PCHAR_u, PCHAR_s, PCHAR_s, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_I, PCHAR_r, PCHAR_o, PCHAR_n, PCHAR_SPACE, PCHAR_L, PCHAR_e, PCHAR_g, 0xff, 0x0, 0x0, 0x0})),
	16, 5500,//Height & weight
	str_pokedex_data_376_page_0, str_pokedex_data_376_page_1,
	0,//unused
	272, 3,//Pokemon scale, displacement
	461, 4,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 377
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_t, PCHAR_e, PCHAR_i, PCHAR_n, PCHAR_g, PCHAR_i, PCHAR_p, PCHAR_f, PCHAR_e, PCHAR_l, 0xff}), P99_PROCTECT({PCHAR_R, PCHAR_o, PCHAR_c, PCHAR_k, PCHAR_SPACE, PCHAR_P, PCHAR_e, PCHAR_a, PCHAR_k, 0xff, 0x0, 0x0})),
	17, 2300,//Height & weight
	str_pokedex_data_377_page_0, str_pokedex_data_377_page_1,
	0,//unused
	256, 1,//Pokemon scale, displacement
	309, 1,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 378
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_I, PCHAR_c, PCHAR_e, PCHAR_b, PCHAR_e, PCHAR_r, PCHAR_g, 0xff, 0x0, 0x0, 0x0, 0x0})),
	18, 1750,//Height & weight
	str_pokedex_data_378_page_0, str_pokedex_data_378_page_1,
	0,//unused
	265, 0,//Pokemon scale, displacement
	317, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 379
	PSTRING(P99_PROCTECT({PCHAR_E, PCHAR_i, PCHAR_s, PCHAR_e, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_I, PCHAR_r, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	19, 2050,//Height & weight
	str_pokedex_data_379_page_0, str_pokedex_data_379_page_1,
	0,//unused
	256, 0,//Pokemon scale, displacement
	359, 6,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 380
	PSTRING(P99_PROCTECT({PCHAR_ae, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	14, 400,//Height & weight
	str_pokedex_data_380_page_0, str_pokedex_data_380_page_1,
	0,//unused
	291, 2,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 381
	PSTRING(P99_PROCTECT({PCHAR_ae, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_E, PCHAR_o, PCHAR_n, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	20, 600,//Height & weight
	str_pokedex_data_381_page_0, str_pokedex_data_381_page_1,
	0,//unused
	273, 0,//Pokemon scale, displacement
	313, 3,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 382
	PSTRING(P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_e, PCHAR_g, PCHAR_r, PCHAR_ue, PCHAR_n, PCHAR_d, PCHAR_l, PCHAR_e, PCHAR_r, 0xff}), P99_PROCTECT({PCHAR_S, PCHAR_e, PCHAR_a, PCHAR_SPACE, PCHAR_B, PCHAR_a, PCHAR_s, PCHAR_i, PCHAR_n, 0xff, 0x0, 0x0})),
	45, 3520,//Height & weight
	str_pokedex_data_382_page_0, str_pokedex_data_382_page_1,
	0,//unused
	272, 1,//Pokemon scale, displacement
	639, 13,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 383
	PSTRING(P99_PROCTECT({PCHAR_K, PCHAR_o, PCHAR_n, PCHAR_t, PCHAR_i, PCHAR_n, PCHAR_e, PCHAR_n, PCHAR_t, 0xff, 0x0, 0x0}), P99_PROCTECT({PCHAR_C, PCHAR_o, PCHAR_n, PCHAR_t, PCHAR_i, PCHAR_n, PCHAR_e, PCHAR_n, PCHAR_t, 0xff, 0x0, 0x0})),
	35, 9500,//Height & weight
	str_pokedex_data_383_page_0, str_pokedex_data_383_page_1,
	0,//unused
	276, 0,//Pokemon scale, displacement
	530, 12,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 384
	PSTRING(P99_PROCTECT({PCHAR_H, PCHAR_i, PCHAR_m, PCHAR_m, PCHAR_e, PCHAR_l, PCHAR_h, PCHAR_o, PCHAR_c, PCHAR_h, 0xff, 0x0}), P99_PROCTECT({PCHAR_S, PCHAR_k, PCHAR_y, PCHAR_SPACE, PCHAR_H, PCHAR_i, PCHAR_g, PCHAR_h, 0xff, 0x0, 0x0, 0x0})),
	70, 2065,//Height & weight
	str_pokedex_data_384_page_0, str_pokedex_data_384_page_1,
	0,//unused
	286, 65535,//Pokemon scale, displacement
	483, 9,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 385
	PSTRING(P99_PROCTECT({PCHAR_W, PCHAR_ue, PCHAR_n, PCHAR_s, PCHAR_c, PCHAR_h, PCHAR_e, PCHAR_r, 0xff, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_W, PCHAR_i, PCHAR_s, PCHAR_h, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	3, 11,//Height & weight
	str_pokedex_data_385_page_0, str_pokedex_data_385_page_1,
	0,//unused
	608, 65528,//Pokemon scale, displacement
	256, 65534,//Trainer scale, displacement
	0,//unused
},
{
	//Entry 386
	PSTRING(P99_PROCTECT({PCHAR_D, PCHAR_n, PCHAR_s, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}), P99_PROCTECT({PCHAR_D, PCHAR_n, PCHAR_a, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0})),
	17, 608,//Height & weight
	str_pokedex_data_386_page_0, str_pokedex_data_386_page_1,
	0,//unused
	293, 0,//Pokemon scale, displacement
	337, 2,//Trainer scale, displacement
	0,//unused
}

};
