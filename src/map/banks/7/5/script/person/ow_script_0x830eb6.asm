.include "callstds.s"
.include "flags.s"
.include "movements.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x830eef
ow_script_movs_0x830eef:
.byte LOOK_UP
.byte FACE_DOWN
.byte LOOK_LEFT
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x830eb6
ow_script_0x830eb6:
lock
faceplayer
checkflag FRBADGE_2
gotoif EQUAL ow_script_0x830ee4
loadpointer 0x0 str_0x8f078d
callstd MSG
applymovement 0x3 ow_script_movs_0x830eef
waitmovement 0x0
hidesprite 0x3
warp 0x7 0xa 0x0 0x14 0xf
release
end


.global ow_script_0x830ee4
ow_script_0x830ee4:
loadpointer 0x0 str_0x8f08c4
callstd MSG
release
end


.ifdef LANG_GER
.global str_0x8f078d

str_0x8f078d:
    .string "PLAYER, wie schön dich hier\nzu treffen. Du brauchst wohl den\lRanken-Orden, um den Zeitwald zu\lmeistern.\lAuch wenn ich ihn dir nur zu gerne\lkampflos überreichen würde, damit\ldu Team Violet vertreiben kannst,\lmuss ich die Regeln befolgen.\lFolge mir in die Arena!"
        
        
.global str_0x8f08c4

str_0x8f08c4:
    .string "Du hast unfassbar gekämpft. Team\nViolet sollte für dich kein\lProblem darstellen."
        
        
.elseif LANG_EN

.endif
