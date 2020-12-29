.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "vars.s"
.include "person_behaviours.s"
.include "levelscript_types.s"

.global tafelberg_levelscripts

tafelberg_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
	.word lsrc_setwmflag_and_movesprites
	.byte 0x0

lsrc_setwmflag_and_movesprites:
	setworldmapflag WM_KUSTENBERG
	compare STORY_PROGRESS 33
	callif EQUAL move_sprites
	end

move_sprites:
	movesprite2 42 0x21 0x24
	spritebehave 42 BEHAVIOUR_FACE_RIGHT
	movesprite2 9 0x22 0x24
	spritebehave 9 BEHAVIOUR_FACE_DOWN
	movesprite2 43 0x23 0x24
	spritebehave 43 BEHAVIOUR_FACE_DOWN
	return
