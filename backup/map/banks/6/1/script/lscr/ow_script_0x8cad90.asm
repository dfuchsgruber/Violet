.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_movs_0x8cadd5
ow_script_movs_0x8cadd5:
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8cadcd
ow_script_movs_0x8cadcd:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8caddd
ow_script_movs_0x8caddd:
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8cad90
ow_script_0x8cad90:
loadpointer 0x0 str_0x8cade0
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT MSG_FACE
applymovement 0xff ow_script_movs_0x8cadd5
applymovement 0x1 ow_script_movs_0x8cadcd
waitmovement 0x0
hidesprite 0x1
applymovement 0xff ow_script_movs_0x8caddd
waitmovement 0x0
goto ow_script_0x8cae78


.global ow_script_0x8cae78
ow_script_0x8cae78:
clearflag AKTANIA_LESTER_REGI_ROOM
setvar STORY_PROGRESS 0x13
warp 0x6 0x9 0x0 0x0 0x0
end


.ifdef LANG_GER
.global str_0x8cade0

str_0x8cade0:
    .string "Dieser Ort ist heilig. Niemand\ndarf ihn je betreten, der nicht\lseinen Eid gegenüber den Wächtern\lgeschworen hat.\pDOTS\nBeeilen wir uns."
        
        
.elseif LANG_EN

.endif
