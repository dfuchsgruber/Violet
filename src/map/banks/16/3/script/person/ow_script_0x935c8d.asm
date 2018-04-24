.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x935c8d
ow_script_0x935c8d:
trainerbattlestd 0x0 0x7b 0x0 str_0x937767 str_0x9377c1
loadpointer 0x0 str_0x9377c1
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x937767

str_0x937767:
    .string "Der Fang in einer Höhle könnte\ndurchaus besser sein...\lOb ich am Fluss mehr Glück habe?"
        
        
.global str_0x9377c1

str_0x9377c1:
    .string "Ich sollte mein Glück am Fluss\nnach Meriana City probieren."
        
        
.elseif LANG_EN

.endif
