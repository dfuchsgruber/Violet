.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_clouds_person_5
.global ow_script_route_2_clouds_person_6

ow_script_route_2_clouds_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_route_2_clouds_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_5:
    .autostring 34 2 "Ich erinnere mich an den Burschen Lucius, der später zum Champion wurde.\pEr hat sich das Wolkenreiten selbst beigebracht."
str_6:
    .autostring 34 2 "Als Kind hat mir mein Vater oft von den Ruinen hier oben erzählt.\pJetzt kann ich sie endlich selbst erkunden!"

.elseif LANG_EN
str_5:
    .autostring 34 2 "I remember the boy Lucius, who later became champion.\pHe taught the cloud riding to himself."
str_6:
    .autostring 34 2 "When I was a child my father used to tell me about the ruins up here.\pNow I can explore them myself!"
.endif