.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_18_2_person_0
.global ow_script_map_18_2_person_2
.global ow_script_map_18_2_person_1
.global ow_script_map_18_2_trainer_0

ow_script_map_18_2_person_0:
loadpointer 0x0 str_0x1a0c6e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x1a0c6e:
    .string "Hallo! Danke für die Erfrischung!"


.elseif LANG_EN

.endif


ow_script_map_18_2_person_2:
loadpointer 0x0 str_0x95e017
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95e017:
    .string "Route 6 ist ein wirklich\nunangenehm heißer Ort.\pDu solltest dir etwas leichters\nanziehen, bevor du dich dort\lhinbegiebstDOTS"


.elseif LANG_EN

.endif


ow_script_map_18_2_trainer_0:
trainerbattlestd 0x0 0x92 0x0 str_0x95e0ac str_0x95e105
loadpointer 0x0 str_0x95e105
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95e0ac:
    .string "Du willst kämpfen?\nBeschwer dich aber hinterher\lnicht, dass du dich verbrannt\lhättest!"



str_0x95e105:
    .string "Au! Au! Heiß!"


.elseif LANG_EN

.endif


ow_script_map_18_2_person_1:
loadpointer 0x0 str_0x95e11e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95e11e:
    .string "Weiter westwärts kommst du zum Fuß\ndes Volcanos, einem aktiven\lVulkan.\pDass jemand dort eine Stadt\nerrichtet hat, erscheint mir sehr\lfragwürdigDOTS"


.elseif LANG_EN

.endif