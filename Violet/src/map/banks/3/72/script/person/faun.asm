.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "mugshot.s"

.global ow_script_trainerschool_faun
ow_script_trainerschool_faun:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test
loadpointer 0x0 str_after_test
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE
end

@ Before the written test
before_test:
	loadpointer 0x0 str_before_test
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE
	end

.ifdef LANG_GER
str_after_test:
	.autostring 35 2 "Ein unfairer Test?\nWas soll das heißen?\pDenkst du, Kleiner, dass du da draußen immer nur mit Fragen konfrontiert wirst, deren Antwort du hier gelernt hast?\pNur nicht unterkriegen lassen, der Feldtest steht ja noch an!"
str_before_test:
	.autostring 35 2 "PLAYER, du Schlafmütze!\nHehe!\pHusch auf deinen Platz, oder du fällst durch, Kleiner!"
        
.elseif LANG_EN

.endif
