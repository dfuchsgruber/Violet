@this code starts an attack animation without any table required
@signature: (u8 user_index, u8 target_index, void* script)


.global call_attack_anim_by_offset

.align 2
.thumb

.thumb_func
call_attack_anim_by_offset:
push {r4, lr}
lsl r0, #0x18
lsr r0, #0x18
mov r4, r0	@store user for rest of func
ldr r0, =0x02037F1A
strb r4, [r0]
ldr r0, =0x02037F1B
strb r1, [r0]

@now we pretend a table
sub sp, #0x4
str r2, [sp]
mov r0, sp
mov r1, #0
mov r2, #0
bl start_anim_by_table_nd_index

add sp, #0x4

@return to rest of function (spawns a callback for the execution)
ldr r0, =0x080340F7
bx r0


start_anim_by_table_nd_index:
ldr r3, =0x08072539
bx r3
