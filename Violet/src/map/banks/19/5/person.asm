.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ceometria_gym_entrance_person_0

ow_script_ceometria_gym_entrance_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "In dieser Arena dreht sich alles um die Fähigkeit, dein eigenes Schicksal vorsehen zu können.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pMan kann es natürlich auch als Glückssache betrachtenDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "In this gym everything is about how well you can predict your own destiny.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pOr you can also view it as a matter of luck, of courseDOTS"
.endif


