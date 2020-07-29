.include "vars.s"
.include "map_adjacency_types.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "ordinals.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "flags.s"
.include "species.s"
.include "items.s"

.global ow_script_map_3_41_trainer_7
.global ow_script_map_3_41_trainer_20
.global ow_script_map_3_7_route_2_east_trainer_0
.global ow_script_0x8dc94e
.global ow_script_0x1aba6e
.global ow_script_map_3_41_trainer_10
.global ow_script_map_3_41_trainer_11
.global ow_script_map_3_41_trainer_1
.global ow_script_0x1abab4
.global ow_script_0x8dce6c
.global ow_script_0x8305a5
.global ow_script_map_3_41_trainer_9
.global ow_script_0x877bed
.global ow_script_0x1aba89
.global ow_script_0x1abacd
.global ow_script_map_3_41_trainer_3
.global ow_script_0x8ac1e8
.global ow_script_map_3_41_trainer_19
.global ow_script_0x93d5cd
.global ow_script_map_3_41_trainer_14
.global ow_script_0x8fb0c5
.global ow_script_map_3_41_trainer_15
.global ow_script_map_3_41_trainer_12
.global ow_script_0x8aaf95
.global ow_script_map_3_41_trainer_0
.global ow_script_0x8ac217
.global ow_script_0x87f942
.global ow_script_0x947e76
.global ow_script_0x8304ac
.global ow_script_map_3_41_trainer_2
.global ow_script_map_3_7_route_2_east_trainer_1
.global ow_script_map_3_41_trainer_8
.global ow_script_0x8fb0b2
.global ow_script_0x8448c2
.global ow_script_0x8cb3c8
.global ow_script_0x880bcd
.global ow_script_0x8fb105
.global ow_script_0x880bd9
.global ow_script_map_3_41_trainer_21
.global ow_script_map_3_41_trainer_16
.global ow_script_map_3_41_trainer_22
.global ow_script_0x1abaa2
.global ow_script_map_3_41_trainer_4
.global ow_script_map_3_41_trainer_18
.global ow_script_map_3_7_route_2_east_trainer_2
.global ow_script_0x931332
.global ow_script_0x8dc43a
.global ow_script_0x8ac33f
.global ow_script_0x8dcb4e
.global ow_script_map_3_41_trainer_6
.global ow_script_0x8305ae
.global ow_script_0x8fb10e
.global ow_script_map_3_41_trainer_13
.global ow_script_0x8fafe1
.global ow_script_map_3_41_trainer_17
.global ow_script_0x8fb076
.global ow_script_map_3_41_trainer_5
.global ow_script_0x830543
.global ow_script_0x8ac281
.global ow_script_0x8c8acf

ow_script_map_3_41_trainer_7:
loadpointer 0x0 str_0x80f654
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x80f654:
    .autostring 34 2 "Dort drüben hat Professor Tann sein Labor.\pEr ist ein sehr berühmter Archäologe.\pAls er einmal behauptet hat, er wolle sogar die versunkene Stadt Atlantea finden, war ich schwer beeindruckt!"
.elseif LANG_EN
str_0x80f654:
    .autostring 34 2 "Over there, Professor Fig has his laboratory.\pHe is a well renown archeologist.\pWhen he once claimed to even discover the sunken city Atlantea I was most impressed."
.endif


ow_script_map_3_41_trainer_4:
trainerbattlestd 0x0 0x13 0x0 str_0x80f360 str_0x80f391
loadpointer 0x0 str_0x80f391
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x80f360:
    .autostring 34 2 "Ich habe mir eine ganze Reihe starker Käfer-Pokémon gefangen!\pDie machen dich platt!"
str_0x80f391:
    .autostring 34 2 "Meine armen Käfer!\nSie konnten nichts ausrichtenDOTS"
.elseif LANG_EN
str_0x80f360:
    .autostring 34 2 "I caught myself many Bug-type Pokémon.\pThey will demolish your party!"
str_0x80f391:
    .autostring 34 2 "My poor bugs.\nThey couldn't do a thing against your PokémonDOTS"

.endif


ow_script_map_3_41_trainer_3:
trainerbattlestd 0x0 0x14 0x0 str_0x80f3b7 str_0x80f40b
loadpointer 0x0 str_0x80f40b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x80f3b7:
    .autostring 34 2 "Ich bin eine vornehme Lady.\pEs würde sich nicht geziemen, meine Herausforderung abzulehnen."
str_0x80f40b:
    .autostring 34 2 "Wie ungehobelt dein Kampfstil doch ist!"

.elseif LANG_EN
str_0x80f3b7:
    .autostring 34 2 "I am a well-educated lady.\pIt wouldn't be appropriate to decline my challange."
str_0x80f40b:
    .autostring 34 2 "You're fighting style is way too rude!"

.endif


ow_script_map_3_41_trainer_9:
trainerbattlestd 0x0 0x17 0x0 str_0x810968 str_0x810989
loadpointer 0x0 str_0x810989
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x810968:
    .autostring 34 2 "Ich kann Gedanken lesen, weißt du?\pDamit hast du keine Chance gegen mich zu gewinnen!"
str_0x810989:
    .autostring 34 2 "Wie?\nIch kann deine Gedanken nicht hören?"
.elseif LANG_EN

str_0x810968:
    .autostring 34 2 "I can read your mind, you know?\pSo you are pretty much without the slightest chance!"
str_0x810989:
    .autostring 34 2 "How?\nI can't hear your thoughts?"
.endif


ow_script_map_3_41_trainer_11:
loadpointer 0 str_violet_grunt
special 0xE
loadpointer 0x0 str_0x810ec2
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER
str_violet_grunt:
	.string "Team Violet Rüpel"
str_0x810ec2:
    .autostring 34 2 "Hey, was willst du von mir?\pDas hier geht dich nichts an!\pZieh Leine!"
.elseif LANG_EN
str_violet_grunt:
	.string "Team Violet Grunt"
str_0x810ec2:
    .autostring 34 2 "Hey, what do you want?\pThis is none of your buisiness!\pGet lost!"
.endif

ow_script_map_3_41_trainer_10:
lock
faceplayer
checkflag FLAG_ROUTE_2_QUICKCLAW
gotoif EQUAL ow_script_0x8448c2
loadpointer 0x0 str_0x8448cd
callstd MSG_FACE
copyvarifnotzero 0x8000 ITEM_FLINKKLAUE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
lock
compare LASTRESULT 0x0
gotoif EQUAL ow_script_no_room_for_giveitem
setflag FLAG_ROUTE_2_QUICKCLAW
loadpointer 0x0 str_0x844937
callstd MSG_FACE
release
end

ow_script_0x8448c2:
loadpointer 0x0 str_0x844937
callstd MSG_FACE
release
end


.ifdef LANG_GER
str_0x8448cd:
    .autostring 34 2 "Sieh mal, was ich hier auf dem Boden gefunden habe!\pEine Art Klaue oder soDOTS"
str_0x844937:
    .autostring 34 2 "Die Flinkklaue sieht wirklich sehr merkwürdig aus, meinst du nicht?"
.elseif LANG_EN
str_0x8448cd:
    .autostring 34 2 "Look what I just found on the ground.\pIt's some kind of claw or something like itDOTS"
str_0x844937:
    .autostring 34 2 "The Quick Claw really looks funny, doesn't it?"
.endif


ow_script_map_3_41_trainer_16:
    end

ow_script_movs_0x8f5c79:
.byte SAY_EXCLAM
.byte STOP


ow_script_map_3_41_trainer_13:
loadpointer 0x0 str_0x8a538f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a538f:
    .autostring 34 2 "Man nennt Route 2 auch den Birkenpfad.\pIch muss dir wohl nicht erst erklären, wieso, oder?"
.elseif LANG_EN
    .autostring 34 2 "Some people call Route 2 the Birch Path.\pI don't have to explain to you why that is, do I?"
.endif


ow_script_map_3_41_trainer_2:
trainerbattlestd 0x0 0xa 0x0 str_0x8a8910 str_0x8a896a
loadpointer 0x0 str_0x8a896a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a8910:
    .autostring 34 2 "Ein Kampf ist wie ein starker Strom!\pUnd wir Trainer stehen dabei gehörig unter Spannung!"
str_0x8a896a:
    .autostring 34 2 "Oh je!\nIch glaube, das war ein Kurzschulss!"
.elseif LANG_EN

str_0x8a8910:
    .autostring 34 2 "A battle is just like a strong current.\pAnd we trainers are electrized by it!"
str_0x8a896a:
    .autostring 34 2 "Oh man!\nI think that was a short circuit!"

.endif


ow_script_map_3_7_route_2_east_trainer_1:
trainerbattlestd 0x0 0xb 0x0 str_0x8a9536 str_0x8a959f
loadpointer 0x0 str_0x8a959f
callstd MSG_FACE
end

.ifdef LANG_GER

str_0x8a9536:
    .autostring 34 2 "Es ist unfassbar, wie wenig Manieren die jungen Trainer doch heutzutage haben!\pDu bist da nicht anders!"
str_0x8a959f:
    .autostring 34 2 "Nah, vielleicht bist du doch nicht so übel, Kindchen."
.elseif LANG_EN

str_0x8a9536:
    .autostring 34 2 "It really is unbelievable how ill-mannered young trainers are these days!\pAnd you are just like them!"
str_0x8a959f:
    .autostring 34 2 "Nah, maybe you aren't that bad, kiddo."
.endif


ow_script_map_3_41_trainer_5:
trainerbattlestd 0x0 0xc 0x0 str_0x8a9ca1 str_0x8a95fb
loadpointer 0x0 str_0x8a95fb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a9ca1:
    .autostring 34 2 "Gibt es etwas Entspannenderes als ein Picknick im Sonnenschein?\pSicher doch!\nEinen Kampf!"
str_0x8a95fb:
    .autostring 34 2 "Dann bleibt mir jetzt nur noch das Picknick."
.elseif LANG_EN

str_0x8a9ca1:
    .autostring 34 2 "Is there anything more relaxing than camping under the sun?\pSure there is!\nA battle!"
str_0x8a95fb:
    .autostring 34 2 "Well, camping it is then."
.endif


ow_script_map_3_41_trainer_1:
trainerbattlestd 0x0 0xd 0x0 str_0x8a9ce9 str_0x8a9d56
loadpointer 0x0 str_0x8a9d56
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a9ce9:
    .autostring 34 2 "Ich habe noch keinen Kampf verloren.\pMeine Schönheit hat meine Gegner geradezu geblendet!"
str_0x8a9d56:
    .autostring 34 2 "Wie?\nDu konntest meiner Schönheit widerstehen?"
.elseif LANG_EN
str_0x8a9ce9:
    .autostring 34 2 "I never lost a single battle.\pMy beatuy always blinded all my opponents!"
str_0x8a9d56:
    .autostring 34 2 "What?\nYou could withstand my beatuy?"

.endif


ow_script_map_3_7_route_2_east_trainer_2:
trainerbattlestd 0x0 0xe 0x0 str_0x8aa83e str_0x8aa8fb
loadpointer 0x0 str_0x8aa8fb
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x8aa83e:
    .autostring 34 2 "Eines Tages werde ich für Manuel in seiner Arena arbeiten!\pMeinst du, meine Schläge sind schon stark genug?"
str_0x8aa8fb:
    .autostring 34 2 "Wow!\nGroßartig, deine Kampftechnik!\pManuel wäre sicher beeindruckt!"
.elseif LANG_EN

str_0x8aa83e:
    .autostring 34 2 "One day I will work in Manuel's gym!\pDo you think my punches are strong enough yet?"
str_0x8aa8fb:
    .autostring 34 2 "Wow!\nAmazing, your technique is incredible!\pManuel would surely be impressed by you!"
.endif


ow_script_map_3_41_trainer_8:
trainerbattlestd 0x0 0xf 0x0 str_0x8aaad4 str_0x8aab7f
loadpointer 0x0 str_0x8aab7f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8aaad4:
    .autostring 34 2 "Ein Ranger muss auf alle Situationen vorbereitet sein.\pEin vielfältiges Team ist da ein absolutes Muss!"
str_0x8aab7f:
    .autostring 34 2 "Nicht schlecht!\nDu solltest trotzdem daran arbeiten, dein Team vielfältig zu gestalten!"
.elseif LANG_EN

str_0x8aaad4:
    .autostring 34 2 "A ranger needs to be prepeared for all situations.\pA diverse team is an absolute neccisity!"
str_0x8aab7f:
    .autostring 34 2 "Not half bad!\nNonetheless you should work on diversifying your team!"
.endif


ow_script_map_3_41_trainer_0:
trainerbattlestd 0x0 0x9 0x0 str_0x8a9d7f str_0x8aaf13
loadpointer 0x0 str_0x8aaf13
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a9d7f:
    .autostring 34 2 "Gibt es etwas berauschenderes, als das Knirschen des Herbstlaubes unter den Füßen?"
str_0x8aaf13:
    .autostring 34 2 "Die Geräuschkulisse der Natur hat mich zu sehr abgelenktDOTS"
.elseif LANG_EN

str_0x8a9d7f:
    .autostring 34 2 "Is there anything more exhilarating than that crunching sound of leaves under your feet?"
str_0x8aaf13:
    .autostring 34 2 "The sounds of natur distracted me too muchDOTS"
.endif


ow_script_map_3_41_trainer_6:
trainerbattlestd 0x0 0x11 0x0 str_0x8ab8e2 str_0x8abf92
loadpointer 0x0 str_0x8abf92
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ab8e2:
    .autostring 34 2 "Ich bin extrem stark!\pIch habe sogar einmal Manuel aus Blütenbach herausgefordert!\pDu hast keine Chance!"
str_0x8abf92:
    .autostring 34 2 "Unmöglich!\nDu bist sehr stark!"
.elseif LANG_EN

str_0x8ab8e2:
    .autostring 34 2 "I am extremely strong.\pI once even challanged Manuel of Petal Creek to a battle!\pYou have no chance!"
str_0x8abf92:
    .autostring 34 2 "Impossible!\pYou are very strong indeed!"
.endif


ow_script_map_3_41_trainer_22:
    loadpointer 0 str_revo
    special 0xE
    loadpointer 0x0 str_0x8de6b0
    callstd MSG_FACE
    special 0xF
    end

.ifdef LANG_GER
str_revo:
    .string "Revolutionär"
str_0x8de6b0:
    .autostring 34 2 "Unser Anführer nimmt sich am Strand einen Moment Zeit für sich.\pWir warten hier solange auf ihn."

.elseif LANG_EN
str_revo:
    .string "Revolutionary"
str_0x8de6b0:
    .autostring 34 2 "Our leader takes some time for himself at the beach.\pWe will wait here for him."
.endif

ow_script_map_3_41_trainer_17:
loadpointer 0x0 str_0x8e6508
callstd MSG_FACE
end

.ifdef LANG_GER

str_0x8e6508:
    .autostring 34 2 "Südlich von hier liegt Ceometria, die Stadt der Toten.\pAm Waldfriedhof dort betrauern Trainer ihre verstorbenen Pokémon."
.elseif LANG_EN
str_0x8e6508:
    .autostring 34 2 "Going south from here you will eventually reach Ceometria, the town of the dead.\pAt the Forest Cemetery there, trainers pay tribute to the Pokémon they lost."
.endif


ow_script_map_3_7_route_2_east_trainer_0:
trainerbattlestd 0x0 0x37 0x0 str_0x8e658b str_0x8e65f1
loadpointer 0x0 str_0x8e65f1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e658b:
    .autostring 34 2 "Ich bin tierisch genervt!\pDiese Revolutionäre in ihren grünen Kapuzen wollten mich überreden, bei ihnen mitzumachen!\pWas für ein Unfug!\pKomm mir du jetzt nicht auch noch blöd!"
str_0x8e65f1:
    .autostring 34 2 "Ergh\nHeute geht mir alles auf den SenkelDOTS"
.elseif LANG_EN

str_0x8e658b:
    .autostring 34 2 "I am really annoyed!\pThese revolutionaries with their green hoodies tried to convince me to join them!\pWhat a nonsense!\pYou better don't annoy me more now!"
str_0x8e65f1:
    .autostring 34 2 "Ergh\nToday everything just sucksDOTS"
.endif


ow_script_map_3_41_trainer_18:
loadpointer 0x0 str_0x8e6626
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e6626:
    .autostring 34 2 "Von Zeit zu Zeit irren einige Geist-Pokémon hier umher.\pSie kommen wohl aus Ceometria, südlich von hier."
.elseif LANG_EN
str_0x8e6626:
    .autostring 34 2 "From time to time some Ghost-type Pokémon wander arround here.\pThey probably come from Ceometria."
.endif


ow_script_map_3_41_trainer_14:
checkflag BIBOR_QUEST_BIBOR_RECEIVED
gotoif EQUAL ow_script_0x8fb105
checkflag BIBOR_QUEST_DONE
gotoif EQUAL ow_script_0x8fb10e
checkflag BIBOR_QUEST_NOT_TRIGGERED
gotoif EQUAL ow_script_0x8fafe1
loadpointer 0x0 str_0x8dcaa4
callstd MSG_FACE
end


ow_script_movs_0x87bf49:
.byte SAY_QUESTION
.byte STOP


ow_script_0x8fafe1:
checktrainerflag 0x28
gotoif LESS ow_script_0x8fb076
lock
faceplayer
loadpointer 0x0 str_0x8dca59
callstd MSG_KEEPOPEN
fanfare 0x13e
loadpointer 0x0 str_0x8dc421
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
setflag BIBOR_QUEST_DONE
lock
faceplayer
applymovement 0x800f ow_script_movs_0x87bf49
waitmovement 0x0
loadpointer 0x0 str_0x8dc9a6
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x8fb0b2
loadpointer 0x0 str_0x8fb02d
callstd MSG_FACE
end


ow_script_0x8fb0b2:
countpokemon
compare LASTRESULT 0x6
gotoif LESS ow_script_0x8fb0c5
goto ow_script_0x8dc43a

ow_script_0x8dc43a:
loadpointer 0x0 str_0x8dc8dd
callstd MSG_FACE
end

ow_script_0x8fb0c5:
fanfare 0x13e
lock
faceplayer
loadpointer 0x0 str_0x87ae8d
callstd MSG_KEEPOPEN
waitfanfare
givepokemon POKEMON_BIBOR 0xc 0 0x0 0x0 0x0
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x8dc43a
bufferpokemon 0x0 POKEMON_BIBOR
bufferpokemon 0x1 POKEMON_BIBOR
call ow_script_set_nickname
loadpointer 0x0 str_0x8dcd2f
callstd MSG_FACE
setflag BIBOR_QUEST_BIBOR_RECEIVED
end


ow_script_0x8fb076:
lock
faceplayer
loadpointer 0x0 str_0x8dcba5
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8dcb4e
loadpointer 0x0 str_0x8dcb0a
callstd MSG
clearflag BIBOR_QUEST_NOT_TRIGGERED
release
end


ow_script_0x8dcb4e:
loadpointer 0x0 str_0x8dcb58
callstd MSG_FACE
end


ow_script_0x8fb10e:
lock
faceplayer
loadpointer 0x0 str_0x8fcddd
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8dc94e
goto ow_script_0x8fb0b2


ow_script_0x8dc94e:
loadpointer 0x0 str_0x8dc958
callstd MSG_FACE
end


ow_script_0x8fb105:
loadpointer 0x0 str_0x8dcd4c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8dcaa4:
    .autostring 34 2 "Wenn ich mich nicht täusche, ist der Rüpel nach Norden, in Richtung Route 3 geflohen!"
str_0x8dca59:
    .autostring 34 2 "Du hast mir mein Bibor wiedergebracht!\pWahnsinn!\nDankesehr!"
str_0x8dc421:
    .autostring 34 2 "PLAYER übergibt Bibor!"
str_0x8dc9a6:
    .autostring 34 2 "Was ist das?\pEs sieht so aus, als wolle das Bibor bei dir bleiben.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pEs wäre bei dir sicherlich in guten Händen.\pWas sagst du?\nWillst du Bibor in dein Team aufnehmen?"
str_0x8fb02d:
    .autostring 34 2 "Das ist natürlich enttäuschend.\pAber ich bin mir sicher, dass das Bibor, wenn du deine Meinung ändern solltest, jederzeit gerne an deiner Seite kämpfen würde."
str_0x8dc8dd:
    .autostring 34 2 "Sieht so aus, als hättest du keinen Platz, um das Bibor aufzunehmen!\pKomm wieder, wenn du Platz geschaffen hast!"
str_0x87ae8d:
    .autostring 34 2 "PLAYER hat Bibor erhalten!"
str_0x8dcd2f:
    .autostring 34 2 "Kümmere dich gut um Bibor!"
str_0x8dcba5:
    .autostring 34 2 "Du bist ein Trainer, oder?\pEben waren diese Schurken von Team Violet hier und haben mir kurzerhand mein Bibor gestohlen.\pIch habe das Bibor selbst großgezogen.\pIch habe es gekannt, als es noch ein Hornliu war.\pBitte, ich kann gegen diese Ganoven nichts ausrichten.\pWürdest du mir mein Bibor wieder zurückholen?"
str_0x8dcb0a:
    .autostring 34 2 "Ja wirklich?\nWie überhaus großherzig von dir!"
str_0x8dcb58:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pNein, das verstehe ich natürlich.\pMein armes BiborDOTS"
str_0x8fcddd:
    .autostring 34 2 "Bist du gekommen, um Bibor in dein Team aufzunehmen?"
str_0x8dc958:
    .autostring 34 2 "Na gut!\nAber wenn du deine Meinung geändert hast, kannst du dir sicher sein, dass Bibor und ich hier auf dich warten werden."
str_0x8dcd4c:
    .autostring 34 2 "Ich bin dir unendlich dankbar dafür, dass du mein Bibor aus den Fängen von Team Violet befreit hast.\pIch weiß gar nicht, wie ich diese Schuld jemals begleichen sollteDOTS"
.elseif LANG_EN
str_0x8dcaa4:
    .autostring 34 2 "If I am not mistaken, the grunt fled to Route 3, north of here!"
str_0x8dca59:
    .autostring 34 2 "You brought my Beedrill back!\pThank you so much!"
str_0x8dc421:
    .autostring 34 2 "PLAYER hands over the Beedrill"
str_0x8dc9a6:
    .autostring 34 2 "What's that?\pIt looks like the Beedrill wants to stay with you.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIt would be in good hands for sureDOTS\pWhat do you think?\pDo you want to take the Beedrill into your party?"
str_0x8fb02d:
    .autostring 34 2 "Thats disappointing.\pBut I am sure, if you ever change your mind, the Beedrill would be very happy to fight at your side"
str_0x8dc8dd:
    .autostring 34 2 "Looks like you don't have room to get the Beedrill!\pCome back once you made room for it!"
str_0x87ae8d:
    .autostring 34 2 "PLAYER received Beedrill!"
str_0x8dcd2f:
    .autostring 34 2 "Take good care of Beedrill!"
str_0x8dcba5:
    .autostring 34 2 "You are a trainer, right?\pJust now, these grunts of Team Violet were here and stole my precious Beedrill!\pI raised that one myself.\pI have known it ever since it was a Weedle.\pKnowing it's now with people like these breaks my heart.\pPlease, I can't do anything against these grunts.\pCould you, maybe, get back my Beedrill?"
str_0x8dcb0a:
    .autostring 34 2 "Really?\pThat's amazing!\pThank you so much!"
str_0x8dcb58:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pOh, I understand, really.\pMy poor BeedrillDOTS"
str_0x8fcddd:
    .autostring 34 2 "Did you come to take the Beedrill into your party?"
str_0x8dc958:
    .autostring 34 2 "Alright!\pIf you change your mind, be sure that I and Beedrill will be waiting here for you!"
str_0x8dcd4c:
    .autostring 34 2 "I am infintely thankful to you for saving my Beedrill!\pI really don't know how to repay that debt everDOTS"

.endif


ow_script_map_3_41_trainer_12:
checkflag ROUTE_2_LINKCABLE
gotoif EQUAL ow_script_0x8aaf95
lock
faceplayer
loadpointer 0x0 str_0x8abe1c
callstd MSG
copyvarifnotzero 0x8000 ITEM_LINKKABEL
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_no_room_for_giveitem
loadpointer 0x0 str_0x8ab77f
callstd MSG
setflag ROUTE_2_LINKCABLE
release
end


ow_script_0x8aaf95:
loadpointer 0x0 str_0x8ab6bf
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8abe1c:
    .autostring 34 2 "Viele lange Jahre habe ich für Professor Primus in der Laz. Corp gearbeitet.\pUnd wofür?\nEr wirft mich einfach so raus!\pAber bei meinem Abgang habe ich etwas mitgehen lassen!\pIch lasse mich nicht einfach so abspeisen.\pNur habe ich dafür überhaupt keine Verwendung.\pVielleicht kannst du es ja gebrauchen?"
str_0x8ab77f:
    .autostring 34 2 "Das Linkkabel simuliert einen Pokémon-Tausch.\pManche Pokémon entwickeln sich auf diese Weise."
str_0x8ab6bf:
    .autostring 34 2 "Professor Primus Forschung an einem Raum-Zeit-Portal ist einfach blanker Wahnsinn.\pIch musste ihm meine Bedenken mitteilen.\pAber er ist grausam und hat mich einfach rausgeschmissenDOTS"
.elseif LANG_EN
str_0x8abe1c:
    .autostring 34 2 "I spent so many years working for Professor Primus at the Laz. Corp.\pAnd for what?\pThey just fire me!\pBut when I left I took something from them.\pI won't just silently disappear!\pUnfortunately, I don't have any use for it.\pMaybe you want to have it?"    
str_0x8ab77f:
    .autostring 34 2 "The link cable simulates a Pokémon trade.\pSome Pokémon evolve that way."
str_0x8ab6bf:
    .autostring 34 2 "Professor Primus' research on a space-time-portal is just insanity.\pI had to tell them my objections!\pBut Primus is just too cruel.\pHe instantly fired me for thatDOTS"
.endif


ow_script_movs_0x8dea30:
.byte FACE_DOWN
.byte STOP


ow_script_map_3_41_trainer_19:
lock
faceplayer
draw_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT mask_name=1
loadpointer 0x0 str_0x8e225d
callstd MSG_KEEPOPEN
closeonkeypress
hide_mugshot
special 0x113
applymovement 0x7F mov_cam
waitmovement 0

fadesong MUS_REVOLUTION
applymovement 0x800f ow_script_movs_0x8dea30
waitmovement 0x0
loadpointer 0x0 str_0x8e1e69
show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT mask_name=1
applymovement 0x7F mov_cam_back
waitmovement 0
special 0x114
faceplayer
loadpointer 0x0 str_0x8de830
show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT mask_name=1
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
fadesong MUS_ROUTE_24_25
release
end


mov_cam:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP

mov_cam_back:
	.byte STEP_UP, STEP_UP, STEP_UP, STOP


.ifdef LANG_GER

str_0x8e225d:
    .autostring 34 2 "Hallo, mein Kind.\pBeim Blick auf das Meer, werde ich immer ganz sentimentalDOTS"
str_0x8e1e69:
	.autostring 34 2 "Ich erinnere mich dann immer an die guten alten Zeiten zurück.\pBevor Korruption und Machthunger diese Region zerstört haben.\pDamals, als die Trainer nichts als das Kämpfen im Sinn hatten.\pAls niemand möglichst viel Kontrolle über etwas erlangen wollte.\pAberDOTS DOTS DOTS\nDOTS DOTS DOTS\pDiese Zeiten sind vorbei, nicht?"
str_0x8de830:
	.autostring 34 2 "Entschuldige bitte.\pIch muss dir sehr seltsam vorkommen.\pDas Geschwafel eines alten Mannes kann ein Kind nicht beeindrucken.\pAber ich sehe dir an, dass du kein gewöhnlicher Trainer bist.\pWenn ich Recht behalte, dann werden wir uns sicherlich wiedersehen.\pVielleicht, in einem ganz anderen Licht!"
.elseif LANG_EN

str_0x8e225d:
    .autostring 34 2 "Hello, little one.\pWhen looking at the ocean, I just get very sentimalDOTS"
str_0x8e1e69:
	.autostring 34 2 "I remember the good old times then.\pBefore corruption and the hunger for power ruined this region entirely.\pBack then, when trainers only ever cared for battling.\pAnd no one wanted to get control over anything.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pBut these times are long gone, eh?"
str_0x8de830:
	.autostring 34 2 "I am very sorry.\pI must seem very weird to you.\pAn old man's speech won't impress a child.\pBut I can see that you are no ordinary child at all.\pAnd if I am right, we will most likely meet again.\pProbably, under completely different circumstances."

.endif