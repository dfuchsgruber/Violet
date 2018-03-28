.include "overworld_script.s"

.include "std.s"

.global ow_script_mart0x8fb16a
ow_script_mart0x8fb16a:
.hword ITEM_TM01
.hword ITEM_TM33
.hword ITEM_TM50
.hword ITEM_VM01
.hword ITEM_NONE


.global ow_script_0x8a19ed
ow_script_0x8a19ed:
pokemart ow_script_mart0x8fb16a
loadpointer 0x0 str_0x416651
end


.ifdef LANG_GER
.global str_0x416651

str_0x416651:
    .string "Du hast nicht genug Geld.PAUSE_UNTIL_PRESS"
        
        
.elseif LANG_EN

.endif
