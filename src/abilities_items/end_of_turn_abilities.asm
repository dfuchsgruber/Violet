
.align 2
.thumb

.global end_of_turn_ab

.equ bsc_recoil, 0x88AC497
.equ bsc_rage, 0x88AC8A5
.equ bsc_lucid, 0x88bb750

@these abilities boost your attack/satk by 50% however you loose 1/8 of your hp at end of turn if the weather is active
.equ solarkraft, 0x54
.equ regenmut, 0x55
.equ kältewahn, 0x56
.equ sandherz, 0x57
.equ rage, 0x59
.equ lucid, 0x63


end_of_turn_ab:
ldr r0, =0x02023D6B
mov r1, r10
strb r1, [r0]
mov r2, r8
ldrb r5, [r2]	@ability
cmp r5, #solarkraft
beq skraft
cmp r5, #regenmut
beq rmut
cmp r5, #kältewahn
beq kwahn
cmp r5, #sandherz
beq sherz
cmp r5, #rage
beq rge
cmp r5, #lucid
beq wld
@now we return to the normal checks!
ldr r1, =0x0801A383
bx r1

skraft:
mov r0, #0x40	@bit 6
b check_for_weather
rmut:
mov r0, #0x7
b check_for_weather
kwahn:
mov r0, #0x80	@bit 7
b check_for_weather
sherz:
mov r0, #0x10
check_for_weather:	@recieves r0 the bit that has to be set
ldr r1, =0x2023F1C
ldrh r1, [r1]
and r1, r0
cmp r1, #0
beq end_event

@now we must check if weather negating abilities are present
mov r0, #0xD
bl check_if_ability_is_present

cmp r0, #0
bne end_event
mov r0, #0x4D
bl check_if_ability_is_present
cmp r0, #0
bne end_event
mov r0, r8
strb r5, [r0]
ldr r1, =0x02023D50
ldrh r0, [r4, #0x2C]
lsr r0, #3
cmp r0, #0
bne skip_set_1
mov r0, #1
skip_set_1:
str r0, [r1]

@now we init our BSC
ldr r0, =bsc_recoil
end_withbsc:
bl init_bsc
ldr r0, =0x801BADF
bx r0
end_event:
ldr r4, =0x0801BB2D
bx r4

check_if_ability_is_present:
push {r4,lr}
sub sp, #0x4
mov r2, r0
mov r0, #0
str r0, [sp]
mov r0, #0x13
mov r1, #0x0
mov r3, #0x0
bl ab_management
add sp, #0x4
pop {r4,pc}

ab_management:
ldr r4, =0x08019E9D
bx r4

init_bsc:
ldr r1, =0x801BBA9
bx r1

rge:	@r4 current poke
ldrb r0, [r4, #0x19]	@atk boost
cmp r0, #11
bgt end_event
ldrb r1, [r4, #0x1a]	@def boost
cmp r1, #0
beq end_event
add r0, #1
sub r1, #1
strb r0, [r4, #0x19]
strb r1, [r4, #0x1a]
ldr r0, =0x2023FC4
mov r1, #0xF
strb r1, [r0, #0x10]
mov r1, #0x0
strb r1, [r0, #0x11]
mov r1, r10
strb r1, [r0, #0x17]
ldr r0, =bsc_rage
b end_withbsc

wld:
mov r0, #0x4C
add r0, r4
ldr r0, [r0]	@status conditions
mov r1, #0x7
and r0, r1		@sleeping bits
cmp r0, #0
beq end_event
@the poke is asleep
ldrb r0, [r4, #0x1c]	@satk boost
cmp r0, #11
bgt end_event
add r0, #1
strb r0, [r4, #0x1c]	@inc sattack
ldr r0, =0x2023FC4
mov r1, #0x12
strb r1, [r0, #0x10]
mov r1, #0x0
strb r1, [r0, #0x11]
mov r1, r10
strb r1, [r0, #0x17]
ldr r0, =bsc_lucid
b end_withbsc





