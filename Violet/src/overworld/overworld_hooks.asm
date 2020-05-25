.global hook_overworld_createsprite_load_npc_palette
.global hook_overworld_fame_checker_npc_palette
.global hook_npc_create_by_person
.global hook_npc_create_by_npc
.global hook_npc_create_by_npc2
.global hook_npc_create_oam_template

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


.align 4
.thumb

.thumb_func
// Creating a npc by a person should respect the extension
hook_npc_create_by_person:
    mov r0, r9
    bl overworld_get_by_person
    ldr r1, = 0x0805e760 | 1
    bx r1
    

.align 4
.thumb

.thumb_func
// Creating a npc by a person should respect the extension
hook_npc_create_by_npc:
    add r5, r0, r1 // npc *n
    mov r0, r5
    bl overworld_get_by_npc
    ldr r1, = 0x0805e5dc | 1
    bx r1
    
.align 4
.thumb

.thumb_func
// Creating a npc by a person should respect the extension
hook_npc_create_by_npc2:
    str r0, [sp, #0x20] // Removed by hook
    mov r0, r6 // npc *n
    bl overworld_get_by_npc
    ldr r1, = 0x0805ee90 | 1
    bx r1
    
.align 4
.thumb

.thumb_func
// When creating the oam template, we should respect the extension
hook_npc_create_oam_template:
    mov r0, r6
    add r3, sp, #0x20
    mov r2, sp
    bl overworld_create_oam_template_by_npc_with_movement_callback
    ldr r0, =0x0805eeac | 1
    bx r0
 