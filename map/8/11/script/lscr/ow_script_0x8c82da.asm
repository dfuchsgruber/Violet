.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8c8300
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


.global ow_script_0x8c82da
ow_script_0x8c82da:
lockall
pause 0x28
call ow_script_0x92f097
loadpointer 0x0 str_0x8c80e4
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8c8300
waitmovement 0x0
hidesprite 0x2
addvar STORY_PROGRESS 0x1
set_intern_bank 0x10 0x10
loadbytefrompointer 0x12 0x10121012
set_intern_bank 0xfe 0x6b
end


.ifdef LANG_GER
.global str_0x8c80e4

str_0x8c80e4:
    .string "Sehr gut, du hast\nhergefunden.\pWo wir uns hier befinden?\nDas hier ist das dunkle Geheimnis\lKaskadas, die Schattenseite des\lSystems, dem wir unterworfen sind.\lEs ist ein geheimer Markt im\lUntergrund, der größte und\lberüchtigste des Kontinents.\lEr liegt direkt unterhalb\lKaskadas, sodass sogar Schiffe\lhier anlegen können.\lWas gehandelt wird?\lVerbotene Gegenstände, Falschgeld\lund sogar versklavte Pokémon...\lEs ist ein trauriger Ort, das\lhässliche Gesicht Thetos.\lKomm mit, ich führe dich herum."
        
        
.elseif LANG_EN

.endif
