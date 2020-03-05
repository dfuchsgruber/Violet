.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x80f348
ow_script_0x80f348:
trainerbattlestd 0x0 0x13 0x0 str_0x80f360 str_0x80f391
loadpointer 0x0 str_0x80f391
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x80f360

str_0x80f360:
    .string "Sieh mal, was ich mir für Käfer\ngefangen habe!"
        
        
.global str_0x80f391

str_0x80f391:
    .string "Meine Käfer!!"
        
        
.elseif LANG_EN

.endif
