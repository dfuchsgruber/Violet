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
    .string "Ich trainere mein Pokémon um Rosalie\nherauszufordern."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_3:
loadpointer 0x0 str_0x81ab2c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81ab2c:
    .autostring 34 2 "Kranzdorf wurde in der Lichtung eines Waldes erbaut.\pAlles hier ist durchströmt vom Geist der Natur."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_1:
loadpointer 0x0 str_0x81ab8e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81ab8e:
    .autostring 34 2 "Mein Hausarzt hat mir verordnet, hier einen Urlaub zu machen.\pIch muss sagen, dass die Waldluft mir sehr gut tut."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_2:
loadpointer 0x0 str_0x8e1ba8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e1ba8:
    .autostring 34 2 "Der Zeitwald hat schon immer etwas Mysteriöses an sich gehabt.\pKennst du schon den geweihten Schrein, der sich dort befindet?"

.elseif LANG_EN

.endif



ow_script_map_3_3_person_7:
loadpointer 0x0 str_0x8df298
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8df298:
    .autostring 34 2 "Rosalie, die Arenaleiterin dieses Dorfes hat ihr Leben diesem Wald gewidmet.\pMan merkt ihr die Leidenschaft für die Natur sehr an, finde ich."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_8:
loadpointer 0x0 str_0x8e0932
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e0932:
    .autostring 34 2 "Hast du es mitbekommen?\pDer alte Champion Lucius wurde besiegt!\pIch habe gehört, dass es ein Mädchen gewesen sein sollDOTS"

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