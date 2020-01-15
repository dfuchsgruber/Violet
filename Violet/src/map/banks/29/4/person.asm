.include "overworld_script.s"
.include "callstds.s"
.include "items.s"
.include "flags.s"
.include "vars.s"
.include "specials.s"
.include "ordinals.s"
.include "songs.s"

.global ow_script_route_7_secret_power_lab_person_0
.global ow_script_route_7_secret_power_lab_person_1

ow_script_route_7_secret_power_lab_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_7_secret_power_lab_person_1:
    checkflag SECRET_POWER_LAB_ACCESS
    gotoif EQUAL done
    checkflag FLAG_ROUTE_7_SECRET_POWER_LAB_QUEST_TAKEN
    gotoif EQUAL skip_intro
    callasm route_7_secret_power_lab_buffer_all_species
    loadpointer 0 str_intro
    callstd MSG_FACE
    setflag FLAG_ROUTE_7_SECRET_POWER_LAB_QUEST_TAKEN
    end
skip_intro:
    lock
    faceplayer
    loadpointer 0 str_1
    callstd MSG_KEEPOPEN
    pause 32
    closeonkeypress
    special2 LASTRESULT SPECIAL_ROUTE_7_SECRET_POWER_LAB_COUNT_MISSING_DEX_ENTRIES
    compare LASTRESULT 3
    gotoif EQUAL missing_3
    compare LASTRESULT 2
    gotoif EQUAL missing_2
    compare LASTRESULT 1
    gotoif EQUAL missing_1 
    fanfare MUS_SOUND_317
    loadpointer 0 str_success
    callstd MSG_KEEPOPEN
    waitfanfare

    loadpointer 0 str_no_missing
    callstd MSG_KEEPOPEN
    
    fanfare 0x13E
    loadpointer 0 str_got_access
    callstd MSG_KEEPOPEN
    waitfanfare
    setflag SECRET_POWER_LAB_ACCESS
done:
    loadpointer 0 str_done
    callstd MSG_FACE
    end

missing_3:
    loadpointer 0 str_missing_3
    callstd MSG_FACE
    end

missing_2:
    loadpointer 0 str_missing_2
    callstd MSG_FACE
    end

missing_1:
    loadpointer 0 str_missing_1
    callstd MSG_FACE
    end





    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Wir erforschen die Geheimpower.\pMit dem Angriff kannst du schwer zugängliche Gebiete erkunden.\pNur dort findest du die seltensten Pokémon."
str_intro:
    .autostring 34 2 "Ich bin ein Forscher der Laz. Corp und forsche hier draußen an der Geheimpower.\pWas das ist?\pNun, bei Geheimpower handelt es sich um einen Angriff, den du auch außerhalb des Kampfes verwenden kannst, um schwer zugängliche Areale zu erkunden.\pAllerdings fehlen mir für meine Forschung die Pokédex-Daten von drei ganz bestimmten PokémonDOTS\pDabei handelt es sich um BUFFER_1, BUFFER_2 und BUFFER_3.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAber du scheinst ein talentierter Trainer zu sein.\pKannst du mir vielleicht die Pokédex-Einträge zu diesen drei Pokémon beschaffen?\pIch wäre dir wirklich dankbar!"
str_1:
    .autostring 34 2 "Oh, du bist es!\pWenn ich mir deinen Pokédex so anseheDOTS"
str_missing_3:
    .autostring 34 2 "Dann fehlen mir offenbar noch immer die Dex-Einträge zu BUFFER_1, BUFFER_2 und BUFFER_3DOTS\pWenn du diese Pokémon fangen und mir deren Pokédex-Einträge zeigen könntest, wäre ich dir wirklich sehr dankbar!"
str_missing_2:
    .autostring 34 2 "Dann fehlen mir die Pokédex Einträge von BUFFER_1 und BUFFER_2.\pZumindest einen der Dex-Einträge haben wir schon.\pWenn du mir die anderen beiden zeigen kannst, wäre ich dir sehr dankbar.\pBleib dran."
str_missing_1:
    .autostring 34 2 "Dann fehlt nur noch der Pokédex Eintrag von BUFFER_1.\pFast geschafft also!\pZeig mir noch den Pokédex Eintrag von BUFFER_1, und ich werde mich dafür erkenntlich zeigen!"
str_success:
    .autostring 34 2 "Sind meine Daten jetzt vollständig!"
str_no_missing:
    .autostring 34 2 "Vielen Dank!\pAls Gegenleistung werde ich dir Zugang zum Geheimpower-Labor der Laz. Corp verschaffen.\pDas ist ein großes Privileg, das nur die besten Trainer der Region genießen.\pFühl dich also ruhig geehrt!"
str_got_access:
    .autostring 34 2 "PLAYER hat nun Zugang zum Geheimpower Labor der Laz. Corp."
str_done:
    .autostring 34 2 "Du solltest unbedingt im Hauptquartier der Laz. Corp vorbeischauen.\pIch sage dir, dass Geheimpower das Trainer-Dasein revolutionieren wird."

.elseif LANG_EN
str_0:
    .autostring 34 2 "We do research on Secret Power.\pWith that attack you can explore areas that are hard to reach.\pOnly there you can find the most rare Pokémon."
str_intro:
    .autostring 34 2 "Hello there, I am a reserarcher at the Laz. Corp and work on the Secret Power out here.\pWhat that is?\pWell secret power is an attack that can be used outside of a battle to explore areas that are hard to get to.\pHowever, for my studies I still lack some Pokédex data of very specific species.\pTo be a bit more precise, I need the Pokédex entries of BUFFER_1, BUFFER_2 and BUFFER_3.\pDOTS DOTS DOTS\pDOTS DOTS DOTS\pBut you seem to be a talented trainer, yes?\pMaybe you can help me gather the Pokédex entries of those three?\pI really would be grateful to you!"
str_1:
    .autostring 34 2 "Oh, it's you!\pIf I take a look at your PokédexDOTS"
str_missing_3:
    .autostring 34 2 "I still need the Pokédex entries of BUFFER_1, BUFFER_2 and BUFFER_3DOTS\pIf you can catch those Pokémon and show me the respective Pokédex entries I would be most grateful."
str_missing_2:
    .autostring 34 2 "I am missing the Pokédex entries of BUFFER_1 and BUFFER_2.\pAt least one entry we already got.\pIf you can provide me with the other two, I will give you something very special in return.\pKeep it up!"
str_missing_1:
    .autostring 34 2 "I only need the Pokédex entry of BUFFER_1!\pAlmost done!\pShow me the Pokédex entry of BUFFER_1 and I will grant you a very special gift!"
str_success:
    .autostring 34 2 "My data is now complete!"
str_no_missing:
    .autostring 34 2 "Thank you so much!\pIn return I will grant you access to the secret power laboratory of the Laz. Corp.\pThis is a great privilege as only the best trainers of this region use secret power.\pYou may as well feel honored!"
str_got_access:
    .autostring 34 2 "PLAYER was granted access to the secret power laboratory of the Laz. Corp."
str_done:
    .autostring 34 2 "You really should pay the headquarters of the Laz. Corp a visit.\pI assure you, Secret Power is going to revolutionize being a trainer!"
.endif