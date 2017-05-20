
.align 2
.thumb

.global hook_turn_end

hook_turn_end:
ldr r0, =0x02023D6B
mov r1, r10
strb r1, [r0]
mov r2, r8
ldrb r5, [r2]	@ability
mov r0, r5
mov r1, r4
bl turn_end
cmp r0, #0
beq end_event
end_withbsc:
ldr r0, =0x801BADF
bx r0
end_event:
ldr r4, =0x0801BB2D
bx r4
