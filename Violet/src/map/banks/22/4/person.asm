.include "callstds.s"
.include "overworld_script.s"

.global ow_script_tafelberg_south_person_1
.global ow_script_tafelberg_south_person_2

ow_script_tafelberg_south_person_1:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_tafelberg_south_person_2:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Diese blauen Felsen sind super schön!\pJuhu!\nBlaue Felsen!"
str_1:
    .autostring 34 2 "Das hab ich nun davon, mir einzureden, diesen steilen Pass hinauf zu joggenDOTS\pIch bin völlig außer PusteDOTS"
.elseif LANG_EN
.endif