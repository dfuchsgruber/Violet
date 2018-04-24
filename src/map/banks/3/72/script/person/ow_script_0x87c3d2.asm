.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x87c3d2
ow_script_0x87c3d2:
loadpointer 0x0 str_0x89f1c6
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x89f1c6

str_0x89f1c6:
    .string "Die Schule ist anstrengend, aber\nman darf nicht aufgeben!"
        
        
.elseif LANG_EN

.endif
