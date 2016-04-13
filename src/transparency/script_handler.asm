@insert at 0x069848 via bx_r0.bin
@if cntrl flag is set the transparency changes are overrided till the flag is cleared
@status flag is important for the palettes and states if transparecny is on or off
@table is a list of commands, which deactivate the transparecny ([byte: cmd] 00 [byte: cmd] 00 [FF FF: end])
@recommended commands are 02, 97, 5C, 5D, B7, 29
.align 2
.thumb

.equ table, 0x9181600
.equ cntrl_flag, 0x911
.equ status_flag, 0x910
.equ special_table, 0x9197180

.global transparency_script_handler

.thumb_func
transparency_script_handler:
ldr r0, =cntrl_flag
bl checkflag
cmp r0, #0
bne disables
ldr r3, =0xFFFF @terminate
ldr r2, [r4, #0x8]
ldrb r0, [r2]	@loading command id
cmp r0, #0x27 @waitstate skips this
beq return
cmp r0, #0x25
beq special
cmp r0, #0x26
beq special
ldr r1, =table

scan_table:
ldrh r2, [r1]
cmp r2, r3
beq ables
cmp r2, r0
beq disables
add r1, #2
b scan_table
ables:
mov r0, #1
b set
disables:
mov r0, #0
set:
bl set_trans
return:
@this is the regular script handler
ldr r2, [r4, #0x8]
ldrb r1, [r2]
add r0, r2, #1
str r0, [r4, #0x8]
lsl r1, #2
ldr r0, =0x08069851
bx r0

special:
ldrb r0, [r2, #0x1]
ldrb r1, [r2, #0x2]
lsl r1, #8
add r0, r1
ldr r1, =special_table
b scan_table



set_trans:
push {lr}
ldr r1, =0x0202555A
ldrb r1, [r1]
cmp r1, #6
beq clear_transflag
cmp r1, #8
beq clear_transflag
cmp r1, #9
beq clear_transflag
cmp r1, #0xa
beq clear_transflag

cmp r0, #0
beq disable
ldr r0, =0x04000048
mov r1, #0x3f
strb r1, [r0]
mov r1, #0x1F
strb r1, [r0, #1]
ldr r1, =0x0a0f3f41
str r1, [r0, #0x8]
ldr r0, =status_flag
bl setflag
b end_func

disable:
ldr r0, =0x04000048
mov r1, #0x1f
strb r1, [r0]
mov r1, #0x1F
strb r1, [r0, #1]
ldr r1, =0x101E40
str r1, [r0, #0x8]
ldr r0, =status_flag
clear_transflag:
ldr r0, =status_flag
bl clearflag
end_func:
pop {pc}


setflag:
ldr r1, =0x0806E5E5
bx r1

clearflag:
ldr r1, =0x0806E60D
bx r1

checkflag:
ldr r1, =0x0806E635
bx r1


