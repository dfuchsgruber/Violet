.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_5_0_person_0

ow_script_map_5_0_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Jedes Jahr im Frühling, wenn die Bäume ihre Kirschblüten tragen, kommen zahlreiche Pokémon nach Blütenbach.\pOb die Kirschblüten sie wohl irgendwie anziehen?"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Every year during the spring, when the trees grow their cherry blossoms, many Pokémon come to Petal Creek.\pI wonder if the cherry trees kind of attract them."
.endif