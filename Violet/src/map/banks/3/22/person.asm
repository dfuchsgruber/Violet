.include "callstds.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_map_3_22_trainer_3
.global ow_script_map_3_22_trainer_2
.global ow_script_map_3_22_trainer_0
.global ow_script_map_3_22_trainer_5
.global ow_script_map_3_22_trainer_4
.global ow_script_map_3_22_trainer_1
.global ow_script_map_3_22_trainer_6
.global ow_script_map_3_22_trainer_7

ow_script_map_3_22_trainer_0:
trainerbattlestd 0x0 0x74 0x0 str_0x935b6f str_0x932010
loadpointer 0x0 str_0x932010
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x935b6f:
    .string "Südwärts gelangst du über den\nWasserpfad nach Meriana City.\pDort trainiert der größte aller\nKämpfer, Manus!"



str_0x932010:
    .string "Eines Tages werde ich in seiner\nArena arbeiten!"


.elseif LANG_EN

.endif


ow_script_map_3_22_trainer_4:
loadpointer 0x0 str_0x9367ce
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9367ce:
    .string "Hast du je von der Königin der\nFinsternis gehört?\pEin berühmtes Kindermärchen, das\nvon einer Hexe handelt, welche\lSeelen vertilgt."


.elseif LANG_EN

.endif


ow_script_map_3_22_trainer_5:
loadpointer 0x0 str_0x936852
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x936852:
    .string "Der Wasserpfad ist ein\nunterirdischer Tunnel, welcher\lunter einem Flussbett verläuft."


.elseif LANG_EN

.endif


ow_script_map_3_22_trainer_1:
trainerbattledouble 0x4 0x16b 0 str_challange str_defeat str_one_poke
loadpointer 0x0 str_defeat
callstd MSG_FACE
end


.ifdef LANG_GER
str_challange:
    .autostring 34 2 "Mein Liebling und ich werden dich mit der Kraft unserer Liebe besiegen!"
str_defeat:
    .autostring 34 2 "Was, das kann nicht sein?\pNichts ist stärker als unsere Liebe!"
str_one_poke:
    .autostring 34 2 "Du willst allein gegen ein Liebespaar antreten?\pDas würde ich mir an deiner Stelle überlegen."

.elseif LANG_EN

.endif


ow_script_map_3_22_trainer_2:
trainerbattlestd 0x0 0x76 0x0 str_0x935bdc str_0x935c48
loadpointer 0x0 str_0x935c48
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x935bdc:
    .string "Meine Gedanken sind in der Zukunft\nund sehen eine NiederlageDOTS"



str_0x935c48:
    .string "Ich sah meine eigene Niederlage!\nWelch Pech!"


.elseif LANG_EN

.endif


ow_script_map_3_22_trainer_3:
trainerbattlestd 0x0 0x77 0x0 str_0x935d84 str_0x93679b
loadpointer 0x0 str_0x93679b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x935d84:
    .string "Etikette und Anstand sind zeichen\neines guten Charakters."



str_0x93679b:
    .string "Nur wer sich auch zu benehmen\nweiß, kann kämpfen."


.elseif LANG_EN

.endif


ow_script_map_3_22_trainer_6:
trainerbattlestd 0x0 0x78 0x0 str_0x93690c str_0x9368a9
loadpointer 0x0 str_0x9368a9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93690c:
    .string "Hast du je einen Angler in Meriana\nCity gesehen?\pNein? Das dachte ich mir, denn ich\nfange jedes Pokémon ehe es\lflussabwärts dorthin gelangt."



str_0x9368a9:
    .string "Wenn sich meine Niederlage erst\nherumgesprochen hatDOTS\pAlle werden sie in Meriana City\nangelnDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_22_trainer_7:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8004 0x3
special 0x19
waitstate
clearflag TRANS_DISABLE
loadpointer 0x0 str_0x92f13e
callstd MSG
end


.ifdef LANG_GER

str_0x92f13e:
    .string "g"


.elseif LANG_EN

.endif