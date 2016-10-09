trainersprites equ 0x0823944C
trainerpals equ 0x082398EC
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

.org trainersprites + 8 * 118
    .word gfx_trainer_manusTiles

.org trainerpals + 8 * 118
    .word gfx_trainer_manusPal
