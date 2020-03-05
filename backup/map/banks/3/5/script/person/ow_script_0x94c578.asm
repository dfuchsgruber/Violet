.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94c578
ow_script_0x94c578:
loadpointer 0x0 str_0x94d9e4
callstd MSG
end


.ifdef LANG_GER
.global str_0x94d9e4

str_0x94d9e4:
    .string "Los, Staralili! Ruckzuckhieb!"
        
        
.elseif LANG_EN

.endif
