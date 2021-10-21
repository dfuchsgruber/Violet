.global compatibility_strings

.align 4
compatibility_strings:
    .word str_high
    .word str_normal
    .word str_low
    .word str_none

.ifdef LANG_GER
str_high:
    .autostring 34 2 "Die beiden scheinen sich sehr zu mögen."
str_normal:
    .autostring 34 2 "Die beiden scheinen sich zu vertragen."
str_low:
    .autostring 34 2 "Die beiden mögen sich nicht sehr."
str_none:
    .autostring 34 2 "Die beiden spielen lieber mit anderen Pokémon als miteinander."
.elseif LANG_EN
str_high:
    .autostring 34 2 "They seem to like each other"
str_normal:
    .autostring 34 2 "They get along with each other well."
str_low:
    .autostring 34 2 "They dont like each other very much."
str_none:
    .autostring 34 2 "They rather play with different Pokémon than together."
.endif
