.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8ecce5
ow_script_0x8ecce5:
trainerbattlestd 0x0 0x6d 0x0 str_0x928049 str_0x9280cb
loadpointer 0x0 str_0x9280cb
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x928049

str_0x928049:
    .string "Du willst dich der Revolution in\nden Weg stellen? Du willst dich\lder Freiheit in den Weg stellen?\lDas werde ich nicht zulassen."
        
        
.global str_0x9280cb

str_0x9280cb:
    .string "Dein Handeln wird hunderte in die\nVerdammnis stürzen."
        
        
.elseif LANG_EN

.endif
