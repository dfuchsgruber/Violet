.include "vars.s"
.include "move_tutor.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "movements.s"

.global ow_script_map_9_12_person_2
.global ow_script_map_9_12_person_3
.global ow_script_0x94610c
.global ow_script_0x9460a5
.global ow_script_map_9_12_person_1
.global ow_script_map_9_12_person_0

ow_script_map_9_12_person_0:
loadpointer 0x0 str_0x95d460
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95d460:
    .string "Mit einem Wissenschaftler\nverheiratet zu sein, ist nicht\limmer einfach.\pDen ganzen Tag redet er vom\nWellencharakter des Lichts.\lOder waren es doch Teilchen?"


.elseif LANG_EN

.endif


ow_script_map_9_12_person_3:
loadpointer 0x0 str_0x84c6c3
callstd MSG
end


.ifdef LANG_GER

str_0x84c6c3:
    .string "ZzzDOTS Schnarch DOTS\nGraaähDOTS ZzzDOTS ZzzDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_12_person_2:
loadpointer 0x0 str_0x84c6fa
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x84c6fa:
    .string "Weißt du, mein Bruder schläft gar\nnicht, er tut nur so!"


.elseif LANG_EN

.endif

make_move_tutor_std move_tutor str_0 str_bye

.global ow_script_map_9_12_person_1
ow_script_map_9_12_person_1:
    call move_tutor
    end

.ifdef LANG_GER

str_0:
    .autostring 34 2 "Ich bin ein Forscher der Laz.Corp und fasziniert von der Beschaffenheit des Lichts.\pDie BUFFER_3 ist der Angriff meiner Wahl!\pAber ich bin auch sein Sammler.\pWenn du mir entweder BUFFER_1x Riesenpliz oder BUFFER_2x Minipilz bringst, kann ich im Gegenzug dafür einem deiner Pokémon BUFFER_3 beibringen."
str_bye:
    .autostring 34 2 "Wie unverhofft!\nSolltest du deine Einstellung ändern und meine Faszination für Licht teilen, weißt du ja, wo du mich findest!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "I am a researcher of Laz.Corp and fascinated by the nature of light.\pBUFFER_3 is my attack of choice!\pBut I am also its collector.\pIf you bring me either BUFFER_1x Big Mushroom or BUFFER_2x Tiny Mushroom, I can teach BUFFER_3 to one of your Pokémon."
str_bye:
    .autostring 34 2 "How unexpected!\nIf you change your mind and share my fascination for light, you know where to find me!"
.endif