.include "vars.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "movements.s"

.global ow_script_map_18_3_trigger_0
.global ow_script_0x95e6bd
.global ow_script_0x95e771

ow_script_map_18_3_trigger_0:
lockall
clearflag PKMNMENU
setvar LASTTALKED 0xb
showsprite 0xb
setvar 0x8004 0xb
special 0x1b
waitmovement 0x0
faceplayer
draw_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
loadpointer 0x0 str_0x95e7e5
callstd MSG_KEEPOPEN
goto ow_script_0x95e6bd


ow_script_0x95e6bd:
loadpointer 0x0 str_0x95eb33
callstd MSG_KEEPOPEN
multichoice 8 8 0 1
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x95e771
hide_mugshot
sound 0x15
applymovement 0x800f ow_script_movs_0x8a1cc6
waitmovement 0x0
loadpointer 0x0 str_0x95e710
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
setvar 0x8004 0xb
setvar 0x8005 0x1d
setvar 0x8006 0x17
special 0x24
waitmovement 0x0
hidesprite 0x800f
addvar STORY_PROGRESS 0x1
releaseall
end


ow_script_0x95e771:
loadpointer 0x0 str_0x95e77f
callstd MSG_KEEPOPEN
goto ow_script_0x95e6bd

ow_script_movs_0x8a1cc6:
.byte SAY_SMILE
.byte STOP

.ifdef LANG_GER

str_0x95e7e5:
	.autostring 35 2 "Hallo PLAYER!\pÜberrascht, mich hier zu treffen?\pDu musst wissen, dass ich hier aufgewachsen bin.\pAußerdem bin ich DOTS DOTS DOTS\pDOTS DOTS DOTS naja, wie soll ich sagen DOTS\pDOTS Arenaleiter von Inferior.\pDas bleibt aber unter uns, ja?\pWenn die Menschen wüssten, dass ein Arenaleiter heimlich Teil der Revolutionsbewegung ist DOTS\pAber dein Timing ist perfekt, PLAYER.\pMan erzählt sich, dass eine Division von Team Violet in der Nähe des Volcano ihr Unwesen treibt.\pAuch ein Kommandant soll unter ihnen gewesen sein.\pMit den Kommandanten von Team Violet ist nicht zu spaßen DOTS\pAlso wäre es toll, wenn du mir vielleicht etwas unter die Arme greifen könntest.\pImmerhin sollst du ja schon einmal einen Kommandanten von Team Violet besiegt haben.\pNoch dazu kommt DOTS DOTS DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pSagen wir einfach, dass ich nicht alleine gegen diese Divison vorgehen will."



str_0x95eb33:
    .autostring 35 2 "Was sagst du dazu?\nHilfst du mir?"



str_0x95e710:
    .autostring 35 2 "Ich wusste, dass ich auf dich zählen kann, PLAYER.\pWir treffen uns in Inferior, westlich von hier!"



str_0x95e77f:
    .autostring 35 2 "Hey! Du kannst mich nicht einfach so im Stich lassen, PLAYER!\pWir sind doch Freunde, oder nicht?"


.elseif LANG_EN

.endif