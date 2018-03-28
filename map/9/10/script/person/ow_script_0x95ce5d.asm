.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95ce5d
ow_script_0x95ce5d:
loadpointer 0x0 str_0x95ce67
callstd MSG
end


.ifdef LANG_GER
.global str_0x95ce67

str_0x95ce67:
    .string "Es ... verfolgt ...\nmich ...\lDer Mondschatten ...\lDar ... Dark ... Darkrai..."
        
        
.elseif LANG_EN

.endif
