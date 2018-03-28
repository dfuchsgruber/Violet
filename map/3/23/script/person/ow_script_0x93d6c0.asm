.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93d6c0
ow_script_0x93d6c0:
loadpointer 0x0 str_0x949cb9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x949cb9

str_0x949cb9:
    .string "Heil denen, die auf den Wolken\nwandern.\lHeil dem Volk des Himmels."
        
        
.elseif LANG_EN

.endif
