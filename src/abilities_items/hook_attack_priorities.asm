.global hook_attack_priorities

.align 2
.thumb

.thumb_func
hook_attack_priorities:
mov r4, r2
mov r0, r3
mov r1, r9
bl attack_priority_get
@r0 players prio
mov r1, r4
mov r4, r0
mov r0, r1
mov r1, r10
bl attack_priority_get
@r0 opps_priority, r4 players_priority
mov r1, r4
cmp r1, #0x0
bne notboth_0
cmp r0, #0x0
beq both_0
notboth_0:
cmp r1, r0
bne prios_unequal
ldr r0, =0x08014FCD
bx r0
both_0:
ldr r0, =0x08014FFD
bx r0
prios_unequal:
ldr r2, =0x8014FF3
bx r2
