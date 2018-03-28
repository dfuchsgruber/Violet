.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94e73a
ow_script_0x94e73a:
loadpointer 0x0 str_0x94e744
callstd MSG
end

.global str_0x94e744

str_0x94e744:
    .string "Verkatert und pleite...\nIch fühle mich fast wieder wie ein\lStudent..."
        
        