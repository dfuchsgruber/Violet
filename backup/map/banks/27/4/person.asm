

.include "overworld_script.s"
.include "callstds.s"

.global ow_script_indoor_0_person_0
.global ow_script_indoor_0_person_1

ow_script_indoor_0_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_indoor_0_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Für einige Zeit habe ich zusammen mit Blackbeard auf einem Handelsschiff gedient.\pBevor dieser Idiot zum Piraten wurde, natürlichDOTS"
str_1:
    .autostring 34 2 "Haweiland ist für Urlauber ein Paradies.\pWenn man hier aber aufgewachsen ist, wird es schnell ödeDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "For some time I severd on the same cargo ship as Blackbeard did.\pOf course, that was before this became a filthy pirateDOTS"
str_1:
    .autostring 34 2 "For people on vacation Haweiland is a paradise.\pIf you grew up here however, it very quickly gets very dullDOTS"
.endif