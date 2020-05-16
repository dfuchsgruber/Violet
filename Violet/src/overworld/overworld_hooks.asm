.global hook_overworld_createsprite_load_npc_palette
.global hook_overworld_fame_checker_npc_palette

.align 4
.thumb

.thumb_func
// Makes createsprite dynamically allocate the palette
hook_overworld_createsprite_load_npc_palette:
    mov r0, sp
    bl overworld_npc_load_palette_by_template
    ldr r0, = 0x0805ea48 | 1
    bx r0

.align 4
.thumb

.thumb_func
// Makes famechecker dynamically allocate the palette
hook_overworld_fame_checker_npc_palette:
    mov r0, sp
    bl overworld_npc_load_palette_by_template
    ldr r0, = 0x0805eb80 | 1
    bx r0
