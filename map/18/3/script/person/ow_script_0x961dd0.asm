.include "overworld_script.s"

.include "std.s"

.global ow_script_0x961dd0
ow_script_0x961dd0:
trainerbattlestd 0x0 0xa2 0x0 str_0x96364e str_0x96368c
loadpointer 0x0 str_0x96368c
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x96364e

str_0x96364e:
    .string "Meine Pokémon speien Flammen und\nwir werden dich versengen!"
        
        
.global str_0x96368c

str_0x96368c:
    .string "Wuah! Dein Feuer war heißer als\ndas meine..."
        
        
.elseif LANG_EN

.endif
