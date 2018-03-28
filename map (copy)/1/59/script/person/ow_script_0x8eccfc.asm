.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8eccfc
ow_script_0x8eccfc:
loadpointer 0x0 str_0x928102
callstd MSG
end

.global str_0x928102

str_0x928102:
    .string "Was erhofft ihr zu erreichen? Eure\nRevolution wird scheitern, die\lWelt ist nicht bereit für eure\lIdeale!"
        
        