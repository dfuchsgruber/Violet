.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "mugshot.s"

.global ow_script_trainerschool_rival
ow_script_trainerschool_rival:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test
loadpointer 0x0 str_after_test
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
end

before_test:
loadpointer 0x0 str_before_test
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
end

.ifdef LANG_GER

str_before_test:
    .autostring 35 2 "Wegen dir habe ich von Faun eine Standpauke bekommen!\pBeste Freunde können auch mal ein Klotz am Bein sein, wie es scheint!"
        
str_after_test:
	.autostring 35 2 "Das ist ja lachhaft!\nWas sich Faun wohl bei diesem Test gedacht hat?\pLachhaft, wirklich!"
        
.elseif LANG_EN

.endif
