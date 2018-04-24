.align 2
.thumb

.global evolution_m_hitem

evolution_m_hitem:
add r0, r6, r7
lsl r0, #3
add r0, r2
add r4, r0, r3
mov r0, r8
mov r1, #0xC	@Held Item
ldr r2, = 0x0803FAE9	@pokemondecrypt
bl call_via_r2
ldrh r1, [r4, #0x2]
cmp r1, r0
bne return

mov r0, r8
mov r1, #0x0
strh r1, [r0, #0x22]


ldrh r1, [r4, #0x4]
mov r10, r1
return:
ldr r2, =0x08043011

call_via_r2:
bx r2
