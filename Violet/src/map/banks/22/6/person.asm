.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "mugshot.s"

.global ow_script_desert_tent_tann
.global ow_script_desert_tent_elise
.global ow_script_desert_tent_assistant
.global ow_script_desert_tent_person_0
.global ow_script_desert_tent_person_1
.global ow_script_desert_tent_person_2

ow_script_desert_tent_tann:
    loadpointer 0 str_0
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT message_type=MSG_FACE
    end
ow_script_desert_tent_elise:
    loadpointer 0 str_1
	show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG_FACE
    end
ow_script_desert_tent_assistant:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_desert_tent_person_0:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_desert_tent_person_1:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_desert_tent_person_2:
    loadpointer 0 str_5
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Na, wenn das mal nicht PLAYER ist!\pWie schön, dich hier zu sehen.\pWir haben hier eine wirklich spannende Expedition gestartet.\pDu kannst dich, wenn du von deinem Abenteuer eine kleine Pause brauchst, gerne in unser Bett legen und etwas durchschnaufen."
str_1:
    .autostring 34 2 "Professor Tann glaubt, dass sich in dieser Wüste Fossilien befinden.\pEs gibt zwar nur wenige Anhaltspunkte, aber er ist wie immer bester Dinge.\pIch hoffe, dass diese Expedition ein Erfolg wirdDOTS"
str_2:
    .autostring 34 2 "Den ganzen Tag in einer heißen Wüste zu arbeiten ist wirklich fordernd.\pAber wenn wir mit unserer Expedition erfolgreich sind, ist das der perfekte Start für eine steile Karriere als Archäologe."
str_3:
    .autostring 34 2 "Diese kleine Zeltsiedlung wurde auf Initiative der Pokémon-Ranger ins Leben gerufen.\pNachdem immer mehr Trainer in der Hitze hier zusammengebrochen sind, haben wir uns entschlossen, hier einen kleinen Ruheort einzurichten."
str_4:
    .autostring 34 2 "Kannst du dir vorstellen, wie schwierig es war, hier die notwendige Infrastruktur für einen Computer aufzuziehen?"
str_5:
    .autostring 34 2 "Ich muss zugeben, dass es schon ungewöhnlich für eine Schwester ist, nicht in einem Pokéstop zu arbeiten.\pAber ich glaube wirklich daran, dass ich hier viel mehr Trainern und ihren Pokémon helfen kann."

.elseif LANG_EN
.endif