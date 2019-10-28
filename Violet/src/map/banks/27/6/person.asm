

.include "overworld_script.s"
.include "callstds.s"

.global ow_script_indoor_2_person_0
.global ow_script_indoor_2_person_1
.global ow_script_indoor_2_person_2

ow_script_indoor_2_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_indoor_2_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_indoor_2_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Wäre es zu viel verlangt, die Schuhe auszuziehen, wenn du mein Haus betrittst?\pDu machst hier alles sandig!"
str_1:
    .autostring 34 2 "Seit mein Bruder sich Blackbeards Bande angeschlossen hat, ist Oma ständig schlecht gelauntDOTS"
str_2:
    .autostring 34 2 "Mein Sohn, ein PiratDOTS\pWas sollen nur die Nachbaren denken?"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Would it be too much to ask of you if you could take of your shoes when you enter my house?\pYou sure carry a lot of sand inside!"
str_1:
    .autostring 34 2 "Since my brother joined Blackbeard's crew, grandma is always in a very bad moodDOTS"
str_2:
    .autostring 34 2 "My son, a pirateDOTS\pWhat should the neighbours think?"

.endif