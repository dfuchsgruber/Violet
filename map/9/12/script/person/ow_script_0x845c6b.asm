.include "overworld_script.s"

.include "std.s"

.global ow_script_0x845c6b
ow_script_0x845c6b:
loadpointer 0x0 str_0x95d460
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95d460

str_0x95d460:
    .string "Mit einem Wissenschaftler\nverheiratet zu sein, ist nicht\limmer einfach.\pDen ganzen Tag redet er vom\nWellencharakter des Lichts.\lOder waren es doch Teilchen?"
        
        
.elseif LANG_EN

.endif
