.include "callstds.s"
.include "overworld_script.s"
.include "movements.s"
.include "ordinals.s"

.global ow_script_0x86ef25
.global ow_script_map_3_75_person_0


ow_script_movs_0x947b30:
.byte STEP_LEFT
.byte STOP


ow_script_map_3_75_person_0:
special 0x44
comparevars 0x8004 0x8005
gotoif EQUAL ow_script_0x86ef25
loadpointer 0 str_updated
callstd MSG_FACE
applymovement 0x800f ow_script_movs_0x947b30
waitmovement 0x0
releaseall
end


ow_script_0x86ef25:
loadpointer 0x0 str_0x971e6a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x971e6a:
    .string "Hallo, ich bin Wodka, der\nEntwickler des Spiels.\pWenn du deinen Spielstand auf eine\nneue Version deines Spiels bringen\lwillst, musst du dafür folgendes\ltun:\pZuerst erstellst du eine ROM mit\nder aktuellsten Version von\lPokémon Violet. Dabei folgst du\lden Anweisungen in der README.txt\lDatei.\pWichtig ist, dass du eine\nungepatchte deutsche Feuerrot ROM\lbenutzt.\pDann ersetzt du die derzeitig\nbenutze ROM mit der neu gepatchten\lund sprichst mich wieder an."

str_updated:
	.autostring 35 2 "Dein Spiel wurde erfolgreich auf die Version BUFFER_1 übertragen."

.elseif LANG_EN

.endif