.include "vars.s"

.global lscr_0x721034

lscr_0x721034:
	.byte 0x3
.word ow_script_0x80146d
	.byte 0x2
.word lscr_0x7208f4
	.byte 0x1
.word ow_script_0x802a66
	.byte 0x0




.align 4
.global lscr_0x7208f4

lscr_0x7208f4:
	.hword STORY_PROGRESS, 0xa
	.word ow_script_0x886ce6
	.hword 0x0


.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x935de6
.global ow_script_0x802a66
.global ow_script_0x886ce6
.global ow_script_0x80146d
.global ow_script_0x88abb8

ow_script_0x80146d:
setworldmapflag WM_MERIANA_CITY
end


ow_script_0x802a66:
checkflag MERIANA_CITY_HIKER_BLOCKING_ROUTE_4
callif EQUAL ow_script_0x935de6
end


ow_script_0x935de6:
setmaptile 0x4a 0xe 0x2fc 0x1
return


ow_script_0x886ce6:
goto ow_script_0x88abb8


ow_script_movs_0x8a136f:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_NORTH_EAST
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8a133b:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_NORTH_EAST

.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT

.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte STOP


ow_script_movs_0x888e47:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8a13a1:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


ow_script_0x88abb8:
lockall
loadpointer 0x0 str_0x886d49
callstd MSG
playsong MUS_KOMMT_MIT_SPIELER_WIRD_HERUMGEFUHRT 0x0
applymovement 0x2 ow_script_movs_0x8a136f
applymovement 0xff ow_script_movs_0x8a133b
waitmovement 0x0
loadpointer 0x0 str_0x888a45
callstd MSG
applymovement 0x2 ow_script_movs_0x888e47
waitmovement 0x0
fadesong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY
loadpointer 0x0 str_0x888cd2
callstd MSG
applymovement 0x2 ow_script_movs_0x8a13a1
waitmovement 0x0
hidesprite 0x2
setvar STORY_PROGRESS 0xb
releaseall
end


.ifdef LANG_GER

str_0x886d49:
    .string "Einen letzten Ort solltest du als\nTrainer noch unbedingt kennen.\lFolge mir einfach wie bisher!"



str_0x888a45:
    .string "Das ist eine Pokémon-Arena. In\nganz Theto gibt es acht davon.\lJede von ihnen hat einen\lArenaleiter, der nicht nur sehr\lstark ist, sondern sich auch auf\lden Kampf mit einem bestimmten\lPokémon-Typen versteht. Der\lArenaleiter dieser Stadt, Manus,\lbeispielsweise ist auf\lKampf-Pokémon spezialsiert. Soviel\lich weiß, ist er jedoch außer Haus\lund repariert den Durchgang im\lWassertunnel, der kürzlich bei\leinem Erdbeben eingestürzt ist.\lBesiegst du einen Arenaleiter, so\lerhältst du einen Arena-Orden.\lSammle alle acht Orden ein, und du\ldarfst dich zu den besten\lTrainern überhaupt zählen. Jeder\lTrainer sollte das Ziel haben,\lalle Orden einzusammeln."



str_0x888cd2:
    .string "Diese Orte solltest du als\nPokémon-Trainer auf jeden Fall\lkennen und auch nutzen. Du\lbrauchst mir für meine Hilfe nicht\lzu danken, ich habe gerne Anteil\lam Glück anderer. Viel Glück auf\ldeiner Reise, ich habe bereits\lzuvor gemerkt, dass du das gewisse\lEtwas hast, das ein\lPokémon-Trainer braucht."


.elseif LANG_EN

.endif