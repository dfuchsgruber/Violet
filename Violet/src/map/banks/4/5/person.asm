.include "callstds.s"
.include "overworld_script.s"

.global ow_script_amonia_clouds_person_0
.global ow_script_amonia_clouds_person_1

ow_script_amonia_clouds_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_amonia_clouds_person_1:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end


.ifdef LANG_GER

str_0:
    .autostring 34 2 "Es ist ein Jammer, welche Kultur mit dem Himmelreich untergegangen istDOTS\pIch hätte so gerne gesehen, welche prachtvollen Bauwerke hier emporragten, ehe sie zu den Ruinen wurden, die man jetzt hier vorfindet."
str_1:
    .autostring 34 2 "Wenn jemand von ganzem Herzen nach Freiheit strebt, dann muss er sicherlich hier oben vollkommene Erfüllung vorfinden."

.elseif LANG_EN
str_0:
    .autostring 34 2 "It is a pity how much culture perished hereDOTS\pI would have loved to see all the buildings that stood here before they became the ruins you will find."
str_1:
    .autostring 34 2 "If someone opts for freedom of the heart, then up here he has to find entire fulfillment."

.endif
