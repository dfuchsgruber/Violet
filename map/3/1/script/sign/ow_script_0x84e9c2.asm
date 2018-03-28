.include "overworld_script.s"

.include "std.s"

.global ow_script_0x84e9c2
ow_script_0x84e9c2:
checkflag MERIANA_CITY_HIKER_BLOCKING_ROUTE_4
gotoif EQUAL ow_script_0x84ea05
loadpointer 0x0 str_0x84e9d5
callstd MSG_SIGN
end


.global ow_script_0x84ea05
ow_script_0x84ea05:
loadpointer 0x0 str_0x84ea0f
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x84e9d5

str_0x84e9d5:
    .string "Die Arena ist einem Kampf-Dojo\nnachempfunden."
        
        
.global str_0x84ea0f

str_0x84ea0f:
    .string "Arenaleiter Manus außer Haus,\nArena geschlossen."
        
        
.elseif LANG_EN

.endif
