.include "overworld_script.s"
.include "callstds.s"

.global ow_script_silvania_clouds_person_0
.global ow_script_silvania_clouds_person_1

ow_script_silvania_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_silvania_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hier hat wohl einst ein Tempel gestandenDOTS\pIch frage mich, was damit passiert istDOTS"
str_1:
    .autostring 34 2 "Autsch!\pIch habe mir vorhin an dieser Fackel die Finger verbrannt!"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Once a temple was standing hereDOTS\pI wonder what happened to itDOTS"
str_1:
    .autostring 34 2 "Ouch!\pJust a minute ago I burned my fingers at this torch!"

.endif