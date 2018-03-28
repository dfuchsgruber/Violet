.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95ef34
ow_script_0x95ef34:
loadpointer 0x0 str_0x95ef3e
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x95ef3e

str_0x95ef3e:
    .string "Westen: Route 6\nOsten: Orina City"
        
        
.elseif LANG_EN

.endif
