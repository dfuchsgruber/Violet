.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "mugshot.s"

.global ow_script_trainerschool_faun
ow_script_trainerschool_faun:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test
call after_test
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE
end

@ Before the written test
before_test:
	checkgender
    compare LASTRESULT 0x0
    callif EQUAL before_test_m
    callif NOT_EQUAL before_test_f
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE
	end

before_test_m:
	loadpointer 0x0 str_before_test_m
	return

before_test_f:
	loadpointer 0x0 str_before_test_f
	return

after_test:
	checkgender
	compare LASTRESULT 0x0
	callif EQUAL after_test_m
	callif NOT_EQUAL after_test_f
	return

after_test_m:
	loadpointer 0x0 str_after_test_m
	return

after_test_f:
	loadpointer 0x0 str_after_test_f
	return

.ifdef LANG_GER
str_before_test_m:
	.autostring 35 2 "PLAYER, du Schlafmütze!\nHehe!\pHusch auf deinen Platz, oder du fällst durch, Kleiner!"
str_before_test_f:
	.autostring 35 2 "PLAYER, du Schlafmütze!\nHehe!\pHusch auf deinen Platz, oder du fällst durch, Kleines!"
str_after_test_m:
	.autostring 35 2 "Ein unfairer Test?\nWas soll das heißen?\pDenkst du, Kleiner, dass du da draußen immer nur mit Fragen konfrontiert wirst, deren Antwort du hier gelernt hast?\pNur nicht unterkriegen lassen, der Feldtest steht ja noch an!"
str_after_test_f:
	.autostring 35 2 "Ein unfairer Test?\nWas soll das heißen?\pDenkst du, Kleines, dass du da draußen immer nur mit Fragen konfrontiert wirst, deren Antwort du hier gelernt hast?\pNur nicht unterkriegen lassen, der Feldtest steht ja noch an!"
        
.elseif LANG_EN

.endif
