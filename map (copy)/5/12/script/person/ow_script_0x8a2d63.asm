.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a2d63
ow_script_0x8a2d63:
loadpointer 0x0 str_0x8a3651
callstd MSG_FACE
end

.global str_0x8a3651

str_0x8a3651:
    .string "Opi kennt so viele tolle\nGeschichten. Und Omi hat die ganze\lWelt bereist, erzählt sie immer!"
        
        