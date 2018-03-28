.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95a8d0
ow_script_0x95a8d0:
loadpointer 0x0 str_0x95a8da
callstd MSG_SIGN
end

.global str_0x95a8da

str_0x95a8da:
    .string "Hinter der Vitrine liegt ein\nFossil, dessen Konturen scharf\lzu sein scheinen.\lDas Fossil ist mit QUOTEDomfossilQUOTE\lbetitelt."
        
        