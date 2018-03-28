.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8f7c
ow_script_0x8c8f7c:
loadpointer 0x0 str_0x8f179f
callstd MSG_FACE
end

.global str_0x8f179f

str_0x8f179f:
    .string "Schon lange frage ich mich, was\ndie Erbauer dieser Stadt mit\ldiesen marineblauen\lPflastersteinen zum Ausdruck\lbringen wollten..."
        
        