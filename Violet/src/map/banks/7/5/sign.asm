.include "overworld_script.s"
.include "callstds.s"
.include "specials.s"
.include "songs.s"

.global ow_script_silvania_city_gym_statue

ow_script_silvania_city_gym_statue:
    loadpointer 0 str_statue
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_statue:
    .autostring 34 2 "Waldarena.\nArenaleiterin: Mia.\pEs sind die Namen Larissa und Mara eingeritzt.\pRIVAL scheint seinen Namen darunter geschrieben zu habenDOTS"
.elseif LANG_EN
str_statue:
    .autostring 34 2 "Forest Gym.\pGym Leader: Mia.\pThe names Larissa and Mara are engraved.\pIt appears that RIVAL put their name belowDOTS"
.endif
