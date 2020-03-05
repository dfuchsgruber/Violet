.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x878711
ow_script_0x878711:
loadpointer 0x0 str_0x87aafc
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x87aafc

str_0x87aafc:
    .string "RIVALs Haus"
        
        
.elseif LANG_EN

.endif
