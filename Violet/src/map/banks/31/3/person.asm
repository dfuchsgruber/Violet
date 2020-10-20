.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ardeal_person_3
.global ow_script_ardeal_person_4
.global ow_script_ardeal_person_5
.global ow_script_ardeal_person_6
.global ow_script_ardeal_person_7
.global ow_script_ardeal_person_8

ow_script_ardeal_person_3:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_ardeal_person_4:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_ardeal_person_5:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_ardeal_person_6:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_ardeal_person_7:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_ardeal_person_8:
    loadpointer 0 str_5
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "In diesem Raum werden unzählige Vorräte aufbewahrt.\pDenk gar nicht erst daran, etwas davon zu stehlen!"
str_1:
    .autostring 34 2 "Von Zeit zu Zeit zieht der Burgherr sich in diesen Raum zurück und lässt seinen Blick über den weiten Ozean schweifen.\pEr ist wahrlich ein Mann von großer Weisheit."
str_2:
    .autostring 34 2 "Lord Lucius hat sich in jungen Jahren einen Ruf als Drachentöter gemacht.\pEr verehert das Schwert-Pokémon Durengard auch mitunter deshalb, weil es ihm zu großem Ruhm verholfen hat."
str_3:
    .autostring 34 2 "Nur wenige wissen darüber bescheid, dass der Burgherr einst einen erbitterten Kampf mit einem legendären Pokémon ausgefochten hat.\pSein gesamter Körper ist deshalb mit Narben versehrt."
str_4:
    .autostring 34 2 "Die Bücher, die hier aufbewahrt werden, sind sehr alt.\pSie erzählen davon, dass eine dunkle Königin diese Burg erbaut haben soll.\pFür viele Jahre musste der Kontinent sich ihrer Schreckensherrschaft beugen."
str_5:
    .autostring 34 2 "Viele Butler wissen nicht, vom geheimen Verließ dieser Burg.\pLucius hat alles daran gesetzt, es geheimzuhaltenDOTS\pIch frage mich, was wohl der Grund dafür ist."

.elseif LANG_EN
str_0:
    .autostring 34 2 "In this room we store our stocks.\pDon't you even think about stealing any of it!"
str_1:
    .autostring 34 2 "Every now and then the lord retreats to this room and lets his eyes wander about the vast ocean.\pHe really is a man of much wisdom."
str_2:
    .autostring 34 2 "Lord Lucius made himself a name as dragon slayer during his younger years.\pHe worships the sword Pokémon Aegislash above else as it helped him to much fame."
str_3:
    .autostring 34 2 "Only few people know that the lord of this castle once had a fierce battle with a legendary Pokémon.\pBecause of that scars are all over his body."
str_4:
    .autostring 34 2 "The books that are kept here are very old.\pThey tell about a dark queen building this caslte.\pFor many years the continent had to suffer her oppressive reign."
str_5:
    .autostring 34 2 "Many butlers don't even know about the secret dungeon of this castle.\pLucius put a lot of effort into keeping it a secretDOTS\pI really wonder why that is."

.endif