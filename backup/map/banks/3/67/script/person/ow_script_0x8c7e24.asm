.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c7e24
ow_script_0x8c7e24:
loadpointer 0x0 str_0x8c7e2e
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c7e2e

str_0x8c7e2e:
    .string "Es heißt, dass man in der Wüste\ndie Versteckte Maschine Blitz\lfinden kann.\pGlücklicherweise ist diese Höhle\nnicht dunkel."
        
        
.elseif LANG_EN

.endif
