.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "mugshot.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_map_3_72_person_5
.global ow_script_map_3_72_person_2
.global ow_script_map_3_72_person_1
.global ow_script_map_3_72_person_3
.global ow_script_map_3_72_person_0
.global ow_script_map_3_72_person_4
.global ow_script_trainerschool_felix
.global ow_script_trainerschool_maike
.global ow_script_trainerschool_blaise
.global ow_script_trainerschool_faun
.global ow_script_trainerschool_faun_inside

ow_script_map_3_72_person_5:
loadpointer 0x0 str_0x89f1c6
callstd MSG_FACE
end

ow_script_trainerschool_faun_inside:
	loadpointer 0 str_faun_inside
	show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT message_type=MSG_FACE
	end

.ifdef LANG_GER
str_faun_inside:
	.autostring 34 2 "PLAYER!\pWie schlägst du dich?\pDu warst einer meiner faszinierendsten Schüler.\pDu hast wirklich eine Gabe für Pokémonkämpfe.\pIch bin mir sicher, dass du für Großes bestimmt bist!"
.elseif LANG_EN
str_faun_inside:
	.autostring 34 2 "PLAYER!\pHow are you doing?\pYou were one of my most fascinating students.\pYou really have a gift for Pokémon battles.\pI am sure you are destined for greatness!"
.endif

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
