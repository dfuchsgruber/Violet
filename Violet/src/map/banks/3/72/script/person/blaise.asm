.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "mugshot.s"

.global ow_script_trainerschool_blaise
ow_script_trainerschool_blaise:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test
loadpointer 0x0 str_after_test
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT MSG_FACE
end

before_test:
loadpointer 0x0 str_before_test
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT MSG_FACE
end

.ifdef LANG_GER

str_before_test:
    .autostring 35 2 "DOTS DOTS DOTS"
        
str_after_test:
	.autostring 35 2 "Dieser verrückte, alte KnackerDOTS\pWas für ein lächerlicher TestDOTS"
        
.elseif LANG_EN

.endif
