.global battle_allocate_hook

.align 2
.thumb

.thumb_func
battle_allocate_hook:
    bl _bg_set_tilemap
    bl battle_allocate_new
    pop {r4, r5}
    pop {r0}
    bx r0

_bg_set_tilemap:
    ldr r2, =bg_set_tilemap
    bx r2

.global battle_free_hook

.align 2
.thumb

.thumb_func
battle_free_hook:
    bl battle_free_new
    pop {r4, r5, r6}
    pop {r0}
    bx r0

.global battle_string_decrypt_additional_buffers_hook

.align 2
.thumb

.thumb_func
battle_string_decrypt_additional_buffers_hook:
    ldrb r0, [r2]
    cmp r0, #0x1D
    beq _decrypt_additional // TrainerA name
    cmp r0, #0x2E
    beq _decrypt_additional // TrainerB defeat text
    cmp r0, #0x2F
    beq _decrypt_additional // TrainerB victory text
    cmp r0, #0x30
    bls _decrypt_buffers_normal
_decrypt_additional:
    bl battle_string_decrypt_additional_buffers
    cmp r0, #0
    beq _could_not_decrypt
    // A new controll character was decrypted
    mov r4, r0
    ldr r0, =0x080d858a | 1
    bx r0

_could_not_decrypt:
    ldr r0, =0x080d858a | 1
    bx r0

_decrypt_buffers_normal: // These buffers can be decrypted by the firered engine
    ldr r1, =0x080d7b4a | 1
    bx r1

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
    bl battle_controller_double_battle_should_send_out_only_one_pokemon
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
    bl battle_controller_double_battle_should_send_out_only_one_pokemon
    cmp r0, #0
    ldr r1, =0x08035da8 | 1
    bx r1


.global battle_intro_trainer_pokemon_send_out_hook3

.align 2
.thumb

.thumb_func
battle_intro_trainer_pokemon_send_out_hook3:
    bl battle_controller_double_battle_should_send_out_only_one_pokemon
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

.global hook_clear_temporary_effects

.align 2
.thumb

.thumb_func
hook_clear_temporary_effects:
    mov r0, r9
    bl battle_clear_temporary_custom_effects
    pop {r3-r5}
    mov r8, r3
    mov r9, r4
    mov r10, r5
    pop {r4-r7}
    pop {r0}
    bx r0


.global battle_hook_before_attack

.align 2
.thumb

@//insert via bx_r2 at 0x080162D0
.thumb_func
battle_hook_before_attack:
    strb r0, [r1]
    bl battle_before_attack_effects
    add sp, #8
    pop {r3-r5}
    mov r8, r3
    mov r9, r4
    mov r10, r5
    pop {r4-r7}
    pop {r0}
    bx r0



.global hook_battle_item_switch_in_effects

.align 2
.thumb

@ insert at 0x0801bce4 as a pointer in a jump-table (i.e. without | 1)
.thumb_func
hook_battle_item_switch_in_effects:
    mov r0, r7
    bl battle_items_switch_in_effects
    cmp r0, #0xFF
    beq battle_items_effect_with_no_bsc_activated
    cmp r0, #0
    bne battle_items_switch_in_effect_activated
    ldr r0, = 0x0801bcf8 | 1 // Resume to the original functions, i.e. amulett coin and white herb
    bx r0

battle_items_switch_in_effect_activated:
    str r0, [sp, #0xC] // Return effect
battle_items_effect_with_no_bsc_activated:
    ldr r0, = 0x0801cf2a | 1 // End the function, but return 0 overall
    bx r0

.global battle_item_effect_after_attack_hook

.align 2
.thumb

.thumb_func
battle_item_effect_after_attack_hook:
    mov r0, r7 @ battler_idx
    mov r1, r6 @ move_turn
    bl battle_item_effect_after_attack
    cmp r0, #0
    bne battle_item_effect_after_attack_happened
    sub r0, r5, #1
    cmp r0, #0x2a
    bls battle_item_effect_after_attack_hook_jpt
battle_item_effect_after_attack_break:
    ldr r1, =0x0801c8d6 | 1
    bx r1
battle_item_effect_after_attack_hook_jpt:
    ldr r1, =0x0801bda6 | 1
    bx r1
battle_item_effect_after_attack_happened:
    str r0, [sp, #0xC]
    b battle_item_effect_after_attack_break
