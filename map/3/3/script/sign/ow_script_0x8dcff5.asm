.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8dcff5
ow_script_0x8dcff5:
loadpointer 0x0 str_0x8de321
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8de321

str_0x8de321:
    .string "Beerenladen"
        
        
.elseif LANG_EN

.endif
