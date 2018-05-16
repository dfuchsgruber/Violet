@insert this at 0x43084 via bx_r0.bin
.align 2
.thumb 

.global evolution_m_litem

.equ link_stone, 0x63
.equ funkelstein, 102

evolution_m_litem:
add r0, r6, r7
ldr r1, [sp, #4]
add r0, r1
lsl r0, #3
add r1, r0, r3
ldrh r0, [r1]
cmp r0, #7
beq param_is_normal_item
cmp r0, #0x14						@REPLACE this NUMBER with the ID of the evolution method!
beq link_stone_hold_param
cmp r0, #0x15
beq male_funkelstone_evo
b param_is_not_item_evolution

link_stone_hold_param:
ldr r0, =link_stone
cmp r0, r9
bne param_is_not_item_evolution
mov r4, r1
ldr r0, =0x800D		@LASTRESULT
bl var_access
mov r1, #1
strh r1, [r0]
mov r1, r4
mov r2, sp
ldrh r0, [r2]
mov r9, r0

param_is_normal_item:
ldrh r0, [r1, #2]
cmp r0, r9
beq equals_req
param_is_not_item_evolution:
ldr r2, =0x08043099
bx r2



male_funkelstone_evo:
mov r0, #funkelstein
cmp r0, r9
bne param_is_not_item_evolution
mov r4, r1
mov r0, r8
bl get_pokemons_gender
cmp r0, #0x0
bne param_is_not_item_evolution
mov r1, r4
b equals_req


get_pokemons_gender:
ldr r1, =0x0803F631
bx r1



equals_req:
ldr r0, =0x0804307D
bx r0

var_access:
ldr r1, =0x0806E3B9
bx r1
