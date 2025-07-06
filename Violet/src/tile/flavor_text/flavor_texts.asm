.include "overworld_script.s"
.include "callstds.s"

.global ow_script_flavor_text_inside_piano

ow_script_flavor_text_inside_piano:
    loadpointer 0 str_piano
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_piano:
    .autostring 34 2 "Ein Klavier einer teuren Marke.\pEs scheint bereits länger nicht mehr gestimmt worden zu seinDOTS"

.elseif LANG_EN 
str_piano:
    .autostring 34 2 "A piano of a high-quality brand.\pIt seems to have not been tuned in a whileDOTS"
.endif