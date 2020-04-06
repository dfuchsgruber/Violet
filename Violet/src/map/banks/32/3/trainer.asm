.include "overworld_script.s"
.include "callstds.s"

.global ow_script_dark_tower_trainer_2

ow_script_dark_tower_trainer_2:
    trainerbattlestd 0 0x183 0 str_before_0 str_after_0
    loadpointer 0 str_after_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Dieser Turm ist der Königin der Nacht geweiht.\pEin Ungläubiger wie du ist hier nicht erwünscht."
str_after_0:
    .autostring 34 2 "Du solltest das Vermächtnis der dunklen Königin ehrenDOTS"

.elseif LANG_EN
.endif