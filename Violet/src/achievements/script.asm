.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "callstds.s"
.include "songs.s"

.global ow_script_achievement_unlocked
.global ow_script_end_achievement_reward
.global ow_script_show_achievement_unlocked

ow_script_achievement_unlocked:
    lockall
    callasm achievements_set_flag_achieved
    callasm achievements_create_name_tbox
    fanfare FANFARE_ACHIEVEMENT
    loadpointer 0x0 str_achievement_unlocked
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    callasm achievements_delete_name_tbox_if_active
    call achievement_give_reward
    callasm achievements_is_reward_obtained
    compare LASTRESULT 0
    callif EQUAL show_message_can_be_obtained_later
    callasm achievements_achieved_get_next
    compare LASTRESULT 1
    callif EQUAL ow_script_show_achievement_unlocked
ow_script_check_next_achievement:
    callasm achievements_compute_unlocked_message_issued
    callasm achievements_get_issued_unlocked_message_group_idx_to_vars
    compare LASTRESULT 1
    gotoif EQUAL ow_script_achievement_unlocked
    release
    end

ow_script_show_achievement_unlocked:
    sound 24
    callasm achievements_create_name_tbox
    loadpointer 0 str_new_achievement
    callstd MSG_KEEPOPEN
    callasm achievements_delete_name_tbox_if_active
    return

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
    .autostring 34 2 "Herausforderung abgeschlossen!"
str_can_be_obtained_later:
    .autostring 34 2 "Erhalte die Belohnung später über das Start-Menü."
str_new_achievement:
    .autostring 34 2 "Neue Herausforderung freigeschaltet!"
.elseif LANG_EN
str_achievement_unlocked:
    .autostring 34 2 "New achievement!"
str_can_be_obtained_later:
    .autostring 34 2 "You can obtain the reward later through the Start Menu."
str_new_achievement:
    .autostring 34 2 "New challenge unlocked!"
.endif
