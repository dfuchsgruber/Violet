.include "overworld_script.s"
.include "callstds.s"
.include "items.s"
.include "specials.s"
.include "vars.s"
.include "ordinals.s"
.include "movements.s"
.include "flags.s"
.include "species.s"

.global ow_script_pokemart
.global ow_script_nurse_joy
.global ow_script_init_union_room
.global ow_script_botogel

ow_script_pokemart:
    lock
    faceplayer
    preparemsg str_mart_ask
    waitmsg
    pokemart3 mart
    loadpointer 0x0 str_mart_exit
    callstd MSG_KEEPOPEN
    release
    end

mart:
    .hword 0

.ifdef LANG_GER
    str_mart_ask:
        .autostring 34 2 "Hallo!\nKann ich dir behilflich sein?"
    str_mart_exit:
        .autostring 34 2 "Bitte komm bald wieder!"
.elseif LANG_EN
    str_mart_ask:
        .autostring 34 2 "Hello!\nHow can I help you?"
    str_mart_exit:
        .autostring 34 2 "Have a nice day!"
.endif

ow_script_nurse_joy:
    preparemsg str_joy_intro
    waitmsg
    multichoice 0x13 0x8 0x0 0x2
    copyvar 0x8000 LASTRESULT
    compare 0x8000 0x0
    gotoif EQUAL ow_script_0x877467
    compare 0x8000 0x1
    gotoif EQUAL ow_script_0x949710
    compare 0x8000 0x7f
    gotoif EQUAL ow_script_0x949710
    end

ow_script_0x949710:
    loadpointer 0x0 str_joy_bye
    callstd MSG
    end

ow_script_0x877467:
    savincrementkey 0xf
    loadpointer 0x0 str_joy_takes_care
    callstd MSG_KEEPOPEN
    closeonkeypress
    call ow_script_0x1a947f
    pause 0x5
    special 0x169
    pause 0x5
    goto ow_script_0x1a949d

ow_script_0x1a949d:
    special2 0x800d 0x1b1
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_0x1a94ce
    special2 0x800d 0x183
    copyvar 0x8008 LASTRESULT
    compare 0x8008 0x0
    gotoif EQUAL ow_script_0x1a94ce
    compare 0x8008 0x1
    gotoif EQUAL ow_script_0x1a94e7
    end

ow_script_0x1a94e7:
    checkflag 0x842
    gotoif EQUAL ow_script_0x949719
    loadpointer 0x0 str_joy_healed
    callstd MSG_KEEPOPEN
    setflag 0x842
    preparemsg str_joy_mon_plays
    waitmsg
    applymovement 0x800f ow_script_movs_0x1a951d
    waitmovement 0x0
    loadpointer 0x0 str_joy_bye
    callstd MSG_KEEPOPEN
    end

ow_script_0x949719:
    preparemsg str_joy_healed
    waitmsg
    applymovement 0x800f ow_script_movs_0x1a951d
    waitmovement 0x0
    loadpointer 0x0 str_joy_bye
    callstd MSG
    end

ow_script_0x1a94ce:
    preparemsg str_joy_healed
    waitmsg
    applymovement 0x800f ow_script_movs_0x1a951d
    waitmovement 0x0
    loadpointer 0x0 str_joy_bye
    callstd MSG
    end

ow_script_0x1a947f:
    applymovement 0x800f ow_script_movs_0x1aa419
    waitmovement 0x0
    doanimation 0x19
    checkanimation 0x19
    applymovement 0x800f ow_script_movs_0x1aa41f
    waitmovement 0x0
    special SPECIAL_HEAL
    return

ow_script_movs_0x1aa419:
    .byte LOOK_LEFT_DELAYED, STOP

ow_script_movs_0x1aa41f:
    .byte LOOK_DOWN_DELAYED, STOP

ow_script_movs_0x1a951d:
.byte 0x5b, 0x1a, STOP


.ifdef LANG_GER
str_joy_intro:
    .autostring 34 2 "Willkommen im Pokéstop!\pWir heilen deine Pokémon und machen sie wieder fit!"
str_joy_bye:
    .autostring 34 2 "Komm jederzeit wieder vorbei!"
str_joy_takes_care:
    .autostring 34 2 "Okay, ich nehme deine Pokémon für einen Moment in meine Obhut."
str_joy_healed:
    .autostring 34 2 "Danke!\nDeine Pokémon sind wieder topfit!"
str_joy_mon_plays:
    .autostring 34 2 "Es scheint, als ob BUFFER_1 gerade spielt.\pLos!"
.elseif LANG_EN
str_joy_intro:
    .autostring 34 2 "Welcome to the Pokéstop!\pWe take heal your injured Pokémon and make them fit again!"
str_joy_bye:
    .autostring 34 2 "Feel free to come by any time."
str_joy_takes_care:
    .autostring 34 2 "Okay, I will take care of your Pokémon."
str_joy_healed:
    .autostring 34 2 "Thanks!\nYour Pokémon are perfectly fit again!"
str_joy_mon_plays:
    .autostring 34 2 "It seems like BUFFER_1 is playing right no.\pGo!"
.endif

ow_script_init_union_room:
	special 0x182
	end

ow_script_botogel:
    lock
    checkflag PRESENT_INTRODUCED
    gotoif 0 introduce
query:
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_2
    callstd 4
    waitcry
    special 0x4A
    waitstate
    lock
    compare LASTRESULT 1
    gotoif EQUAL receive_present
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_0
    callstd 4
    waitcry
    loadpointer 0 str_ow_script_botogel_3
    callstd 6
    release
    end

receive_present:
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_0
    callstd 4
    waitcry
    jumpram
    end

introduce:
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_0
    callstd 4
    waitcry
    loadpointer 0 str_ow_script_botogel_1
    callstd 6
    setflag PRESENT_INTRODUCED
    goto query



.ifdef LANG_GER
str_ow_script_botogel_0:
    .autostring 34 2 "Botogel!\nBotogel!"
str_ow_script_botogel_1:
    .autostring 34 2 "Hey, Botogel scheint dich zu mögen!\pDu hast es richtig glücklich gemacht.\pBotogels Aufgabe ist es, Geschenke an Trainer zu verteilen, wenn diese einen gültigen Code kennen.\pWeil das Botogel so außer sich ist, werde ich dir einen Code verraten.\pProbier es mit\nBOTOGEL und achte dabei, auf die korrekte Groß- und Kleinschreibung."
str_ow_script_botogel_2:
    .autostring 34 2 "Botogel! Botogel?"
str_ow_script_botogel_3:
    .autostring 34 2 "Oh tut mir leid!\nSieht so aus, als wäre der Code ungültig!\pHast du auch auf die korrekte Groß- und Kleinschreibung geachtet?"
.elseif LANG_EN

str_ow_script_botogel_0:
    .autostring 34 2 "Delibird!\nDelibird!"
str_ow_script_botogel_1:
    .autostring 34 2 "Hey, looks like the Delibird kind of likes you!\pYou made it really happy!\pDelibird's duty is to distribute presents to trainers if they know a proper pass code.\pSince Delibird is most delightet, I will tell you one pass code.\pTry out BOTOGEL and pay attention to upper and lower case letters."
str_ow_script_botogel_2:
    .autostring 34 2 "Delibird! Delibird?"
str_ow_script_botogel_3:
    .autostring 34 2 "Oh am sorry, but it seems like this code is not valid.\pDid you check for proper use of upper and lower case?"
.endif