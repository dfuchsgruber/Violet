.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8f6a
ow_script_0x8c8f6a:
loadpointer 0x0 str_0x8f16ab
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f16ab

str_0x8f16ab:
    .string "Dieser Brunnen wurde dem schönsten\naller Pokemon erbaut, Milotic.\pEs heißt, dass eines von ihnen in\nden hiesigen Gewässern lebe."
        
        
.elseif LANG_EN

.endif
