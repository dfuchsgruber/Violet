.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x16b3ba
ow_script_0x16b3ba:
loadpointer 0x0 str_0x19684c
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x19684c

str_0x19684c:
    .string "Diese Stadt ist ein Ort voller\nWunder. Die Laz.Corp. bringt uns\lder Zukunft jeden Tag ein Stück\lnäher."
        
        
.elseif LANG_EN

.endif
