.include "callstds.s"
.include "overworld_script.s"

@ ToDo: Investigate the letter-casing

.global ow_script_0x816e62
ow_script_0x816e62:
loadpointer 0x0 str_0x823a89
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x823a89

str_0x823a89:
    .string "Route 1: Verbindungsstrecke\nAmonia - Meriana City"
        
        
.elseif LANG_EN

.endif
