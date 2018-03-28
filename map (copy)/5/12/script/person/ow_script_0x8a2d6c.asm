.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a2d6c
ow_script_0x8a2d6c:
loadpointer 0x0 str_0x8a36af
callstd MSG_FACE
end

.global str_0x8a36af

str_0x8a36af:
    .string "Hunger! Ich habe Hunger! Mami soll\nendlich Essen machen! Hunger!"
        
        