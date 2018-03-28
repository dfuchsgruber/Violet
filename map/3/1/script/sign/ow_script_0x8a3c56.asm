.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a3c56
ow_script_0x8a3c56:
loadpointer 0x0 str_0x8a3c60
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8a3c60

str_0x8a3c60:
    .string "Meriana City, die Stadt am Fuße\ndes Wassergebirges."
        
        
.elseif LANG_EN

.endif
