.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_map_6_14_person_0
.global ow_script_map_6_14_person_1

ow_script_map_6_14_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_map_6_14_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Als ich nach Bruchfels gezogen bin, war dieser Ort ein Strandparadies.\pViele Leute haben über diesen Ort wie über Haweiland geredet.\pJetzt ist hier alles völlig zerstörtDOTS"
str_1:
    .autostring 34 2 "Seit dem Unglück scheint hier in Bruchfels auch die Sonne nur noch selten.\pEs ist fast so, als wüsste das Wetter um die Tragödie, die diesen Ort heimgesucht hat."
.elseif LANG_EN
.endif