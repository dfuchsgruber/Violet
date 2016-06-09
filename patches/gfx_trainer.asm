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