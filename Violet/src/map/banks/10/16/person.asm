.include "movements.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_map_10_16_person_0
.global ow_script_map_10_16_trainer_0
.global ow_script_map_10_16_trainer_1
.global ow_script_0x86d439
.global ow_script_map_10_16_trainer_2

ow_script_map_10_16_trainer_2:
trainerbattlestd 0x0 0xab 0x0 str_0x86d276 str_0x86d2a0
loadpointer 0x0 str_0x86d2a0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86d276:
    .string "In dieser Arena ist es wahnsinnig\nheiß!"



str_0x86d2a0:
    .string "Die Hitze macht einem echt zu\nschaffen."


.elseif LANG_EN

.endif


ow_script_map_10_16_trainer_1:
trainerbattlestd 0x0 0xac 0x0 str_0x86d2e0 str_0x86d328
loadpointer 0x0 str_0x86d328
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86d2e0:
    .string "Ich hasse diesen Job. Immer verirre\nich mich bei diesen Pfeilfeldern!"



str_0x86d328:
    .string "Ich brauche jeden Tag Stunden bis\nich meinen Platz gefunden habe!"


.elseif LANG_EN

.endif


ow_script_map_10_16_trainer_0:
trainerbattlestd 0x0 0xad 0x0 str_0x86d382 str_0x86d3cd
loadpointer 0x0 str_0x86d3cd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86d382:
    .string "Ich schwitze nicht! Das ist\nMassageöl, das meinen Körper\lglänzen lässt!"



str_0x86d3cd:
    .string "Ich schwöre dir, das ist kein\nSchweiß!"


.elseif LANG_EN

.endif


ow_script_movs_0x86d5b0:
.byte LOOK_UP
.byte STOP


ow_script_map_10_16_person_0:
lockall
faceplayer
checkflag FRBADGE_5
gotoif EQUAL ow_script_0x86d439
loadpointer 0x0 str_0x86d444
callstd MSG
applymovement 0x1 ow_script_movs_0x86d5b0
waitmovement 0x0
hidesprite 0x1
pause 0x10
releaseall
warp 0xa 0x7 0x0 0x0 0x0
end


ow_script_0x86d439:
loadpointer 0x0 str_0x86d584
callstd MSG
releaseall
end


.ifdef LANG_GER

str_0x86d444:
    .string "PLAYER! Freut mich, dich zu\nsehen. Im Namen der Stadt Inferior\lund der ganzen Region möchte ich\ldir für deine Unterstützung am\lVulcano danken. Ich bin\lzuversichtlich, dass du es schaffen\lwirst, den Orden zu erinngen. Wenn\ldu aber glaubst, ich würde nicht\lalles geben, dann irrst du dich,\lkomm mit mir!"



str_0x86d584:
    .string "Das war der heißeste Kampf meines\nLebens!"


.elseif LANG_EN

.endif