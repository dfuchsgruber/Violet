@insert at 0x020D44 via bx_r0.bin

.align 2
.thumb

.global hook_thief

.thumb_func
hook_thief:
@check if r3 matches a mega table
ldr r0, =0x02023D6C	@defender
ldrb r1, [r0]
mov r0, #0x58
mul r1, r0
ldr r0, =0x002023BE4	@battler data
add r0, r1
ldrh r1, [r0, #0x2E]
cmp r1, #0
beq bsc_next

mov r4, r3
bl is_item_removable
cmp r0, #0
beq bsc_next
mov r3, r4
mov r4, #0
mov r0, r3
sub r0, #0x79
lsl r0, #16
lsr r0, #16
cmp r0, #0xB
bhi thief
bsc_next:
ldr r0, =0x08021071
bx r0



thief:
ldr r0, =0x08020D59
bx r0
