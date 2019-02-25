.include "flags.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8ff26e
ow_script_movs_0x8ff26e:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8ff96a
ow_script_movs_0x8ff96a:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8ff0da
ow_script_movs_0x8ff0da:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8ff001
ow_script_0x8ff001:
lockall
clearflag PKMNMENU
showsprite 0x12
getplayerpos 0x8004 0x8005
compare 0x8005 0x5
callif EQUAL ow_script_0x8ff96d
applymovement 0x12 ow_script_movs_0x8ff26e
waitmovement 0x0
applymovement 0xff ow_script_movs_0x8ff96a
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8ff6f3
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x9454f8
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x94591f
callstd MSG_KEEPOPEN
special 0x7
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
copyvar 0x8004 LASTRESULT
compare 0x8004 0x0
callif EQUAL ow_script_0x8ff277
compare 0x8004 0x1
callif EQUAL ow_script_0x8ff296
loadpointer 0x0 str_0x945a65
callstd MSG
special 0x7
pause 0x28
call ow_script_0x89e1fc
loadpointer 0x0 str_0x945bc8
callstd MSG
special 0x7
compare 0x8005 0x5
callif EQUAL ow_script_0x8ff0e5
compare 0x8005 0x4
callif EQUAL ow_script_0x8ff0f1
applymovement 0x12 ow_script_movs_0x8ff0da
waitmovement 0x0
hidesprite 0x12
addvar STORY_PROGRESS 0x1
releaseall
end

.align 4
choice:
    .word str_felsige_oednis_choice_0, 0
    .word str_felsige_oednis_choice_1, 0


.global ow_script_movs_0x8ff979
ow_script_movs_0x8ff979:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8ff0f1
ow_script_0x8ff0f1:
applymovement 0x12 ow_script_movs_0x8ff979
waitmovement 0x0
return


.global ow_script_movs_0x8ff0fd
ow_script_movs_0x8ff0fd:
.byte STEP_UP
.byte STOP


.global ow_script_0x8ff0e5
ow_script_0x8ff0e5:
applymovement 0x12 ow_script_movs_0x8ff0fd
waitmovement 0x0
return


.global ow_script_0x8ff296
ow_script_0x8ff296:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x945da0
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x945daa
callstd MSG_KEEPOPEN
return


.global ow_script_0x8ff277
ow_script_0x8ff277:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x945c7d
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x945d2b
callstd MSG_KEEPOPEN
return


.global ow_script_0x8ff96d
ow_script_0x8ff96d:
applymovement 0x12 ow_script_movs_0x8ff979
waitmovement 0x0
return


.ifdef LANG_GER
.global str_0x8ff6f3

str_0x8ff6f3:
	.autostring 35 2 "PLAYER!\nWas für ein Zufall, dass wir uns hier begegnen.\pIch irre schon seit einiger Zeit in dieser Höhle umher.\pWenn nur eines meiner Pokémon die Versteckte Maschine Blitz beherrschen würde, käme ich vermutlich besser zurecht.\pBist du auch unterwegs nach Kaskada, um gegen die Revolutionsbewegung zu kämpfen?\pGerüchten zufolge hält sich dort ihr Anführer Albus auf.\pOpi ist vermutlich auch schon auf dem Weg dorthin."
        
.global str_0x9454f8

str_0x9454f8:
    .autostring 35 2 "Faun hat mich und die Arenaleiterin von Silvania damit beauftragt, Team Violet im Silvania-Wald zu bekämpfen.\pEr wollte sich der Revolutionäre selbst annehmen."
        
        
.global str_0x94591f

str_0x94591f:
    .autostring 35 2 "Ich verstehe!\nDann ist dir das wohl gelungen?\pDOTS DOTS DOTS\pDiese Team Violet Rüpel sind nicht zu unterschätzen, denke ich DOTS\pAber die Revolutionsbewegung bedroht den Frieden der Region.\pWenn es ihnen gelingt, die Top Vier zu stürzen DOTS\pWer beschützt dann die Menschen in Theto?\pWollen wir in Kaskada nicht gemeinsam gegen diese Fanatiker kämpfen?"
        
        
.global str_felsige_oednis_choice_0

str_felsige_oednis_choice_0:
    .string "Revolution bekämpfen"
        
        
.global str_felsige_oednis_choice_1

str_felsige_oednis_choice_1:
    .string "Revolution verteidigen"
        
        
.global str_0x945a65

str_0x945a65:
	.autostring 35 2 "DOTS DOTS DOTS\pÜbrigens, hast du zufällig Blaise getroffen?\pIch mache mir wirklich Sorgen um ihn.\pEr ist so vom Hass auf seinen Vater zerfressen, dass ich ihm alles zutrauen würde.\pAber es sind genau Menschen wie Blaise, die die Hilfe von Freunden am Dringendsten brauchen."
        
        
.global str_0x945bc8

str_0x945bc8:
    .autostring 35 2 "Wie auch immer DOTS\pEs ist wahrscheinlich am Klügsten, wir treffen uns in Kaskada und unterstützen dann Opi beim Kampf gegen den Revolutionsführer.\pLass mich nicht all zu lange warten, PLAYER!"
        
        
.global str_0x945da0

str_0x945da0:
    .autostring 35 2 "DOTS DOTS DOTS"
        
        
.global str_0x945daa

str_0x945daa:
    .autostring 35 2 "Willst du damit etwa sagen, dass du auf der Seite dieser Spinner stehst, PLAYER?\pIhre Ziele mögen sich ja zunächst ganz sinnvoll anhören DOTS\pAber überleg doch einmal!\pGäbe es die Top Vier nicht, hätten Organisation wie Team Violet Theto schon längst erobert.\pSicherlich ist nicht alles an diesem System perfekt, DOTS\pDOTS aber ist der Frieden, den die Top Vier uns bringen, das alles nicht irgendwo auch wert?\pDOTS DOTS DOTS\nDOTS DOTS DOTS"

        
.global str_0x945c7d

str_0x945c7d:
	.autostring 35 2 "Die Revolutionsbewegung bring uns vor allem Chaos.\pDeshalb muss sie gestoppt werden!"
        
.global str_0x945d2b

str_0x945d2b:
    .autostring 35 2 "Es freut micht, dass du auch so denkst!\pDas wird Opi sicher stolz machen, dass zwei seiner Schützlinge für seine Sache kämpfen!"
        
.elseif LANG_EN

.endif
