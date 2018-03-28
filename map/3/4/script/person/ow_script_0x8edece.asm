.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8edece
ow_script_0x8edece:
loadpointer 0x0 str_0x8f1a1d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f1a1d

str_0x8f1a1d:
    .string "Wie ich mir eine Kanufahrt leisten\nkonnte?\pIch gehe arbeiten, wie das\nErwachsene eben so tun."
        
        
.elseif LANG_EN

.endif
