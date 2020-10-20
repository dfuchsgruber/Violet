.include "vars.s"

.global lscr_0x7194d8

lscr_0x7194d8:
	.byte 0x2
.word lscr_0x719852
	.byte 0x0


.align 4
.global lscr_0x719852

lscr_0x719852:
	.hword STORY_PROGRESS, 0x21
	.word ow_script_0x8c82da
	.hword 0x0
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "overworld_script.s"

.global ow_script_0x8c82da

ow_script_movs_0x8c8300:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


ow_script_0x8c82da:
lockall
pause 0x28
loadpointer 0x0 str_0x8c80e4
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
applymovement 0x2 ow_script_movs_0x8c8300
waitmovement 0x0
hidesprite 0x2
addvar STORY_PROGRESS 0x1
set_intern_bank 0x10 0x10
loadbytefrompointer 0x12 0x10121012
set_intern_bank 0xfe 0x6b
end


.ifdef LANG_GER

str_0x8c80e4:
	.autostring 35 2 "Sehr gut, du hast hergefunden, PLAYER!\pWo wir uns hier befinden?\pDas hier ist das dunkle Geheimnis von Kaskada.\pEin geheimer Markt im Untergrund, genauer gesagt der größte und berüchtigste in ganz Theto.\pEr liegt direkt unterhalb Kaskadas, sodass sogar Schiffe anlegen können.\pWas hier gehandelt wird?\pIllegale Objekte, Falschgeld, ja sogar mit Pokémon wird hier gehandelt.\pEs ist ein ganz und gar hässlicher Ort und das direkt vor den Augen der Top Vier.\pLass mich dich herumführen."

.elseif LANG_EN

.endif