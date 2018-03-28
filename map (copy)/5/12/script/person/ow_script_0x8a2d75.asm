.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a2d75
ow_script_0x8a2d75:
loadpointer 0x0 str_0x8a36f1
callstd MSG_FACE
end

.global str_0x8a36f1

str_0x8a36f1:
    .string "Als Forscherin habe ich die ganze\nWelt bereist und meinen Beitrag\lzur Entdeckung der Mega-Evolution\lgeleistet... Guten Gewissens haben\lich, mein Mann und unsere Kinder\lund Enkel uns hier niedergelassen."
        
        