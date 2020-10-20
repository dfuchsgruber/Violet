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
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_RUMINATIVE
end

before_test_blaise:
loadpointer 0x0 str_before_test_blaise
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT MSG_FACE
end

.ifdef LANG_GER

str_before_test_blaise:
    .autostring 35 2 "DOTS DOTS DOTS"
str_after_test_blaise:
	.autostring 35 2 "Wie kommt dieser verrückte alte Knacker denn auf so einen Test?"

.elseif LANG_EN
str_before_test_blaise:
    .autostring 35 2 "DOTS DOTS DOTS"
str_after_test_blaise:
	.autostring 35 2 "How on earth did this crazy old geezer come up with a test like that?"

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
	loadpointer 0x0 str_after_test_m
	return

.ifdef LANG_GER
str_before_test_m:
	.autostring 35 2 "PLAYER, du Schlafmütze!\nHehe!\pHusch, auf deinen Platz, oder du fällst durch, Junge!"
str_before_test_f:
	.autostring 35 2 "PLAYER, du Schlafmütze!\nHehe!\pHusch auf deinen Platz, oder du fällst durch, Mädchen!"
str_after_test_m:
	.autostring 35 2 "Wie?\nDu fandest den Test unfair?\pAch ja?\nFragen, auf die man die Antworten gar nicht hätte wissen können?\pDenkst du etwa, dass man als Trainer die Antworten auf alle Fragen immer kennt?"

.elseif LANG_EN
str_before_test_m:
	.autostring 35 2 "PLAYER, you sleepy head!\nHehe!\pTake seat, boy!"
str_before_test_f:
	.autostring 35 2 "PLAYER, you sleepy head!\nHehe!\pTake a seat, girl!"
str_after_test_m:
	.autostring 35 2 "Come again?\nYou think the test was unfair?\pIs that so?\nQuestion you couldn't have known the answer to?\pDo you think that as a trainer you will always know the answer to everything?"

.endif

ow_script_trainerschool_felix:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test_felix
loadpointer 0x0 str_after_test_felix
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_ANGRY
end

before_test_felix:
loadpointer 0x0 str_before_test_felix
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_ANNOYED
end

.ifdef LANG_GER

str_before_test_felix:
    .autostring 35 2 "PLAYERDOTS\pGerade heute hier zu spät aufkreuzen.\pDu hast vielleicht NervenDOTS"
str_after_test_felix:
	.autostring 35 2 "Was für ein unsinnger Test!\pWer soll solche Fragen denn beantworten können?\pWas hat sich Opi dabei nur gedachtDOTS"

.elseif LANG_EN

str_before_test_felix:
    .autostring 35 2 "PLAYERDOTS\pBeing late on a day like this!\pYou really got some nervesDOTS"
str_after_test_felix:
	.autostring 35 2 "What a stupid test!\pWho is even able to answer question like that?\pWhat was grandpa thinking?"
.endif

ow_script_trainerschool_maike:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test_may
loadpointer 0x0 str_after_test_may
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_SAD
end

before_test_may:
loadpointer 0x0 str_before_test_may
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_SCARED
end

.ifdef LANG_GER

str_before_test_may:
    .autostring 35 2 "Ich binDOTS\nDOTSso unvorbereitetDOTS\pDiesen Test werde ich niemals bestehenDOTS"
str_after_test_may:
	.autostring 35 2 "SchniefDOTS\pBei diesen Fragen bin ich mir ganz sicher, durchgefallen zu seinDOTS"

.elseif LANG_EN

str_before_test_may:
    .autostring 35 2 "I am just soDOTS\nDOTSpoorly prepearedDOTS\pI will never pass that testDOTS"
str_after_test_may:
	.autostring 35 2 "SobDOTS\pAfter questions like these I am just certain that I failed the examDOTS"

.endif


ow_script_map_3_72_person_5:
loadpointer 0x0 str_0x89f1c6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x89f1c6:
    .autostring 34 2 "Die Schule ist so ermüdend!\pIch freue mich schon darauf, wenn ich hiermit fertig bin.\pDanach wird bestimmt alles besser!"
.elseif LANG_EN
str_0x89f1c6:
    .autostring 34 2 "School is so tedious!\pI can't wait until I am done with all of this.\pAfter that, everything will get a lot better!"

.endif


ow_script_map_3_72_person_4:
loadpointer 0x0 str_0x8a05dd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a05dd:
    .autostring 34 2 "Diese Statue stellt Fauns Liebingspokémon Flunkifer dar.\pSeines soll unglaublich stark sein!"
.elseif LANG_EN
str_0x8a05dd:
    .autostring 34 2 "This is a statue of Mawile, one of Faun's favourites.\pHis one is said to be extremely strong!"
.endif


ow_script_map_3_72_person_0:
loadpointer 0x0 str_0x8a062f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a062f:
    .autostring 34 2 "Feuer schlägt Wasser, Wasser schlägt Pflanze und Pflanze schlägt FeuerDOTS\pNein, warte!DOTS"
.elseif LANG_EN

str_0x8a062f:
    .autostring 34 2 "Fire beats Water, Water beats Grass and Grass beats FireDOTS\pNo, wait!DOTS"
.endif


ow_script_map_3_72_person_1:
loadpointer 0x0 str_0x8a068a
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x8a068a:
    .autostring 34 2 "Wusstest du, dass Beeren nicht nur schön anzusehen sind, sondern auch einen Nutzen im Kampf haben können?"
.elseif LANG_EN
str_0x8a068a:
    .autostring 34 2 "Did you know that berries are not only nice to look at but also can give you an edge in battles?"

.endif


ow_script_map_3_72_person_2:
loadpointer 0x0 str_0x8a06ea
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a06ea:
    .autostring 34 2 "Ich versuche im Kampf stets einen Typenvorteil zu behalten.\pEffektive Angriffe richten viel mehr Schaden an."
.elseif LANG_EN
str_0x8a06ea:
    .autostring 34 2 "I always try to maintain a type advantage in battles.\pSuper effective attacks do way more damage."
.endif


ow_script_map_3_72_person_3:
loadpointer 0x0 str_0x8a0763
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a0763:
    .autostring 34 2 "Mein Pokémon hat einen hohen Angriffswert.\pSeine physischen Angriffe sind also stärker."
.elseif LANG_EN
str_0x8a0763:
    .autostring 34 2 "Mein Pokémon has a high attack stat.\pThat means its physical attacks are stronger."

.endif

ow_script_trainerschool_rival:
compare TRAINERSCHOOL_PROGRESS 2
gotoif LESS before_test_rival
loadpointer 0x0 str_after_test_rival
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_ANGRY
end

before_test_rival:
loadpointer 0x0 str_before_test_rival
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_ANNOYED
end

.ifdef LANG_GER

str_before_test_rival:
	.autostring 34 2 "Toll gemacht, PLAYER!\pWeil du so rumtrödeln musstest, haben wir eine Standpauke von Faun bekommen!"
str_after_test_rival:
	.autostring 34 2 "Was um alles in der Welt?\pWas waren das bitte für Fragen?"
.elseif LANG_EN
str_before_test_rival:
	.autostring 34 2 "Jeez, PLAYER!\pBecause you dawdled arround Faun got super angry at us!"
str_after_test_rival:
	.autostring 34 2 "What in the world?\pWhat kind of questions were those even?"
.endif