.include "overworld_script.s"

.include "std.s"

.global ow_script_0x16b3ba
ow_script_0x16b3ba:
loadpointer 0x0 str_0x19684c
callstd MSG_FACE
end

.global str_0x19684c

str_0x19684c:
    .string "Diese Stadt ist ein Ort voller\nWunder. Die Laz.Corp. bringt uns\lder Zukunft jeden Tag ein Stück\lnäher."
        
        