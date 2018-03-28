.include "overworld_script.s"

.include "std.s"

.global ow_script_0x89f057
ow_script_0x89f057:
loadpointer 0x0 str_0x89f061
callstd MSG_FACE
end

.global str_0x89f061

str_0x89f061:
    .string "Vor vielen Jahren und nach\netlichen Kriegen erschuf der\lChampion ein dezentrales\lHerrschaftssystem, das von den Top\lVier geleitet wird."
        
        