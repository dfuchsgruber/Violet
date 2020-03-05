.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x71bf24
ow_script_0x71bf24:
loadpointer 0x0 str_0x71cdbe
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x71cdbe

str_0x71cdbe:
    .string "An den Flüssen kann man\nunglaublich gut Staudämme bauen."
        
        
.elseif LANG_EN

.endif
