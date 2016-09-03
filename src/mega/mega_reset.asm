@insert at 0x79D20 via bx_r1.bin

@insert at 0x79D20 via bx_r1.bin
.align 2
.thumb

.global mega_reset

.equ table, megas

.thumb_func
mega_reset:
push {r4, lr}
lsl r0, #0x18
lsr r4, r0, #0x18
push {r5-r7}

ldr r0, =0x920
bl clearflag

bl count_pokemon
mov r5, r0
mov r6, #0

pokemon_loop:
cmp r6, r5
bge end_func

mov r0, #0x64
mul r0, r6
ldr r1, =0x02024284
add r7, r1, r0

@get species
mov r0, r7
mov r1, #0xB
mov r2, #0
bl get_attr

ldr r1, =table @mega table
ldr r2, =0xFFFF @termination

scan_table:
ldrh r3, [r1, #4]
cmp r3, r2
beq end_scan_table
cmp r3, r0
bne table_next

@we found a mega poke we have to revert
mov r2, r1
mov r1, #0xB
mov r0, r7
bl set_attr

mov r0, r7
bl recalculate_stats

b end_scan_table

table_next:
add r1, #8
b scan_table

end_scan_table:
add r6, #1
b pokemon_loop


end_func:
pop {r5-r7}
ldr r2, =0x02037F34
ldr r1, =0x08079D29
bx r1

count_pokemon:
ldr r0, =0x08040B3D
bx r0

clearflag:
ldr r1, =0x0806E60D
bx r1


recalculate_stats:
ldr r1, =0x0803E37D
bx r1


get_attr:
ldr r3, =0x0803FAE9
bx r3

set_attr:
ldr r3, =0x0804027D
bx r3
