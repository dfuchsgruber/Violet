.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_6_clouds_trainer_0
.global ow_script_route_6_clouds_trainer_1

ow_script_route_6_clouds_trainer_0:
    trainerbattlestd 0 0x11a 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_route_6_clouds_trainer_1:
    trainerbattlestd 0 0x11b 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Wir Pokémon-Ranger patroullieren sogar auf dem Wolken.\pDamit leisten wir weitaus mehr, als die Polizei von Theto."
str_trainer0_defeat:
    .autostring 34 2 "Du bist recht stark.\pHast du darüber nachgedacht, ein Ranger zu werden?"
str_trainer1_challange:
    .autostring 34 2 "Weiter westlich wird die Luft sehr unangehm, wegen der Asche, die aus dem Vulcano aufsteigt.\pIch würde mich fernhalten!"
str_trainer1_defeat:
    .autostring 34 2 "Mein Husten muss mich überwältigt habenDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "We pokémon rangers do our duty even on the clouds.\pThis way we do way more than the police of Theto."
str_trainer0_defeat:
    .autostring 34 2 "You are pretty strong.\pDid you ever consider becoming a ranger?"
str_trainer1_challange:
    .autostring 34 2 "Further west the air becomes very bad because of the ash that rises from the Vulcano.\pI would keep some distance!"
str_trainer1_defeat:
    .autostring 34 2 "I must have been overtaken by my coughingDOTS"
.endif