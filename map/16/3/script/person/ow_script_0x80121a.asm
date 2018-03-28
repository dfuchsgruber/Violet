.include "overworld_script.s"

.include "std.s"

.global ow_script_0x80121a
ow_script_0x80121a:
loadpointer 0x0 str_0x93767f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x93767f

str_0x93767f:
    .string "Im Laufe der Jahrtausende hat das\nWasser diesen Tunnel ausgespült.\lSo viele Sackgassen..."
        
        
.elseif LANG_EN

.endif
