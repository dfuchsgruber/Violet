.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94e5dd
ow_script_0x94e5dd:
loadpointer 0x0 str_0x94e5e7
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e5e7

str_0x94e5e7:
    .string "Mami! Können wir noch ins Museum\ngehen?"
        
        
.elseif LANG_EN

.endif
