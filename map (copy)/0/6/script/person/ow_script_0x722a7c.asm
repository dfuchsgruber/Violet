.include "overworld_script.s"

.include "std.s"

.global ow_script_0x722a7c
ow_script_0x722a7c:
trainerbattlestd 0x0 0x53 0x0 str_0x72883a str_0x72888e
loadpointer 0x0 str_0x72888e
callstd MSG_FACE
end

.global str_0x72883a

str_0x72883a:
    .string "Mein Ziel ist es nach Kaskada zu\nkommen, doch dazu muss ich über den\lWüstenpfad."
        
        
.global str_0x72888e

str_0x72888e:
    .string "Ich frage mich, wie Kaskada wohl so\nist."
        
        