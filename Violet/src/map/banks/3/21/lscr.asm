
.include "overworld_script.s"
.include "levelscript_types.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"

.global levelscript_felsige_oednis

levelscript_felsige_oednis:
	.byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
	.word fata_morgana
	.byte 0x0

fata_morgana:
	.hword AKTANIA_FLASHBACK_LSCR_PLAYER_INVISIBLE, 0x0
	.word ow_script_fata_morgana
	.hword 0x0
ow_script_fata_morgana:
	callasm fata_morgana_update_blocks_dont_redraw
	end
