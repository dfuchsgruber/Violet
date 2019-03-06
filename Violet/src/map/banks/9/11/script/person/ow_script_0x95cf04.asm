.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95cf04
ow_script_0x95cf04:
loadpointer 0x0 str_0x95cf0e
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95cf0e

str_0x95cf0e:
    .string "Wer du nicht sein kannst, der\nsollst du auch nicht sein.\pDas ist eine Weisheit, die ich\njedem auf den Weg mitgeben will."
        
        
.elseif LANG_EN

.endif
