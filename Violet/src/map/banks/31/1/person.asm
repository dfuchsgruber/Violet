.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ardeal_person_3

ow_script_ardeal_person_3:    
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "In diesem Saal darf nur der Lord selbst dinnieren.\pNicht einmal die Überreste darf ein anderer bekommen."

.elseif LANG_EN
str_0:
    .autostring 34 2 "In this hall only the lord himself may dine.\pNot even the leftovers may be given to someone else."

.endif 