.global tile_tall_grass_init_hook
.global tile_is_high_grass_hook
.global tile_is_any_grass_hook
.global tile_high_grass_init_hook


.align 2
.thumb

.thumb_func
tile_tall_grass_init_hook:
    
    mov r0, sp
    bl tile_any_grass_init
    ldr r1, =0x080DB84D
    bx r1


.thumb_func
tile_high_grass_init_hook:
    mov r0, sp
    bl tile_any_grass_init
    ldr r1, =0x080DB5A1
    bx r1


.thumb_func
tile_is_high_grass_hook:
    push {lr}
    bl tile_is_high_grass
    pop {r1}
    bx r1

.thumb_func
tile_is_any_grass_hook:
    push {lr}
    bl tile_is_any_grass
    pop {r1}
    bx r1
    
    
