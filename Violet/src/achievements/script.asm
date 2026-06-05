.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "callstds.s"
.include "songs.s"

.global ow_script_achievement_unlocked
.global ow_script_end_achievement_reward

ow_script_achievement_unlocked:
    lockall
    callasm achievements_set_flag_achieved
    fanfare FANFARE_ACHIEVEMENT
    loadpointer 0x0 str_achievement_unlocked
    callstd MSG_KEEPOPEN
    callasm achievements_load_achieved_text
    callasm achievements_create_name_tbox
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    callasm achievements_delete_name_tbox
    call achievement_give_reward
    callasm achievements_is_reward_obtained
    compare LASTRESULT 0
    callif EQUAL show_message_can_be_obtained_later
    callasm achievements_compute_unlocked_message_issued
    callasm achievements_get_issued_unlocked_message_group_idx_to_vars
    compare LASTRESULT 1
    gotoif EQUAL ow_script_achievement_unlocked
    release
    end


achievement_give_reward:
    callasm achievements_load_reward_script
    compare LASTRESULT 0
    gotoif EQUAL ow_script_end_achievement_reward
    jumpram
ow_script_end_achievement_reward:
    callasm achievements_get_return_to_achievements_to_lastresult
    compare LASTRESULT 0
    gotoif EQUAL _end
    callasm achievements_ui_initialize_from_overworld
    waitstate
_end:
    return

show_message_can_be_obtained_later:
    loadpointer 0x0 str_can_be_obtained_later
    callstd MSG_KEEPOPEN
    return


.ifdef LANG_GER
str_achievement_unlocked:
    .autostring 34 2 "Neuer Erfolg!"
str_can_be_obtained_later:
    .autostring 34 2 "Erhalte die Belohnung später über das Start-Menü."
.elseif LANG_EN
str_achievement_unlocked:
    .autostring 34 2 "New Achievement!"
str_can_be_obtained_later:
    .autostring 34 2 "You can obtain the reward later through the Start Menu."
.endif
