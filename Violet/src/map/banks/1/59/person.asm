.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"
.include "songs.s"
.include "ordinals.s"

.global ow_script_map_1_59_trainer_2
.global ow_script_map_1_59_trainer_10
.global ow_script_map_1_59_trainer_0
.global ow_script_map_1_59_trainer_4
.global ow_script_map_1_59_trainer_8
.global ow_script_map_1_59_trainer_6
.global ow_script_map_1_59_trainer_12
.global ow_script_0x8aaf68
.global ow_script_map_1_59_person_0
.global ow_script_map_1_59_trainer_3
.global ow_script_map_1_59_trainer_11
.global ow_script_map_1_59_trainer_13
.global ow_script_map_1_59_trainer_15
.global ow_script_map_1_59_trainer_1
.global ow_script_map_1_59_trainer_5
.global ow_script_map_1_59_trainer_14
.global ow_script_map_1_59_trainer_9
.global ow_script_map_1_59_trainer_7
.global ow_script_kuestenberg_harrenfeld

ow_script_kuestenberg_harrenfeld:
    loadpointer 0x0 str_harrenfeld
    show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT MSG
    end


.ifdef LANG_GER
str_harrenfeld:
    .autostring 34 2 "PLAYER!\nDu kommst gerade recht!\pDiese Revolutionäre sind verflixt hartnäckig!\pAber Faun ist bereits weiter vorgedrungen, um den Revolutionsführer Albus zu stellen!"

.elseif LANG_EN
.endif

ow_script_map_1_59_trainer_1:
trainerbattlestd 0x0 0x6c 0x0 str_0x927db0 str_0x927d4e
loadpointer 0x0 str_0x927d4e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x927db0:
    .string "Hey, du da!\nDu kannst da nicht lang, unser\lAnführer hat dort zu tun.\pEr wird die Welt zu einem besseren\nOrt machen, weswegen ich dich\lnicht passieren lassen kann."



str_0x927d4e:
    .string "Wieso widersetzt du dich dem\nRecht, dem Frieden? Träumst du\lnicht auch von einer besseren\lWelt?"


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_6:
loadpointer 0x0 str_0x927e54
callstd MSG_FACE
end


.ifdef LANG_GER

str_police:

str_0x927e54:
	.autostring 35 2 "Argh!\pDiese verdammten Revolutionäre!\pAber Lord Faun wird diesen Regierungsfeinden einen Denkzettel verpassen!"


.elseif LANG_EN

.endif


ow_script_0x8aaf68:
loadpointer 0x0 str_0x927ee7
callstd MSG
end


.ifdef LANG_GER

str_0x927ee7:
    .string "Nimm das, du Schurke!\pWir wollen keine Revolution hier,\nwir brauchen keinen Krieg!"


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_5:
loadpointer 0x0 str_0x927f3b
callstd MSG
end


.ifdef LANG_GER

str_0x927f3b:
    .string "Du bist stark, aber ich kann dir\nnicht erlauben, zu gewinnen.\pSo viele Menschen verlassen sich\ndarauf, dass wir Frieden wahren."


.elseif LANG_EN

.endif


ow_script_map_1_59_person_0:
loadpointer 0x0 str_0x927fbc
callstd MSG
end


.ifdef LANG_GER

str_0x927fbc:
    .string "Ihr systemtreuen Narren! Versteht\nihr nicht, dass alles dem\lUntergang geweiht ist?"


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_4:
loadpointer 0x0 str_0x928010
callstd MSG
end


.ifdef LANG_GER

str_0x928010:
    .string "Wenn wir nicht für eine bessere\nWelt kämpfen, wer dann?"


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_0:
trainerbattlestd 0x0 0x6d 0x0 str_0x928049 str_0x9280cb
loadpointer 0x0 str_0x9280cb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x928049:
    .string "Du willst dich der Revolution in\nden Weg stellen? Du willst dich\lder Freiheit in den Weg stellen?\lDas werde ich nicht zulassen."



str_0x9280cb:
    .string "Dein Handeln wird hunderte in die\nVerdammnis stürzen."


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_2:
loadpointer 0x0 str_0x928102
callstd MSG
end


.ifdef LANG_GER

str_0x928102:
    .string "Was erhofft ihr zu erreichen? Eure\nRevolution wird scheitern, die\lWelt ist nicht bereit für eure\lIdeale!"


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_3:
loadpointer 0x0 str_0x92816c
callstd MSG
end


.ifdef LANG_GER

str_0x92816c:
    .string "Die Herrschaft von Unredlichkeit\nund Geld wird mit uns ein Ende\lfinden. Albus wird uns retten."


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_9:
loadpointer 0x0 str_0x92d0bb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x92d0bb:
    .string "Der Küstenberg ist seither bekannt\nfür seine reinen Quellen, die den\lganzen Kontinent mit Wasser\lversorgen.\pDas Meerwasser wird im Laufe der\nJahrtausende vom Gestein\lgesäubert."


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_7:
trainerbattlestd 0x0 0x6e 0x0 str_0x9281cc str_0x928233
loadpointer 0x0 str_0x928233
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9281cc:
    .string "Unser Anführer ist einer der\nmächtigsten Trainer der Region.\pEr beherrscht sogar die\nMega-Evolution."



str_0x928233:
    .string "Du weißt nicht, was die\nMega-Evolution ist?\pKein Wunder, dass du dich nicht\nmit ihm messen kannst."


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_11:
loadpointer 0x0 str_0x9284d1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9284d1:
    .string "Immer häufiger sehe ich hier\ndubiouse Gestalten wandeln, die\laus dieser Höhle im Norden zu\lkommen scheinen."


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_12:
loadpointer 0x0 str_0x928e02
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x928e02:
    .string "Kaskada wurde am Fuß des\nKüstenbergs erbaut und benutzt die\lEnergie der Wasserfälle, um eine\lStromversorgung zu garantieren."


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_13:
loadpointer 0x0 str_0x92dce2
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x92dce2:
    .string "Ein Blick aufs Meer genügt, mein\nHerz mit Sehensucht zu erfüllen.\pWie gerne ich doch auf einem\nLapras in den Sonnenunterang\lsegeln würdeDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_14:
trainerbattlestd 0x0 0x70 0x0 str_0x92d16d str_0x92dd6f
loadpointer 0x0 str_0x92dd6f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x92d16d:
    .string "Was ist eine schönere Szenerie für\neinen Kampf als eine Klippe am\lMeer?"



str_0x92dd6f:
    .string "Es wäre hilfreich gewesen, weniger\nder Landschaft die Aufmerksamkeit\lzu schenken und mehr dem KampfDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_10:
trainerbattlestd 0x0 0x6f 0x0 str_0x92ddd7 str_0x92de26
loadpointer 0x0 str_0x92de26
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x92ddd7:
    .string "Wärst du eine Blume, würde ich\ndich pflücken, du bist so hübsch\lanzusehenDOTS"



str_0x92de26:
    .string "Unglücklicherweise aber hast du\nnun mich gepflücktDOTS Findest du\lmich etwa auch anziehend?"


.elseif LANG_EN

.endif

movs:
.byte LOOK_UP
.byte STOP


ow_script_map_1_59_trainer_8:
lock
faceplayer
loadpointer 0x0 str_0
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL no_story
playsong MUS_DARK_QUEEN 0x0
applymovement LASTTALKED movs
waitmovement 0x0
setvar 0x8004 0x1
special SPECIAL_CUTSCENE_SHOW
waitstate
loadpointer 0x0 str_story
callstd MSG
setvar 0x8004 0x2
special SPECIAL_CUTSCENE_SHOW
waitstate
fadesong MUS_ROUTE_24_25
loadpointer 0x0 str_after
callstd MSG_FACE
end

no_story:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hehe!\pWer ich bin?\pEine Hexe natürlich, was sonst?\pMöchtest du eine spannende Geschichte hören?"
str_1:
    .autostring 34 2 "Wie auch immerDOTS\pSolltest du deine Meinung ändern, findest du mich hierDOTS"
str_story:
    .autostring 34 2 "Vor vielen Jahren herrschte eine dunkle Königin über diese Region, lange noch, bevor es die Top Vier überhaupt gab.\pSie war eine tyrannische, machtsüchtige Frau, und unfassbar mächtig.\pSie bändigte eigenhändig zahlreiche legendäre Pokémon und kein Mensch war im Stande, ihr Einhalt zu gebieten.\pEines Tages erklärte sie dann den Göttern unserer Welt den Krieg.\pLetztlich wurde sie für ihren Hochmut bestraft und vernichtet.\pEs heißt, dass ihr unsterblicher Geist noch immer umherirrt."
str_after:
    .autostring 34 2 "Viele Hexen sind auf der Suche nach dem Geist der dunklen Königin.\pSie gilt als die Mutter des Hexentums."
.elseif LANG_EN
str_0:
    .autostring 34 2 "Hehe!\pWho I am?\pWhy, a witch of course, what else?\pDo you want to hear a compelling story?"
str_1:
    .autostring 34 2 "WhateverDOTS\pIf you change your mind you can find me right hereDOTS"
str_story:
    .autostring 34 2 "Many years ago a dark queen ruled over this region, long before the Elite Four even were thing.\pShe was a tyrant and her lust for power was without any limit.\pAbove all however, she was unmatched in power.\pShe tamed many legendary Pokémon on her own and nobody was able to stand up to her.\pSome day she declared war on the gods of this world.\pFor this grandeure she was punished in the end and utterly destroyed.\pIt is said that her spirit wanders arround in this world to this very day."
str_after:
    .autostring 34 2 "Many witches are still searching for the spirit of the dark queen.\pShe is considered to be the mother of witchcraft."

.endif


ow_script_map_1_59_trainer_15:
settrainerflag 0xa7
trainerbattlestd 0x0 0xa7 0x0 str_0x94560d str_0x94560d
end


.ifdef LANG_GER

str_0x94560d:
    .string "a"


.elseif LANG_EN

.endif