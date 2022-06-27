.include "callstds.s"
.include "overworld_script.s"

.global ow_script_amonia_clouds_person_0
.global ow_script_amonia_clouds_person_1
.global ow_script_amonia_clouds_person_2
.global ow_script_amonia_clouds_person_3
.global ow_script_amonia_clouds_person_4
.global ow_script_amonia_clouds_person_5

ow_script_amonia_clouds_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_amonia_clouds_person_1:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end
ow_script_amonia_clouds_person_2:
    loadpointer 0x0 str_2
    callstd MSG_FACE
    end
ow_script_amonia_clouds_person_3:
    loadpointer 0x0 str_3
    callstd MSG_FACE
    end
ow_script_amonia_clouds_person_4:
    loadpointer 0x0 str_4
    callstd MSG_FACE
    end
ow_script_amonia_clouds_person_5:
    loadpointer 0x0 str_5
    callstd MSG_FACE
    end


.ifdef LANG_GER

str_0:
    .autostring 34 2 "Es ist ein Jammer, welche Kultur mit dem Himmelreich untergegangen istDOTS\pIch hätte so gerne gesehen, welche prachtvollen Bauwerke hier emporragten, ehe sie zu den Ruinen wurden, die man jetzt hier vorfindet."
str_1:
    .autostring 34 2 "Wenn jemand von ganzem Herzen nach Freiheit strebt, dann muss er sicherlich hier oben vollkommene Erfüllung vorfinden."
str_2:
    .autostring 34 2 "Ich schlafwandle oft und wache dann an den seltsamsten Orten auf.\pAber wie ich hierher gekommen bin, ist mir wirklich ein RätselDOTS"
str_3:
    .autostring 34 2 "Hast du auch schon einmal seltsam funkelnde Kristalle hier oben gefunden?\pIch frage mich, was es damit auf sich hatDOTS"
str_4:
    .autostring 34 2 "Diese Ruinen sind wirklich faszinierend.\pWelche Art von Kultur hat diese Gebäude errichtet?\pWie fortschrittlich waren diese Menschen?"
str_5:
    .autostring 34 2 "Siehst du den Kristall in der Ruine dort?\pIch habe schon einige solcher Steine hier oben gesehen.\pOb sie für die Zivilisation, die hier einmal gelebt hat, eine besondere Bedeutung hatten?"
.elseif LANG_EN
str_0:
    .autostring 34 2 "It is a pity how much culture perished hereDOTS\pI would have loved to see all the buildings that stood here before they became the ruins you will find."
str_1:
    .autostring 34 2 "If someone opts for freedom of the heart, then up here he has to find entire fulfillment."

.endif
