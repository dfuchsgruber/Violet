.include "overworld_script.s"

.include "std.s"

.global ow_script_0x811319
ow_script_0x811319:
loadpointer 0x0 str_0x8cb4a1
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8cb4a1

str_0x8cb4a1:
    .string "Das Leben an einem trostlosen Ort\nist trübselig.\pAber Lester unternimmt jeden\nVersuch etwas Leben auf diese\lInsel zu bringen. Er ist ein guter\lJunge, wirklich."
        
        
.elseif LANG_EN

.endif
