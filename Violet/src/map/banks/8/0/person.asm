.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_8_0_person_0
.global ow_script_map_8_0_person_1
.global ow_script_map_8_0_person_3
.global ow_script_map_8_0_person_2

ow_script_map_8_0_person_0:
lock
faceplayer
call ow_script_0x1a9429
release
end


ow_script_map_8_0_person_3:
loadpointer 0x0 str_0x195c7a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x195c7a:
    .string "Ich bin erst vor kurzem in diese\nStadt gezogen!"


.elseif LANG_EN

.endif


ow_script_map_8_0_person_2:
loadpointer 0x0 str_0x71cdbe
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x71cdbe:
    .string "An den Flüssen kann man\nunglaublich gut Staudämme bauen."


.elseif LANG_EN

.endif


ow_script_map_8_0_person_1:
loadpointer 0x0 str_0x95aaa5
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95aaa5:
    .string "Das Wasser in Kaskada ist das\nsauberste der ganzen Theto-Region."


.elseif LANG_EN

.endif