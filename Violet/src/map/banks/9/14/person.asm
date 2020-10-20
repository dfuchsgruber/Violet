.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_9_14_person_2
.global ow_script_map_9_14_person_1
.global ow_script_map_9_14_person_4
.global ow_script_map_9_14_person_0
.global ow_script_map_9_14_person_3

ow_script_map_9_14_person_4:
loadpointer 0x0 str_0x947ab3
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x947ab3:
    .string "Professor Primus ist eine Koryphäe\nauf dem Gebiet der Physik.\pSeine Abhandlungen zur Raum-Zeit-\nStruktur sind hochspannend."


.elseif LANG_EN

.endif


ow_script_map_9_14_person_3:
loadpointer 0x0 str_0x95c8bf
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95c8bf:
    .string "Selbst die Lobby dieser Firma\nstrahlt einen unvergleichlichen\lFuturismus aus."


.elseif LANG_EN

.endif


ow_script_map_9_14_person_0:
loadpointer 0x0 str_0x95c90e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95c90e:
    .string "Die Laz.Corp investiert Unsummen\nin völlig abstruse Forschungen.\pProfessor Primus forscht an einer\ntransdimensionalen Portaltechnik.\pEr träumt davon, zu fremden\nGalaxien reisen zu können."


.elseif LANG_EN

.endif


ow_script_map_9_14_person_1:
loadpointer 0x0 str_0x95c9cb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95c9cb:
    .string "Wusstest du, dass sich jede\nBeziehung zwischen Teilchen auf\lvier fundamentale Kräfte\lzurückführen lässt?\pDa wären die Gravitation und die\nelektromagnetische Kraft.\lDazu kommen die mysterösen starken\lund schwachen KernkräfteDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_14_person_2:
loadpointer 0x0 str_0x95cab9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95cab9:
    .string "Wusstest du, dass das Pokémon\nLagerunssystem entscheidend durch\ldie Laz.Corp voran gebracht wurde?\pAbteilungsleiter Bill aus Kanto\nist ein Genie!"


.elseif LANG_EN

.endif