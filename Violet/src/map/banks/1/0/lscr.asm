
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"
.include "levelscript_types.s"
.include "songs.s"
.include "person_behaviours.s"
.include "ordinals.s"

.global lscr_0x719d18
.global ow_script_silvania_forest_setmaptiles_burning_trees

lscr_0x719d18:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
	.word lsrc_setwmflag_and_movesprites
	.byte LEVELSCRIPT_TYPE_ON_LOAD
	.word lsrc_setmaptile
	.byte 0x0
lsrc_setwmflag_and_movesprites:
	setworldmapflag WM_SILVANIA_FOREST
	checkflag FLAG_SILVANIA_FOREST_BURNING
	callif EQUAL forest_burning_move_sprites
	end

forest_burning_move_sprites:
	playsong2 MUS_VIOLET_ENCOUNTER
	movesprite2 42 0x2d 0x13
	movesprite2 43 0x31 0x14
	spritebehave 42 BEHAVIOUR_FACE_UP
	spritebehave 43 BEHAVIOUR_FACE_UP
	spritebehave 36 BEHAVIOUR_LOOK_AROUND
	return


lsrc_setmaptile:
	checkflag FLAG_SILVANIA_FOREST_BURNING
	callif EQUAL ow_script_silvania_forest_setmaptiles_burning_trees
	end

ow_script_silvania_forest_setmaptiles_burning_trees:
	setmaptile 0x2c 0x10 0x38a 1
	setmaptile 0x2d 0x10 0x38b 1
	setmaptile 0x31 0x11 0x376 1
	setmaptile 0x32 0x11 0x377 1
	setmaptile 0x31 0xf 0x387 1
	setmaptile 0x2f 0xf 0x387 1
	// Across the river
	setmaptile 0x38 0xd 0x38a 1
	setmaptile 0x39 0xd 0x38b 1
	setmaptile 0x3e 0xd 0x38a 1
	setmaptile 0x3f 0xd 0x38b 1
	setmaptile 0x3e 0x10 0x38a 1
	setmaptile 0x3f 0x10 0x38b 1
	setmaptile 0x3d 0xb 0x377 1
	setmaptile 0x39 0xf 0x377 1
	setmaptile 0x3b 0x10 0x376 1
	setmaptile 0x41 0x16 0x38a 1
	setmaptile 0x42 0x16 0x38b 1
	setmaptile 0x43 0x14 0x386 1
	setmaptile 0x44 0x13 0x37d 1
	return

