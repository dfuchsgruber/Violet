.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8c90b9
ow_script_movs_0x8c90b9:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8c909d
ow_script_movs_0x8c909d:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8f149d
ow_script_0x8f149d:
lockall
pause 0x40
sound 0x15
applymovement 0x3 ow_script_movs_0x8c90b9
waitmovement 0x0
compare KARMA_VALUE 0x7fff
gotoif HIGHER ow_script_0x8c8fc8
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8c90a0
callstd MSG
special 0x7
applymovement 0x3 ow_script_movs_0x8c909d
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8c8fec
callstd MSG
special 0x7
goto ow_script_0x92eac0


.global ow_script_movs_0x8c8fc0
ow_script_movs_0x8c8fc0:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x92eac0
ow_script_0x92eac0:
applymovement 0x3 ow_script_movs_0x8c8fc0
waitmovement 0x0
hidesprite 0x3
hidesprite 0x57
setflag KASKADA_FELIX_DONE
setflag KASKADA_IGVA
addvar STORY_PROGRESS 0x1
end


.global ow_script_0x8c8fc8
ow_script_0x8c8fc8:
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8c8fde
callstd MSG
special 0x7
goto ow_script_0x92eac0

.global str_0x8c90a0

str_0x8c90a0:
    .string "PLAYER, da bist du ja."
        
        
.global str_0x8c8fec

str_0x8c8fec:
    .string "Hier herrscht das reinste Chaos!\nRevolutionäre und Polizisten\lbesetzen die Stadt. Sie liefern\lsich einen erbitterten Kampf. Wir\lsollten nach Opi suchen, und ihn\lunterstützen."
        
        
.global str_0x8c8fde

str_0x8c8fde:
    .string "... ... ..."
        
        