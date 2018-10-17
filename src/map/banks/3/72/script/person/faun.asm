.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_trainerschool_faun
ow_script_trainerschool_faun:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test
call ow_script_0x89c5ee
loadpointer 0x0 str_after_test
callstd MSG_FACE
special 0x7
end

@ Before the written test
before_test:
	call ow_script_0x89c5ee
	loadpointer 0x0 str_before_test
	callstd MSG_FACE
	special 0x7
	end

.ifdef LANG_GER
str_after_test:
	.autostring 36 2 "Ein unfairer Test?\nWas soll das heißen?\pDenkst du, Kleiner, dass du da draußen immer nur mit Fragen konfrontiert wirst, deren Antwort du hier gelernt hast?\pNur nicht unterkriegen lassen, der Feldtest steht ja noch an!"
str_before_test:
	.autostring 36 2 "PLAYER, du Schlafmütze!\nHehe!\pHusch auf deinen Platz, oder du fällst durch, Kleiner!"
        
.elseif LANG_EN

.endif
