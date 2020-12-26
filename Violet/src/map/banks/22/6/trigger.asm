.include "overworld_script.s"
.include "callstds.s"

.global ow_script_desert_tent_trigger_bed

ow_script_desert_tent_trigger_bed:
    lockall
    applymovement 0xFF mov_fd
    waitmovement 0
    pause 16
	call ow_script_healing_sequence
    loadpointer 0 str_healed
    callstd MSG_KEEPOPEN
    setvar 0x4000 1
    releaseall
    end


.ifdef LANG_GER
str_healed:
    .autostring 34 2 "Deine Pokémon haben sich nach einer ausgiebigen Pause wieder vollständig erholt."
.elseif LANG_EN
.endif