#define ASDF 88


.align 2
.thumb

.global after_attack_abilities

.equ lifeorb, 0x3a
.equ attack_data, 0x9100000
.equ bsc_recoil, 0x088AC63B

.equ hochmut, 0x60
.equ bsc_hmut, 0x88ACA20

.equ lernfähig, 0x5E
.equ bsc_lernfähig, 0x88ac980

.equ seeges, 0x65
.equ bsc_seeges, 0x88B3FEE



.thumb_func
after_attack_abilities:
ldr r1, =ASDF
ldr r0, =0x02023D6B	@attacker
ldrb r0, [r0]
mov r1, #0x58
mul r0, r1
ldr r1, =0x02023BE4
add r3, r0,r1
@attacking poke
ldrh r1, [r3, #0x2E]	@item
ldr r2, =lifeorb
cmp r1, r2
bne end_lorb
@has the attacker hp left
ldrh r0, [r3, #0x28]
cmp r0, #0x0
beq end_lorb

@now we must check weather the attack succeded
ldr r0, =0x02023DCC	@attack result
ldrb r1, [r0]
mov r0, #0x29
and r0, r1
cmp r0, #0
bne end_lorb

ldr r0, =attack_data
ldr r1, =0x02023D4A	@active attack
ldrh r1, [r1]
mov r2, #0xC
mul r1, r2
add r0, r1
ldrb r0, [r0, #1]
cmp r0, #0
beq end_lorb	@attack does no dmg
ldr r0, =0x02023D6B	@attacker
ldrb r0, [r0]
lsl r0, #4
ldr r1, =0x02023E8C
add r0, r1

ldrb r0, [r0, #1]
lsl r0, #0x1F

cmp r0, #0
bne end_lorb

@now we can apply life orb recoil
ldrh r0, [r3, #0x2C]	@maxhp
mov r1, #10
bl unsinged_div
@1/10 of max hp as dmg
cmp r0, #0
bne skip
mov r0, #1
skip:
ldr r1, =0x02023D50	@dmg to apply
str r0, [r1]
bl bsc_store_next_cmd_on_stack
ldr r0, =bsc_recoil
ldr r1, =0x02023D74
str r0, [r1]

end_lorb:
mov r0, r3
add r0, #0x20
ldrb r1, [r0]	@ability of attacker
cmp r1, #lernfähig
beq a_lern
cmp r1, #hochmut
beq a_hmut
cmp r1, #seeges
beq a_seeges
end_func:
ldr r0, =0x02023D6C
ldrb r1, [r0]
mov r0, #0
str r0, [sp]
ldr r0, =0x0802350D
bx r0

unsinged_div:
ldr r2, =0x081E7F01
bx r2

bsc_store_next_cmd_on_stack:
ldr r0, =0x080174C9
bx r0

a_lern:
ldr r2, =0x02023DCC	@attack result
ldrb r2, [r2]
lsl r2, #0x1F
cmp r2, #0
beq end_func
@the attack misses
ldrb r0, [r3, #0x1E]	@gen_change
cmp r0, #11
bgt end_func
add r0, #1
strb r0, [r3, #0x1E]
ldr r0, =0x2023FC4
mov r1, #0x14
strb r1, [r0, #0x10]
mov r1, #0x0
strb r1, [r0, #0x11]
mov r1, r10
strb r1, [r0, #0x17]
bl bsc_store_next_cmd_on_stack
ldr r0, =bsc_lernfähig
ldr r1, =0x02023D74
str r0, [r1]
b end_func

a_hmut:
ldr r0, =0x02023DCC	@attack result
ldrb r1, [r0]
mov r0, #0x29
and r0, r1
cmp r0, #0

bne end_func
ldr r0, =attack_data
ldr r1, =0x02023D4A	@active attack
ldrh r1, [r1]
mov r2, #0xC
mul r1, r2
add r0, r1
ldrb r0, [r0, #1]

cmp r0, #0
beq end_func	@attack does no dmg
ldr r0, =0x02023D6B	@attacker
ldrb r0, [r0]
lsl r0, #4
ldr r1, =0x02023E8C
add r0, r1
ldrb r0, [r0, #1]
lsl r0, #0x1F
cmp r0, #0
bne end_func
ldr r0, =0x02023D6C
ldrb r0, [r0]
mov r1, #0x58
mul r0, r1
ldr r1, =0x02023BE4
add r0, r1
ldrh r1, [r0, #0x28]	@opps hp
cmp r1, #0
bne end_func
@now we init bsc
ldrb r0, [r3, #0x19]	@atk boost
cmp r0, #11
bgt end_func
add r0, #1
strb r0, [r3, #0x19]
ldr r0, =0x2023FC4
mov r1, #0xF
strb r1, [r0, #0x10]
mov r1, #0x0
strb r1, [r0, #0x11]
mov r1, r10
strb r1, [r0, #0x17]
bl bsc_store_next_cmd_on_stack
ldr r0, =bsc_hmut
ldr r1, =0x02023D74
str r0, [r1]
b end_func

a_seeges:
ldr r0, =0x02023DCC	@attack result
ldrb r1, [r0]
mov r0, #0x29
and r0, r1
cmp r0, #0
bne end_func
ldr r0, =attack_data
ldr r1, =0x02023D4A	@active attack
ldrh r1, [r1]
mov r2, #0xC
mul r1, r2
add r0, r1
ldrb r0, [r0, #1]
cmp r0, #0
beq end_func	@attack does no dmg
ldrh r0, [r3, #0x28]	@current hp attacker
ldrh r1, [r3, #0x2c]	@max hp
cmp r0, r1
bge end_func
ldr r0, =0x02023D54
ldr r0, [r0]	@total dmg
lsr r0, #2
cmp r0, #0
bne skip_1
mov r0, #1
skip_1:
neg r0, r0
ldr r1, =0x02023D50
str r0, [r1]
bl bsc_store_next_cmd_on_stack
ldr r0, =bsc_seeges
ldr r1, =0x02023D74
str r0, [r1]
b end_func




