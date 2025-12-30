.include "vars.s"
.include "overworld_script.s"
.include "callstds.s"
.include "specials.s"

.global ow_script_route_3_house_bed_heal

ow_script_route_3_house_bed_heal:
    lockall
    loadpointer 0 str_sleep
    callstd MSG
    fadescreen 1
    special SPECIAL_HEAL
    fanfare 0x100
    waitfanfare
    fadescreen 0
    loadpointer 0 str_slept
    callstd MSG
    setvar (VAR_TMP_BASE + 1), 1
    end

.ifdef LANG_GER
str_sleep:
    .autostring 34 2 "Dieses Bett sieht warm und kuschelig aus.\pEine Pause wäre willkommenDOTS"
str_slept:
    .autostring 34 2 "Deine Pokémon und du fühlen sich ausgeschlafen und energetisch!"
.elseif LANG_EN
.endif

