.include "vars.s"

.global lscr_inferior_gym_arena

lscr_inferior_gym_arena:
	.byte 0x2
.word lscr_battle
	.byte 0x4
.word lscr_facing
	.byte 0x0

lscr_battle:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_inferior_gym_battle
	.hword 0x0

lscr_facing:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_player_face_left
	.hword 0x0
