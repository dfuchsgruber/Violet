.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x92eac0
.global ow_script_map_3_4_trigger_0

ow_script_movs_0x8c90b9:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8c909d:
.byte STEP_DOWN
.byte STOP


ow_script_map_3_4_trigger_0:
lockall
pause 0x40
sound 0x15
applymovement 0x3 ow_script_movs_0x8c90b9
waitmovement 0x0
loadpointer 0x0 str_0x8c90a0
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
applymovement 0x3 ow_script_movs_0x8c909d
waitmovement 0x0
loadpointer 0x0 str_0x8c8fec
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
goto ow_script_0x92eac0


ow_script_movs_0x8c8fc0:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_0x92eac0:
applymovement 0x3 ow_script_movs_0x8c8fc0
waitmovement 0x0
hidesprite 0x3
hidesprite 0x57
setflag KASKADA_FELIX_DONE
setflag KASKADA_IGVA
addvar STORY_PROGRESS 0x1
end



.ifdef LANG_GER

str_0x8c90a0:
    .autostring 35 2 "PLAYER, da bist du ja."



str_0x8c8fec:
	.autostring 35 2 "Hier herrscht das reinste Chaos.\pDie Polizei hat die Stadt abgeriegelt.\pIrgendwo hier muss sich der Anführer der Revolution rumtreiben.\pWir sollten uns auf die Suche machen!"

.elseif LANG_EN

.endif