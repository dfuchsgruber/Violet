.include "achievements.s"

.macro achievement_unlocked achievement_group_idx:req, achievement_idx=0
    setvar 0x8004 \achievement_group_idx
    setvar 0x8005, \achievement_idx
    call ow_script_show_achievement_unlocked
.endm
