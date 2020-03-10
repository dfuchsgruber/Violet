.global battle_intro_draw_pokemon_or_trainer_sprite_hook

.align 2
.thumb

.thumb_func
battle_intro_draw_pokemon_or_trainer_sprite_hook:
    bl battle_intro_draw_pokemon_or_trainer_sprite_draw_second_trainer
    // Loop footer
    mov r2, r9
    ldrb r0, [r2]
    add r0, #1
    strb r0, [r2]
    ldr r1, =0x08013284 | 1
    bx r1


.global battle_intro_trainer_pokemon_send_out_hook

.align 2
.thumb

.thumb_func
battle_intro_trainer_pokemon_send_out_hook:
    bl battle_has_two_opponents
    cmp r0, #0
    beq ret_08038d30
ret_08038cfe:
    ldr r0, =0x08038cfe | 1
    bx r0
ret_08038d30:
    ldr r0, =0x08038d30 | 1
    bx r0


.global battle_intro_trainer_pokemon_send_out_hook2

.align 2
.thumb

.thumb_func
battle_intro_trainer_pokemon_send_out_hook2:
    bl battle_has_two_opponents
    cmp r0, #0
    ldr r1, =0x08035da8 | 1
    bx r1


.global battle_intro_trainer_pokemon_send_out_hook3

.align 2
.thumb

.thumb_func
battle_intro_trainer_pokemon_send_out_hook3:
    bl battle_has_two_opponents
    cmp r0, #0
    beq ret_08013702
ret_080136e8:
    ldr r0, =0x080136e8 | 1
    bx r0
ret_08013702:
    ldr r0, =0x08013702 | 1
    bx r0

.global battle_controller_opponent_create_trainer_pic_oam_hook

.align 2
.thumb

.thumb_func
battle_controller_opponent_create_trainer_pic_oam_hook:
    bl battle_controller_opponent_create_trainer_pic_oam
    ldr r1, = 0x08037c8e | 1
    bx r1

.global battle_switch_in_clear_hook

.align 2
.thumb

.thumb_func
battle_switch_in_clear_hook:
    bl battle_switch_in_clear_new
    add sp, #0x1C
    pop {r3, r4, r5}
    mov r8, r3
    mov r9, r4
    mov r10, r5
    pop {r4-r7}
    pop {r0}
    bx r0
