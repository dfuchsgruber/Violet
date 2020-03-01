.global battle_allocate_hook

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

battle_free_hook:
    bl battle_free_new
    pop {r4, r5, r6}
    pop {r0}
    bx r0
