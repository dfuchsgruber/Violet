@insert at 0x3485C via bx_r0.bin

.global hook_spawn_symbol

.align 2
.thumb


hook_spawn_symbol:
mov r0, r5
ldr r1, =spawn_symbols
bl call_r1
mov r0, r6
pop {r4-r6, pc}


call_r1:
bx r1
