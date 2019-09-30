.include "overworld_script.s"
.include "callstds.s"

.global ow_script_vulcano_clouds_person_0

ow_script_vulcano_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Nur solche, die vom ganzem Herzen Wolkenreiter sind, wagen sich an einen so von Asche überfluteten OrtDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Only those who are cloud riders from deep down of their heart dare to go to ashy places like thisDOTS"

.endif