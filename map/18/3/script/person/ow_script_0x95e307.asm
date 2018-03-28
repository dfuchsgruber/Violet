.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e307
ow_script_0x95e307:
trainerbattlestd 0x0 0x94 0x0 str_0x95e31f str_0x95e369
loadpointer 0x0 str_0x95e369
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95e31f

str_0x95e31f:
    .string "Das einzige, was noch heißer ist,\nals dieser Ort, wäre meine\lWenigkeit!"
        
        
.global str_0x95e369

str_0x95e369:
    .string "Wie kannst du meine Schönheit so\ndreist misachten?"
        
        
.elseif LANG_EN

.endif
