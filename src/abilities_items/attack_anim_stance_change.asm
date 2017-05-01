.include "attack_anim.s"

.global attack_anim_stance_change
attack_anim_stance_change:
loadgraphic 0x27a9
loadgraphic 0x2797
enable_oam_as_target 0x3
playsound_modulation_user_target_based 0xa4 0xc0
nop3 0
fade_into_background 0x2b
wait
loadcallback 0x80bb919 0x5 0x4
    .hword 0xf700, 0x300, 0, 0xffff
force_end_frame 
enablebld 0x80c
pause 0x50


@Fade the screen to white
loadcallback 0x080BA929 5 5
    .hword 5, 2, 0, 16, 0xFFFF
pause 0x38
disable_oam_as_target 0x3
loadcallback attack_anim_stance_change_sprite_change 2 1
    .hword 0x7FFF
pause 0x10
loadcallback 0x080BA929 5 5
    .hword 5, 2, 16, 0, 0xFFFF
pause 0x40
resetbld 

enable_oam_as_target 0x3
loadcallback 0x080B95A1 5 3 @shake pokemon
    .hword 1, 5, 14
loadcallback attack_anim_stance_change_cry 2 0

pause 0x80

disable_oam_as_target 0x3

fade_into_battle_background 
wait 
setadditional 0x7 0xffff
force_end_frame
end









pause 0xa
loadoam 0x83d47f0 0x2 0x5
.hword 0x0, 0x18, 0x0, 0x0, 0x6
pause 0x3
loadoam 0x83e6724 0x3 0x5
.hword 0xffd6, 0x19, 0x0, 0x0, 0x6
pause 0x4
playsound_modulation_user_target_based 0x95 0x3f
loadoam 0x83e7108 0x2 0x4
.hword 0x0, 0x0, 0x1, 0x0
loadoam 0x83d47f0 0x2 0x5
.hword 0x1, 0xfff0, 0x4, 0x1, 0x4
waitstate 
loadcallback 0x8098dd5 0x2 0x5
.hword 0x1, 0xfffc, 0x1, 0xc, 0x1
loadoam 0x83e703c 0x2 0x7
.hword 0x7, 0x5, 0x1, 0x7fff, 0xa, 0x0, 0x0
pause 0xa
loadoam 0x83d47d8 0x2 0x3
.hword 0x0, 0x0, 0xb
pause 0x3
loadoam 0x83d47d8 0x2 0x3
.hword 0x1, 0x0, 0x7
waitstate 
waitstate 
disable_oam_as_target 0x3
resetbld 
fade_into_battle_background 
wait 
setadditional 0x7 0xffff
force_end_frame 
end 