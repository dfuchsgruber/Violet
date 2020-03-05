.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_10_clouds_person_0
.global ow_script_route_10_clouds_person_1

ow_script_route_10_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_route_10_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Unter den Wolkenreitern erzählt man sich von einem großen grünen Drachen, der durch die Ozonschicht streift.\pIch würde zugerne wissen, ob an der Legende etwas Wahres istDOTS"
str_1:
    .autostring 34 2 "Über die Geschichte dieser Ruinen ist wenig bekannt.\pVor einigen Jahren hat sich aber Lucius, der ehemalige Champion, intensiv damit auseinandergesetzt."
.elseif LANG_EN
str_0:
    .autostring 34 2 "A story among cloud riders tells about a great grean dragon that wanders through the ozon.\pI really want to know if there is any truth to this legendDOTS"
str_1:
    .autostring 34 2 "About the history of this ruins almost nothing is known.\pSome years ago Lucius, the former champ, studied it intensely however."
.endif
