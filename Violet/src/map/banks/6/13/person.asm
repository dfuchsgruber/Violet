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
    .autostring 34 2 "Wir haben lange Zeit versucht, diese Stadt wieder aufzubauen.\pAber Lester konnte es nicht zulassen, auch nur einen Stein dieser Ruinen zu berühren.\pWir Bewohner machen nun das Beste daraus, aber viele von uns haben Bruchfels längst verlassen."
.elseif LANG_EN
.endif