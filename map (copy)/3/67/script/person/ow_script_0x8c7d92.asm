.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c7d92
ow_script_0x8c7d92:
loadpointer 0x0 str_0x8c7d9c
callstd MSG_FACE
end

.global str_0x8c7d9c

str_0x8c7d9c:
    .string "Ich kann es nicht fassen, dass ich\nnach dem langen und aufreibenden\lMarsch durch die Wüste noch immer\lnicht in Kaskada angekommen bin!"
        
        