
.include "overworld_script.s"
.include "levelscript_types.s"
.include "flags.s"
.include "ordinals.s"

.global levelscript_antike_ruine_regirock

levelscript_antike_ruine_regirock:
	.byte LEVELSCRIPT_TYPE_ON_LOAD
	.word cave
	.byte 0x0

cave:
	checkflag FLAG_REGIROCK_PUZZLE_SOLVED
	callif EQUAL ow_script_field_move_golem_regirock_open_cave
	end
