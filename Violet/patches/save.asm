// Replace the complete slot loader. This preserves the vanilla normal
// sector flow and additionally restores csave from selected sector tails.
.org 0x080DA078
    ldr r2, =save_slot_data_load | 1
    bx r2
    .pool

// Replace normal sector construction/writing.
.org 0x080D9A94
    ldr r2, =save_sector_handle_write | 1
    bx r2
    .pool

// HandleReplaceSector has an independent construction path. Serialize its
// custom tail after the vanilla checksum is stored and before flash erasure.
.org 0x080D9E28
    ldr r0, =hook_save_block_replace | 1
    bx r0
    .pool
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


.org 0x0804c082
    mov r1, #0 // Don't move saveblocks, this makes it waaaay easier to debug...
