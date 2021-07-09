.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"
.include "species.s"
.include "pathfinding.s"
.include "specials.s"
.include "items.s"

.global ow_script_power_plant_person_0
.global ow_script_power_plant_person_1
.global ow_script_power_plant_person_2
.global ow_script_power_plant_person_3

ow_script_power_plant_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_power_plant_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_power_plant_person_3:
    loadpointer 0 str_3
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
    checkflag FLAG_POWER_PLANT_WINGULL_FOUND
    gotoif NOT_EQUAL quest_ongoing
    pause 16
    applymovement 3 mov_fr
    applymovement 14 mov_fl
    waitmovement 0
    loadpointer 0 str_quest_resolve
    callstd MSG
    pause 16
    sound 0x15
    applymovement 14 mov_say_smile
    waitmovement 0
    checksound
    loadpointer 0 str_quest_resolve_2
    callstd MSG
    pause 8
    applymovement 14 mov_fd
    applymovement 15 mov_fu
    waitmovement 0
    loadpointer 0 str_quest_resolve_3
    callstd MSG
    cry POKEMON_WINGULL 0
    waitcry
    sound 0x15
    applymovement 14 mov_say_smile
    waitmovement 0
    checksound
    loadpointer 0 str_quest_resolve_4
    callstd MSG
    npc_move_to 14 0x15 0x15
    sound 9
    hidesprite 14
    checksound
    pause 24
    loadpointer 0 str_quest_resolve_5
    callstd MSG
    applymovement 15 mov_1u
    waitmovement 0
    applymovement 15 mov_fl
    waitmovement 0
    cry POKEMON_WINGULL 0
    waitcry
    setvar 0x8004 3
    setvar 0x8005 0xFF
    special SPECIAL_NPC_FACE_TO_NPC
    loadpointer 0 str_quest_resolve_6
    callstd MSG
    copyvarifnotzero 0x8000 ITEM_VM03
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
    loadpointer 0 str_quest_resolve_7
    callstd MSG
    fadescreen 1
    hidesprite 3
    hidesprite 15
    setflag FLAG_POWER_PLANT_SURF_QUEST_DONE
    clearflag FLAG_POWER_PLANT_WINGULL_SCIENTIST
    fadescreen 0
    releaseall
    end
quest_ongoing:
    loadpointer 0 str_quest_ongoing
    callstd MSG_FACE
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
str_quest_ongoing:
    .autostring 34 2 "Mein Wingull muss sich irgendwo im Kraftwerk verlaufen habenDOTS\pEs muss sich ganz schrecklich vor den ganzen Elektro-Pokémon dort fürchten.\pBitte beeil dich, ehe ihm etwas zustößt."
str_quest_resolve:
    .autostring 34 2 "Es tut mir wirklich sehr leid, dass mein Wingull Ihnen einfach so ins Kraftwerk gefolgt ist.\pEs ist sehr verspielt und begeht manchmal DummheitenDOTS"
str_quest_resolve_2:
    .autostring 34 2 "Ach, das macht doch nichts!\pDieses Wingull hat mir den Tag versüßt, ehrlich!\pUnd ich bin froh, dass es wieder bei seinem Besitzer sein kann."
str_quest_resolve_3:
    .autostring 34 2 "Auf wiedersehen, Kleines!\pEs hat mir großen Spaß mit dir gemacht!"
str_quest_resolve_4:
    .autostring 34 2 "Mach's gut!"
str_quest_resolve_5:
    .autostring 34 2 "Ich bin ja so froh, dich wiederzuhaben!"
str_quest_resolve_6:
    .autostring 34 2 "Ich bin dir wirklich sehr dankbar, dass du mir mein Wingull zurückgebracht hast.\pWie sich herausgestellt hat, war es gar nicht in Gefahr, sondern hat einfach nur nach einem Spielgefährten gesucht.\pIch bin wohl mittlerweile einfach zu alt, um bei solchen Alberein mitzumachenDOTS\pAber die Erleichterung, dass meinem Wingull nichts zugestoßen ist, steht mir sicherlich ins Gesicht geschrieben.\pDafür möchte ich mich bei dir erkenntlich zeigen."
str_quest_resolve_7:
    .autostring 34 2 "Diese Versteckte Maschine enthält Surfer.\pDamit kannst du auf Wellen reiten und Gewässer passieren.\pIn meinen jungen Jahren würden mein Wingull und ich die Küsten der Region bereisen und dort gemeinsam die Meere erkunden.\pVielleicht sollte ich das einmal wieder ins Auge fassen, wo sich mein Wingull doch inzwischen mit mir zu langweilen scheintDOTS\pWie dem auch sei, vielen Dank, dass du uns beide wieder zusammengebracht hast.\pAuf Wiedersehen, junger Trainer!"
str_3:
    .autostring 34 2 "Hätte ich gewusst, dass dieses Wingull einen Besitzer hat, hätte ich es natürlich sofort zurückgebrachtDOTS"
.elseif LANG_EN
.endif
