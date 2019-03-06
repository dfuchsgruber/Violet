.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x864763
ow_script_0x864763:
trainerbattlestd 0x0 0xad 0x0 str_0x8657cf str_0x86582b
loadpointer 0x0 str_0x86582b
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8657cf

str_0x8657cf:
    .string "Halt! Weiter geht es nicht für\ndich.\pJenseits dieser Höhle haben die\ngroßen Leute zu tun!"
        
        
.global str_0x86582b

str_0x86582b:
    .string "Wenn du klug bist, kehrst du um!"
        
        
.elseif LANG_EN

.endif
