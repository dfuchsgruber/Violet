.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "vars.s"
.include "person_behaviours.s"
.include "levelscript_types.s"

.global kaskada_teahouse_levelscripts

kaskada_teahouse_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
	.word lsrc_movesprites
	.byte 0x0

lsrc_movesprites:
	checkflag FLAG_KASKADA_TEAHOUSE_BLACK_MARKET_UNLOCKED
	callif EQUAL move_sprites
	end

move_sprites:
	movesprite2 1 0x8 0x3
	spritebehave 1 BEHAVIOUR_FACE_RIGHT
	return
