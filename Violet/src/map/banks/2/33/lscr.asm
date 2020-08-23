.include "vars.s"
.include "map_connections.s"


.global lscr_0x71cbcc

lscr_0x71cbcc:
	.byte 0x2
.word lscr_0x7193ce
	.byte 0x4
.word lscr_0x71cb9f
	.byte 0x0


.align 4
.global lscr_0x7193ce

lscr_0x7193ce:
	.hword STORY_PROGRESS, 0x35
	.word ow_script_0x9730ba
	.hword 0x0


.align 4
.global lscr_0x71cb9f

lscr_0x71cb9f:
	.hword STORY_PROGRESS, 0x35
	.word ow_script_0x811aa5
	.hword 0xffff
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"

.global ow_script_0x9730ba
.global ow_script_0x811aa5
.global ow_script_0x953cf2

ow_script_0x811aa5:
spriteface 0xff 0x2
end




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



ow_script_0x953cf2:
clearflag 0x896d
setvar SONG_OVERRIDE 0xffff
sound 0x64
checksound
warpmuted 0x0 0xd 0xff 0x11 0x1a
waitstate
end



ow_moves_0x971d5d:
	.byte FACE_DOWN
	.byte STOP



ow_moves_0x96eff0:
	.byte LOOK_RIGHT
	.byte STOP



ow_moves_0x96ef91:
	.byte LOOK_UP
	.byte STOP


.ifdef LANG_GER


str_0x971e16:
	.autostring 35 2 "Was um alles in der Welt?"



str_0x971d73:
	.autostring 35 2 "Mistral, PLAYER!\pEs wurde Zeit, dass wir einander begegnen."



str_0x971d60:
	.autostring 35 2 "Wer bist du?"



str_0x971c82:
	.autostring 35 2 "Mein Name ist Rubys.\pIch habe das antike Pokémon Groudon beruhigt und den Ausbruch des Volcanos verhindert.\pFolglich DOTS\nDOTS verdankt ihr mir eure Leben."


str_0x971c05:
	.autostring 35 2 "Unsinn!\pKein Mensch ist zu so etwas in der Lage!\pWo um alles in der Welt sind wir hier?"



str_0x953d08:
	.autostring 34 2 "Ganz richtig, ein gewöhnlicher im Mensch wäre dazu sicherlich nicht im Stande, ja.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWir befinden uns hier an einem Ort jenseits eurer Welt, der Arc.\pDies hier ist meine Festung, die Arc Scrim."


str_0x9718d8:
	.autostring 34 2 "Was ist das hier für ein Ort?\pUnd wieso hast du uns hierher gebracht?\pWer bist du überhaupt?"



str_0x9717c3:
	.autostring 34 2 "Ihr habt viele Fragen.\pDas ist nur verständlich.\pUnd auch, wenn es mir verboten wurde, mich euch zu zeigen, geschweigedenn euch mit den Geheimnissen der Arc vertraut zu machenDOTS\pDOTSbin ich der Auffassung, dass es an der Zeit ist, euch über gewisse Ereignisse ins Bild zu setzten."



str_0x971424:
	.autostring 34 2 "Mein Name ist Rubys, und ich gehöre dem Volk der Chronen an.\pWir Chronen sind der imensen Aufgabe verschrieben, das Schicksal der Welt zu lenken.\pAus dem Verborgenen helfen wir dem Weltgeschehen auf seine vorbestimmte Bahn.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pUnd über Jahrhunderte hinweg wurden wir unserer Pflicht gerecht und wie Welt entwickelte sich exakt nach unserer Vorsehung.\pDoch vor kurzer Zeit änderten die Dinge sich drastisch.\pAus irgendeinem Grund begannen das Schicksal der Welt von unseren Plänen zu divergieren.\pIn zunehmendem Maße verloren wir Chronen die Kontrolle über das Weltgeschehen.\pSchließlich erreichte ein Meteor eure Welt und brachte eine Macht mit sich, die in der Lage ist, das Leben, wie ihr es kennt, für alle Zeit auszulöschen."


str_0x96fd7a:
	.autostring 34 2 "Wie die Dinge stehen, scheint es, als würde eure Welt sich auf eine Katastrophe zubewegen.\pVergeblich habe ich versucht, euch beide dieser Tatsache bewusst werden zu lassen.\pDie Visionen, die ich euch gezeigt habe, sollten euch sowohl Vergangenheit als auch die bevorstehende Zukunft offenbaren.\pDas Wesen, das in dem Meteorit schlummerte, welcher vor eingigen Jahren bei Bruchfels eingeschlagen ist, das Wesen, das beinahe die ganze Stadt vernichtet hätteDOTS\pDieses Wesen wird eure Welt in einen Ort verwandeln, an dem weder Mensch noch Pokémon existieren dürfen.\pDie beiden Visionen sollten euch diese nahende Katastrophe zeigen und euch warnen."


str_0x96fa81:
	.autostring 35 2 "Das heißt, dass du für diese Visionen verantwortlich warst?\pHat PLAYER sie etwa auch erlebt?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAber warum ich?\nWarum PLAYER?"


str_0x96f811:
	.autostring 35 2 "Das ist wohl die interessanteste aller Fragen.\pIch kann sie euch leider nicht beantworten.\pIhr beiden seid der Grund, weshalb die Chronen nicht mehr in der Lage sind, die Zeitlinie eurer Welt zu beeinflussen.\pAllein weil ihr existiert, können wir die Dinge nicht berichtigen."


str_0x96f680:
	.autostring 35 2 "Mistral und ich sind DOTS DOTS DOTS"



str_0x96f55c:
	.autostring 35 2 "Ich kann euch ehrlich nicht sagen, was ihr seid.\pDeshalb sind die Chronen der Überzeugung, dass wenn man euch aus der Geschichte tilgen würde, die Dinge wieder ins Lot kämen.\pIch allerdings bin anderer Ansicht.\pIch denke nicht, dass euer Tod die Dinge wieder geraderücken kann.\pGanz im Gegenteil.\nIch vermute, dass es an euch liegt, die Zukunft, die eurer Welt droht, zu verhindern.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDer Zeistein, der DiseraktDOTS\pDOTS DOTS DOTS\pVielleicht ist er der Auslöser für diese Katastrophe."


str_0x96f427:
	.autostring 35 2 "Das klingt ja alles höchst interessant.\pAber ich habe keine Lust, Teil irgendeines göttlichen Dramas zu sein.\pSelbst wenn ich dieser aberwitzigen Geschichte auch nur einen Funken Bedeutung beimessen würdeDOTS\pMich interessiert nicht, was mit unserer Welt passiert.\pHörst du Rubys?\pDu vernichtest mich lieber an Ort und Stelle.\pWenn du mich zurückschickst DOTS DOTS DOTS\pDOTS werde ich da weitermachen, wo ich aufgehört habe!"



str_0x96ef94:
	.autostring 35 2 "Das kann nicht dein Ernst sein, Mistral!\pHast du denn überhaupt zugehört?\pWir müssen zusammen arbeiten, wenn wir verhindern wollen, dass die Visionen, die Rubys uns geschickt hat, Realität werden!"



str_0x96edc1:
	.autostring 34 2 "Schweigt!\nAlle beide!\pEs stürzt mich beinahe in tiefste Verzweiflung, die Kontrolle über die Dinge in solchem Ausmaß verloren zu haben.\pEs ist ungewiss, welcher Weg in die Katastrophe führt und welche Handlungen sie verhindern.\pIch habe euch gegen den Willen der anderen Chronen hergeholt, damit ihr versteht, was auf dem Spiel steht.\pIch bin, wie ich bereits sagte, der festen Überzeugung, dass es an euch beiden liegt, die bevorstehende Zukunft zu verändern."


str_0x96ef26:
	.autostring 35 2 "Ich werde euch nun wieder in eure Welt zurückschicken."


str_0x96ef5f:
	.autostring 35 2 "Hoffentlich werden wir einander nie wieder sehen DOTS"

.elseif LANG_EN

.endif