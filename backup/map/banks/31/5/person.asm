.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ardeal_person_9

ow_script_ardeal_person_9:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich weiß ehrlich nicht, was ich davon halten soll, dass nun so viele Rüpel von diesem Team Violet in der Burg herumlungern."

.elseif LANG_EN
str_0:
    .autostring 34 2 "I really don't know what I am supposed to think about all these Team Violet grunts lurking arround here."

.endif