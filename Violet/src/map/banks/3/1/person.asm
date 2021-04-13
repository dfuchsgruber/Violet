.include "ordinals.s"
.include "vars.s"
.include "attacks.s"
.include "move_tutor.s"
.include "movements.s"
.include "map_adjacency_types.s"
.include "specials.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"
.include "overworld/overworld_effects.s"

.global ow_script_map_bluetenbach_person_0
.global ow_script_map_bluetenbach_person_1
.global ow_script_map_bluetenbach_person_2
.global ow_script_map_bluetenbach_person_3
.global ow_script_map_bluetenbach_person_4
.global ow_script_map_bluetenbach_person_5
.global ow_script_map_bluetenbach_person_6
.global ow_script_map_bluetenbach_person_7
.global ow_script_map_bluetenbach_person_8
.global ow_script_map_bluetenbach_person_9
.global ow_script_map_bluetenbach_person_10
.global ow_script_map_bluetenbach_person_11
.global ow_script_map_bluetenbach_person_12
.global ow_script_map_bluetenbach_person_13
.global ow_script_map_bluetenbach_person_14
.global ow_script_map_bluetenbach_person_15
.global ow_script_map_bluetenbach_person_16
.global ow_script_map_bluetenbach_person_17
.global ow_script_map_bluetenbach_person_18
.global ow_script_map_bluetenbach_person_19
.global ow_script_map_bluetenbach_person_20
.global ow_script_map_bluetenbach_trainer_0
.global ow_script_map_bluetenbach_move_tutor_rock_slide
.global ow_script_map_bluetenbach_rival
.global ow_script_map_bluetenbach_black_belt_gift

ow_script_map_bluetenbach_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_7:
    loadpointer 0 str_7
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_8:
    loadpointer 0 str_8
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_9:
    loadpointer 0 str_9
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_10:
    loadpointer 0 str_10
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_11:
    loadpointer 0 str_11
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_12:
    loadpointer 0 str_12
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_13:
    loadpointer 0 str_13
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_14:
    loadpointer 0 str_14
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_15:
    loadpointer 0 str_15
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_16:
    loadpointer 0 str_16
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_17:
    loadpointer 0 str_17
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_18:
    loadpointer 0 str_18
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_19:
    loadpointer 0 str_19
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_person_20:
    loadpointer 0 str_20
    callstd MSG_FACE
    end
ow_script_map_bluetenbach_trainer_0:
    trainerbattlecont 1 0x19A 17 str_before0 str_after0 trainer0_later
trainer0_later:
    loadpointer 0 str_later0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Blütenbach ist ein Ort voll Tradition.\pSeit Jahrzehnten finden sich hier Kämpfer ein, um gegeinander anzutreten."
str_1:
    .autostring 34 2 "Für manche ist dieses Dorf ein Pilgerzentrum des Kampfes.\pAber laden die Kirschblüten nicht viel mehr dazu ein, Frieden zu suchen?"
str_2:
    .autostring 34 2 "Von hier oben kann bis nach Anemoia herabblicken.\pDas ist wirklich ein schöner Fleck Land."
str_3:
    .autostring 34 2 "Mein Bruder hat mir mein Funkelstück geklaut!\pDem werde ich es zeigen!"
str_4:
    .autostring 34 2 "Ich habe meine Schwester überhaupt nichts weggenommen!\pDiese Zicke soll mich in Ruhe lassen!"
str_5:
    .autostring 34 2 "Selbst an einem so schönen Ort wie diesem vergeht kein Tag, an dem meine Kinder nicht streitenDOTS"
str_6:
    .autostring 34 2 "Für viele Wanderer stellt diese Region einen großen Reiz dar.\pIch bin den ganzen Weg von der Felsigen Ödnis hierher gekommen, und das nur zu Fuß!"
str_7:
    .autostring 34 2 "Jeder Schwarzgurt, der sich einen Namen gemacht hat, trainierte in Blütenbach.\pDer Arenaleiter Manuel ist selbst eine Koryphähe des Faustkampfes!"
str_8:
    .autostring 34 2 "Viele meinen, ein Schwarzgurt wäre nur auf rohe Kraft und Stärke bedacht.\pWenn mir der Arenaleiter Manuel eines beigebracht hat, dann das die wahre Stärke im Geist liegt.\pNur wer gesammelt und fokussiert kämpft, kann bestehen!"
str_9:
    .autostring 34 2 "Es ist schon faszinierend, dass das Wasser, das von hier bis nach Anemonia ließt, direkt aus dem Meer kommtDOTS\pErstaunlich, wie offenbar schon unscheinbare Kleinigkeiten zusammenhängen, oder?"
str_10:
    .autostring 34 2 "Ich mag nicht wie ein Schwarzgurt aussehen, aber ich verehre den Arenaleiter Manuel dennoch sehr.\pAls ich noch ein Kind war, habe ich mit angesehen, wie er die Steine, auf denen wir in diesem Moment stehen, aus dem Berg mit bloßen Händen herausgeschlagen hat.\pDas hat starken Eindruck hinterlassen."
str_11:
    .autostring 34 2 "Um mich zu beeindrucken hat mein Freund sogar den Arenaleiter herausgefordert.\pDas ist zwar nicht unbedingt gut für ihn ausgegangen, aber als ich ihn wieder gesund gepflegt habe, sind wir uns dann doch näher gekommen.\pMan könnte also sagen, dass sein Plan doch in gewisser Weise aufgegangen ist."
str_12:
    .autostring 34 2 "Ich habe Jahre gebraucht, den Mut aufzubringen, meiner Freundin meine Gefühle zu gestehen.\pUnd dann hat es noch zwei weitere gebraucht, ehe ich ihr Herz erobert hatte.\pAber all diese Strapazen würde ich, ohne zu zögern, wieder auf mich nehmen."
str_13:
    .autostring 34 2 "Mein Pokémon ist diesen Baum hinaugeklettert.\pJetzt traut es sich aber nicht mehr herunterDOTS"
str_14:
    .autostring 34 2 "Viele wissen das nicht mehr, aber der Pinke Faun ist in diesem Dorf aufgewachsen.\pIch glaube sogar, dass die Kirschblüten hier ihm zu seinem Namen verholfen haben.\pWer hätte gedacht, dass aus so einem netten Jungen ein so berühmter Trainer werden könnte?"
str_15:
    .autostring 34 2 "Dieses Jahr werde ich mich an Fauns Trainerschule einschreiben.\pAlso muss ich in Form kommen.\pIch habe gehört, dass Faun überaus streng mit seinen Schülern ist und ich will einen guten ersten Eindruck machen!"
str_16:
    .autostring 34 2 "Mein Bruder wurde war Matrose, ehe der Pirat Blackbeard ihn ums Eck gebracht hat.\pJetzt trainiere ich hier, um irgendwann Rache für ihn zu nehmen!\pErst, wenn ich, wie Manuel, in der Lage bin, Stein mit bloßen Händen zu zertrümmern, werde ich eine Chance gegen Blackbeard haben."
str_17:
    .autostring 34 2 "Kannst du dir vorstellen, mit welchen Vorurteilen man hier zu kämpfen hat, wenn man etwas dicker ist?\pSchließlich wimmelt es in diesem Dorf ja nur so von Muskelprotzen."
str_18:
    .autostring 34 2 "Der Wassertunnel gilt als der sicherste Weg, um schnell nach Kaskada zu gelangen.\pTrotzdem stürzt er ab und an ein.\pDa kommt der unser Arenaleiter, Manuel, ins Spiel.\pEr räumt die Brocken einfach so weg.\pUnglaublich, wie stark er ist, nicht?"
str_19:
    .autostring 34 2 "Als ich Manuel das erste Mal herausgefordert habe, hat er sich die Augen verbunden, nur um mich zu verhöhnen.\pUnd trotzdem hat er mit mir den Boden aufgewischt.\pEin solcher Kämpfer ist nur zu bewundern."
str_20:
    .autostring 34 2 "Ich bin auf der Suche nach seltenen Käfer-Pokémon.\pAber an diesem Ort scheint sich diese Art von Pokémon nicht gerade zu tummeln.\pWohin das Auge blickt, diese furchteinflößenden Kampf-PokemonDOTS"
str_before0:
    .autostring 34 2 "Du bist wohl hier, um den Arenaleiter Manuel herauszufordern, was?\pAber du bist noch ein Grünschnabel.\pDu würdest in dieser Arena keine Sekunde überstehen.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDu glaubst mir nicht?\pNa, dann zeig mir doch, was du auf dem Kasten hast!"
str_after0:
    .autostring 34 2 "Gar nicht mal übelDOTS\pFür einen Anfänger natürlich."
str_later0:
    .autostring 34 2 "Pech gehabt!\nDer Arenaleiter ist gerade nicht im Haus, also kannst du trotzdem nicht hinein.\pManuel ist damit beschäftigt, den unlängst eingestürzten Wassertunnel zu räumen."
.elseif LANG_EN
str_0:
    .autostring 34 2 "Petal Creek is a place full of tradition.\pFor decaded strong people from all around the world come together here in order to challange one another."
str_1:
    .autostring 34 2 "For some fighters this village is a center of pilgrimage.\pBut don't these cherry trees much rather invite one to seek out peace?"
str_2:
    .autostring 34 2 "From up here you can see all the way to Anemoia.\pThis really is a beautiful piece of land."
str_3:
    .autostring 34 2 "My brother took my Sparkle Piece!\pJust wait until I get him!"
str_4:
    .autostring 34 2 "I didn't take anything from my sister!\pThis she-goat needs to leave me alone!"
str_5:
    .autostring 34 2 "Even at a place as beautiful as this there isn't a single day on which my children wouldn't fight each otherDOTS"
str_6:
    .autostring 34 2 "For many hikers this region is very tempting.\pI for example walked all the way from the Rocky Wastelands by foot!"
str_7:
    .autostring 34 2 "Every black belt that made a name of themselves once trained in Petal Creek.\pThis town's gym leader Manuel himself is a tycoon when it comes to close combat!"
str_8:
    .autostring 34 2 "Many think a black belt only ever is concerned with raw power and strength.\pBut if the gym leader Manuel taught me one thing, it is that true strength originates in ones mind.\pOnly one who is focused may be victorious in the end!"
str_9:
    .autostring 34 2 "It really is fascinating that the water that reaches even Anemonia from here directly comes from the oceanDOTS\pIt really is astounding how even seemingly meaningless things are connected in such ways, don't you think so?"
str_10:
    .autostring 34 2 "I may not look like a black belt, but I really do think very highly of the gym leader Manuel.\pWhen I was a child, I saw him break the rocks we are standing on right now out of a mountain side with just his bare hands.\pThat made a lasting impression on me, I guess."
str_11:
    .autostring 34 2 "To impress me, my boyfriend even picked a fight with the gym leader Manuel.\pYou can't really say that things went all to well for him, obviously.\pThen again, only when I took care of him afterwards we two got closer to each other.\pSo I guess you could say that my boyfriend's plan kinda worked out for him, right?"
str_12:
    .autostring 34 2 "It took me years to finally confess my feelings to my girlfriend.\pAnd only years later I finally was able to win her heart.\pBut even considering all these struggles I wouldn't hesitate to do it all again."
str_13:
    .autostring 34 2 "My Pokémon just climbed this tree.\pNow it is too afraid to come down againDOTS"
str_14:
    .autostring 34 2 "Many may not rembember that, but actually the Pink Faun grew up in this village.\pI think that the cherry trees here might have even helped him to his name.\pWho would have thought that such a nice little boy could become a trainer this famous?"
str_15:
    .autostring 34 2 "This year I will register at Faun's trainerschool.\pThat is why I have to get in shape.\pI have heard that Faun is very strict with his disciples.\pThat's why I want to make a good first impression!"
str_16:
    .autostring 34 2 "My brother was a sailor until the pirate Blackbeard got the best of him.\pNow I have to train here until I am strong enough to take my revenge for him.\pOnly when I am able to smash rocks with my bare hands, just like Manuel, I will stand a chance against Blackbeard."
str_17:
    .autostring 34 2 "Can you even image what it is being bigger at a place like this?\pThere is so many muscular guys here, that I can't help but feeling awfulDOTS"
str_18:
    .autostring 34 2 "The water tunnel is said to be the safest way to get to Cascada from here.\pNonetheless it just collapses from time to time.\pThat's when our gym leader, Manuel, comes into play.\pHe just carries all the boulders away.\pIncredible how strong this guy is, right?"
str_19:
    .autostring 34 2 "When I challanged Manuel the first time, he blindfolded himself just to taunt me.\pRegardless of his blindness I was utterly defeated by him.\pYou can't help but to admire a fighter like that."
str_20:
    .autostring 34 2 "I am looking for Bug-type Pokémon.\pBut it appears that this kind of Pokémon doesn't rellay live here.\pWherever you look, there is just one of those frightening Fighting-type PokémonDOTS"
str_before0:
    .autostring 34 2 "Let me guessDOTS\pYou are here to challange the gym leader Manuel, right?\pBut you are but a rookie!\pYou wouldn't last a mere second in this gym.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDon't believe me, eh?\pThen show me what you are made of, kiddo!"
str_after0:
    .autostring 34 2 "Not even half badDOTS\pFor a rookie, that isDOTS"
str_later0:
    .autostring 34 2 "Well, joke's on you!\pThe gym leader is not here right now, so you can't enter anyway.\pManuel is busy clearing the recently collapsed water tunnel."

.endif

ow_script_map_bluetenbach_black_belt_gift:
    lock
    faceplayer
    checkflag MERIANA_CITY_BLACK_BELT
    gotoif EQUAL after_receiving_black_belt
    loadpointer 0x0 str_intro_black_belt
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_SCHWARZGURT
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    loadpointer 0x0 str_after_receiving_black_belt
    callstd MSG_KEEPOPEN
    closeonkeypress
    release
    setflag MERIANA_CITY_BLACK_BELT
    end

after_receiving_black_belt:
    loadpointer 0x0 str_after_receiving_black_belt
    callstd MSG_FACE
    end


.ifdef LANG_GER

str_intro_black_belt:
    .autostring 34 2 "Hyjaaa!\nKa! Pow! Haja!\pIch bin unbesiegbar!\pUnd weißt du, woran das liegt?\pNa, an meinem Kampfgurt, natürlich!\pDu glaubst mir nicht?\pIch werde es dir beweisen.\pNimm diesen Schwarzgurt!"
str_after_receiving_black_belt:
    .autostring 34 2 "Der Schwarzgurt verstärkt die Kampf-Angriffe eines Pokémon, wenn es ihn trägt.\pDamit sitzt jeder Schlag, garantiert!"
.elseif LANG_EN
str_intro_black_belt:
    .autostring 34 2 "Hjyaaa!\nKa! Pow! Haja!\pI am invincible!\pAnd do you know why that is?\pWell, because of my belt, of course!\pYou don't believe me?\pI will prove it to you!\pTake this Black Belt!"
str_after_receiving_black_belt:
    .autostring 34 2 "The Black Belt makes Fighting-Type attacks stronger when being held by a Pokémon.\pEvery move will be a hit, I am not gonna lie!"
.endif

ow_script_map_bluetenbach_move_tutor_rock_slide:
    loadpointer 0x0 str_move_tutor_intro
    callstd MSG_FACE
    call move_tutor_item_check
    gotoif EQUAL has_mushrooms
    end

has_mushrooms:
    applymovement 0x800f say_exclam
    waitmovement 0x0
    loadpointer 0x0 str_ask_move_tutor
    callstd MSG_YES_NO
    compare LASTRESULT 0x1
    gotoif LESS move_tutor_abort
    loadpointer 0x0 str_which_should_learn
    callstd MSG
    setvar 0x8005 MOVE_TUTOR_STEINHAGEL
    call ow_script_move_tutor_do
    compare LASTRESULT 0x0
    gotoif EQUAL move_tutor_abort
    call ow_script_move_tutor_pay_items
    loadpointer 0x0 str_move_tutor_pay_items
    callstd MSG
    end

move_tutor_abort:
    loadpointer 0x0 str_move_tutor_abort
    callstd MSG
    end

say_exclam:
    .byte SAY_EXCLAM, STOP

.ifdef LANG_GER
str_move_tutor_intro:
    .autostring 34 2 "Viele Jahre habe ich die verschiedensten Höhlen erkundet.\pIch habe viele Kampffertigkeiten erworben.\pMeine Pokémon sind nun sogar dazu im Stande, Steine hageln zu lassen.\pWenn du mir entweder einen Riesenpilz oder drei Minipilze gibst, kann ich diese Technik einem deiner Pokémon beibringen."
str_ask_move_tutor:
    .autostring 34 2 "Ha!\nAusgezeichnet!\pDu hast BUFFER_2-mal BUFFER_1 bei dir!\pAls Gegenleistung bringe ich einem deiner Pokémon Steinhagel bei.\pWas sagst du dazu?"
str_which_should_learn:
    .autostring 34 2 "Gute Wahl!\pWelches Pokémon soll Steinhagel lernen?"
str_move_tutor_abort:
    .autostring 34 2 "Wie schade!\pSolltest du einem deiner Pokémon Steinhagel beibringen wollen, weißt du ja, wo ich zu finden bin."
.elseif LANG_EN
str_move_tutor_intro:
    .autostring 34 2 "Many years I have spend exploring many caves!\pI learned many battle techniques while wandering arround the world.\pNow, my Pokémon are even able to make rocks fall down on foes.\pIf you want me to teach this to one of your Pokémon, bring me either one Large Mushroom or three Tiny Mushrooms."
str_ask_move_tutor:
    .autostring 34 2 "Ha!\nSplendid!\pYou brought me BUFFER_2-times BUFFER_1!\pIn return I can teach one of your Pokémon the move Rock Slide.\pWhat do you think?"
str_which_should_learn:
    .autostring 34 2 "Good choice!\pWhich Pokémon should learn Rock Slide?"
str_move_tutor_abort:
    .autostring 34 2 "What a shame!\pIf you want me to teach one of your Pokémon Rock Slide, I will just be right here."
.endif

ow_script_map_bluetenbach_rival:
    lock
    faceplayer

	setvar 0x8004 2
	setvar 0x8005 2
	special SPECIAL_BUFFER_BADGE_NAME
    loadpointer 0 str_rival_0
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT hide_mugshot=0 message_type=MSG_KEEPOPEN
    loadpointer 0 str_rival_1
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_rival_2
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    callstd MSG_KEEPOPEN
    loadpointer 0 str_rival_3
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_rival_4
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_rival_5
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_rival_6
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    callstd MSG_KEEPOPEN
    loadpointer 0 str_rival_7
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_rival_8
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_rival_9
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_rival_10
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    pause 15
    applymovement LASTTALKED mov_fd
    waitmovement 0
    pause 50
    setanimation 0, 1
    doanimation OVERWORLD_EFFECT_NPCFLY_OUT
    pause 15
    hidesprite LASTTALKED
    checkanimation OVERWORLD_EFFECT_NPCFLY_OUT
    release
    end

.ifdef LANG_GER
str_rival_0:
    .autostring 34 2 "PLAYER!\pDa bist du ja!"
str_rival_1:
    .autostring 34 2 "Hätte ich mir eigentlich denken müssen, dass ich dich in der Arena finde."
str_rival_2:
    .autostring 34 2 "Du siehst ganz schön geschafft ausDOTS"
str_rival_3:
    .autostring 34 2 "Da hat dir Manuel wohl ordentlich zugesetzt, was?"
str_rival_4:
    .autostring 34 2 "Aber ich habe den BUFFER_3 natürlich schon errungen!"
str_rival_5:
    .autostring 34 2 "Deswegen habe ich dich aber eigentlich nicht gesucht, PLAYER."
str_rival_6:
    .autostring 34 2 "Und ich fürchte, dass wir leider auch keine Zeit haben, gegeneinander zu kämpfen."
str_rival_7:
    .autostring 34 2 "Weißt du, ich habe vorhin einen Anruf von Papi erhalten.\pUnd du wirst nie erraten, was er mir erzählt hat, PLAYER!"
str_rival_8:
    .autostring 34 2 "Papi wird sich auf eine gefährliche Expedition begeben und für einige Zeit unterwegs sein."
str_rival_9:
    .autostring 34 2 "Und da wollte er sich davor noch von uns beiden verabschieden.\pAlso müssen wir unseren Kampf vertagen, PLAYER.\pIch weiß nicht, wie lange Papi noch hier sein wird, also sollten wir uns besser beeilen, ja?"
str_rival_10:
    .autostring 34 2 "Wer zuletzt in seinem Labor auf Route 2 ist, schuldet dem anderen einen Tee aus Kaskada, ja?\pUnd dir gebe ich ganz sicher nichts aus, PLAYER!"


str_elise:
	.autostring 34 2 "Hallo PLAYER!\nSchön, dich zu sehen!\pIch muss dir wirklich noch einmal danken, dass du im Kranzwald meinen Vater vor Team Violet gerettet hast.\pEs will mir nicht in den Kopf gehen, dass solche Leute es auf meinen Vater abgesehen habenDOTS\pAber ich bin aus einem ganz anderen Grund hier.\pProfessor Tann schickt mich, weil er dir und RIVAL etwas verkünden möchte.\pEigentlich sollte ich es nicht verraten, aber er wird sich auf eine sehr gefährliche Expedition begeben und will euch beide zuvor noch einmal sehen.\pAm Besten besuchst du uns in Professor Tanns Labor auf Route 2.\pBis dann, PLAYER!"
.elseif LANG_EN
str_elise:
    .autostring 34 2 "Hello PLAYER!\pNice to see you!\nHow are you doing?\pI really have to thank you again for saving my father in the Kranzdorf-Forest from Team Violet.\pIt just doesn't make sense to me why people like these are after my dad.\pBut actually I am here for a completely different reason.\pProfessor Fir sends me because he wants to tell something to you and RIVAL.\pTo be honest I was told not to spoil it, but the professor is going on a very dangerous expedition and before he wants to see you guys once more.\pBest you visit him in the Professor's lab on Route 2.\pSee you, PLAYER!"
.endif
