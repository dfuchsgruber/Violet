.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_trainerschool_felix
ow_script_trainerschool_felix:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test
call ow_script_0x89e1fc
loadpointer 0x0 str_after_test
callstd MSG_FACE
special 0x7
end

before_test:
call ow_script_0x89e1fc
loadpointer 0x0 str_before_test
callstd MSG_FACE
special 0x7
end

.ifdef LANG_GER

str_before_test:
    .autostring 36 2 "PLAYER...\nHeute auch noch zu spät kommen!\pDu weißt doch wie Opi sein kann!"

str_after_test:
	.autostring 36 2 "Was für ein unsinnger Test!\pWer soll solche Fragen denn beantworten können?\pWas hat sich Opi dabei nur gedacht..."
        
.elseif LANG_EN

.endif
