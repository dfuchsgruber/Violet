.include "overworld_script.s"

.include "std.s"

.global ow_script_0x71adbd
ow_script_0x71adbd:
trainerbattlestd 0x0 0x5b 0x0 str_0x71b3bd str_0x71b424
loadpointer 0x0 str_0x71b424
callstd MSG_FACE
end

.global str_0x71b3bd

str_0x71b3bd:
    .string "Ich würde zu gerne wissen, was am\nanderen Ende der Höhle ist! Man\nspricht von einer Wüste."
        
        
.global str_0x71b424

str_0x71b424:
    .string "Ich hoffe, es ist keine Wüste!"
        
        