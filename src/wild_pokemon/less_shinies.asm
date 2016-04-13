.align 2
.thumb

.global wild_poke_less_shinies

wild_poke_less_shinies:
lsr r4, #0x10
lsl r0, #0x10
orr r4, r0
bl rnd
lsl r0, #0x1F
cmp r0, #0
bne valid_shiny
@50 % chance that a shiny will be downgraded
mov r0, #0x2
lsl r0, #0x10
orr r4, r0
valid_shiny:
str r4, [sp, #0x14]
ldr r0, =0x0803DA15
bx r0





rnd:
ldr r1, =random_change_seed
bx r1
