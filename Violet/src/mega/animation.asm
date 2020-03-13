.include "attack_anim.s"


.global battle_animation_mega_evolution
.global battle_animation_regent_evolution

battle_animation_mega_evolution:
    loadcallback battle_animation_mega_intialize_vars 2 0
    loadgraphic 0x27E3 // Solar Beam 
    loadgraphic 0x27E4 // Growing Orb
    loadcallback battle_animation_mega_callback_load_gfx 2 0
    loadcallback battle_animation_mega_modify_particle_pals 2 0
    enable_oam_as_target OAM_ATTACKER
    enablebld 0x80C
    fadebattler SPRITE_FADING_AFFECTS_BATTLE_BG 1 0 10 0 // Fade BG to dark
    waitstate
    // earthquakeeffect EARTHQUAKE_BG 10 32
    // earthquakeeffect EARTHQUAKE_ALL_BATTLERS 10 32
    // playsound_with_pan 0xe3 0
    loadcallback battle_animation_solar_beam_absorb_particles 2 4
        .hword 0, 60, 2, 12 // is_animation_target, num_particles, delay, speed
    playsound_with_pan 0x85, -0x40
    pause 0x24
    playsound_with_pan 0x85, -0x40
    pause 0x24
    loadoam battle_animation_oam_template_growing_orb 2, 1
        .hword 0 // is_animation_target
    pause 0x28
    playsound_with_pan 0xCE, -0x40
    pause 0x24
    playsound_with_pan 0xCE, -0x40
    fadebattler SPRITE_FADING_AFFECTS_BATTLE_BG 1 10 0 0 // Fade BG from dark
    pause 11
    fadeexclude FADEEXCLUDE_NONE, 2, 0, 16, 0x7FFF
    pause 100
    disable_oam_as_target OAM_ATTACKER
    loadcallback battle_animation_update_battler_callback 5, 1
        .hword SLOT_USER
    pause 2 // This pause is essential, since the palette must be updated w/o fading (takes 2 frames)
    fadeexclude FADEEXCLUDE_NONE, 2, 16, 0, 0x7FFF
    pause 40
    enable_oam_as_target OAM_ATTACKER
    earthquakeeffect SLOT_USER 5 14
    cry SLOT_USER 0
    waitstate
    disable_oam_as_target OAM_ATTACKER
    loadoam battle_animation_mega_sparkle_template, OAM_AT_USER | 2, 0
    pause 60
    end


battle_animation_regent_evolution:
    loadcallback battle_animation_mega_intialize_vars 2 0
    loadgraphic 0x27E3 // Solar Beam 
    loadgraphic 0x27E4 // Growing Orb
    loadcallback battle_animation_mega_callback_load_gfx 2 0
    loadcallback battle_animation_mega_modify_particle_pals 2 0
    enable_oam_as_target OAM_ATTACKER
    enablebld 0x80C
    fadebattler SPRITE_FADING_AFFECTS_BATTLE_BG 1 0 10 0 // Fade BG to dark
    waitstate
    earthquakeeffect EARTHQUAKE_BG 10 32
    earthquakeeffect EARTHQUAKE_ALL_BATTLERS 10 32
    playsound_with_pan 0xe3 0
    loadcallback battle_animation_solar_beam_absorb_particles 2 4
        .hword 0, 60, 2, 12 // is_animation_target, num_particles, delay, speed
    playsound_with_pan 0x85, -0x40
    pause 0x24
    playsound_with_pan 0x85, -0x40
    pause 0x24
    loadoam battle_animation_oam_template_growing_orb 2, 1
        .hword 0 // is_animation_target
    pause 0x28
    playsound_with_pan 0xCE, -0x40
    pause 0x24
    playsound_with_pan 0xCE, -0x40
    fadebattler SPRITE_FADING_AFFECTS_BATTLE_BG 1 10 0 0 // Fade BG from dark
    pause 11
    fadeexclude FADEEXCLUDE_NONE, 2, 0, 16, 0x7FFF
    pause 100
    disable_oam_as_target OAM_ATTACKER
    loadcallback battle_animation_update_battler_callback 5, 1
        .hword SLOT_USER
    pause 2 // This pause is essential, since the palette must be updated w/o fading (takes 2 frames)
    fadeexclude FADEEXCLUDE_NONE, 2, 16, 0, 0x7FFF
    pause 40
    enable_oam_as_target OAM_ATTACKER
    earthquakeeffect EARTHQUAKE_BG 10 32
    earthquakeeffect EARTHQUAKE_ALL_BATTLERS 10 32
    playsound_with_pan 0xe3 0
    cry SLOT_USER 0
    waitstate
    disable_oam_as_target OAM_ATTACKER
    loadoam battle_animation_regent_sparkle_template, OAM_AT_USER | 2, 0
    pause 60
    end
