.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_movs_0x8ca7be
ow_script_movs_0x8ca7be:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x8ca6a6
ow_script_0x8ca6a6:
loadpointer 0x0 str_0x8ca6c5
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT MSG_FACE
applymovement 0x800f ow_script_movs_0x8ca7be
waitmovement 0x0
hidesprite 0x800f
end


.ifdef LANG_GER
.global str_0x8ca6c5

str_0x8ca6c5:
	.autostring 35 2 "Sehr schön, du bist also gekommen.\pIch bin von echtem Kampfgeist fasnziniert.\pVor vielen Jahrhunderten hat man in diesem Tempel den Golem-Pokémon gehuldigt.\pSeit dem Vorfall vor einiger Zeit ist von den einst beeindruckenden Kunstwerken nicht mehr viel zu sehen.\pDaher habe ich im Untergrund eine Kampfarena ausgehoben.\pDort werden wirst du mich herausfordern!"
        
.elseif LANG_EN

.endif
