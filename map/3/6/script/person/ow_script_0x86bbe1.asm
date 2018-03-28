.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86bbe1
ow_script_0x86bbe1:
loadpointer 0x0 str_0x965ac5
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x965ac5

str_0x965ac5:
    .string "Ich komme nur wegen der schönen\nDamen, die sich hier in den\lThermen tummeln!\pHehe! Aber das erzählst du\nnatürlich niemandem, oder?"
        
        
.elseif LANG_EN

.endif
