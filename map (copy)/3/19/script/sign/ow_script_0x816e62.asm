.include "overworld_script.s"

.include "std.s"

.global ow_script_0x816e62
ow_script_0x816e62:
loadpointer 0x0 str_0x823a89
callstd MSG_SIGN
end

.global str_0x823a89

str_0x823a89:
    .string "ROUTE 1: Verbindungsstrecke\nAMONIA - MERIANA CITY"
        
        