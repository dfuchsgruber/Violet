.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb2f1
ow_script_0x8fb2f1:
loadpointer 0x0 str_0x8fb2fb
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8fb2fb

str_0x8fb2fb:
    .string "Wusstest du, dass im Stein antike\nPokémon-Fossilien konsveriert\lsind?"
        
        
.elseif LANG_EN

.endif
