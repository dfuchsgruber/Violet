.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"

.global ow_script_map_9_16_trainer_2
.global ow_script_map_9_16_person_3
.global ow_script_map_9_16_person_1
.global ow_script_map_9_16_person_2
.global ow_script_map_9_16_person_5
.global ow_script_map_9_16_trainer_0
.global ow_script_map_9_16_person_0
.global ow_script_map_9_16_trainer_1
.global ow_script_map_9_16_person_4
.global ow_script_map_9_16_trainer_3

ow_script_map_9_16_person_4:
loadpointer 0x0 str_0x958dc8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958dc8:
    .autostring 34 2 "Diese Nachbildungen von bereits augestorbenen Pokémon sind wirklich beeindruckend.\pNur frage ich mich, ob die Pokémon wirklich einmal so ausgesehen habenDOTS"
.elseif LANG_EN

.endif


ow_script_map_9_16_person_3:
loadpointer 0x0 str_0x958e8b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958e8b:
    .autostring 34 2 "Ich wünschte, ich wäre so berühmt wie Professor Tann.\pFast alle Fossilien in diesem Museum sind seiner bahnbrechenden Arbeit geschuldet."


.elseif LANG_EN

.endif


ow_script_map_9_16_person_5:
loadpointer 0x0 str_0x958a43
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958a43:
    .autostring 34 2 "Sieh dir einmal dieses Pokémon an!\pSein Skelett ist wirklich gigantisch."


.elseif LANG_EN

.endif


ow_script_map_9_16_person_2:
    loadpointer 0x0 str_0x958ef0
    callstd MSG_FACE
    end


.ifdef LANG_GER

str_0x958ef0:
    .autostring 34 2 "Die Pinselführung dieses Künstlers ist wirklich einmalig, findest du nicht?"

.elseif LANG_EN

.endif


ow_script_map_9_16_person_1:
loadpointer 0x0 str_0x958f48
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958f48:
    .autostring 34 2 "Viele der Ausstellungsstücke wurden von Professor Tann geborgen.\pEr hat sie dann in Zusammenarbeit mit der Laz. Corp. restauriert."

.elseif LANG_EN

.endif


ow_script_map_9_16_person_0:
loadpointer 0x0 str_0x958fef
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958fef:
    .autostring 34 2 "Die Steine hinter diesen Vitrinen sind tausende Jahre alt.\pSolche Zeitspannen kann man sich als Mensch kaum vorstellen, oder?"


.elseif LANG_EN

.endif


ow_script_map_9_16_trainer_3:
loadpointer 0x0 str_0x959066
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x959066:
    .autostring 34 2 "Unser Anführer war bereits Kommandant in der Revolutionsbewegung.\pEr ist unglaublich stark und macht keine halben Sachen.\pNimm dich lieber in Acht, Kindchen!"
.elseif LANG_EN
.endif


ow_script_map_9_16_trainer_0:
trainerbattlestd 0x0 0x8e 0x0 str_0x959139 str_0x959100
loadpointer 0x0 str_0x959100
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x959139:
    .autostring 34 2 "Du willst dich mit uns anlegen?\pUnser Kommandant Mistral wird dir schon zeigen, wohin das führt!"

str_0x959100:
    .autostring 34 2 "Wenn unser Kommandant mit dir fertig ist, wird dir dein dämliches Grinsen schon noch vergehen, Kindchen!"


.elseif LANG_EN

.endif


ow_script_map_9_16_trainer_2:
    trainerbattlestd 0x0 0x8f 0x0 str_0x959205 str_0x9591cb
    loadpointer 0x0 str_0x9591cb
    callstd MSG_FACE
    end


.ifdef LANG_GER

str_0x959205:
    .autostring 34 2 "Unsere Division ist die stärkste von allen, verstanden?\pWir sind nicht solche Versager wie die Rüpel, die unter Rin kämpfen."
str_0x9591cb:
    .autostring 34 2 "Na gut, vielleicht ist die erste Division noch ein Stück stärker als wirDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_16_trainer_1:
trainerbattlestd 0x0 0x90 0x0 str_0x9592b0 str_0x95927d
loadpointer 0x0 str_0x95927d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9592b0:
    .autostring 34 2 "Ich habe einmal für Rins Division gekämpft.\pDann habe ich mich aber Mistral angeschlossen.\pSeine ambitionierte und skrupellose Art entspricht mir viel mehr!"

str_0x95927d:
    .autostring 34 2 "Das ist nur ein kleiner RückschlagDOTS\pMistral wird die Dinge ins Lot rücken!"


.elseif LANG_EN

.endif