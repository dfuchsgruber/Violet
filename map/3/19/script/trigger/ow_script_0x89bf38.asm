.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x89bf97
ow_script_movs_0x89bf97:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x89bf9b
ow_script_movs_0x89bf9b:
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STOP


.global ow_script_0x89bf38
ow_script_0x89bf38:
lockall
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
pause 0x20
sound 0x15
applymovement 0x6 ow_script_movs_0x89bf97
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89bf76
callstd MSG
special 0x7
applymovement 0x6 ow_script_movs_0x89bf9b
waitmovement 0x0
fadesong MUS_ROUTE_1_AND_TUNNELPFAD
hidesprite 0x6
goto ow_script_0x8f6de3


.global ow_script_0x8f6de3
ow_script_0x8f6de3:
setflag ROUTE_1_RIVAL
setvar STORY_PROGRESS 0x4
end


.ifdef LANG_GER
.global str_0x89bf76

str_0x89bf76:
    .string "Wo bleibst du denn?!\nBeeilung!"
        
        
.elseif LANG_EN

.endif
