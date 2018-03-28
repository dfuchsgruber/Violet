.include "overworld_script.s"

.include "std.s"

.global ow_script_0x818f1b
ow_script_0x818f1b:
trainerbattlestd 0x0 0x1e 0x0 str_0x818f6a str_0x818f33
loadpointer 0x0 str_0x818f33
callstd MSG_FACE
end

.global str_0x818f6a

str_0x818f6a:
    .string "Ein Experte zu sein, bringt viele\nVorteile mit sich."
        
        
.global str_0x818f33

str_0x818f33:
    .string "Ein Experte zu sein, bringt auch\nNachteile mit sich."
        
        