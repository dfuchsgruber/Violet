.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93d69c
ow_script_0x93d69c:
trainerbattlestd 0x0 0x88 0x0 str_0x949b31 str_0x949b9d
loadpointer 0x0 str_0x949b9d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x949b31

str_0x949b31:
    .string "Käferpokémon gibt es sehr viele,\nman kann sie leicht fangen.\pAber ob sie auch im Kampf\nüberzeugen können?"
        
        
.global str_0x949b9d

str_0x949b9d:
    .string "Buhu! Du hast sie alle zerquetscht\nmeine armen Käfer."
        
        
.elseif LANG_EN

.endif
