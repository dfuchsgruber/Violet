
.global lscr_0x16b390

lscr_0x16b390:
	.byte 0x3
.word ow_script_0x16b39b
	.byte 0x5
.word ow_script_init_union_room
	.byte 0x0




.include "overworld_script.s"
.include "healingplaces.s"

.global ow_script_0x16b39b
ow_script_0x16b39b:
sethealingplace HEALINGPLACE_ORINA_CITY
end