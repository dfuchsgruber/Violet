.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_7_3_person_1
.global ow_script_map_7_3_person_3
.global ow_script_map_7_3_person_2



ow_script_map_7_3_person_1:
loadpointer 0x0 str_0x194666
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x194666:
    .string "Vor vielen Jahren riefen drei\njunge Trainertalente das System\lder Top Vier ins Leben."


.elseif LANG_EN

.endif


ow_script_map_7_3_person_3:
lock
faceplayer
setvar 0x8004 0x3
setvar 0x8005 0x5
special 0x173
textcolor 0x3
loadpointer 0x0 str_0x1b46c9
callstd MSG_KEEPOPEN
release
end


.ifdef LANG_GER

str_0x1b46c9:
    .string "Pokémon Journal\pSonderreportage: Arenaleiterin\nMisty aus Azuria City!\pMisty vergöttert angeblich\nLorelei von den Top Vier."


.elseif LANG_EN

.endif


ow_script_map_7_3_person_2:
loadpointer 0x0 str_0x81c244
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81c244:
    .string "Ich liebe es einen Spaziergang\ndurch den Kranzdorf-Wald zu machen.\lDort sind immer diese leuchtenden\lSteine!"


.elseif LANG_EN

.endif