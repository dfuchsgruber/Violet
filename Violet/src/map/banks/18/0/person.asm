.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_6_clouds_person_0
.global ow_script_route_6_clouds_person_1
.global ow_script_route_6_clouds_person_2

ow_script_route_6_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_6_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_6_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Die Luft hier ist zwar kühler, als am Boden, aber mir immer noch viel zu heiß!"
str_1:
    .autostring 34 2 "Ich bin zu schwer für meine WolkeDOTS\pWie soll ich denn jetzt zum Boden zurück kommen?"
str_2:
    .autostring 34 2 "Anstatt den Vulcano zu besteigen, werde ich einfach die Wolken nutzen, um auf seinen Gipfel zu kommen!\pOb das nicht Betrug ist?\pDOTS DOTS DOTS\pKümmere dich um deine Angelegenheiten!"

.elseif LANG_EN
str_0:
    .autostring 34 2 "The air up here is cooler than on the ground, but for me it still is way too hot!"
str_1:
    .autostring 34 2 "I am too heavy for my cloudDOTS\pHow am I supposed to get back to the ground now?"
str_2:
    .autostring 34 2 "Instead of climbing the Vulcano I will use the clouds to reach its summit.\pIf that isn't cheating?\pDOTS DOTS DOTS\pMind your own buisness!"
.endif