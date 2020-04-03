.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "mugshot.s"
.include "overworld_script.s"

.global ow_script_map_3_72_person_5
.global ow_script_map_3_72_person_2
.global ow_script_map_3_72_person_1
.global ow_script_map_3_72_person_3
.global ow_script_map_3_72_person_0
.global ow_script_map_3_72_person_4
.global ow_script_trainerschool_rival
.global ow_script_trainerschool_felix
.global ow_script_trainerschool_maike
.global ow_script_trainerschool_blaise
.global ow_script_trainerschool_faun


ow_script_trainerschool_blaise:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test_blaise
loadpointer 0x0 str_after_test_blaise
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT MSG_FACE
end

before_test_blaise:
loadpointer 0x0 str_before_test_blaise
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT MSG_FACE
end

.ifdef LANG_GER

str_before_test_blaise:
    .autostring 35 2 "DOTS DOTS DOTS"

str_after_test_blaise:
	.autostring 35 2 "Dieser verrückte, alte KnackerDOTS\pWas für ein lächerlicher TestDOTS"

.elseif LANG_EN

.endif

ow_script_trainerschool_faun:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test_faun
call after_test_faun
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE
end

@ Before the written test
before_test_faun:
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

after_test_faun:
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

ow_script_trainerschool_felix:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test_felix
loadpointer 0x0 str_after_test_felix
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
end

before_test_felix:
loadpointer 0x0 str_before_test_felix
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
end

.ifdef LANG_GER

str_before_test_felix:
    .autostring 35 2 "PLAYERDOTS\nHeute auch noch zu spät kommen!\pDu weißt doch wie Opi sein kann!"

str_after_test_felix:
	.autostring 35 2 "Was für ein unsinnger Test!\pWer soll solche Fragen denn beantworten können?\pWas hat sich Opi dabei nur gedachtDOTS"

.elseif LANG_EN

.endif

ow_script_trainerschool_maike:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test_may
loadpointer 0x0 str_after_test_may
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE
end

before_test_may:
loadpointer 0x0 str_before_test_may
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE
end

.ifdef LANG_GER

str_before_test_may:
    .autostring 35 2 "Oh MannDOTS\nIch bin so schlecht vorbereitetDOTS\pWie soll ich nur jemals diesen Test bestehen?"

str_after_test_may:
	.autostring 35 2 "SchniefDOTS\nSolche FragenDOTS\pKann doch niemand beantwortenDOTS"

.elseif LANG_EN

.endif


ow_script_map_3_72_person_5:
loadpointer 0x0 str_0x89f1c6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x89f1c6:
    .string "Die Schule ist anstrengend, aber\nman darf nicht aufgeben!"


.elseif LANG_EN

.endif


ow_script_map_3_72_person_4:
loadpointer 0x0 str_0x8a05dd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a05dd:
    .string "Diese Statue stellt ein Pokémon\nvom Typen Stahl und Fee dar. Es\lheißt Flunkifer."


.elseif LANG_EN

.endif


ow_script_map_3_72_person_0:
loadpointer 0x0 str_0x8a062f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a062f:
    .string "Feuer schlägt Wasser, Wasser\nschlägt Pflanze und Pflanze\lschlägt FeuerDOTS Nein, warte!DOTS"


.elseif LANG_EN

.endif


ow_script_map_3_72_person_1:
loadpointer 0x0 str_0x8a068a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a068a:
    .string "Sind die KP eines Pokémon niedrig,\nsollte man ein Heilitem benutzen.\lEinen Trank zum Beispiel!"


.elseif LANG_EN

.endif


ow_script_map_3_72_person_2:
loadpointer 0x0 str_0x8a06ea
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a06ea:
    .string "Die Typenverhältnisse der\nPokémonwelt zu kennen, ist von\lgroßem Vorteil. So kann man seine\lAngriffe effektiv einsetzen!"


.elseif LANG_EN

.endif


ow_script_map_3_72_person_3:
loadpointer 0x0 str_0x8a0763
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a0763:
    .string "Der Angriff eines Pokémons bestimmt\nüber die Stärke seiner physischen\lAngriffe. Der Spezial-Angriff\ldagegen stärkt die speziellen\lAttacken. Ähnlich verhält es sich\lmit den Verteidigungswerten."


.elseif LANG_EN

.endif

ow_script_trainerschool_rival:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test_rival
loadpointer 0x0 str_after_test_rival
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
end

before_test_rival:
loadpointer 0x0 str_before_test_rival
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
end

.ifdef LANG_GER

str_before_test_rival:
    .autostring 35 2 "Wegen dir habe ich von Faun eine Standpauke bekommen!\pBeste Freunde können auch mal ein Klotz am Bein sein, wie es scheint!"

str_after_test_rival:
	.autostring 35 2 "Das ist ja lachhaft!\nWas sich Faun wohl bei diesem Test gedacht hat?\pLachhaft, wirklich!"

.elseif LANG_EN

.endif