.include "callstds.s"
.include "overworld_script.s"


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
	.autostring 35 2 "Ich werde ganz sicher mehr Pokémon in meiner Pokédex-app registrieren, als du!"
        
.elseif LANG_EN

.endif
