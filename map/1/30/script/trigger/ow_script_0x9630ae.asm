.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "species.s"
.include "vars.s"
.include "overworld_script.s"


.global ow_script_movs_0x801223
ow_script_movs_0x801223:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x9630a8
ow_script_movs_0x9630a8:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x9630ae
ow_script_0x9630ae:
lockall
applymovement 0xff ow_script_movs_0x801223
waitmovement 0x0
cry POKEMON_LAVADOS 0x0
fadesong 0
pause 0x40
special 0x113
applymovement 0x7f ow_script_movs_0x9630a8
waitmovement 0x0
showpokepic POKEMON_LAVADOS 0x8 0x2
loadpointer 0x0 str_0x963098
callstd MSG
hidepokepic
call ow_script_0x963073
call ow_script_0x963073
call ow_script_0x963082
call ow_script_0x963082
call ow_script_0x963082
call ow_script_0x963082
call ow_script_0x963082
cry POKEMON_LAVADOS 0x0
showpokepic POKEMON_LAVADOS 0x8 0x2
loadpointer 0x0 str_0x96305b
callstd MSG
hidepokepic
pause 0x40
sound 0x80
applymovement 0x9 ow_script_movs_0x8e1959
waitmovement 0x0
special 0x114
setvar 0x8004 0x92
special 0x163
hidesprite 0x9
addvar ASCHHAIN_LAVADOS_VAR 0x1
playsong MUS_LAVA 0x0
releaseall
end


.global ow_script_0x963082
ow_script_0x963082:
sound 0x96
applymovement 0x7f ow_script_movs_0x94be33
applymovement 0x9 ow_script_movs_0x94be33
waitmovement 0x0
return


.global ow_script_0x963073
ow_script_0x963073:
sound 0x96
applymovement 0x9 ow_script_movs_0x94be33
waitmovement 0x0
return


.ifdef LANG_GER
.global str_0x963098

str_0x963098:
    .string "Grueeeeh! ..."
        
        
.global str_0x96305b

str_0x96305b:
    .string "Gyahhh! Gyaaaaahhhhh!"
        
        
.elseif LANG_EN

.endif
