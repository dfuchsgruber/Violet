.include "callstds.s"
.include "overworld_script.s"

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
    .string "Es ist wirklich beeindruckend, wie\ngut man ausgestorbene Pokémon\lanhand von Fossilien\lrekonstruieren kann.\pIch frage mich allerdings, ob sie\ntatsächlich wie ihre Nachbildungen\lausgesehen haben."


.elseif LANG_EN

.endif


ow_script_map_9_16_person_3:
loadpointer 0x0 str_0x958e8b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958e8b:
    .string "Es ist mein Traum, eines Tages\nselbst ein Fossil auszugraben und\ldamit dieses Museum zu bereichern."


.elseif LANG_EN

.endif


ow_script_map_9_16_person_5:
loadpointer 0x0 str_0x958a43
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958a43:
    .string "Sieh dir nur mal dieses Pokémon\nan!\pSein Skelett ist riesig!"


.elseif LANG_EN

.endif


ow_script_map_9_16_person_2:
loadpointer 0x0 str_0x958ef0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958ef0:
    .string "Die Pinselführung, die der\nKünstler hier an den Tag gelegt\lhat, ist wirklich einmalig."


.elseif LANG_EN

.endif


ow_script_map_9_16_person_1:
loadpointer 0x0 str_0x958f48
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958f48:
    .string "Ich habe gehört, dass das Museum\neng mit der Laz.Corp\lzusammenarbeitet.\pGerüchten zufolge geht es um die\nRestauration von ausgestorbenen\lPokémon aus deren Fossilien."


.elseif LANG_EN

.endif


ow_script_map_9_16_person_0:
loadpointer 0x0 str_0x958fef
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958fef:
    .string "Die Steine in den Vitrinen sind\njahrtausende alt.\pAllein der Gedanke an solch imense\nZeitintervalle ist erschreckend."


.elseif LANG_EN

.endif


ow_script_map_9_16_trainer_3:
loadpointer 0x0 str_0x959066
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x959066:
    .string "Mistral war bereits ein Kommandant\nder Revolutionsbewegung.\pEr ist bestens ausgebildet und\nmacht keine halben Sachen.\pNimm dich lieber in Acht, Bursche!"


.elseif LANG_EN

.endif


ow_script_map_9_16_trainer_0:
trainerbattlestd 0x0 0x8e 0x0 str_0x959139 str_0x959100
loadpointer 0x0 str_0x959100
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x959139:
    .string "Du willst dich mit uns anlegen?\pWenn Mistral erst das Magmaherz\nin seinem Besitz hat, wird das\lniemandem mehr gelingen!"



str_0x959100:
    .string "Erfreu dich an deinem Sieg,\nsolange du es noch kannst!"


.elseif LANG_EN

.endif


ow_script_map_9_16_trainer_2:
trainerbattlestd 0x0 0x8f 0x0 str_0x959205 str_0x9591cb
loadpointer 0x0 str_0x9591cb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x959205:
    .string "Mistrals Division ist zweifellos\ndie mächtigste innerhalb von Team\lViolet.\pDu bist chancenlos!"



str_0x9591cb:
    .string "Was? Du hast mich besiegt?\nDu hast \'was auf dem Kasten!"


.elseif LANG_EN

.endif


ow_script_map_9_16_trainer_1:
trainerbattlestd 0x0 0x90 0x0 str_0x9592b0 str_0x95927d
loadpointer 0x0 str_0x95927d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9592b0:
    .string "Ursprünglich war ich Teil von Rins\nDivision, habe mich aber dann für\lden vielverprechenden Mistral\lentschieden.\pEr wird uns Ruhm und Macht\nbescheren, bestimmt!"



str_0x95927d:
    .string "HmpfDOTS\nAber gegen Mistral hast du keine\lChance!"


.elseif LANG_EN

.endif