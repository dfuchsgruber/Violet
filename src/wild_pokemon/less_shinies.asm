.align 2
.thumb

.global wild_poke_less_shinies

wild_poke_less_shinies:
lsr r4, #0x10
lsl r0, #0x10
orr r0, r4
bl pid_shinyness_apply
mov r4, r0
valid_shiny:
str r4, [sp, #0x14]
ldr r0, =0x0803DA15
bx r0





rnd:
ldr r1, =random_change_seed
bx r1
