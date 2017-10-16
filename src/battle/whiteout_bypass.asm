.include "std.s"

.global battle_whiteout_bypass
.global hook_battle_result

@this code disables the whiteout event and lets the player return to the script even after a loss
@insert at 0x15778 via bx_r0.bin
.align 4
.thumb

.thumb_func
battle_whiteout_bypass:
ldr r0, =BLACKOUT_BYPASS
bl _checkflag
ldr r1, =0x020386CC
cmp r0, #1
bne skip
strh r0, [r1]

skip:
ldrh r0, [r1]
mov r1, #1
and r1, r0
ldr r0, =0x08015780 | 1
bx r0

_checkflag:
ldr r1, =checkflag
bx r1



@insert this code by changing the pointers in the switch table (0x80050, 54) to this code (not | 1)

.align 4
.thumb

hook_battle_result:
ldr r0, =BLACKOUT_BYPASS
bl _checkflag
cmp r0, #1
bne return_true
ldr r1, =0x20370D0	@LASTRESULT
mov r0, #0xFF
strh r0, [r1]	@return 0XFF, the wild battle was lost
mov r0, #0x0
b end_func
return_true:
mov r0, #1
end_func:
pop {r1}
bx r1


