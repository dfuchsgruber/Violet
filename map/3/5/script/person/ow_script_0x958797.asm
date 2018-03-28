.include "overworld_script.s"

.include "std.s"

.global ow_script_0x958797
ow_script_0x958797:
loadpointer 0x0 str_0x9587a1
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9587a1

str_0x9587a1:
    .string "Hey, verschwinde von hier!\nMistral hat Dinge im Museum zu\lerledigen, die dich nichts\langehen, du Bengel!"
        
        
.elseif LANG_EN

.endif
