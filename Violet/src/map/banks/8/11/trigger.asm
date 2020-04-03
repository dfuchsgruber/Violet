.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x93395a
.global ow_script_map_8_11_trigger_0
.global ow_script_0x93154e
.global ow_script_map_8_11_trigger_1

ow_script_map_8_11_trigger_0:
lockall
showsprite 0xc
setvar 0x8004 0xc
special 0x1b
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x93144c
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
setvar 0x8005 0x1b
setvar 0x8006 0x2b
special 0x24
goto ow_script_0x93154e


ow_script_0x93154e:
waitmovement 0x0
hidesprite 0xC
addvar STORY_PROGRESS 0x1
end


.ifdef LANG_GER

str_0x93144c:
	.autostring 34 2 "Wenn ich es mir recht überlege DOTS\pVielleicht solltest du diesen Ort auf eigene Faust erkunden.\pSo kannst du dir besser selbst ein Bild von den Zuständen in Theto machen.\pKomm einfach zu mir, wenn du dich etwas umgesehen hast.\pAber versuche, nicht zu sehr aufzufallen.\pDie Menschen hierDOTS\nDOTS DOTS DOTS\pSei einfach auf der Hut!"

.elseif LANG_EN

.endif


ow_script_movs_0x9339f0:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_movs_0x933904:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x931fc2:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x931fc5:
.byte STEP_UP
.byte STOP


ow_script_map_8_11_trigger_1:
lockall
fadesong MUS_PIRATE
special 0x113
applymovement 0x7f ow_script_movs_0x9339f0
waitmovement 0x0

loadpointer 0 str_pirat
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x93386b
callstd MSG
special 0xF

loadpointer 0 str_pirat
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x9337e5
callstd MSG
special 0xF
showsprite 0x1a
pause 0x18

loadpointer 0 str_pirat
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x933908
callstd MSG
special 0xF

sound 0x15
applymovement 0x18 ow_script_movs_0x933904
applymovement 0x19 ow_script_movs_0x933904
waitmovement 0x0

loadpointer 0 str_pirat
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x9338d3
callstd MSG
special 0xF

applymovement 0x1a ow_script_movs_0x931fc2
applymovement 0x18 ow_script_movs_0x931fc5
applymovement 0x19 ow_script_movs_0x931fc5
pause 0x38
goto ow_script_0x93395a


ow_script_movs_0x933b99:
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


ow_script_movs_0x9339f6:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


ow_script_0x93395a:
hidesprite 0x18
hidesprite 0x19
hidesprite 0x1a
applymovement 0x2 ow_script_movs_0x933b99
waitmovement 0x0
hidesprite 0x2
applymovement 0x7f ow_script_movs_0x9339f6
waitmovement 0x0
special 0x114
addvar STORY_PROGRESS 0x1
fadesong MUS_BLACK_MARKET
releaseall
end


.ifdef LANG_GER

str_pirat:
	.string "Pirat"


str_0x93386b:
	.autostring 34 2 "Ich habe mich noch nie so lebendig gefühlt in meinem ganzen Leben.\pAuf Blackbeards Schiff anzuheuern, war die beste Entscheidung meines Lebens."



str_0x9337e5:
	.autostring 34 2 "Ein Beutefeldzug und schon Pirat durch und durch, was?\pLass es dir ja nicht zu gut gehen, wir haben noch einiges vor.\pKapitän Blackbeard plant, die Expidition von Professor Tann zu karpern.\pDas wird sicher ein Spaß!"


str_0x933908:
	.autostring 34 2 "Ahoi, Männer!\pWir stehen ich See!\pWir sind hier fertig."



str_0x9338d3:
    .autostring 34 2 "Aye! Wir haben verstanden!\pAlle Mann an Board!"


.elseif LANG_EN

.endif