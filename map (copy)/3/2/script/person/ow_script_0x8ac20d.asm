.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8ac20d
ow_script_0x8ac20d:
loadpointer 0x0 str_0x8c105d
callstd MSG_FACE
end

.global str_0x8c105d

str_0x8c105d:
    .string "Nick und Rick nutzen Vögel, um\nhierher zu gelangen. Ihre\lStaraptor\ sind so gut trainiert,\ldass sie selbst durch die\lGewitterstürme fliegen können."
        
        