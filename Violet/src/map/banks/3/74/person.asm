.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"

.global ow_script_map_3_74_trainer_10
.global ow_script_0x8e2f3f
.global ow_script_map_3_74_trainer_7
.global ow_script_map_3_74_trainer_6
.global ow_script_map_3_74_trainer_1
.global ow_script_map_3_74_trainer_3
.global ow_script_0x8f4675
.global ow_script_map_3_74_trainer_0
.global ow_script_0x8e2d6f
.global ow_script_0x8e601c
.global ow_script_map_3_74_trainer_17
.global ow_script_0x8ecbe0
.global ow_script_map_3_74_trainer_15
.global ow_script_map_3_74_trainer_8
.global ow_script_map_3_74_trainer_11
.global ow_script_map_3_74_trainer_5
.global ow_script_map_3_74_trainer_16
.global ow_script_map_3_74_trainer_2
.global ow_script_map_3_74_person_0
.global ow_script_map_3_74_trainer_12
.global ow_script_0x8ecbfa
.global ow_script_0x8e305a
.global ow_script_map_3_74_trainer_4
.global ow_script_map_3_74_trainer_9
.global ow_script_0x8e6853
.global ow_script_map_3_74_trainer_13
.global ow_script_map_3_74_trainer_14

ow_script_map_3_74_trainer_10:
trainerbattlestd 0x0 0x3b 0x0 str_0x81c2e7 str_0x81c32b
loadpointer 0x0 str_0x81c32b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81c2e7:
    .string "Ein Ass-Trainer hat seine Pokémon\nstets ausgewogen zu trainieren!"



str_0x81c32b:
    .string "Ein ausgewogenes Training ist der\nSchlüssel zum Erfolg!"


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_17:
getplayerpos 0x8000 0x8001
draw_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
settrainerflag 0x3
trainerbattlecont 0x1 0x3 0x0 str_0x81c4e9 str_0x81c4e9 ow_script_0x8ecbe0


ow_script_0x8ecbe0:
goto ow_script_0x8ecbfa


ow_script_0x8ecbfa:
additem ITEM_SONDERBONBON 0x63
loadpointer 0x0 str_0x81c4e9
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
end


.ifdef LANG_GER

str_0x81c4e9:
    .string "koo"


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_14:
trainerbattlestd 0x0 0x3c 0x0 str_0x8774d7 str_0x88adf9
loadpointer 0x0 str_0x88adf9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8774d7:
    .string "Es heißt, dass es in der Wüste\ngoldene Kateen geben soll.\lOb das stimmt?"



str_0x88adf9:
    .string "Vielleicht werde ich nach goldenen\nKakteen suchenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_74_person_0:
loadpointer 0x0 str_0x8e1081
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e1081:
    .string "Dieser Ort trägt den Namen\nFelsige Ödnis zurecht.\lIn dieser Savanne findet man\linteressante Pokémon."


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_0:
trainerbattlestd 0x0 0x2d 0x0 str_0x8e101d str_0x8e1060
loadpointer 0x0 str_0x8e1060
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e101d:
    .string "Dieser Weg führt ostwärts in eine\nWüste. Halte dich lieber fern!"



str_0x8e1060:
    .string "Wüsten sind trocken und heißDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_1:
trainerbattlestd 0x0 0x2e 0x0 str_0x8e1843 str_0x8e18b9
loadpointer 0x0 str_0x8e18b9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e1843:
    .string "Das Wetter in dieser Gegend ist\ngrauenvoll. In dieser ariden\lUmgebung können meine Pflanzen-\lPokémon nicht wachsen!"



str_0x8e18b9:
    .string "Ich sollte zurück in den\nSilvania-Wald gehen."


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_2:
trainerbattlestd 0x0 0x2f 0x0 str_0x8e10e9 str_0x8e18e8
loadpointer 0x0 str_0x8e18e8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e10e9:
    .string "Ein enges Band zu seinen Pokémon\nist für Erfolg essentiell."



str_0x8e18e8:
    .string "Mir scheint, du pfelgst eine sehr\ninnige Beziehung zu deinen\lPokémon."


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_7:
loadpointer 0x0 str_0x8e2c92
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e2c92:
    .string "Ich suche hier nach dem Pokémon\nSkorgla. Es heißt, dass es sich\lhier finden lässt."


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_3:
trainerbattlestd 0x0 0x30 0x0 str_0x8e1c76 str_0x8e1cdd
loadpointer 0x0 str_0x8e1cdd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e1c76:
    .string "Es heißt, der Champion der Region\nsei ein junger Mann. Andere\lsprechen von einer wunderschönen\lLady."



str_0x8e1cdd:
    .string "Wer auch immer der Champion Thetos\nist, er muss unglaublich stark\lsein."


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_4:
trainerbattlestd 0x0 0x31 0x0 str_0x8e1d3e str_0x8e2ad4
loadpointer 0x0 str_0x8e2ad4
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e1d3e:
    .string "Mein Herz gehört einem Jungen, der\nmich vor langer Zeit allein\lgelassen hat."



str_0x8e2ad4:
    .string "In einem Vergnügungspark habe ich\nihn das letzte Mal gesehenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_11:
loadpointer 0x0 str_0x8e66ad
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e66ad:
    .string "Pokémon, die sich durch Tausch\nentwickeln, können ihre Evolution\lstattdessen mithilfe eines\lsimulierten Tauschs durchführen.\pEin Linkkabel wird dazu aber\nbenötigt, und man sagt sich, dass\ldiese äußert selten sind."


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_5:
trainerbattlestd 0x0 0x32 0x0 str_0x8e2b2d str_0x8e2ba1
loadpointer 0x0 str_0x8e2ba1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e2b2d:
    .string "Viele Wanderer treten den\nbeschwerlichen Pfad durch die\lÖdnis und Wüste nach Kaskada an.\pDas zeugt von Fähigkeit."



str_0x8e2ba1:
    .string "In Kaskada erwarten einen die\nreinsten Wasserquellen der ganzen\lRegion, so sagt man."


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_6:
trainerbattlestd 0x0 0x33 0x0 str_0x8e2c0f str_0x8e2c5c
loadpointer 0x0 str_0x8e2c5c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e2c0f:
    .string "In körperlicher Form zu bleiben\nhat höchste Priorität für uns\lTriathleten!"



str_0x8e2c5c:
    .string "Ich und meine Pokémon müssen\nhärter an uns arbeiten!"


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_8:
checkflag FELSIGE_ODNIS_BEERENSAFT_QUEST_DONE
gotoif EQUAL ow_script_0x8e305a
checkflag FELSIGE_ODNIS_BEERENSAFT_QUEST_ACCEPTED
gotoif EQUAL ow_script_0x8e601c
lock
faceplayer
loadpointer 0x0 str_0x8e2f49
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8e2d6f
loadpointer 0x0 str_0x8e2d1b
callstd MSG
setflag FELSIGE_ODNIS_BEERENSAFT_QUEST_ACCEPTED
release
end


ow_script_0x8e2d6f:
loadpointer 0x0 str_0x8e2d79
callstd MSG_FACE
end


ow_script_0x8e601c:
checkitem ITEM_SINELBEERE 0x19
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8e2f3f
removeitem ITEM_SINELBEERE 0x19
lock
faceplayer
loadpointer 0x0 str_0x8e2f06
callstd MSG
lock
loadpointer 0x0 str_0x8e2ee7
callstd MSG_KEEPOPEN
lock
closeonkeypress
lock
loadpointer 0x0 str_0x8e2e62
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_BEERENSAFT
copyvarifnotzero 0x8001 25
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x8e3064
callstd MSG
setflag FELSIGE_ODNIS_BEERENSAFT_QUEST_DONE
release
end


ow_script_0x8e2f3f:
loadpointer 0x0 str_0x8e2d1b
callstd MSG_FACE
end


ow_script_0x8e305a:
loadpointer 0x0 str_0x8e3064
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e2f49:
    .string "Mein Hobby ist es, Beerensaft\nherzustellen. Gerade arbeite ich\lan einem Saft, der aus dem Extrakt\lvon Sinelbeeren hergestellt wird.\lWenn du mir genügend Sinelbeeren\lbesorgst, habe ich ein Geschenk\lfür dich.\pIch brauche - ähm - sagen wir etwa\l25 Stück.\pWas sagst du dazu?"



str_0x8e2d1b:
    .string "Etwa 25 Sinelbeeren sollten\nausreichen, um meine neuste\lKreation fertigzustellen."



str_0x8e2d79:
    .string "Das ist äußerst schade. Wir beide\nwürden davon profitieren. Was ich\ldir zu bieten habe, ist für jeden\lTrainer sehr begehrenswert."



str_0x8e2f06:
    .string "Oh, wie wunderbar! Du hast mir 25\nSinelbeeren besorgt!"



str_0x8e2ee7:
    .string "PLAYER übergibt die\nSinelbeeren."



str_0x8e2e62:
    .string "Sei unbesorgt, ich werde nun auch\nmeinen Teil der Vereinbarung\lerfüllen. Nimm diese versteckte\lMaschine als Zeichen meines\lDankes!"



str_0x8e3064:
    .string "Beerensaft heilt die Kraftpunkte\ndeines Pokémons im Kampf und\lschmeckt dazu auch noch äußert\lgut!"


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_9:
trainerbattlestd 0x0 0x34 0x0 str_0x8e30de str_0x8e311d
loadpointer 0x0 str_0x8e311d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e30de:
    .string "Auch wir Jugendlichen können es\nweit bringen in dieser Welt!"



str_0x8e311d:
    .string "Siehst du? Du hast mich\ngeschlagen und wirst den Geist\lunserer Generation in die Welt\ltragen!"


.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_12:
trainerbattlestd 0x0 0x38 0x0 str_0x8e6784 str_0x8e67f6
loadpointer 0x0 str_0x8e67f6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e6784:
    .string "Viele ziehen ihre Pokémon nur zum\nKämpfen auf. Sie mit Liebe zu\lbehandeln ist allerdings nicht\lweniger wichtig."



str_0x8e67f6:
    .string "Eine Niederlage ist absolut keine\nSchande. Meine Pokémon haben ihr\lBestes gegeben."


.elseif LANG_EN

.endif

ow_script_0x8e6853:
setvar 0x8000 POKEMON_FLUFFELUFF
call ow_script_find_egg
end


ow_script_map_3_74_trainer_13:
trainerbattlestd 0x0 0x39 0x0 str_0x8e687b str_0x8e6906
loadpointer 0x0 str_0x8e6906
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e687b:
    .string "Ich habe Bedenken, weiter östlich\nzu wandern, denn dort liegt eine\ltödliche Wüste. Viele Wanderer\lsollen dort bereits verschwunden\lsein."



str_0x8e6906:
    .string "Vielleicht bleibe ich lieber hier,\nin der Nähe des Silvania-Waldes."


.elseif LANG_EN

.endif


ow_script_movs_0x8ec5cb:
.byte SAY_EXCLAM
.byte STOP


ow_script_map_3_74_trainer_15:
lockall
sound 0x15
applymovement 0x800f ow_script_movs_0x8ec5cb
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x8ec458
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE
loadpointer 0x0 str_0x8e8f9d
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_FACE
loadpointer 0x0 str_0x8e8da8
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE
fadescreen 0x1
hidesprite 0x800f
clearflag SILVANIA_FAUN_AND_MIA
addvar STORY_PROGRESS 0x1
fadescreen 0x0
releaseall
end


.ifdef LANG_GER

str_0x8ec458:
	.autostring 35 2 "PLAYER!\nIch habe alle Hände voll zu tun.\pMan hat Albus, den Anführer der Revolutionsbewegung hier gesichtet.\pDie Revolutionäre sind die wohl gefährlichste Gruppe unserer Zeit.\pWenn es ihnen gelingt, die Regierung zu stürzen, versinkt der Kontinent im Chaos.\pNoch dazu belagert eine Kommandantin dieser Violet Punks den Silvania-Wald.\pDOTS DOTS DOTS\nIch kann mich nicht beiden Problemen gleichzeitig widmen DOTS"


str_0x8e8f9d:
    .autostring 35 2 "Ich kann mich ja der Kommandantin von Team Violet annehmen."



str_0x8e8da8:
    .autostring 35 2 "PLAYER!\nIch habe volles Vertrauen in dich, aber ich denke nicht, dass du einem Kommandanten von Team Violet gewachsen bist.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWenn ich es mir recht überlege, sollten wir das mit der Arenaleiterin von Silvania absprechen.\pWir treffen uns in ihrem Haus in Silvania.\pIch zähle auf dich, PLAYER."

.elseif LANG_EN

.endif


ow_script_map_3_74_trainer_16:
checkflag SILVANIA_FOREST_RIN
gotoif EQUAL ow_script_0x8f4675
loadpointer 0x0 str_0x8f461a
callstd MSG_FACE
end


ow_script_0x8f4675:
loadpointer 0x0 str_0x8f4d9d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f461a:
    .string "Ich muss hier so lange Wache\nhalten, bis Rin ihre Mission im\lSilvania-Wald erledigt hat!"



str_0x8f4d9d:
    .string "DOTS Äh DOTS in dieser Version bin\nich zwar noch hier, in der\lnächsten aber werde ich dir den\lWeg schon freigemacht haben!"


.elseif LANG_EN

.endif