.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_4_clouds_cave_tablet

ow_script_route_4_clouds_cave_tablet:
    loadpointer 0 str_0
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL close_str
    loadpointer 0 str_1
    callstd MSG
    end
close_str:
    releaseall
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Die Schrift auf dieser Tafel ist fast verblasstDOTS\pMöchtest du sie lesen?"
str_1:
    .autostring 34 2 "Von Osten bis Westen, von Norden bis Süden hallt der schreckliche Schrei der Bestie wider.\pWem an seinem Leben etwas liegt, der laufe!"
.elseif LANG_EN
.endif
