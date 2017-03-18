//save file block restauration

.org 0x80DA100
    ldr r0, =hook_save_block_load | 1
    bx r0
    .pool

.org 0x80D9B42
    bx r7 //use a previous word load

.org 0x80D9B80
    .word hook_save_block_store | 1


.org 0x83FEC98 //the save block size lut
    
.halfword 0x0
.halfword 0xf24

//5008 block
.halfword 0x0
.halfword 0xff0

.halfword 0xff0
.halfword 0xff0

.halfword 0x1fe0
.halfword 0xff0

.halfword 0x2fd0
.halfword 0xd98

//5010 (box) block

.halfword 0x0
.halfword 0xff0

.halfword 0xff0
.halfword 0xff0

.halfword 0x1fe0
.halfword 0xff0

.halfword 0x2fd0
.halfword 0xff0

.halfword 0x3fc0
.halfword 0xff0

.halfword 0x4fb0
.halfword 0xff0

.halfword 0x5fa0
.halfword 0xff0

.halfword 0x6f90
.halfword 0xff0

.halfword 0x7f80
.halfword 0x450
