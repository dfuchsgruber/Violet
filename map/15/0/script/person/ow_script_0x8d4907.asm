.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8d4907
ow_script_0x8d4907:
trainerbattlestd 0x0 0x20 0x0 str_0x8d491f str_0x8d494b
loadpointer 0x0 str_0x8d494b
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8d491f

str_0x8d491f:
    .string "Oh, ich find dicke Fische einfach\nklasse."
        
        
.global str_0x8d494b

str_0x8d494b:
    .string "Dicke Fische bedeuten aber nicht\nimmer starke Fische."
        
        
.elseif LANG_EN

.endif
