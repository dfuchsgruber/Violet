.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_map_5_13_person_0
.global ow_script_map_5_13_person_5
.global ow_script_map_5_13_person_1
.global ow_script_map_5_13_person_4
.global ow_script_map_5_13_person_3
.global ow_script_map_5_13_person_2
.global ow_script_meriana_city_gym_referee

ow_script_meriana_city_gym_referee:
    checkflag FRBADGE_3
    gotoif EQUAL gym_beaten
    loadpointer 0 str_meriana_city_gym_referee
    callstd MSG_FACE
    end
gym_beaten:
    loadpointer 0 str_beaten
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_beaten:
    .autostring 34 2 "Starke Leistung, Manus zu besiegen!\pAllein ihm gegenüberzutreten fällt manchen nicht leicht."
.elseif LANG_EN
.endif


ow_script_map_5_13_person_5:
loadpointer 0x0 str_0x93c067
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93c067:
    .string "Diese Arena ist perfekt geeignet\nzur Mediation und zum Training.\pGeist und Körper können sich hier\nvoll und ganz entfalten."


.elseif LANG_EN

.endif


ow_script_map_5_13_person_0:
loadpointer 0x0 str_0x93c0e4
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93c0e4:
    .string "Manus legt großen Wert auf\nDisziplin.\lNur wer sich im griff hat, wird\lgewinnen."


.elseif LANG_EN

.endif


ow_script_map_5_13_person_1:
loadpointer 0x0 str_0x93c135
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93c135:
    .string "Weibliche Kämper sind ebenso ernst\nzu nehmen, wie männliche Gegner!"


.elseif LANG_EN

.endif


ow_script_map_5_13_person_2:
loadpointer 0x0 str_0x93c17a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93c17a:
    .string "Woher Manus nur all die Mittel\nhat, ein derart gewaltiges Dojo zu\lerrichten?"


.elseif LANG_EN

.endif


ow_script_map_5_13_person_3:
loadpointer 0x0 str_0x93c8b8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93c8b8:
    .string "Diese Zeichen werden Katakana-\nZeichen genannt.\lIm Gegensatz zu den Hiragana-\lZeichen sind diese eckiger."


.elseif LANG_EN

.endif


ow_script_map_5_13_person_4:
loadpointer 0x0 str_0x93c923
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93c923:
    .string "Das letzte Zeichen ist ein Kanji-\nZeichen.\lEs wird mit dem Wort Sprache\lübersetzt."


.elseif LANG_EN

.endif