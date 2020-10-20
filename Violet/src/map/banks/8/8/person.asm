.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_8_8_person_0
.global ow_script_map_8_8_person_1

ow_script_map_8_8_person_1:
loadpointer 0x0 str_0x87f9d5
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87f9d5:
    .string "Im Fernsehen laufen oft sehr\nspannende Berichte!\pErst kürzlich habe ich eine\nDokumentation über das seltene\lPokémon Barschwa gesehen."


.elseif LANG_EN

.endif


ow_script_map_8_8_person_0:
loadpointer 0x0 str_0x87fa5c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87fa5c:
    .string "Die Fernsehberichte orientieren\nsich immer an den aktuellen\lEreignissen in der Region."


.elseif LANG_EN

.endif