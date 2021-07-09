.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"
.include "pathfinding.s"

.global ow_script_power_plant_inside_person_0
.global ow_script_power_plant_inside_person_1
.global ow_script_power_plant_inside_person_2
.global ow_script_power_plant_inside_person_3
.global ow_script_power_plant_inside_person_4
.global ow_script_power_plant_inside_person_5
.global ow_script_power_plant_inside_person_6

ow_script_power_plant_inside_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_power_plant_inside_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_power_plant_inside_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_power_plant_inside_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_power_plant_inside_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_power_plant_inside_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_power_plant_inside_person_6:
    checkflag FLAG_POWER_PLANT_SURF_QUEST_DONE
    gotoif 1 quest_done
    lockall
    faceplayer
    loadpointer 0 str_wingull_0
    callstd MSG
    pause 16
    sound 0x15
    applymovement LASTTALKED mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_wingull_1
    callstd MSG
    npc_move_to LASTTALKED 0x25 0x9
    applymovement LASTTALKED mov_fu
    waitmovement 0
    pause 32
    sound 0x15
    applymovement 21 mov_fd
    waitmovement 0
    applymovement 21 mov_exclam
    waitmovement 0
    checksound
    npc_move_to 21 0x25 0x8
    pause 16
    applymovement LASTTALKED mov_5d
    applymovement 21 mov_5d
    waitmovement 0
    hidesprite LASTTALKED
    hidesprite 21
    clearflag (FLAG_POWER_PLANT_WINGULL_OUTSIDE | 0x8000) // Make Wingull appear outside
    releaseall
    end

quest_done:
    loadpointer 0 str_6
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hier im Kraftwerk erzeugen wir den Strom für die gesamte Region.\pUnd dafür verwenden wir außerdem nur Sonnenlicht.\pNachhaltigkeit steht für uns hier an erster Stelle."
str_1:
    .autostring 34 2 "Die Solarzellen, die wir draußen einsetzen, wurden von der Laz. Corp. entwickelt.\pSelbst bei schlechtem Wetter machen sie einen großen Teil der Sonnenergie nutzbar."
str_2:
    .autostring 34 2 "Wenn man in diesem Kraftwerk beschäftig ist, steht man quasi immer unter Spannung.\pDas muss einem schon Spaß machen, sonst muss man sich schnell eine andere Beschäftigung suchen!"
str_3:
    .autostring 34 2 "Elektro-Pokémon lieben das Kraftwerk.\pViele meiner Kollegen bringen ihre Pokémon mit an den Arbeitsplatz.\pIch finde das ehrlichgesagt aber ziemlich unprofessionell."
str_4:
    .autostring 34 2 "Seitdem ich mein Pokémon mit zur Arbeit nehme, fühle ich mich viel besser.\pSchon erstaunlich, wie viel einem die eigenen Pokémon geben." 
str_5:
    .autostring 34 2 "Ich bin der Leiter dieses Kraftwerks.\pWeil wir die gesamte Region mit Strom versorgen, ist das eine sehr große Verantwortung.\pAber ich bin auch sehr stolz auf das, was wir hier im Kraftwerk leisten."
str_6:
    .autostring 34 2 "Ich vermisse es ja schon, dass mir das Wingull nicht mehr auf Schritt und Tritt folgtDOTS\pAber ich bin natürlich froh darüber, dass es jetzt wieder bei seinem Besitzer ist."
str_wingull_0:
    .autostring 34 2 "Ich hatte schon lange nicht mehr so einen Spaß bei der Arbeit!\pDieses Wingull hier ist mir einfach ins Kraftwerk gefolgt.\pSeitdem weicht es nicht von meiner Seite.\pDas macht mich richtig fröhlich!"
str_wingull_1:
    .autostring 34 2 "Wie bitte?\pDieses Wingull ist seinem Besitzer einfach entlaufen?\pDas ist ja fürchterlich.\pEr muss sich große Sorgen um sein Pokémon machen.\pDOTSTEXT_DELAY_LONGDOTSTEXT_DELAY_LONGDOTSTEXT_DELAY_LONG\pNa, wenn das so ist, werde ich ihm sein Pokémon natürlich unverzüglich wieder zurückbringen.\pWie schade, dass es nicht länger bei mir bleiben kannDOTS"
.elseif LANG_EN
.endif