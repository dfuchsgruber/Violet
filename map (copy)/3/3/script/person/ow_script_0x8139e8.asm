.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8139e8
ow_script_0x8139e8:
loadpointer 0x0 str_0x81ab2c
callstd MSG_FACE
end

.global str_0x81ab2c

str_0x81ab2c:
    .string "Diese Stadt wurde im Wald errichtet\nund sie ist fast nur aus Holz\lgebaut. Umweldfreundlich, oder?"
        
        