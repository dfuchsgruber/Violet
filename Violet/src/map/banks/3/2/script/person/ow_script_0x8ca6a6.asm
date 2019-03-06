.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"


.global ow_script_movs_0x8ca7be
ow_script_movs_0x8ca7be:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x8ca6a6
ow_script_0x8ca6a6:
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8ca6c5
callstd MSG_FACE
special 0x7
applymovement 0x800f ow_script_movs_0x8ca7be
waitmovement 0x0
hidesprite 0x800f
end


.global ow_script_0x8c09e6
ow_script_0x8c09e6:
setvar 0x8000 0x0
setvar 0x8001 0xd
setvar 0x8002 0xf
special 0x6
return


.ifdef LANG_GER
.global str_0x8ca6c5

str_0x8ca6c5:
	.autostring 35 2 "Sehr schön, du bist also gekommen.\pIch bin von echtem Kampfgeist fasnziniert.\pVor vielen Jahrhunderten hat man in diesem Tempel den Golem-Pokémon gehuldigt.\pSeit dem Vorfall vor einiger Zeit ist von den einst beeindruckenden Kunstwerken nicht mehr viel zu sehen.\pDaher habe ich im Untergrund eine Kampfarena ausgehoben.\pDort werden wirst du mich herausfordern!"
        
.elseif LANG_EN

.endif
