.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x87731f
ow_script_0x87731f:
loadpointer 0x0 str_0x8ecc17
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8ecc17

str_0x8ecc17:
    .string "Der westliche Teil Thetos wird vom\nältesten der Top Vier regiert."
        
        
.elseif LANG_EN

.endif
