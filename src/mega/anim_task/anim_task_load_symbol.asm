.align 2
.thumb

.global anim_task_load_symbol

.thumb_func
anim_task_load_symbol:
push {r4-r5, lr}
mov r4, r0
ldr r0, =0x02037F02
ldrh r5, [r0]	@mode
adr r0, gfxs
lsl r1, r5, #3	@8 bytes per gfx
add r0, r1
bl load_gfx_and_alloc_lz77
adr r0, pals
cmp r5, #0
beq skip
add r0, #8	@regent pals
skip:
ldrh r5, [r0, #4]	@tag
bl attack_anim_cmdx00_load_obj_palette
mov r0, r5
bl add_atk_obj_animation
mov r0, r4
bl end_anim_cb
pop {r4-r5, pc}




add_atk_obj_animation:                  
ldr r1, =0x080726FD
bx r1

load_gfx_and_alloc_lz77:
ldr r1, =0x0800EFB9
bx r1

attack_anim_cmdx00_load_obj_palette:
ldr r1, =0x0800EFFD
bx r1

end_anim_cb:
ldr r1, =0x080726C5
bx r1


.align 4
gfxs:
.word gfx_mega_sparkleTiles
.hword 0x200
.hword 0xAAA0
.word gfx_regent_kyogre_sparkleTiles
.hword 0x200
.hword 0xAAA0
.word gfx_regent_groudon_sparkleTiles
.hword 0x200
.hword 0xAAA0
.word gfx_regent_rayquaza_sparkleTiles
.hword 0x200
.hword 0xAAA0

.align 4
pals:
.word gfx_mega_sparklePal
.word 0xAAA0
.word gfx_regent_kyogre_sparklePal
.word 0xAAA1
