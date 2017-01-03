@insert at 0x020FDC via bx_r0.bin


.align 2
.thumb

.global hook_knock_off

.thumb_func
hook_knock_off:
push {r0-r3}	@i hate to do this, but we have to
mov r0, r1
bl is_item_removable
cmp r0, #0
beq bsc_next
pop {r0-r3}
ldrh r0, [r1, #0x2E]
cmp r0, #0
beq bsc_next_n
mov r0, r3
ldr r1, =0x08020FE5
bx r1

bsc_next:
pop {r0-r3}
bsc_next_n:
ldr r0, =0x08021071
bx r0



