.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a0ad1
ow_script_0x8a0ad1:
trainerbattlestd 0x0 0x6c 0x0 str_0x927db0 str_0x927d4e
loadpointer 0x0 str_0x927d4e
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x927db0

str_0x927db0:
    .string "Hey, du da!\nDu kannst da nicht lang, unser\lAnführer hat dort zu tun.\pEr wird die Welt zu einem besseren\nOrt machen, weswegen ich dich\lnicht passieren lassen kann."
        
        
.global str_0x927d4e

str_0x927d4e:
    .string "Wieso widersetzt du dich dem\nRecht, dem Frieden? Träumst du\lnicht auch von einer besseren\lWelt?"
        
        
.elseif LANG_EN

.endif
