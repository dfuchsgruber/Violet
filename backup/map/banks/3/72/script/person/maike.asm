.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "mugshot.s"

.global ow_script_trainerschool_maike
ow_script_trainerschool_maike:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test
loadpointer 0x0 str_after_test
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE
end

before_test:
loadpointer 0x0 str_before_test
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE
end

.ifdef LANG_GER

str_before_test:
    .autostring 35 2 "Oh MannDOTS\nIch bin so schlecht vorbereitetDOTS\pWie soll ich nur jemals diesen Test bestehen?"
        
str_after_test:
	.autostring 35 2 "SchniefDOTS\nSolche FragenDOTS\pKann doch niemand beantwortenDOTS"
        
.elseif LANG_EN

.endif
