.include "overworld_script.s"

.include "std.s"

.global ow_script_0x958361
ow_script_0x958361:
loadpointer 0x0 str_0x958fef
callstd MSG_FACE
end

.global str_0x958fef

str_0x958fef:
    .string "Die Steine in den Vitrinen sind\njahrtausende alt.\pAllein der Gedanke an solch imense\nZeitintervalle ist erschreckend."
        
        