.align 2
.thumb

.global evolution_m_map

evolution_m_map:

add r0, r6, r7
lsl r0, #3
add r0, r2
add r1, r0, r3

ldrh r0, [r1, #0x2]		@condition
ldr r2, = 0x2025530 	@current Map
ldrh r2, [r2]			@Map, Bank
cmp r0, r2
bne no_evolution
ldrh r1, [r1, #0x4]
mov r10, r1
no_evolution:
ldr r0, =0x08043011
bx r0

