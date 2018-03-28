.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94bf78
ow_script_0x94bf78:
loadpointer 0x0 str_0x94de8d
callstd MSG_FACE
end

.global str_0x94de8d

str_0x94de8d:
    .string "Ich halte Ausschau nach\nzwielichten Gestalten!\pWenn ich einen Verbrecher\nergreife, werde ich befördert!"
        
        