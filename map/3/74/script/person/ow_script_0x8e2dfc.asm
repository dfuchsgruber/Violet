.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e2dfc
ow_script_0x8e2dfc:
trainerbattlestd 0x0 0x34 0x0 str_0x8e30de str_0x8e311d
loadpointer 0x0 str_0x8e311d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e30de

str_0x8e30de:
    .string "Auch wir Jugendlichen können es\nweit bringen in dieser Welt!"
        
        
.global str_0x8e311d

str_0x8e311d:
    .string "Siehst du? Du hast mich\ngeschlagen und wirst den Geist\lunserer Generation in die Welt\ltragen!"
        
        
.elseif LANG_EN

.endif
