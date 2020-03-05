.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8a2d7e
ow_script_0x8a2d7e:
loadpointer 0x0 str_0x8a3b23
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a3b23

str_0x8a3b23:
    .string "Hier in Meriana City bekommen wir\nsauberes Wasser aus den Quellen\lvon Kaskada, südlich von hier."
        
        
.elseif LANG_EN

.endif
