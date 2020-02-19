@insert at 0x02E3D0 via bx_r0.bin (battle_controller_player_choose_action)

@this code is responsible for spawning the icon for the mega selection

.align 2
.thumb

.global hook_show_mega_icon

hook_show_mega_icon:
push {r4-r7, lr}
mov r7, r8
push {r7}
ldr r7, =0x02023BC4

ldr r0, =0x020370D0
ldr r1, =0xFFFF
strh r1, [r0]	@writing no icon to the oam recently

@checking if we pressed a
ldr r0, =0x03003040
ldrh r1, [r0, #0x2e]	@keypress input
mov r2, #1
and r1, r2
cmp r1, #0
beq end_func

ldrb r1, [r7]
ldr r0, =0x02023FF8
add r0, r1
ldrb r1, [r0]
cmp r1, #0
bne end_func

@now we spawn the oam
ldr r0, = mega_show_icon
bl callr0

end_func:
ldr r0, =0x0802E3D9
callr0:
bx r0


