.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x94566b
ow_script_0x94566b:
special2 0x800d 0x49
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x94567d
end


.global ow_script_0x94567d
ow_script_0x94567d:
movesprite 0x1 0xc 0xc
end
