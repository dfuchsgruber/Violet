.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8fb58c
ow_script_0x8fb58c:
trainerbattlestd 0x0 0x54 0x0 str_0x8fe86e str_0x8feac9
loadpointer 0x0 str_0x8feac9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8fe86e

str_0x8fe86e:
    .string "Da ich nach Kaskada will, muss ich\nmich durch die Wüste kämpfen!"
        
        
.global str_0x8feac9

str_0x8feac9:
    .string "Ein beständiger, ausdauernder\nKampfstil ist der Schlüssel zum\lErfolg!"
        
        
.elseif LANG_EN

.endif
