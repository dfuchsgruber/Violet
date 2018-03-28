.include "overworld_script.s"

.include "std.s"

.global ow_script_0x84b0b8
ow_script_0x84b0b8:
loadpointer 0x0 str_0x85ff50
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x85ff50

str_0x85ff50:
    .string "Es ist wirklich sehr\nnervenaufreibend zu warten, bis man\lan der Reihe ist, findest du nicht?"
        
        
.elseif LANG_EN

.endif
