.include "overworld_script.s"
.include "callstds.s"

.global ow_script_flavor_text_laz_corp_fossils_rock_0
.global ow_script_flavor_text_laz_corp_fossils_rock_1
.global ow_script_flavor_text_laz_corp_fossils_machine

ow_script_flavor_text_laz_corp_fossils_rock_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_flavor_text_laz_corp_fossils_rock_1:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end
ow_script_flavor_text_laz_corp_fossils_machine:
    loadpointer 0x0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "In diesem Stein scheinen einige Fossilien zu stecken.\pDie Forscher werden sie vermutlich untersuchenDOTS"
str_1:
    .autostring 34 2 "Der Stein glänzt seltsam hell.\pOb er mit einem Präparat behandelt wurde?"
str_2:
    .autostring 34 2 "Die Maschine gibt ein lautes Summen von sich.\pWozu sie wohl gut ist?"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Some fossils seem to be stuck in this rock.\pThe researchers will probably examine themDOTS"
str_1:
    .autostring 34 2 "The rock shines strangely bright.\pI wonder if it has been treated with some kind of preparation?"
str_2:
    .autostring 34 2 "The machine emits a loud humming sound.\pI wonder what it is used for?"
.endif
