.include "overworld_script.s"

.include "std.s"

.global ow_script_0x85e80d
ow_script_0x85e80d:
loadpointer 0x0 str_0x8f4eff
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8f4eff

str_0x8f4eff:
    .string "RIVALs Computer scheint das neuste\nModell zu sein!\p...\pIch sollte mich auf den Weg\nmachen."
        
        
.elseif LANG_EN

.endif
