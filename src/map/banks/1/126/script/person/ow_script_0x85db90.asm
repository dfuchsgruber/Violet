.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x85db90
ow_script_0x85db90:
trainerbattlestd 0x0 0xa9 0x0 str_0x8646a4 str_0x864721
loadpointer 0x0 str_0x864721
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8646a4

str_0x8646a4:
    .string "Ich habe es mir ausgesucht, ein\nRanger zu sein, also kann ich mich\lnicht darüber beschweren, nun an\lsolchen Orten zu sein!"
        
        
.global str_0x864721

str_0x864721:
    .string "Urgh... Diese vernichtende,\nzermürbende Hitze..."
        
        
.elseif LANG_EN

.endif
