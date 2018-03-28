.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c9183
ow_script_0x8c9183:
loadpointer 0x0 str_0x8f19ca
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f19ca

str_0x8f19ca:
    .string "Meine Freundin und ich kommen oft\nhierher, um uns gemeinsam die\lWellen anzusehen."
        
        
.elseif LANG_EN

.endif
