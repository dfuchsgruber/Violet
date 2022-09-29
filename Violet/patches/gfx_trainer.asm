trainersprites equ 0x0823944C
trainerpals equ 0x082398EC

.macro trainergfx,num,tiles,pal
.org trainersprites + 8 * num
    .word tiles
.org trainerpals + 8 * num
    .word pal
.endmacro


.org trainersprites + 8*1
    .word gfx_trainer_revo_mTiles

.org trainerpals + 8*1
    .word gfx_trainer_revo_mPal

.org trainersprites + 8*2
    .word gfx_trainer_revo_fTiles

.org trainerpals + 8*2
    .word gfx_trainer_revo_fPal

.org trainersprites +8 *5
    .word gfx_trainer_eliseTiles

.org trainerpals + 8*5
    .word gfx_trainer_elisePal

.org trainersprites + 8 * 71
    .word gfx_trainer_cloudrider_femTiles

.org trainerpals + 8 * 71
    .word gfx_trainer_cloudrider_femPal

.org trainersprites + 8 * 72
    .word gfx_trainer_cloudrider_maleTiles

.org trainerpals + 8 * 72
    .word gfx_trainer_cloudrider_malePal

.org trainersprites + 8 * 118
    .word gfx_trainer_manusTiles

.org trainerpals + 8 * 118
    .word gfx_trainer_manusPal

.org trainersprites + 8 * 119
    .word gfx_trainer_teahTiles

.org trainerpals + 8 * 119
    .word gfx_trainer_teahPal

.org trainersprites + 8 * 73
    .word gfx_trainer_violet_elite_femTiles

.org trainerpals + 8 * 73
    .word gfx_trainer_violet_elite_femPal

.org trainersprites + 8 * 74
    .word gfx_trainer_violet_elite_maleTiles

.org trainerpals + 8 * 74
    .word gfx_trainer_violet_elite_malePal

.org trainersprites + 8 * 96
    .word gfx_trainer_mistraltiles

.org trainerpals + 8 * 96
    .word gfx_trainer_mistralPal


.org trainersprites + 8 * 135
    .word gfx_trainer_hiroTiles

.org trainerpals + 8 * 135
    .word gfx_trainer_hiroPal

.org trainersprites + 8 * 136
    .word gfx_trainer_hiroineTiles

.org trainerpals + 8 * 136
    .word gfx_trainer_hiroinePal



trainergfx 0,gfx_trainer_polizistTiles,gfx_trainer_polizistPal
trainergfx 27,gfx_trainer_rinTiles,gfx_trainer_rinPal
trainergfx 78,gfx_trainer_violet_grunt_fTiles,gfx_trainer_violet_grunt_fPal
trainergfx 106,gfx_trainer_rivalTiles,gfx_trainer_rivalPal
trainergfx 109,gfx_trainer_violet_grunt_mTiles,gfx_trainer_violet_grunt_mPal
trainergfx 116,gfx_trainer_lesterTiles,gfx_trainer_lesterPal
trainergfx 117,gfx_trainer_miaTiles,gfx_trainer_miaPal
trainergfx 137,gfx_trainer_violet_grunt_fTiles,gfx_trainer_violet_grunt_fPal
trainergfx 121,gfx_trainer_igvaTiles, gfx_trainer_igvaPal
trainergfx 26,gfx_trainer_harrenfeldTiles,gfx_trainer_harrenfeldPal
trainergfx 25,gfx_trainer_pirateTiles,gfx_trainer_piratePal
trainergfx 24,gfx_trainer_butlerTiles,gfx_trainer_butlerPal
trainergfx 28,gfx_trainer_luciusTiles,gfx_trainer_luciusPal
trainergfx 62,gfx_trainer_blackbeardTiles,gfx_trainer_blackbeardPal
trainergfx 75,gfx_trainer_chefTiles,gfx_trainer_chefPal
trainergfx 76,gfx_trainer_icarusTiles,gfx_trainer_icarusPal
trainergfx 77,gfx_trainer_dark_guard_blueTiles,gfx_trainer_dark_guard_bluePal
trainergfx 79,gfx_trainer_dark_guard_redTiles,gfx_trainer_dark_guard_redPal
trainergfx 80,gfx_trainer_dark_guard_greenTiles,gfx_trainer_dark_guard_greenPal
trainergfx 81,gfx_trainer_dark_guard_yellowTiles,gfx_trainer_dark_guard_yellowPal
trainergfx 28,gfx_trainer_crypticTiles,gfx_trainer_crypticPal

.org 0x0803f7a0
    .word trainer_backsprite_templates

.org 0x080334d4
    .word trainer_backsprite_palettes
.org 0x08034674
    .word trainer_backsprite_palettes
.org 0x080d704c
    .word trainer_backsprite_palettes
.org 0x080eb0e4
    .word trainer_backsprite_palettes
.org 0x08159124
    .word trainer_backsprite_palettes

.org 0x0803230c
	.word trainer_backsprite_coordinates
.org 0x08032474
	.word trainer_backsprite_coordinates
.org 0x08077d3a
	.word trainer_backsprite_coordinates
.org 0x08077d70
	.word trainer_backsprite_coordinates
.org 0x08077d9a
	.word trainer_backsprite_coordinates
.org 0x08077dfc
	.word trainer_backsprite_coordinates
.org 0x080d64c8
	.word trainer_backsprite_coordinates
.org 0x080ddcac
	.word trainer_backsprite_coordinates
.org 0x080ea0fc
	.word trainer_backsprite_coordinates
.org 0x080ea124
	.word trainer_backsprite_coordinates
.org 0x080ea1b8
	.word trainer_backsprite_coordinates
.org 0x080ea240
	.word trainer_backsprite_coordinates
.org 0x080ea268
	.word trainer_backsprite_coordinates
.org 0x080ea2fc
	.word trainer_backsprite_coordinates
.org 0x08158042
	.word trainer_backsprite_coordinates
.org 0x081580ac
	.word trainer_backsprite_coordinates
.org 0x08158232
	.word trainer_backsprite_coordinates
.org 0x081582c0
	.word trainer_backsprite_coordinates

.org 0x0803f7a4
    .word trainer_backsprite_animations
