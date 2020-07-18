
.global lscr_0x16a999

lscr_0x16a999:
	.byte 0x3
.word ow_script_0x16a9a4
	.byte 0x5
.word ow_script_init_union_room
	.byte 0x0




.include "overworld_script.s"
.include "healingplaces.s"

.global ow_script_0x16a9a4
ow_script_0x16a9a4:
sethealingplace HEALINGPLACE_SILVANIA_CITY
end