.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8c8d28
ow_script_0x8c8d28:
loadpointer 0 str_0
callstd MSG_FACE
end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hehe!\pDas hier ist ein wirklich fabelhafter Ort.\pUnter dem Schirm der Top Vier kann man so einiges anstellenDOTS"
        
.elseif LANG_EN

.endif
