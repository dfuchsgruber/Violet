.macro loadgraphic id
.byte 0x0
.hword \id
.endm


.macro cmd1 param0
.byte 0x1
.hword \param0
.endm


.equ OAM_AT_USER, 0
.equ OAM_AT_TARGET, 0x80
.macro loadoam oam_template:req subpriority_and_flags:req parameter_count:req
.byte 0x2
.word \oam_template
.byte \subpriority_and_flags
.byte \parameter_count
.endm


.macro loadcallback function priority additional
.byte 0x3
.word \function
.byte \priority
.byte \additional
.endm


.macro pause frames
.byte 0x4
.byte \frames
.endm


.macro waitstate 
.byte 0x5

.endm


.macro nop 
.byte 0x6

.endm


.macro nop2 
.byte 0x7

.endm


.macro end 
.byte 0x8

.endm


.macro playsound sound
.byte 0x9
.hword \sound
.endm

.equ OAM_ATTACKER, 0
.equ OAM_TARGET, 1
.equ OAM_ANIMATION_USER, 2
.equ OAM_ANIMATION_TARGET, 3
.macro enable_oam_as_target slot
.byte 0xa
.byte \slot
.endm


.macro disable_oam_as_target slot
.byte 0xb
.byte \slot
.endm


.macro enablebld bld
.byte 0xc
.hword \bld
.endm


.macro resetbld
.byte 0xd

.endm


.macro call subscript
.byte 0xe
.word \subscript
.endm


.macro return 
.byte 0xf

.endm


.macro setadditional id value
.byte 0x10
.byte \id
.hword \value
.endm


.macro goto_if_charging_state_bit_0 subscript_not_set subscript_set
.byte 0x11
.word \subscript_not_set
.word \subscript_set
.endm


.macro goto_if_charging_state_equals value subscript
.byte 0x12
.byte \value
.word \subscript
.endm


.macro jump subscript
.byte 0x13
.word \subscript
.endm


.macro fade_into_background id
.byte 0x14
.byte \id
.endm


.macro fade_into_battle_background 
.byte 0x15

.endm


.macro wait 
.byte 0x16

.endm


.macro force_end_frame 
.byte 0x17

.endm


.macro display_background id
.byte 0x18
.byte \id
.endm

.equ SOUND_PAN_ATTACKER, 0xC0

.macro playsound_with_pan sound pan
.byte 0x19
.hword \sound
.byte \pan
.endm


.macro sound_apply_modulation_user_target_based modulation
.byte 0x1a
.byte \modulation
.endm


.macro sound2 sound param1 param2 param3 param4
.byte 0x1b
.hword \sound
.byte \param1
.byte \param2
.byte \param3
.byte \param4
.endm


.macro loopsoundwithpan sound:req pan:req loop_frame:req number_of_loops:req
.byte 0x1c
.hword \sound
.byte \pan
.byte \loop_frame
.byte \number_of_loops
.endm


.macro playsound5 sound modulation param2
.byte 0x1d
.hword \sound
.byte \modulation
.byte \param2
.endm


.macro setbld value
.byte 0x1e
.hword \value
.endm


.macro loadcallback_and_execute_and_endframe function additional
.byte 0x1f
.word \function
.byte \additional
.endm


.macro cmd20 
.byte 0x20

.endm


.macro goto_if_additional_equals id value param3
.byte 0x21
.byte \id
.hword \value
.word \param3
.endm


.macro something_with_poke_oam slot
.byte 0x22
.byte \slot
.endm


.macro something_with_poke_oam_on_user slot
.byte 0x23
.byte \slot
.endm


.macro nop3 unused
.byte 0x24
.word \unused
.endm


.macro fade_into_background_target_based id_target_battler_is_opponent id_target_is_not_opponent unused
.byte 0x25
.byte \id_target_battler_is_opponent
.byte \id_target_is_not_opponent
.byte \unused
.endm


.macro playsound2 sound param1 param2 param3 param4
.byte 0x26
.hword \sound
.byte \param1
.byte \param2
.byte \param3
.byte \param4
.endm


.macro cmd27 param1 param2 param3 param4 param5
.byte 0x27
.hword \param1
.byte \param2
.byte \param3
.byte \param4
.byte \param5
.endm


.macro cmd28 param0
.byte 0x28
.byte \param0
.endm


.macro cmd29 
.byte 0x29

.endm


.macro cmd2A param0
.byte 0x2a
.byte \param0
.endm


.macro cmd2B param0
.byte 0x2b
.byte \param0
.endm


.macro cmd2C param0
.byte 0x2c
.byte \param0
.endm


.macro cmd2D 
.byte 0x2d

.endm


.macro cmd2E param0
.byte 0x2e
.byte \param0
.endm


.macro cmd2F 
.byte 0x2f

.endm

// *** META MACROS ***

// Macro that creates a callback that loads the gfxs
.macro load_custom_gfx graphic:req palette:req
    loadcallback battle_animation_task_load_custom_gfx 10 4
    .word \graphic
    .word \palette
.endm

// Macro that fades a battler sprite on the bg
.equ SPRITE_FADING_AFFECTS_BATTLE_BG, 1
.equ SPRITE_FADING_AFFECTS_USER, 2
.equ SPRITE_FADING_AFFECTS_TARGET, 4
.equ SPRITE_FADING_AFFECTS_USER_PARTNER, 8 // Which palettes does this address exactly?
.equ SPRITE_FADING_AFFECTS_TARGET_PARTNER, 16 // Which palettes does this address exactly?
.equ SPRITE_FADING_AFFECTS_OAM_PAL0, 32 // ??
.equ SPRITE_FADING_AFFECTS_OAM_PAL1, 64 // ??

.macro fadebattler affects:req delay:req alpha_start:req alpha_finish:req color:req
    loadoam battle_animation_oam_template_fadescreen_battler 2 5
    .hword \affects
    .hword \delay
    .hword \alpha_start
    .hword \alpha_finish
    .hword \color
.endm

.equ SLOT_USER, 0
.equ SLOT_TARGET, 1
.equ SLOT_USER_PARTNER, 2
.equ SLOT_TARGET_PARTNER, 3


// Macro that applies earthquake effect (Horizontal shifting)
.equ EARTHQUAKE_ALL_BATTLERS, 4
.equ EARTHQUAKE_BG, 5
.equ INTENSITY_MOVE_STRENGTH_DEPENDENT, 0
.macro earthquakeeffect slot:req intensity:req duration:req
    loadcallback battle_animation_earthquake 2 3
    .hword \slot
    .hword \intensity
    .hword \duration
.endm

// Macro that fades everything but certain elements

.equ FADEEXCLUDE_USER, 0
.equ FADEEXCLUDE_TARGET, 1
.equ FADEEXCLUDE_USER_AND_BG, 2
.equ FADEEXCLUDE_TARGET_AND_BG, 3
.equ FADEEXCLUDE_USER_AND_TARGET, 4
.equ FADEEXCLUDE_NONE, 5
.equ FADEEXCLUDE_USER_PARTNER_AND_BG, 6
.equ FADEEXCLUDE_TARGET_PARTNER_AND_BG, 7
.macro fadeexclude excludes:req delay:req alpha_start:req alpha_finish:req color:req
    loadcallback battle_animation_fadescreen_exclude_battlers 5, 5
    .hword \excludes
    .hword \delay
    .hword \alpha_start
    .hword \alpha_finish
    .hword \color
.endm

// Macro for cries

.macro cry slot:req effect:req
    loadcallback battle_animation_cry 2 2
    .hword \slot
    .hword \effect
.endm

// Macro that blends the palette of a particle
.macro particleblend pal_tag:req delay:req alpha_from:req alpha_to:req color:req
    loadcallback battle_animation_blend_particle_callback 5, 5
    .hword \pal_tag, \delay, \alpha_from, \alpha_to, \color
.endm

// Macro that blends palettes (instantaneously) in a cyclic fashin (multiple times), alternating between two different colors
.macro fadebattlercyclic affects:req cycle_duration:req num_cycles:req color1:req alpha1:req color2:req alpha2:req
    loadoam battle_animation_oam_template_cyclic_blending 10, 7
    .hword \affects, \cycle_duration, \num_cycles, \color1, \alpha1, \color2, \alpha2
.endm
