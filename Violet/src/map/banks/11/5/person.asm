.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_cave_person_0

ow_script_route_2_cave_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Es ist lästig, eine Höhle zu erkunden, wenn es so dunkel istDOTS\pWenn doch nur eines meiner Pokémon die VM Blitz beherrschen würdeDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "It really is annoying to explore a cave if it's dark like thisDOTS\pIf only one of my pokémon knew the HM FlashDOTS"
.endif