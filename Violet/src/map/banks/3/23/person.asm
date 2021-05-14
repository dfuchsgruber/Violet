.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"
.include "overworld/overworld_effects.s"
.include "specials.s"

.global ow_script_route_5_person_0
.global ow_script_route_5_person_1
.global ow_script_route_5_person_2
.global ow_script_route_5_person_3
.global ow_script_route_5_person_4
.global ow_script_route_5_person_5
.global ow_script_route_5_person_6
.global ow_script_route_5_person_7
.global ow_script_route_5_person_8
.global ow_script_map_route_5_sooth_bell
.global ow_script_route_5_cloud_priest
.global ow_script_route_5_priest_receive_cloud

ow_script_route_5_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_5_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_5_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_route_5_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_route_5_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_route_5_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_route_5_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_route_5_person_7:
    loadpointer 0 str_7
    callstd MSG_FACE
    end
ow_script_route_5_person_8:
    loadpointer 0 str_8
    callstd MSG_FACE
    end

ow_script_map_route_5_sooth_bell:
    lock
    faceplayer
    checkflag ROUTE_5_SANFTGLOCKE
    gotoif EQUAL after_receiving_sooth_bell
    loadpointer 0x0 str_intro_sooth_bell
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_SANFTGLOCKE
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    loadpointer 0x0 str_after_receiving_sooth_bell
    callstd MSG_KEEPOPEN
    closeonkeypress
    release
    setflag ROUTE_5_SANFTGLOCKE
    end

after_receiving_sooth_bell:
    loadpointer 0x0 str_after_receiving_sooth_bell
    callstd MSG_FACE
    end

ow_script_route_5_cloud_priest:
    lock
    faceplayer
    checkflag ROUTE_5_CLOUD_RECEIVED
    gotoif EQUAL priest_done
    checkflag FLAG_ROUTE_5_CLOUD_ARIADOS_DEFEATED
    gotoif EQUAL receive_cloud
    checkflag FLAG_ROUTE_5_CLOUD_QUEST_TAKEN
    gotoif EQUAL priest_quest_taken
    loadpointer 0 str_priest_take_quest
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL priest_refuse_quest
    loadpointer 0 str_priest_fly_up
    callstd MSG_KEEPOPEN
    closeonkeypress
    setvar VAR_ROUTE_5_CLOUD_LEVELSCRIPT 1
    setflag FLAG_ROUTE_5_CLOUD_QUEST_TAKEN
priest_fly_up:
    special SPECIAL_PLAYER_GET_POSITION_FACING
    setanimation 0 0x8004
    setanimation 1 0x8005
    doanimation OVERWORLD_EFFECT_WHIRLWIND
    pause 32
    applymovement 0xFF mov_fly_out
    applymovement LASTTALKED mov_fly_out
    waitmovement 0
    warpmuted 17 2 0xFF 0x6 0x13
    waitstate
    releaseall
    end
priest_done:
    loadpointer 0 str_priest_done
    callstd MSG_FACE
    end
receive_cloud:
    call ow_script_route_5_priest_receive_cloud
    release
    end
ow_script_route_5_priest_receive_cloud:
    checksound
    sound 0x15
    applymovement LASTTALKED mov_exclam
    waitmovement 0
    loadpointer 0 str_priest_make_cloud
    callstd MSG
    fadescreen 1
    pause 20
    fadescreen 0
    loadpointer 0 str_priest_give_cloud
    callstd MSG_KEEPOPEN
    fanfare 0x13e
    additem ITEM_FAHRRAD 0x1
    loadpointer 0 str_receive_cloud
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    removeitem ITEM_WOLKENGARN 0x1
    loadpointer 0 str_priest_explain_cloud
    callstd MSG_KEEPOPEN
    setflag ROUTE_5_CLOUD_RECEIVED
    clearflag FLAG_ROUTE_5_CLOUD_QUEST_TAKEN // hides the priest on sky island
    return

priest_refuse_quest:
    loadpointer 0 str_priest_refuse_quest
    callstd MSG_FACE
    end

priest_quest_taken:
    loadpointer 0 str_priest_ask_up_again
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL priest_dont_go_up_again
    loadpointer 0 str_priest_up_again
    callstd MSG_KEEPOPEN
    closeonkeypress
    goto priest_fly_up

priest_dont_go_up_again:
    loadpointer 0 str_priest_not_up_again
    callstd MSG_FACE
    end

mov_fly_out:
    .byte 164, STOP


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich verstecke mich gern im hohen Gras.\pAber manchmal machen mir die wilden Pokémon AngstDOTS"
str_1:
    .autostring 34 2 "Im Fernsehen haben sie über ein seltenes Käfer-Pokémon berichtet.\pJetzt suche ich überall danachDOTS\pWo ich wohl ein Ramoth finden kann?"
str_2:
    .autostring 34 2 "Manchmal beobachte ich diese lustigen Wolkenreiter, wie sie dahin gleiten.\pIch muss zugeben, dass so eine Wolke doch sehr gemütlich aussieht, findest du nicht?"
str_3:
    .autostring 34 2 "Ich habe einmal eine Wolkenreiterin dabei beobachtet, wie sie auf ihrer Wolke in so einer Windhose abgehoben ist.\pIch frage mich, ob sie einfach wieder heruntergefallen istDOTS"
str_4:
    .autostring 34 2 "Ich war einmal Angestellter der Laz. Corp.\pViele Jahre habe ich für Professor Primus gearbeitet.\pAber seit er damals aus Bruchfels zurückgekehrt istDOTS\pDu weißt schon, nach dem Unglück daDOTS\pNun, er hat sich irgendwie verändert."
str_5:
    .autostring 34 2 "Wir Wolkenreiter folgen einer langen Tradition des Wolkenreitens.\pVor vielen Jahrhunderten hat man ganze Städte auf schwebenden Himmelsinseln errichtet."
str_6:
    .autostring 34 2 "Bist du neidisch auf meine Wolke?\pIch habe sie selbst gewoben."
str_7:
    .autostring 34 2 "Dieser Teich ist ein großartiger Ort, um einmal dem ganzen Lärm der Großstadt zu entkommen.\pVersteh mich nicht falschDOTS\pIch mag es, in Orina City zu leben, aber manchmal braucht selbst ein Teenager eine Auszeit."
str_8:
    .autostring 34 2 "Warst du schon einmal im Museum von Orina City?\pProfessor Tann hat einen großen Teil der dort ausgestellten Fossilien ausgegraben.\pDiese Ausstellungsstücke sind wirklich atemberaubend!"
str_intro_sooth_bell:
    .autostring 34 2 "Ein Trainer kann das volle Potential seiner Pokémon nur entfalten, wenn diese ihm voll und ganz vertrauen.\pDas Band zwischen Mensch und Pokémon muss jede Zerreisprobe überstehen können.\pDu wirkst auf mich wie eine Person, die sich um das Wohl der eigenen Pokémon sorgt.\pIch will dir dieses Item anvertrauen."
str_after_receiving_sooth_bell:
    .autostring 34 2 "Ein Pokémon, das die Sanftglocke trägt, wird schneller zutraulich.\pDas wird das Band zwischen dir und deinen Pokémon noch stärker machen."
str_priest_done:
    .autostring 34 2 "Auf deiner Wolke kannst du dich bis ans Ende der Welt gleiten.\pHalte deine Augen nach kleinen Wirbelströmungen in der Luft offen.\pDie tragen dich hoch hinauf in eine Welt, die wie aus einem Märchen wirkt."
str_priest_take_quest:
    .autostring 34 2 "Dieser Tempel wurde vor langer Zeit von einem Volk erbaut, das hoch oben im Himmel lebte.\pAuf selbstgewobenen Wolken haben sie auf schwebenden Inseln prächtige Städte errichtet.\pUnd noch heute gibt es einige wenige Menschen, die sich in der Kunst des Wolkenwebens verstehen.\pUnd ich bin einer von ihnen!\pWeißt du was?\pIch werde dir einfach zeigen, was ich meine, ja?"
str_priest_refuse_quest:
    .autostring 34 2 "W-Was?\pDu denkst wohl, ich erzähle dir Märchen!\pAber ich sage dir, all das ist die Wahrheit!\pWenn du es dir anders überlegen solltestDOTS\pDu weißt ja, wo du mich findest."
str_priest_fly_up:
    .autostring 34 2 "Alles klar!\pDann nimm meine Hand und halte dich gut fest.\pAuf keinen Fall loslassen, ja?"
str_priest_ask_up_again:
    .autostring 34 2 "Dich hat doch wohl nicht die Höhenangst gepackt?\pDas will ich aber nicht hoffenDOTS\pSoll ich doch noch einmal nach oben bringen?"
str_priest_up_again:
    .autostring 34 2 "Halt dich gut fest!"
str_priest_not_up_again:
    .autostring 34 2 "Ganz wie du willst.\pWenn du es dir anders überlegstDOTS\pDu weißt ja, wo du mich findest."
str_priest_make_cloud:
    .autostring 34 2 "Du hast den Wolkengarn beschafft?\pDas ist ja fantastisch.\pWenn du mir kurz gibst, werde ich dir daraus eine Wolke weben, ja?"
str_priest_give_cloud:
    .autostring 34 2 "Also gut, alles fertig!"
str_priest_explain_cloud:
    .autostring 34 2 "Auf dieser Wolke kannst du die unendlichen Weiten des Himmels erkunden.\pNicht viele Trainer können das von sich behaupten.\pIst das nicht einfach spitze?"
str_receive_cloud:
    .autostring 34 2 "PLAYER hat Wolke erhalten."
.elseif LANG_EN

.endif
