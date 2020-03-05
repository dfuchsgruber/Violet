.include "overworld_script.s"
.include "callstds.s"

.global ow_script_aktania_clouds_person_0
.global ow_script_aktania_clouds_person_1
.global ow_script_aktania_clouds_person_2

ow_script_aktania_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_aktania_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_aktania_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Diese Ruinen sind hoch interessant.\pOft findet man antike Icognito-Schriftzeichen.\pWas wohl die Menschen über den Wolken mitzuteilen hatten?"
str_1:
    .autostring 34 2 "Meine Großmutter hat mir einmal erzählt, dass die Wolkenmenschen als Strafe für ihren Hochmut ausgelöscht wurden."
str_2:
    .autostring 34 2 "Ich liebe es, auf Regenwolken zu fliegen.\pSie verbreiten so einen einzigartigen Duft."

.elseif LANG_EN
str_0:
    .autostring 34 2 "It is safe to dismount the cloud on solid ground.\pOn a cloud however you better don't try to go afootDOTS"
str_1:
    .autostring 34 2 "As a child I once saw Lucius riding a cloud.\pFrom then on I knew that I wanted to be a cloud rider."
str_2:
    .autostring 34 2 "Do you think that we people would have it better if we lived freely above the clouds?"

.endif