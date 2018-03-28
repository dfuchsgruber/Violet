.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x917148
ow_script_0x917148:
trainerbattlestd 0x0 0x76 0x0 str_0x935bdc str_0x935c48
loadpointer 0x0 str_0x935c48
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x935bdc

str_0x935bdc:
    .string "Meine Gedanken sind in der Zukunft\nund sehen eine Niederlage..."
        
        
.global str_0x935c48

str_0x935c48:
    .string "Ich sah meine eigene Niederlage!\nWelch Pech!"
        
        
.elseif LANG_EN

.endif
