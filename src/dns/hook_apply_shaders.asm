.align 2
.thumb

.global dns_hook_apply_shaders
.global dns_hook_apply_shaders2
.global dns_hook_apply_shaders3

.thumb_func
dns_hook_apply_shaders:
push {r4, r5, lr}
lsl r0, #0x10
lsr r4, r0, #0x10
lsl r1, #0x10
lsr r5, r1, #0x10
ldr r0, =0x02036E28	@pal shaders
ldr r1, [r0]
cmp r1, #0
bne no_dns_shader

mov r0, r4
mov r1, r5
bl dns_apply_shaders


no_dns_shader:
ldr r0, =0x080598D7
bx r0

@08059948

.thumb_func
dns_hook_apply_shaders2:
push {r4-r6, lr}
lsl r0, #0x10
lsr r4, r0, #0x10
lsl r1, #0x10
lsr r5, r1, #0x10
ldr r0, =0x02036E28	@pal shaders
ldr r1, [r0]
cmp r1, #0
bne no_dns_shader2

mov r0, r4
mov r1, r5
bl dns_apply_shaders


no_dns_shader2:
ldr r0, =0x08059953
bx r0

.thumb_func
dns_hook_apply_shaders3:
push {r4, lr}
lsl r0, #0x18
lsr r4, r0, #0x18
ldr r0, =0x02036E28	@pal shaders
ldr r1, [r0]
cmp r1, #0
bne no_dns_shader3

mov r0, r4
add r0, #0x10
lsl r0, #4
mov r1, #0x10


bl dns_apply_shaders

@transfer the pal into palram
ldr r0, =0x020371F8
mov r1, r4
add r1, #0x10
lsl r1, #5
add r0, r1
ldr r2, =0x020375F8
add r1, r2
mov r2, #0x8
swi 0xC


no_dns_shader3:
ldr r0, =0x02036E28	
ldr r1, =0x08083505
bx r1
