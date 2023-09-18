.include "overworld_script.s"
.include "callstds.s"

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Mein Vater nimmt mich oft mit hier herauf, um nach seltenen Pokémon Ausschau zu halten.\pDas ist öde!\nAlso lass und kämpfen!"
str_trainer0_defeat:
    .autostring 34 2 "Na warte, wenn das mein Vater erfährt!"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "My father often takes me up here to look for rare pokémon.\pBut that's tedious.\nSo let's battle!"
str_trainer0_defeat:
    .autostring 34 2 "Just wait until my father hears about this!"
.endif