.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810377
ow_script_0x810377:
loadpointer 0x0 str_0x8c90bc
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c90bc

str_0x8c90bc:
    .string "Kaskada ist die einzige Stadt des\nOstens, die nicht dem Pinken Faun\luntersteht."
        
        
.elseif LANG_EN

.endif
