

.include "overworld_script.s"
.include "callstds.s"

.global ow_script_indoor_1_person_0
.global ow_script_indoor_1_person_1
.global ow_script_indoor_1_person_2

ow_script_indoor_1_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_indoor_1_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_indoor_1_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich hasse es, dass unsere Familie hier lebt.\pNarzissa, zu deren Gebiet Haweiland gehört, ist eine egozentrische, eingebildete Diva.\pDOTS DOTS DOTS\pOb etwa nur ich neidisch bin?\pNiemals!"
str_1:
    .autostring 34 2 "Über viele Generationen hinweg hat meine Familie in Haweiland gelebt.\pEs gibt nichts, was uns von hier vertreiben könnte!"
str_2:
    .autostring 34 2 "Meine Tochter macht gerade eine schwierige Phase durch.\pIch denke, sie eifert zu sehr einigen geradezu unerreichbaren Vorbildern nachDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "I hate the fact that our family lives here.\pNarcissa, who rules over this city, is a egocentric and conceited diva.\pDOTS DOTS DOTS\pWhat?\nI am just jealous?\pNever!"
str_1:
    .autostring 34 2 "For many generations now my family has lived in Haweiland.\pThere is nothing which could make us leave this wonderful place!"
str_2:
    .autostring 34 2 "My daughter is currently living through a difficult phase.\pI think that she strives too much to be like one of her ridiculously unreachable idolsDOTS"

.endif