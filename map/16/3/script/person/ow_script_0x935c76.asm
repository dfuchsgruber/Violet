.include "overworld_script.s"

.include "std.s"

.global ow_script_0x935c76
ow_script_0x935c76:
trainerbattlestd 0x0 0x7a 0x0 str_0x9376da str_0x93771d
loadpointer 0x0 str_0x93771d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9376da

str_0x9376da:
    .string "Hieb und Schlag!\nWie ich\s mag!\lTritt und Kick!\lHalten mich fit!"
        
        
.global str_0x93771d

str_0x93771d:
    .string "Wie, was schon aus?\nHast\ einiges drauf!\lIch lern dazu!\lKarate! Kung Fu!"
        
        
.elseif LANG_EN

.endif
