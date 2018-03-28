.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a5553
ow_script_0x8a5553:
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a679f
callstd MSG_FACE
special 0x7
end


.ifdef LANG_GER
.global str_0x8a679f

str_0x8a679f:
    .string "Ich frage mich, was welche Pokémon\nich mir als erstes fangen werde!\lBestimmt werde ich mehr Pokémon im\lPokedex registrieren, als du!"
        
        
.elseif LANG_EN

.endif
