.include "overworld_script.s"
.include "callstds.s"

.global ow_script_map_bruchfels_gym_trainer_1
.global ow_script_map_bruchfels_gym_trainer_2

ow_script_map_bruchfels_gym_trainer_1:
    trainerbattlestd 0x0 0x19f 0x0 str_before1 str_after1
    loadpointer 0x0 str_later1
    callstd MSG_FACE
    end
ow_script_map_bruchfels_gym_trainer_2:
    trainerbattlestd 0x0 0x1a0 0x0 str_before2 str_after2
    loadpointer 0x0 str_after2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before1:
    .autostring 34 2 "Du willst einen Tipp, um das Stein-Rätsel hier zu lösen?\pNur, wenn du mich im Kampf besiegen kannst!"
str_after1:
    .autostring 34 2 "Meinetwegen, du kannst deinen Tipp habenDOTS"
str_later1:
    .autostring 34 2 "Also gut, du kriegst einen Tipp von mir.\pDu solltest den Stein hier die U-förmige Strecke nicht nur einmal entlangschieben.\pImmerhin kann es nützlich sein, die anderen Felsen zu rotierenDOTS"
str_before2:
    .autostring 34 2 "Viele Trainer sind schon an dem Schieberätsel hier verzweifelt!\pAber wollen wir doch zuerst einmal sehen, ob du überhaupt kämpfen kannst!"
str_after2:
    .autostring 34 2 "Wohl an, du bist ganz gut, Kindchen.\pHast du auch den Grips, das Rätsel hier zu lösen?"
.elseif LANG_EN
.endif