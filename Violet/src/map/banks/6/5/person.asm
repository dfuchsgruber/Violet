.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_6_5_person_0
.global ow_script_map_6_5_person_1

ow_script_map_6_5_person_0:
lock
faceplayer
call ow_script_0x1a9429
release
end


ow_script_map_6_5_person_1:
loadpointer 0x0 str_0x811138
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x811138:
    .string "Aktania war einst eine schöne Stadt\nam Strand. Jedes Jahr hatten wir\ltausende Besucher hier, aber dann\lkam der schwarze Nebel und hat den\lganzen Strand vernebelt und die\lStadt verdunkeltDOTS "


.elseif LANG_EN

.endif