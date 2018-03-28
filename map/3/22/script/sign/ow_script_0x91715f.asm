.include "overworld_script.s"

.include "std.s"

.global ow_script_0x91715f
ow_script_0x91715f:
loadpointer 0x0 str_0x91831f
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x91831f

str_0x91831f:
    .string "Wasserpfad"
        
        
.elseif LANG_EN

.endif
