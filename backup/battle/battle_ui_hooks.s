// This hook renders the pokeballs when a trainer enters the battle in a split-fashion
.global hook_battle_ui_render_pokeball_icons @ 08048ffc

hook_battle_ui_render_pokeball_icons:
    bl battle_has_two_opponents
    cmp r0, #0
    beq render_pokeball_icons_single_trainer
render_pokeball_icons_double_trainer:
    ldr r0, =0x08049006 | 1
    bx r0
render_pokeball_icons_single_trainer:
    ldr r0, =0x080490b0 | 1
    bx r0

