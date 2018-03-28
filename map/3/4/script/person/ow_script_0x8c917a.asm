.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c917a
ow_script_0x8c917a:
loadpointer 0x0 str_0x8f1987
callstd MSG
end


.ifdef LANG_GER
.global str_0x8f1987

str_0x8f1987:
    .string "Ich liebe es, gemeinsam mit meinem\nSchatz den Wellen zu lauschen."
        
        
.elseif LANG_EN

.endif
