.align 2
.thumb

.global restore_trigger_cbs
.global destroy_trigger_cbs

.thumb_func
restore_trigger_cbs:
push {r4-r7, lr}

bl destroy_trigger_cbs

@checking if we need to bring back a callback for any of the own pokemon
mov r4, #0

bring_back_loop:
ldr r0, =0x02023BCC
ldrb r1, [r0]
cmp r4, r1
bge end_func
mov r0, r4
bl _is_opponent
cmp r0, #0
bne next_poke

@now we check if the pokemon has an active trigger
ldr r0, =0x02023BE4
mov r1, #0x58
mul r1, r4
add r0, r1
add r0, #0x3B
ldrb r1, [r0]
cmp r1, #0
beq next_poke

@pokemon has an active trigger, so we have to spawn the callback
mov r5, r0
ldr r0, =mega_trigger_callback
mov r1, #0
bl _spawn_big_callback
mov r1, #0x28
mul r0, r1
ldr r1, =0x03004FE0
add r0, r1
str r5, [r0, #8]
strb r4, [r0, #0x10]


next_poke:
add r4, #1
b bring_back_loop
end_func:
pop {r4-r7, pc}


_is_opponent:
ldr r1, =is_opponent
bx r1

.thumb_func
destroy_trigger_cbs:
push {lr}
destruction_loop:
ldr r0, =mega_trigger_callback
bl search_if_func_is_already_a_cb
cmp r0, #0xFF
beq exit_loop
bl fake_trigger_cb
b destruction_loop
exit_loop:
pop {pc}


fake_trigger_cb:
push {r4-r5, lr}
mov r5, r0
mov r1, #0x28
mul r0, r1
ldr r1, =0x03004FE0
add r2, r0, r1
ldrb r0, [r2, #0x10]	@related index
ldr r1, =0x02023d44
add r0, r1
ldrb r1, [r0]
mov r0, #0x44
mul r0, r1
ldr r1, =0x0202063C
add r0, r1
ldrh r0, [r0, #4]	@palette
lsr r0, #12

add r0, #16
lsl r0, #4
mov r1, #0x10
mov r2, #0
mov r3, #0
bl color_blend
mov r0, r5
bl remove_big_cb
pop {r4-r5, pc}

color_blend:
ldr r4, =0x08045179
bx r4

remove_big_cb:
ldr r1, =0x0807746D
bx r1

search_if_func_is_already_a_cb:
ldr r1, =0x80775ED
bx r1

_spawn_big_callback:
ldr r2, =spawn_big_callback
bx r2
