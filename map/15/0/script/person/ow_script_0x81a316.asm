.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81a316
ow_script_0x81a316:
trainerbattlestd 0x0 0x21 0x0 str_0x81a32e str_0x81a36d
loadpointer 0x0 str_0x81a36d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x81a32e

str_0x81a32e:
    .string "Ein Angler braucht Geduld, und\nmeist ist der Fang nicht gut."
        
        
.global str_0x81a36d

str_0x81a36d:
    .string "Mein Fang war wohl eher schlecht."
        
        
.elseif LANG_EN

.endif
