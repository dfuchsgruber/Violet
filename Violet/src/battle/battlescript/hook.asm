.include "pokemon_attributes.s"

.global hook_bsc_cmd_xEF_handleballthrow_select_target
.global hook_ball_throw_anim_callback_select_target
.global hook_bsc_cmd_xF2_display_dex_entry
.global hook_battle_handle_action_selection_before_action_chosen

.align 4
.thumb

.thumb_func
hook_bsc_cmd_xEF_handleballthrow_select_target:
    ldr r5, =active_battler
    ldr r0, =attacking_battler
    ldrb r0, [r0]
    strb r0, [r5]
    ldr r6, =defending_battler
    bl bsc_cmd_xEF_determine_target_to_catch
    strb r0, [r6]
    ldr r0, =0x0802d3ea | 1
    bx r0

.align 4
.thumb

.thumb_func
hook_ball_throw_anim_callback_select_target:
    push {r4, r5, r6}
    lsl r0, #0x18
    lsr r0, #0x18
    mov r10, r0
    bl bsc_cmd_xEF_determine_target_to_catch
    ldr r1, =battle_animation_target
    strb r0, [r1]
    ldr r0, =0x080ef846 | 1
    bx r0

.align 4
.thumb

.thumb_func
hook_bsc_cmd_xF2_display_dex_entry:
    push {r4-r5, lr}
    sub sp, #0x18
    bl battle_get_catch_target_pokemon
    mov r1, #ATTRIBUTE_SPECIES
    ldr r2, =0x0802d978 | 1
    bx r2

.align 4
.thumb

.thumb_func
hook_battle_handle_action_selection_before_action_chosen:
    // This prevents the action on the right player mon in wild double battles if neccessary
    bl battle_handle_turn_selection_actions_are_prevented
    cmp r0, #0
    bne action_prevented
    // The mon can select an action, replace the code deleted by the hook
    ldr r0, =battler_action_chosen
    ldrb r1, [r0]
    ldr r0, =battle_general_buffers1
    ldrb r2, [r0, #1]
    ldr r3, =0x08014148 | 1
    bx r3
action_prevented: // The player's right mon can't act
    ldr r0, =0x08014bd2 | 1
    bx r0
