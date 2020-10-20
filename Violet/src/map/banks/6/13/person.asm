.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_6_13_person_1
.global ow_script_map_6_13_person_0

ow_script_map_6_13_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_map_6_13_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Seit dem Unglück hier ist der arme Lester ganz aufgelöst.\pWer kann es ihm verübeln, wo er doch seinen Vater verloren hat?"
str_1:
    .autostring 34 2 "Lester war so ein froher Junge!\pJetzt ist er immerzu so deprimiertDOTS\pAls hätte die Lebensfreude ihn komplett verlassen.\pDer Junge tut mir ehrlichgesagt sehr leidDOTS"
.elseif LANG_EN
.endif