.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94d1e4
ow_script_0x94d1e4:
cry POKEMON_STARALILI 0x0
loadpointer 0x0 str_0x94da03
callstd MSG
end


.ifdef LANG_GER
.global str_0x94da03

str_0x94da03:
    .string "Stara! Staralili! Staaar!"
        
        
.elseif LANG_EN

.endif
