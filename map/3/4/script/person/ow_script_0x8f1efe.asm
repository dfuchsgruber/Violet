.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f1efe
ow_script_0x8f1efe:
loadpointer 0x0 str_0x926c84
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x926c84

str_0x926c84:
    .string "Keiner weiß warum um das Haus im\nSüden immerzu von irgendwelchem\lKisten umgeben ist. Was wohl dort\lgetrieben wird?"
        
        
.elseif LANG_EN

.endif
