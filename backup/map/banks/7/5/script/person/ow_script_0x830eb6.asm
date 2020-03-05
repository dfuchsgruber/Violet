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
loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8f078d
callstd MSG
special 0xF
applymovement 0x3 ow_script_movs_0x830eef
waitmovement 0x0
hidesprite 0x3
warp 0x7 0xa 0x0 0x14 0xf
release
end


.global ow_script_0x830ee4
ow_script_0x830ee4:
loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8f08c4
callstd MSG
special 0xF
release
end


.ifdef LANG_GER

str_mia:
	.string "Mia"

.global str_0x8f078d

str_0x8f078d:
	.autostring 35 2 "PLAYER.\nDa bist du ja.\pKommen wir gleich zur Sache.\pAuch wenn einiges auf dem Spiel steht, werde ich dir den Wald-Orden nicht kampflos überreichen.\pLass uns in die Kampfarena gehen DOTS"

.global str_0x8f08c4

str_0x8f08c4:
    .autostring 35 2 "Faun hat dich wirklich ausgezeichnet ausgebildet.\pDas muss ich wirklich eingestehen."
        
        
.elseif LANG_EN

.endif
