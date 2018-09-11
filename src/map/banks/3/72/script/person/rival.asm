.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_trainerschool_rival
ow_script_trainerschool_rival:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test
call ow_script_0x89ba6e
loadpointer 0x0 str_after_test
callstd MSG_FACE
special 0x7
end

before_test:
call ow_script_0x89ba6e
loadpointer 0x0 str_before_test
callstd MSG_FACE
special 0x7
end

.ifdef LANG_GER

str_before_test:
    .autostring 36 2 "Wegen dir habe ich von Faun eine Standpauke bekommen!\pBeste Freunde können auch mal ein Klotz am Beim sein, wie es scheint!"
        
str_after_test:
	.autostring 36 2 "Das ist ja lachhaft!\nWas sich Faun wohl bei diesem Test gedacht hat?\pLachhaft, wirklich!"
        
.elseif LANG_EN

.endif
