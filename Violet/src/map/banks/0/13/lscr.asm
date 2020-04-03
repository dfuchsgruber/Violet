.include "vars.s"

.global lscr_0x84020c

lscr_0x84020c:
	.byte 0x2
.word lscr_0x840218
	.byte 0x4
.word lscr_0x84e9b8
	.byte 0x0


.align 4
.global lscr_0x840218

lscr_0x840218:
	.hword STORY_PROGRESS, 0x36
	.word ow_script_0x94772b
	.hword 0x0


.align 4
.global lscr_0x84e9b8

lscr_0x84e9b8:
	.hword STORY_PROGRESS, 0x36
	.word ow_script_0x812c75
	.hword 0x0
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "overworld_script.s"

.global ow_script_0x812c75
.global ow_script_0x8f6d1b
.global ow_script_0x94772b

ow_script_0x812c75:
spriteface 0xff 0x2
end


ow_script_movs_0x94794b:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x947948:
.byte FACE_DOWN
.byte STOP


ow_script_0x94772b:
lockall
loadpointer 0x0 str_0x947967
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
pause 0x1
applymovement 0xc ow_script_movs_0x94794b
waitmovement 0x0
loadpointer 0x0 str_0x9479c7
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
pause 0x1
setvar 0x8004 0xb
setvar 0x8005 0x11
setvar 0x8006 0x22
special 0x24
applymovement 0xc ow_script_movs_0x947948
hidesprite 0xb
draw_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
loadpointer 0x0 str_0x94794f
callstd MSG_KEEPOPEN
waitmovement 0
hide_mugshot
loadpointer 0x0 str_0x9477c9
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
setvar 0x8004 0xc
setvar 0x8005 0x11
setvar 0x8006 0x22
special 0x24
waitmovement 0x0
hidesprite 0xc
addvar STORY_PROGRESS 0x1
setvar SONG_OVERRIDE 0x0
//call ow_script_0x8f6d1b
playsong MUS_KONEX_KLUB 0x0
releaseall
end


ow_script_0x8f6d1b:
pause 0x40
fadescreen 0x1
fadesong 0
loadpointer 0x0 str_0x8fb998
callstd MSG
warpmuted 0x3 0x4b 0xff 0x2 0x2
end


.ifdef LANG_GER

str_0x947967:
	.autostring 35 2 "Die Beben haben nachgelassen DOTS\pUnd DOTS DOTS DOTS\pGroudon ist verschwunden?\nAber wie?"



str_0x9479c7:
	.autostring 35 2 "Nenn es Glück im Unglück, Igva.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWie es scheint, hat sich die Lage beruhigt.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pUnd ich bin nun entschlossener denn je.\pIch sehe meinen Weg ganz deutlich vor mir.\pDOTS DOTS DOTS"



str_0x94794f:
    .autostring 35 2 "Warte, Mistral!"



str_0x9477c9:
	.autostring 35 2 "DOTS DOTS DOTS\pIch verstehe das alles überhaupt nicht?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAber offenbar sind wir mit einem blauen Auge davon gekommen.\pPLAYER!\nIch muss dir für deine Hilfe danken!\pDein Sieg über Mistral hat vielleicht unser aller Leben gerettet.\pUnd ich habe natürlich auch nicht vergessen, weshalb du überhaupt nach Inferior gekommen bist.\pWenn du auf einen Arenakampf aus bist, werde ich dich liebend gerne erwarten!\pPLAYER!\nIch bin schon ganz aufgeregt, gegen dich zu kämpfen!\pDu weißt, wo du mich findest!"



str_0x8fb998:
	.autostring 35 2 "Dies ist das Ende der Alpha-Version von Pokémon Violet.\pDu wirst nun in eine Höhle auf Route 2 gebracht.\pDort MUSST du dein Spiel speichern, wann immer du es auf die nächste Version übertragen möchtest.\pSichere den Spielstand, in dem Raum, in dem sich NICHT das Relaxo, welches den Entwickler des Spiels verkörpert, befindet.\pSicher das Spiel in dem Raum in dem sich KEINE Person findet.\pIch hoffe, du hattest Spaß beim Spielen und wirst dein Abenteuer fortsetzten, wenn die nächste Version erscheint!"


.elseif LANG_EN

.endif