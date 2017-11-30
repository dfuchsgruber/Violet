.org 0x800f224
	.word battle_bgs

.org 0x800f264
	.word battle_bgs

.org 0x800f2a4
	.word battle_bgs

.org 0x800fce0
	.word battle_bgs

.org 0x800fd0c
	.word battle_bgs

.org 0x080738C4
        .word battle_anim_bgs


.org 0x0800F3D8
        .word gfx_battle_boxTiles

.org 0x0800F3E0
        .word gfx_battle_boxPal

//bsc strings
	

.org 0x80cf194
	.word bsc_strings

.org 0x80cf270
	.word bsc_strings

.org 0x80cf2b8
	.word bsc_strings

.org 0x80cf350
	.word bsc_strings

.org 0x80cf530
	.word bsc_strings

.org 0x80cf5b0
	.word bsc_strings

.org 0x80cf5f8
	.word bsc_strings

.org 0x80cf640
	.word bsc_strings

.org 0x80cf674
	.word bsc_strings

.org 0x80cf6a0
	.word bsc_strings

.org 0x80cfcd0
	.word bsc_strings

.org 0x80cfda8
	.word bsc_strings

.org 0x80cfdf0
	.word bsc_strings

.org 0x80cfe90
	.word bsc_strings

.org 0x80cff0c
	.word bsc_strings

.org 0x80cff48
	.word bsc_strings

.org 0x80d0058
	.word bsc_strings

.org 0x80d00c4
	.word bsc_strings

.org 0x80d010c
	.word bsc_strings

.org 0x80d0154
	.word bsc_strings

.org 0x80d0188
	.word bsc_strings

.org 0x80d01b4
	.word bsc_strings

.org 0x80d79b8
	.word bsc_strings

.org 0x80d86a4
	.word bsc_strings


.org 0x802BE0C
        .word terrain_moves

.org 0x0800F1E4
        ldr r1, =battle_bg_load | 1
        bx r1
        .pool

.org 0x0800F230
        ldr r1, =battle_bg_load_anim | 1
        bx r1
        .pool

.org 0x0800F270
        push{lr, r4}
        ldr r4, =battle_bg_get | 1
        bl blxr4
        pop {r0}
        bx r0
blxr4:
        bx r4
        .pool



.org 0x0807FBC0
        ldr r0, =battle_bg_by_tile | 1
        bx r0
        .pool

.org 0x0802d9b0
        .word battle_bg_catch

.org 0x800FBB0
        ldr r0, =battle_bg_get_id | 1
        bx r0
        .pool



.org 0x080CE03C
        .byte 13 //battle bg evo

.org 0x080CE348
        .byte 13 //^
        
//@battlestring remove the bsc string limitation (extend it to 0x7FFF)
.org 0x080D7988
    .halfword 0x7FFF

//@battlestring remove attack limitations
.org 0x080D80AA
    mov r0, #0x7F
    lsl r0, #0x18 //high number so that all attacks are valid

.org 0x080D80C2
    mov r0, #0x7F
    lsl r0, #0x18 //high number so all attacks are valid

//fadeing intro of battle
.org 0x0824EEB4
    .word dma0_dump

.org 0x0800FEB0
    .halfword 0x5050 //win0 settings

.org 0x8014ba0
	.word battle_script_cmds

.org 0x80159ac
	.word battle_script_cmds

.org 0x8015bf0
	.word battle_script_cmds

.org 0x8015c1c
	.word battle_script_cmds

.org 0x801cfd8
	.word battle_script_cmds

.org 0x080153B4
        ldr r0, =hook_clear_temporary_effects | 1
        bx r0
        .pool

.org 0x08015778
    ldr r0, =battle_whiteout_bypass | 1
    bx r0
    .pool

.org 0x08080404
    .word trainerbattle_after_battle | 1

.org 0x08080050
    .word hook_battle_result
    .word hook_battle_result

