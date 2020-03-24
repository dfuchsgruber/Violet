.include "attack_anim.s"

.global battle_animation_stance_change
battle_animation_stance_change:
    loadgraphic 0x27a9
    loadgraphic 0x2797
    playsound_with_pan 0xa4 0xc0
    nop3 0
    fade_into_background 0x2b
    wait
    loadcallback battle_animation_battle_bg_scrolling 5, 4
        .hword -0x600, 0x300, 0, 0xFFFF // dx * 256, dy * 256, reverse for opponent, wait for "additional" == value
    force_end_frame 
    enablebld 0x80c
    pause 0x50
    fadeexclude FADEEXCLUDE_NONE, 2, 0, 16, 0x7FFF
    pause 0x38
    loadcallback battle_animation_update_battler_callback 5, 1
        .hword SLOT_USER
    pause 2 // This pause is essential, since the palette must be updated w/o fading (takes 2 frames)
    fadeexclude FADEEXCLUDE_NONE, 2, 16, 0, 0x7FFF
    pause 0x40
    resetbld 
    enable_oam_as_target 0x3
    earthquakeeffect SLOT_USER 5 14
    cry SLOT_USER 0
    waitstate
    disable_oam_as_target 0x3
    fade_into_battle_background 
    wait 
    setadditional 0x7 0xffff // The bg scrolling callback is notified to end
    force_end_frame
    end





