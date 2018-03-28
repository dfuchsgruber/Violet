.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x816e62
ow_script_0x816e62:
loadpointer 0x0 str_0x823a89
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x823a89

str_0x823a89:
    .string "ROUTE 1: Verbindungsstrecke\nAMONIA - MERIANA CITY"
        
        
.elseif LANG_EN

.endif
