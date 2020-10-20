.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_15_4_trainer_0
.global ow_script_map_15_4_trainer_1

ow_script_map_15_4_trainer_0:
trainerbattlestd 0x0 0x15 0x0 str_0x8d433f str_0x8d4315
loadpointer 0x0 str_0x8d433f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8d433f:
    .string "Es heißt, in dieser Mühle würde\nein goldenes Altaria nisten.\lOb an den Gerüchten etwas dran\list?"



str_0x8d4315:
    .string "Oho! Du hast da ein paar nette\nPokémon!"


.elseif LANG_EN

.endif


ow_script_map_15_4_trainer_1:
trainerbattlestd 0x0 0x25 0x0 str_0x8d499a str_0x8d49d0
loadpointer 0x0 str_0x8d49d0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8d499a:
    .string "In dieser Mühle kann man\ninteressante Dinge finden!"



str_0x8d49d0:
    .string "Hast du auch schon interessante\nDinge hier gefunden?"


.elseif LANG_EN

.endif