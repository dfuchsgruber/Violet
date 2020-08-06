
.org 0x800fce0
	.word battle_bgs

.org 0x800fd0c
	.word battle_bgs

.org 0x080738C4
        .word battle_anim_bgs


.org 0x0800F3D8
        .word gfx_battle_boxTiles

.org 0x0800F3E0
        .word gfx_battle_boxPal

//bsc strings

.org 0x80cf194
	.word bsc_strings

.org 0x80cf270
	.word bsc_strings

.org 0x80cf2b8
	.word bsc_strings

.org 0x80cf350
	.word bsc_strings

.org 0x80cf530
	.word bsc_strings

.org 0x80cf5b0
	.word bsc_strings

.org 0x80cf5f8
	.word bsc_strings

.org 0x80cf640
	.word bsc_strings

.org 0x80cf674
	.word bsc_strings

.org 0x80cf6a0
	.word bsc_strings

.org 0x80cfcd0
	.word bsc_strings

.org 0x80cfda8
	.word bsc_strings

.org 0x80cfdf0
	.word bsc_strings

.org 0x80cfe90
	.word bsc_strings

.org 0x80cff0c
	.word bsc_strings

.org 0x80cff48
	.word bsc_strings

.org 0x80d0058
	.word bsc_strings

.org 0x80d00c4
	.word bsc_strings

.org 0x80d010c
	.word bsc_strings

.org 0x80d0154
	.word bsc_strings

.org 0x80d0188
	.word bsc_strings

.org 0x80d01b4
	.word bsc_strings

.org 0x80d79b8
	.word bsc_strings

.org 0x80d86a4
	.word bsc_strings


.org 0x0800F1E4
        ldr r1, =battle_bg_load | 1
        bx r1
        .pool

.org 0x0800F230
        ldr r1, =battle_bg_load_anim | 1
        bx r1
       .pool

.org 0x0800F270
       push{r4, lr}
       ldr r4, =battle_bg_get | 1
        bl blxr4
        pop {r4}
        pop {r0}
        bx r0
blxr4:
       bx r4
        .pool

.org 0x0802d9b0
        .word battle_bg_catch

.org 0x800FBB0
        ldr r0, =battle_bg_get_id | 1
        bx r0
        .pool

.org 0x080CDFB8
        ldr r0, =battle_bg_evolution1 | 1
        bx r0
        .pool

.org 0x080CE20C
        ldr r0, =battle_bg_evolution2 | 1
        bx r0
        .pool

.org 0x080CE344
        ldr r1, =battle_bg_evolution3 | 1
        bx r1
        .pool


        
//@battlestring remove the bsc string limitation (extend it to 0x7FFF)
.org 0x080D7988
    .halfword 0x7FFF

//@battlestring remove attack limitations
.org 0x080D80AA
    mov r0, #0x7F
    lsl r0, #0x18 //high number so that all attacks are valid

.org 0x080D80C2
    mov r0, #0x7F
    lsl r0, #0x18 //high number so all attacks are valid


.org 0x080bc48c
	push {r4, lr}
	mov r4, #0 // Always use the slide function of terrain 0
	ldr r0, = 0x080bc568 | 1
	b 0x080bc4d4
	.pool

// Slide function of terrain 0: DMA0 sets BG3X, which we set to 0 for the entire scanline
.org 0x080bc6f0
	mov r0, #0
.org 0x080bc71c
	mov r0, #0


.org 0x8014ba0
	.word battle_script_cmds

.org 0x80159ac
	.word battle_script_cmds

.org 0x8015bf0
	.word battle_script_cmds

.org 0x8015c1c
	.word battle_script_cmds

.org 0x801cfd8
	.word battle_script_cmds


.org 0x080153B4
        ldr r0, =hook_clear_temporary_effects | 1
        bx r0
        .pool

.org 0x08080404
    .word battle_trainerbattle_continuation | 1

.org 0x0807fb04
	ldr r0, =battle_scripted_wild_battle_continuation | 1
	bx r0
	.pool
	
.org 0x0807f57c
	.word whiteout_callback_print_text | 1

.org 0x080BFEA0
	ldr r1, =whiteout_setup_warp | 1
	bx r1
	.pool

.org 0x0807F530
	.word ow_script_whiteout_joy


.org 0x0807F550
	.word ow_script_whiteout_mother

// Obedience changes
.org 0x0801D40A
	ldr r0, =battle_obedience_get_max_level | 1
	bl _blxr0
	mov r6, r0
	ldr r0, =0x0801D442 | 1
_blxr0:
	bx r0
	.pool

.org 0x08014C5C
	ldr r3, =priority_compare | 1
	bx r3
	.pool

// healthbars
.org 0x0826012C
	.word gfx_healthbar_player_single_battleTiles
.org 0x08260134
	.word gfx_healthbar_opponent_single_battleTiles
.org 0x0826013C
	.word gfx_healthbar_player_double_battleTiles
.org 0x08260144
	.word gfx_healthbar_player_double_battleTiles
.org 0x0826014C
	.word gfx_healthbar_opponent_double_battleTiles
.org 0x08260154
	.word gfx_healthbar_opponent_double_battleTiles
.org 0x0826015C
	.word gfx_healthbar_safariTiles
.org 0x08260184
	.word gfx_healthbar_player_single_battlePal
.org 0x082603a0
	.word gfx_healthbar_player_single_battlePal
.org 0x082603a8
	.word gfx_healthbar_player_single_battlePal

.org 0x0802e0a6
	ldr r2, =battle_allocate_hook | 1
_blxr2:
	bx r2
	.pool

.org 0x0802e198
	ldr r0, =battle_free_hook | 1
	bx r0
	.pool

.org 0x08034050
	.word battle_animations

.org 0x080803c0	
	ldr r0, =battle_initialize_trainerbattle | 1
	bx r0
	.pool

.org 0x08048ffc
	ldr r0, =hook_battle_ui_render_pokeball_icons_opponent | 1
	bx r0
	.pool

.org 0x08048e8e
	ldr r0, =hook_battle_ui_render_pokeball_icons_player | 1
	bx r0
	.pool


.org 0x0800d6ec
	ldr r0, =battle_setup_party_idxs | 1
	bx r0
	.pool
	
.org 0x08039d3c
	ldr r0, =battle_ai_get_pokemon_to_switch_into | 1
	bx r0
	.pool

.org 0x08038644
	ldr r0, =battle_controller_opponent_handle_choose_pokemon | 1
	bx r0
	.pool

.org 0x08019b94
	ldr r3, =battler_has_no_switching_targets | 1
_blxr3:
	bx r3
	.pool

.org 0x08037bd8 // Battle controller opponent handle draw trainer sprite (1)
	ldr r0, =battle_controller_opponent_get_trainer_pic | 1
	bl _blxr0
	ldr r1, =0x08037c3a | 1
	bx r1
	.pool

.org 0x08037c7e // Battle controller opponent handle draw trainer sprite (2)
	mov r1, r4 // y
	ldr r2, =battle_controller_opponent_create_trainer_pic_oam_hook | 1
	bx r2
	.pool

.org 0x08037dac // Battle controller opponent handle draw trainer sprite sliding
	ldr r0, =battle_controller_opponent_get_trainer_pic | 1
	bl _blxr0
	ldr r1, =0x08037e0e | 1
	bx r1
	.pool

.org 0x0801327c
	ldr r0, =battle_intro_draw_pokemon_or_trainer_sprite_hook | 1
	bx r0
	.pool

.org 0x08037da4 // For trainerslidein, chose the correct trainer picture
	ldr r0, =battle_controller_opponent_get_trainer_pic | 1
	bl _blxr0
	ldr r1, =0x08037e0e | 1
	bx r1
	.pool


.org 0x08013552
	ldr r0, =battle_intro_try_second_trainer_ball_throw | 1
	bl _blxr0
	ldr r0, =0x08013578 | 1
	bx r0
	.pool

.org 0x080136dc
	ldr r0, =battle_intro_try_partner_ball_throw | 1
	bl _blxr0
	ldr r0, =0x08013702 | 1
	bx r0
	.pool

.org 0x08038cf2
	ldr r0, =battle_intro_trainer_pokemon_send_out_hook | 1
	bx r0
	.pool

.org 0x08035da0
	ldr r0, =battle_intro_trainer_pokemon_send_out_hook2 | 1
	bx r0
	.pool

.org 0x08035b30
	ldr r0, =sub_08035b30 | 1
	bx r0
	.pool

.org 0x080d7b40 // Battle String Decryption: Support new characters
	ldr r0, =battle_string_decrypt_additional_buffers_hook | 1
	bx r0
	.pool

// Hooks for non-table battle-strings

.org 0x080d7524 // bsc_string 0: Intro message
	ldr r0, =battle_intro_buffer_message | 1
	bl _blxr0
	ldr r1, =0x080d799c | 1
	bx r1
	.pool

.org 0x080d75d8 // bsc_string 1: Send out message
	ldr r0, =battle_send_out_buffer_message | 1
	bl _blxr0
	ldr r1, =0x080d799c | 1
	bx r1
	.pool
	
org 0x080d7680 // bsc_string 2: Return to trainer message
	ldr r0, =battle_string_return_pokemon_buffer_message | 1
	bl _blxr0
	ldr r1, =0x080d799c | 1
	bx r1
	.pool

.org 0x080d7710 // bsc_string 3: Switch in message
	ldr r0, =battle_switch_in_buffer_message | 1
	bl _blxr0
	ldr r1, =0x080d799c | 1
	bx r1
	.pool

.org 0x080d7814 // bsc_string 5: battle end message
	ldr r0, =battle_end_battle_buffer_message | 1
	bl _blxr0
	ldr r1, =0x080d799c | 1
	bx r1
	.pool

// Battle-Script for winning against two trainers
.org 0x081dca85
	.byte 0x28 // goto
	.word battlescript_trainer_battle_won

.org 0x08054c24
	ldr r0, =money_lost | 1
	bx r0 
	.pool

.org 0x0800d4f0
	ldr r0, =battle_controllers_setup_tag_battles | 1
	bl _blxr0
	ldr r0, =0x0800d6d8 | 1
	bx r0
	.pool

.org 0x0802e2d4
	ldr r0, =battle_controller_player_or_partner_execution_finished | 1
	bx r0
	.pool

.org 0x080125d8
	mov r1, #0 // Initialize the battle_state->ai_switch_target_chosen with zero


.org 0x08012af0
	ldr r0, =battle_switch_in_clear_hook | 1
	bx r0
	.pool

.org 0x08038618
	ldr r0, =battle_controller_opponent_handle_choose_item | 1
	bx r0
	.pool

.org 0x08038494
	ldr r0, =battle_controller_opponent_handle_choose_action | 1
	bx r0
	.pool

.org 0x080384b0
	ldr r0, =battle_controller_opponent_handle_choose_move | 1
	bx r0
	.pool

.org 0x0801639c
	ldr r0, =battle_action_use_item | 1
	bx r0
	.pool

.org 0x0824ff8c
	.word battle_action_turn_finished_wrapper | 1

.org 0x080443c4
	ldr r0, =battle_get_partner_name | 1
	bx r0
	.pool

.org 0x08127904
	ldr r0, =pokemon_party_menu_layout_by_battle_type | 1
	bx r0
	.pool

.org 0x08033418
	ldr r0, =battle_controller_partner_intro_ball_throw_allocate_palette | 1
	bl _blxr0
	ldr r0, =0x08033454 | 1
	bx r0
	.pool

.org 0x8033596
	ldr r0, =battle_controller_partner_is_single_or_multi_or_tag_battle | 1
	bl _blxr0
	cmp r0, #0
	beq 0x80335dc
	b 0x080335ac
	.pool

.org 0x0802f9f0
	ldr r0, =battle_controller_partner_is_single_or_multi_or_tag_battle | 1
	bl _blxr0
	cmp r0, #0
	bne 0x0802fa5c
	b 0x0802fa06
	.pool

.org 0x0802faf0
	.word battle_controller_player_or_partner_wait_for_healthboxes | 1

.org 0x0803217c
	ldr r0, =battle_controller_player_handle_draw_trainer_picture | 1
	bx r0 
	.pool

.org 0x0800fd5c
	ldr r0, =battle_initialize_graphics_or_preview | 1
	bl _blxr0
	ldr r0, = 0x0800fda0 | 1 // We don't set game's context any more, because there is no help system
	bx r0
	.pool


.org 0x08021c6c
	ldr r0, =bsc_cmd_exp_gain_should_gain_exp | 1
	bl _blxr0
	cmp r0, #0
	beq 0x08021c82
	b 0x08021ca8
	.pool


.org 0x08013750
	.word battle_introduce_handicap | 1
.org 0x080137dc
	.word battle_introduce_handicap | 1

.org 0x08024f32
	ldr r0, =bsc_cmd_switch_in_effects_check_ability_or_handicap | 1
	bl _blxr0
	cmp r0, #0
	beq 0x08024f48
	b 0x0802504a
	.pool


.org 0x080162D0
    ldr r2, =battle_hook_before_attack | 1
    bx r2
    .pool


// Move end battle script command x49
.org 0x08023b7a
        // The original command would have incremented the bsc offset by 3, instead we go to state 18
        mov r0, #18
        strb r0, [r1, #0x14]
        b 0x08023b82

.org 0x08013b70
	ldr r0, =battle_end_turn_effects | 1
	bl _blxr0
	cmp r0, #0
	beq 0x08013b88
	b 0x08013ca4
	.pool

.org 0x0824ff94
	.word battle_end_turn_handle_battle_continues_wrapper | 1

.org 0x08013cd8
	ldr r0, = battle_is_running_impossible | 1
	bx r0
	.pool

.org 0x0803265c
	ldr r0, =battle_handle_successful_ball_throw | 1
	bx r0
	.pool

.org 0x080326b0
	ldr r0, =battle_handle_ball_throw | 1
	bx r0
	.pool

.org 0x080ef83c
	ldr r1, =hook_ball_throw_anim_callback_select_target | 1
	bx r1
	.pool

.org 0x0802d3da
	ldr r0, =hook_bsc_cmd_xEF_handleballthrow_select_target | 1
	bx r0
	.pool
// bsc cmd xF0 give caught mon: Always target the defending_battler
.org 0x0802d80c
	.word defending_battler
.org 0x0802d8e4
	.word defending_battler
.org 0x0802d7aa
	lsl r0, #0 // Nop (i.e. dont OPPONENT(attacking_battler))
.org 0x0802d7f0
	lsl r0, #0 // As above
.org 0x0802d83e
	lsl r0, #0 // As above
.org 0x0802d88c
	mov r1, r0 // Instead of eor r1, r0 -> mov r1, r0

// bsc cmd xF3 nickname caught mon: Always target the defending battler
.org 0x0802de9c
	.word defending_battler
.org 0x0802defc
	.word defending_battler

.org 0x0802ddf0
	lsl r0, #0 // Nop (i.e. dont OPPONENT(attacking_battler))
.org 0x0802de1c
	lsl r0, #0 // Nop (i.e. dont OPPONENT(attacking_battler))
.org 0x0802de3c
	lsl r0, #0 // Nop (i.e. dont OPPONENT(attacking_battler))
.org 0x0802de5a
	mov r4, r0 // Instead of eor r4, r0
.org 0x0802dece
	mov r0, r1 // Instead of eor r0, r1 with r0 = 1



.org 0x0802d970
	ldr r0, =hook_bsc_cmd_xF2_display_dex_entry | 1
	bx r0
	.pool

.org 0x08021ca8
	ldr r0, =bsc_cmd_x23_should_play_victory_music | 1
	bl _blxr0
	cmp r0, #0
	beq 0x08021cd6
	b 0x08021cc4
	.pool

.org 0x08011ce8
	ldr r1, =battle_wild_pokemon_oam_callback | 1
	bx r1
	.pool

.org 0x08011d82
	mov r0, r4
	mov r1, #1
	ldr r2, =battle_wild_pokemon_sprite_fade_palettes | 1
	bl _blxr2
	b 0x08011d94
	.pool

.org 0x08014140
	ldr r0, = hook_battle_handle_action_selection_before_action_chosen | 1
	bx r0
	.pool

.org 0x0801485c
	ldr r0, =battle_handle_selection_actions_item_selected | 1
	bl _blxr0
	bl 0x08014bd2
	.pool

.org 0x0801f3d6
	ldr r0, =battle_active_attack_should_do_animation | 1
	bl _blxr0
	ldr r3, [0x0801f414] // =active_attack
	cmp r0, #0
	bne 0x0801f424 // attack requires animations, even though they are turned off, so we show them
	b 0x0801f3ee
	.pool

.org 0x0801f220
	ldr r0, =hook_bsc_cmd_x07_adjustnormal_damage | 1
	bx r0
	.pool
/** 
.org 0x08012642
	ldr r0, =hook_battle_initialize_absent_battlers | 1
	bx r0
	.pool

.org 0x08075188
	ldr r1, =battler_sprite_visible | 1
	bx r1
	.pool
**/

/**
.org 0x08077c12
	mov r0, r7 // Battler idx
	ldr r1, =battler_sprite_visible | 1
	bl _blxr1
	b 0x08077c30
	.pool

.org 0x08078074
	mov r0, r5 // Battler idx
	ldr r1, =battler_sprite_visible | 1
	bl _blxr1
	b 0x08078088
	.pool
**/

.org 0x0807fee4
	ldr r0, =battle_trainer_get_transition_type | 1
	bx r0
	.pool
	
.org 0x080d0b90
	.word battle_transition_phase_1_callbacks

.org 0x080d0bc8
	.word battle_transition_phase_1_callbacks

.org 0x080d0c00
	.word battle_transition_phase_2_callbacks
	
.org 0x080d0c30
	.word battle_transition_phase_2_callbacks