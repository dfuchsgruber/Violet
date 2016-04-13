.align 2
.thumb

.global tm_count_arrows
.thumb_func
tm_count_arrows:

ldrh r0, [r5, #0xA]	@item
mov r6, r1
mov r4, r2
bl item_get_pocket
cmp r0, #4
bne skip_write

mov r4, #1
strh r4, [r6, #0x14]

skip_write:
cmp r4, #1
beq skip_spawn

bl pokemart_spawn_counter_arrows

skip_spawn:
ldr r0, =0x0809BE4D
bx r0

pokemart_spawn_counter_arrows:
ldr r0, =0x809B7E1
bx r0
