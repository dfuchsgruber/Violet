.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_0_5_trainer_2
.global ow_script_map_0_5_trainer_7
.global ow_script_map_0_5_trainer_1
.global ow_script_map_0_5_trainer_9
.global ow_script_map_0_5_trainer_10
.global ow_script_map_0_5_trainer_5
.global ow_script_map_0_5_trainer_3
.global ow_script_map_0_5_trainer_0
.global ow_script_map_0_5_trainer_6
.global ow_script_map_0_5_trainer_8
.global ow_script_map_0_5_trainer_4

ow_script_map_0_5_trainer_0:
trainerbattlestd 0x0 0x4d 0x0 str_0x71a83d str_0x71a860
loadpointer 0x0 str_0x71a860
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x71a83d:
    .string "In dieser Höhle ist es so dunkel."



str_0x71a860:
    .string "Man hat mit gesagt, mit Vm Blitz\nkann man in Höhlen besser sehenDOTS"


.elseif LANG_EN

.endif


ow_script_map_0_5_trainer_2:
trainerbattlestd 0x0 0x4e 0x0 str_0x71aa9d str_0x71aae0
loadpointer 0x0 str_0x71aae0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x71aa9d:
    .string "In dieser Höhle gibt es allerlei\ninteressante Pokémon."



str_0x71aae0:
    .string "So viele PokémonDOTS"


.elseif LANG_EN

.endif


ow_script_map_0_5_trainer_5:
trainerbattlestd 0x0 0x4f 0x0 str_0x71ab1f str_0x8fb233
loadpointer 0x0 str_0x71ab61
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x71ab1f:
    .string "Vorhin war ein hübsches Mädchen\nmit rotem Kopftuch hier!"



str_0x8fb233:
    .string "Sie war vielleicht hübsch aber\nebenso stark!"



str_0x71ab61:
    .string "Sie war stark!"


.elseif LANG_EN

.endif


ow_script_map_0_5_trainer_6:
trainerbattlestd 0x0 0x50 0x0 str_0x71ab90 str_0x71abf9
loadpointer 0x0 str_0x71abf9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x71ab90:
    .string "Ich war schon am anderen Ausgang!\nDu willst wissen was dort ist? Ich\lsags dir, wenn du mich besiegst!"



str_0x71abf9:
    .string "Dort ist eine grauenhafte Wüste!"


.elseif LANG_EN

.endif


ow_script_map_0_5_trainer_3:
trainerbattlestd 0x0 0x51 0x0 str_0x71ac32 str_0x71ac8d
loadpointer 0x0 str_0x71ac8d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x71ac32:
    .string "Ich frage mich, wo der Ausgang\nistDOTS Ich irre schon seit Stunden\ldurch diese HöhlenDOTS"



str_0x71ac8d:
    .string "Die Dunkelheit ist mir bei der\nSuche nach dem Ausgang nicht sehr\lhilfreich."


.elseif LANG_EN

.endif


ow_script_map_0_5_trainer_9:
trainerbattlestd 0x0 0x5b 0x0 str_0x71b3bd str_0x71b424
loadpointer 0x0 str_0x71b424
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x71b3bd:
    .string "Ich würde zu gerne wissen, was am\nanderen Ende der Höhle ist! Man\nspricht von einer Wüste."



str_0x71b424:
    .string "Ich hoffe, es ist keine Wüste!"


.elseif LANG_EN

.endif


ow_script_map_0_5_trainer_1:
loadpointer 0x0 str_0x8fb1c7
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8fb1c7:
    .string "Warum muss es hier auch so\nverflucht dunkel sein?\pStändig stolpere ich über ein\nKleinsteinDOTS"


.elseif LANG_EN

.endif


ow_script_map_0_5_trainer_7:
loadpointer 0x0 str_0x8fb26b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8fb26b:
    .string "Gemäß Insider-Informationen soll\nman in dieser Höhle Fossilien\lfinden können.\pOb ich eines ergattern kann?"


.elseif LANG_EN

.endif


ow_script_map_0_5_trainer_4:
loadpointer 0x0 str_0x8fb2fb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8fb2fb:
    .string "Wusstest du, dass im Stein antike\nPokémon-Fossilien konsveriert\lsind?"


.elseif LANG_EN

.endif


ow_script_map_0_5_trainer_8:
loadpointer 0x0 str_0x8febc6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8febc6:
    .string "Einer Legende nach sind hier die\nSieglkammern eines legendären\lPokémon."


.elseif LANG_EN

.endif


ow_script_map_0_5_trainer_10:
loadpointer 0x0 str_0x8fecef
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8fecef:
    .string "Man kann die Hitze der Wüste\nförmlich spüren. Der Ausgang muss\lnah sein."


.elseif LANG_EN

.endif