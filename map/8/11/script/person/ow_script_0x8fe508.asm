.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8fe508
ow_script_0x8fe508:
loadpointer 0x0 str_0x931edc
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x931edc

str_0x931edc:
    .string "Die Welt ist kompliziert.\nWenn jemand wie Team Violet\leinfache Lösungen anbietet, wieso\lnicht?"
        
        
.elseif LANG_EN

.endif
