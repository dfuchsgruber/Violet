.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x93cb68
ow_script_0x93cb68:
loadpointer 0 str_0
callstd MSG_FACE
end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Seit einigen Jahren ist es in Mode, auf einer Wolke zu reiten.\pIch wünschte, ich besäße so eine Wolke."
        
.elseif LANG_EN
str_0:
    .autostring 34 2 "Some years ago it became a trend to ride a cloud.\pI wish I had one of those."
        

.endif
