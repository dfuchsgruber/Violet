// This hook renders the pokeballs when a trainer enters the battle in a split-fashion
.global hook_battle_ui_render_pokeball_icons_opponent @ 08048ffc

.align 2
.thumb

.thumb_func
hook_battle_ui_render_pokeball_icons_opponent:
    bl battle_has_two_opponents
    cmp r0, #0
    beq render_pokeball_icons_single_trainer
render_pokeball_icons_double_trainer:
    ldr r0, =0x08049006 | 1
    bx r0
render_pokeball_icons_single_trainer:
    ldr r0, =0x080490b0 | 1
    bx r0


// This hook renders the pokeballs for the player party & partner in a split-fashion
.global hook_battle_ui_render_pokeball_icons_player @ 08048e8e

.align 2
.thumb

.thumb_func
hook_battle_ui_render_pokeball_icons_player:
    bl battle_has_two_players
    cmp r0, #0
    bne render_pokeballs_partner
render_pokeballs_single_player:
    ldr r0, =0x8048f48| 1
    bx r0
render_pokeballs_partner:
    ldr r0, =0x08048e9a | 1
    bx r0


