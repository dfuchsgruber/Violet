.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94e555
ow_script_0x94e555:
loadpointer 0x0 str_0x94e55f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e55f

str_0x94e55f:
    .string "Gerüchten zufolge wird die\nLaz.Corp ihren giftigen Müll\leinfach durchs Abwasser los.\pIch frage mich, ob da etwas dran\nistDOTS"
        
        
.elseif LANG_EN

.endif
