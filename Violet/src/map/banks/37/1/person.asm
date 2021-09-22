.include "overworld_script.s"
.include "callstds.s"

.global ow_script_desert_village_tent_1_person_0
.global ow_script_desert_village_tent_1_person_1

ow_script_desert_village_tent_1_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_desert_village_tent_1_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich finde es total spannend, den Knacklion zuzusehen.\pIst es nicht lustig, wie sie sich auf dem Teppich flüchten?"
str_1:
    .autostring 34 2 "Ich weiß nicht, was über mich gekommen ist, meinen Enkel an einen solchen Ort zu bringen.\pHoffentlich taucht hier bald ein Pokémon-Range rauf und bringt uns nach KaskadaDOTS"
.elseif LANG_EN
.endif