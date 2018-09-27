.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_trainerschool_blaise
ow_script_trainerschool_blaise:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test
call ow_script_0x89e33c
loadpointer 0x0 str_after_test
callstd MSG_FACE
special 0x7
end

before_test:
call ow_script_0x89e33c
loadpointer 0x0 str_before_test
callstd MSG_FACE
special 0x7
end

.ifdef LANG_GER

str_before_test:
    .autostring 36 2 "DOTS DOTS DOTS"
        
str_after_test:
	.autostring 36 2 "Dieser verrückte alte KnackerDOTS\pWas für ein lächerlicher TestDOTS"
        
.elseif LANG_EN

.endif
