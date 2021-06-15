.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "map_adjacency_types.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"

.global ow_script_map_9_13_person_5
.global ow_script_map_9_13_person_6
.global ow_script_map_9_13_person_3
.global ow_script_map_9_13_person_1
.global ow_script_0x9584ba
.global ow_script_map_9_13_person_0
.global ow_script_map_9_13_person_4
.global ow_script_map_9_13_person_2

ow_script_map_9_13_person_0:
loadpointer 0x0 str_0x955c37
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x955c37:
    .autostring 34 2 "Früher einmal hat die Laz. Corp. versucht, ein Pokémon zu klonen.\pDas soll allerdings nicht sehr gut ausgegangen seinDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_13_person_6:
loadpointer 0x0 str_0x955c9d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x955c9d:
    .autostring 34 2 "Ich bin der Laz. Corp. Abteilungsleiter für Kybernetik.\pWir arbeiten seit einiger Zeit daran, ein virtuelles Pokémon zu realisieren.\pUnd dank der zauberhaften und ebenso genailen Elise ist uns nun endlich der Durchbruch gelungen!"

.elseif LANG_EN

.endif


ow_script_map_9_13_person_3:
loadpointer 0x0 str_0x955d38
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x955d38:
    .autostring 34 2 "Ein Problem des virtuellen Pokémons, an dem wir arbeiten, sind seine harten Kanten.\pMit dem nächsten Up-Grade müssen wir diese unbedingt glätten."
.elseif LANG_EN

.endif


ow_script_map_9_13_person_2:
    checkflag ORINA_CITY_UP_GRADE
    gotoif EQUAL done
    checkflag ORINA_CITY_RECEIVED_PORYGON
    gotoif EQUAL not_received_pory
    lock
    faceplayer
    loadpointer 0x0 str_0x957fcc
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_UP_GRADE
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    setflag ORINA_CITY_UP_GRADE
done:
    loadpointer 0x0 str_0x9580a7
    callstd MSG_FACE
    end
not_received_pory:
    loadpointer 0 str_not_received_pory
    callstd MSG_FACE
    end

.ifdef LANG_GER

str_0x957fcc:
    .autostring 34 2 "Ich habe Tag und Nacht gearbeitet, um eine Verbesserungs-Software für Porygon zu entwickeln.\pWürdest du sie bitte für mich ausprobieren?\pIch wäre dir wirklich dankbar!"
str_0x9580a7:
    .autostring 34 2 "Du kannst ein Linkkabel benutzen, um das Up-Grade bei Porygon zu installieren.\pDas wird seine Fähigkeiten deutlich verbessern."
str_not_received_pory:
    .autostring 34 2 "Meine Aufgabe ist es, das virtuelle Pokémon, das wir hier entwickeln, noch stärker zu machen.\pUnd ich habe die Software dafür gerade kürzlich erst fertig gestelltDOTS"
.elseif LANG_EN

.endif


ow_script_map_9_13_person_1:
loadpointer 0x0 str_0x958121
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958121:
    .autostring 34 2 "Wir arbeiten laufend daran, das Pokémon, das wir entwickelt haben, zu verbessern.\pUnd das Praktische dabei ist, dass wir dafür bloß ein Software-Update installieren müssen."


.elseif LANG_EN

.endif


ow_script_map_9_13_person_4:
    loadpointer 0x0 str_0x9581f2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0x9581f2:
    .autostring 34 2 "Ich habe immer davon geträumt, ein Pokémon selbst zu entwerfen\pEs ist ein unglaubliches Gefühl, so etwas selbst zu erschaffen, verstehst du?"


.elseif LANG_EN

.endif

ow_script_map_9_13_person_5:
    lockall
    faceplayer
    loadpointer 0 str_elise_0
    show_mugshot MUGSHOT_ELISE message_type=MSG_KEEPOPEN hide_mugshot=0
    loadpointer 0 str_elise_1
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    hide_mugshot
    setvar 0x4001 POKEMON_PORYGON
    givepokemon POKEMON_PORYGON 0x1e ITEM_NONE 0x0 0x0 0x0
    compare LASTRESULT 0x2
    gotoif EQUAL ow_script_0x9584ba
    hide_mugshot
    applymovement LASTTALKED mov_fu
    waitmovement 0x0
    pause 48
    faceplayer
    bufferpokemon 0x0 POKEMON_PORYGON
    fanfare 0x13e
    loadpointer 0x0 str_receive_porygon
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    call ow_script_set_nickname
    loadpointer 0x0 str_after_porygon
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT hide_mugshot=0
    update_mugshot_emotion MUGSHOT_HAPPY
    loadpointer 0 str_after_porygon_2
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_after_porygon_3
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    loadpointer 0 str_after_porygon_4
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_HAPPY
    loadpointer 0 str_after_porygon_5
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_after_porygon_6
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_HAPPY
    loadpointer 0 str_after_porygon_7
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_after_porygon_8
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_SHOCKED
    loadpointer 0 str_after_porygon_9
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_HAPPY
    loadpointer 0 str_after_porygon_10
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    setflag ORINA_CITY_MISTRALS_GRUNTS
    clearflag FLAG_ELISE_GONE
    addvar STORY_PROGRESS 1
    fadescreen 0x1
    hidesprite LASTTALKED
    fadescreen 0x0
    releaseall
    end

ow_script_0x9584ba:
    loadpointer 0x0 str_0x9584c8
    callstd MSG
    hide_mugshot
    releaseall
    end


.ifdef LANG_GER
str_elise_0:
    .autostring 34 2 "Hallo PLAYER!\pSieht so aus, als hättest du mein Labor gefunden.\pUnd wie versprochen erhältst du nun das Pokémon, das wir entwickelt haben."
str_elise_1:
    .autostring 34 2 "Ich bin mir sicher, dass es in deinen fähigen Händen gut aufgehoben ist."
str_receive_porygon:
    .autostring 34 2 "PLAYER hat ein BUFFER_1 erhalten."
str_after_porygon:
    .autostring 34 2 "Dieses Pokémon befindet sich noch in einem experimentellen Stadium.\pWir werden an ihm sicherlich noch einige Verbesserungen vornehmen können."
str_after_porygon_2:
    .autostring 34 2 "Ist es nicht spannend, dass unsere Technologie in der Lage ist, ein Pokémon am Computer zu optimieren?\pBei der Laz. Corp. wird wirklich Unglaubliches geleistet."
str_after_porygon_3:
    .autostring 34 2 "Und wo wir gerade bei großen Leistungen sindDOTS\p"
str_after_porygon_4:
    .autostring 34 2 "Ich frage mich, wie es Professor Tann auf seiner Expedition wohl ergehen magDOTS"
str_after_porygon_5:
    .autostring 34 2 "Ich hoffe wirklich, dass er eines Tages die versunkene Stadt findet, nach der er nun schon so lange sucht."
str_after_porygon_6:
    .autostring 34 2 "Er ist immerhin eine Kopryphähe der Archäologie.\pDas Museum hier in der Stadt verdankt viele seiner Ausstellungsstücke der Arbeit von Professor Tann.\pDu solltest dir die Gelegenheit auf keinen Fall entgehen lassen, dort vorbeizusehen."
str_after_porygon_7:
    .autostring 34 2 "Das Archäologiemuseum von Orina City ist wirklich einen Besuch wert."
str_after_porygon_8:
    .autostring 34 2 "DOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG"
str_after_porygon_9:
    .autostring 34 2 "Ich rede schon wieder ohne Punkt und Komma.\pDabei sollte ich wirklich zurück an die Arbeit."
str_after_porygon_10:
    .autostring 34 2 "Es war schön, dich wieder einmal zu sehen, PLAYER!\pPass auf dich und das BUFFER_1 auf, ja?"
str_0x9584c8:
    .autostring 35 2 "Wie schade, du scheinst keinen Platz mehr auf deinem PC zu haben.\pKomm doch wieder, wenn du das BUFFER_1 entgegennehmen kannst."


.elseif LANG_EN

.endif