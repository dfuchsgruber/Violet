.include "overworld_script.s"
.include "callstds.s"

.global ow_script_map_felsige_oednis_clouds_person_0
.global ow_script_map_felsige_oednis_clouds_trainer_0

ow_script_map_felsige_oednis_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_map_felsige_oednis_clouds_trainer_0:
    trainerbattlestd 0 0x214 0 str_before_0 str_after_0
    loadpointer 0 str_later_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hier oben einen Spaziergang zu machen gibt der Seele eine Art der Entspannung, die man in der Welt unten kaum finden kann."
str_before_0:
    .autostring 34 2 "Hast du dir die zwei Türme hier einmal näher angesehen?\pDort gibt es bestimmt eine Menge an Schätzen!"
str_after_0:
    .autostring 34 2 "Nein!\nDie Schätze in den Türmen, willst du mir etwa zuvorkommen?"
str_later_0:
    .autostring 34 2 "Mir ist egal, dass ich verloren habe.\pIch will mir sowieso jetzt erst einmal die beiden Türme hier ansehen!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Taking a walk up here gives the soul a kind of relaxation that you can hardly find in the world below."
str_before_0:
    .autostring 34 2 "Have you taken a closer look at the two towers here?\pThere must be a lot of treasures there!"
str_after_0:    
    .autostring 34 2 "No!\nYou want to get ahead of me with the treasures in the towers?"
str_later_0:
    .autostring 34 2 "I don't care that I lost.\pI want to take a look at the two towers here anyway!"
.endif
