.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"
.include "pathfinding.s"

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
.global ow_script_map_felsige_oednis_cook

ow_script_map_felsige_oednis_cook:
    lock
    faceplayer
    loadpointer 0 str_cook_ask
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif NOT_EQUAL cook_battle
    loadpointer 0 str_cook_dont_battle
    callstd MSG_KEEPOPEN
    release
    end
cook_battle:
    trainerbattlecont 1 0x1a3 0 str_cook_before str_cook_after cook_after
cook_after:
    lock
    loadpointer 0 str_cook_give
    callstd MSG_KEEPOPEN
    fanfare 258
    loadpointer 0 str_got_recipe
    callstd MSG_KEEPOPEN
    waitfanfare
    loadpointer 0 str_after_recipe
    callstd MSG_KEEPOPEN
    closeonkeypress
    fadescreen 1
    hidesprite LASTTALKED
    fadescreen 0
    release
    end

.ifdef LANG_GER
str_cook_ask:
    .autostring 34 2 "Hey Kindchen, du siehst aus wie jemand, der absolut keinen Geschmack hat!\pIch bin ein Meisterkoch und weltberühmt für meine Minze.\pIch mach dir ein Angebot, ja?\pWenn du mich im Kampf besiegst, verrate ich dir das Geheimnis meiner Minze!\pWas sagst du dazu?\nKämpfst du gegen mich um das Rezept?"
str_cook_before:
    .autostring 34 2 "Ich werde dir Saures geben, du Tölpel!"
str_cook_after:
    .autostring 34 2 "Na gut, ich gebe ja zu, dass du nicht übel bistDOTS"
str_cook_dont_battle:
    .autostring 34 2 "Das hab ich mir gleich gedacht!\pJemand mit einem so schlechten Geschmack muss auch ein Feigling sein!"
str_cook_give:
    .autostring 34 2 "Da hab dich wohl unterschätzt, was?\pAber abgemacht ist abgemacht.\pIch werde dir mein Rezept für Minze geben."
str_got_recipe:
    .autostring 34 2 "PLAYER hat ein Rezept erhalten!"
str_after_recipe:
    .autostring 34 2 "Mit diesem Rezept kannst du im Pokéstop Minze herstellen, die das Wesen deiner Pokémon beeinflusst.\pEs ist wirklich ein Jammer, dass ich ein solch wertvolles Rezept einem Kind geben mussDOTS\pAber da ist nichts zu machen!\pEin Koch steht zu seinem Wort.\pAber ich muss mir deinen herablassenden Blick trotzdem nicht länger gefallen lassen.\pAdieu, Kindchen!"
.elseif LANG_EN
.endif

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
    .string "Ich sollte zurück in den\nKranzwald gehen."


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
    .string "Vielleicht bleibe ich lieber hier,\nin der Nähe des Kranzwaldes."


.elseif LANG_EN

.endif


ow_script_movs_0x8ec5cb:
.byte SAY_EXCLAM
.byte STOP

.macro npc_faceplayer person_idx:req
    setvar 0x8004 \person_idx
    setvar 0x8005 0xFF
    special SPECIAL_NPC_FACE_TO_NPC
    waitmovement 0
    //special SPECIAL_SET_TARGET_NPC_TO_VAR
.endm

ow_script_map_3_74_trainer_15:
lockall
loadpointer 0 str_faun0
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
loadpointer 0 str_faun1
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
loadpointer 0 str_faun2
show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY 
closeonkeypress
pause 64
loadpointer 0 str_faun3
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SCARED
loadpointer 0 str_faun4
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SCARED
closeonkeypress
pause 24
loadpointer 0 str_faun5
show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
npc_faceplayer 25
npc_faceplayer 31
npc_faceplayer 32
sound 0x15
applymovement 25 mov_exclam
applymovement 31 mov_exclam
applymovement 32 mov_exclam
waitmovement 0
checksound
loadpointer 0 str_faun6
show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
applymovement 31 mov_fu
applymovement 32 mov_fu
waitmovement 0
loadpointer 0 str_faun7
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
closeonkeypress
sound 0x15
applymovement 25 mov_fd
waitmovement 0
applymovement 25 mov_smile
waitmovement 0
checksound
loadpointer 0 str_faun8
show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
loadpointer 0 str_faun9
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
applymovement 32 mov_fr
waitmovement 0
loadpointer 0 str_faun10
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANNOYED
applymovement 32 mov_fu
waitmovement 0
loadpointer 0 str_faun11
show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
closeonkeypress
npc_move_to 25 0x30 0x17 waitmovement=0
pause 64
applymovement 32 mov_fd
applymovement 31 mov_fd
applymovement 0xFF mov_fd
waitmovement 25
hidesprite 25
loadpointer 0 str_faun12
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANNOYED
applymovement 32 mov_fr
waitmovement 0
loadpointer 0 str_faun13
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANNOYED
closeonkeypress
npc_move_to 32 0x30 0x17 waitmovement=1
hidesprite 32
loadpointer 0 str_faun14
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SHOCKED
closeonkeypress
npc_move_to 31 0x31 0x17 speed=A_STAR_SPEED_FAST waitmovement=0
waitmovement 31
hidesprite 31
clearflag SILVANIA_FAUN_AND_MIA
addvar STORY_PROGRESS 0x1
releaseall
end



mov_exclam:
    .byte SAY_EXCLAM, STOP
mov_smile:
    .byte SAY_SMILE, STOP
mov_fu:
    .byte LOOK_UP, STOP
mov_fl:
    .byte LOOK_LEFT, STOP
mov_fr:
    .byte LOOK_RIGHT, STOP
mov_fd:
    .byte LOOK_DOWN, STOP

.ifdef LANG_GER
str_faun0:
    .autostring 34 2 "Aber Opi!\pDu bist doch ein Mitglied der Top Vier!\pDu musst uns im Kampf gegen Team Violet unterstützen!"
str_faun1:
    .autostring 34 2 "Felix hat Recht!\pDiese Bande hat meinen Vater angegriffen!\pDamit können wir sie nicht davon kommen lassen!"
str_faun2:
    .autostring 34 2 "Jetzt reißt euch erst einmal zusammen!\pWie redet ihr eigentlich mit mir?\pGlaubt ihr, nur weil ihr jetzt Trainer seid, dass ihr keinen Respekt mehr zu haben braucht?\pIch sage euch mal was, ihr Gören!\pIhr seid eintausend Jahre zu früh dran, in einem solchen Ton mit mir zu reden, ja?"
str_faun3:
    .string "DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT"
str_faun4:
    .autostring 34 2 "Entschuldige OpiDOTS"
str_faun5:
    .autostring 34 2 "Na, schon viel besser, oder?\pJetzt können wir uns auch über dieses Team Violet unterhalten, ja?"
str_faun6:
    .autostring 34 2 "Ah, PLAYER!\pDu kommst genau rechtzeitig!\pDeine Schulfreunde haben sich zwar etwas im Ton vergriffen, aber ich glaube, die beiden haben sich in den Kopf gesetzt, Team Violet zu bekämpfen."
str_faun7:
    .autostring 34 2 "Genau das werden wir tun!\pUnd PLAYER wird uns übrigens dabei helfen!"
str_faun8:
    .autostring 34 2 "Aha!\nNa ihr scheint es ja ganz schön ernst zu meinen.\pAlso gut, ich will mir das genau anhören, was ihr zu sagen habt.\pDieser Kommandant von Team Violet soll sich in Kranzdorf aufhalten, ja?\pDann sollten wir auf jeden Fall die Arenaleiterin Rosalie mit ins Boot holen.\pDie wird auch etwas von einem Kampf gegen Team Violet wissen wollen."
str_faun9:
    .autostring 34 2 "Eine Arenaleiterin?\pWir brauchen aber keine Hilfe!\pWir schlagen Team Violet auch zu dritt!"
str_faun10:
    .autostring 34 2 "Werd' mal nicht übermütig, RIVALDOTS\pWir wissen gar nicht, was auf uns zu kommtDOTS"
str_faun11:
    .autostring 34 2 "Felix hat Recht!\pDa haben sie dir bei der Polizei wohl etwas Vernunft beigebracht, was?\pIch werde mich auf die Suche nach Rosalie machen.\pWir treffen uns dann in ihrem Haus in Kranzdorf, verstanden?\pUnd denkt gar nicht daran, zu trödeln!"
str_faun12:
    .autostring 34 2 "Wie langweiligDOTS\pJetzt mischt sich ein Arenaleiter in unser Abenteuer einDOTS"
str_faun13:
    .autostring 34 2 "Du bist wirklich ein hoffnungsloser Fall, RIVALDOTS"
str_faun14:
    .autostring 34 2 "H-Hey!\nWarte!\pIch werde doch einem Polizisten nicht den ganzen Spaß überlassen!"
.elseif LANG_EN
.endif



.ifdef LANG_GER

str_0x8ec458:
	.autostring 35 2 "PLAYER!\nIch habe alle Hände voll zu tun.\pMan hat Albus, den Anführer der Revolutionsbewegung hier gesichtet.\pDie Revolutionäre sind die wohl gefährlichste Gruppe unserer Zeit.\pWenn es ihnen gelingt, die Regierung zu stürzen, versinkt der Kontinent im Chaos.\pNoch dazu belagert eine Kommandantin dieser Violet Punks den Kranzwald.\pDOTS DOTS DOTS\nIch kann mich nicht beiden Problemen gleichzeitig widmen DOTS"


str_0x8e8f9d:
    .autostring 35 2 "Ich kann mich ja der Kommandantin von Team Violet annehmen."



str_0x8e8da8:
    .autostring 35 2 "PLAYER!\nIch habe volles Vertrauen in dich, aber ich denke nicht, dass du einem Kommandanten von Team Violet gewachsen bist.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWenn ich es mir recht überlege, sollten wir das mit der Arenaleiterin von Kranzdorf absprechen.\pWir treffen uns in ihrem Haus in Kranzdorf.\pIch zähle auf dich, PLAYER."

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
    .string "Ich muss hier so lange Wache\nhalten, bis Rin ihre Mission im\lKranzwald erledigt hat!"



str_0x8f4d9d:
    .string "DOTS Äh DOTS in dieser Version bin\nich zwar noch hier, in der\lnächsten aber werde ich dir den\lWeg schon freigemacht haben!"


.elseif LANG_EN

.endif