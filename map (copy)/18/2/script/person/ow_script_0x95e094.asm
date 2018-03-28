.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e094
ow_script_0x95e094:
trainerbattlestd 0x0 0x92 0x0 str_0x95e0ac str_0x95e105
loadpointer 0x0 str_0x95e105
callstd MSG_FACE
end

.global str_0x95e0ac

str_0x95e0ac:
    .string "Du willst kämpfen?\nBeschwer dich aber hinterher\lnicht, dass du dich verbrannt\lhättest!"
        
        
.global str_0x95e105

str_0x95e105:
    .string "Au! Au! Heiß!"
        
        