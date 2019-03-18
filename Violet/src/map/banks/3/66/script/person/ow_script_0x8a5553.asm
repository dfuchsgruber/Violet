.include "callstds.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_0x8a5553
ow_script_0x8a5553:
loadpointer 0x0 str_0x8a679f
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a679f

str_0x8a679f:
	.autostring 35 2 "Ich werde ganz sicher mehr Pokémon in meiner Pokédex-app registrieren, als du!"
        
.elseif LANG_EN

.endif
