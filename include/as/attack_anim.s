.macro loadgraphic id
.byte 0x0
.hword \id
.endm


.macro cmd1 param0
.byte 0x1
.hword \param0
.endm


.macro loadoam oam unkown additional
.byte 0x2
.word \oam
.byte \unkown
.byte \additional
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


.macro playsound_modulation_user_target_based sound modulation
.byte 0x19
.hword \sound
.byte \modulation
.endm


.macro sound_apply_modulation_user_target_based modulation
.byte 0x1a
.byte \modulation
.endm


.macro sound_modulation param0 param1 param2 param3 param4
.byte 0x1b
.hword \param0
.byte \param1
.byte \param2
.byte \param3
.byte \param4
.endm


.macro playsound4 sound modulation param2 param3
.byte 0x1c
.hword \sound
.byte \modulation
.byte \param2
.byte \param3
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


.macro fade_into_background_target_based id_target_is_opponent id_target_is_not_opponent unused
.byte 0x25
.byte \id_target_is_opponent
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
