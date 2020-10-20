.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_0x95cc66
.global ow_script_0x95cc5b
.global ow_script_map_9_9_person_1
.global ow_script_map_9_9_person_2
.global ow_script_map_9_9_person_0

ow_script_map_9_9_person_1:
loadpointer 0x0 str_0x84c5fb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x84c5fb:
    .string "Seit Wochen gehe ich Laufen, aber\nich nehme keinen Kilo ab! Ich\lsollte wirklich weniger Chips\lessenDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_9_person_2:
loadpointer 0x0 str_0x95cb56
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95cb56:
    .string "Glaubst du an einen Gott?\nManche verehren Arceus, den\lSchöpfer aller DingeDOTS\pIch weiß nicht, ob ich an etwas\nderart abstraktes glauben kannDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_9_person_0:
checkflag ORINA_CITY_DONNERSTEIN
gotoif EQUAL ow_script_0x95cc66
lock
faceplayer
loadpointer 0x0 str_0x95cd1c
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_DONNERSTEIN
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95cc5b
loadpointer 0x0 str_0x95ccac
callstd MSG
setflag ORINA_CITY_DONNERSTEIN
release
end


ow_script_0x95cc5b:
loadpointer 0x0 str_0x95cc70
callstd MSG
release
end


ow_script_0x95cc66:
loadpointer 0x0 str_0x95ccac
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95cd1c:
    .string "Ich bin bei der Laz.Corp im\nBereich Energieforschung\langestellt.\lDieser Stein enthält sehr viel\lelektrische Energie."



str_0x95ccac:
    .string "Der Donnerstein kann durch seine\nhohe energetische Aktivität einem\lElektro-Pokémon zur Entwicklung\lverhelfen."



str_0x95cc70:
    .string "OhDOTS! Es scheint, du hast keinen\nPlatz in deinem Beutel!"


.elseif LANG_EN

.endif