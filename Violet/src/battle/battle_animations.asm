
.include "attack_anim.s"

.global battle_animations

.align 4
battle_animations:
    .word 0x81d9e18		@BATTLE_ANIM_CASTFORM_CHANGE
    .word 0x81d9e4e		@BATTLE_ANIM_STATS_CHANGE
    .word 0x81d9e57		@BATTLE_ANIM_SUBSTITUTE_FADE
    .word 0x81d9e94		@BATTLE_ANIM_SUBSTITUTE_APPEAR
    .word 0x81d9e9c		@BATTLE_ANIM_BAIT_THROW
    .word 0x81d9ee4		@BATTLE_ANIM_ITEM_KNOCKOFF
    .word 0x81d9eef		@BATTLE_ANIM_TURN_TRAP
    .word 0x81da082		@BATTLE_ANIM_ITEM_EFFECT
    .word 0x81da0f6		@BATTLE_ANIM_SMOKEBALL_ESCAPE
    .word 0x81da1d2		@BATTLE_ANIM_HANGED_ON
    .word 0x81da21f		@BATTLE_ANIM_RAIN_CONTINUES
    .word 0x81da268		@BATTLE_ANIM_SUN_CONTINUES
    .word 0x81da26d		@BATTLE_ANIM_SANDSTORM_CONTINUES
    .word 0x81da272		@BATTLE_ANIM_HAIL_CONTINUES
    .word 0x81da277		@BATTLE_ANIM_LEECH_SEED_DRAIN
    .word 0x81da285		@BATTLE_ANIM_MON_HIT
    .word 0x81da2b6		@BATTLE_ANIM_ITEM_STEAL
    .word 0x81da2db		@BATTLE_ANIM_SNATCH_MOVE
    .word 0x81da339		@BATTLE_ANIM_FUTURE_SIGHT_HIT
    .word 0x81da398		@BATTLE_ANIM_DOOM_DESIRE_HIT
    .word 0x81da45d		@BATTLE_ANIM_FOCUS_PUNCH_SETUP
    .word 0x81da49d		@BATTLE_ANIM_INGRAIN_HEAL
    .word 0x81da4e0		@BATTLE_ANIM_WISH_HEAL
    .word 0x81da51a		@BATTLE_ANIM_MON_SCARED
    .word 0x81da591		@BATTLE_ANIM_GHOST_GET_OUT
    .word 0x81da60b		@BATTLE_ANIM_SILPH_SCOPED
    .word 0x81da624		@BATTLE_ANIM_ROCK_THROW
    .word 0x81da66c		@BATTLE_ANIM_SAFARI_REACTION
    .word battle_animation_mega_evolution
    .word battle_animation_regent_evolution
    .word battle_animation_stance_change
    .word battle_animation_extreme_heat_introduction
    .word battle_animation_extreme_heat
    .word battle_animation_floating_rocks_introduction
    .word battle_animation_floating_rocks_protect

battle_animation_extreme_heat_introduction:
    loadgraphic 0x2815
    particleblend 0x2815, 0, 6, 6, 31 // Blend to RGB(31, 0, 0), alpha=6 instantly
    loadcallback battle_animation_sandstorm_background 5, 1
        .hword 1
    loadcallback battle_animation_blend_special_background 5, 3
        .hword 10, 10, 31 // from_alpha = to_alpha = 6, color = RGB(31, 0, 0)
    pause 10
    sound2 0xE9, 192, 63, 2, 0  
    pause 64
    end

battle_animation_extreme_heat:
    loadgraphic 0x2815
    particleblend 0x2815, 0, 6, 6, 31 // Blend to RGB(31, 0, 0), alpha=6 instantly
    loadcallback battle_animation_sandstorm_background 5, 1
        .hword 1
    loadcallback battle_animation_blend_special_background 5, 3
        .hword 10, 10, 31 // from_alpha = to_alpha = 6, color = RGB(31, 0, 0)
    pause 10
    sound2 0xE9, 192, 63, 2, 0
    pause 10
    // Buggy for some reason?
    //enable_oam_as_target OAM_ATTACKER
    fadebattler SPRITE_FADING_AFFECTS_USER, 8, 0, 10, 31
    pause 96
    fadebattler SPRITE_FADING_AFFECTS_USER, 1, 10, 0, 31
    //disable_oam_as_target OAM_ATTACKER
    end

battle_animation_floating_rocks_introduction:
    loadgraphic 0x274A
    playsound 164
    fadebattler SPRITE_FADING_AFFECTS_BATTLE_BG | SPRITE_FADING_AFFECTS_USER | SPRITE_FADING_AFFECTS_TARGET | SPRITE_FADING_AFFECTS_USER_PARTNER | SPRITE_FADING_AFFECTS_TARGET_PARTNER, 4, 0, 6, 0
    waitstate
    loadoam battle_animation_oam_template_ancient_power_rock_arbitrary_position, 2, 5
        .hword 40, 80, 54, 160, 2 // x, y, dy, dt, frame
    loadoam battle_animation_oam_template_ancient_power_rock_arbitrary_position, 2, 5
        .hword 212, 52, 30, 160, 5 // x, y, dy, dt, frame
    pause 8
    loadoam battle_animation_oam_template_ancient_power_rock_arbitrary_position, 2, 5
        .hword 112, 84, 62, 160 - 8, 3 // x, y, dy, dt, frame
    pause 8
    loadoam battle_animation_oam_template_ancient_power_rock_arbitrary_position, 2, 5
        .hword 160, 72, 40, 160 - 16, 2 // x, y, dy, dt, frame
    pause 16
    loadoam battle_animation_oam_template_ancient_power_rock_arbitrary_position, 2, 5
        .hword 32, 32, 16, 160 - 32, 1 // x, y, dy, dt, frame
    pause 8
    loadoam battle_animation_oam_template_ancient_power_rock_arbitrary_position, 2, 5
        .hword 124, 88, 72, 160 - 40, 4 // x, y, dy, dt, frame
    waitstate
    fadebattler SPRITE_FADING_AFFECTS_BATTLE_BG | SPRITE_FADING_AFFECTS_USER | SPRITE_FADING_AFFECTS_TARGET | SPRITE_FADING_AFFECTS_USER_PARTNER | SPRITE_FADING_AFFECTS_TARGET_PARTNER, 4, 6, 0, 0
    end

battle_animation_floating_rocks_protect:
    loadgraphic 0x274A
    playsound 164
    loadoam battle_animation_oam_template_ancient_power_rocks, 2, 5
        .hword 20, 32, -48, 80, 2 // x, y0, y1, dt, frame
    loadoam battle_animation_oam_template_ancient_power_rocks, 2, 5
        .hword 0, 16, -38, 80, 5 // x, y0, y1, dt, frame
    loadoam battle_animation_oam_template_ancient_power_rocks, 2, 5
        .hword 32, 24, -28, 80, 3 // x, y0, y1, dt, frame
    loadoam battle_animation_oam_template_ancient_power_rocks, 2, 5
        .hword -20, 24, -48, 80, 2 // x, y0, y1, dt, frame
    loadoam battle_animation_oam_template_ancient_power_rocks, 2, 5
        .hword 20, 16, -28, 80, 1 // x, y0, y1, dt, frame
    loadoam battle_animation_oam_template_ancient_power_rocks, 2, 5
        .hword 0, 24, -28, 80, 4 // x, y0, y1, dt, frame
    pause 8
    //enable_oam_as_target OAM_ATTACKER
    pause 24
    loopsoundwithpan 0x71 SOUND_PAN_ATTACKER 28 2
    loadcallback battle_animation_metallic_shine 5, 3
        .hword 0, 0, 0 // Keep Palette-Effect, Use-Custom-Color, Custom Color
    waitstate

    //loadcallback battle_animation_battler_fade_to_invisible, 2, 1 // This thing may be buggy... the target bg is calculated using the attacker...
    //    .hword 3 // Delay
    //pause 100
    //loadcallback battle_animation_battler_prepeare_fade_from_invisible 2, 0
    //loadcallback battle_animation_battler_fade_from_invisible 2, 1
     //   .hword 1 // Delay
    //waitstate
    //disable_oam_as_target OAM_ATTACKER
    end
