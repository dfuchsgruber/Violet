.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x81112e
ow_script_0x81112e:
loadpointer 0x0 str_0x811138
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x811138

str_0x811138:
    .string "Aktania war einst eine schöne Stadt\nam Strand. Jedes Jahr hatten wir\ltausende Besucher hier, aber dann\lkam der schwarze Nebel und hat den\lganzen Strand vernebelt und die\lStadt verdunkelt... "
        
        
.elseif LANG_EN

.endif
