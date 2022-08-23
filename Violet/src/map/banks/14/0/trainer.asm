.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_10_trainer_8

ow_script_route_10_trainer_8:
    trainerbattlestd 0 0xe0 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_after
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Hier oben hat man grenzenlose Freiheit!\pDas ist es, was die Leute sagen!\pWie frei fühlst du dich hier?"
str_trainer0_defeat:
    .autostring 34 2 "Grenzenlose Freiheit bedeutet wohl auch, dass man verlieren kann."
str_trainer0_after:
    .autostring 34 2 "Freiheit, die hat man hier oben tatsächlich.\pMan ist frei, so zu kämpfen, wie man es möchte.\pGewinnen, verlierenDOTS\pWas spielt das für eine Rolle?"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "Over the clouds, they say, the freedom must be endless.\pI could not agree more."
str_trainer0_defeat:
    .autostring 34 2 "Infinite freedom also means you can lose."
.endif