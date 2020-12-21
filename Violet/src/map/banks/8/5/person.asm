.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kaskada_house_1_person_0
.global ow_script_kaskada_house_1_person_1

ow_script_kaskada_house_1_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_kaskada_house_1_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Es ist wirklich ein Jammer, was für ein Taugenichts mein Sohn geworden istDOTS\pEr besitzt einfach überhaupt kein PflichtbewusstseinDOTS\pWürde mich nicht sonderlich überraschen, wenn er eines Tages auf die schiefe Bahn gerät."
str_1:
    .autostring 34 2 "Letzens hat mich im Teehaus einer dieser Revolutionäre angesprochen.\pHat mir gesagt, dass es an der Zeit ist, für eine gerechtere Welt zu kämpfen.\pAber dafür bin ich fiel zu faul, wenn ich ehrlich sein soll."
.elseif LANG_EN
.endif