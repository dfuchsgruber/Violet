.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8e0e
ow_script_0x8c8e0e:
loadpointer 0x0 str_0x931aaa
callstd MSG_FACE
end

.global str_0x931aaa

str_0x931aaa:
    .string "Manus, aus Meriana City, verkehrt\ndes Öfteren hier.\pWas er hier treibt? Keinen blassen\nSchimmer.\pLegal ist es auf jeden Fall nicht!"
        
        