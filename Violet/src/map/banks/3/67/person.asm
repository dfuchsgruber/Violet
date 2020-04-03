.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_67_person_0
.global ow_script_map_3_67_person_1

ow_script_map_3_67_person_0:
loadpointer 0x0 str_0x8c7d9c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c7d9c:
    .string "Ich kann es nicht fassen, dass ich\nnach dem langen und aufreibenden\lMarsch durch die Wüste noch immer\lnicht in Kaskada angekommen bin!"


.elseif LANG_EN

.endif


ow_script_map_3_67_person_1:
loadpointer 0x0 str_0x8c7e2e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c7e2e:
    .string "Es heißt, dass man in der Wüste\ndie Versteckte Maschine Blitz\lfinden kann.\pGlücklicherweise ist diese Höhle\nnicht dunkel."


.elseif LANG_EN

.endif