.align 2
.thumb

.global evolution_m_know_move

evolution_m_know_move:
add r0, r6, r7
lsl r0, #3
add r0, r2
add r4, r0, r3
ldrh r5, [r4, #0x2]

mov r0, r8
mov r1, #0xD	@Move0
bl decrypt
cmp r0, r5
beq has_move

mov r0, r8
mov r1, #0xe	@Move1
bl decrypt
cmp r0, r5
beq has_move

mov r0, r8
mov r1, #0xf	@Move2
bl decrypt
cmp r0, r5
beq has_move

mov r0, r8
mov r1, #0x10	@Move3
bl decrypt
cmp r0, r5
beq has_move
b return
has_move:
ldrh r5, [r4, #0x4]
mov r10, r5
return:
ldr r2, =0x08043011

call_via_r2:
bx r2

decrypt:
push {lr}
ldr r2, =0x0803FAE9
bl call_via_r2
pop {pc}
