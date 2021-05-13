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
    warpmuted 17 2 0xFF 0x8 0x13
    waitstate
    releaseall
    end

priest_done:
    loadpointer 0 str_priest_done
    callstd MSG_FACE
    end

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
.elseif LANG_EN

.endif



.global ow_script_map_3_23_trainer_4
.global ow_script_0x94bff4
.global ow_script_map_3_23_trainer_12
.global ow_script_0x94be70
.global ow_script_map_3_23_trainer_2
.global ow_script_map_3_23_trainer_10
.global ow_script_map_3_23_trainer_0
.global ow_script_map_3_23_trainer_8
.global ow_script_0x949a37
.global ow_script_0x94c10c
.global ow_script_0x94be24
.global ow_script_0x94ba17
.global ow_script_map_3_23_trainer_11
.global ow_script_map_3_23_trainer_5
.global ow_script_map_3_23_trainer_6
.global ow_script_map_3_23_trainer_9
.global ow_script_map_3_23_trainer_7
.global ow_script_map_3_23_trainer_1
.global ow_script_map_3_23_trainer_3

ow_script_map_3_23_trainer_1:
loadpointer 0 str_x
callstd MSG_FACE
end

.ifdef LANG_GER
str_x:
    .autostring 34 2 "Seit einigen Jahren ist es in Mode, auf einer Wolke zu reiten.\pIch wünschte, ich besäße so eine Wolke."

.elseif LANG_EN
str_x:
    .autostring 34 2 "Some years ago it became a trend to ride a cloud.\pI wish I had one of those."


.endif


ow_script_map_3_23_trainer_2:
trainerbattlestd 0x0 0x85 0x0 str_0x949732 str_0x9497bd
loadpointer 0x0 str_0x9497bd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x949732:
    .string "Diese Ruinen entstammen der Kultur\neines antiken Volkes.\pSie haben die Wolken und das\nsymbolisch dafür stehende Pokémon\lAltaria verehrt."



str_0x9497bd:
    .string "Noch heute findet der Kult der\nWolkenmenschen Anhänger."


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_3:
loadpointer 0x0 str_0x94982e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94982e:
    .string "Hast du je von der Laz.Corp\ngehört?\pSie ist für den rapiden\ntechnischen Fortschritt unserer\lZeit verantwortlich!"


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_7:
loadpointer 0x0 str_0x949bd4
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x949bd4:
    .string "Wir sind Wolkenpriester und\nWolkenreiter und verehren den\lHimmel.\pUnsere Tradition reicht bis zu den\nAnfängen der Geschichte zurück.\pEines Tages wird der große grüne\nDrache erneut herabsteigen und ein\lneues Zeitalter einläuten."


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_0:
trainerbattlestd 0x0 0x86 0x0 str_0x948c85 str_0x9497f6
loadpointer 0x0 str_0x9497f6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x948c85:
    .string "Es tut mir im Herzen weh, wie ihr\njungen Leute das Vermächtnis\lmeiner Generation vernichtet."



str_0x9497f6:
    .string "Dass du nicht einmal den Anstand\nhast, zu verlierenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_4:
trainerbattlestd 0x0 0x87 0x0 str_0x9498a0 str_0x94994a
loadpointer 0x0 str_0x94994a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9498a0:
    .string "Hast du es schon gehört?\pDie Laz.Corp will diesen Monat\nnoch ein Produkt namens Poképad\lauf den Markt bringen.\pAls Ass-Trainer muss ich mir das\nauf jeden Fall ansehen."



str_0x94994a:
    .string "Wie, du besitzt bereits ein\nPoképad?"


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_6:
trainerbattlestd 0x0 0x88 0x0 str_0x949b31 str_0x949b9d
loadpointer 0x0 str_0x949b9d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x949b31:
    .string "Käferpokémon gibt es sehr viele,\nman kann sie leicht fangen.\pAber ob sie auch im Kampf\nüberzeugen können?"



str_0x949b9d:
    .string "Buhu! Du hast sie alle zerquetscht\nmeine armen Käfer."


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_8:
loadpointer 0x0 str_0x949cb9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x949cb9:
    .string "Heil denen, die auf den Wolken\nwandern.\lHeil dem Volk des Himmels."


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_10:
loadpointer 0x0 str_0x94c233
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94c233:
    .string "Hast du je vom weißen Albus\ngehört?\pEr war einst Mitglied der Top Vier\nund leitet jetzt die edle\lRevolutionsbewegung.\pEr ist ja so edel, so großmüßtig\nund großherzigDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_11:
loadpointer 0x0 str_0x94c2dd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94c2dd:
    .string "Besitzt du auch eine Detektor?\pIn den Optionen kannst du\neinstellen, ob du benachricht\lwerden willst, wenn du dich in die\lNähe eines versteckten Items\lbegibst."


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_12:
trainerbattlestd 0x0 0x8b 0x0 str_0x94c37e str_0x949d71
loadpointer 0x0 str_0x949d71
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94c37e:
    .string "Hast du schon deine Typentabelle\nauswendig gelernt?\pIch für meinen Teil kenne alle\nTypverhältnisse aus dem Stegreif!"



str_0x949d71:
    .string "Was? Hast du überhaupt gelernt?"


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_5:
checkflag ROUTE_5_SANFTGLOCKE
gotoif EQUAL ow_script_0x949a37
lock
faceplayer
loadpointer 0x0 str_0x9499a7
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_SANFTGLOCKE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x949a41
callstd MSG_FACE
setflag ROUTE_5_SANFTGLOCKE
end


ow_script_0x949a37:
loadpointer 0x0 str_0x949a41
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9499a7:
    .string "Du siehst mir aus wie jemand, der\nsich darum bemüht, ein enges Band\lzu seinen Pokémon aufzubauen.\pNimm dieses Item, es wird dir\ndabei helfen."



str_0x949a41:
    .string "Trägt ein Pokémon die Sanftglocke,\nso wird es zutraulicher."

.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_9:
checkflag ROUTE_5_CLOUD_RECEIVED
gotoif EQUAL ow_script_0x94ba17
lock
faceplayer

loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94b8ae
callstd MSG_KEEPOPEN
special 0xF

checkflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
gotoif EQUAL ow_script_0x94bff4

loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x949ddc
callstd MSG_KEEPOPEN
special 0xF

checkitem ITEM_ITEM_10B 0x1
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x94c10c
closeonkeypress
special 0xF
release
end


ow_script_movs_0x94c6c7:
.byte SAY_EXCLAM
.byte STOP


ow_script_0x94c10c:
sound 0x15
applymovement 0x800f ow_script_movs_0x94c6c7
waitmovement 0x0

loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94c615
callstd MSG_KEEPOPEN
special 0xF

fanfare 0x13e
additem ITEM_FAHRRAD 0x1
loadpointer 0x0 str_0x94bc55
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
removeitem ITEM_ITEM_10B 0x1


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94ba96
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94c596
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94ba21
callstd MSG
special 0xF
setflag ROUTE_5_CLOUD_RECEIVED
end




ow_script_movs_0x94be6d:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x94bc7c:
.byte FACE_DOWN
.byte STOP


ow_script_0x94bff4:
fadesong MUS_CLOUDS
closeonkeypress
cry POKEMON_ALTARIA 0x0
waitcry
sound 0x15
applymovement 0xff ow_script_movs_0x94be6d
applymovement 0x800f ow_script_movs_0x94be6d
waitmovement 0x0


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94be36
callstd MSG
special 0xF

cry POKEMON_ALTARIA 0x0
waitcry
clearflag PKMNMENU
showsprite 0xd
call ow_script_0x94be24
call ow_script_0x94be24
call ow_script_0x94be24
call ow_script_0x94be24
call ow_script_0x94be70
cry POKEMON_ALTARIA 0x0
waitcry


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94bdbf
callstd MSG
special 0xF

cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94bd31
callstd MSG
special 0xF

cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94bc7f
callstd MSG
special 0xF

cry POKEMON_ALTARIA 0x0
waitcry
applymovement 0x800f ow_script_movs_0x94bc7c
waitmovement 0x0
fanfare 0x13e
additem ITEM_FAHRRAD 0x1
loadpointer 0x0 str_0x94bc55
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
cry POKEMON_ALTARIA 0x0
waitcry

loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94bf95
callstd MSG
special 0xF
fadescreen 0x1
cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry
hidesprite 0xd
fadescreen 0x0
fadesong MUS_ROUTE_3_10_AND_ROUTE_16_22


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94bb88
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94c596
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94ba21
callstd MSG
special 0xF
setflag PKMNMENU
setflag ROUTE_5_CLOUD_RECEIVED
release
end


ow_script_movs_0x94c591:
.byte STEP_IN_PLACE_DOWN_FAST
.byte 0x1c
.byte 0x1c
.byte STEP_DOWN
.byte STOP


ow_script_0x94be70:
sound 0x96
applymovement 0xd ow_script_movs_0x94c591
waitmovement 0x0
return


ow_script_movs_0x94be33:
.byte STEP_DOWN_VERY_SLOW
.byte STOP


ow_script_0x94be24:
sound 0x96
applymovement 0xd ow_script_movs_0x94be33
waitmovement 0x0
return


ow_script_0x94ba17:

loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94ba21
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER

str_priest:
	.string "Wolkenpriester"

str_0x94b8ae:
	.autostring 35 2 "Hallo, junger Trainer!\pIch bin ein Priester der Wolken.\pWir haben eine traditionsreiche Kultur, musst du wissen.\pAußerdem beherrschen wir die Kunst des Wolkenwebens.\pMenschen können auf gewobenen Wolken schweben.\pDOTS DOTS DOTS\pLeider kann ich dir so eine Wolke nicht einfach überlassen.\pNur, wer sich durch Hingabe als würdig erweist, erhält das Privileg, auf einer gewobenen Wolke zu fliegen."


str_0x949ddc:
	.autostring 35 2 "Allerdings DOTS DOTS DOTS\pIch könnte eine Ausnahme machen, vorausgesetzt, du bist bereit, eine Gegenleistung zu erbringen.\pDer Archäologe Professor Tann hat vor einier Zeit ein Artefakt entdeckt, das eigentlich unsere Kultur hätte zugestanden.\pStattdessen aber hat man es in das Orina City Museum gebracht.\pWenn du uns das Wolkenherz aus dem Museum beschaffen kannst, werde ich dir im Gegenzug eine Wolke weben."




str_0x94c615:
	.autostring 35 2 "Oh? Du hast es tatsächlich dabei, das Wolkenherz?\pIch muss mich bei dir bedanken, du hast unserer Kultur einen großen Gefallen erwiesen.\pIch kann dir nun guten Gewissens eine Wolke weben."



str_0x94bc55:
    .string "PLAYER hat eine\ngewobene Wolke erhalten."



str_0x94ba96:
	.autostring 35 2 "Das Wolkenherz ist ein uraltes Relikt, das schon viele Generationen vor uns in Ehren gehalten haben.\pEs gehört den Wolkenmenschen und sollte nicht in einem Museum ausgestellt werden."


str_0x94c596:
    .autostring 35 2 "Du kannst auf einer Wolke wie auf einem Fahrad die Landschaft schneller erkunden."



str_0x94ba21:
    .autostring 35 2 "Wenn du am Boden den Schatten einer tiefliegenden Wolke erkennst, kannst du auf deiner gewobenen Wolke in den Himmel emporsteigen."



str_0x94be36:
    .autostring 35 2 "Wie, was ist das?\pDer Ruf eines Altarias?"



str_0x94bdbf:
    .autostring 35 2 "Ist das ein goldenes Altaria?\pSo etwas habe ich noch nie gesehen!"



str_0x94bd31:
    .autostring 35 2 "Es DOTS DOTS DOTS\nscheint sich bei dir für etwas bedanken zu wollen DOTS"



str_0x94bc7f:
	.autostring 35 2 "Weißt du, warum das Altaria in deiner Schuld steht?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pSo so! Du hast sein Ei beschützt?\pSag das doch gleich!\pJemand, der einem solchen Pokémon selbstlos seine Hilfe geschenkt hat, ist sicherlich würdig, eine gewobene Wolke zu besitzen."



str_0x94bf95:
    .autostring 35 2 "Das Altaria verabschiedet sich von dir.\pEs ist ein wirklich rührender Augenblick!"



str_0x94bb88:
	.autostring 35 2 "Du bist ein wirklich bemerkenswertes Kind.\pDu hast außerordentliches Glück, ein goldenes Altaria mit eigenen Augen zu sehen.\pNicht viele Menschen können das von sich behaupten."


.elseif LANG_EN

.endif