.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86bbd8
ow_script_0x86bbd8:
loadpointer 0x0 str_0x965a40
callstd MSG_FACE
end

.global str_0x965a40

str_0x965a40:
    .string "Viele alte Menschen besuchen\nInferior der heißen Quellen wegen.\pDas Wasser soll eine reinigende\nWirkung auf Seele und Körper\lhaben."
        
        