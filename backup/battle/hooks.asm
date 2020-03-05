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
