.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95a952
ow_script_0x95a952:
loadpointer 0x0 str_0x95a95c
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x95a95c

str_0x95a95c:
    .string "Hinter der Vitrine liegt ein\nFossil, dessen Kontruen eine\lglitschige Wölbung aufweisen.\pEs wurde mit QUOTEHelixfossilQUOTE\nbetitelt."
        
        
.elseif LANG_EN

.endif
