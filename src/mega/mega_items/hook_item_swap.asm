@inser at 0x02C150 via bx_r0.bin

.align 2
.thumb


.global is_item_removable
.global hook_item_swap

.thumb_func
hook_item_swap:
ldrb r0, [r7]
mov r7, r3
mul r0, r5
add r0, r8
bl is_item_removable
cmp r0, #0
beq fail_script
ldr r0, =0x02023D6B
ldrb r0, [r0]
mul r0, r5
add r0, r8
bl is_item_removable
cmp r0, #0
beq fail_script


@items can be swapped
mov r3, r7
ldr r7, =0x02023D6C
ldrb r0, [r7]
mul r0, r5
mov r2, r8
add r1, r0, r2
ldr r2, =0x802C159
bx r2



fail_script:
ldr r0, =0x0802C177
bx r0





.thumb_func
is_item_removable:	@bool func (battler* b)

push {r4-r5, lr}
ldrh r2, [r0]	@target species
ldrh r3, [r0, #0x2E]	@target item
ldr r0, =megas
ldr r1, =0xFFFF
scan_table:
ldrh r5, [r0]	@species
cmp r5, r1
beq return_true
ldrh r4, [r0, #2]	@item
cmp r4, r3
bne next_entry
cmp r5, r2
beq return_false
ldrh r4, [r0, #4]	@target
cmp r4, r2
beq return_false
next_entry:
add r0, #8
b scan_table
return_false:
mov r0, #0
b return
return_true:
mov r0, #1
return:
pop {r4-r5, pc}













