.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "mugshot.s"

.global ow_script_trainerschool_felix
ow_script_trainerschool_felix:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test
loadpointer 0x0 str_after_test
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
end

before_test:
loadpointer 0x0 str_before_test
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
end

.ifdef LANG_GER

str_before_test:
    .autostring 35 2 "PLAYERDOTS\nHeute auch noch zu spät kommen!\pDu weißt doch wie Opi sein kann!"

str_after_test:
	.autostring 35 2 "Was für ein unsinnger Test!\pWer soll solche Fragen denn beantworten können?\pWas hat sich Opi dabei nur gedachtDOTS"
        
.elseif LANG_EN

.endif
