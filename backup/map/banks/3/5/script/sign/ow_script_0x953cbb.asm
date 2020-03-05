.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x953cbb
ow_script_0x953cbb:
loadpointer 0x0 str_0x95587d
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x95587d

str_0x95587d:
    .string "Orina City, die Stadt der\nWolkenkratzer"
        
        
.elseif LANG_EN

.endif
