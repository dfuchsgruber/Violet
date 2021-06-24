.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"

.global ow_script_power_plant_person_0
.global ow_script_power_plant_person_1
.global ow_script_power_plant_person_2

ow_script_power_plant_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_power_plant_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_power_plant_person_2:
    checkflag FLAG_POWER_PLANT_WINGULL_QUEST_TAKEN
    gotoif EQUAL quest_taken
    lock
    faceplayer
    loadpointer 0 str_take_quest
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL take_quest
    loadpointer 0 str_dont_take_quest
    callstd MSG_KEEPOPEN
    release
    end
take_quest:
    loadpointer 0 str_quest_taken
    callstd MSG_KEEPOPEN
    setflag FLAG_POWER_PLANT_WINGULL_QUEST_TAKEN
    getplayerpos 0x8000 0x8001
    compare 0x8000 0x14
    callif EQUAL move_right
    compare 0x8000 0x14
    callif NOT_EQUAL move_left
    release
    end

move_right:
    applymovement LASTTALKED mov_1r
    waitmovement 0
    applymovement LASTTALKED mov_fl
    waitmovement 0
    return
move_left:
    applymovement LASTTALKED mov_1l
    waitmovement 0
    applymovement LASTTALKED mov_fr
    waitmovement 0
    return

quest_taken:
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Mein Pokémon und ich arbeiten im Kraftwerk.\pWir können beide einfach nicht genug von der Elektrizität hier bekommen!"
str_1:
    .autostring 34 2 "Hörst du das Kinstern?\pDas kommt von den Spulen, die hier betrieben werden.\pGanz schon furchteinflößend, oder?"
str_take_quest:
    .autostring 34 2 "Oh, du bist ein Trainer, oder?\pMein geliebtes Wingull ist mir davon gelaufen und hat sich in dieses Kraftwert verirrt.\pUnd dort gibt es so viele Elektro-PokémonDOTS\pIch mache mir solche Sorgen um mein Wingull.\pKönntest du es mir vielleicht zurückbringen?"
str_dont_take_quest:
    .autostring 34 2 "Oh, na gut.\pIch denke, dass ich auch gar nicht das Recht habe, dich um so einen Gefallen zu bitten.\pAber ich mache mir solche Sorgen um mein WingullDOTS"
str_quest_taken:
    .autostring 34 2 "Wirklich?\pDas ist ja fantastisch!\pMein Wingull muss sich irgendwo im Kraftwerk verlaufen haben.\pBitte beeil dich, ehe ihm etwas zustößt."
.elseif LANG_EN
.endif
