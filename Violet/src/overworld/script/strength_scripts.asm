.include "overworld_script.s"
.include "specials.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"
.include "attacks.s"
.include "callstds.s"

.global ow_script_strength_boulder
.global ow_script_strength_use

ow_script_strength_boulder:
    special 0x187
    compare LASTRESULT 2
    gotoif EQUAL end_script
    checkflag STRENGTH_USED
    gotoif EQUAL strength_used
    loadpointer 0 str_could_move
    callstd MSG_KEEPOPEN
    checkflag FRBADGE_5
    gotoif NOT_EQUAL badge_needed
    checkattack ATTACK_STAERKE
    compare LASTRESULT 6
    gotoif EQUAL badge_needed
    setanimation 0 LASTRESULT
    loadpointer 0 str_ask_strength
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL badge_needed
    closeonkeypress
ow_script_strength_use:
    doanimation 0x28
    waitstate
    setflag 0x805
strength_used:
    loadpointer 0 str_strength_used
    callstd MSG_SIGN
    end


badge_needed:
    closeonkeypress
end_script:
    releaseall
    end

.ifdef LANG_GER
str_strength_used:
    .autostring 34 2 "Stärke ermöglicht es, den Felsen zu bewegen."
str_could_move:
    .autostring 34 2 "Ein Pokémon kann diesen Felsen vielleicht bewegen."
str_ask_strength:
    .autostring 34 2 "Möchtest du Stärke einsetzten?"
.elseif LANG_EN
str_strength_used:
    .autostring 34 2 "Strength makes it possible to move the boulder."
str_could_move:
    .autostring 34 2 "A Pokémon may be able to move this boulder."
str_ask_strength:
    .autostring 34 2 "Do you want to use Strength?"
.endif