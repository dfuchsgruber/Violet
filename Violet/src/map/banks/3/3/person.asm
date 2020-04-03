.include "callstds.s"
.include "overworld_script.s"
.include "species.s"
.include "flags.s"

.global ow_script_map_3_3_person_3
.global ow_script_map_3_3_person_5
.global ow_script_map_3_3_person_2
.global ow_script_map_3_3_person_6
.global ow_script_map_3_3_person_7
.global ow_script_map_3_3_person_1
.global ow_script_map_3_3_person_8
.global ow_script_0x8f08aa
.global ow_script_map_3_3_person_4
.global ow_script_0x8f08a1
.global ow_script_map_3_3_person_0

ow_script_map_3_3_person_0:
loadpointer 0x0 str_0x81aafa
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81aafa:
    .string "Ich trainere mein Pokémon um Mia\nherauszufordern."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_3:
loadpointer 0x0 str_0x81ab2c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81ab2c:
    .string "Diese Stadt wurde im Wald errichtet\nund sie ist fast nur aus Holz\lgebaut. Umweldfreundlich, oder?"


.elseif LANG_EN

.endif


ow_script_map_3_3_person_1:
loadpointer 0x0 str_0x81ab8e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81ab8e:
    .string "Ich bin hierhergekommen, um die\nWaldluft zu genießen. Anordnung\lmeines Hausarztes."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_2:
loadpointer 0x0 str_0x8e1ba8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e1ba8:
    .string "Silvania wurde in einer Lichtung\ndes Silvania-Waldes von den\lErkundern dieser Region errichtet.\pIm Wald selbst haben sie auch\neinen Schrein gebaut, um dem darin\lwohnenden Zeitpokemon zu huldigen."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_4:
cry POKEMON_PIKACHU 0x0
loadpointer 0x0 str_0x817948
callstd MSG_FACE
waitcry
end


.ifdef LANG_GER

str_0x817948:
    .string "Pikachuuu!!!"


.elseif LANG_EN

.endif

@ ToDo: Investigate the letter-casing

ow_script_map_3_3_person_5:
loadpointer 0x0 str_0x818ef3
callstd MSG
setflag FRBADGE_2
end


.ifdef LANG_GER

str_0x818ef3:
    .string "Hihi."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_6:
clearflag FRBADGE_2
sound 0x10
end


ow_script_map_3_3_person_7:
loadpointer 0x0 str_0x8df298
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8df298:
    .string "Mia, die Arenaleiterin dieser\nStadt, kümmert sich um den\lSilvania-Wald."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_8:
loadpointer 0x0 str_0x8e0932
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e0932:
    .string "Der amtierende Champion soll\näußert bescheiden sein. Niemand\lweiß, wer er oder sie istDOTS"


.elseif LANG_EN

.endif


ow_script_0x8f08a1:
goto ow_script_0x8f08aa


ow_script_0x8f08aa:
loadpointer 0x0 str_0x8f4688
callstd MSG_KEEPOPEN
callasm 0x91a44c1
pause 0x1
end


.ifdef LANG_GER

str_0x8f4688:
    .string "  Wählst du dieses Pokémon?\nA : Bestätigen  B : Abbruch"


.elseif LANG_EN

.endif