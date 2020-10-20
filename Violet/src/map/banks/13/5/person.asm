.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_9_horizontal_clouds_person_0
.global ow_script_route_9_horizontal_clouds_person_1
.global ow_script_route_9_horizontal_clouds_person_2

ow_script_route_9_horizontal_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_9_horizontal_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_9_horizontal_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Es ist sicher, auf solidem Untergrund von der Wolke abzusteigen.\pAllerdings solltest du dich nicht zu Fuß auf eine Wolke wagenDOTS"
str_1:
    .autostring 34 2 "Als Kind habe ich einmal Lucius auf einer Wolke reiten sehen.\pVon da an wusste ich, dass ich ein Wolkenreiter werden möchte."
str_2:
    .autostring 34 2 "Glaubst du, wir Menschen wären besser dran, wenn wir alle ganz frei hier über den Wolken leben könnten?"

.elseif LANG_EN
str_0:
    .autostring 34 2 "It is safe to dismount the cloud on solid ground.\pOn a cloud however you better don't try to go afootDOTS"
str_1:
    .autostring 34 2 "As a child I once saw Lucius riding a cloud.\pFrom then on I knew that I wanted to be a cloud rider."
str_2:
    .autostring 34 2 "Do you think that we people would have it better if we lived freely above the clouds?"

.endif