.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x719d01
ow_script_0x719d01:
trainerbattlestd 0x0 0x4d 0x0 str_0x71a83d str_0x71a860
loadpointer 0x0 str_0x71a860
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x71a83d

str_0x71a83d:
    .string "In dieser Höhle ist es so dunkel."
        
        
.global str_0x71a860

str_0x71a860:
    .string "Man hat mit gesagt, mit Vm Blitz\nkann man in Höhlen besser sehen..."
        
        
.elseif LANG_EN

.endif
