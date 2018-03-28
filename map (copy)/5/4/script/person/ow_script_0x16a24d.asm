.include "overworld_script.s"

.include "std.s"

.global ow_script_0x16a24d
ow_script_0x16a24d:
loadpointer 0x0 str_0x192a92
callstd MSG_FACE
end

.global str_0x192a92

str_0x192a92:
    .string "Du kannst den PC in der Ecke dort\ndrüben benutzen!\pDarauf hat man mich am Empfang\nfreundlicherweise hingewiesen."
        
        