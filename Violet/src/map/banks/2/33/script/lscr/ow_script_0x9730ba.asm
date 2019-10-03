.include "overworld_script.s"
.include "vars.s"
.include "callstds.s"
.include "movements.s"
.include "songs.s"
.include "flags.s"
.include "mugshot.s"

.global ow_script_0x9730ba

ow_script_0x9730ba:
loadpointer 0x0 str_0x971e16
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
pause 0x1
loadpointer 0x0 str_0x971d73
show_mugshot MUGSHOT_RUBYS MUGSHOT_RIGHT
pause 0x1
setvar SONG_OVERRIDE 0x0
playsong MUS_PUNKTLOCH_AND_TANIBOSCHLUSSEL_AND_ICOGNITO_KAMMERN 0x0
loadpointer 0x0 str_0x971d60
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
pause 0x1
applymovement 0x1 ow_moves_0x971d5d
waitmovement 0x0
loadpointer 0x0 str_0x971c82
show_mugshot MUGSHOT_RUBYS MUGSHOT_RIGHT
pause 0x1
loadpointer 0x0 str_0x971c05
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
loadpointer 0x0 str_0x953d08
show_mugshot MUGSHOT_RUBYS MUGSHOT_RIGHT
pause 0x1
loadpointer 0x0 str_0x9718d8
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
pause 0x1
loadpointer 0x0 str_0x9717c3
show_mugshot MUGSHOT_RUBYS MUGSHOT_RIGHT
pause 0x1
playsong MUS_SPIELHALLE_VERSION_3 0x0
fadescreen 0x1
draw_mugshot MUGSHOT_RUBYS MUGSHOT_RIGHT
loadpointer 0x0 str_0x971424
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96fd7a
callstd MSG
hide_mugshot
pause 0x1
fadesong MUS_PUNKTLOCH_AND_TANIBOSCHLUSSEL_AND_ICOGNITO_KAMMERN
fadescreen 0x0
loadpointer 0x0 str_0x96fa81
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
pause 0x1
loadpointer 0x0 str_0x96f811
show_mugshot MUGSHOT_RUBYS MUGSHOT_RIGHT
pause 0x1
loadpointer 0x0 str_0x96f680
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
pause 0x1
loadpointer 0x0 str_0x96f55c
show_mugshot MUGSHOT_RUBYS MUGSHOT_RIGHT
pause 0x1
loadpointer 0x0 str_0x96f427
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
applymovement 0xff ow_moves_0x96eff0
waitmovement 0x0
loadpointer 0x0 str_0x96ef94
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
pause 0x1
applymovement 0xff ow_moves_0x96ef91
waitmovement 0x0
draw_mugshot MUGSHOT_RUBYS MUGSHOT_RIGHT
loadpointer 0x0 str_0x96edc1
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96ef26
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96ef5f
callstd MSG
hide_mugshot
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
	.autostring 35 2 "Ein Mensch wäre dazu sicherlich nicht im Stande, ja.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWir befinden uns hier an einem Ort jenseits der Welt, die euch bekannt ist.\pDieses Reich trägt den Namen Arc.\pUm genauer zu sein, ihr befindet euch in meiner Festung, der Arc Skrim.\pDie Arc wird von Wesen, die sich Chronen nennen, bewohnt.\pWir Chronen existieren jenseits der Zeit, wie ihr sie kennt.\pFür uns sind Vergangenheit, Gegenwart und Zukunft völlig gehaltlose Begriffe."

.global str_0x9718d8

str_0x9718d8:
	.autostring 35 2 "Verstehe ich das richtig?\pDu willst uns Glauben machen, dass du eine Art Gott bist?\pUnd selbst, wenn das der Wahrheit entsprechen sollte DOTS\pWieso hast du all das getan?\pWieso sind Mistral und ich hier?"


.global str_0x9717c3

str_0x9717c3:
	.autostring 34 2 "Ihr habt viele Fragen.\pDas ist nur verständlich.\pEigentlich ist es nicht meine Absicht, euch über die Zusammenhänge ins Bild zu setzen.\pDoch sehe ich mich nun gezwungen, gegen die mir auferlegten Gesetze zu verstoßen, und euch zumindest ein wenig aufzuklären."

.global str_0x971424

str_0x971424:
	.autostring 34 2 "Die Aufgabe der Chronen ist es, dafür zu sorgen, dass die Geschichte einen Weg einschlägt, der vor langer Zeit vorgesehen wurde und dem sich eure Welt zu fügen hat.\pDoch durch gewisse Umstände ist es nun der Fall, dass eure Welt von diesem Schicksal abgekommen zu sein scheint.\pDie Folgen dieser Divergenz sind selbst den Chronen nicht völlig klar, denn der Verlauf dieser neuen Geschichte scheint nahezu im Dunkeln zu liegen.\pAls jedoch das Unglück von Aktania sich ereignete, und mit einem Meteor etwas auf eure Welt kam, das diese völlig zu vernichten im Stande ist, stand fest, dass die Dinge außer Kontrolle geraten warenDOTSDOTSDOTS"

.global str_0x96fd7a

str_0x96fd7a:
	.autostring 34 2 "Eure Zeitline bewegt sich auf eine Katastrophe vor, deren Ursache ich nicht völlig absehen kann.\pIch zeigte euch beiden bereits, auf welches Desaster sich eure Welt zu bewegt und welches schreckliche Schicksal ihr bevorsteht.\pEine Welt voller Dunkelheit, beherrscht von Wesen, die niemals mit den Menschen hätten in Kontakt kommen dürfen.\pOhne zu übertreiben, wäre dies als das Ende der Menschen und Pokémon zu bezeichnenDOTS"


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
	.autostring 35 2 "Ich kann euch ehrlich nicht sagen, was ihr seid.\pDeshalb sind die Chronen der Überzeugung, dass wenn man euch aus der Geschichte tilgen würde, die Dinge wieder ins Lot kämen.\pIch allerdings bin anderer Ansicht.\pIch denke nicht, dass euer Tod die Dinge wieder geraderücken kann.\pGanz im Gegenteil.\nIch vermute, dass es an euch liegt, die Zukunft, die eurer Welt droht, zu verhindern.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDer Zeistein, der DiseraktDOTS\pDOTS DOTS DOTS\pVielleicht ist er der Auslöser für diese Katastrophe."

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
