.include "vars.s"

.global lscr_0x726a18

lscr_0x726a18:
	.byte 0x4
.word lscr_0x726a1e
	.byte 0x0


.align 4
.global lscr_0x726a1e

lscr_0x726a1e:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_0x94566b
	.hword 0x0
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_0x94566b
.global ow_script_0x94567d

ow_script_0x94566b:
special2 0x800d 0x49
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x94567d
end


ow_script_0x94567d:
movesprite 0x1 0xc 0xc
end