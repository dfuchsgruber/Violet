.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c8426
ow_script_0x8c8426:
loadpointer 0x0 str_0x8c8430
callstd MSG
end


.ifdef LANG_GER
.global str_0x8c8430

str_0x8c8430:
    .string "Die Bezahlung für besagte Waren\nkann ich nur bar entgegennehmen..."
        
        
.elseif LANG_EN

.endif
