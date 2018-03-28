.include "overworld_script.s"

.include "std.s"

.global ow_script_0x84c6b9
ow_script_0x84c6b9:
loadpointer 0x0 str_0x84c6c3
callstd MSG
end

.global str_0x84c6c3

str_0x84c6c3:
    .string "Zzz... Schnarch ...\nGraaäh... Zzz... Zzz..."
        
        