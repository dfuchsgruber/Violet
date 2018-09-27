.include "overworld_script.s"
.include "vars.s"
.include "callstds.s"
.include "movements.s"
.include "songs.s"
.include "flags.s"

.global ow_script_0x9730ba

ow_script_0x9730ba:
call ow_script_0x936c1c
loadpointer 0x0 str_0x971e16
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x971d73
callstd MSG
special 0x7
pause 0x1
setvar SONG_OVERRIDE 0x0
playsong MUS_PUNKTLOCH_AND_TANIBOSCHLUSSEL_AND_ICOGNITO_KAMMERN 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x971d60
callstd MSG
special 0x7
pause 0x1
applymovement 0x1 ow_moves_0x971d5d
waitmovement 0x0
call ow_script_0x97231c
loadpointer 0x0 str_0x971c82
callstd MSG
special 0x7
pause 0x1
call ow_script_0x936c1c
loadpointer 0x0 str_0x971c05
callstd MSG
special 0x7
call ow_script_0x97231c
loadpointer 0x0 str_0x953d08
callstd MSG
special 0x7
pause 0x1
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x9718d8
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x9717c3
callstd MSG
special 0x7
pause 0x1
playsong MUS_SPIELHALLE_VERSION_3 0x0
fadescreen 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x971424
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96fd7a
callstd MSG
special 0x7
pause 0x1
fadesong MUS_PUNKTLOCH_AND_TANIBOSCHLUSSEL_AND_ICOGNITO_KAMMERN
fadescreen 0x0
call ow_script_0x936c1c
loadpointer 0x0 str_0x96fa81
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x96f811
callstd MSG
special 0x7
pause 0x1
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x96f680
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x96f55c
callstd MSG
special 0x7
pause 0x1
call ow_script_0x936c1c
loadpointer 0x0 str_0x96f427
callstd MSG
special 0x7
applymovement 0xff ow_moves_0x96eff0
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x96ef94
callstd MSG
special 0x7
pause 0x1
applymovement 0xff ow_moves_0x96ef91
waitmovement 0x0
call ow_script_0x97231c
loadpointer 0x0 str_0x96edc1
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96ef26
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96ef5f
callstd MSG
special 0x7
pause 0x1
addvar STORY_PROGRESS 0x1
setflag PKMNMENU
setflag PKMNMENU
goto ow_script_0x953cf2


.global ow_script_0x953cf2

ow_script_0x953cf2:
clearflag 0x896d
setvar SONG_OVERRIDE 0xffff
sound 0x64
checksound
warpmuted 0x0 0xd 0xff 0x11 0x1a
waitstate
end


.global ow_script_0x97231c

ow_script_0x97231c:
setvar 0x8000 0x1
setvar 0x8001 0x11
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8a1cc9

ow_script_0x8a1cc9:
setvar 0x8000 0x0
setvar 0x8001 0xc
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x936c1c

ow_script_0x936c1c:
setvar 0x8000 0x0
setvar 0x8001 0x2
setvar 0x8002 0xe
special 0x6
return


.global ow_moves_0x971d5d

ow_moves_0x971d5d:
	.byte FACE_DOWN
	.byte STOP


.global ow_moves_0x96eff0

ow_moves_0x96eff0:
	.byte LOOK_RIGHT
	.byte STOP


.global ow_moves_0x96ef91

ow_moves_0x96ef91:
	.byte LOOK_UP
	.byte STOP


.ifdef LANG_GER

.global str_0x971e16

str_0x971e16:
	.autostring 35 2 "Was um alles in der Welt?"


.global str_0x971d73

str_0x971d73:
	.autostring 35 2 "Mistral, PLAYER!\pEs wurde Zeit, dass wir einander begegnen."


.global str_0x971d60

str_0x971d60:
	.autostring 35 2 "Wer bist du?"


.global str_0x971c82

str_0x971c82:
	.autostring 35 2 "Mein Name ist Rubys.\pIch habe das antike Pokémon Groudon beruhigt und den Ausbruch des Volcanos verhindert.\pFolglich DOTS\nDOTS verdankt ihr mir eure Leben."

.global str_0x971c05

str_0x971c05:
	.autostring 35 2 "Unsinn!\pKein Mensch ist zu so etwas in der Lage!\pWo um alles in der Welt sind wir hier?"


.global str_0x953d08

str_0x953d08:
	.autostring 35 2 "Ein Mensch wäre dazu sicherlich nicht im Stande, ja.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWir befinden uns hier an einem Ort jenseits der Welt, die euch bekannt ist.\pDieses Reich trägt den Namen Arc.\pUm genauer zu sein, ihr befindet euch in meiner Festung, der Arc Skrim.\pDie Arc wird von Wesen, die sich Chronen nennen, bewohnt.\pWir Chronen existieren jenseits der Zeit, wie ihr sie kennt.\pFür uns sind Vergangenheit, Gegenwart und Zukunft völlig gehaltlose Begriffe.\pEs ist uns Chronen eigentlich strengstens untersagt, jemals mit eurer Welt zu interagieren DOTS"

.global str_0x9718d8

str_0x9718d8:
	.autostring 35 2 "Verstehe ich das richtig?\pDu willst uns Glauben machen, dass du eine Art Gott bist?\pUnd selbst, wenn das der Wahrheit entsprechen sollte DOTS\pWieso hast du all das getan?\pWieso sind Mistral und ich hier?"


.global str_0x9717c3

str_0x9717c3:
	.autostring 35 2 "Ihr habt viele Fragen.\pDas ist nur verständlich.\pUm euch meine Motive aber verständlich zu machen, muss ich sehr weit ausholen."


.global str_0x971424

str_0x971424:
	.autostring 35 2 "Meine Geschichte beginnt vor unvorstellbar vielen Jahren.\pEuer Universum war praktisch erst entstanden und zum ersten Mal überhaupt, würde Leben in der weiten trostlosen Kälte des Alls entstehen.\pBegeistert von diesem Ereignis, setzte ich mich über unsere Gesetze hinweg und betrat eure Welt, um selbst Zeuge dieses Augenblicks zu werden, unwissend, was ich damit in Gang setzten würde.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pMit meinem Erscheinen in eurer Welt veränderte ich den Lauf der Dinge, der für euer Universum vorgesehen war.\pIch kann es mir selbst nicht gänzlich erklären DOTS\pDOTS aber indem ich diesem Ereignis beiwohnte, brachte ich dieses erste Leben direkt auf eure Welt.\pMein Engreifen führte schließlich zur Katastrophe von Aktania, als eines der ersten Lebewesen auf einem Meteor in eure Welt gelangte.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAb diesem Zeitpunkt, gerieten die Dinge außer Kontrolle."

.global str_0x96fd7a

str_0x96fd7a:
	.autostring 35 2 "Mehr und mehr entzog sich eure Welt der Kontrolle der Chronen.\pEs enstand eine Zeitlinie, die niemals existieren sollte.\pVergeblich schickte ich euch beiden Visionen, die euch eure Rolle in all dem begreiflich machen sollten.\pIch zeigte euch die Vergangenheit, als die Wesen aus dem All auf euren Planeten kamen.\pIch ließ euch die Zukunft sehen.\pEine Welt, die völlig von Finsternis verschlungen ist DOTS"


.global str_0x96fa81

str_0x96fa81:
	.autostring 35 2 "Das heißt, dass du für diese Visionen verantwortlich warst?\pHat PLAYER sie etwa auch erlebt?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAber warum ich?\nWarum PLAYER?"

.global str_0x96f811

str_0x96f811:
	.autostring 35 2 "Das ist wohl die interessanteste aller Fragen.\pIch kann sie euch leider nicht beantworten.\pIhr beiden seid der Grund, weshalb die Chronen nicht mehr in der Lage sind, die Zeitlinie eurer Welt zu beeinflussen.\pWeil ihr existiert, können wir die Dinge nicht berichtigen."

.global str_0x96f680

str_0x96f680:
	.autostring 35 2 "Mistral und ich sind DOTS DOTS DOTS"


.global str_0x96f55c

str_0x96f55c:
	.autostring 35 2 "Ich kann euch ehrlich nicht sagen, was ihr seid.\pDeshalb sind die Chronen der Überzeugung, dass wenn man euch aus der Geschichte tilgen würde, die Dinge wieder ins Lot kämen.\pIch allerdings bin anderer Ansicht.\pIch denke nicht, dass euer Tod die Dinge wieder geraderücken kann.\pGanz im Gegenteil.\nIch vermute, dass es an euch liegt, die Zukunft, die eurer Welt droht, zu verhindern.\pHabt ihr das verstanden?\pIhr müsst den Diserakt, den Stein der Zeit, um jeden Preis beschützen.\pWenn er in die falschen Hände gerät, wird eure Welt in eine endlose Dunkelheit gestürzt DOTS"

.global str_0x96f427

str_0x96f427:
	.autostring 35 2 "Das klingt ja alles höchst interessant.\pAber ich habe keine Lust, Teil irgendeines göttlichen Dramas zu sein.\pMich interessiert nicht, was mit unserer Welt passiert.\pHörst du Rubys?\pDu vernichtest mich lieber an Ort und Stelle.\pWenn du mich zurückschickst DOTS DOTS DOTS\pDOTS werde ich da weitermachen, wo ich aufgehört habe!"


.global str_0x96ef94

str_0x96ef94:
	.autostring 35 2 "Das kann nicht dein Ernst sein, Mistral!\pHast du denn überhaupt zugehört?\pWir müssen zusammen arbeiten, wenn wir verhindern wollen, dass die Visionen, die Rubys uns geschickt hat, Realität werden!"


.global str_0x96edc1

str_0x96edc1:
	.autostring 35 2 "Schweigt, alle beide!\pIch bin nicht länger in der Lage, eure Zeitlinie zu verstehen.\pDie Zukunft eurer Welt ist DOTS DOTS DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTS sie ist ungewiss.\pNie zuvor haben wir Chronen uns in einer solchen Lage befunden.\pIhr selbst müsst entscheiden, wie ihr mit der Situation umgehen wollt.\pDOTS DOTS DOTS\nDOTS DOTS DOTS"

.global str_0x96ef26

str_0x96ef26:
	.autostring 35 2 "Ich werde euch nun wieder in eure Welt zurückschicken."


.global str_0x96ef5f

str_0x96ef5f:
	.autostring 35 2 "Hoffentlich werden wir einander nie wieder sehen DOTS"

.elseif LANG_EN

.endif
