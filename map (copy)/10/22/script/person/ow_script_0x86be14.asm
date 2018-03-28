.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86be14
ow_script_0x86be14:
loadpointer 0x0 str_0x965de4
callstd MSG_FACE
end

.global str_0x965de4

str_0x965de4:
    .string "Selbst an Wintertagen herrschen in\nInferior Höchsttemperaturen.\pWir haben hier sogut wie niemals\nSchneefall."
        
        