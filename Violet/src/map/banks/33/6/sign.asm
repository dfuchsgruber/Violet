.include "overworld_script.s"
.include "callstds.s"

.global ow_script_blackbeard_ship_cabins_hammock

ow_script_blackbeard_ship_cabins_hammock:
    lockall
    loadpointer 0 str_healing
    callstd MSG
    call ow_script_healing_sequence
    loadpointer 0 str_healed
    callstd MSG
    end

.ifdef LANG_GER
str_healing:
    .autostring 34 2 "Die Hängematte sieht gemütlich aus.\pPLAYER gönnt sich und seinen Pokémon eine Pause."
str_healed:
    .autostring 34 2 "Die Pokémon von PLAYER sind wieder topfit!"
.elseif LANG_EN
.endif