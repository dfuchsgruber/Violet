.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86c24d
ow_script_0x86c24d:
loadpointer 0x0 str_0x8c7d34
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8c7d34

str_0x8c7d34:
    .string "Östlich: Silvania-Wald"
        
        
.elseif LANG_EN

.endif
