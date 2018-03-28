.include "flags.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x802a66
ow_script_0x802a66:
checkflag MERIANA_CITY_HIKER_BLOCKING_ROUTE_4
callif EQUAL ow_script_0x935de6
end


.global ow_script_0x935de6
ow_script_0x935de6:
setmaptile 0x4a 0xe 0x2fc 0x1
return
