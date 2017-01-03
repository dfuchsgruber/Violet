@insert the offset of this function as a pointer at 0x419E4 (do not increment | 1)
.align 2
.thumb

.global evolution_stone_remove_item

evolution_stone_remove_item:

ldr r0, =0x800D
bl vardecrypt
mov r1, #0
strh r1, [r0]
ldr r2, [sp, #8]
push {r1-r5}
mov r5, r0

@execute usual code

mov r0, r8
mov r1, #2

bl check_for_evolution
mov r4, r0

ldrh r0, [r5]
cmp r0, #0
beq skip_removing_item

mov r0, #0
strh r0, [r5]

mov r0, r8
mov r1, #0xC
mov r2, r5
bl poke_encrypt

skip_removing_item:
mov r0, r4
pop {r1-r5}
ldr r1, =0x08041F37
bx r1


vardecrypt:
ldr r1, =0x0806E3B9
bx r1

check_for_evolution:
ldr r4, =0x08042dc5
bx r4

poke_encrypt:
ldr r3, =0x0804027D
bx r3
