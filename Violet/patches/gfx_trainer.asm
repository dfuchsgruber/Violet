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

