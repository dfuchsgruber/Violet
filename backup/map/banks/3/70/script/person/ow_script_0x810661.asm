.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x810661
ow_script_0x810661:
trainerbattlestd 0x0 0x5 0x0 str_0x8106f1 str_0x81089a
loadpointer 0x0 str_0x81089a
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8106f1

str_0x8106f1:
    .string "Zeit für einen Kampf!"
        
        
.global str_0x81089a

str_0x81089a:
    .string "Du bist der verdiente Sieger."
        
        
.elseif LANG_EN

.endif
