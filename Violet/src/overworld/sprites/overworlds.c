#include "types.h"
#include "overworld/sprite.h"
#include "oam.h" 
#include "vars.h"
#include "debug.h"
#include "berry.h"

static graphic overworld_sprite_deoxys_normal_sprites[] = {
	{&gfx_ow_deoxys_normal_0Tiles, 0x200, 0},
	{&gfx_ow_deoxys_normal_1Tiles, 0x200, 0},
	{&gfx_ow_deoxys_normal_2Tiles, 0x200, 0},
	{&gfx_ow_deoxys_normal_3Tiles, 0x200, 0},
	{&gfx_ow_deoxys_normal_4Tiles, 0x200, 0},
	{&gfx_ow_deoxys_normal_5Tiles, 0x200, 0},
	{&gfx_ow_deoxys_normal_6Tiles, 0x200, 0},
	{&gfx_ow_deoxys_normal_7Tiles, 0x200, 0},
	{&gfx_ow_deoxys_normal_8Tiles, 0x200, 0}
};

overworld_sprite ow_deoxys_normal = {
	0xffff, 0x1103, 0x11ff, 0x200,
	32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
	&ow_final_oam_32_32, &ow_formation_32_32,
	ow_anim_standard_npc, overworld_sprite_deoxys_normal_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_registeel_sprites[] = {
	{&gfx_ow_registeel_0Tiles, 0x200, 0},
	{&gfx_ow_registeel_1Tiles, 0x200, 0},
	{&gfx_ow_registeel_2Tiles, 0x200, 0},
	{&gfx_ow_registeel_3Tiles, 0x200, 0},
	{&gfx_ow_registeel_4Tiles, 0x200, 0},
	{&gfx_ow_registeel_5Tiles, 0x200, 0},
	{&gfx_ow_registeel_6Tiles, 0x200, 0},
	{&gfx_ow_registeel_7Tiles, 0x200, 0},
	{&gfx_ow_registeel_8Tiles, 0x200, 0}
};

overworld_sprite ow_registeel = {
	0xffff, 0x1104, 0x11ff, 0x200,
	32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_32_32, &ow_formation_32_32,
	ow_anim_standard_npc, overworld_sprite_registeel_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_regice_sprites[] = {
	{&gfx_ow_regice_0Tiles, 0x200, 0},
	{&gfx_ow_regice_1Tiles, 0x200, 0},
	{&gfx_ow_regice_2Tiles, 0x200, 0},
	{&gfx_ow_regice_3Tiles, 0x200, 0},
	{&gfx_ow_regice_4Tiles, 0x200, 0},
	{&gfx_ow_regice_5Tiles, 0x200, 0},
	{&gfx_ow_regice_6Tiles, 0x200, 0},
	{&gfx_ow_regice_7Tiles, 0x200, 0},
	{&gfx_ow_regice_8Tiles, 0x200, 0}
};

overworld_sprite ow_regice = {
	0xffff, 0x1104, 0x11ff, 0x200,
	32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_32_32, &ow_formation_32_32,
	ow_anim_standard_npc, overworld_sprite_regice_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_regirock_sprites[] = {
	{&gfx_ow_regirock_0Tiles, 0x200, 0},
	{&gfx_ow_regirock_1Tiles, 0x200, 0},
	{&gfx_ow_regirock_2Tiles, 0x200, 0},
	{&gfx_ow_regirock_3Tiles, 0x200, 0},
	{&gfx_ow_regirock_4Tiles, 0x200, 0},
	{&gfx_ow_regirock_5Tiles, 0x200, 0},
	{&gfx_ow_regirock_6Tiles, 0x200, 0},
	{&gfx_ow_regirock_7Tiles, 0x200, 0},
	{&gfx_ow_regirock_8Tiles, 0x200, 0}
};

overworld_sprite ow_regirock = {
	0xffff, 0x1106, 0x11ff, 0x200,
	32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_32_32, &ow_formation_32_32,
	ow_anim_standard_npc, overworld_sprite_regirock_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_voltilamm_sprites[] = {
	{&gfx_ow_voltilamm_0Tiles, 0x100, 0},
	{&gfx_ow_voltilamm_1Tiles, 0x100, 0},
	{&gfx_ow_voltilamm_2Tiles, 0x100, 0},
	{&gfx_ow_voltilamm_3Tiles, 0x100, 0},
	{&gfx_ow_voltilamm_4Tiles, 0x100, 0},
	{&gfx_ow_voltilamm_5Tiles, 0x100, 0},
	{&gfx_ow_voltilamm_6Tiles, 0x100, 0},
	{&gfx_ow_voltilamm_7Tiles, 0x100, 0},
	{&gfx_ow_voltilamm_8Tiles, 0x100, 0}
};

overworld_sprite ow_voltilamm = {
	0xffff, 0x1103, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_voltilamm_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_staralili_sprites[] = {
	{&gfx_ow_staralili_0Tiles, 0x80, 0},
	{&gfx_ow_staralili_1Tiles, 0x80, 0},
	{&gfx_ow_staralili_2Tiles, 0x80, 0},
	{&gfx_ow_staralili_3Tiles, 0x80, 0},
	{&gfx_ow_staralili_4Tiles, 0x80, 0},
	{&gfx_ow_staralili_5Tiles, 0x80, 0},
	{&gfx_ow_staralili_6Tiles, 0x80, 0},
	{&gfx_ow_staralili_7Tiles, 0x80, 0},
	{&gfx_ow_staralili_8Tiles, 0x80, 0}
};

overworld_sprite ow_staralili = {
	0xffff, 0x1106, 0x11ff, 0x80,
	16, 16, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_16, &ow_formation_16_16,
	ow_anim_standard_npc, overworld_sprite_staralili_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_larissa_sprites[] = {
	{&gfx_ow_larissa_0Tiles, 0x100, 0},
	{&gfx_ow_larissa_1Tiles, 0x100, 0},
	{&gfx_ow_larissa_2Tiles, 0x100, 0},
	{&gfx_ow_larissa_3Tiles, 0x100, 0},
	{&gfx_ow_larissa_4Tiles, 0x100, 0},
	{&gfx_ow_larissa_5Tiles, 0x100, 0},
	{&gfx_ow_larissa_6Tiles, 0x100, 0},
	{&gfx_ow_larissa_7Tiles, 0x100, 0},
	{&gfx_ow_larissa_8Tiles, 0x100, 0}
};

overworld_sprite ow_larissa = {
	0xffff, 0x1106, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_larissa_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_elise_sprites[] = {
	{&gfx_ow_elise_0Tiles, 0x100, 0},
	{&gfx_ow_elise_1Tiles, 0x100, 0},
	{&gfx_ow_elise_2Tiles, 0x100, 0},
	{&gfx_ow_elise_3Tiles, 0x100, 0},
	{&gfx_ow_elise_4Tiles, 0x100, 0},
	{&gfx_ow_elise_5Tiles, 0x100, 0},
	{&gfx_ow_elise_6Tiles, 0x100, 0},
	{&gfx_ow_elise_7Tiles, 0x100, 0},
	{&gfx_ow_elise_8Tiles, 0x100, 0}
};

overworld_sprite ow_elise = {
	0xffff, 0x1103, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_elise_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_faun_young_sprites[] = {
	{&gfx_ow_faun_young_0Tiles, 0x100, 0},
	{&gfx_ow_faun_young_1Tiles, 0x100, 0},
	{&gfx_ow_faun_young_2Tiles, 0x100, 0},
	{&gfx_ow_faun_young_3Tiles, 0x100, 0},
	{&gfx_ow_faun_young_4Tiles, 0x100, 0},
	{&gfx_ow_faun_young_5Tiles, 0x100, 0},
	{&gfx_ow_faun_young_6Tiles, 0x100, 0},
	{&gfx_ow_faun_young_7Tiles, 0x100, 0},
	{&gfx_ow_faun_young_8Tiles, 0x100, 0}
};

overworld_sprite ow_faun_young = {
	0xffff, 0x1105, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_faun_young_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_egg_sprites[] = {
	{&gfx_ow_egg_0Tiles, 0x80, 0},
	{&gfx_ow_egg_0Tiles, 0x80, 0},
	{&gfx_ow_egg_0Tiles, 0x80, 0},
	{&gfx_ow_egg_0Tiles, 0x80, 0},
	{&gfx_ow_egg_0Tiles, 0x80, 0},
	{&gfx_ow_egg_0Tiles, 0x80, 0},
	{&gfx_ow_egg_0Tiles, 0x80, 0},
	{&gfx_ow_egg_0Tiles, 0x80, 0},
};

overworld_sprite ow_egg = {
	0xffff, 0x1105, 0x11ff, 0x80,
	16, 16, 0, 1, 1, 0, 0x0, 0x0, 0x0,
	&ow_final_oam_16_16, &ow_formation_16_16,
	ow_anim_none, overworld_sprite_egg_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_rin_sprites[] = {
	{&gfx_ow_rin_0Tiles, 0x100, 0},
	{&gfx_ow_rin_1Tiles, 0x100, 0},
	{&gfx_ow_rin_2Tiles, 0x100, 0},
	{&gfx_ow_rin_3Tiles, 0x100, 0},
	{&gfx_ow_rin_4Tiles, 0x100, 0},
	{&gfx_ow_rin_5Tiles, 0x100, 0},
	{&gfx_ow_rin_6Tiles, 0x100, 0},
	{&gfx_ow_rin_7Tiles, 0x100, 0},
	{&gfx_ow_rin_8Tiles, 0x100, 0}
};

overworld_sprite ow_rin = {
	0xffff, 0x110b, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_rin_sprites, 
	oam_rotscale_anim_table_null
};
static graphic overworld_sprite_blaise_sprites[] = {
	{&gfx_ow_blaise_0Tiles, 0x100, 0},
	{&gfx_ow_blaise_1Tiles, 0x100, 0},
	{&gfx_ow_blaise_2Tiles, 0x100, 0},
	{&gfx_ow_blaise_3Tiles, 0x100, 0},
	{&gfx_ow_blaise_4Tiles, 0x100, 0},
	{&gfx_ow_blaise_5Tiles, 0x100, 0},
	{&gfx_ow_blaise_6Tiles, 0x100, 0},
	{&gfx_ow_blaise_7Tiles, 0x100, 0},
	{&gfx_ow_blaise_8Tiles, 0x100, 0}
};

overworld_sprite ow_blaise = {
	0xffff, 0x1103, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_blaise_sprites, 
	oam_rotscale_anim_table_null
};
static graphic overworld_sprite_mia_sprites[] = {
	{&gfx_ow_mia_0Tiles, 0x100, 0},
	{&gfx_ow_mia_1Tiles, 0x100, 0},
	{&gfx_ow_mia_2Tiles, 0x100, 0},
	{&gfx_ow_mia_3Tiles, 0x100, 0},
	{&gfx_ow_mia_4Tiles, 0x100, 0},
	{&gfx_ow_mia_5Tiles, 0x100, 0},
	{&gfx_ow_mia_6Tiles, 0x100, 0},
	{&gfx_ow_mia_7Tiles, 0x100, 0},
	{&gfx_ow_mia_8Tiles, 0x100, 0}
};

overworld_sprite ow_mia = {
	0xffff, 0x1105, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_mia_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_lester_sprites[] = {
	{gfx_ow_lesterTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lesterTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lesterTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lesterTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lesterTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lesterTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lesterTiles + 6 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lesterTiles + 7 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lesterTiles + 8 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
};

overworld_sprite ow_lester = {
	0xffff, 0x1106, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_lester_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_faun_sprites[] = {
	{&gfx_ow_faun_0Tiles, 0x100, 0},
	{&gfx_ow_faun_1Tiles, 0x100, 0},
	{&gfx_ow_faun_2Tiles, 0x100, 0},
	{&gfx_ow_faun_3Tiles, 0x100, 0},
	{&gfx_ow_faun_4Tiles, 0x100, 0},
	{&gfx_ow_faun_5Tiles, 0x100, 0},
	{&gfx_ow_faun_6Tiles, 0x100, 0},
	{&gfx_ow_faun_7Tiles, 0x100, 0},
	{&gfx_ow_faun_8Tiles, 0x100, 0}
};

overworld_sprite ow_faun = {
	0xffff, 0x1106, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_faun_sprites, 
	oam_rotscale_anim_table_null
};
static graphic overworld_sprite_revolutionary_sprites[] = {
	{&gfx_ow_revolutionary_0Tiles, 0x100, 0},
	{&gfx_ow_revolutionary_1Tiles, 0x100, 0},
	{&gfx_ow_revolutionary_2Tiles, 0x100, 0},
	{&gfx_ow_revolutionary_3Tiles, 0x100, 0},
	{&gfx_ow_revolutionary_4Tiles, 0x100, 0},
	{&gfx_ow_revolutionary_5Tiles, 0x100, 0},
	{&gfx_ow_revolutionary_6Tiles, 0x100, 0},
	{&gfx_ow_revolutionary_7Tiles, 0x100, 0},
	{&gfx_ow_revolutionary_8Tiles, 0x100, 0}
};

overworld_sprite ow_revolutionary = {
	0xffff, 0x1105, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_revolutionary_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_rival_sprites[] = {
	{&gfx_ow_rival_0Tiles, 0x100, 0},
	{&gfx_ow_rival_1Tiles, 0x100, 0},
	{&gfx_ow_rival_2Tiles, 0x100, 0},
	{&gfx_ow_rival_3Tiles, 0x100, 0},
	{&gfx_ow_rival_4Tiles, 0x100, 0},
	{&gfx_ow_rival_5Tiles, 0x100, 0},
	{&gfx_ow_rival_6Tiles, 0x100, 0},
	{&gfx_ow_rival_7Tiles, 0x100, 0},
	{&gfx_ow_rival_8Tiles, 0x100, 0}
};

overworld_sprite ow_rival = {
	0xffff, 0x1103, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_rival_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_rival_beaten_sprites[] = {
	{&gfx_ow_rival_beatenTiles, GRAPHIC_SIZE_4BPP(32, 32), 0},
	{&gfx_ow_rival_beatenTiles, GRAPHIC_SIZE_4BPP(32, 32), 0},
	{&gfx_ow_rival_beatenTiles, GRAPHIC_SIZE_4BPP(32, 32), 0},
	{&gfx_ow_rival_beatenTiles, GRAPHIC_SIZE_4BPP(32, 32), 0},
	{&gfx_ow_rival_beatenTiles, GRAPHIC_SIZE_4BPP(32, 32), 0},
	{&gfx_ow_rival_beatenTiles, GRAPHIC_SIZE_4BPP(32, 32), 0},
	{&gfx_ow_rival_beatenTiles, GRAPHIC_SIZE_4BPP(32, 32), 0},
	{&gfx_ow_rival_beatenTiles, GRAPHIC_SIZE_4BPP(32, 32), 0},
	{&gfx_ow_rival_beatenTiles, GRAPHIC_SIZE_4BPP(32, 32), 0},
};

overworld_sprite ow_rival_beaten = {
	0xFFFF, 0x1103, 0x11ff, GRAPHIC_SIZE_4BPP(32, 32),
	32, 32, 0, 1, 1, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_32_32, &ow_formation_32_32,
	ow_anim_standard_npc, overworld_sprite_rival_beaten_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_tann_sprites[] = {
	{&gfx_ow_tann_0Tiles, 0x100, 0},
	{&gfx_ow_tann_1Tiles, 0x100, 0},
	{&gfx_ow_tann_2Tiles, 0x100, 0},
	{&gfx_ow_tann_3Tiles, 0x100, 0},
	{&gfx_ow_tann_4Tiles, 0x100, 0},
	{&gfx_ow_tann_5Tiles, 0x100, 0},
	{&gfx_ow_tann_6Tiles, 0x100, 0},
	{&gfx_ow_tann_7Tiles, 0x100, 0},
	{&gfx_ow_tann_8Tiles, 0x100, 0}
};

overworld_sprite ow_tann = {
	0xffff, 0x1106, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_tann_sprites, 
	oam_rotscale_anim_table_null
};
static graphic overworld_sprite_felix_sprites[] = {
	{&gfx_ow_felix_0Tiles, 0x100, 0},
	{&gfx_ow_felix_1Tiles, 0x100, 0},
	{&gfx_ow_felix_2Tiles, 0x100, 0},
	{&gfx_ow_felix_3Tiles, 0x100, 0},
	{&gfx_ow_felix_4Tiles, 0x100, 0},
	{&gfx_ow_felix_5Tiles, 0x100, 0},
	{&gfx_ow_felix_6Tiles, 0x100, 0},
	{&gfx_ow_felix_7Tiles, 0x100, 0},
	{&gfx_ow_felix_8Tiles, 0x100, 0}
};

overworld_sprite ow_felix = {
	0xffff, 0x1103, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x9,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_felix_sprites, 
	oam_rotscale_anim_table_null
};
static graphic overworld_sprite_albus_sprites[] = {
	{&gfx_ow_albus_0Tiles, 0x100, 0},
	{&gfx_ow_albus_1Tiles, 0x100, 0},
	{&gfx_ow_albus_2Tiles, 0x100, 0},
	{&gfx_ow_albus_3Tiles, 0x100, 0},
	{&gfx_ow_albus_4Tiles, 0x100, 0},
	{&gfx_ow_albus_5Tiles, 0x100, 0},
	{&gfx_ow_albus_6Tiles, 0x100, 0},
	{&gfx_ow_albus_7Tiles, 0x100, 0},
	{&gfx_ow_albus_8Tiles, 0x100, 0}
};

overworld_sprite ow_albus = {
	0xffff, 0x1105, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_albus_sprites, 
	oam_rotscale_anim_table_null
};
static graphic overworld_sprite_violet_grunt_f_sprites[] = {
	{&gfx_ow_violet_grunt_f_0Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_f_1Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_f_2Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_f_3Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_f_4Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_f_5Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_f_6Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_f_7Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_f_8Tiles, 0x100, 0}
};

overworld_sprite ow_violet_grunt_f = {
	0xffff, 0x110b, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_violet_grunt_f_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_violet_grunt_m_sprites[] = {
	{&gfx_ow_violet_grunt_m_0Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_m_1Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_m_2Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_m_3Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_m_4Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_m_5Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_m_6Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_m_7Tiles, 0x100, 0},
	{&gfx_ow_violet_grunt_m_8Tiles, 0x100, 0}
};

overworld_sprite ow_violet_grunt_m = {
	0xffff, 0x110b, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_violet_grunt_m_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_primus_sprites[] = {
	{&gfx_ow_primus_0Tiles, 0x100, 0},
	{&gfx_ow_primus_1Tiles, 0x100, 0},
	{&gfx_ow_primus_2Tiles, 0x100, 0},
	{&gfx_ow_primus_3Tiles, 0x100, 0},
	{&gfx_ow_primus_4Tiles, 0x100, 0},
	{&gfx_ow_primus_5Tiles, 0x100, 0},
	{&gfx_ow_primus_6Tiles, 0x100, 0},
	{&gfx_ow_primus_7Tiles, 0x100, 0},
	{&gfx_ow_primus_8Tiles, 0x100, 0}
};

overworld_sprite ow_primus = {
	0xffff, 0x1105, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_primus_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_hiro_call_bike_sprites[] = {
	{&gfx_ow_hiro_call_bike_0Tiles, 0x200, 0},
	{&gfx_ow_hiro_call_bike_1Tiles, 0x200, 0},
	{&gfx_ow_hiro_call_bike_2Tiles, 0x200, 0},
	{&gfx_ow_hiro_call_bike_3Tiles, 0x200, 0},
	{&gfx_ow_hiro_call_bike_4Tiles, 0x200, 0},
	{&gfx_ow_hiro_call_bike_5Tiles, 0x200, 0}
};

overworld_sprite ow_hiro_call_bike = {
	0xffff, 0x1109, 0x1102, 0x200,
	32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_32_32, &ow_formation_32_32,
	ow_anim_hiro_bike, overworld_sprite_hiro_call_bike_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_hiro_call2_sprites[] = {
	{&gfx_ow_hiro_call2_0Tiles, 0x100, 0},
	{&gfx_ow_hiro_call2_1Tiles, 0x100, 0},
	{&gfx_ow_hiro_call2_2Tiles, 0x100, 0},
	{&gfx_ow_hiro_call2_3Tiles, 0x100, 0},
	{&gfx_ow_hiro_call2_4Tiles, 0x100, 0},
	{&gfx_ow_hiro_call2_5Tiles, 0x100, 0},
	{&gfx_ow_hiro_call2_6Tiles, 0x100, 0},
	{&gfx_ow_hiro_call2_7Tiles, 0x100, 0},
	{&gfx_ow_hiro_call2_8Tiles, 0x100, 0}
};

overworld_sprite ow_hiro_call2 = {
	0xffff, 0x1100, 0x1102, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_hiro_call2, overworld_sprite_hiro_call2_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_hiro_rod_sprites[] = {
	{&gfx_ow_hiro_rod_0Tiles, 0x200, 0},
	{&gfx_ow_hiro_rod_1Tiles, 0x200, 0},
	{&gfx_ow_hiro_rod_2Tiles, 0x200, 0},
	{&gfx_ow_hiro_rod_3Tiles, 0x200, 0},
	{&gfx_ow_hiro_rod_4Tiles, 0x200, 0},
	{&gfx_ow_hiro_rod_5Tiles, 0x200, 0},
	{&gfx_ow_hiro_rod_6Tiles, 0x200, 0},
	{&gfx_ow_hiro_rod_7Tiles, 0x200, 0},
	{&gfx_ow_hiro_rod_8Tiles, 0x200, 0},
	{&gfx_ow_hiro_rod_9Tiles, 0x200, 0},
	{&gfx_ow_hiro_rod_10Tiles, 0x200, 0},
	{&gfx_ow_hiro_rod_11Tiles, 0x200, 0}
};

overworld_sprite ow_hiro_rod = {
	0xffff, 0x1100, 0x1102, 0x200,
	32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_32_32, &ow_formation_32_32,
	ow_anim_hiro_rod, overworld_sprite_hiro_rod_sprites, 
	oam_rotscale_anim_table_null
};


static graphic overworld_sprite_hiroine_rod_sprites[] = {
	{&gfx_ow_hiroine_rod_0Tiles, 0x200, 0},
	{&gfx_ow_hiroine_rod_1Tiles, 0x200, 0},
	{&gfx_ow_hiroine_rod_2Tiles, 0x200, 0},
	{&gfx_ow_hiroine_rod_3Tiles, 0x200, 0},
	{&gfx_ow_hiroine_rod_4Tiles, 0x200, 0},
	{&gfx_ow_hiroine_rod_5Tiles, 0x200, 0},
	{&gfx_ow_hiroine_rod_6Tiles, 0x200, 0},
	{&gfx_ow_hiroine_rod_7Tiles, 0x200, 0},
	{&gfx_ow_hiroine_rod_8Tiles, 0x200, 0},
	{&gfx_ow_hiroine_rod_9Tiles, 0x200, 0},
	{&gfx_ow_hiroine_rod_10Tiles, 0x200, 0},
	{&gfx_ow_hiroine_rod_11Tiles, 0x200, 0}
};

overworld_sprite ow_hiroine_rod = {
	0xffff, 0x1100, 0x1102, 0x200,
	32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_32_32, &ow_formation_32_32,
	ow_anim_hiro_rod, overworld_sprite_hiroine_rod_sprites, 
	oam_rotscale_anim_table_null
};


static graphic overworld_sprite_hiro_call_sprites[] = {
	{&gfx_ow_hiro_call_0Tiles, 0x100, 0},
	{&gfx_ow_hiro_call_1Tiles, 0x100, 0},
	{&gfx_ow_hiro_call_2Tiles, 0x100, 0},
	{&gfx_ow_hiro_call_3Tiles, 0x100, 0},
	{&gfx_ow_hiro_call_4Tiles, 0x100, 0},
	{&gfx_ow_hiro_call_5Tiles, 0x100, 0},
	{&gfx_ow_hiro_call_6Tiles, 0x100, 0},
	{&gfx_ow_hiro_call_7Tiles, 0x100, 0},
	{&gfx_ow_hiro_call_8Tiles, 0x100, 0}
};

overworld_sprite ow_hiro_call = {
	0xffff, 0x1100, 0x1102, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_hiro_call, overworld_sprite_hiro_call_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_hiroine_call_sprites[] = {
	{&gfx_ow_hiroine_call_0Tiles, 0x100, 0},
	{&gfx_ow_hiroine_call_1Tiles, 0x100, 0},
	{&gfx_ow_hiroine_call_2Tiles, 0x100, 0},
	{&gfx_ow_hiroine_call_3Tiles, 0x100, 0},
	{&gfx_ow_hiroine_call_4Tiles, 0x100, 0},
	{&gfx_ow_hiroine_call_5Tiles, 0x100, 0},
	{&gfx_ow_hiroine_call_3Tiles, 0x100, 0},
	{&gfx_ow_hiroine_call_4Tiles, 0x100, 0},
	{&gfx_ow_hiroine_call_5Tiles, 0x100, 0}
};

overworld_sprite ow_hiroine_call = {
	0xffff, 0x1100, 0x1102, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_hiro_call, overworld_sprite_hiroine_call_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_hiro_sit_sprites[] = {
	{&gfx_ow_hiro_sit_0Tiles, 0x100, 0},
	{&gfx_ow_hiro_sit_1Tiles, 0x100, 0},
	{&gfx_ow_hiro_sit_2Tiles, 0x100, 0},
	{&gfx_ow_hiro_sit_3Tiles, 0x100, 0},
	{&gfx_ow_hiro_sit_4Tiles, 0x100, 0},
	{&gfx_ow_hiro_sit_5Tiles, 0x100, 0},
	{&gfx_ow_hiro_sit_6Tiles, 0x100, 0},
	{&gfx_ow_hiro_sit_7Tiles, 0x100, 0},
	{&gfx_ow_hiro_sit_8Tiles, 0x100, 0},
	{&gfx_ow_hiro_sit_9Tiles, 0x100, 0},
	{&gfx_ow_hiro_sit_10Tiles, 0x100, 0},
	{&gfx_ow_hiro_sit_11Tiles, 0x100, 0}
};

overworld_sprite ow_hiro_sit = {
	0xffff, 0x1100, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_hiro_sit, overworld_sprite_hiro_sit_sprites, 
	oam_rotscale_anim_table_null
};


static graphic overworld_sprite_hiroine_sit_sprites[] = {
	{&gfx_ow_hiroine_sit_0Tiles, 0x100, 0},
	{&gfx_ow_hiroine_sit_1Tiles, 0x100, 0},
	{&gfx_ow_hiroine_sit_2Tiles, 0x100, 0},
	{&gfx_ow_hiroine_sit_0Tiles, 0x100, 0},
	{&gfx_ow_hiroine_sit_0Tiles, 0x100, 0},
	{&gfx_ow_hiroine_sit_1Tiles, 0x100, 0},
	{&gfx_ow_hiroine_sit_1Tiles, 0x100, 0},
	{&gfx_ow_hiroine_sit_2Tiles, 0x100, 0},
	{&gfx_ow_hiroine_sit_2Tiles, 0x100, 0},
	{&gfx_ow_hiroine_sit_0Tiles, 0x100, 0},
	{&gfx_ow_hiroine_sit_1Tiles, 0x100, 0},
	{&gfx_ow_hiroine_sit_2Tiles, 0x100, 0}
};


overworld_sprite ow_hiroine_sit = {
	0xffff, 0x1110, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_hiro_sit, overworld_sprite_hiroine_sit_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_hiro_sprites[] = {
	{&gfx_ow_hiro_0Tiles, 0x200, 0},
	{&gfx_ow_hiro_1Tiles, 0x200, 0},
	{&gfx_ow_hiro_2Tiles, 0x200, 0},
	{&gfx_ow_hiro_3Tiles, 0x200, 0},
	{&gfx_ow_hiro_4Tiles, 0x200, 0},
	{&gfx_ow_hiro_5Tiles, 0x200, 0},
	{&gfx_ow_hiro_6Tiles, 0x200, 0},
	{&gfx_ow_hiro_7Tiles, 0x200, 0},
	{&gfx_ow_hiro_8Tiles, 0x200, 0},
	{&gfx_ow_hiro_9Tiles, 0x200, 0},
	{&gfx_ow_hiro_10Tiles, 0x200, 0},
	{&gfx_ow_hiro_11Tiles, 0x200, 0},
	{&gfx_ow_hiro_12Tiles, 0x200, 0},
	{&gfx_ow_hiro_13Tiles, 0x200, 0},
	{&gfx_ow_hiro_14Tiles, 0x200, 0},
	{&gfx_ow_hiro_15Tiles, 0x200, 0},
	{&gfx_ow_hiro_16Tiles, 0x200, 0},
	{&gfx_ow_hiro_17Tiles, 0x200, 0},
	{&gfx_ow_hiro_18Tiles, 0x200, 0},
	{&gfx_ow_hiro_19Tiles, 0x200, 0}
};

overworld_sprite ow_hiro = {
	0xffff, 0x1100, 0x1102, 0x200,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_hiro, overworld_sprite_hiro_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_mskate_sprites[] = {
    {&gfx_pskate_0Tiles, 0x200, 0},
    {&gfx_pskate_1Tiles, 0x200, 0},
    {&gfx_pskate_2Tiles, 0x200, 0},
    {&gfx_pskate_3Tiles, 0x200, 0},
    {&gfx_pskate_4Tiles, 0x200, 0},
    {&gfx_pskate_5Tiles, 0x200, 0},
    {&gfx_pskate_6Tiles, 0x200, 0},
    {&gfx_pskate_7Tiles, 0x200, 0},
    {&gfx_pskate_8Tiles, 0x200, 0}
};

overworld_sprite ow_mskate = {
    0xFFFF, 0x1100 + 0, 0x1102, 0x200,
    32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
    &ow_final_oam_32_32, &ow_formation_32_32,
    ow_anim_standard_npc, overworld_sprite_mskate_sprites,
    oam_rotscale_anim_table_null
};


static graphic overworld_sprite_fskate_sprites[] = {
    {&gfx_pskatef_0Tiles, 0x200, 0},
    {&gfx_pskatef_1Tiles, 0x200, 0},
    {&gfx_pskatef_2Tiles, 0x200, 0},
    {&gfx_pskatef_3Tiles, 0x200, 0},
    {&gfx_pskatef_4Tiles, 0x200, 0},
    {&gfx_pskatef_5Tiles, 0x200, 0},
    {&gfx_pskatef_6Tiles, 0x200, 0},
    {&gfx_pskatef_7Tiles, 0x200, 0},
    {&gfx_pskatef_8Tiles, 0x200, 0}
};

overworld_sprite ow_fskate = {
    0xFFFF, 0x1100 + 0, 0x1102, 0x200,
    32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
    &ow_final_oam_32_32, &ow_formation_32_32,
    ow_anim_standard_npc, overworld_sprite_fskate_sprites,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_igva_sprites[] = {
    {&gfx_ow_igva_0Tiles, 0x100, 0},
    {&gfx_ow_igva_1Tiles, 0x100, 0},
    {&gfx_ow_igva_2Tiles, 0x100, 0},
    {&gfx_ow_igva_3Tiles, 0x100, 0},
    {&gfx_ow_igva_4Tiles, 0x100, 0},
    {&gfx_ow_igva_5Tiles, 0x100, 0},
    {&gfx_ow_igva_6Tiles, 0x100, 0},
    {&gfx_ow_igva_7Tiles, 0x100, 0},
    {&gfx_ow_igva_8Tiles, 0x100, 0}
};

overworld_sprite ow_igva = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_igva_sprites,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_botogel_sprites[] = {
    {&gfx_ow_botogel_0Tiles, 0x100, 0},
    {&gfx_ow_botogel_1Tiles, 0x100, 0},
    {&gfx_ow_botogel_2Tiles, 0x100, 0},
    {&gfx_ow_botogel_0Tiles, 0x100, 0},
    {&gfx_ow_botogel_0Tiles, 0x100, 0},
    {&gfx_ow_botogel_1Tiles, 0x100, 0},
    {&gfx_ow_botogel_1Tiles, 0x100, 0},
    {&gfx_ow_botogel_2Tiles, 0x100, 0},
    {&gfx_ow_botogel_2Tiles, 0x100, 0}
};

overworld_sprite ow_botogel = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_botogel_sprites,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_bbship_sprites[] = {
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0}
};

overworld_sprite ow_bbship = {
    0xFFFF, 0x1100 + 0x15, 0x11FF, 0x1000,
    128, 64, 0, 1, 0, 0, 0x0, 0x0, 0x0,
    &ow_final_oam_128_64, &ow_formation_128_64,
    ow_anim_standard_npc, overworld_sprite_bbship_sprites,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_mpirate_sprites [] = {
    {&gfx_ow_mpirate_0Tiles, 0x100, 0},
    {&gfx_ow_mpirate_1Tiles, 0x100, 0},
    {&gfx_ow_mpirate_2Tiles, 0x100, 0},
    {&gfx_ow_mpirate_3Tiles, 0x100, 0},
    {&gfx_ow_mpirate_4Tiles, 0x100, 0},
    {&gfx_ow_mpirate_5Tiles, 0x100, 0},
    {&gfx_ow_mpirate_6Tiles, 0x100, 0},
    {&gfx_ow_mpirate_7Tiles, 0x100, 0},
    {&gfx_ow_mpirate_8Tiles, 0x100, 0}
};

overworld_sprite ow_mpirate = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_mpirate_sprites,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_animal [] = {
    {&gfx_ow_shape_animal_0Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_1Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_2Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_0Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_0Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_1Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_1Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_2Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_animal = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_animal,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_human [] = {
    {&gfx_ow_shape_human_0Tiles, 0x100, 0},
    {&gfx_ow_shape_human_1Tiles, 0x100, 0},
    {&gfx_ow_shape_human_2Tiles, 0x100, 0},
    {&gfx_ow_shape_human_0Tiles, 0x100, 0},
    {&gfx_ow_shape_human_0Tiles, 0x100, 0},
    {&gfx_ow_shape_human_1Tiles, 0x100, 0},
    {&gfx_ow_shape_human_1Tiles, 0x100, 0},
    {&gfx_ow_shape_human_2Tiles, 0x100, 0},
    {&gfx_ow_shape_human_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_human = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_human,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_tail [] = {
    {&gfx_ow_shape_tail_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_2Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_2Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_tail = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_tail,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_snake [] = {
    {&gfx_ow_shape_snake_0Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_1Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_2Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_0Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_0Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_1Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_1Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_2Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_snake = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_snake,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_winsect [] = {
    {&gfx_ow_shape_winsect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_2Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_2Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_winsect = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_winsect,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_winged [] = {
    {&gfx_ow_shape_winged_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_2Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_2Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_winged = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_winged,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_insect [] = {
    {&gfx_ow_shape_insect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_2Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_2Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_insect = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_insect,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_head [] = {
    {&gfx_ow_shape_head_0Tiles, 0x100, 0},
    {&gfx_ow_shape_head_1Tiles, 0x100, 0},
    {&gfx_ow_shape_head_2Tiles, 0x100, 0},
    {&gfx_ow_shape_head_0Tiles, 0x100, 0},
    {&gfx_ow_shape_head_0Tiles, 0x100, 0},
    {&gfx_ow_shape_head_1Tiles, 0x100, 0},
    {&gfx_ow_shape_head_1Tiles, 0x100, 0},
    {&gfx_ow_shape_head_2Tiles, 0x100, 0},
    {&gfx_ow_shape_head_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_head = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_head,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_arms [] = {
    {&gfx_ow_shape_arms_0Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_1Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_2Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_0Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_0Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_1Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_1Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_2Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_arms = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_arms,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_legs [] = {
    {&gfx_ow_shape_legs_0Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_1Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_2Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_0Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_0Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_1Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_1Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_2Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_legs = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_legs,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_tentacles [] = {
    {&gfx_ow_shape_tentacles_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_2Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_2Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_tentacles = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_tentacles,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_fish [] = {
    {&gfx_ow_shape_fish_0Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_1Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_2Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_0Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_0Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_1Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_1Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_2Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_fish = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_fish,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_ball [] = {
    {&gfx_ow_shape_ball_0Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_1Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_2Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_0Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_0Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_1Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_1Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_2Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_ball = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_ball,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_shape_multi [] = {
    {&gfx_ow_shape_multi_0Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_1Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_2Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_0Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_0Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_1Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_1Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_2Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_multi = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_shape_multi,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_mistral [] = {
    {&gfx_ow_mistral_0Tiles, 0x100, 0},
    {&gfx_ow_mistral_1Tiles, 0x100, 0},
    {&gfx_ow_mistral_2Tiles, 0x100, 0},
    {&gfx_ow_mistral_3Tiles, 0x100, 0},
    {&gfx_ow_mistral_4Tiles, 0x100, 0},
    {&gfx_ow_mistral_5Tiles, 0x100, 0},
    {&gfx_ow_mistral_6Tiles, 0x100, 0},
    {&gfx_ow_mistral_7Tiles, 0x100, 0},
    {&gfx_ow_mistral_8Tiles, 0x100, 0}
};

overworld_sprite ow_mistral = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_mistral,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_manus [] = {
    {&gfx_ow_manus_0Tiles, 0x100, 0},
    {&gfx_ow_manus_1Tiles, 0x100, 0},
    {&gfx_ow_manus_2Tiles, 0x100, 0},
    {&gfx_ow_manus_3Tiles, 0x100, 0},
    {&gfx_ow_manus_4Tiles, 0x100, 0},
    {&gfx_ow_manus_5Tiles, 0x100, 0},
    {&gfx_ow_manus_6Tiles, 0x100, 0},
    {&gfx_ow_manus_7Tiles, 0x100, 0},
    {&gfx_ow_manus_8Tiles, 0x100, 0}
};

overworld_sprite ow_manus = {
    0xFFFF, 0x1100 + 4, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_manus,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_altaria [] = {
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_1Tiles, 0x200, 0},
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_1Tiles, 0x200, 0},
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_1Tiles, 0x200, 0}
};

overworld_sprite ow_altaria = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x200,
    32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
    &ow_final_oam_32_32, &ow_formation_32_32,
    ow_anim_ho_oh, overworld_sprite_altaria,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_cloudrider_fem [] = {
    {&gfx_ow_cloudrider_fem_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_2Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_2Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_2Tiles, 0x200, 0}
};

overworld_sprite ow_cloudrider_fem = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x200,
    32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
    &ow_final_oam_32_32, &ow_formation_32_32,
    ow_anim_standard_npc, overworld_sprite_cloudrider_fem,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_cloudrider_male [] = {
    {&gfx_ow_cloudrider_male_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_2Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_2Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_2Tiles, 0x200, 0}
};

overworld_sprite ow_cloudrider_male = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x200,
    32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
    &ow_final_oam_32_32, &ow_formation_32_32,
    ow_anim_standard_npc, overworld_sprite_cloudrider_male,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_moltres [] = {
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_1Tiles, 0x800, 0},
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_1Tiles, 0x800, 0},
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_1Tiles, 0x800, 0}
};

overworld_sprite ow_moltres = {
    0xFFFF, 0x1100 + 3, 0x11FF, 0x800,
    64, 64, 0, 1, 0, 0, 0x1, 0x0, 0,
    &ow_final_oam_64_64, &ow_formation_64_64,
    ow_anim_standard_npc, overworld_sprite_moltres,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprites_diserakt [] = {
    {&gfx_ow_diserakt_0Tiles, 0x100, 0},
    {&gfx_ow_diserakt_2Tiles, 0x100, 0},
    {&gfx_ow_diserakt_1Tiles, 0x100, 0},
    {&gfx_ow_diserakt_0Tiles, 0x100, 0},
    {&gfx_ow_diserakt_0Tiles, 0x100, 0},
    {&gfx_ow_diserakt_2Tiles, 0x100, 0},
    {&gfx_ow_diserakt_2Tiles, 0x100, 0},
    {&gfx_ow_diserakt_1Tiles, 0x100, 0},
    {&gfx_ow_diserakt_1Tiles, 0x100, 0},
};

overworld_sprite ow_diserakt = {
    0xFFFF, 0x1100 + 4, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprites_diserakt,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_groudon [] = {
    {&gfx_ow_groudon_0Tiles, 0x800, 0},
    {&gfx_ow_groudon_0Tiles, 0x800, 0},
    {&gfx_ow_groudon_0Tiles, 0x800, 0},
    {&gfx_ow_groudon_1Tiles, 0x800, 0},
    {&gfx_ow_groudon_2Tiles, 0x800, 0},
    {&gfx_ow_groudon_1Tiles, 0x800, 0},
    {&gfx_ow_groudon_2Tiles, 0x800, 0},
    {&gfx_ow_groudon_1Tiles, 0x800, 0},
    {&gfx_ow_groudon_2Tiles, 0x800, 0}
};

overworld_sprite ow_groudon = {
    0xFFFF, 0x1100 + 3, 0x11FF, 0x800,
    64, 64, 0, 1, 0, 0, 0x1, 0x0, 0,
    &ow_final_oam_64_64, &ow_formation_64_64,
    ow_anim_standard_npc, overworld_sprite_groudon,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_rubys [] = {
    {&gfx_ow_rubys_0Tiles, 0x100, 0},
    {&gfx_ow_rubys_1Tiles, 0x100, 0},
    {&gfx_ow_rubys_2Tiles, 0x100, 0},
    {&gfx_ow_rubys_3Tiles, 0x100, 0},
    {&gfx_ow_rubys_4Tiles, 0x100, 0},
    {&gfx_ow_rubys_5Tiles, 0x100, 0},
    {&gfx_ow_rubys_6Tiles, 0x100, 0},
    {&gfx_ow_rubys_7Tiles, 0x100, 0},
    {&gfx_ow_rubys_8Tiles, 0x100, 0}
};

overworld_sprite ow_rubys = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_rubys,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_hiroine_sprites[] = {
	{&gfx_ow_hiroine_0Tiles, 0x200, 0},
	{&gfx_ow_hiroine_1Tiles, 0x200, 0},
	{&gfx_ow_hiroine_2Tiles, 0x200, 0},
	{&gfx_ow_hiroine_3Tiles, 0x200, 0},
	{&gfx_ow_hiroine_4Tiles, 0x200, 0},
	{&gfx_ow_hiroine_5Tiles, 0x200, 0},
	{&gfx_ow_hiroine_6Tiles, 0x200, 0},
	{&gfx_ow_hiroine_7Tiles, 0x200, 0},
	{&gfx_ow_hiroine_8Tiles, 0x200, 0},
	{&gfx_ow_hiroine_9Tiles, 0x200, 0},
	{&gfx_ow_hiroine_10Tiles, 0x200, 0},
	{&gfx_ow_hiroine_11Tiles, 0x200, 0},
	{&gfx_ow_hiroine_12Tiles, 0x200, 0},
	{&gfx_ow_hiroine_13Tiles, 0x200, 0},
	{&gfx_ow_hiroine_14Tiles, 0x200, 0},
	{&gfx_ow_hiroine_15Tiles, 0x200, 0},
	{&gfx_ow_hiroine_16Tiles, 0x200, 0},
	{&gfx_ow_hiroine_17Tiles, 0x200, 0},
	{&gfx_ow_hiroine_18Tiles, 0x200, 0},
	{&gfx_ow_hiroine_19Tiles, 0x200, 0}
};

overworld_sprite ow_hiroine = {
	0xffff, 0x1110, 0x1102, 0x200,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_hiro, overworld_sprite_hiroine_sprites, 
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_mother_sprites[] = {
	{&gfx_ow_mother_0Tiles, 0x100, 0},
	{&gfx_ow_mother_1Tiles, 0x100, 0},
	{&gfx_ow_mother_2Tiles, 0x100, 0},
	{&gfx_ow_mother_3Tiles, 0x100, 0},
	{&gfx_ow_mother_4Tiles, 0x100, 0},
	{&gfx_ow_mother_5Tiles, 0x100, 0},
	{&gfx_ow_mother_6Tiles, 0x100, 0},
	{&gfx_ow_mother_7Tiles, 0x100, 0},
	{&gfx_ow_mother_8Tiles, 0x100, 0}
};

overworld_sprite ow_mother = {
	0xffff, 0x1103, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_mother_sprites,
	oam_rotscale_anim_table_null
};

static graphic overworld_sprite_drampa_sprites[] = {
  {&gfx_ow_drampaTiles[0 * 32 * 32 / 2 / 2], 0x200, 0},
  {&gfx_ow_drampaTiles[2 * 32 * 32 / 2 / 2], 0x200, 0},
  {&gfx_ow_drampaTiles[4 * 32 * 32 / 2 / 2], 0x200, 0},
  {&gfx_ow_drampaTiles[0 * 32 * 32 / 2 / 2], 0x200, 0},
  {&gfx_ow_drampaTiles[1 * 32 * 32 / 2 / 2], 0x200, 0},
  {&gfx_ow_drampaTiles[2 * 32 * 32 / 2 / 2], 0x200, 0},
  {&gfx_ow_drampaTiles[3 * 32 * 32 / 2 / 2], 0x200, 0},
  {&gfx_ow_drampaTiles[4 * 32 * 32 / 2 / 2], 0x200, 0},
  {&gfx_ow_drampaTiles[5 * 32 * 32 / 2 / 2], 0x200, 0},
};

overworld_sprite ow_drampa = {
  0xffff, 0x1104, 0x11ff, 0x200,
  32, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
  &ow_final_oam_32_32, &ow_formation_32_32,
  ow_anim_standard_npc, overworld_sprite_drampa_sprites,
  oam_rotscale_anim_table_null
};

static graphic overworld_sprite_blackbeard_sprites[] = {
	{&gfx_ow_blackbeardTiles[0 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_blackbeardTiles[1 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_blackbeardTiles[2 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_blackbeardTiles[3 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_blackbeardTiles[4 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_blackbeardTiles[5 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_blackbeardTiles[6 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_blackbeardTiles[7 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_blackbeardTiles[8 * 16 * 32 / 2 / 2], 0x100, 0},
};

overworld_sprite ow_blackbeard = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_blackbeard_sprites,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_teah_sprites[] = {
	{&gfx_ow_teahTiles[0 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_teahTiles[1 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_teahTiles[2 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_teahTiles[3 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_teahTiles[4 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_teahTiles[5 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_teahTiles[6 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_teahTiles[7 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_teahTiles[8 * 16 * 32 / 2 / 2], 0x100, 0},
};

overworld_sprite ow_teah = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_teah_sprites,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_narcissa_sprites[] = {
	{&gfx_ow_narcissaTiles[0 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_narcissaTiles[1 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_narcissaTiles[2 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_narcissaTiles[3 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_narcissaTiles[4 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_narcissaTiles[5 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_narcissaTiles[6 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_narcissaTiles[7 * 16 * 32 / 2 / 2], 0x100, 0},
	{&gfx_ow_narcissaTiles[8 * 16 * 32 / 2 / 2], 0x100, 0},
};

overworld_sprite ow_narcissa = {
    0xFFFF, 0x1100 + 0xB, 0x11FF, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x0,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_narcissa_sprites,
    oam_rotscale_anim_table_null
};


graphic overworld_sprite_harrenfeld_sprites [] = {
    {&gfx_ow_harrenfeld_0Tiles, 0x100, 0},
    {&gfx_ow_harrenfeld_1Tiles, 0x100, 0},
    {&gfx_ow_harrenfeld_2Tiles, 0x100, 0},
    {&gfx_ow_harrenfeld_3Tiles, 0x100, 0},
    {&gfx_ow_harrenfeld_4Tiles, 0x100, 0},
    {&gfx_ow_harrenfeld_5Tiles, 0x100, 0},
    {&gfx_ow_harrenfeld_6Tiles, 0x100, 0},
    {&gfx_ow_harrenfeld_7Tiles, 0x100, 0},
    {&gfx_ow_harrenfeld_8Tiles, 0x100, 0}
};

overworld_sprite ow_harrenfeld = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_harrenfeld_sprites,
    oam_rotscale_anim_table_null
};

graphic overworld_sprite_butler_sprites [] = {
    {&gfx_ow_butler_0Tiles, 0x100, 0},
    {&gfx_ow_butler_1Tiles, 0x100, 0},
    {&gfx_ow_butler_2Tiles, 0x100, 0},
    {&gfx_ow_butler_3Tiles, 0x100, 0},
    {&gfx_ow_butler_4Tiles, 0x100, 0},
    {&gfx_ow_butler_5Tiles, 0x100, 0},
    {&gfx_ow_butler_6Tiles, 0x100, 0},
    {&gfx_ow_butler_7Tiles, 0x100, 0},
    {&gfx_ow_butler_8Tiles, 0x100, 0}
};

overworld_sprite ow_butler = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_butler_sprites,
    oam_rotscale_anim_table_null
};

static graphic overworld_sprite_lucius [] = {
    {&gfx_ow_lucius_0Tiles, 0x100, 0},
    {&gfx_ow_lucius_1Tiles, 0x100, 0},
    {&gfx_ow_lucius_2Tiles, 0x100, 0},
    {&gfx_ow_lucius_3Tiles, 0x100, 0},
    {&gfx_ow_lucius_4Tiles, 0x100, 0},
    {&gfx_ow_lucius_5Tiles, 0x100, 0},
    {&gfx_ow_lucius_6Tiles, 0x100, 0},
    {&gfx_ow_lucius_7Tiles, 0x100, 0},
    {&gfx_ow_lucius_8Tiles, 0x100, 0}
};

overworld_sprite ow_lucius = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_lucius,
    oam_rotscale_anim_table_null
};

graphic overworld_sprite_lucky[] = {
	{gfx_ow_luckyTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_luckyTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_luckyTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_luckyTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_luckyTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_luckyTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_luckyTiles + 6 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_luckyTiles + 7 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_luckyTiles + 8 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
};

overworld_sprite ow_lucky = {
	0xffff, 0x1105, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_lucky, 
	oam_rotscale_anim_table_null
};

static overworld_sprite ow_pokemon_32_32 = {
	.tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE,
	.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
	.final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
	.graphics = overworld_sprite_lucky, .rotscale_animation = oam_rotscale_anim_table_null,
};

static overworld_sprite ow_pokemon_64_64 = {
	.tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE,
	.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(64, 64), .width = 64, .height = 64,
	.final_oam = &ow_final_oam_64_64, .subsprite_table = &ow_formation_64_64, .gfx_animation = ow_anim_standard_npc,
	.graphics = NULL, .rotscale_animation = oam_rotscale_anim_table_null,
};

static overworld_sprite ow_berry_tree = {
	.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE ,
	.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
	.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = ow_anim_standard_npc,
	.graphics = NULL + 0, .rotscale_animation = oam_rotscale_anim_table_null,	
};

static overworld_sprite ow_misc_16_16 = {
	.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE ,
	.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 16), .width = 16, .height = 16,
	.final_oam = &ow_final_oam_16_16, .subsprite_table = &ow_formation_16_16, .gfx_animation = ow_anim_standard_npc,
	.graphics = NULL + 0, .rotscale_animation = oam_rotscale_anim_table_null,	
};

graphic overworld_sprite_chef[] = {
	{gfx_ow_chefTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_chefTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_chefTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_chefTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_chefTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_chefTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_chefTiles + 6 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_chefTiles + 7 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
	{gfx_ow_chefTiles + 8 * GRAPHIC_SIZE_4BPP(16, 32), GRAPHIC_SIZE_4BPP(16, 32), 0},
};

overworld_sprite ow_chef = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
    &ow_final_oam_16_32, &ow_formation_16_32,
    ow_anim_standard_npc, overworld_sprite_chef,
    oam_rotscale_anim_table_null
};

static gfx_frame gfx_animation_mega_stone[] = {
	{.data = 0, .duration = 0}, {.data = 0, .duration = 12}, {.data = 1, .duration = 12}, 
    {.data = 2, .duration = 12}, {.data = 3, .duration = 12}, {.data = 4, .duration = 12},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame *gfx_animations_mega_stone[1] = {gfx_animation_mega_stone};

graphic overworld_gfxs_mega_stone[] = {
	{gfx_ow_mega_stoneTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), GRAPHIC_SIZE_4BPP(16, 16), 0},
	{gfx_ow_mega_stoneTiles + 1 * GRAPHIC_SIZE_4BPP(16, 16), GRAPHIC_SIZE_4BPP(16, 16), 0},
	{gfx_ow_mega_stoneTiles + 2 * GRAPHIC_SIZE_4BPP(16, 16), GRAPHIC_SIZE_4BPP(16, 16), 0},
	{gfx_ow_mega_stoneTiles + 3 * GRAPHIC_SIZE_4BPP(16, 16), GRAPHIC_SIZE_4BPP(16, 16), 0},
	{gfx_ow_mega_stoneTiles + 4 * GRAPHIC_SIZE_4BPP(16, 16), GRAPHIC_SIZE_4BPP(16, 16), 0},
};

overworld_sprite ow_mega_stone = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_MEGA_STONE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 16), .width = 16, .height = 16,
        .final_oam = &ow_final_oam_16_16, .subsprite_table = &ow_formation_16_16, .gfx_animation = gfx_animations_mega_stone,
        .graphics = overworld_gfxs_mega_stone, .rotscale_animation = oam_rotscale_anim_table_null,
};

static palette overworld_mega_stone_palette = {
	.pal = gfx_ow_mega_stonePal, .tag = OW_PAL_TAG_MEGA_STONE,
};

palette *overworld_palette_get_mega_stone() {
	return &overworld_mega_stone_palette;
}

static graphic overworld_sprite_lester_young_sprites[] = {
	{gfx_ow_lester_youngTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lester_youngTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lester_youngTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lester_youngTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lester_youngTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lester_youngTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lester_youngTiles + 6 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lester_youngTiles + 7 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_lester_youngTiles + 8 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
};

overworld_sprite ow_lester_young = {
	0xffff, 0x1106, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_lester_young_sprites, 
	oam_rotscale_anim_table_null
};



static graphic overworld_sprite_roman_sprites[] = {
	{gfx_ow_romanTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_romanTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_romanTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_romanTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_romanTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_romanTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_romanTiles + 6 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_romanTiles + 7 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
	{gfx_ow_romanTiles + 8 * GRAPHIC_SIZE_4BPP(16, 32), 0x100, 0},
};

overworld_sprite ow_roman = {
	0xffff, OW_PAL_TAG_ROMAN, 0x11ff, 0x100,
	16, 32, 0, 1, 0, 0, 0x1, 0x0, 0x8,
	&ow_final_oam_16_32, &ow_formation_16_32,
	ow_anim_standard_npc, overworld_sprite_roman_sprites, 
	oam_rotscale_anim_table_null
};

//The overworld table
overworld_sprite *overworld_sprites[] = {
    	&ow_hiro,
	&ow_mskate,//(overworld_sprite*) 0x96d865c,
	&ow_hiro_sit,
	&ow_hiro_call,
	&ow_hiro_rod,
	&ow_hiro_call2,
	&ow_hiro_call_bike,
	&ow_hiroine,
	&ow_fskate,
	&ow_hiroine_sit,
//10
	&ow_hiroine_call,
	&ow_hiroine_rod,
	&ow_hiroine_call,
	(overworld_sprite*) 0x83a47d0,
	(overworld_sprite*) 0x83a3b28,
	(overworld_sprite*) 0x83a3b4c,
	(overworld_sprite*) 0x83a3b70,
	(overworld_sprite*) 0x83a3b94,
	(overworld_sprite*) 0x83a3c00,
	(overworld_sprite*) 0x83a3c6c,
//20
	(overworld_sprite*) 0x83a3cb4,
	(overworld_sprite*) 0x83a3bb8,
	(overworld_sprite*) 0x83a3bdc,
	(overworld_sprite*) 0x83a3c24,
	(overworld_sprite*) 0x83a3c90,
	(overworld_sprite*) 0x83a4254,
	(overworld_sprite*) 0x83a4278,
	(overworld_sprite*) 0x83a3cd8,
	(overworld_sprite*) 0x83a3d20,
	(overworld_sprite*) 0x83a3db0,
//30        
	(overworld_sprite*) 0x83a3cfc,
	(overworld_sprite*) 0x83a3c48,
	(overworld_sprite*) 0x83a3d44,
	(overworld_sprite*) 0x83a3df8,
	(overworld_sprite*) 0x83a42e4,
	(overworld_sprite*) 0x83a3e1c,
	(overworld_sprite*) 0x83a4110,
	(overworld_sprite*) 0x83a40ec,
	(overworld_sprite*) 0x83a4134,
	(overworld_sprite*) 0x83a3e40,
//40
	(overworld_sprite*) 0x83a3e64,
	(overworld_sprite*) 0x83a3e88,
	(overworld_sprite*) 0x83a3eac,
	(overworld_sprite*) 0x83a3f3c,
	(overworld_sprite*) 0x83a3f60,
	(overworld_sprite*) 0x83a3f84,
	(overworld_sprite*) 0x83a3fa8,
	&ow_primus, //(overworld_sprite*) 0x83a3d68,
	(overworld_sprite*) 0x83a3d8c,
	&ow_violet_grunt_m,//(overworld_sprite*) 0x83a44dc,
//50
	&ow_violet_grunt_f,//(overworld_sprite*) 0x83a3f18,
	(overworld_sprite*) 0x83a483c,
	(overworld_sprite*) 0x83a3ed0,
	&ow_butler, // (overworld_sprite*) 0x83a417c,
	(overworld_sprite*) 0x83a3fcc,
	(overworld_sprite*) 0x83a3ff0,
	(overworld_sprite*) 0x83a4158,
	(overworld_sprite*) 0x83a4080,
	(overworld_sprite*) 0x83a3ef4,
	(overworld_sprite*) 0x83a3dd4,
//60
	(overworld_sprite*) 0x83a3b04,
	(overworld_sprite*) 0x83a4014,
	(overworld_sprite*) 0x83a4038,
	(overworld_sprite*) 0x83a405c,
	(overworld_sprite*) 0x83a41c4,
	(overworld_sprite*) 0x83a4398,
	&ow_albus,//(overworld_sprite*) 0x83a43bc,
	&ow_blackbeard,// (overworld_sprite*) 0x83a41e8,
	(overworld_sprite*) 0x83a432c,
	&ow_felix,//(overworld_sprite*) 0x83a4350,
//70
	&ow_harrenfeld, //(overworld_sprite*) 0x83a4374,
	&ow_tann,//(overworld_sprite*) 0x83a4230,
	&ow_rival, //(overworld_sprite*) 0x83a46f8,
	&ow_lucius, //(overworld_sprite*) 0x83a4668,
	(overworld_sprite*) 0x83a46d4,
	&ow_narcissa, //(overworld_sprite*) 0x83a4524,
	(overworld_sprite*) 0x83a468c,
	(overworld_sprite*) 0x83a46b0,
	&ow_revolutionary,//(overworld_sprite*) 0x83a429c,
	&ow_faun, //(overworld_sprite*) 0x83a42c0,
//80
	&ow_lester,//(overworld_sprite*) 0x83a4548,
	&ow_mia, //(overworld_sprite*) 0x83a456c,
	&ow_manus,//(overworld_sprite*) 0x96d7e58,
	&ow_teah, //(overworld_sprite*) 0x83a45b4,
	(overworld_sprite*) 0x83a45d8,
	(overworld_sprite*) 0x83a4644,
	&ow_igva,//(overworld_sprite*) 0x96d85f0,
	(overworld_sprite*) 0x83a45fc,
	&ow_mother, //(overworld_sprite*) 0x83a4fb0,
	&ow_blaise, //(overworld_sprite*) 0x83a4500,
//90
	&ow_rin,
	(overworld_sprite*) 0x83a41a0,
	(overworld_sprite*) 0x83a420c,
	&ow_mega_stone, // (overworld_sprite*) 0x83a47f4,
	(overworld_sprite*) 0x83a4818,
	(overworld_sprite*) 0x83a4308,
	(overworld_sprite*) 0x83a43e0,
	&overworld_sprite_strength_boulder,
	(overworld_sprite*) 0x83a4884,
	(overworld_sprite*) 0x83a48a8,
//100
	(overworld_sprite*) 0x83a48cc,
	&ow_egg,//(overworld_sprite*) 0x83a48f0,
	(overworld_sprite*) 0x83a4914,
	&ow_faun_young,//(overworld_sprite*) 0x83a4938,
	(overworld_sprite*) 0x83a495c,
	&ow_elise,//(overworld_sprite*) 0x83a4980,
	&ow_larissa,//(overworld_sprite*) 0x83a49a4,
	(overworld_sprite*) 0x83a49c8,
	(overworld_sprite*) 0x83a4fd4,
	(overworld_sprite*) 0x83a4860,
//110
        &ow_staralili,//(overworld_sprite*) 0x83a49ec,
	&ow_voltilamm,//(overworld_sprite*) 0x83a4e48,
	(overworld_sprite*) 0x83a4eb4,
	&ow_groudon,//(overworld_sprite*) 0x96d7bd0,
	(overworld_sprite*) 0x83a4ed8,
	(overworld_sprite*) 0x83a4f44,
	(overworld_sprite*) 0x83a4f68,
	(overworld_sprite*) 0x83a4efc,
	(overworld_sprite*) 0x83a4a10,
	(overworld_sprite*) 0x83a4a34,
//120
        (overworld_sprite*) 0x83a4f20,
	(overworld_sprite*) 0x83a4a58,
	(overworld_sprite*) 0x83a4a7c,
	(overworld_sprite*) 0x83a4aa0,
	(overworld_sprite*) 0x83a4ac4,
	(overworld_sprite*) 0x83a4ae8,
	(overworld_sprite*) 0x83a4b0c,
	(overworld_sprite*) 0x83a4b30,
	(overworld_sprite*) 0x83a4b54,
	(overworld_sprite*) 0x83a4b78,
//130	
        (overworld_sprite*) 0x83a4b9c,
	(overworld_sprite*) 0x83a4bc0,
	(overworld_sprite*) 0x83a4be4,
	&ow_regirock,//(overworld_sprite*) 0x83a4c08,
	&ow_regice,//(overworld_sprite*) 0x83a4e6c,
	&ow_registeel,//(overworld_sprite*) 0x83a4c2c,
	(overworld_sprite*) 0x83a4c50,
	&ow_moltres,//(overworld_sprite*) 0x96d7ca8,
	(overworld_sprite*) 0x83a4c98,
	(overworld_sprite*) 0x83a4d28,
//140	
        (overworld_sprite*) 0x83a4d4c,
	(overworld_sprite*) 0x83a4d70,
	(overworld_sprite*) 0x83a4db8,
	(overworld_sprite*) 0x83a4d94,
	(overworld_sprite*) 0x83a4ddc,
	(overworld_sprite*) 0x83a4e00,
	(overworld_sprite*) 0x83a4e24,
	(overworld_sprite*) 0x83a4e90,
	(overworld_sprite*) 0x83a4cbc,
	(overworld_sprite*) 0x83a4ce0,
//150	
        &ow_deoxys_normal,//(overworld_sprite*) 0x83a4d04,
	(overworld_sprite*) 0x83a4ff8,
	&ow_bbship,//(overworld_sprite*) 0x96d8584,
	&ow_mpirate,//(overworld_sprite*) 0x96d8518,
        &ow_shape_animal,
	&ow_shape_human,//(overworld_sprite*) 0x96d84ac,
	&ow_shape_tail,//(overworld_sprite*) 0x96d8440,
	&ow_shape_snake,//(overworld_sprite*) 0x96d83d4,
	&ow_shape_winsect,//(overworld_sprite*) 0x96d8368,
	&ow_shape_winged,//(overworld_sprite*) 0x96d82fc,
//160
	&ow_shape_insect,//(overworld_sprite*) 0x96d8290,
	&ow_shape_head,//(overworld_sprite*) 0x96d8224,
	&ow_shape_arms,//(overworld_sprite*) 0x96d81b8,
	&ow_shape_legs,//(overworld_sprite*) 0x96d814c,
	&ow_shape_tentacles,//(overworld_sprite*) 0x96d80e0,
	&ow_shape_fish,//(overworld_sprite*) 0x96d8074,
	&ow_shape_ball,//(overworld_sprite*) 0x96d8008,
	&ow_shape_multi,//(overworld_sprite*) 0x96d7f9c,
	&ow_mistral,
	&ow_altaria,
//170	
        &ow_cloudrider_fem,
        &ow_cloudrider_male,
        &ow_diserakt,
        &ow_rubys,
//174 
        &ow_botogel,
        &ow_drampa,
		&ow_lucky,
		&ow_chef,
// 178
		&ow_lester_young,
		&ow_roman,
		&ow_rival_beaten,

	[OVERWORLD_SPRITE_MISC] = &ow_misc_16_16,
	[OVERWORLD_SPRITE_BERRY] = &ow_berry_tree, // dummy
	[OVERWORLD_SPRITE_POKEMON_32_32] = &ow_pokemon_32_32, // dummy with size 32x32
	[OVERWORLD_SPRITE_POKEMON_64_64] = &ow_pokemon_64_64, // dummy with size 64x64

};


overworld_sprite *overworld_get (u16 picture){
    if(picture >= 0xF0){
		// dprintf("Picture is %d\n", *var_access((u16)(0x4010+picture-0xF0)));
        return overworld_sprites[*var_access((u16)(0x4010 + picture - 0xF0))];
    }
    return overworld_sprites[picture];
}
