
.global lscr_0x721670

lscr_0x721670:
	.byte 0x3
.word ow_script_0x80fdc2
	.byte 0x0


.include "overworld_script.s"

.global ow_script_0x80fdc2

ow_script_0x80fdc2:
special 0x30
end