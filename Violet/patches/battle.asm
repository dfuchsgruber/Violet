
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

//fadeing intro of battle
.org 0x0824EEB4
    .word dma0_dump

.org 0x0800FEB0
    .halfword 0x5050 //win0 settings

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

.org 0x08015778
    ldr r0, =battle_whiteout_bypass | 1
    bx r0
    .pool

.org 0x08080404
    .word trainerbattle_store_possible_loss_in_lastresult | 1

.org 0x08080050
    .word hook_battle_result
    .word hook_battle_result

.org 0x807f4a0
	.word str_whiteout

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
	ldr r0, =hook_battle_ui_render_pokeball_icons | 1
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
