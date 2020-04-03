.include "vars.s"

.global lscr_0x719d18

lscr_0x719d18:
	.byte 0x2
.word lscr_0x719cc3
	.byte 0x3
.word ow_script_0x87bd10
	.byte 0x4
.word lscr_0x719d28
	.byte 0x0


.align 4
.global lscr_0x719cc3

lscr_0x719cc3:
	.hword STORY_PROGRESS, 0x1b
	.word ow_script_0x8f2223
	.hword 0x0




.align 4
.global lscr_0x719d28

lscr_0x719d28:
	.hword STORY_PROGRESS, 0x1b
	.word ow_script_0x81c506
	.hword 0x0
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"

.global ow_script_0x8f21ef
.global ow_script_0x81c506
.global ow_script_0x8f2223
.global ow_script_0x87bd10

ow_script_0x81c506:
spriteinvisible 0xff 0x1 0x0
end


ow_script_0x87bd10:
setworldmapflag WM_SILVANIA_FOREST
end


ow_script_movs_0x8f2219:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8ed0b2:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8ed0b5:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x8ed0af:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8ed069:
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8ecfe7:
.byte SAY_QUESTION
.byte STOP


ow_script_0x8f2223:
pause 0x48
loadpointer 0x0 str_0x8ed116
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x1 ow_script_movs_0x8f2219
waitmovement 0x0
loadpointer 0x0 str_0x8ed0b8
show_mugshot MUGSHOT_FAUN_YOUNG MUGSHOT_RIGHT
applymovement 0x1 ow_script_movs_0x8ed0b2
waitmovement 0x0
pause 0x20
applymovement 0x1 ow_script_movs_0x8ed0b5
waitmovement 0x0
pause 0x20
applymovement 0x1 ow_script_movs_0x8ed0af
waitmovement 0x0
loadpointer 0x0 str_0x8ed06c
show_mugshot MUGSHOT_FAUN_YOUNG MUGSHOT_RIGHT
cry POKEMON_CELEBI 0x0
waitcry
sound 0x15
applymovement 0x1 ow_script_movs_0x8ed069
waitmovement 0x0
loadpointer 0x0 str_0x8ed049
show_mugshot MUGSHOT_FAUN_YOUNG MUGSHOT_RIGHT
cry POKEMON_CELEBI 0x0
waitcry
pause 0x18
cry POKEMON_CELEBI 0x0
waitcry
fadescreen 0x3
showsprite 0x2
fadescreen 0x2
cry POKEMON_CELEBI 0x0
waitcry
sound 0x15
applymovement 0x1 ow_script_movs_0x8ed069
waitmovement 0x0
loadpointer 0x0 str_0x8ed00c
show_mugshot MUGSHOT_FAUN_YOUNG MUGSHOT_RIGHT
cry POKEMON_CELEBI 0x0
loadpointer 0x0 str_0x8ecfea
show_mugshot MUGSHOT_CELEBI MUGSHOT_LEFT
waitcry
sound 0x15
applymovement 0x1 ow_script_movs_0x8ecfe7
waitmovement 0x0
loadpointer 0x0 str_0x8ecfd8
show_mugshot MUGSHOT_FAUN_YOUNG MUGSHOT_RIGHT
cry POKEMON_CELEBI 0x0
loadpointer 0x0 str_0x8ecfb4
show_mugshot MUGSHOT_CELEBI MUGSHOT_LEFT
waitcry
loadpointer 0x0 str_0x8ecf8a
show_mugshot MUGSHOT_FAUN_YOUNG MUGSHOT_RIGHT
cry POKEMON_CELEBI 0x0
loadpointer 0x0 str_0x8ecdda
show_mugshot MUGSHOT_CELEBI MUGSHOT_LEFT
waitcry
cry POKEMON_CELEBI 0x0
waitcry
pause 0x38
loadpointer 0x0 str_0x8ecd2c
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
subvar STORY_PROGRESS 0x1
setflag SILVANIA_FOREST_FLASHBACK_DONE
goto ow_script_0x8f21ef


ow_script_0x8f21ef:
fadescreen 0x1
writebytetooffset 0x0 0x2036e28
warpmuted 0x7 0x8 0xff 0x6 0x6
releaseall
end


.ifdef LANG_GER

str_0x8ed116:
	.autostring 35 2 "Vor einer halben Ewigkeit, als ich selbst noch ein Anfänger war, machte ich mich auf, nach dem legendären Pokémon Celebi zu suchen.\pIch hatte gehört, dass es im Silvania-Wald leben soll DOTS"


str_0x8ed0b8:
    .autostring 35 2 "Das muss der Schrein sein, der dem Pokémon Celebi geweiht ist DOTS"



str_0x8ed06c:
    .autostring 35 2 "Nur von Celebi selbst fehlt scheinbar jede Spur DOTS"



str_0x8ed049:
    .autostring 35 2 "Was war das für ein Geräusch?"



str_0x8ed00c:
    .autostring 35 2 "Das DOTS DOTS DOTS\pDOTS muss das legendäre Pokémon Celebi sein!"



str_0x8ecfea:
    .autostring 35 2 "DOTS Lieber Mensch!\pDOTS Hör mir zu, lieber Mensch!"



str_0x8ecfd8:
    .autostring 35 2 "Eine Stimme?"



str_0x8ecfb4:
    .autostring 35 2 "DOTS Lieber Mensch!\pDOTS Ich will dich warnen! DOTS DOTS DOTS"



str_0x8ecf8a:
    .autostring 35 2 "Spricht es DOTS über Telepathie mit mir?"



str_0x8ecdda:
	.autostring 35 2 "DOTS Sie haben den Fluss der Zeit verändert DOTS\pUnd jetzt gerät alles außer Kontrolle DOTS\pDie Wesen aus dem All DOTS\pSie haben sie zu uns hergeführt!\pUnd durch die Kraft der Zeit werden sie uns finden DOTS DOTS DOTS\pDOTS Lieber Mensch!\pDein Herz ist rein.\nDu musst das verhindern.\pDas Herz der Zeit muss vor ihnen beschützt werden DOTS DOTS DOTS\pIch werde es den drei mächtigsten Wächtern anvertrauen DOTS\pUnd das Schicksal Thetos in deine Hände legen, lieber Mensch DOTS"



str_0x8ecd2c:
	.autostring 35 2 "Bis heute geben mir die Worte des Pokémons Celebi Rätsel auf.\pDoch mir wird immer mehr klar, dass es sich bei der Gefahr, vor der es mich warnen wollte, vielleicht um Team Violet handeln könnte DOTS"


.elseif LANG_EN

.endif