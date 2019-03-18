.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_movs_0x899c63
ow_script_movs_0x899c63:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x899c67
ow_script_movs_0x899c67:
.byte LOOK_UP
.byte STOP


.global ow_script_0x899c42
ow_script_0x899c42:
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
sound 0x15
applymovement 0x1 ow_script_movs_0x899c63
applymovement 0xff ow_script_movs_0x899c67
waitmovement 0x0
goto ow_script_0x89c06b


.global ow_script_movs_0x89bfe7
ow_script_movs_0x89bfe7:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


.global ow_script_0x89c06b
ow_script_0x89c06b:
loadpointer 0x0 str_0x89bfed
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0x1 ow_script_movs_0x89bfe7
waitmovement 0x0
sound 0x9
hidesprite 0x1
checksound
fadesong MUS_TRAINERSCHOOL
setflag TRAINERSCHOOL_RIVAL
setvar STORY_PROGRESS 0x5
end


.ifdef LANG_GER
.global str_0x89bfed

str_0x89bfed:
    .string "Na los! Die Schule hat längst\nangefangen. Faun wird uns Feuer\lunterm Hintern machen, wenn wir\luns nicht bald blicken lassen."
        
        
.elseif LANG_EN

.endif
