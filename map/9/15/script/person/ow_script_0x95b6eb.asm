.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95b6eb
ow_script_0x95b6eb:
loadpointer 0x0 str_0x95c6e9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95c6e9

str_0x95c6e9:
    .string "Unser Traum war es immer,\nFossilien zum Leben erwecken zu\lkönnen.\pNun, da wir dazu im Stande sind,\nwo führt uns unser Weg hin?"
        
        
.elseif LANG_EN

.endif
