.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93838d
ow_script_0x93838d:
loadpointer 0x0 str_0x93c135
callstd MSG_FACE
end

.global str_0x93c135

str_0x93c135:
    .string "Weibliche Kämper sind ebenso ernst\nzu nehmen, wie männliche Gegner!"
        
        