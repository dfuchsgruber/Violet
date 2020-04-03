.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"

.global ow_script_map_1_82_trigger_0

ow_script_movs_0x9665c2:
.byte FACE_DOWN
.byte STOP


ow_script_map_1_82_trigger_0:
applymovement 0xff ow_script_movs_0x9665c2
waitmovement 0x0
lockall
clearflag PKMNMENU
showsprite 0x2
setvar LASTTALKED 0x2
setvar 0x8004 0x2
special 0x1b
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x9665c5
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT

call ow_script_healing_sequence

loadpointer 0x0 str_0x96659a
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
setvar 0x8004 0x2
setvar 0x8005 0x1c
setvar 0x8006 0x5
special 0x24
waitmovement 0x0
sound 0x9
hidesprite 0x800f
checksound
addvar STORY_PROGRESS 0x1
releaseall
end


.ifdef LANG_GER

str_0x9665c5:
	.autostring 35 2 "Du hast wirklich ein ordentliches Tempo drauf!\pPuh!\nBevor wir uns aber auf zum Gipfel machen, sollten wir unseren Pokémon eine kurze Verschnaufpause gönnen.\pWir können es uns nicht leisten, nicht mit ganzer Kraft dort anzutreten."


str_0x96659a:
    .autostring 35 2 "Auf jetzt!\nWir dürfen keine Zeit mehr verlieren."


.elseif LANG_EN

.endif