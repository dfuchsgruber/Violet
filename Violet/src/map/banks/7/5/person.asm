
.include "movements.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_map_7_5_trainer_2
.global ow_script_0x830ee4
.global ow_script_map_7_5_trainer_0
.global ow_script_map_7_5_trainer_3
.global ow_script_map_7_5_trainer_1
.global ow_script_map_7_5_trainer_4
.global ow_script_silvania_gym_referee

ow_script_silvania_gym_referee:
    checkflag FRBADGE_2
    gotoif EQUAL gym_beaten
    loadpointer 0 str_silvania_gym_referee
    callstd MSG_FACE
    end
gym_beaten:
    loadpointer 0 str_beaten
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_beaten:
    .autostring 34 2 "Wahnsinn!\nDu hast Rosalie tatsächlich besiegt.\pIch hab dir das natürlich die ganze Zeit über zugetrautDOTS"
.elseif LANG_EN
.endif

ow_script_map_7_5_trainer_0:
trainerbattlestd 0x0 0x3f 0x0 str_0x81aff5 str_0x81b06e
loadpointer 0x0 str_0x81b06e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81aff5:
    .string "Rosalie legt großen Wert auf\nNatürlichkeit. Deswegen ist in der\lArena auch alles aus natürlichen\lRohstoffen hergestellt."



str_0x81b06e:
    .string "Sogar die Wände sind aus Holz aus\ndem Kranzwald."


.elseif LANG_EN

.endif


ow_script_map_7_5_trainer_4:
trainerbattlestd 0x0 0x3e 0x0 str_0x81b0bb str_0x81b0f6
loadpointer 0x0 str_0x81b0f6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81b0bb:
    .string "Pflanzen-Pokémon sind stark.\nDeswegen trainiere ich sie."



str_0x81b0f6:
    .string "Pflanzen-Pokémon sind sehr\nstark, auch wenn ich verloren habe."


.elseif LANG_EN

.endif


ow_script_map_7_5_trainer_3:
trainerbattlestd 0x0 0x3d 0x0 str_0x81b151 str_0x81b1b1
loadpointer 0x0 str_0x81b1b1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81b151:
    .string "Ich liebe diese Arena! Der Geruch\nvon frischen Planzen lässt mich auf\lWolke sieben schweben."



str_0x81b1b1:
    .string "Ahh! Dieser Duft!\nWas? Nein ich bin nicht verrückt!"


.elseif LANG_EN

.endif


ow_script_map_7_5_trainer_2:
trainerbattlestd 0x0 0x3a 0x0 str_0x81b250 str_0x81b289
loadpointer 0x0 str_0x81b289
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81b250:
    .string "An den Hecken hier wachsen manchmal\nsogar rote Beeren!"



str_0x81b289:
    .string "Erzähl es nicht Rosalie, aber manchmal\nesse ich diese Beeren, wenn ich\lhungrig werde."


.elseif LANG_EN

.endif


ow_script_movs_0x830eef:
.byte LOOK_UP
.byte FACE_DOWN
.byte LOOK_LEFT
.byte LOOK_RIGHT
.byte STOP


ow_script_map_7_5_trainer_1:
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
	.string "Rosalie"


str_0x8f078d:
	.autostring 35 2 "PLAYER.\nDa bist du ja.\pKommen wir gleich zur Sache.\pAuch wenn einiges auf dem Spiel steht, werde ich dir den Wald-Orden nicht kampflos überreichen.\pLass uns in die Kampfarena gehen DOTS"


str_0x8f08c4:
    .autostring 35 2 "Faun hat dich wirklich ausgezeichnet ausgebildet.\pDas muss ich wirklich eingestehen."


.elseif LANG_EN

.endif